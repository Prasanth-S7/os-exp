BEGIN{
    totalPay =0;
    empcount=0;
}
{
    name=$1;
    salaryperday=$2;
    noOfdaysworked=$3;
    if(salaryperday>6000 && noOfdaysworked>4){
        salaryearned = salaryperday * noOfdaysworked;
        print name, salaryearned
        totalPay+=salaryearned;
        empcount++;
    }
}
END{
    if(empcount>0){
        averagePay= totalPay/empcount
        print "total employees " , empcount
        print "averagePay", averagePay
    }
    else{
        print "no employees satisfies"
    }
}