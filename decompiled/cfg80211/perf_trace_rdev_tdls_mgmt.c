__int64 __fastcall perf_trace_rdev_tdls_mgmt(
        __int64 result,
        __int64 a2,
        __int64 a3,
        int *a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        char a10,
        const void *a11,
        size_t a12)
{
  __int64 v12; // x30
  short float v13; // h8
  __int64 v14; // x21
  __int64 v15; // x19
  __int64 v19; // x22
  unsigned __int64 StatusReg; // x24
  unsigned int v21; // w23
  _QWORD *v22; // x9
  __int64 v23; // x25
  const char *v24; // x21
  size_t v25; // x0
  unsigned __int64 v26; // x2
  __int64 v27; // x8
  int v28; // w9
  char v29; // w8
  int v30; // w9
  __int64 v31; // x8
  long double v32; // q0
  short float v33; // h20
  short float v34; // h28
  float v35; // s1
  __int64 v36; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int64 v37; // [xsp+8h] [xbp-38h]
  __int64 v38; // [xsp+10h] [xbp-30h]
  int v39; // [xsp+1Ch] [xbp-24h]
  int v40; // [xsp+20h] [xbp-20h]
  int v41; // [xsp+24h] [xbp-1Ch]
  int v42; // [xsp+28h] [xbp-18h]
  unsigned int v43; // [xsp+2Ch] [xbp-14h] BYREF
  _QWORD v44[2]; // [xsp+30h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v41 = a7;
  v42 = a8;
  v14 = v12;
  v15 = result;
  v39 = a5;
  v40 = a6;
  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44[0] = 0;
  v19 = *(_QWORD *)(result + 104);
  v43 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(result + 112) && !*(_QWORD *)(StatusReg + v19) )
    goto LABEL_15;
  v21 = ((a12 + 99) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v21, v44, &v43);
  if ( !result )
    goto LABEL_15;
  v22 = (_QWORD *)v44[0];
  *(_QWORD *)(v44[0] + 232LL) = &vars0;
  v23 = result;
  v22[31] = &v36;
  v22[32] = v14;
  v22[33] = 5;
  *(_DWORD *)(result + 84) = ((_DWORD)a12 << 16) | 0x58;
  v24 = *(const char **)(a2 + 504);
  if ( !v24 )
    v24 = *(const char **)(a2 + 392);
  v25 = strnlen(v24, 0x20u);
  if ( v25 == -1 )
  {
    _fortify_panic(2, -1);
  }
  else
  {
    v37 = StatusReg;
    v38 = v19;
    if ( v25 == 32 )
      v26 = 32;
    else
      v26 = v25 + 1;
    if ( v26 < 0x21 )
    {
      sized_strscpy(v23 + 8, v24);
      v27 = *(_QWORD *)(a3 + 304);
      *(_QWORD *)(v23 + 40) = *(_QWORD *)(a3 + 296);
      *(_QWORD *)(v23 + 48) = v27;
      *(_DWORD *)(v23 + 56) = *(_DWORD *)(a3 + 224);
      if ( a4 )
      {
        v28 = *a4;
        *(_WORD *)(v23 + 64) = *((_WORD *)a4 + 2);
        *(_DWORD *)(v23 + 60) = v28;
      }
      else
      {
        *(_WORD *)(v23 + 64) = 0;
        *(_DWORD *)(v23 + 60) = 0;
      }
      v30 = v39;
      v29 = v40;
      *(_DWORD *)(v23 + 76) = a9;
      *(_BYTE *)(v23 + 80) = a10 & 1;
      *(_DWORD *)(v23 + 68) = v30;
      *(_BYTE *)(v23 + 72) = v29;
      LOBYTE(v30) = v41;
      *(_WORD *)(v23 + 74) = v42;
      v31 = *(unsigned __int16 *)(v23 + 84);
      *(_BYTE *)(v23 + 73) = v30;
      memcpy((void *)(v23 + v31), a11, a12);
      result = perf_trace_run_bpf_submit(v23, v21, v43, v15, 1, v44[0], v37 + v38, 0);
LABEL_15:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v32 = _fortify_panic(7, 32);
  *(short float *)&v35 = v34 - (short float)(v33 * v13);
  return trace_event_raw_event_rdev_dump_survey(v32, v35);
}
