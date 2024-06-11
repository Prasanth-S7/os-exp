{
    name=$1;
    pass=1;

    for(i=2;i<=NF;i++){
        if($i<45){
            pass=0;
            break;
        }
    }
    if(pass==1){
        print name, "pass";
    }
    else{
        print name, "fail";
    }
}