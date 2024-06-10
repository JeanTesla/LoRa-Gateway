#!/bin/sh

clear;
echo "Copiando arquivos para o orangePI...\n";
smbclient //192.168.1.9/sharing -W domain -U tesla%pausebreak \
-c 'prompt OFF; recurse ON; cd orangepi/LoRaGateway; lcd /home/tesla/Documentos/Nosferatu/LoRa-Gateway/; mput *'
