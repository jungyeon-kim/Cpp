#pragma once	// 인클루드 가드:		중복 인클루드 방지 (ifndef, endif와 같은 기능)

class Test;		// 전방 선언:	자기자신을 include하는 일이 있을 수 있어 
			//			다른 객체를 참조하고싶다면 이 방식이 더 좋다.
			//			객체를 간접적으로 참조하기 때문에 컴파일 시간도 단축된다.
			//			크기를 알 수 있는 포인터나 크기를 몰라도 되는 선언만 된 함수의 반환값, 매개변수로만 접근 가능
			// PCH:			미리 컴파일된 헤더. 보통 소스파일에서 자신의 헤더파일 include 보다 
			//			위에 위치하기 때문에 헤더파일에서 전방선언 없이도 접근이 가능하다. (일반 헤더여도 가능한 일)

/*
	쓸데없이 소스에 라이브러리 include를 많이해도 obj파일이 커질 뿐, 
	해당 라이브러리를 사용하지 않으면 실행파일은 커지지 않는다.
	-> 사용되지않는 라이브러리는 실행파일 생성과정에서 제외되기 때문.
*/
