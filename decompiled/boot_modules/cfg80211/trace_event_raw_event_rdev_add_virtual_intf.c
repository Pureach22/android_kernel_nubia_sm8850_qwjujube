__int64 __fastcall trace_event_raw_event_rdev_add_virtual_intf(__int64 a1, __int64 a2, const char *a3, int a4)
{
  __int64 v6; // x8
  const char *v7; // x20
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x22
  const char *v11; // x23
  size_t v12; // x0
  unsigned __int64 v13; // x2
  int v14; // w8
  void *v15; // x21
  size_t v16; // x23
  const char *v17; // x20
  __int64 v18; // x0
  _QWORD v19[7]; // [xsp+8h] [xbp-38h] BYREF

  v19[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 72);
  memset(v19, 0, 48);
  if ( (v6 & 0x2C0) != 0 && (v6 & 0x100) == 0 )
  {
    v17 = a3;
    result = _trace_trigger_soft_disabled(a1);
    a3 = v17;
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  v7 = a3 ? a3 : "<noname>";
  v8 = strlen(v7) + 1;
  result = trace_event_buffer_reserve(v19);
  if ( !result )
    goto LABEL_14;
  v10 = result;
  *(_DWORD *)(result + 40) = (v8 << 16) | 0x30;
  v11 = *(const char **)(a2 + 504);
  if ( !v11 )
    v11 = *(const char **)(a2 + 392);
  v12 = strnlen(v11, 0x20u);
  if ( v12 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v12 == 32 )
      v13 = 32;
    else
      v13 = v12 + 1;
    if ( v13 < 0x21 )
    {
      sized_strscpy(v10 + 8, v11);
      v14 = *(_DWORD *)(v10 + 40);
      v15 = (void *)(v10 + (unsigned __int16)v14);
      v16 = HIWORD(v14) - 1LL;
      memcpy(v15, v7, v16);
      *((_BYTE *)v15 + v16) = 0;
      *(_DWORD *)(v10 + 44) = a4;
      result = trace_event_buffer_commit(v19);
LABEL_14:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v18 = _fortify_panic(7, 32);
  return perf_trace_rdev_add_virtual_intf(v18);
}
