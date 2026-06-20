__int64 __fastcall qtee_ioctl(__int64 a1, int a2, __int64 a3)
{
  if ( a2 == -1071605759 )
    return process_invoke_req(a1, a3);
  else
    return -515;
}
