

//test

const int maxLength = 40;
const int height = 8;
const int width = 16;
uint16_t ledMatrix[height][width][maxLength];
const uint16_t badAddress = 9999;

int ledCount1[height][width] = {
  {21, 20, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //16
  {21, 20, 19, 18, 17, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //15
  {21, 20, 19, 18, 17, 17, 16, 16, 16, 0, 0, 0, 0, 0, 0, 0}, //14
  {1, 20, 19, 18, 17, 16, 16, 16, 16, 16, 0, 0, 0, 0, 0, 0}, //13
  {21, 20, 19, 18, 17, 17, 17, 16, 16, 16, 16, 0, 0, 0, 0, 0},//12
  {40, 40, 40, 18, 17, 17, 17, 16, 16, 16, 16, 16, 0, 0, 0, 0},  //11
  {40, 40, 40, 40, 40, 40, 17, 16, 16, 16, 16, 16, 16, 0, 0, 0},//10
  {40, 40, 40, 40, 40, 40, 40, 16, 16, 15, 15, 14, 14, 0, 0, 0},//9 TODO check dir
};

int ledCount2[height][width] = {
{40, 40, 40, 40, 40, 40, 40, 40, 15, 14, 14, 13, 13, 13, 0, 0}, //8 //TODO -- one direction missing
{0, 40, 40, 40, 40, 40, 40, 40, 40, 13, 13, 12, 12, 12, 12, 0}, //7 //TODO -- check first element -- missing by design
{40, 40, 40, 40, 40, 40, 40, 40, 40, 12, 11, 11, 11, 11, 11, 0},//6
{40, 40, 40, 40, 40, 40, 40, 40, 40, 10, 10, 10, 9, 9, 9, 9}, //5
{40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 9, 8, 8, 8, 8, 8}, //4
{40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 8, 7, 7, 7, 7, 7}, //3
{40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 7, 7, 7, 7, 7}, //2
{40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 7, 7, 7, 7, 7}, //1
};

//UP - 2, DOWN - 1
int ledDir1[height][width] = {
  {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //16
  {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //15
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, //14
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, //13
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},//12
  {2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},//11
  {2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},//10
  {2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0},//9 //TODO: check
};

int ledDir2[height][width] = {
{1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 0, 0}, //8 //TODO -- one direction missing
{0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 0},//7 //TODO -- check first element -- missing by design
{2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 0},//6
{2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1}, //5
{1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1}, //4
{1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1}, //3 TODO -- check
{2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1}, //2
{2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1}, //1
};



void setup() {
    Serial.begin(9600);
  //get all adresses

}

void loop() {
 Serial.println("Matrix:");
 uint16_t elementCounter = 0;
 uint16_t address = 0;
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
          
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
               address = badAddress; 
               ledMatrix[i][j][k] = address;
              }
          }
          else {
               address = badAddress; 
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
