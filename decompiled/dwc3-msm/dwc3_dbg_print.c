__int64 __fastcall dwc3_dbg_print(__int64 result, unsigned __int8 a2, const char *a3, int a4, const char *a5)
{
  int v8; // w2
  int v9; // w9

  if ( a2 == 0xFF )
  {
    if ( !a3 )
      return result;
    v8 = 255;
    return ipc_log_string(result, "%02X %-25.25s %4i ?\t%s", v8, a3, a4, a5);
  }
  v8 = a2;
  if ( (a2 & 1) != 0 )
  {
    if ( !a3 )
      return result;
    v9 = ep_addr_txdbg_mask;
  }
  else
  {
    if ( !a3 )
      return result;
    v9 = ep_addr_rxdbg_mask;
  }
  if ( (v9 & (1 << (a2 >> 1))) != 0 )
    return ipc_log_string(result, "%02X %-25.25s %4i ?\t%s", v8, a3, a4, a5);
  return result;
}
