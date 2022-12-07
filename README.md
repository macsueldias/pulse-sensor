# Heart-m

Esse projeto tem como objetivo possibilitar o acompanhamento da saúde cardiaca pelo paciente e pelos familiares.

Componentes necessários para desenvolver o projeto


#### Componentes:

- Uno R3 Wifi Atmega328P + ESP8266
- Protoboard 400 pontos
- Display LCD 16 x 2
- Modulo Serial I2C
- Sensor Batimento Cardíaco


#### Conexões
A protoboard recebe sinal de 5v e o negativo do arduino, ambos os sinal são usados no display e no sensor cardiaco. O display LCD é conectado no modúlo I2C através da protoboard, o modúlo I2C possui 4 entradas, VCC, GND, SCL e SDA, as duas ultimas são conectadas nas entradas correspondente do arduino, o sensor possui três cabos positivo, negativos e o analógico, o positivo e o negativo é conectado na protoboard, o cabo analógico é conectado na entrada analógica do A1 do arduino.
Para ligar o arduino é necessario conectar uma ponta do cabo usb em algum dispositivo e outra no arduino. 

#### Leitura dos batimentos
Para que o sensor capte os batimentos cardiaco é necessário que o usuário repouse a ponta do dedo sobre o sensor, os sensor irá apresentar a taxa de batimento por minuto no display e enviar para o topico criado no MQTT.


Para que o ESP8266 funcione na ide do arduino deverá acessar a ide e seguir o seguinte passo:


1° Selecionar a aba 'File';
2° Click na opção 'Preferences';
3° Adicinar a url http://arduino.esp8266.com/stable/package_esp8266com_index.json no gerenciador de placa;
4° Click no botão 'OK';

Adicionar as seguintes bibliotecas:

#### Bibliotecas
- EspMQTTClient: conectar com wifi e MQTT
- LiquidCrystal_I2C: controlar o display
- PulseSensorPlayground: obter dados do sensor

#### Uploading

Para adicionar o programa no ESP8266 deverá seguir os passo abaixo:


- 1° ligar os switches 5, 6 e 7 ;
- 2° Conectar o cabo usb no arduino e em um computador;
- 3° Selecionar a aba da ide 'Tools';
- 4° Selecionar a porta que conectado o cabo usb;
- 5° Selecionar a placa 'Generic ESP8266 module';
- 6° Fazer o uploanding do programa;


Para adicionar o programa no ATmega deverá seguir os passo abaixo:


- 1° desconectar o usb;
- 2° desligar os switches 5, 6 e 7;
- 3° ligar os switches 3 e 4 do arduino;
- 4° Conectar o cabo usb no arduino e em um computador;
- 5° Selecionar a aba da ide 'Tools';
- 6° Selecionar a porta que conectado o cabo usb;
- 7° Selecionar a placa 'Arduino Uno';
- 8° Fazer o uploanding do programa;


Para que o ATmega se comunique com o ESP8266 deverá seguir os passos abaixo:


- 1° desconectar o usb;
- 2° desligar os switches 3 e 4;
- 3° ligar os switches 1 e 2 do arduino;
- 4° Conectar o cabo usb no arduino e em um computador;
- 5° Selecionar a aba da ide 'Tools';




