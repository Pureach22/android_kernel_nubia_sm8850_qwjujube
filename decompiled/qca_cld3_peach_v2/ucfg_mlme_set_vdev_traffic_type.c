__int64 __fastcall ucfg_mlme_set_vdev_traffic_type(
        __int64 a1,
        __int64 a2,
        char a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w19
  __int64 result; // x0
  __int64 cmpt_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x23
  __int64 ext_hdl; // x0
  __int64 v29; // x6
  int v30; // w8
  unsigned __int8 v31; // w9
  const char *v32; // x2
  __int64 v33; // x7
  __int64 v34; // x20
  int v35; // w9
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w19
  _DWORD v45[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 *)(a2 + 168);
  if ( (unsigned int)(*(_DWORD *)(a2 + 16) - 4) <= 0xFFFFFFFC )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev %d: not supported for opmode %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "ucfg_mlme_set_vdev_traffic_type",
      *(unsigned __int8 *)(a2 + 168));
    result = 11;
    goto LABEL_13;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !cmpt_obj )
  {
    v32 = "%s: vdev %d: bit_mask 0x%x, set %d, vdev mlme is null";
LABEL_11:
    qdf_trace_msg(
      0x1Fu,
      2u,
      v32,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "ucfg_mlme_set_vdev_traffic_type",
      v12,
      a4,
      a3 & 1);
    result = 16;
    goto LABEL_13;
  }
  v27 = cmpt_obj;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a2, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( !ext_hdl )
  {
    v32 = "%s: vdev %d: bit_mask 0x%x, set %d, vmlme_priv is null";
    goto LABEL_11;
  }
  v29 = a3 & 1;
  v30 = *(unsigned __int8 *)(ext_hdl + 24560);
  v31 = v30 & ~a4;
  if ( (a3 & 1) != 0 )
    v31 = v30 | a4;
  *(_BYTE *)(ext_hdl + 24560) = v31;
  if ( v30 == v31 )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev %d: No change in value 0x%x, set %d mask 0x%x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "ucfg_mlme_set_vdev_traffic_type",
      v12,
      v31,
      v29,
      a4);
    result = 0;
  }
  else
  {
    v33 = a4;
    v34 = ext_hdl;
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev %d: vdev_traffic_type 0x%x (set %d with bit_mask 0x%x)",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "ucfg_mlme_set_vdev_traffic_type",
      v12,
      v31,
      v29,
      v33);
    v35 = *(unsigned __int8 *)(v34 + 24560);
    v45[0] = v12;
    v45[1] = 182;
    v45[2] = v35;
    v44 = tgt_vdev_mgr_set_param_send(v27, (__int64)v45, v36, v37, v38, v39, v40, v41, v42, v43);
    policy_mgr_handle_ml_sta_link_on_traffic_type_change(a1, a2);
    result = v44;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
