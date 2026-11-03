//SPDX-License-Identifier: UNLICENSED


pragma solidity ^0.8.5;

contract Bank{
    address actHolder;
    uint256 balance=0;

    constructor(){
        actHolder=msg.sender;
    }
    
    function deposit() public payable {
        require(msg.value>0,"deposit amt shd be greater than 0");
        require(msg.sender==actHolder,"youre not allowed");
        balance=balance+msg.value;
    }

    function checkBalance() public view returns(uint){
        require(msg.sender==actHolder,"youre not allowed");
        return balance;
    }

    function withdraw() public payable{
        require(msg.sender==actHolder,"youre not allowed");
        require(msg.value>0,"u cant withdraw null");
        require(msg.value<=balance,"withrawal amount invalid");
        balance=balance-msg.value;
        //(bool success, ) = payable(actHolder).call{value: amount}("");
        //require(success, "withdrawal failed");
    }
}
~~~~~~~~~~
//SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.5;

contract Student{

    struct student{
        string name;
        uint256 rollno;
    }

    student[] public studentarr;

    function addStudent(string memory n, uint r) public {
        for(uint i=0;i<studentarr.length;i++){
            if(studentarr[i].rollno==r){
                revert("st alr exist");
            }
        }
        studentarr.push(student(n,r));
    }

    function getStudentCount() public view returns(uint){
        return studentarr.length;
    }

    function displayStudents() public view returns(student[] memory){
        return studentarr;
    }

    function getStudentbyIndex(uint index) public view returns(student memory){
        require(index<studentarr.length,"enter valid index");
        return studentarr[index];
    }

    //fallback
    fallback() external payable {
        //this function ext function call not thwre
     }

     receive() external payable { 
        //
     }

    
}
