size_t __fastcall perf_trace_cam_req_mgr_add_req(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x30
  __int64 v8; // x27
  size_t result; // x0
  int v14; // w28
  unsigned __int64 StatusReg; // x24
  unsigned int v16; // w23
  __int64 v17; // x30
  _QWORD *v18; // x9
  unsigned int v19; // w10
  size_t v20; // x27
  size_t v21; // x26
  size_t v22; // x28
  void *v23; // x0
  __int64 v24; // x8
  __int64 v25; // x2
  __int64 v26; // x5
  int v27; // w8
  __int64 v28; // [xsp+0h] [xbp-30h] BYREF
  __int64 v29; // [xsp+8h] [xbp-28h]
  __int64 v30; // [xsp+10h] [xbp-20h]
  unsigned int v31; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+30h] [xbp+0h] BYREF

  v29 = a4;
  v8 = v6;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  v31 = 0;
  result = strlen((const char *)(a6 + 28));
  v14 = result;
  v30 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v30) )
    goto LABEL_6;
  v16 = ((result + 76) & 0xFFFFFFF8) - 4;
  result = perf_trace_buf_alloc(v16, v32, &v31);
  if ( !result )
    goto LABEL_6;
  v17 = v8;
  v18 = (_QWORD *)v32[0];
  v19 = (v14 << 16) + 65596;
  *(_QWORD *)(v32[0] + 248LL) = &v28;
  v20 = result + 60;
  v21 = result;
  v18[29] = &vars0;
  v22 = HIWORD(v19) - 1LL;
  v18[32] = v17;
  v18[33] = 5;
  *(_DWORD *)(result + 8) = v19;
  v23 = memcpy((void *)(result + 60), (const void *)(a6 + 28), v22);
  *(_BYTE *)(v20 + v22) = 0;
  *(_DWORD *)(v21 + 12) = *(_DWORD *)(a6 + 284);
  v24 = *(_QWORD *)(v29 + 8);
  *(_DWORD *)(v21 + 24) = a3;
  *(_QWORD *)(v21 + 16) = v24;
  *(_DWORD *)(v21 + 28) = *(_DWORD *)(a5 + 4);
  if ( a3 < 0x30 )
  {
    v25 = v31;
    v26 = v32[0];
    *(_DWORD *)(v21 + 32) = *(_DWORD *)(a5 + 48LL * a3 + 44);
    v27 = *(_DWORD *)(a5 + 12);
    *(_QWORD *)(v21 + 40) = a2;
    *(_DWORD *)(v21 + 36) = v27;
    *(_DWORD *)(v21 + 56) = *(_DWORD *)a2;
    *(_QWORD *)(v21 + 48) = *(_QWORD *)(a2 + 33160);
    result = perf_trace_run_bpf_submit(v21, v16, v25, a1, 1, v26, StatusReg + v30, 0);
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return trace_event_raw_event_cam_delay_detect(v23);
}
