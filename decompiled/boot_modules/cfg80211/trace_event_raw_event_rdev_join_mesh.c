__int64 __fastcall trace_event_raw_event_rdev_join_mesh(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x8
  __int64 result; // x0
  const char *v9; // x23
  __int64 v10; // x20
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x8
  __int64 v14; // x0
  _QWORD v15[7]; // [xsp+8h] [xbp-38h] BYREF

  v15[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  memset(v15, 0, 48);
  if ( (v7 & 0x2C0) != 0 && (v7 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_11;
  }
  result = trace_event_buffer_reserve(v15);
  if ( !result )
    goto LABEL_11;
  v9 = *(const char **)(a2 + 504);
  v10 = result;
  if ( !v9 )
    v9 = *(const char **)(a2 + 392);
  v11 = strnlen(v9, 0x20u);
  if ( v11 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v11 == 32 )
      v12 = 32;
    else
      v12 = v11 + 1;
    if ( v12 < 0x21 )
    {
      sized_strscpy(v10 + 8, v9);
      v13 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v10 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v10 + 48) = v13;
      *(_DWORD *)(v10 + 56) = *(_DWORD *)(a3 + 224);
      *(_WORD *)(v10 + 60) = *(_WORD *)a4;
      *(_WORD *)(v10 + 62) = *(_WORD *)(a4 + 2);
      *(_WORD *)(v10 + 64) = *(_WORD *)(a4 + 4);
      *(_WORD *)(v10 + 66) = *(_WORD *)(a4 + 6);
      *(_BYTE *)(v10 + 68) = *(_BYTE *)(a4 + 8);
      *(_BYTE *)(v10 + 69) = *(_BYTE *)(a4 + 9);
      *(_BYTE *)(v10 + 70) = *(_BYTE *)(a4 + 10);
      *(_BYTE *)(v10 + 71) = *(_BYTE *)(a4 + 11);
      *(_DWORD *)(v10 + 72) = *(_DWORD *)(a4 + 12);
      *(_BYTE *)(v10 + 76) = *(_BYTE *)(a4 + 16);
      *(_DWORD *)(v10 + 80) = *(_DWORD *)(a4 + 20);
      *(_DWORD *)(v10 + 84) = *(_DWORD *)(a4 + 28);
      *(_WORD *)(v10 + 88) = *(_WORD *)(a4 + 24);
      *(_WORD *)(v10 + 90) = *(_WORD *)(a4 + 32);
      *(_WORD *)(v10 + 92) = *(_WORD *)(a4 + 34);
      *(_WORD *)(v10 + 94) = *(_WORD *)(a4 + 36);
      *(_BYTE *)(v10 + 96) = *(_BYTE *)(a4 + 38);
      *(_WORD *)(v10 + 98) = *(_WORD *)(a4 + 42);
      *(_BYTE *)(v10 + 100) = *(_BYTE *)(a4 + 44);
      *(_BYTE *)(v10 + 101) = *(_BYTE *)(a4 + 45);
      *(_DWORD *)(v10 + 104) = *(_DWORD *)(a4 + 48);
      *(_WORD *)(v10 + 108) = *(_WORD *)(a4 + 52);
      *(_DWORD *)(v10 + 112) = *(_DWORD *)(a4 + 56);
      *(_WORD *)(v10 + 116) = *(_WORD *)(a4 + 60);
      *(_WORD *)(v10 + 118) = *(_WORD *)(a4 + 62);
      *(_BYTE *)(v10 + 120) = *(_BYTE *)(a4 + 76);
      result = trace_event_buffer_commit(v15);
LABEL_11:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v14 = _fortify_panic(7, 32);
  return perf_trace_rdev_join_mesh(v14);
}
