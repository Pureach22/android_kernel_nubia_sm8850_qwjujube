__int64 __fastcall ucfg_mlme_set_vdev_traffic_type(
        __int64 a1,
        char a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w19
  __int64 result; // x0
  __int64 cmpt_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  __int64 ext_hdl; // x0
  __int64 v27; // x6
  int v28; // w8
  unsigned __int8 v29; // w9
  const char *v30; // x2
  __int64 v31; // x7
  __int64 v32; // x20
  int v33; // w9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _DWORD v42[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a1 + 104);
  if ( (unsigned int)(*(_DWORD *)(a1 + 16) - 4) <= 0xFFFFFFFC )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev %d: not supported for opmode %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ucfg_mlme_set_vdev_traffic_type",
      *(unsigned __int8 *)(a1 + 104));
    result = 11;
    goto LABEL_13;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !cmpt_obj )
  {
    v30 = "%s: vdev %d: bit_mask 0x%x, set %d, vdev mlme is null";
LABEL_11:
    qdf_trace_msg(
      0x1Fu,
      2u,
      v30,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_mlme_set_vdev_traffic_type",
      v11,
      a3,
      a2 & 1);
    result = 16;
    goto LABEL_13;
  }
  v25 = cmpt_obj;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( !ext_hdl )
  {
    v30 = "%s: vdev %d: bit_mask 0x%x, set %d, vmlme_priv is null";
    goto LABEL_11;
  }
  v27 = a2 & 1;
  v28 = *(unsigned __int8 *)(ext_hdl + 24464);
  v29 = v28 & ~a3;
  if ( (a2 & 1) != 0 )
    v29 = v28 | a3;
  *(_BYTE *)(ext_hdl + 24464) = v29;
  if ( v28 == v29 )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev %d: No change in value 0x%x, set %d mask 0x%x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_mlme_set_vdev_traffic_type",
      v11,
      v29,
      v27,
      a3);
    result = 0;
  }
  else
  {
    v31 = a3;
    v32 = ext_hdl;
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev %d: vdev_traffic_type 0x%x (set %d with bit_mask 0x%x)",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ucfg_mlme_set_vdev_traffic_type",
      v11,
      v29,
      v27,
      v31);
    v33 = *(unsigned __int8 *)(v32 + 24464);
    v42[0] = v11;
    v42[1] = 182;
    v42[2] = v33;
    result = tgt_vdev_mgr_set_param_send(v25, (__int64)v42, v34, v35, v36, v37, v38, v39, v40, v41);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
