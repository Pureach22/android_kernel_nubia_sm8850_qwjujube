size_t __fastcall perf_trace_msm_vidc_perf(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x27
  const char *v9; // x8
  const char *v11; // x26
  size_t result; // x0
  __int64 v13; // x20
  unsigned __int64 StatusReg; // x21
  int v15; // w28
  unsigned int v16; // w24
  __int64 v17; // x30
  _QWORD *v18; // x9
  unsigned int v19; // w10
  size_t v20; // x27
  size_t v21; // x25
  size_t v22; // x28
  int v23; // w8
  __int64 v24; // x8
  __int64 v25; // x2
  __int64 v26; // x5
  __int64 v27; // [xsp+0h] [xbp-30h] BYREF
  __int64 v28; // [xsp+8h] [xbp-28h]
  __int64 v29; // [xsp+10h] [xbp-20h]
  unsigned int v30; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v31[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v28 = a4;
  v29 = a5;
  v7 = v5;
  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = (const char *)(a2 + 340);
  if ( !a2 )
    v9 = (const char *)&unk_84D69;
  v31[0] = 0;
  if ( v9 )
    v11 = v9;
  else
    v11 = "(null)";
  v30 = 0;
  result = strlen(v11);
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v15 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v13) )
  {
    v16 = ((result + 100) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v16, v31, &v30);
    if ( result )
    {
      v17 = v7;
      v18 = (_QWORD *)v31[0];
      v19 = (v15 << 16) + 65624;
      *(_QWORD *)(v31[0] + 248LL) = &v27;
      v20 = result + 88;
      v21 = result;
      v18[29] = &vars0;
      v22 = HIWORD(v19) - 1LL;
      v18[32] = v17;
      v18[33] = 5;
      *(_DWORD *)(result + 8) = v19;
      memcpy((void *)(result + 88), v11, v22);
      *(_BYTE *)(v20 + v22) = 0;
      if ( a2 )
      {
        *(_QWORD *)(v21 + 16) = *(_QWORD *)(a2 + 1944);
        *(_QWORD *)(v21 + 24) = *(_QWORD *)(a2 + 1952);
        *(_QWORD *)(v21 + 32) = *(_QWORD *)(a2 + 1960);
        *(_QWORD *)(v21 + 40) = *(_QWORD *)(a2 + 1968);
        *(_QWORD *)(v21 + 48) = *(_QWORD *)(a2 + 1976);
        *(_DWORD *)(v21 + 56) = *(_DWORD *)(a2 + 1984);
        *(_DWORD *)(v21 + 60) = *(_DWORD *)(a2 + 1988);
        v23 = *(_DWORD *)(a2 + 1992);
      }
      else
      {
        v23 = 0;
        *(_QWORD *)(v21 + 48) = 0;
        *(_QWORD *)(v21 + 56) = 0;
        *(_QWORD *)(v21 + 32) = 0;
        *(_QWORD *)(v21 + 40) = 0;
        *(_QWORD *)(v21 + 16) = 0;
        *(_QWORD *)(v21 + 24) = 0;
      }
      *(_DWORD *)(v21 + 64) = v23;
      *(_DWORD *)(v21 + 68) = a3;
      v24 = v29;
      v25 = v30;
      v26 = v31[0];
      *(_QWORD *)(v21 + 72) = v28;
      *(_QWORD *)(v21 + 80) = v24;
      result = perf_trace_run_bpf_submit(v21, v16, v25, a1, 1, v26, StatusReg + v13, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
