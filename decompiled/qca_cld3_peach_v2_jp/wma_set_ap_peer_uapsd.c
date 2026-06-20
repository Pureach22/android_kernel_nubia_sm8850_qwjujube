__int64 __fastcall wma_set_ap_peer_uapsd(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned __int8 *a11,
        int a12,
        char a13)
{
  int v15; // w8
  int v16; // w9
  unsigned int v17; // w23
  unsigned int v18; // w22
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  int v22; // w8
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w20
  __int64 v33; // x4
  __int64 v34; // x5
  const char *v35; // x2
  __int64 v36; // x6
  __int64 v37; // x7
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  int v41; // w8
  __int64 result; // x0
  __int64 v43; // [xsp+0h] [xbp-20h]

  v15 = (a12 << 31 >> 31) & 0xC0;
  if ( (a12 & 2) != 0 )
    v15 = (a12 << 31 >> 31) & 0xC0 | 0x30;
  v16 = v15 | 0xC;
  _ReadStatusReg(SP_EL0);
  if ( (a12 & 4) == 0 )
    v16 = v15;
  if ( (a12 & 8) != 0 )
    v17 = v16 | 3;
  else
    v17 = v16;
  if ( (unsigned __int8)(a13 - 2) > 4u )
  {
    v18 = 0;
    if ( a11 )
      goto LABEL_10;
  }
  else
  {
    v18 = dword_A183C8[(unsigned __int8)(a13 - 2)];
    if ( a11 )
    {
LABEL_10:
      v19 = *a11;
      v20 = a11[1];
      v21 = a11[2];
      v22 = a11[5];
      goto LABEL_13;
    }
  }
  v21 = 0;
  v19 = 0;
  v20 = 0;
  v22 = 0;
LABEL_13:
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set WMI_AP_PS_PEER_PARAM_UAPSD 0x%x for %02x:%02x:%02x:**:**:%02x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wma_set_ap_peer_uapsd",
    v17,
    v19,
    v20,
    v21,
    v22);
  v23 = wmi_unified_ap_ps_cmd_send(*a1);
  if ( v23 )
  {
    v32 = v23;
    if ( a11 )
    {
      v33 = *a11;
      v34 = a11[1];
      v35 = "%s: Failed to set WMI_AP_PS_PEER_PARAM_UAPSD for %02x:%02x:%02x:**:**:%02x";
      v36 = a11[2];
      v37 = a11[5];
    }
    else
    {
      v36 = 0;
      v33 = 0;
      v34 = 0;
      v37 = 0;
      v35 = "%s: Failed to set WMI_AP_PS_PEER_PARAM_UAPSD for %02x:%02x:%02x:**:**:%02x";
    }
LABEL_25:
    qdf_trace_msg(0x36u, 2u, v35, v24, v25, v26, v27, v28, v29, v30, v31, "wma_set_ap_peer_uapsd", v33, v34, v36, v37);
    result = v32;
    goto LABEL_26;
  }
  if ( a11 )
  {
    v38 = *a11;
    v39 = a11[1];
    v40 = a11[2];
    v41 = a11[5];
  }
  else
  {
    v40 = 0;
    v38 = 0;
    v39 = 0;
    v41 = 0;
  }
  LODWORD(v43) = v41;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set WMI_AP_PS_PEER_PARAM_MAX_SP 0x%x for %02x:%02x:%02x:**:**:%02x",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wma_set_ap_peer_uapsd",
    v18,
    v38,
    v39,
    v40,
    v43);
  result = wmi_unified_ap_ps_cmd_send(*a1);
  if ( (_DWORD)result )
  {
    v32 = result;
    if ( a11 )
    {
      v33 = *a11;
      v34 = a11[1];
      v36 = a11[2];
      v37 = a11[5];
    }
    else
    {
      v36 = 0;
      v33 = 0;
      v34 = 0;
      v37 = 0;
    }
    v35 = "%s: Failed to set WMI_AP_PS_PEER_PARAM_MAX_SP for %02x:%02x:%02x:**:**:%02x";
    goto LABEL_25;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
