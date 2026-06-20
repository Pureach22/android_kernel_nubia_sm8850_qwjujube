__int64 __fastcall trace_event_raw_event_rdev_mgmt_tx(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  const char *v9; // x23
  __int64 v10; // x21
  size_t v11; // x0
  unsigned __int64 v12; // x2
  int v13; // w8
  _DWORD *v14; // x8
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_17;
  }
  result = trace_event_buffer_reserve(v15);
  if ( !result )
    goto LABEL_17;
  v9 = *(const char **)(a2 + 504);
  v10 = result;
  if ( !v9 )
    v9 = *(const char **)(a2 + 392);
  v11 = strnlen(v9, 0x20u);
  if ( v11 == -1 )
  {
    _fortify_panic(2, -1);
    goto LABEL_22;
  }
  if ( v11 == 32 )
    v12 = 32;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x21 )
  {
LABEL_22:
    _fortify_panic(7, 32);
    JUMPOUT(0x9B5FC);
  }
  sized_strscpy(v10 + 8, v9);
  v13 = 0;
  if ( a3 && a3 <= 0xFFFFFFFFFFFFF000LL )
    v13 = *(_DWORD *)(a3 + 40);
  *(_DWORD *)(v10 + 40) = v13;
  v14 = *(_DWORD **)a4;
  if ( *(_QWORD *)a4 )
  {
    *(_DWORD *)(v10 + 44) = *v14;
    *(_DWORD *)(v10 + 48) = *(_DWORD *)(*(_QWORD *)a4 + 4LL);
    LOWORD(v14) = *(_WORD *)(*(_QWORD *)a4 + 8LL);
  }
  else
  {
    *(_QWORD *)(v10 + 44) = 0;
  }
  *(_WORD *)(v10 + 52) = (_WORD)v14;
  *(_BYTE *)(v10 + 54) = *(_BYTE *)(a4 + 8);
  *(_DWORD *)(v10 + 56) = *(_DWORD *)(a4 + 12);
  *(_BYTE *)(v10 + 60) = *(_BYTE *)(a4 + 32);
  *(_BYTE *)(v10 + 61) = *(_BYTE *)(a4 + 33);
  result = trace_event_buffer_commit(v15);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
