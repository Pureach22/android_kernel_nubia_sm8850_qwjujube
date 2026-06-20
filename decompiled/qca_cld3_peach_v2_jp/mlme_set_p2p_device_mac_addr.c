__int64 __fastcall mlme_set_p2p_device_mac_addr(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 cmpt_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w10

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
    return 16;
  if ( a2 )
  {
    v20 = *a2;
    *(_WORD *)(cmpt_obj + 998) = *((_WORD *)a2 + 2);
    *(_DWORD *)(cmpt_obj + 994) = v20;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: set mac_addr %02x:%02x:%02x:**:**:%02x",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "mlme_set_p2p_device_mac_addr",
      *(unsigned __int8 *)(cmpt_obj + 994),
      *(unsigned __int8 *)(cmpt_obj + 995),
      *(unsigned __int8 *)(cmpt_obj + 996),
      *(unsigned __int8 *)(cmpt_obj + 999));
  }
  else
  {
    qdf_mem_set((void *)(cmpt_obj + 994), 6u, 0);
  }
  return 0;
}
