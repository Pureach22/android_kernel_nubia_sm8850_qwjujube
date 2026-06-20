_BYTE *__fastcall ucfg_spatial_reuse_send_sr_config(
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
  _BYTE *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 cmpt_obj; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w20
  __int64 v39; // x0

  result = (_BYTE *)wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    if ( result[186] == 1 )
    {
      result = (_BYTE *)wlan_vdev_mlme_get_cmpt_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
      if ( !result || (result[187] & 1) == 0 )
      {
        if ( (a2 & 1) == 0 )
        {
          v39 = a1;
          return (_BYTE *)wlan_spatial_reuse_config_set(v39);
        }
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v21, v22, v23, v24, v25, v26, v27, v28);
        if ( cmpt_obj )
          v38 = *(unsigned __int8 *)(cmpt_obj + 182);
        else
          v38 = 0;
        result = (_BYTE *)wlan_vdev_mlme_get_cmpt_obj(a1, v30, v31, v32, v33, v34, v35, v36, v37);
        if ( result && v38 && result[183] )
        {
          v39 = a1;
          return (_BYTE *)wlan_spatial_reuse_config_set(v39);
        }
      }
    }
  }
  return result;
}
