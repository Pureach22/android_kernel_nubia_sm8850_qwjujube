__int64 __fastcall mlme_set_rso_disabled_bitmap(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  unsigned __int8 v6; // w21
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  __int64 ext_hdl; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  char v26; // w8
  unsigned __int8 v27; // w9
  unsigned __int8 v28; // w8
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v6 = a2;
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( !v7 )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s: vdev object is NULL",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "mlme_set_rso_disabled_bitmap");
  v16 = v7;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v7, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( ext_hdl )
  {
    v26 = *(_BYTE *)(ext_hdl + 156);
    v27 = v26 | a3;
    v28 = v26 & ~(_BYTE)a3;
    if ( (a4 & 1) == 0 )
      v28 = v27;
    *(_BYTE *)(ext_hdl + 156) = v28;
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev[%d] bitmap[0x%x], reqs: %d, clear: %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "mlme_set_rso_disabled_bitmap",
      v6,
      v28,
      a3,
      a4 & 1);
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "mlme_set_rso_disabled_bitmap");
  }
  return wlan_objmgr_vdev_release_ref(v16, 0x43u, v29, v30, v31, v32, v33, v34, v35, v36, v37);
}
