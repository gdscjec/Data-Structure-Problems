const largestNumber = function(nums) {
    nums.sort(function(a, b){
        const strA = a + ""
        const strB = b + ""
        if(strA[0] != strB[0]) 
            return parseInt(strA[0]) > parseInt(strB[0]) ? -1 : 1
        else {
            const fullAB = strA + strB;
            const fullBA = strB + strA;
            for(let i = 0; i< fullAB.length; i++) {
                if(fullAB[i] === fullBA[i]) continue
                return fullAB[i] > fullBA[i] ? -1 : 1
            }
        }
        return 0
    })
    return nums[0] === 0 ? "0" : nums.join("")
}
