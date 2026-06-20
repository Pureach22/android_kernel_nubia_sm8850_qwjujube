__int64 __fastcall trace_event_raw_event_rdev_start_nan(__int64 a1, __int64 a2, unsigned __int64 a3, _BYTE *a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  const char *v9; // x23
  __int64 v10; // x21
  size_t v11; // x0
  unsigned __int64 v12; // x2
  int v13; // w8
  _QWORD v14[7]; // [xsp+8h] [xbp-38h] BYREF

  v14[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v14, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_14;
  }
  result = trace_event_buffer_reserve(v14);
  if ( !result )
    goto LABEL_14;
  v9 = *(const char **)(a2 + 504);
  v10 = result;
  if ( !v9 )
    v9 = *(const char **)(a2 + 392);
  v11 = strnlen(v9, 0x20u);
  if ( v11 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_19;
  }
  if ( v11 == 32 )
    v12 = 32;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x21 )
  {
LABEL_19:
    _fortify_panic(7, 32);
    JUMPOUT(0x9C474);
  }
  sized_strscpy(v10 + 8, v9);
  v13 = 0;
  if ( a3 && a3 <= 0xFFFFFFFFFFFFF000LL )
    v13 = *(_DWORD *)(a3 + 40);
  *(_DWORD *)(v10 + 40) = v13;
  *(_BYTE *)(v10 + 44) = *a4;
  *(_BYTE *)(v10 + 45) = a4[1];
  result = trace_event_buffer_commit(v14);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
