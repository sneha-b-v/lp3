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
