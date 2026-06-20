__int64 __fastcall trace_event_raw_event_api_eosp(__int64 a1, __int64 a2, int *a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  const char *v9; // x21
  size_t v10; // x0
  unsigned __int64 v11; // x2
  int v12; // w9
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v13, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v13);
    if ( result )
    {
      v7 = *(_QWORD *)(a2 + 72);
      v8 = result;
      v9 = *(const char **)(v7 + 504);
      if ( !v9 )
        v9 = *(const char **)(v7 + 392);
      v10 = strnlen(v9, 0x20u);
      if ( v10 == -1 )
      {
        _fortify_panic(2);
      }
      else
      {
        if ( v10 == 32 )
          v11 = 32;
        else
          v11 = v10 + 1;
        if ( v11 < 0x21 )
        {
          sized_strscpy(v8 + 8, v9);
          if ( a3 )
          {
            v12 = *a3;
            *(_WORD *)(v8 + 44) = *((_WORD *)a3 + 2);
            *(_DWORD *)(v8 + 40) = v12;
          }
          else
          {
            *(_WORD *)(v8 + 44) = 0;
            *(_DWORD *)(v8 + 40) = 0;
          }
          result = trace_event_buffer_commit(v13);
          goto LABEL_14;
        }
      }
      _fortify_panic(7);
      JUMPOUT(0x9AEEC);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
