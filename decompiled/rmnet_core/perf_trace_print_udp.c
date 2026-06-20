__int64 __fastcall perf_trace_print_udp(__int64 a1, __int64 a2, __int64 a3, __int64 a4, _WORD *a5, __int16 a6)
{
  __int64 v6; // x30
  __int64 v9; // x24
  __int64 result; // x0
  __int64 v13; // x26
  unsigned __int64 StatusReg; // x27
  unsigned int v15; // w22
  _QWORD *v16; // x9
  int v17; // w8
  __int64 v18; // x25
  int v19; // w10
  const char *v20; // x9
  int v21; // w11
  __int64 v22; // x23
  const char *v23; // x1
  size_t v24; // x24
  int v25; // w8
  void *v26; // x23
  const char *v27; // x1
  size_t v28; // x24
  __int64 v29; // x2
  _QWORD *v30; // x5
  __int16 v31; // w8
  __int64 v32; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v33; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v34; // [xsp+10h] [xbp-30h] BYREF
  __int64 v35; // [xsp+18h] [xbp-28h] BYREF
  const char *v36; // [xsp+20h] [xbp-20h]
  __int64 v37; // [xsp+28h] [xbp-18h]
  const char *v38; // [xsp+30h] [xbp-10h]
  __int64 v39; // [xsp+38h] [xbp-8h]
  __int64 vars0; // [xsp+40h] [xbp+0h] BYREF

  v9 = v6;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = nullptr;
  v35 = 0;
  v36 = nullptr;
  v34 = nullptr;
  v33 = 0;
  result = trace_event_get_offsets_print_udp(&v35, a3, a4);
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v13) )
  {
    v15 = ((result + 51) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v15, &v34, &v33);
    if ( result )
    {
      v16 = v34;
      v34[31] = &v32;
      v17 = v37;
      v16[29] = &vars0;
      v18 = result;
      v16[32] = v9;
      v16[33] = 5;
      v19 = v35;
      v20 = v36;
      *(_QWORD *)(result + 8) = a2;
      *(_DWORD *)(result + 20) = v19;
      *(_DWORD *)(result + 24) = v17;
      v21 = *(_DWORD *)(a2 + 112);
      v22 = result + (unsigned __int16)v19;
      if ( v20 )
        v23 = v20;
      else
        v23 = "(null)";
      v24 = HIWORD(v19) - 1LL;
      *(_DWORD *)(result + 16) = v21;
      memcpy((void *)(result + (unsigned __int16)v19), v23, v24);
      *(_BYTE *)(v22 + v24) = 0;
      v25 = *(_DWORD *)(v18 + 24);
      v26 = (void *)(v18 + (unsigned __int16)v25);
      if ( v38 )
        v27 = v38;
      else
        v27 = "(null)";
      v28 = HIWORD(v25) - 1LL;
      memcpy(v26, v27, v28);
      *((_BYTE *)v26 + v28) = 0;
      v29 = v33;
      v30 = v34;
      *(_WORD *)(v18 + 28) = *a5;
      v31 = a5[1];
      *(_WORD *)(v18 + 32) = a6;
      *(_WORD *)(v18 + 30) = v31;
      result = perf_trace_run_bpf_submit(v18, v15, v29, a1, 1, v30, StatusReg + v13, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
