__int64 __fastcall trace_event_raw_event_rdev_set_sar_specs(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v5; // x8
  __int64 result; // x0
  const char *v7; // x22
  __int64 v8; // x21
  size_t v9; // x0
  unsigned __int64 v10; // x2
  long double v11; // q0
  _QWORD v12[7]; // [xsp+8h] [xbp-38h] BYREF

  v12[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 72);
  memset(v12, 0, 48);
  if ( (v5 & 0x2C0) == 0 || (v5 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v12);
    if ( result )
    {
      v7 = *(const char **)(a2 + 504);
      v8 = result;
      if ( !v7 )
        v7 = *(const char **)(a2 + 392);
      v9 = strnlen(v7, 0x20u);
      if ( v9 == -1 )
      {
        _fortify_panic(2, -1);
      }
      else
      {
        if ( v9 == 32 )
          v10 = 32;
        else
          v10 = v9 + 1;
        if ( v10 < 0x21 )
        {
          sized_strscpy(v8 + 8, v7);
          *(_WORD *)(v8 + 40) = *a3;
          *(_WORD *)(v8 + 42) = a3[1];
          result = trace_event_buffer_commit(v12);
          goto LABEL_11;
        }
      }
      v11 = _fortify_panic(7, 32);
      MEMORY[0xFFFFFFFFFEBBCCD0](v11);
      JUMPOUT(0xA18C8);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
