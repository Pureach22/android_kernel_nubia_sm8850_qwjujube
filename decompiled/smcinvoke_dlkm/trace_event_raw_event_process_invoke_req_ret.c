__int64 __fastcall trace_event_raw_event_process_invoke_req_ret(
        __int64 a1,
        const char *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  __int64 v13; // x9
  __int64 result; // x0
  _DWORD *v15; // x25
  size_t v16; // x0
  unsigned __int64 v17; // x2
  _QWORD v18[7]; // [xsp+8h] [xbp-38h] BYREF

  v18[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 72);
  memset(v18, 0, 48);
  if ( (v13 & 0x2C0) == 0 || (v13 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v18);
    if ( result )
    {
      v15 = (_DWORD *)result;
      v16 = strnlen(a2, 0x30u);
      if ( v16 == -1 )
      {
        _fortify_panic(2, -1, 0);
      }
      else
      {
        if ( v16 == 48 )
          v17 = 48;
        else
          v17 = v16 + 1;
        if ( v17 < 0x31 )
        {
          sized_strscpy(v15 + 2, a2);
          v15[14] = a3;
          v15[15] = a4;
          v15[17] = a6;
          v15[18] = a7;
          v15[16] = a5;
          result = trace_event_buffer_commit(v18);
          goto LABEL_9;
        }
      }
      _fortify_panic(7, 48, v17);
      JUMPOUT(0xA660);
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
