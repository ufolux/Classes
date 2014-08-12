#include "util/testLog.h"

testLog::testLog()
{
}

testLog::~testLog()
{
}

void testLog::L( const char * pszFormat, ...){

	if( flag ){
		printf("Â³öÎLog: ");
		char szBuf[512];

		va_list ap;
		va_start(ap, pszFormat);
		vsnprintf(szBuf, 512, pszFormat, ap);
		va_end(ap);
		printf("%s", szBuf);
		printf("\n");
	}


}

static testLog* instance = NULL;
testLog* testLog::sharedtestLog(){

	if (!instance ) {

		instance = new testLog();
	}

	return instance;

}


void testLog::purge(){

	CC_SAFE_DELETE( instance );
}