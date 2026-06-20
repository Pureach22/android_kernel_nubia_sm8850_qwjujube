__int64 __fastcall trace_event_raw_event_rdev_return_void_tx_rx(__int64 a1, __int64 a2, int a3, int a4, int a5, int a6)
{
  __int64 v11; // x8
  __int64 result; // x0
  const char *v13; // x25
  _DWORD *v14; // x24
  size_t v15; // x0
  unsigned __int64 v16; // x2
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v11 & 0x2C0) == 0 || (v11 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v17);
    if ( result )
    {
      v13 = *(const char **)(a2 + 504);
      v14 = (_DWORD *)result;
      if ( !v13 )
        v13 = *(const char **)(a2 + 392);
      v15 = strnlen(v13, 0x20u);
      if ( v15 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v15 == 32 )
          v16 = 32;
        else
          v16 = v15 + 1;
        if ( v16 < 0x21 )
        {
          sized_strscpy(v14 + 2, v13);
          v14[10] = a3;
          v14[11] = a4;
          v14[12] = a5;
          v14[13] = a6;
          result = trace_event_buffer_commit(v17);
          goto LABEL_11;
        }
      }
      _fortify_panic(7, 32);
      JUMPOUT(0x993EC);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
