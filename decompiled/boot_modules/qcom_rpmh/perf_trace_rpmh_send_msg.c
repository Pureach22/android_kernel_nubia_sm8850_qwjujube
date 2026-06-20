size_t __fastcall perf_trace_rpmh_send_msg(__int64 a1, const char *a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  __int64 v7; // x30
  __int64 v9; // x27
  const char *v13; // x26
  size_t result; // x0
  __int64 v15; // x22
  unsigned __int64 StatusReg; // x23
  int v17; // w28
  unsigned int v18; // w25
  __int64 v19; // x30
  _QWORD *v20; // x9
  unsigned int v21; // w10
  size_t v22; // x27
  int v23; // w22
  size_t v24; // x21
  size_t v25; // x28
  int v26; // w8
  int v27; // w9
  __int64 v28; // x2
  __int64 v29; // x5
  __int64 v30; // [xsp+0h] [xbp-30h] BYREF
  __int64 v31; // [xsp+8h] [xbp-28h]
  int v32; // [xsp+14h] [xbp-1Ch]
  int v33; // [xsp+18h] [xbp-18h]
  unsigned int v34; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v35[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v32 = a3;
  v33 = a4;
  v9 = v7;
  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v13 = a2;
  else
    v13 = "(null)";
  v35[0] = 0;
  v34 = 0;
  result = strlen(v13);
  v15 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v17 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v15) )
  {
    v18 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v18, v35, &v34);
    if ( result )
    {
      v19 = v9;
      v20 = (_QWORD *)v35[0];
      v21 = (v17 << 16) + 65573;
      *(_QWORD *)(v35[0] + 248LL) = &v30;
      v22 = result + 37;
      v20[29] = &vars0;
      v31 = v15;
      v23 = a6;
      v24 = result;
      v25 = HIWORD(v21) - 1LL;
      v20[32] = v19;
      v20[33] = 5;
      *(_DWORD *)(result + 8) = v21;
      memcpy((void *)(result + 37), v13, v25);
      v27 = v32;
      v26 = v33;
      *(_BYTE *)(v22 + v25) = 0;
      *(_DWORD *)(v24 + 20) = a5;
      *(_DWORD *)(v24 + 24) = v23;
      v28 = v34;
      v29 = v35[0];
      *(_DWORD *)(v24 + 12) = v27;
      *(_DWORD *)(v24 + 16) = v26;
      *(_DWORD *)(v24 + 28) = *a7;
      *(_DWORD *)(v24 + 32) = a7[1];
      *(_BYTE *)(v24 + 36) = a7[2] != 0;
      result = perf_trace_run_bpf_submit(v24, v18, v28, a1, 1, v29, StatusReg + v31, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
