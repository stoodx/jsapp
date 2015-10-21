function getSyncDataEcmascript(fileName)
{
    var res = "Error: No native function";
    return res;
}

var getSyncDataHelper = (this.getSyncDataNative || getSyncDataEcmascript);

function getSyncData(fileName)
{
    return getSyncDataHelper(fileName);
}

function main(fileName)
{
    var res = getSyncData(fileName);
    alert(res);
}