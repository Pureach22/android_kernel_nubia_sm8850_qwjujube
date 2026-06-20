__int64 __fastcall wlan_hdd_set_mc_rate(
        __int64 *a1,
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
  __int64 v10; // x23
  __int64 *v11; // x22
  unsigned int v12; // w0
  unsigned int v14; // w19
  const char *v15; // x2
  const char *v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v26; // w0
  int v27; // w24
  __int16 v28; // w9
  int v29; // w25
  const char *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _BYTE v39[4]; // [xsp+1Ch] [xbp-34h] BYREF
  bool v40; // [xsp+20h] [xbp-30h] BYREF
  _BYTE v41[11]; // [xsp+21h] [xbp-2Fh]
  __int64 v42; // [xsp+2Ch] [xbp-24h]
  __int64 v43; // [xsp+34h] [xbp-1Ch]
  __int64 v44; // [xsp+3Ch] [xbp-14h]
  int v45; // [xsp+44h] [xbp-Ch]
  __int64 v46; // [xsp+48h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v45 = 0;
  v44 = 0;
  v43 = 0;
  v11 = *(__int64 **)(v10 + 24);
  v42 = 0;
  *(_QWORD *)&v41[3] = 0;
  v39[0] = 0;
  if ( v11 )
  {
    v12 = *(_DWORD *)(v10 + 40);
    if ( v12 >= 2 )
    {
      v16 = qdf_opmode_str(v12);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Received SETMCRATE cmd in invalid mode %s(%d)",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_hdd_set_mc_rate",
        v16,
        *(unsigned int *)(v10 + 40));
      v14 = -22;
      v15 = "%s: SETMCRATE cmd is allowed only in STA or SOFTAP mode";
    }
    else if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*v11, v39) )
    {
      v14 = -22;
      v15 = "%s: unable to get vht_enable2x2";
    }
    else
    {
      v26 = *(_DWORD *)(v10 + 40);
      v27 = *(_DWORD *)(v10 + 1617);
      v28 = *(_WORD *)(v10 + 1621);
      HIDWORD(v43) = a2;
      LODWORD(v44) = 1;
      *(_DWORD *)v41 = v27;
      *(_WORD *)&v41[4] = v28;
      v40 = v39[0] != 0;
      v29 = HIBYTE(v28);
      *(_DWORD *)&v41[7] = v26;
      LODWORD(v42) = -1;
      HIDWORD(v44) = a2;
      v30 = qdf_opmode_str(v26);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: MC Target rate %d, mac = %02x:%02x:%02x:**:**:%02x, dev_mode %s(%d)",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "wlan_hdd_set_mc_rate",
        a2,
        (unsigned __int8)v27,
        BYTE1(v27),
        BYTE2(v27),
        v29,
        v30,
        *(_DWORD *)(v10 + 40));
      if ( !(unsigned int)sme_send_rate_update_ind(v11[2], &v40) )
      {
        v14 = 0;
        goto LABEL_8;
      }
      v14 = -14;
      v15 = "%s: SETMCRATE failed";
    }
  }
  else
  {
    v14 = -22;
    v15 = "%s: HDD context is null";
  }
  qdf_trace_msg(0x33u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_set_mc_rate");
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v14;
}
