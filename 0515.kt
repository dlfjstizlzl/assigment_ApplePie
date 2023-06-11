class yabal(val insang:String?){
    var value:String="힘들어요 살려주세ㅇ.."
    var reason:String = "과제 덕에?"
    fun hahahaha(){
        println("$insang 은 $reason $value")
    }
}

fun main(args: Array<String>){
    var hehe = yabal("인생")
    hehe.reason = "많은 시련 때문에"
    hehe.value = "힘들 수도 있어요"
    hehe.hahahaha()


}