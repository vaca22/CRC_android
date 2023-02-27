#include <jni.h>
#include <string>



unsigned char crc8_compute(unsigned char *pdata, unsigned data_size)
{
    unsigned char crc_in=0;
    uint8_t cnt;
    uint8_t crc_poly = 0x07;
    uint8_t data_tmp = 0;

    while (data_size--){
        data_tmp = *(pdata++);
        crc_in ^= (data_tmp << 0);
        for(cnt = 0; cnt < 8; cnt++){
            if(crc_in & 0x80){
                crc_in = (crc_in << 1) ^ crc_poly;
            }else{
                crc_in = crc_in << 1;
            }
        }
    }

    return crc_in;
}


extern "C"
JNIEXPORT jbyte JNICALL
Java_com_example_crc_1android_MainActivity_crc(JNIEnv *env, jobject thiz, jbyteArray b) {
    signed char *byteArray;
    jsize arraySize;
    arraySize = (*env).GetArrayLength(b);
    jboolean *isCopy = (jboolean *) malloc(sizeof(jboolean));
    byteArray = (*env).GetByteArrayElements(b, isCopy);
    unsigned char result = crc8_compute(reinterpret_cast<unsigned char *>(byteArray), arraySize);
    jbyte j_result = result;
    return j_result;
}