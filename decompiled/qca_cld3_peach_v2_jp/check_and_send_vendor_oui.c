__int64 __fastcall check_and_send_vendor_oui(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  unsigned int v14; // w19
  __int64 values; // x0
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  __int64 v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 21560);
  v16 = 0;
  v17 = 0;
  if ( !(unsigned int)wlan_scan_get_entry_by_mac_addr(v4, (int *)(a2 + 24), (unsigned int *)&v16) || (_DWORD)v16 )
  {
    LODWORD(v16) = v16 - 36;
    if ( (lim_enable_cts_to_self_for_exempted_iot_ap(a1, a2, v17 + 36, v16) & 1) == 0 )
    {
      v14 = *(unsigned __int8 *)(a2 + 10);
      values = cfg_psoc_get_values(*(_QWORD *)(a1 + 21552));
      wma_cli_set_command(v14, 44, *(unsigned int *)(values + 1192), 1);
    }
    result = _qdf_mem_free(v17);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Failed to get scan entry for %02x:%02x:%02x:**:**:%02x",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "check_and_send_vendor_oui",
               *(unsigned __int8 *)(a2 + 24),
               *(unsigned __int8 *)(a2 + 25),
               *(unsigned __int8 *)(a2 + 26),
               *(unsigned __int8 *)(a2 + 29));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
