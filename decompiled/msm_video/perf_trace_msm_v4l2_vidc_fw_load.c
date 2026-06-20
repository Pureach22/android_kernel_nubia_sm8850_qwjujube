size_t __fastcall perf_trace_msm_v4l2_vidc_fw_load(__int64 a1, const char *a2)
{
  __int64 v2; // x30
  __int64 v4; // x21
  const char *v5; // x20
  size_t result; // x0
  __int64 v7; // x24
  unsigned __int64 StatusReg; // x25
  int v9; // w22
  int v10; // w26
  __int64 v11; // x30
  _QWORD *v12; // x9
  unsigned int v13; // w10
  size_t v14; // x21
  size_t v15; // x23
  size_t v16; // x22
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v18; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v4 = v2;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v5 = a2;
  else
    v5 = "(null)";
  v19[0] = 0;
  v18 = 0;
  result = strlen(v5);
  v7 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v9 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v7) )
  {
    v10 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 20, v19, &v18);
    if ( result )
    {
      v11 = v4;
      v12 = (_QWORD *)v19[0];
      v13 = (v9 << 16) + 65548;
      *(_QWORD *)(v19[0] + 248LL) = &v17;
      v14 = result + 12;
      v12[29] = &vars0;
      v15 = result;
      v16 = HIWORD(v13) - 1LL;
      v12[32] = v11;
      v12[33] = 5;
      *(_DWORD *)(result + 8) = v13;
      memcpy((void *)(result + 12), v5, v16);
      *(_BYTE *)(v14 + v16) = 0;
      result = perf_trace_run_bpf_submit(v15, (unsigned int)(v10 + 20), v18, a1, 1, v19[0], StatusReg + v7, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
