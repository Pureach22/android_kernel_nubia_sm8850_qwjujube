__int64 __fastcall wlan_cfg80211_mgmt_tx(
        __int64 a1,
        __int64 a2,
        char a3,
        unsigned int a4,
        __int64 a5,
        int a6,
        char a7,
        char a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        _QWORD *a17,
        int a18)
{
  __int64 v18; // x19
  unsigned int v19; // w20
  __int64 v20; // x8
  const char *v21; // x2
  __int64 v22; // x20
  char v23; // w21
  unsigned int v24; // w22
  __int64 v25; // x23
  char v26; // w25
  char v27; // w24
  int v28; // w26
  __int64 v29; // x21
  unsigned int v30; // w22
  char v31; // w26
  __int64 v32; // x0
  unsigned int v33; // w23
  int v34; // w24
  char v35; // w25
  char v36; // w27
  __int64 v37; // x28
  unsigned int is_chan_ok_for_dnbs; // w0
  __int64 v39; // x4
  const char *v40; // x2
  __int64 result; // x0
  unsigned int v42; // w0
  _BYTE v43[4]; // [xsp+4h] [xbp-3Ch] BYREF
  unsigned __int64 v44; // [xsp+8h] [xbp-38h] BYREF
  unsigned int v45; // [xsp+10h] [xbp-30h]
  int v46; // [xsp+14h] [xbp-2Ch]
  int v47; // [xsp+18h] [xbp-28h]
  int v48; // [xsp+1Ch] [xbp-24h]
  __int64 v49; // [xsp+20h] [xbp-20h]
  __int64 v50; // [xsp+28h] [xbp-18h]
  __int64 v51; // [xsp+30h] [xbp-10h]
  __int64 v52; // [xsp+38h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  v51 = 0;
  v49 = 0;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a1 + 216);
    if ( a2 )
    {
      v19 = *(_DWORD *)(a2 + 4);
      v20 = *(_QWORD *)(a1 + 216);
      if ( !v18 )
        goto LABEL_11;
    }
    else
    {
      v22 = a1;
      v23 = a3;
      v24 = a4;
      v25 = a5;
      v26 = a8;
      v27 = a7;
      v28 = a6;
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: NULL chan, set channel to 0",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        "wlan_cfg80211_mgmt_tx");
      v20 = *(_QWORD *)(v22 + 216);
      a1 = v22;
      a4 = v24;
      a6 = v28;
      a7 = v27;
      a3 = v23;
      a8 = v26;
      a5 = v25;
      v19 = 0;
      if ( !v20 )
        goto LABEL_11;
    }
    v29 = *(_QWORD *)(v20 + 80);
    if ( v29 )
    {
      v30 = *(unsigned __int8 *)(a1 + 168);
      if ( a4 >= 0x97 )
      {
        v31 = a3;
        v32 = *(_QWORD *)(v20 + 80);
        v33 = a4;
        v34 = a6;
        v35 = a7;
        v36 = a8;
        v37 = a5;
        v43[0] = 0;
        is_chan_ok_for_dnbs = policy_mgr_is_chan_ok_for_dnbs(v32, v19, v43, a9, a10, a11, a12, a13, a14, a15, a16);
        if ( is_chan_ok_for_dnbs )
        {
          v39 = is_chan_ok_for_dnbs;
          v40 = "%s: policy_mgr_is_chan_ok_for_dnbs():ret:%d";
LABEL_19:
          qdf_trace_msg(0x48u, 2u, v40, a9, a10, a11, a12, a13, a14, a15, a16, "wlan_cfg80211_mgmt_tx", v39);
          goto LABEL_13;
        }
        if ( (v43[0] & 1) == 0 )
        {
          v40 = "%s: Rejecting mgmt_tx for channel:%d as DNSC is set";
          v39 = v19;
          goto LABEL_19;
        }
        a5 = v37;
        a8 = v36;
        a3 = v31;
        a7 = v35;
        a6 = v34;
        a4 = v33;
      }
      v45 = a4;
      v46 = a6;
      v47 = a7 & 1;
      v48 = a8 & 1;
      v44 = __PAIR64__(v19, v30);
      LODWORD(v49) = a3 & 1;
      v50 = a5;
      LODWORD(v51) = a18;
      v42 = ucfg_p2p_mgmt_tx(v29, (const void **)&v44, a17, v18, a9, a10, a11, a12, a13, a14, a15, a16);
      result = qdf_status_to_os_return(v42);
      goto LABEL_14;
    }
LABEL_11:
    v21 = "%s: psoc handle is NULL";
    goto LABEL_12;
  }
  v21 = "%s: invalid vdev object";
LABEL_12:
  qdf_trace_msg(0x48u, 2u, v21, a9, a10, a11, a12, a13, a14, a15, a16, "wlan_cfg80211_mgmt_tx");
LABEL_13:
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
