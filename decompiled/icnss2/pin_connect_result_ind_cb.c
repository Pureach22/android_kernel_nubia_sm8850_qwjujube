__int64 __fastcall pin_connect_result_ind_cb(_DWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w4
  __int64 result; // x0

  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Received Pin Connect Result Indication\n");
  if ( !a3 )
    return printk(byte_12E112);
  if ( *(_BYTE *)a4 )
    a1[351] = *(_DWORD *)(a4 + 4);
  if ( *(_BYTE *)(a4 + 8) )
    a1[352] = *(_DWORD *)(a4 + 12);
  v7 = *(_DWORD *)(a4 + 20);
  if ( *(_BYTE *)(a4 + 16) )
    a1[353] = v7;
  result = ipc_log_string(
             icnss_ipc_log_context,
             "icnss2_qmi: Pin connect Result: pwr_pin: 0x%x phy_io_pin: 0x%x rf_io_pin: 0x%x\n",
             *(_DWORD *)(a4 + 4),
             *(_DWORD *)(a4 + 12),
             v7);
  ++a1[498];
  return result;
}
