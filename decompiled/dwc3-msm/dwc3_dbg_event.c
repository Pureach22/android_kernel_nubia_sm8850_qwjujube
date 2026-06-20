__int64 __fastcall dwc3_dbg_event(__int64 result, unsigned __int8 a2, const char *a3, int a4)
{
  int v6; // w2
  int v7; // w8
  int v8; // w9

  if ( a2 == 0xFF )
  {
    if ( !a3 )
      return result;
    v6 = 255;
    return ipc_log_string(result, "%02X %-25.25s %4i ?\t%s", v6, a3, a4, (const char *)&unk_16A05);
  }
  v6 = a2;
  v7 = 1 << (a2 >> 1);
  if ( (a2 & 1) != 0 )
  {
    if ( a3 && (ep_addr_txdbg_mask & v7) != 0 )
    {
      v8 = ep_addr_txdbg_mask;
LABEL_11:
      if ( (v8 & v7) == 0 )
        return result;
      return ipc_log_string(result, "%02X %-25.25s %4i ?\t%s", v6, a3, a4, (const char *)&unk_16A05);
    }
  }
  else if ( a3 && (ep_addr_rxdbg_mask & v7) != 0 )
  {
    v8 = ep_addr_rxdbg_mask;
    goto LABEL_11;
  }
  return result;
}
