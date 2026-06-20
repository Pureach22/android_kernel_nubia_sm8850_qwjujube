_DWORD *__fastcall perf_trace_msm_v4l2_vidc_buffer_events(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x30
  __int64 v9; // x26
  _DWORD *result; // x0
  __int64 v15; // x28
  unsigned __int64 StatusReg; // x23
  unsigned int v17; // w21
  __int64 v18; // x30
  _QWORD *v19; // x9
  int v20; // w11
  int v21; // w8
  const char *v22; // x12
  char *v23; // x26
  _DWORD *v24; // x22
  int v25; // w9
  const char *v26; // x1
  size_t v27; // x27
  int v28; // w8
  char *v29; // x26
  const char *v30; // x1
  size_t v31; // x27
  int v32; // w8
  char *v33; // x26
  const char *v34; // x1
  size_t v35; // x27
  __int64 v36; // x9
  __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v40; // x2
  _QWORD *v41; // x5
  __int64 v42; // [xsp+0h] [xbp-60h] BYREF
  __int64 v43; // [xsp+8h] [xbp-58h]
  __int64 v44; // [xsp+10h] [xbp-50h]
  unsigned int v45; // [xsp+1Ch] [xbp-44h] BYREF
  _QWORD *v46; // [xsp+20h] [xbp-40h] BYREF
  __int64 v47; // [xsp+28h] [xbp-38h] BYREF
  const char *v48; // [xsp+30h] [xbp-30h]
  __int64 v49; // [xsp+38h] [xbp-28h]
  const char *v50; // [xsp+40h] [xbp-20h]
  __int64 v51; // [xsp+48h] [xbp-18h]
  const char *v52; // [xsp+50h] [xbp-10h]
  __int64 v53; // [xsp+58h] [xbp-8h]
  __int64 vars0; // [xsp+60h] [xbp+0h] BYREF

  v9 = v7;
  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v52 = nullptr;
  v49 = 0;
  v50 = nullptr;
  v47 = 0;
  v48 = nullptr;
  v46 = nullptr;
  v45 = 0;
  result = (_DWORD *)trace_event_get_offsets_msm_v4l2_vidc_buffer_events(&v47, a2);
  v15 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v15) )
  {
    v17 = (((_DWORD)result + 131) & 0xFFFFFFF8) - 4;
    result = (_DWORD *)perf_trace_buf_alloc(v17, &v46, &v45);
    if ( result )
    {
      v18 = v9;
      v43 = a6;
      v44 = a7;
      v19 = v46;
      v20 = v47;
      v46[31] = &v42;
      v21 = v49;
      v22 = v48;
      v19[29] = &vars0;
      v23 = (char *)result + (unsigned __int16)v20;
      v24 = result;
      v19[32] = v18;
      v19[33] = 5;
      v25 = v51;
      result[2] = v20;
      result[3] = v21;
      if ( v22 )
        v26 = v22;
      else
        v26 = "(null)";
      result[4] = v25;
      v27 = HIWORD(v20) - 1LL;
      memcpy((char *)result + (unsigned __int16)v20, v26, v27);
      v23[v27] = 0;
      v28 = v24[3];
      v29 = (char *)v24 + (unsigned __int16)v28;
      if ( v50 )
        v30 = v50;
      else
        v30 = "(null)";
      v31 = HIWORD(v28) - 1LL;
      memcpy(v29, v30, v31);
      v29[v31] = 0;
      v32 = v24[4];
      v33 = (char *)v24 + (unsigned __int16)v32;
      if ( v52 )
        v34 = v52;
      else
        v34 = "(null)";
      v35 = HIWORD(v32) - 1LL;
      memcpy(v33, v34, v35);
      v33[v35] = 0;
      if ( a5 )
      {
        v36 = v43;
        v24[5] = *(_DWORD *)(a5 + 32);
        v24[6] = *(_DWORD *)(a5 + 36);
        v24[7] = *(_DWORD *)(a5 + 44);
        *((_QWORD *)v24 + 4) = *(_QWORD *)(a5 + 56);
        *((_QWORD *)v24 + 5) = v36;
        *((_QWORD *)v24 + 6) = v44;
        v24[14] = *(_DWORD *)(a5 + 40);
        v24[15] = *(_DWORD *)(a5 + 48);
        v24[16] = *(_DWORD *)(a5 + 64);
        *((_QWORD *)v24 + 9) = *(_QWORD *)(a5 + 72);
        v24[20] = *(_DWORD *)(a5 + 80);
        if ( a2 )
        {
LABEL_15:
          *((_QWORD *)v24 + 11) = a2[529];
          *((_QWORD *)v24 + 12) = a2[532];
          *((_QWORD *)v24 + 13) = a2[530];
          v37 = a2[531];
LABEL_18:
          v40 = v45;
          v41 = v46;
          *((_QWORD *)v24 + 14) = v37;
          result = (_DWORD *)perf_trace_run_bpf_submit(v24, v17, v40, a1, 1, v41, StatusReg + v15, 0);
          goto LABEL_19;
        }
      }
      else
      {
        *((_QWORD *)v24 + 3) = 0;
        *((_QWORD *)v24 + 4) = 0;
        v24[5] = -1;
        v39 = v43;
        v38 = v44;
        *((_QWORD *)v24 + 7) = 0;
        v24[16] = 0;
        *((_QWORD *)v24 + 5) = v39;
        *((_QWORD *)v24 + 6) = v38;
        *((_QWORD *)v24 + 9) = 0;
        v24[20] = 0;
        if ( a2 )
          goto LABEL_15;
      }
      v37 = 0;
      *((_QWORD *)v24 + 12) = 0;
      *((_QWORD *)v24 + 13) = 0;
      *((_QWORD *)v24 + 11) = 0;
      goto LABEL_18;
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
