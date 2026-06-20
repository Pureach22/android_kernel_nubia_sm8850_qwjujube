__int64 __fastcall hdd_set_bssid_prefs(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x20
  __int64 result; // x0
  const char *v15; // x2
  _WORD *v19; // x8
  int v20; // w25
  __int64 v21; // x21
  unsigned __int16 *v22; // x23
  unsigned __int8 *v23; // x27
  unsigned int v24; // w9
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  __int64 v37; // x4
  __int64 v38; // x8
  _QWORD v40[16]; // [xsp+8h] [xbp-C8h] BYREF
  __int64 v41; // [xsp+88h] [xbp-48h]
  __int64 v42; // [xsp+90h] [xbp-40h]
  __int64 v43; // [xsp+98h] [xbp-38h]
  __int64 v44; // [xsp+A0h] [xbp-30h]
  __int64 v45; // [xsp+A8h] [xbp-28h]
  __int64 v46; // [xsp+B0h] [xbp-20h]
  __int64 v47; // [xsp+B8h] [xbp-18h]
  __int64 v48; // [xsp+C0h] [xbp-10h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a3 + 120);
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v41 = 0;
  memset(v40, 0, sizeof(v40));
  if ( !v12 )
  {
    v15 = "%s: attr num of preferred bssid failed";
LABEL_21:
    qdf_trace_msg(0x33u, 2u, v15, a5, a6, a7, a8, a9, a10, a11, a12, "hdd_set_bssid_prefs");
    result = 4294967274LL;
    goto LABEL_27;
  }
  v13 = *(unsigned int *)(v12 + 4);
  if ( (unsigned int)v13 >= 0x11 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Preferred BSSID count %u exceeds max %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hdd_set_bssid_prefs",
      (unsigned int)v13,
      16);
    result = 4294967274LL;
    goto LABEL_27;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Num of Preferred BSSID (%d)",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "hdd_set_bssid_prefs",
    (unsigned int)v13);
  v19 = *(_WORD **)(a3 + 112);
  if ( !v19 )
  {
    v15 = "%s: attr Preferred BSSID failed";
    goto LABEL_21;
  }
  v20 = (unsigned __int16)(*v19 - 4);
  if ( (unsigned int)v20 < 4 )
  {
    LODWORD(v21) = 0;
  }
  else
  {
    v21 = 0;
    v22 = v19 + 2;
    v23 = a2 + 3;
    do
    {
      v24 = *v22;
      if ( v24 < 4 || v20 < v24 )
        break;
      if ( v13 == v21 )
      {
        qdf_trace_msg(
          0x33u,
          3u,
          "%s: Ignoring excess Preferred BSSID",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "hdd_set_bssid_prefs");
        goto LABEL_26;
      }
      if ( (unsigned int)_nla_parse(
                           v40,
                           22,
                           v22 + 2,
                           (unsigned __int16)(v24 - 4),
                           &wlan_hdd_set_roam_param_policy,
                           31,
                           0) )
      {
        v15 = "%s: nla_parse failed";
        goto LABEL_21;
      }
      if ( !v41 )
      {
        v15 = "%s: attr mac address failed";
        goto LABEL_21;
      }
      if ( v21 == 16 )
      {
        __break(0x5512u);
        return hdd_set_denylist_bssid();
      }
      nla_memcpy(v23 - 2, v41, 6);
      if ( v23 == (_BYTE *)&off_0 + 2 )
      {
        v35 = 0;
        v33 = 0;
        v34 = 0;
        v36 = 0;
      }
      else
      {
        v33 = *(v23 - 2);
        v34 = *(v23 - 1);
        v35 = *v23;
        v36 = v23[3];
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_set_bssid_prefs",
        v33,
        v34,
        v35,
        v36);
      if ( !v42 )
      {
        v15 = "%s: BSSID Preference score failed";
        goto LABEL_21;
      }
      v37 = (unsigned __int8)*(_DWORD *)(v42 + 4);
      a2[v21 + 97] = *(_DWORD *)(v42 + 4);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: BSSID Preference score (%d)",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "hdd_set_bssid_prefs",
        v37);
      ++v21;
      v23 += 6;
      v38 = (*v22 + 3) & 0x1FFFC;
      v20 -= v38;
      v22 = (unsigned __int16 *)((char *)v22 + v38);
    }
    while ( v20 > 3 );
  }
  if ( (unsigned int)v21 < (unsigned int)v13 )
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Num Preferred BSSID %u less than expected %u",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hdd_set_bssid_prefs",
      (unsigned int)v21,
      (unsigned int)v13);
  LOBYTE(v13) = v21;
LABEL_26:
  *a2 = v13;
  sme_update_roam_params(*(_QWORD *)(a1 + 16), a4, a2, 0, 27);
  result = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
