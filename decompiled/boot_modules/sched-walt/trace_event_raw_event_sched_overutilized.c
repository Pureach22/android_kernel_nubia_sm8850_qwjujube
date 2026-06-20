__int64 __fastcall trace_event_raw_event_sched_overutilized(__int64 a1, int a2, const char *a3)
{
  __int64 v3; // x27
  __int64 v6; // x1
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x21
  size_t v10; // x0
  unsigned __int64 v11; // x2
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v6 = a1;
  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v6 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v13, v6, 20);
    if ( result )
    {
      v9 = result;
      *(_DWORD *)(result + 8) = a2;
      v10 = strnlen(a3, 8u);
      if ( v10 == -1 )
      {
        _fortify_panic(2, -1, 0);
      }
      else
      {
        if ( v10 == 8 )
          v11 = 8;
        else
          v11 = v10 + 1;
        if ( v11 < 9 )
        {
          sized_strscpy(v9 + 12, a3);
          result = trace_event_buffer_commit(v13);
          goto LABEL_9;
        }
      }
      _fortify_panic(7, 8, v11);
      if ( v3 )
        JUMPOUT(0x3CA24);
      JUMPOUT(0xFFFFFFFFFFFBA01CLL);
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
