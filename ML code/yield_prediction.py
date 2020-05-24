
# coding: utf-8

# In[2]:


import csv
from sklearn.preprocessing import StandardScaler
import pandas as pd
import numpy as np
import keras
from keras.models import Model
from keras.layers import Input, Dense
from keras.models import Sequential
from keras.callbacks import EarlyStopping
import matplotlib.pyplot as plt
np.set_printoptions(suppress=True)


# In[49]:


# 0. Load in the data and split the descriptive and the target feature
df = pd.read_csv('bajra.csv',sep=',' , header = None)
X_train = df.iloc[:,0:5].copy()
y_train = df.iloc[:,-1].copy()


# In[50]:


print('X_train.shape : ', X_train.shape, '\ny_train.shape : ' , y_train.shape)


# In[51]:


num_features = X_train.shape[1]
print('Number of features : ' , num_features)


# In[52]:


# 1. Standardize the data
for col in X_train.columns:
    X_train[col] = StandardScaler().fit_transform(X_train[col].values.reshape(-1,1))


# In[53]:


def model():
    #create model
    model = Sequential()

    #get number of columns in training data
    n_cols = num_features

    #add model layers
    model.add(Dense(3, activation='relu', input_shape=(n_cols,)))
    model.add(Dense(2, activation='relu'))
    model.add(Dense(1))
    #compile model using mse as a measure of model performance
    model.compile(optimizer='adam', loss='mean_squared_error', metrics = ['mape'])
    return model


# In[54]:


model = model()


# In[55]:


#train model
history = model.fit(X_train, y_train, validation_split=0.2, epochs=500)


# In[60]:


plt.plot(history.history['mean_absolute_percentage_error'])
plt.plot(history.history['val_mean_absolute_percentage_error'])
plt.title('Model error')
plt.ylabel('Percentage Error')
plt.xlabel('Epoch')
plt.legend(['Train', 'Test'], loc='upper left')
plt.show()

