__int64 __fastcall populate_dot11f_sr_info(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _BYTE *a11)
{
  __int64 cmpt_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char v22; // w21
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  char v32; // w8
  char v33; // w8
  __int64 v34; // x0
  char v35; // w9
  char v36; // w8

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a10 + 16), a1, a2, a3, a4, a5, a6, a7, a8);
  if ( cmpt_obj )
    v22 = *(_BYTE *)(cmpt_obj + 198);
  else
    v22 = 0;
  v23 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a10 + 16), v14, v15, v16, v17, v18, v19, v20, v21);
  if ( v23 && *(_BYTE *)(v23 + 202) == 1 )
  {
    v32 = a11[1];
    *a11 = 1;
    v33 = v22 & 2 | v32 & 0xF0 | 1;
    a11[1] = v33;
    if ( (v22 & 2) == 0 && (v22 & 4) != 0 )
    {
      v34 = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a10 + 16), v24, v25, v26, v27, v28, v29, v30, v31);
      if ( v34 )
        v35 = *(_BYTE *)(v34 + 199);
      else
        v35 = 0;
      v36 = a11[1];
      a11[2] = v35;
      v33 = v36 | 4;
      a11[1] = v33;
    }
    if ( (v22 & 0x10) != 0 )
      a11[1] = v33 | 0x10;
  }
  return 0;
}
