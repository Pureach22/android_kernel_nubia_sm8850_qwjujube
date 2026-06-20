__int64 __fastcall trace_event_raw_event_rdev_remain_on_channel(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        int a5)
{
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x24
  __int64 v12; // x22
  size_t v13; // x0
  unsigned __int64 v14; // x2
  int v15; // w8
  __int16 v16; // w8
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v17, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_17;
  }
  result = trace_event_buffer_reserve(v17);
  if ( !result )
    goto LABEL_17;
  v11 = *(const char **)(a2 + 504);
  v12 = result;
  if ( !v11 )
    v11 = *(const char **)(a2 + 392);
  v13 = strnlen(v11, 0x20u);
  if ( v13 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_22;
  }
  if ( v13 == 32 )
    v14 = 32;
  else
    v14 = v13 + 1;
  if ( v14 >= 0x21 )
  {
LABEL_22:
    _fortify_panic(7, 32);
    JUMPOUT(0x9ADC4);
  }
  sized_strscpy(v12 + 8, v11);
  v15 = 0;
  if ( a3 && a3 <= 0xFFFFFFFFFFFFF000LL )
    v15 = *(_DWORD *)(a3 + 40);
  *(_DWORD *)(v12 + 40) = v15;
  if ( a4 )
  {
    *(_DWORD *)(v12 + 44) = *(_DWORD *)a4;
    *(_DWORD *)(v12 + 48) = *(_DWORD *)(a4 + 4);
    v16 = *(_WORD *)(a4 + 8);
  }
  else
  {
    v16 = 0;
    *(_QWORD *)(v12 + 44) = 0;
  }
  *(_WORD *)(v12 + 52) = v16;
  *(_DWORD *)(v12 + 56) = a5;
  result = trace_event_buffer_commit(v17);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
