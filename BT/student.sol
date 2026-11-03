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
