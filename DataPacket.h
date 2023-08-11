#pragma once

ref class S_APP_TO_SIMULATOR {
public:
	unsigned short stx;
	unsigned short messageId;
	unsigned int packetCounter;
	float timeStamp;
	unsigned int reserved3;
	unsigned int checksum;
};

ref class S_SIMULATOR_TO_APP {
public:
	unsigned int stx;
	unsigned int status;
	unsigned int checksum;
};