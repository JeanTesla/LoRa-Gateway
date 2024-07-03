#!/bin/sh

clear;
echo "Copiando arquivos para o orangePI...\n";

# Copiando arquivos para o orangePI
smbclient //192.168.1.9/sharing -W domain -U tesla%pausebreak \
-c 'prompt OFF; recurse ON; cd orangepi/LoRaGateway; lcd /home/tesla/Documentos/Nosferatu/LoRa-Gateway/; mput *'

# Trazendo o banco de dados para a máquina local
cp /run/user/1000/doc/42d41c81/gateway-cfg.db ./gateway-cfg.db
