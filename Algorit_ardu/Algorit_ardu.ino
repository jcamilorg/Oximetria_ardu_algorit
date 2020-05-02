int mini;
int data;
int maxi;

void setup() {
  mini=0;
  maxi=0;
}

void loop() {
  if (data < mini) {
    mini=data;
  }
  if (data > maxi) {
    maxi=data;
  }

}
