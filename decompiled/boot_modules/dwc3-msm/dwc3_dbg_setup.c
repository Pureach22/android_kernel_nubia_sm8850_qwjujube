__int64 __fastcall dwc3_dbg_setup(__int64 result, unsigned __int8 a2, unsigned __int8 *a3)
{
  int v3; // w8
  int v4; // w10

  v3 = 255;
  if ( a2 == 0xFF )
  {
    if ( a3 )
      return ipc_log_string(
               result,
               "%02X %-25.25s ?\t%02X %02X %04X %04X %d",
               v3,
               "SETUP",
               *a3,
               a3[1],
               *((unsigned __int16 *)a3 + 1),
               *((unsigned __int16 *)a3 + 2),
               *((unsigned __int16 *)a3 + 3));
  }
  else
  {
    v3 = a2;
    if ( (a2 & 1) != 0 )
    {
      if ( !a3 )
        return result;
      v4 = ep_addr_txdbg_mask;
    }
    else
    {
      if ( !a3 )
        return result;
      v4 = ep_addr_rxdbg_mask;
    }
    if ( (v4 & (1 << (a2 >> 1))) != 0 )
      return ipc_log_string(
               result,
               "%02X %-25.25s ?\t%02X %02X %04X %04X %d",
               v3,
               "SETUP",
               *a3,
               a3[1],
               *((unsigned __int16 *)a3 + 1),
               *((unsigned __int16 *)a3 + 2),
               *((unsigned __int16 *)a3 + 3));
  }
  return result;
}
