__int64 __fastcall ucfg_spatial_reuse_send_sr_prohibit(
        __int64 a1,
        int a2,
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  char v21; // w21
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w22
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj )
    v21 = *(_BYTE *)(cmpt_obj + 202);
  else
    v21 = 0;
  v22 = wlan_vdev_mlme_get_cmpt_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( v22 )
    v31 = *(unsigned __int8 *)(v22 + 204);
  else
    v31 = 0;
  v32 = wlan_vdev_mlme_get_cmpt_obj(a1, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( v32 && (*(_DWORD *)&v21 & ((unsigned __int8)(*(_BYTE *)(v32 + 198) & 0x10) >> 4)) == 1 && ((v31 ^ a2) & 1) != 0 )
  {
    result = wlan_spatial_reuse_he_siga_val15_allowed_set(a1);
    if ( !(_DWORD)result )
    {
      result = wlan_vdev_mlme_get_cmpt_obj(a1, v42, v43, v44, v45, v46, v47, v48, v49);
      if ( result )
      {
        *(_BYTE *)(result + 204) = a2 & 1;
        return 0;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Prohibit command can not be sent sr_enabled %d, sr_ctrl %d , sr_prohibited %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "ucfg_spatial_reuse_send_sr_prohibit",
      v21 & 1);
    return 16;
  }
  return result;
}
