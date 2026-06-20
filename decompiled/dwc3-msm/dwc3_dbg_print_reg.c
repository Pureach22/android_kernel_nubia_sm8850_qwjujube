__int64 __fastcall dwc3_dbg_print_reg(__int64 result, const char *a2, int a3)
{
  if ( a2 )
    return ipc_log_string(result, "%s = 0x%08x", a2, a3);
  return result;
}
