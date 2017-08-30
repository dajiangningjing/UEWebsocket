using UnityEngine; 
using System; 
namespace ClientProto{
	public enum command {
		CMD_TEST=1,
	}
	[Serializable]
	public class TestInfo{
		public string name;
		public int[] score;
	}
	[Serializable]
	public class CS_CMD_TEST_body{
		public string address;
		public int test;
	}
	[Serializable]
	public class CS_CMD_TEST{
		public string name;
		public int age;
		public TestInfo testinfo;
		public CS_CMD_TEST_body body;
	}

}