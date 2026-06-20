size_t __fastcall perf_trace_relinquish_req_msg_class(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x30
  __int64 v3; // x22
  __int64 v6; // x25
  size_t v7; // x23
  const char *v8; // x0
  size_t result; // x0
  size_t v10; // x21
  unsigned __int64 v11; // x24
  const char *v12; // x23
  __int64 v13; // x25
  unsigned __int64 StatusReg; // x26
  int v15; // w27
  _QWORD *v16; // x9
  size_t v17; // x22
  size_t v18; // x24
  __int64 v19; // x2
  __int64 v20; // x5
  __int64 v21; // x0
  __int64 v26; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v29; // [xsp+20h] [xbp+0h] BYREF

  v3 = v2;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v28[0] = 0;
  v27 = 0;
  result = strnlen(v8, v7);
  v10 = result;
  if ( result > v7 )
  {
    _fortify_panic(2, v7, result + 1);
LABEL_16:
    _fortify_panic(4, v7, v10 + 1);
  }
  if ( result >= v7 )
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
  v15 = result & 0xFFFFFFF8;
  result = perf_trace_buf_alloc(((unsigned int)result & 0xFFFFFFF8) + 28, v28, &v27);
  if ( !result )
    goto LABEL_14;
  v16 = (_QWORD *)v28[0];
  *(_QWORD *)(v28[0] + 232LL) = &v29;
  v16[31] = &v26;
  v16[32] = v3;
  v16[33] = 5;
  *(_DWORD *)(result + 8) = ((_DWORD)v10 << 16) + 65556;
  if ( v11 >= v10 )
  {
    v17 = result + 20;
    v18 = result;
    memcpy((void *)(result + 20), v12, v10);
    *(_BYTE *)(v17 + v10) = 0;
    v19 = v27;
    v20 = v28[0];
    *(_DWORD *)(v18 + 12) = a2[3];
    *(_DWORD *)(v18 + 16) = *a2;
    result = perf_trace_run_bpf_submit(v18, (unsigned int)(v15 + 28), v19, a1, 1, v20, StatusReg + v13, 0);
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v21 = _fortify_panic(16, -1, v10);
  __asm { STLLRB          WZR, [X28] }
  return trace_event_raw_event_alloc_resp_class(v21);
}
