__int64 __fastcall lim_ap_mlme_vdev_rnr_notify(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int8 sap_mode_info; // w0
  __int64 v37; // x23
  __int64 v38; // x24
  const char *v39; // x21
  int v40; // w1
  __int64 session_by_vdev_id; // x0
  unsigned int v42; // w0
  unsigned int v43; // w0
  unsigned int v44; // w19
  __int64 result; // x0
  int v46; // [xsp+8h] [xbp-28h] BYREF
  char v47; // [xsp+Ch] [xbp-24h]
  _QWORD v48[2]; // [xsp+10h] [xbp-20h] BYREF
  int v49; // [xsp+20h] [xbp-10h]
  __int64 v50; // [xsp+28h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v46 = 0;
  v49 = 0;
  v48[0] = 0;
  v48[1] = 0;
  context = _cds_get_context(53, (__int64)"lim_ap_mlme_vdev_rnr_notify", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v44 = 4;
    v39 = "%s: mac ctx is null";
    goto LABEL_17;
  }
  if ( !a1 )
  {
    v44 = 4;
    v39 = "%s: session is NULL";
    goto LABEL_17;
  }
  v19 = (__int64)context;
  if ( (mlme_is_notify_co_located_ap_update_rnr(*(_QWORD *)(a1 + 16), v11, v12, v13, v14, v15, v16, v17, v18) & 1) == 0
    || (mlme_set_notify_co_located_ap_update_rnr(*(_QWORD *)(a1 + 16), 0, v20, v21, v22, v23, v24, v25, v26, v27),
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev id %d non mlo 6G AP notify co-located AP to update RNR",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "lim_ap_mlme_vdev_rnr_notify",
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 104LL)),
        sap_mode_info = policy_mgr_get_sap_mode_info(
                          *(_QWORD *)(v19 + 21552),
                          (unsigned __int64)v48,
                          (unsigned __int64)&v46),
        (v37 = sap_mode_info) == 0) )
  {
LABEL_15:
    result = 0;
    goto LABEL_18;
  }
  v38 = 0;
  v39 = "%s: Unable to update 6g co located RNR in beacon";
  while ( 1 )
  {
    if ( v38 == 5 )
      __break(0x5512u);
    v40 = *((unsigned __int8 *)&v46 + v38);
    if ( v40 == *(unsigned __int8 *)(a1 + 10) )
      goto LABEL_6;
    session_by_vdev_id = pe_find_session_by_vdev_id(v19, v40, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( !session_by_vdev_id || !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(session_by_vdev_id + 284)) )
      goto LABEL_6;
    v42 = ((__int64 (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(v19, a1);
    if ( v42 )
      break;
    v43 = lim_send_beacon_ind(v19, a1, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( v43 )
    {
      v44 = v43;
      v39 = "%s: Unable to send beacon indication";
      goto LABEL_17;
    }
LABEL_6:
    if ( v37 == ++v38 )
      goto LABEL_15;
  }
  v44 = v42;
LABEL_17:
  qdf_trace_msg(0x35u, 2u, v39, v11, v12, v13, v14, v15, v16, v17, v18, "lim_ap_mlme_vdev_rnr_notify");
  result = v44;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
