declare namespace MessageProto{
	enum command {
		enum=1,
		CMD_TEST=1,
	}
	export interface TestInfo{
		name:string;
		score:number[];
	}
	export interface CS_CMD_TEST_body{
		address:string;
		test:number;
	}
	export interface CS_CMD_TEST{
		name:string;
		age:number;
		testinfo:TestInfo;
		body:CS_CMD_TEST_body;
	}

}