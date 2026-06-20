size_t __fastcall perf_trace_ufs_qcom_pm_template(
        __int64 a1,
        const char *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  __int64 v8; // x30
  __int64 v10; // x27
  const char *v14; // x26
  size_t result; // x0
  __int64 v18; // x23
  int v19; // w28
  __int64 v20; // x30
  _QWORD *v21; // x9
  unsigned int v22; // w10
  size_t v23; // x27
  int v24; // w23
  _DWORD *v25; // x20
  size_t v26; // x28
  int v27; // w8
  int v28; // w9
  __int64 v29; // x2
  __int64 v30; // x5
  __int64 v31; // x1
  unsigned __int64 v32; // x8
  __int64 v33; // x9
  __int64 v34; // [xsp+0h] [xbp-30h] BYREF
  int v35; // [xsp+8h] [xbp-28h]
  int v36; // [xsp+Ch] [xbp-24h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-20h]
  unsigned int v38; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v39[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v36 = a3;
  v10 = v8;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v14 = a2;
  else
    v14 = "(null)";
  v39[0] = 0;
  v38 = 0;
  result = strlen(v14);
  v18 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v19 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v18) )
  {
    v35 = result & 0xFFFFFFF8;
    result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 44, v39, &v38);
    if ( result )
    {
      v20 = v10;
      v21 = (_QWORD *)v39[0];
      v22 = (v19 << 16) + 65572;
      *(_QWORD *)(v39[0] + 248LL) = &v34;
      v23 = result + 36;
      v21[29] = &vars0;
      v34 = v18;
      v24 = a8;
      v25 = (_DWORD *)result;
      v26 = HIWORD(v22) - 1LL;
      v21[32] = v20;
      v21[33] = 5;
      *(_DWORD *)(result + 8) = v22;
      memcpy((void *)(result + 36), v14, v26);
      v27 = v35;
      v28 = v36;
      *(_BYTE *)(v23 + v26) = 0;
      v29 = v38;
      v30 = v39[0];
      v25[3] = v28;
      v25[4] = a4;
      v31 = (unsigned int)(v27 + 44);
      v32 = StatusReg;
      v33 = v34;
      v25[5] = a5;
      v25[6] = a6;
      v25[7] = a7;
      v25[8] = v24;
      result = perf_trace_run_bpf_submit(v25, v31, v29, a1, 1, v30, v32 + v33, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
