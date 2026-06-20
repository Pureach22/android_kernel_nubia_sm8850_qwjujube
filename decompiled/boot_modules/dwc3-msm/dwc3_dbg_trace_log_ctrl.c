__int64 __fastcall dwc3_dbg_trace_log_ctrl(__int64 result, unsigned __int8 *a2)
{
  __int64 v3; // x19
  __int64 v4; // x6
  __int64 v5; // x5
  __int64 v6; // x4
  __int64 v7; // x3
  __int64 v8; // x2
  const char *v9; // x20

  if ( a2 )
  {
    v3 = result;
    result = _kmalloc_cache_noprof(_stack_chk_fail, 2336, 500);
    if ( result )
    {
      v4 = *((unsigned __int16 *)a2 + 3);
      v5 = *((unsigned __int16 *)a2 + 2);
      v6 = *((unsigned __int16 *)a2 + 1);
      v7 = a2[1];
      v8 = *a2;
      v9 = (const char *)result;
      usb_decode_ctrl(result, 500, v8, v7, v6, v5, v4);
      ipc_log_string(v3, "dbg_trace_log_ctrl: %s", v9);
      return kfree(v9);
    }
  }
  return result;
}
