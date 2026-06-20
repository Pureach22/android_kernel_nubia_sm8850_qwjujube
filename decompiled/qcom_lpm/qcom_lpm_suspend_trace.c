__int64 __fastcall qcom_lpm_suspend_trace(__int64 a1, const char *a2, __int64 a3, char a4)
{
  __int64 result; // x0
  char v5; // w8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x19
  char v8; // w8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x19

  if ( (a4 & 1) != 0 )
  {
    result = strcmp("dpm_suspend_late", a2);
    if ( !(_DWORD)result )
    {
      v5 = 0;
      suspend_in_progress = 1;
      do
      {
        v6 = (unsigned int)(-1LL << v5) & _cpu_online_mask;
        if ( !(_DWORD)v6 )
          break;
        v7 = __clz(__rbit64(v6));
        result = wake_up_if_idle((unsigned int)v7);
        v5 = v7 + 1;
      }
      while ( v7 <= 0x1E );
    }
  }
  else
  {
    result = strcmp("dpm_resume_early", a2);
    if ( !(_DWORD)result )
    {
      v8 = 0;
      suspend_in_progress = 0;
      do
      {
        v9 = (unsigned int)(-1LL << v8) & _cpu_online_mask;
        if ( !(_DWORD)v9 )
          break;
        v10 = __clz(__rbit64(v9));
        result = wake_up_if_idle((unsigned int)v10);
        v8 = v10 + 1;
      }
      while ( v10 < 0x1F );
    }
  }
  return result;
}
