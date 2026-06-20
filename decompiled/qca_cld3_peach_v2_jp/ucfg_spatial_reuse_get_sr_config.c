__int64 __fastcall ucfg_spatial_reuse_get_sr_config(
        __int64 a1,
        _BYTE *a2,
        _BYTE *a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 cmpt_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w8
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char v35; // w8
  __int64 result; // x0
  char v37; // w8

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( cmpt_obj )
    v25 = *(_BYTE *)(cmpt_obj + 182);
  else
    v25 = 0;
  *a2 = v25;
  v26 = wlan_vdev_mlme_get_cmpt_obj(a1, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( v26 )
    v35 = *(_BYTE *)(v26 + 183);
  else
    v35 = 0;
  *a3 = v35;
  result = wlan_vdev_mlme_get_cmpt_obj(a1, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( result )
    v37 = *(_BYTE *)(result + 186);
  else
    v37 = 0;
  *a4 = v37 & 1;
  return result;
}
