__int64 __fastcall wlan_dp_update_tcp_rx_param(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  const char *v13; // x2
  __int64 (*v15)(void); // x8

  if ( !a1 )
  {
    v13 = "%s: psoc is null";
    return qdf_trace_msg(0x45u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_dp_update_tcp_rx_param");
  }
  if ( !a2 )
  {
    v13 = "%s: Data is null";
    return qdf_trace_msg(0x45u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_dp_update_tcp_rx_param");
  }
  if ( *((_BYTE *)a1 + 124) == 1 )
  {
    v10 = (__int64 (__fastcall *)(_QWORD))a1[69];
    v11 = *a1;
    if ( *((_DWORD *)v10 - 1) != 1848957961 )
      __break(0x8228u);
    return v10(v11);
  }
  if ( (unsigned int)cds_get_radio_index(a1, a2) == -22 )
  {
    v13 = "%s: Invalid radio index";
    return qdf_trace_msg(0x45u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_dp_update_tcp_rx_param");
  }
  v15 = (__int64 (*)(void))a1[68];
  if ( *((_DWORD *)v15 - 1) != -1162056974 )
    __break(0x8228u);
  return v15();
}
