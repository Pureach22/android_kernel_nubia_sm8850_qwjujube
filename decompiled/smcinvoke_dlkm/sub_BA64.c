// positive sp value has been detected, the output may be wrong!
void sub_BA64()
{
  __int64 v0; // x0
  _QWORD *v1; // x9
  __int64 v2; // x23
  size_t v3; // x0
  unsigned __int64 v4; // x2
  __int64 v5; // x2
  _QWORD *v6; // x5
  __int64 v7; // x12
  __int64 v8; // x19
  int v9; // w20
  int v10; // w21
  __int64 v11; // x22
  const char *v12; // x24
  __int64 v13; // x25
  __int64 v14; // x26
  __int64 v15; // x27
  __int64 v16; // x29
  __int64 v17; // [xsp-80h] [xbp-80h] BYREF
  unsigned int v18; // [xsp-74h] [xbp-74h] BYREF
  _QWORD *v19; // [xsp-70h] [xbp-70h] BYREF

  if ( (v7 & 0x80000000000000LL) == 0 )
  {
    _bpf_trace_process_invoke_req_wait();
    return;
  }
  if ( *(_QWORD *)(v15 + v14) )
  {
    v0 = perf_trace_buf_alloc(76, &v19, &v18);
    if ( v0 )
    {
      v1 = v19;
      v2 = v0;
      v19[29] = v16;
      v1[33] = 5;
      v1[31] = &v17;
      v1[32] = v13;
      v3 = strnlen(v12, 0x30u);
      if ( v3 == -1 )
      {
        _fortify_panic(2, -1, 0);
      }
      else
      {
        if ( v3 == 48 )
          v4 = 48;
        else
          v4 = v3 + 1;
        if ( v4 < 0x31 )
        {
          sized_strscpy(v2 + 8, v12);
          v5 = v18;
          v6 = v19;
          *(_QWORD *)(v2 + 56) = v11;
          *(_DWORD *)(v2 + 64) = v10;
          *(_DWORD *)(v2 + 68) = v9;
          perf_trace_run_bpf_submit(v2, 76, v5, v8, 1, v6, v15 + v14, 0);
          goto LABEL_11;
        }
      }
      _fortify_panic(7, 48, v4);
      JUMPOUT(0xABD8);
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
}
