DEFINES += PRL_PROD_SERVER=1
DEFINES += _LIN_
DYN_VZLIB = TRUE

# Product name
PRODUCT = server

isEmpty(PREFIX): PREFIX = $$(PREFIX)
isEmpty(PREFIX): PREFIX = /usr

