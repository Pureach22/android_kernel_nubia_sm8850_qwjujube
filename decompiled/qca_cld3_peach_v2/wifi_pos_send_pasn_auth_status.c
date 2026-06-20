__int64 __fastcall wifi_pos_send_pasn_auth_status(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  __int64 tx_ops; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x23
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x19
  __int64 vdev_priv_obj; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x9
  _BYTE *v43; // x22
  __int64 v44; // x10
  unsigned __int64 v45; // x15
  unsigned __int8 *v46; // x12
  __int64 v47; // x13
  __int16 v48; // w16
  int v49; // w17
  bool v50; // zf
  __int64 (__fastcall *v51)(__int64, unsigned __int8 *); // x8
  unsigned int v52; // w20
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  const char *v71; // x4
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7

  v10 = *a2;
  tx_ops = wifi_pos_get_tx_ops(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !tx_ops )
  {
    v71 = "send_auth_status cb";
LABEL_18:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: %s is null",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wifi_pos_send_pasn_auth_status",
      v71);
    return 16;
  }
  if ( !*(_QWORD *)(tx_ops + 56) )
  {
    v71 = "Tx_ops";
    goto LABEL_18;
  }
  v22 = tx_ops;
  v23 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v10, 13);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: vdev obj is null",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wifi_pos_send_pasn_auth_status");
    return 16;
  }
  v32 = v23;
  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(v23);
  if ( !vdev_priv_obj )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Wifi pos vdev priv obj is null",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wifi_pos_send_pasn_auth_status");
    wlan_objmgr_vdev_release_ref(v32, 0xDu, v72, v73, v74, v75, v76, v77, v78, v79, v80);
    return 16;
  }
  v42 = a2[1];
  v43 = (_BYTE *)vdev_priv_obj;
  v44 = *(unsigned __int8 *)(vdev_priv_obj + 12261);
  if ( (unsigned int)v42 < (unsigned __int8)(v44 + v42) )
  {
    v45 = 1;
    v46 = &a2[288 * a2[1]];
    v47 = vdev_priv_obj + 12165;
    do
    {
      if ( v42 + v45 - 1 >= 0x10 )
      {
        __break(0x5512u);
        JUMPOUT(0x4F7A60);
      }
      v48 = *(_WORD *)(v47 + 4);
      v49 = *(_DWORD *)v47;
      *((_DWORD *)v46 + 72) = 2;
      *((_WORD *)v46 + 4) = v48;
      *((_DWORD *)v46 + 1) = v49;
      if ( v45 >= *(unsigned __int8 *)(vdev_priv_obj + 12261) )
        break;
      v50 = v44 == v45++;
      v46 += 288;
      v47 += 6;
    }
    while ( !v50 );
  }
  v51 = *(__int64 (__fastcall **)(__int64, unsigned __int8 *))(v22 + 56);
  if ( *((_DWORD *)v51 - 1) != -588888907 )
    __break(0x8228u);
  v52 = v51(a1, a2);
  if ( v52 )
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Failed to send PASN authentication status",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "wifi_pos_send_pasn_auth_status");
  wifi_pos_init_11az_context(v43);
  wlan_objmgr_vdev_release_ref(v32, 0xDu, v61, v62, v63, v64, v65, v66, v67, v68, v69);
  return v52;
}
