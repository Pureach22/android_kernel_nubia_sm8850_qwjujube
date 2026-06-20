__int64 __fastcall wlan_mlo_is_csa_allow(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w22
  __int64 v30; // x21
  unsigned __int16 *active_channel; // x0
  unsigned int v32; // w24
  __int64 result; // x0
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x21
  unsigned __int16 *v44; // x0
  __int64 v45; // x1
  unsigned __int16 v46; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-18h] BYREF
  __int64 v48; // [xsp+10h] [xbp-10h]
  __int64 v49; // [xsp+18h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v46 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: vdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_mlo_is_csa_allow");
    result = 0;
    goto LABEL_18;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0
    || (mlo_get_ml_vdev_list(a1, &v46, (__int64)&v47, v12, v13, v14, v15, v16, v17, v18, v19), (v29 = v46) == 0) )
  {
    result = 1;
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v30 = v47;
  if ( v47 != a1
    && (active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(v47)) != nullptr
    && (v20 = (unsigned int *)*active_channel, (_DWORD)v20 == a2) )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: vdev %d will SCC with vdev %d on freq %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_mlo_is_csa_allow",
      *(unsigned __int8 *)(a1 + 168),
      *(unsigned __int8 *)(v30 + 168),
      a2);
    v32 = 0;
  }
  else
  {
    v32 = 1;
  }
  wlan_objmgr_vdev_release_ref(v30, 0x5Au, v20, v21, v22, v23, v24, v25, v26, v27, v28);
  if ( v29 == 1 )
  {
    result = v32;
    goto LABEL_18;
  }
  v43 = v48;
  if ( v48 != a1 )
  {
    v44 = (unsigned __int16 *)wlan_vdev_get_active_channel(v48);
    if ( v44 )
    {
      v34 = (unsigned int *)*v44;
      if ( (_DWORD)v34 == a2 )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: vdev %d will SCC with vdev %d on freq %d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "wlan_mlo_is_csa_allow",
          *(unsigned __int8 *)(a1 + 168),
          *(unsigned __int8 *)(v43 + 168),
          a2);
        v32 = 0;
      }
    }
  }
  wlan_objmgr_vdev_release_ref(v43, 0x5Au, v34, v35, v36, v37, v38, v39, v40, v41, v42);
  result = v32;
  if ( v29 == 2 )
    goto LABEL_18;
  __break(0x5512u);
  return mlo_ttlm_send_cmd_register_resp_cb(v32, v45);
}
