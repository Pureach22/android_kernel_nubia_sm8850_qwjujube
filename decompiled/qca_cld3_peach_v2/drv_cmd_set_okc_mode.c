__int64 __fastcall drv_cmd_set_okc_mode(__int64 a1, __int64 *a2, __int64 a3, unsigned __int8 a4)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  unsigned int v16; // w1
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  unsigned int v36; // w20
  __int64 v37; // x0
  unsigned int v38; // w1
  unsigned int v39; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v40; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v41; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = 0;
  hdd_get_pmkid_modes(a2, &v40);
  if ( (ucfg_cm_get_is_ese_feature_enabled(*a2) & 1) != 0
    && (v40 & 1) != 0
    && (ucfg_cm_get_is_ft_feature_enabled(*a2) & 1) != 0 )
  {
    v15 = "%s: PMKID/ESE/11R are supported simultaneously hence this operation is not permitted!";
    v16 = 3;
LABEL_16:
    qdf_trace_msg(0x33u, v16, v15, v7, v8, v9, v10, v11, v12, v13, v14, "drv_cmd_set_okc_mode");
    result = 0xFFFFFFFFLL;
    goto LABEL_18;
  }
  v17 = a3 + a4;
  if ( (unsigned int)ucfg_mlme_get_pmkid_modes(*a2, (int *)&v39) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: get pmkid modes failed",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "drv_cmd_set_okc_mode");
  v41 = v39 & 1;
  v26 = kstrtouint(v17 + 1, 10, &v41);
  if ( (v26 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: value out of range [0 - 1]",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "drv_cmd_set_okc_mode");
    result = 4294967274LL;
  }
  else
  {
    if ( v41 < 2 )
    {
      v36 = v26;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Received Command to change okc mode = %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "drv_cmd_set_okc_mode");
      v37 = *a2;
      if ( v41 )
        v38 = (v39 & 0xFFFFFFFE) + 1;
      else
        v38 = v39 & 0xFFFFFFFE;
      v39 = v38;
      if ( !(unsigned int)ucfg_mlme_set_pmkid_modes(v37, v38) )
      {
        result = v36;
        goto LABEL_18;
      }
      v15 = "%s: set pmkid modes failed";
      v16 = 2;
      goto LABEL_16;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Okc mode value %d is out of range (Min: 0 Max: 1)",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "drv_cmd_set_okc_mode");
    result = 4294967274LL;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
