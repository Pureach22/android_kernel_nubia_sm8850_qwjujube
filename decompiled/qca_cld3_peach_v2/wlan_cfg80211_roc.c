__int64 __fastcall wlan_cfg80211_roc(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        _QWORD *a4,
        int a5,
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
  __int64 v14; // x19
  unsigned int v15; // w21
  unsigned int v16; // w8
  unsigned int is_chan_ok_for_dnbs; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x4
  const char *v29; // x2
  const char *v30; // x2
  __int64 result; // x0
  unsigned int v32; // w0
  _BYTE v33[4]; // [xsp+4h] [xbp-1Ch] BYREF
  unsigned int v34[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[2] = 0;
  v33[0] = 0;
  if ( !a1 )
  {
    v30 = "%s: invalid vdev object";
LABEL_10:
    qdf_trace_msg(0x48u, 2u, v30, a6, a7, a8, a9, a10, a11, a12, a13, "wlan_cfg80211_roc");
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v30 = "%s: invalid channel";
    goto LABEL_10;
  }
  v13 = *(_QWORD *)(a1 + 216);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    v30 = "%s: psoc handle is NULL";
    goto LABEL_10;
  }
  v15 = *(_DWORD *)(a2 + 4);
  v16 = *(unsigned __int8 *)(a1 + 168);
  v34[3] = a3;
  v34[0] = v16;
  v34[1] = v15;
  is_chan_ok_for_dnbs = policy_mgr_is_chan_ok_for_dnbs(v14, v15, v33, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( is_chan_ok_for_dnbs )
  {
    v28 = is_chan_ok_for_dnbs;
    v29 = "%s: policy_mgr_is_chan_ok_for_dnbs():ret:%d";
  }
  else
  {
    if ( (v33[0] & 1) != 0 )
    {
      v32 = ucfg_p2p_roc_req(v14, v34, a4, a5, v20, v21, v22, v23, v24, v25, v26, v27);
      result = qdf_status_to_os_return(v32);
      goto LABEL_12;
    }
    v29 = "%s: channel%d not OK for DNBS";
    v28 = v15;
  }
  qdf_trace_msg(0x48u, 2u, v29, v20, v21, v22, v23, v24, v25, v26, v27, "wlan_cfg80211_roc", v28);
LABEL_11:
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
