size_t __fastcall perf_trace_cam_req_mgr_connect_device(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v5; // x23
  size_t result; // x0
  __int64 v9; // x26
  unsigned __int64 StatusReg; // x27
  int v11; // w24
  unsigned int v12; // w22
  __int64 v13; // x30
  _QWORD *v14; // x9
  unsigned int v15; // w10
  size_t v16; // x23
  size_t v17; // x25
  size_t v18; // x24
  __int64 v19; // x2
  __int64 v20; // x5
  int v21; // w8
  __int64 v22; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v23; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v25; // [xsp+20h] [xbp+0h] BYREF

  v5 = v3;
  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 0;
  v23 = 0;
  result = strlen((const char *)(a3 + 4));
  v9 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  v11 = result;
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v9) )
  {
    v12 = ((result + 52) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v12, v24, &v23);
    if ( result )
    {
      v13 = v5;
      v14 = (_QWORD *)v24[0];
      v15 = (v11 << 16) + 65576;
      *(_QWORD *)(v24[0] + 248LL) = &v22;
      v16 = result + 40;
      v14[29] = &v25;
      v17 = result;
      v18 = HIWORD(v15) - 1LL;
      v14[32] = v13;
      v14[33] = 5;
      *(_DWORD *)(result + 8) = v15;
      memcpy((void *)(result + 40), (const void *)(a3 + 4), v18);
      *(_BYTE *)(v16 + v18) = 0;
      v19 = v23;
      v20 = v24[0];
      *(_DWORD *)(v17 + 12) = *(_DWORD *)(a3 + 260);
      v21 = *(_DWORD *)(a3 + 264);
      *(_QWORD *)(v17 + 24) = a2;
      *(_DWORD *)(v17 + 16) = v21;
      *(_QWORD *)(v17 + 32) = *(_QWORD *)(a2 + 33160);
      result = perf_trace_run_bpf_submit(v17, v12, v19, a1, 1, v20, StatusReg + v9, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
