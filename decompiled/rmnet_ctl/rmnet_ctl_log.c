__int64 __fastcall rmnet_ctl_log(unsigned int a1, const char *a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0

  result = qword_6B20;
  if ( (unsigned __int8)ipc_log_lvl >= a1 && qword_6B20 != 0 )
  {
    if ( a4 && (_DWORD)a5 )
    {
      if ( (unsigned int)a5 >= 0x20 )
        a5 = 32;
      else
        a5 = (unsigned int)a5;
      return ipc_log_string(qword_6B20, "%3s(%d): %*ph\n", a2, a3, a5);
    }
    else
    {
      return ipc_log_string(qword_6B20, "%3s(%d): (null)\n", a2, a3);
    }
  }
  return result;
}
