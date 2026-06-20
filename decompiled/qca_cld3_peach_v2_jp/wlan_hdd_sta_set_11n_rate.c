__int64 __fastcall wlan_hdd_sta_set_11n_rate(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v12; // x23
  __int64 v13; // x25
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w22
  __int64 v40; // x6
  __int64 v41; // x7
  unsigned int v42; // w20
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w1
  int v52; // w0
  unsigned int v53; // w21
  unsigned int v54; // w22
  unsigned int v55; // w0
  int v56; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(__int64 **)(a1 + 24);
  v13 = *(_QWORD *)(a1 + 52824);
  v56 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: Rate code %d", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_sta_set_11n_rate", a2);
  result = _wlan_hdd_validate_context(
             (__int64)v12,
             (__int64)"wlan_hdd_sta_set_11n_rate",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21);
  if ( !(_DWORD)result )
  {
    if ( wlan_hdd_validate_modules_state((__int64)v12, v23, v24, v25, v26, v27, v28, v29, v30) )
    {
      v39 = 0xFFFF;
      if ( a2 == 0xFFFF )
      {
        v40 = 0;
        v41 = 0;
        v42 = 0;
LABEL_11:
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: wmi_vdev_param_fixed_rate val %d rix %d preamble %x nss %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "wlan_hdd_sta_set_11n_rate",
          v39,
          v42,
          v40,
          v41);
        result = wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 27, v39, 1);
        goto LABEL_12;
      }
      v42 = a2 & 7;
      if ( (a2 & 0x80) != 0 )
      {
        v51 = (a2 >> 3) & 0xF;
        v52 = 2;
      }
      else
      {
        if ( (unsigned int)mlme_get_peer_phymode(*v12, (_BYTE *)(v13 + 300), &v56) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to set rate",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "wlan_hdd_sta_set_11n_rate");
          result = 4294967274LL;
          goto LABEL_12;
        }
        if ( (unsigned int)(v56 - 21) <= 9 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Do not set legacy rate %d in HE mode",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "wlan_hdd_sta_set_11n_rate",
            a2);
          result = 4294967274LL;
          goto LABEL_12;
        }
        if ( (a2 & 0x10) != 0 )
        {
          v51 = 0;
          if ( (a2 & 7) != 3 )
            v42 = a2 & 3 | 4;
          v52 = 1;
        }
        else
        {
          v52 = 0;
          v51 = 0;
        }
      }
      v53 = v51;
      v54 = v52;
      v55 = hdd_assemble_rate_code(v52, v51, v42);
      v40 = v54;
      v41 = v53;
      v39 = v55;
      goto LABEL_11;
    }
    result = 4294967274LL;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
