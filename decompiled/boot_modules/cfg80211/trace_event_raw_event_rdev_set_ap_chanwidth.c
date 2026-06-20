__int64 __fastcall trace_event_raw_event_rdev_set_ap_chanwidth(__int64 a1, __int64 a2, __int64 a3, int a4, __int64 a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x24
  __int64 v12; // x22
  size_t v13; // x0
  unsigned __int64 v14; // x2
  __int64 v15; // x8
  __int64 v16; // x7
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_15;
  }
  result = trace_event_buffer_reserve(v17);
  if ( !result )
    goto LABEL_15;
  v11 = *(const char **)(a2 + 504);
  v12 = result;
  if ( !v11 )
    v11 = *(const char **)(a2 + 392);
  v13 = strnlen(v11, 0x20u);
  if ( v13 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_20;
  }
  if ( v13 == 32 )
    v14 = 32;
  else
    v14 = v13 + 1;
  if ( v14 >= 0x21 )
  {
LABEL_20:
    _fortify_panic(7, 32);
    if ( !v16 )
      JUMPOUT(0x9E250);
    JUMPOUT(0x140364);
  }
  sized_strscpy(v12 + 8, v11);
  v15 = *(_QWORD *)(a3 + 304);
  *(_QWORD *)(v12 + 40) = *(_QWORD *)(a3 + 296);
  *(_QWORD *)(v12 + 48) = v15;
  *(_DWORD *)(v12 + 56) = *(_DWORD *)(a3 + 224);
  if ( a5 && *(_QWORD *)a5 )
  {
    *(_DWORD *)(v12 + 60) = **(_DWORD **)a5;
    *(_DWORD *)(v12 + 64) = *(_DWORD *)(*(_QWORD *)a5 + 4LL);
    *(_DWORD *)(v12 + 68) = *(unsigned __int16 *)(*(_QWORD *)a5 + 8LL);
    *(_DWORD *)(v12 + 72) = *(_DWORD *)(a5 + 8);
    *(_DWORD *)(v12 + 76) = *(_DWORD *)(a5 + 12);
    *(_DWORD *)(v12 + 80) = *(unsigned __int16 *)(a5 + 28);
    *(_DWORD *)(v12 + 84) = *(_DWORD *)(a5 + 16);
    *(_WORD *)(v12 + 88) = *(_WORD *)(a5 + 30);
  }
  else
  {
    *(_QWORD *)(v12 + 82) = 0;
    *(_QWORD *)(v12 + 76) = 0;
    *(_QWORD *)(v12 + 68) = 0;
    *(_QWORD *)(v12 + 60) = 0;
  }
  *(_DWORD *)(v12 + 92) = a4;
  result = trace_event_buffer_commit(v17);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
