__int64 __fastcall perf_trace_netdev_frame_event(__int64 result, __int64 a2, const void *a3, int a4)
{
  __int64 v4; // x30
  __int64 v5; // x24
  __int64 v8; // x19
  __int64 v10; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v12; // w21
  _QWORD *v13; // x9
  size_t v14; // x2
  int v15; // w10
  __int64 v16; // x22
  __int64 v17; // x8
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v19; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 vars0; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v19 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    v12 = ((a4 + 43) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v12, v20, &v19);
    if ( result )
    {
      v13 = (_QWORD *)v20[0];
      v14 = a4;
      *(_QWORD *)(v20[0] + 232LL) = &vars0;
      v13[31] = &v18;
      v13[32] = v5;
      v13[33] = 5;
      v15 = (a4 << 16) | 0x20;
      v16 = result;
      *(_DWORD *)(result + 28) = v15;
      v17 = *(_QWORD *)(a2 + 304);
      *(_QWORD *)(result + 8) = *(_QWORD *)(a2 + 296);
      *(_QWORD *)(result + 16) = v17;
      *(_DWORD *)(result + 24) = *(_DWORD *)(a2 + 224);
      memcpy((void *)(result + (unsigned __int16)v15), a3, v14);
      result = perf_trace_run_bpf_submit(v16, v12, v19, v8, 1, v20[0], StatusReg + v10, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
