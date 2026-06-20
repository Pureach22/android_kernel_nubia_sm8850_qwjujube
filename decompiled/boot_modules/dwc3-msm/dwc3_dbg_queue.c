__int64 __fastcall dwc3_dbg_queue(__int64 result, unsigned __int8 a2, __int64 a3, int a4)
{
  int v4; // w8
  int v5; // w10

  v4 = 255;
  if ( a2 == 0xFF )
  {
    if ( a3 )
      return ipc_log_string(
               result,
               "%02X %-25.25s %4i ?\t%d %d",
               v4,
               "QUEUE",
               a4,
               ((*(_DWORD *)(a3 + 40) >> 17) & 1) == 0,
               *(_DWORD *)(a3 + 8));
  }
  else
  {
    v4 = a2;
    if ( (a2 & 1) != 0 )
    {
      if ( !a3 )
        return result;
      v5 = ep_addr_txdbg_mask;
    }
    else
    {
      if ( !a3 )
        return result;
      v5 = ep_addr_rxdbg_mask;
    }
    if ( (v5 & (1 << (a2 >> 1))) != 0 )
      return ipc_log_string(
               result,
               "%02X %-25.25s %4i ?\t%d %d",
               v4,
               "QUEUE",
               a4,
               ((*(_DWORD *)(a3 + 40) >> 17) & 1) == 0,
               *(_DWORD *)(a3 + 8));
  }
  return result;
}
