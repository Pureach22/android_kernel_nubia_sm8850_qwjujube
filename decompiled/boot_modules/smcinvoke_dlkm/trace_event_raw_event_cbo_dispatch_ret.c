__int64 __fastcall trace_event_raw_event_cbo_dispatch_ret(__int64 a1, const char *a2, int a3, int a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v9; // x22
  size_t v10; // x0
  unsigned __int64 v11; // x2
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v7 & 0x2C0) == 0 || (v7 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12);
    if ( result )
    {
      v9 = result;
      v10 = strnlen(a2, 0x30u);
      if ( v10 == -1 )
      {
        _fortify_panic(2, -1, 0);
      }
      else
      {
        if ( v10 == 48 )
          v11 = 48;
        else
          v11 = v10 + 1;
        if ( v11 < 0x31 )
        {
          sized_strscpy(v9 + 8, a2);
          *(_DWORD *)(v9 + 56) = a3;
          *(_DWORD *)(v9 + 60) = a4;
          result = trace_event_buffer_commit(v12);
          goto LABEL_9;
        }
      }
      _fortify_panic(7, 48, v11);
      JUMPOUT(0xB8F4);
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
