__int64 __fastcall nan_update_pasn_peer_count(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  char v20; // w9
  const char *v21; // x2
  unsigned __int8 v23; // w8

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_vdev_priv_obj");
    goto LABEL_6;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_6:
    v21 = "%s: NAN vdev priv obj is null";
    return qdf_trace_msg(0x53u, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "nan_update_pasn_peer_count");
  }
  if ( (a2 & 1) == 0 )
  {
    if ( *(_BYTE *)(comp_private_obj + 105) )
    {
      v20 = -1;
      goto LABEL_10;
    }
    v21 = "%s: No PASN peers present";
    return qdf_trace_msg(0x53u, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "nan_update_pasn_peer_count");
  }
  v20 = 1;
LABEL_10:
  v23 = *(_BYTE *)(comp_private_obj + 105) + v20;
  *(_BYTE *)(comp_private_obj + 105) = v23;
  return qdf_trace_msg(
           0x53u,
           8u,
           "%s: Pasn peer count:%d",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "nan_update_pasn_peer_count",
           v23);
}
