int main(){
    int i;
    int nbr = 1589.0;

    for (i = 1; i <=3; i++){
        nbr = nbr / 10.0;
    }

    if(nbr==1.589){
        return 1;
    }
    return 0;
}