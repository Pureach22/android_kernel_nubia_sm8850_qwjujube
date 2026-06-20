__int64 __fastcall walt_frame_rate_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w19
  __int64 result; // x0
  __int64 v7; // x8

  v5 = a2;
  result = proc_dointvec_minmax(a1, a2, a3, a4, a5);
  if ( v5 && !(_DWORD)result )
  {
    if ( sysctl_frame_rate )
      v7 = 0x3B9ACA00u / sysctl_frame_rate;
    else
      v7 = 0;
    frame_size_ns = v7;
  }
  return result;
}
