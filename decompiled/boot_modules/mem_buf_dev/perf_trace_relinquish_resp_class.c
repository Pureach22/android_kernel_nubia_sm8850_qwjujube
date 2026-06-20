_DWORD *__fastcall perf_trace_relinquish_resp_class(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x30
  __int64 v3; // x22
  __int64 v6; // x24
  size_t v7; // x23
  const char *v8; // x0
  _DWORD *result; // x0
  size_t v10; // x21
  unsigned __int64 v11; // x27
  const char *v12; // x23
  __int64 v13; // x25
  unsigned __int64 StatusReg; // x26
  unsigned int v15; // w24
  _QWORD *v16; // x9
  _DWORD *v17; // x20
  _DWORD *v18; // x22
  __int64 v19; // x0
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v22[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v23; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (unsigned int)a2[1];
  if ( (unsigned int)v6 > 3 )
  {
    v8 = "(null)";
    v7 = 7;
  }
  else
  {
    v7 = qword_14B00[v6];
    v8 = (&off_14170)[v6];
  }
  v22[0] = 0;
  v21 = 0;
  result = (_DWORD *)strnlen(v8, v7);
  v10 = (size_t)result;
  if ( (unsigned __int64)result > v7 )
  {
    _fortify_panic(2, v7, (char *)result + 1);
LABEL_16:
    _fortify_panic(4, v7, v10 + 1);
  }
  if ( (unsigned __int64)result >= v7 )
    goto LABEL_16;
  if ( (unsigned int)v6 > 3 )
  {
    v12 = "(null)";
    v11 = 7;
  }
  else
  {
    v11 = qword_14B00[v6];
    v12 = (&off_14170)[v6];
  }
  v13 = *(_QWORD *)(a1 + 104);
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( !*(_QWORD *)(a1 + 112) && !*(_QWORD *)(StatusReg + v13) )
    goto LABEL_14;
  v15 = (((_DWORD)result + 28) & 0xFFFFFFF8) - 4;
  result = (_DWORD *)perf_trace_buf_alloc(v15, v22, &v21);
  if ( !result )
    goto LABEL_14;
  v16 = (_QWORD *)v22[0];
  *(_QWORD *)(v22[0] + 232LL) = &v23;
  v16[31] = &v20;
  v16[32] = v3;
  v16[33] = 5;
  result[3] = ((_DWORD)v10 << 16) + 65552;
  result[2] = *a2;
  if ( v11 >= v10 )
  {
    v17 = result + 4;
    v18 = result;
    memcpy(result + 4, v12, v10);
    *((_BYTE *)v17 + v10) = 0;
    result = (_DWORD *)perf_trace_run_bpf_submit(v18, v15, v21, a1, 1, v22[0], StatusReg + v13, 0);
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v19 = _fortify_panic(16, -1, v10);
  return (_DWORD *)trace_event_raw_event_lookup_sgl(v19);
}
