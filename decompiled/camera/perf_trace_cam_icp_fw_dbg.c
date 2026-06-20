__int64 __fastcall perf_trace_cam_icp_fw_dbg(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x30
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v8; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v10; // w21
  _QWORD *v11; // x9
  int v12; // w8
  __int64 v13; // x24
  int v14; // w10
  const char *v15; // x9
  void *v16; // x22
  __int64 v17; // x10
  const char *v18; // x1
  __int64 v19; // x23
  const char *v20; // x10
  int v21; // w8
  void *v22; // x22
  const char *v23; // x1
  size_t v24; // x20
  __int64 v25; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v26; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD *v27; // [xsp+10h] [xbp-30h] BYREF
  __int64 v28; // [xsp+18h] [xbp-28h] BYREF
  const char *v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  const char *v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]
  __int64 v33; // [xsp+40h] [xbp+0h] BYREF

  v6 = v3;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = nullptr;
  v28 = 0;
  v29 = nullptr;
  v27 = nullptr;
  v26 = 0;
  result = trace_event_get_offsets_cam_icp_fw_dbg(&v28);
  v8 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(a1 + 112) || *(_QWORD *)(StatusReg + v8) )
  {
    v10 = ((result + 43) & 0xFFFFFFF8) - 4;
    result = perf_trace_buf_alloc(v10, &v27, &v26);
    if ( result )
    {
      v11 = v27;
      v27[31] = &v25;
      v12 = v30;
      v11[29] = &v33;
      v13 = result;
      v11[32] = v6;
      v11[33] = 5;
      v14 = v28;
      v15 = v29;
      *(_DWORD *)(result + 24) = v12;
      *(_DWORD *)(result + 8) = v14;
      v16 = (void *)(result + (unsigned __int16)v14);
      v17 = HIWORD(v14);
      if ( v15 )
        v18 = v15;
      else
        v18 = "(null)";
      v19 = v17 - 1;
      memcpy(v16, v18, v17 - 1);
      *((_BYTE *)v16 + v19) = 0;
      v20 = v31;
      v21 = *(_DWORD *)(v13 + 24);
      *(_QWORD *)(v13 + 16) = a3;
      v22 = (void *)(v13 + (unsigned __int16)v21);
      if ( v20 )
        v23 = v20;
      else
        v23 = "(null)";
      v24 = HIWORD(v21) - 1LL;
      memcpy(v22, v23, v24);
      *((_BYTE *)v22 + v24) = 0;
      result = perf_trace_run_bpf_submit(v13, v10, v26, a1, 1, v27, StatusReg + v8, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
