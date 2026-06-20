__int64 __fastcall hdd_set_allow_list(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        _BYTE *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x8
  unsigned int v14; // w23
  _BYTE *v15; // x19
  _WORD *v19; // x8
  int v20; // w26
  unsigned int v21; // w24
  void *v22; // x25
  unsigned __int16 *v23; // x27
  __int64 v24; // x8
  unsigned int v25; // w9
  unsigned int v26; // w8
  unsigned int v27; // w28
  __int64 v28; // x19
  __int64 v29; // x22
  unsigned int v30; // w21
  void *v31; // x20
  _BYTE *v32; // x25
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x2
  __int64 result; // x0
  _BYTE *v43; // [xsp+8h] [xbp-D8h]
  _QWORD v45[5]; // [xsp+18h] [xbp-C8h] BYREF
  _WORD *v46; // [xsp+40h] [xbp-A0h]
  __int64 v47; // [xsp+48h] [xbp-98h]
  __int64 v48; // [xsp+50h] [xbp-90h]
  __int64 v49; // [xsp+58h] [xbp-88h]
  __int64 v50; // [xsp+60h] [xbp-80h]
  __int64 v51; // [xsp+68h] [xbp-78h]
  __int64 v52; // [xsp+70h] [xbp-70h]
  __int64 v53; // [xsp+78h] [xbp-68h]
  __int64 v54; // [xsp+80h] [xbp-60h]
  __int64 v55; // [xsp+88h] [xbp-58h]
  __int64 v56; // [xsp+90h] [xbp-50h]
  __int64 v57; // [xsp+98h] [xbp-48h]
  __int64 v58; // [xsp+A0h] [xbp-40h]
  __int64 v59; // [xsp+A8h] [xbp-38h]
  __int64 v60; // [xsp+B0h] [xbp-30h]
  __int64 v61; // [xsp+B8h] [xbp-28h]
  __int64 v62; // [xsp+C0h] [xbp-20h]
  __int64 v63; // [xsp+C8h] [xbp-18h]
  __int64 v64; // [xsp+D0h] [xbp-10h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a3 + 24);
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = nullptr;
  v47 = 0;
  memset(v45, 0, sizeof(v45));
  if ( !v13 )
  {
    v41 = "%s: Number of networks is not provided";
LABEL_18:
    qdf_trace_msg(0x33u, 2u, v41, a6, a7, a8, a9, a10, a11, a12, a13, "hdd_set_allow_list");
    goto LABEL_21;
  }
  v14 = *(_DWORD *)(v13 + 4);
  v15 = a5;
  if ( !v14 )
    goto LABEL_19;
  v19 = *(_WORD **)(a3 + 32);
  if ( !v19 )
  {
    v21 = 0;
    goto LABEL_23;
  }
  v20 = (unsigned __int16)(*v19 - 4);
  if ( (unsigned int)v20 < 4 )
  {
LABEL_19:
    v21 = 0;
    if ( !v14 )
    {
LABEL_24:
      *v15 = v14;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Num of Allowed SSID %d",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "hdd_set_allow_list",
        (unsigned __int8)v14);
      sme_update_roam_params(*(_QWORD *)(a1 + 16), a4, a2, v15, 26);
      result = 0;
      goto LABEL_25;
    }
    goto LABEL_20;
  }
  v21 = 0;
  v22 = &wlan_hdd_set_roam_param_policy;
  v23 = v19 + 2;
  v43 = a5 + 1;
  do
  {
    v25 = *v23;
    if ( v25 < 4 || v20 < v25 )
      break;
    if ( v21 == 8 )
    {
      v41 = "%s: Excess MAX_SSID_ALLOWED_LIST";
      goto LABEL_18;
    }
    if ( (unsigned int)_nla_parse(v45, 22, v23 + 2, (unsigned __int16)(v25 - 4), v22, 31, 0) )
    {
      v41 = "%s: nla_parse failed";
      goto LABEL_18;
    }
    if ( !v46 )
    {
      v41 = "%s: attr allowed ssid failed";
      goto LABEL_18;
    }
    v26 = (unsigned __int16)(*v46 - 4);
    if ( v26 < 2 || (v27 = v26 - 1, v26 - 1 >= 0x21) )
    {
      qdf_trace_msg(0x33u, 2u, "%s: Invalid buffer length", a6, a7, a8, a9, a10, a11, a12, a13, "hdd_set_allow_list");
    }
    else
    {
      if ( v21 > 8 )
      {
        __break(0x5512u);
        return hdd_set_bssid_prefs();
      }
      v28 = a1;
      v29 = a2;
      v30 = a4;
      v31 = v22;
      v32 = &v43[33 * v21];
      nla_memcpy(v32 + 1, v46, v27);
      *v32 = v27;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: SSID[%d]: %.*s,length = %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "hdd_set_allow_list",
        v21,
        v27,
        v32 + 1,
        v27);
      v22 = v31;
      a4 = v30;
      a2 = v29;
      a1 = v28;
      v15 = a5;
      ++v21;
    }
    v24 = (*v23 + 3) & 0x1FFFC;
    v20 -= v24;
    v23 = (unsigned __int16 *)((char *)v23 + v24);
  }
  while ( v20 > 3 );
LABEL_23:
  if ( v21 == v14 )
    goto LABEL_24;
LABEL_20:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Invalid number of SSIDs i = %d, count = %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "hdd_set_allow_list",
    v21,
    v14);
LABEL_21:
  result = 4294967274LL;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
