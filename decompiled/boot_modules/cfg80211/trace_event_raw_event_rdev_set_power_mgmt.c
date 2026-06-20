__int64 __fastcall trace_event_raw_event_rdev_set_power_mgmt(__int64 a1, __int64 a2, __int64 a3, char a4, int a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x24
  __int64 v12; // x23
  size_t v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x8
  __int64 v16; // x0
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  result = trace_event_buffer_reserve(v17);
  if ( !result )
    goto LABEL_11;
  v11 = *(const char **)(a2 + 504);
  v12 = result;
  if ( !v11 )
    v11 = *(const char **)(a2 + 392);
  v13 = strnlen(v11, 0x20u);
  if ( v13 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v13 == 32 )
      v14 = 32;
    else
      v14 = v13 + 1;
    if ( v14 < 0x21 )
    {
      sized_strscpy(v12 + 8, v11);
      v15 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v12 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v12 + 48) = v15;
      LODWORD(v15) = *(_DWORD *)(a3 + 224);
      *(_BYTE *)(v12 + 60) = a4 & 1;
      *(_DWORD *)(v12 + 64) = a5;
      *(_DWORD *)(v12 + 56) = v15;
      result = trace_event_buffer_commit(v17);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v16 = _fortify_panic(7, 32);
  return perf_trace_rdev_set_power_mgmt(v16);
}
