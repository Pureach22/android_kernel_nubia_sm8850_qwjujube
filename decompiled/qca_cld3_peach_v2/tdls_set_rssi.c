__int64 __fastcall tdls_set_rssi(
        __int64 a1,
        unsigned __int8 *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 peer; // x0
  const char *v25; // x2
  unsigned int v26; // w1

  if ( a1 && a2 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: rssi %d, peer %02x:%02x:%02x:**:**:%02x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "tdls_set_rssi",
      (unsigned int)a3,
      *a2,
      a2[1],
      a2[2],
      a2[5]);
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
    if ( comp_private_obj )
    {
      peer = tdls_find_peer(comp_private_obj, a2);
      if ( peer )
      {
        *(_BYTE *)(peer + 31) = a3;
        return 0;
      }
      v25 = "%s: null peer";
      v26 = 8;
    }
    else
    {
      v25 = "%s: null tdls vdev";
      v26 = 2;
    }
    qdf_trace_msg(0, v26, v25, v15, v16, v17, v18, v19, v20, v21, v22, "tdls_set_rssi");
    return 14;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: null pointer", a4, a5, a6, a7, a8, a9, a10, a11, "tdls_set_rssi");
    return 4;
  }
}
