__int64 __fastcall dwc3_dbg_done(__int64 result, unsigned __int8 a2, int a3, int a4)
{
  int v5; // w2
  int v6; // w8

  v5 = 255;
  if ( a2 == 0xFF )
    return ipc_log_string(result, "%02X %-25.25s %4i ?\t%d", v5, "DONE", a4, a3);
  v5 = a2;
  v6 = 1 << (a2 >> 1);
  if ( (a2 & 1) != 0 )
  {
    if ( (ep_addr_txdbg_mask & v6) == 0 )
      return result;
    return ipc_log_string(result, "%02X %-25.25s %4i ?\t%d", v5, "DONE", a4, a3);
  }
  if ( (ep_addr_rxdbg_mask & v6) != 0 )
    return ipc_log_string(result, "%02X %-25.25s %4i ?\t%d", v5, "DONE", a4, a3);
  return result;
}
