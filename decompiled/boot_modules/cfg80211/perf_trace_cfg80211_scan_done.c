__int64 __fastcall perf_trace_cfg80211_scan_done(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v4; // x23
  __int64 v7; // x19
  int v8; // w26
  __int64 v9; // x24
  unsigned __int64 StatusReg; // x25
  unsigned int v11; // w22
  _QWORD *v12; // x9
  __int64 v13; // x23
  int v14; // w9
  __int64 v15; // x8
  __int64 v16; // x8
  __int16 v17; // w9
  int v18; // w8
  int v19; // w9
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v3;
  v7 = result;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v8 = *(_DWORD *)(a2 + 24);
  else
    v8 = 0;
  v22[0] = 0;
  v9 = *(_QWORD *)(result + 104);
  v21 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v11 = ((v8 + 83) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v11, v22, &v21);
    if ( result )
    {
      v12 = (_QWORD *)v22[0];
      *(_QWORD *)(v22[0] + 232LL) = &vars0;
      v12[31] = &v20;
      v12[32] = v4;
      v12[33] = 5;
      *(_DWORD *)(result + 12) = (v8 << 16) | 0x46;
      if ( a2 )
      {
        v13 = result;
        memcpy((void *)(result + *(unsigned __int16 *)(result + 12)), *(const void **)(a2 + 16), *(_QWORD *)(a2 + 24));
        v14 = *(_DWORD *)(a2 + 40);
        result = v13;
        *(_WORD *)(v13 + 20) = *(_WORD *)(a2 + 44);
        *(_DWORD *)(v13 + 16) = v14;
        v15 = *(_QWORD *)(a2 + 64);
        if ( v15 )
          LODWORD(v15) = *(_DWORD *)(v15 + 40);
        *(_DWORD *)(v13 + 40) = v15;
        v16 = *(_QWORD *)(a2 + 96);
        if ( v16 )
        {
          v17 = *(_WORD *)(v16 + 52);
          v18 = *(_DWORD *)(v16 + 48);
          *(_WORD *)(v13 + 48) = v17;
          *(_DWORD *)(v13 + 44) = v18;
        }
        *(_BYTE *)(v13 + 50) = *(_BYTE *)(a2 + 129);
      }
      if ( a3 )
      {
        *(_BYTE *)(result + 51) = *(_BYTE *)(a3 + 14);
        *(_QWORD *)(result + 56) = *(_QWORD *)a3;
        v19 = *(_DWORD *)(a3 + 8);
        *(_WORD *)(result + 68) = *(_WORD *)(a3 + 12);
        *(_DWORD *)(result + 64) = v19;
      }
      result = perf_trace_run_bpf_submit(result, v11, v21, v7, 1, v22[0], StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
