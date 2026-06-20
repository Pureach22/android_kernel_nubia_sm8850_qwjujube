// positive sp value has been detected, the output may be wrong!
__int64 __fastcall perf_trace_wiphy_only_evt(__int64 result, __int64 a2)
{
  __int64 v2; // x25
  __int64 v3; // x26
  char v4; // w28
  __int64 v5; // x30
  __int64 v6; // x22
  __int64 v7; // x19
  __int64 v9; // x23
  unsigned __int64 StatusReg; // x24
  _QWORD *v11; // x9
  __int64 v12; // x20
  __int64 v13; // x22
  size_t v14; // x0
  unsigned __int64 v15; // x2
  char v16; // zf
  __int64 v17; // x0
  unsigned __int64 v18; // x2
  __int64 v19; // x8
  __int64 v20; // x2
  __int64 v21; // x5
  __int64 v22; // [xsp-10h] [xbp-30h] BYREF
  unsigned int v23; // [xsp-4h] [xbp-24h] BYREF
  _QWORD v24[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v25; // [xsp+10h] [xbp-10h] BYREF

  v6 = v5;
  v7 = result;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v9 = *(_QWORD *)(result + 104);
  v23 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v9) )
    goto LABEL_12;
  result = perf_trace_buf_alloc(44, v24, &v23);
  if ( !result )
    goto LABEL_12;
  v11 = (_QWORD *)v24[0];
  v12 = result;
  *(_QWORD *)(v24[0] + 232LL) = &v25;
  v11[33] = 5;
  v11[31] = &v22;
  v11[32] = v6;
  v13 = *(_QWORD *)(a2 + 504);
  if ( !v13 )
    v13 = *(_QWORD *)(a2 + 392);
  v14 = strnlen((const char *)v13, 0x20u);
  if ( v14 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    if ( v14 == 32 )
      v15 = 32;
    else
      v15 = v14 + 1;
    if ( v15 < 0x21 )
    {
      sized_strscpy(v12 + 8, v13);
      result = perf_trace_run_bpf_submit(v12, 44, v23, v7, 1, v24[0], StatusReg + v9, 0);
LABEL_12:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v17 = _fortify_panic(7, 32);
  if ( (v4 & 8) == 0 )
    return ((__int64 (__fastcall *)(__int64))trace_event_raw_event_wiphy_enabled_evt)(v17);
  if ( v16 )
  {
    _fortify_panic(2, -1);
    goto LABEL_23;
  }
  if ( v17 == 32 )
    v18 = 32;
  else
    v18 = v17 + 1;
  if ( v18 >= 0x21 )
  {
LABEL_23:
    _fortify_panic(7, 32);
    JUMPOUT(0x944E0);
  }
  sized_strscpy(a2 + 8, StatusReg);
  v19 = *(_QWORD *)(v13 + 304);
  v20 = v23;
  v21 = v24[0];
  *(_QWORD *)(a2 + 40) = *(_QWORD *)(v13 + 296);
  *(_QWORD *)(a2 + 48) = v19;
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(v13 + 224);
  *(_WORD *)(a2 + 60) = *(_WORD *)v12;
  *(_WORD *)(a2 + 62) = *(_WORD *)(v12 + 2);
  *(_WORD *)(a2 + 64) = *(_WORD *)(v12 + 4);
  *(_WORD *)(a2 + 66) = *(_WORD *)(v12 + 6);
  *(_BYTE *)(a2 + 68) = *(_BYTE *)(v12 + 8);
  *(_BYTE *)(a2 + 69) = *(_BYTE *)(v12 + 9);
  *(_BYTE *)(a2 + 70) = *(_BYTE *)(v12 + 10);
  *(_BYTE *)(a2 + 71) = *(_BYTE *)(v12 + 11);
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(v12 + 12);
  *(_BYTE *)(a2 + 76) = *(_BYTE *)(v12 + 16);
  *(_DWORD *)(a2 + 80) = *(_DWORD *)(v12 + 20);
  *(_DWORD *)(a2 + 84) = *(_DWORD *)(v12 + 28);
  *(_WORD *)(a2 + 88) = *(_WORD *)(v12 + 24);
  *(_WORD *)(a2 + 90) = *(_WORD *)(v12 + 32);
  *(_WORD *)(a2 + 92) = *(_WORD *)(v12 + 34);
  *(_WORD *)(a2 + 94) = *(_WORD *)(v12 + 36);
  *(_BYTE *)(a2 + 96) = *(_BYTE *)(v12 + 38);
  *(_WORD *)(a2 + 98) = *(_WORD *)(v12 + 42);
  *(_BYTE *)(a2 + 100) = *(_BYTE *)(v12 + 44);
  *(_BYTE *)(a2 + 101) = *(_BYTE *)(v12 + 45);
  *(_DWORD *)(a2 + 104) = *(_DWORD *)(v12 + 48);
  *(_WORD *)(a2 + 108) = *(_WORD *)(v12 + 52);
  *(_DWORD *)(a2 + 112) = *(_DWORD *)(v12 + 56);
  *(_WORD *)(a2 + 116) = *(_WORD *)(v12 + 60);
  *(_WORD *)(a2 + 118) = *(_WORD *)(v12 + 62);
  *(_BYTE *)(a2 + 120) = *(_BYTE *)(v12 + 76);
  result = perf_trace_run_bpf_submit(a2, 124, v20, v7, 1, v21, v3 + v2, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
