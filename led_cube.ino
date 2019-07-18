

//test

const int maxLength = 4;
const int height = 1;
const int length = 4;
uint16_t ledMatrix[height][length][maxLength];

int ledCount1[height][length] = {
  {2, 2, 2, 2}, //16
  //{2, 2, 2, 2}, //16
 };



//UP - 2, DOWN - 1
int ledDir1[height][length] = {
  {1, 1, 2, 0},
  //{2, 2, 2, 2},
};


void setup() {
    Serial.begin(9600);
  //get all adresses

}

void loop() {
 Serial.println("Matrix:");
 int elementCounter = 0;
 int address = 0;
  for(int i = 0; i < height; i++){
    for(int j = 0; j < length; j++){
          
          for(int k = 0; k < maxLength; k++){
            if (k < ledCount1[i][j]) { 
             if (ledDir1[i][j] == 1) { //DOWN
                 address = elementCounter*maxLength+k;
                 ledMatrix[i][j][k] = address;
               }
             else if (ledDir1[i][j] == 2) { //UP
               address = elementCounter*maxLength+maxLength - k-1;
               }
            
             else if (ledDir1[i][j] == 0){
               address = 0; 
               ledMatrix[i][j][k] = address;
              }
          }
          else {
               address = 0; 
               ledMatrix[i][j][k] = address;
            }
          Serial.print(address);           
          Serial.print(","); 
          }         
   Serial.println();
   Serial.println(elementCounter);
   elementCounter++;         

   }
  } 
  delay(3000);

} 
