__int64 __fastcall sap_update_mcs_rate(
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
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x22
  _QWORD *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w21
  __int64 result; // x0
  __int64 values; // x0
  int v34; // w22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x4
  const char *v53; // x2
  unsigned int v54; // w8
  __int64 v55; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v56[2]; // [xsp+20h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56[0] = 0x3FFF0000001ALL;
  v55 = 0x1FFF0000001ALL;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v21 = context;
    v22 = _cds_get_context(53, (__int64)"sap_get_mac_context", v13, v14, v15, v16, v17, v18, v19, v20);
    if ( v22 )
    {
      v31 = *(unsigned __int16 *)(v22[1] + 1474LL);
    }
    else
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Invalid MAC context",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "he_mcs_12_13_support");
      v31 = 0;
    }
    values = cfg_psoc_get_values(v21[2694]);
    v34 = *(unsigned __int8 *)(values + 9722);
    result = qdf_trace_msg(
               0x39u,
               8u,
               "%s: session id %d, disable mcs13 support %d, he_mcs_12_13 %d, start %d, disabled_mcs13 %d, ch width %d",
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               "sap_update_mcs_rate",
               *(unsigned __int8 *)(a1 + 12),
               *(unsigned __int8 *)(values + 9722),
               v31,
               a2 & 1,
               *(unsigned __int8 *)(a1 + 1629),
               *(_DWORD *)(a1 + 1500));
    if ( v34 == 1 && v31 )
    {
      if ( (a2 & 1) != 0 )
      {
        v43 = *(_DWORD *)(a1 + 1500);
        if ( v43 <= 7 && ((1 << v43) & 0x98) != 0 )
        {
          result = sme_send_unit_test_cmd(*(unsigned __int8 *)(a1 + 12), 10, 2, &v55);
          if ( !(_DWORD)result )
          {
            *(_BYTE *)(a1 + 1629) = 1;
            goto LABEL_21;
          }
          v52 = *(unsigned __int8 *)(a1 + 12);
          v53 = "%s: Set fixed mcs rate failed, session %d";
          goto LABEL_18;
        }
      }
      else if ( (*(_BYTE *)(a1 + 1629) & 1) != 0 )
      {
        v54 = *(_DWORD *)(a1 + 1500);
        if ( v54 <= 7 && ((1 << v54) & 0x98) != 0 )
        {
          result = sme_send_unit_test_cmd(*(unsigned __int8 *)(a1 + 12), 10, 2, v56);
          if ( !(_DWORD)result )
          {
            *(_BYTE *)(a1 + 1629) = 0;
            goto LABEL_21;
          }
          v52 = *(unsigned __int8 *)(a1 + 12);
          v53 = "%s: Set default mcs rate failed, session %d";
LABEL_18:
          result = qdf_trace_msg(0x39u, 2u, v53, v44, v45, v46, v47, v48, v49, v50, v51, "sap_update_mcs_rate", v52);
        }
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x39u,
               2u,
               "%s: Invalid MAC context",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "sap_update_mcs_rate");
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
