__int64 __fastcall hdd_populate_feature_set_cds_config(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x20
  __int64 ini_config; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int *v28; // x9
  unsigned int v29; // w21
  int v30; // w8
  unsigned int v31; // w9
  bool v32; // zf
  unsigned int v33; // w8
  int v34; // w8
  int v35; // w8
  unsigned int v36; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_22;
  v9 = (__int64 *)result;
  v36 = 0;
  ini_config = cds_get_ini_config(a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !ini_config )
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: CDS config is null.",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "hdd_populate_feature_set_cds_config");
    goto LABEL_22;
  }
  v19 = ini_config;
  *(_BYTE *)(ini_config + 144) = *(_BYTE *)(v9[13] + 181);
  result = wlan_mlme_get_band_capability(*v9, &v36);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Failed to get MLME band capability",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "hdd_populate_feature_set_cds_config");
  v28 = (int *)v9[13];
  v29 = v36;
  v30 = *v28;
  if ( (unsigned int)*v28 > 7 )
    goto LABEL_8;
  if ( ((1 << v30) & 0xAC) != 0 )
  {
    v29 = v36 & 0xFFFFFFFD;
LABEL_8:
    v31 = v29 & 0xFFFFFFFE;
    v32 = v30 == 10;
    v33 = v30 - 11;
    if ( !v32 )
      v31 = v29;
    if ( v33 >= 2 )
      v29 = v31 & 0xFFFFFFFB;
    else
      v29 = v31;
    result = qdf_trace_msg(
               0x38u,
               8u,
               "%s: Update band capability %x",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "hdd_update_band_cap_from_dot11mode",
               v29);
    v28 = (int *)v9[13];
    goto LABEL_14;
  }
  if ( v30 )
    goto LABEL_8;
LABEL_14:
  v36 = v29;
  v34 = *v28;
  if ( *v28 && (unsigned int)(v34 - 11) > 1 )
  {
    v35 = (v34 & 0xFFFFFFFE) == 8;
  }
  else if ( (v29 & 4) != 0 )
  {
    v35 = 3;
  }
  else
  {
    v35 = 2;
  }
  *(_DWORD *)(v19 + 132) = v35;
  *(_DWORD *)(v19 + 140) = v29;
  *(_BYTE *)(v19 + 136) = (v29 & 2) != 0;
  *(_BYTE *)(v19 + 137) = (v29 & 4) != 0;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
