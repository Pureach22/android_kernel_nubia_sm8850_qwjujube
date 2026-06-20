__int64 __fastcall trace_event_raw_event_process_invoke_req_wait(__int64 a1, const char *a2, int a3, int a4, int a5)
{
  __int64 v9; // x9
  __int64 result; // x0
  _DWORD *v11; // x23
  size_t v12; // x0
  unsigned __int64 v13; // x2
  __int64 v14; // x0
  __int64 v15; // x12
  _QWORD v16[7]; // [xsp+8h] [xbp-38h] BYREF

  v16[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 72);
  memset(v16, 0, 48);
  if ( (v9 & 0x2C0) != 0 && (v9 & 0x100) == 0 )
  {
    result = _trace_trigger_soft_disabled(a1);
    if ( (result & 1) != 0 )
      goto LABEL_9;
  }
  result = trace_event_buffer_reserve(v16);
  if ( !result )
    goto LABEL_9;
  v11 = (_DWORD *)result;
  v12 = strnlen(a2, 0x30u);
  if ( v12 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v12 == 48 )
      v13 = 48;
    else
      v13 = v12 + 1;
    if ( v13 < 0x31 )
    {
      sized_strscpy(v11 + 2, a2);
      v11[14] = a3;
      v11[15] = a4;
      v11[16] = a5;
      result = trace_event_buffer_commit(v16);
LABEL_9:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v14 = _fortify_panic(7, 48, v13);
  if ( (v15 & 0x80000000000000LL) != 0 )
    JUMPOUT(0x9450);
  return perf_trace_process_invoke_req_wait(v14);
}
