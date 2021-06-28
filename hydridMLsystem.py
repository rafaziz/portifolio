# -*- coding: utf-8 -*-
"""
Created on Wed Jun 19 18:50:51 2019

@author: Utente
"""


import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.svm import SVR
from sklearn.metrics import mean_squared_error as MSE
import sklearn.neural_network as sknn
from sklearn.preprocessing import StandardScaler

np.random.seed(18)

def processdata(data, dimension):
    
    #Base
    serie = pd.Series(data)
    
    #Processamento
    lagged = pd.concat([serie.shift(i) for i in range(dimension + 1)], axis = 1)
    #é +1 no dimension pois é apenas um passo a frente
    
    #Treino
    trainindex = int(np.floor(0.8 * len(data)))
    
    trainset = lagged.iloc[dimension : trainindex, 1 : dimension + 1]
    traintarget = lagged.iloc[dimension : trainindex, 0]
    #test
    testset = lagged.iloc[trainindex : len(data), 1 : dimension + 1]
    testtarget = lagged.iloc[trainindex : len(data), 0]
    
    return (trainset, traintarget, testset, testtarget)

###############################################################################################
# PSO+SVM

def PSO_SVM(trainset, traintarget, testset, testtarget):
    iterations = 100
    n_pop = 10
    
    pop = np.random.uniform(-5,5,(n_pop,3)) #inicialização das particulas
    
    fit = np.zeros((n_pop,1)) #inicialização do vetor de fitness
    
    for j in range(n_pop):
        model = SVR(kernel='rbf', C=10**pop[j,0], gamma=10**pop[j,1], epsilon=10**pop[j,2])
        model.fit(trainset, traintarget)
        predicts = model.predict(testset)
        fit[j] = MSE(testtarget,predicts)
        
    pbest = np.zeros((n_pop,3)) #personal best, melhor pessoal de cada particula
    pfit = np.zeros((n_pop,1)) #valor do melhor pessoal de cada particula 
    
    index = np.argmin(fit)
    for j in range(n_pop):
        pbest[j,:] = pop[index,:] #personal best, melhor pessoal de cada particula
        pfit[j,:] = fit[index,:] #valor do melhor pessoal de cada particula
    
    v = np.zeros((n_pop,3)) #velocidade
    w = 0.4 #peso da inercia
    
    c1 = 2 #fator cognitivo
    c2 = 2 #fator social
    
    for i in range(iterations): #inicio do loop
        for j in range(n_pop):
            model = SVR(kernel='rbf', C=10**pop[j,0], gamma=10**pop[j,1], epsilon=10**pop[j,2])
            model.fit(trainset, traintarget)
            predicts = model.predict(testset)
            fit[j] = MSE(testtarget,predicts)
            
            if(fit[j] < pfit[j]): #determinando o melhor pessoal de cada particula
                #pbest[j,0] = pop[j,0]
                #pbest[j,1] = pop[j,1]
                pbest[j] = pop[j].copy()
                pfit[j] = fit[j]
        
        index = np.argmin(pfit) #calculo da melhor particula, gbest
        gbest = pbest[index].copy()
        fitbest = pfit[index]
        
        for j in range(n_pop):
            v[j] = w*v[j] + c1*np.random.rand()*(pbest[j]-pop[j] )+ c2*np.random.rand()*(gbest - pop[j])
            pop[j] = np.clip(pop[j]+v[j],-5,5)
        
        print('Iteration {0}, fit best = {1}'.format(i+1, fitbest))
        
    # Melhor modelo
    model = SVR(kernel='rbf', C=10**pop[index,0], gamma=10**pop[index,1], epsilon=10**pop[index,2])
    model.fit(trainset, traintarget)
    predicts = model.predict(testset)
    return predicts, MSE(testtarget,predicts), pop[index,:]

###############################################################################################
# Rede neural
    
def RN(trainset, traintarget, testset, testtarget):
    scaler = StandardScaler()  
    scaler.fit(trainset)
    
    X_train = scaler.transform(trainset)  
    X_test = scaler.transform(testset)
    
    Y_train = traintarget.as_matrix()
    
    mlp =sknn.MLPRegressor(hidden_layer_sizes=(10, 10, 10), max_iter=10000)
    mlp.fit(X_train, Y_train)  
    predictions = mlp.predict(X_test)  
    MSE = np.mean((predictions - testtarget.as_matrix())**2)
    return predictions, MSE, mlp, scaler

###############################################################################################
# Auto regresivo
    
def AR(trainset, traintarget, testset, testtarget):
    trainset1 = trainset.copy()
    testset1 = testset.copy()
    trainset1[dimension + 1] = 1
    testset1[dimension + 1] = 1
    #encontra os coeficientes do modelo auto-regressivo
    coefs = np.linalg.pinv(trainset1).dot(traintarget)
    #as previsoes são encontradas multiplicando a matriz set pela matriz coefs
    predicts = testset1.dot(coefs)
    erro = MSE(predicts, testtarget)
    return predicts, erro, coefs

###############################################################################################
    
dimension = 1
data = pd.read_csv('petr4data.txt')['Close']
serie = pd.Series(data)

(trainset, traintarget, testset, testtarget) = processdata(serie, dimension)

###########

Y_AR, mse_AR, param_AR = AR(trainset, traintarget, testset, testtarget)
Y_RN, mse_RN, model_RN, scaler_RN = RN(trainset, traintarget, testset, testtarget)
Y_SVM, mse_SVM, param_SVM = PSO_SVM(trainset, traintarget, testset, testtarget)

Y_mean = (Y_AR + Y_RN + Y_SVM)/3
mse_mean = np.mean((Y_mean-testtarget)**2)

X_est = np.concatenate((np.ones((len(testtarget),1)),np.expand_dims(Y_AR,1),np.expand_dims(Y_RN,1),np.expand_dims(Y_SVM,1)), 1)
coef = np.linalg.pinv(X_est).dot(testtarget)
Y_RL = X_est.dot(coef)
mse_RL = np.mean((Y_RL - testtarget)**2)

Results = [['AR', mse_AR],
 ['RN', mse_RN],
 ['PSO+SVM', mse_SVM],
 ['Mean', mse_mean],
 ['Ensemble', mse_RL]
]
plt.figure()
plt.plot(testtarget, label='target')
plt.plot(testtarget.index, Y_RN, label='RN')
plt.plot(Y_mean, label='Mean Value')
plt.plot(testtarget.index,Y_RL, label='Regresion')
plt.legend()
plt.title('Prediction')

print(Results)
Results

plt.figure()
# AR
y_AR_t1 = np.sum(param_AR * np.array([serie[251], 1]))
serie_AR = pd.concat((serie,pd.Series(y_AR_t1)), ignore_index=True)
(trainset_AR, traintarget_AR, testset_AR, testtarget_AR) = processdata(serie_AR, dimension)
Y_AR_t1, mse_AR_t1, param_AR_t1 = AR(trainset_AR, traintarget_AR, testset_AR, testtarget_AR)
mse_AR_t = np.mean((Y_AR_t1.as_matrix() - testtarget.as_matrix())**2) 
plt.plot(testtarget, label='target')
plt.plot(testtarget.index,Y_AR_t1, label='AR')

# Neural Network
yy_t = scaler_RN.transform(np.array([serie[251]]).reshape(1,-1))
y_RN_t1 = model_RN.predict(yy_t)[0]
serie_RN = pd.concat((serie,pd.Series(y_RN_t1)), ignore_index=True)
(trainset_RN, traintarget_RN, testset_RN, testtarget_RN) = processdata(serie_RN, dimension)
Y_RN_t1, mse_RN_t1, param_RN_t1, scaler_RN_t1 = RN(trainset_RN, traintarget_RN, testset_RN, testtarget_RN)
mse_RN_t = np.mean((Y_RN_t1 - testtarget.as_matrix())**2)
plt.plot(testtarget.index,Y_RN_t1, label='RN')

# Suport Vector Machine
model = SVR(kernel='rbf', C=10**param_SVM[0], gamma=10**param_SVM[1], epsilon=10**param_SVM[2])
model.fit(trainset, traintarget)
y_SVM_t1 = model.predict(np.array([serie[251]]).reshape(1,-1))[0]
serie_SVM = pd.concat((serie,pd.Series(y_SVM_t1)), ignore_index=True)
(trainset_SVM, traintarget_SVM, testset_SVM, testtarget_SVM) = processdata(serie_SVM, dimension)
Y_SVM_t1, mse_SVM_t1, param_SVM_t1 = PSO_SVM(trainset_SVM, traintarget_SVM, testset_SVM, testtarget_SVM)
mse_SVM_t = np.mean((Y_SVM_t1 - testtarget.as_matrix())**2)
plt.plot(testtarget.index,Y_SVM_t1, label='SVM')

#Mediana
YY_predicts = np.concatenate((np.expand_dims(Y_AR_t1,1),np.expand_dims(Y_RN_t1,1),np.expand_dims(Y_SVM_t1,1)), 1)
y_median = np.median(YY_predicts,1)
mse_median = np.mean((y_median-testtarget)**2)
plt.plot(testtarget.index, y_median, label='median')

# Ensemble
y_RL_t1 = np.sum(np.array([1, y_AR_t1, y_RN_t1, y_SVM_t1])*coef)
serie_RL = pd.concat((serie,pd.Series(y_RL_t1)), ignore_index=True)
(trainset_RL, traintarget_RL, testset_RL, testtarget_RL) = processdata(serie_RL, dimension)
Y_AR_RL, _, _ = AR(trainset_RL, traintarget_RL, testset_RL, testtarget_RL)
Y_RN_RL, _, _, _ = RN(trainset_RL, traintarget_RL, testset_RL, testtarget_RL)
Y_SVM_RL, _, _ = PSO_SVM(trainset_RL, traintarget_RL, testset_RL, testtarget_RL)
X_est_t1 = np.concatenate((np.ones((len(testtarget_RL),1)),np.expand_dims(Y_AR_RL,1),np.expand_dims(Y_RN_RL,1),np.expand_dims(Y_SVM_RL,1)), 1)
coef_t1 = np.linalg.pinv(X_est_t1).dot(testtarget_RL)
Y_RL_t1 = X_est_t1.dot(coef_t1)
mse_RL_t1 = np.mean((Y_RL_t1 - testtarget_RL)**2)
mse_RL_t = np.mean((Y_RL_t1 - testtarget.as_matrix())**2)
plt.plot(testtarget.index,Y_RL_t1, label='RL')
plt.legend()
plt.title('Prediction II')

Results_t1 = [['AR', mse_AR_t1, mse_AR_t],
 ['RN', mse_RN_t1, mse_RN_t],
 ['PSO+SVM', mse_SVM_t1, mse_SVM_t],
 ['median', '', mse_median],
 ['Ensemble', mse_RL_t1, mse_RL_t]
]
print(Results_t1)
Results_all = [[Results[i][0], Results[i][1], Results_t1[i][2]] for i in range(5)]
Results_all
