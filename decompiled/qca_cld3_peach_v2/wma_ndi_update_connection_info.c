__int64 __fastcall wma_ndi_update_connection_info(
        unsigned __int8 a1,
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
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x21
  _QWORD *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  const char *v33; // x2

  context = _cds_get_context(54, (__int64)"wma_ndi_update_connection_info", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 16;
  v21 = context;
  v22 = _cds_get_context(54, (__int64)"wma_get_interface_by_vdev_id", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !v22 )
    goto LABEL_9;
  if ( *((unsigned __int16 *)v22 + 81) <= (unsigned int)a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid vdev_id %u",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_get_interface_by_vdev_id",
      a1);
    goto LABEL_9;
  }
  v31 = v22[65] + 488LL * a1;
  if ( !v31 )
  {
LABEL_9:
    v33 = "%s: can't find vdev_id %d in WMA table";
LABEL_10:
    qdf_trace_msg(0x36u, 2u, v33, v23, v24, v25, v26, v27, v28, v29, v30, "wma_ndi_update_connection_info", a1);
    return 16;
  }
  if ( *(_DWORD *)(v31 + 164) != 7 )
  {
    v33 = "%s: Given vdev id(%d) not of type NDI!";
    goto LABEL_10;
  }
  if ( a2 )
  {
    *(_DWORD *)(v31 + 180) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v31 + 436) = *(_DWORD *)(a2 + 4);
    *(_BYTE *)(v31 + 236) = *(_DWORD *)(a2 + 12);
    wlan_mlme_set_vdev_mac_id(v21[4], a1, *(unsigned __int8 *)(a2 + 16));
    return 0;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Provided chan info is NULL!",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wma_ndi_update_connection_info");
  return 16;
}
