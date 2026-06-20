__int64 __fastcall hdd_set_p2p_opps(__int64 a1, char *s)
{
  size_t v4; // x0
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  __int64 v24; // x4
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int8 v34; // w8
  unsigned int v35; // w5
  __int64 v36; // x9
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // [xsp+18h] [xbp-38h] BYREF
  unsigned int v46; // [xsp+20h] [xbp-30h] BYREF
  unsigned int v47[3]; // [xsp+24h] [xbp-2Ch] BYREF
  __int64 v48; // [xsp+30h] [xbp-20h]
  __int64 v49; // [xsp+38h] [xbp-18h]
  int v50; // [xsp+40h] [xbp-10h]
  int v51; // [xsp+44h] [xbp-Ch]
  __int64 v52; // [xsp+48h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v46 = 0;
  v45 = 0;
  v4 = strlen(s);
  v5 = strnchr(s, v4, 32);
  if ( !v5 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: strnchr failed to find delimiter",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_set_p2p_opps");
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  v14 = sscanf((const char *)(v5 + 1), "%d %d %d", &v46, (char *)&v45 + 4, &v45);
  if ( v14 != 3 )
  {
    v24 = v14;
    v23 = "%s: P2P_SET GO PS: fail to read params, ret=%d";
    goto LABEL_7;
  }
  if ( (unsigned int)(HIDWORD(v45) - 2) <= 0xFFFFFFFC )
  {
    v23 = "%s: Invalid opp_ps value:%d";
    v24 = HIDWORD(v45);
LABEL_7:
    qdf_trace_msg(0x33u, 2u, v23, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_set_p2p_opps", v24);
    goto LABEL_8;
  }
  if ( (unsigned int)(v45 + 1) >= 2 && (unsigned int)(v45 - 10) >= 0x76 )
  {
    v23 = "%s: Invalid CT window value:%d";
    v24 = (unsigned int)v45;
    goto LABEL_7;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: P2P_SET GO PS: legacy_ps=%d opp_ps=%d ctwindow=%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hdd_set_p2p_opps",
    v46);
  if ( (_DWORD)v45 != -1 )
    *(_DWORD *)(a1 + 4300) = v45;
  v34 = BYTE4(v45);
  if ( HIDWORD(v45) != -1 )
  {
    v35 = *(_DWORD *)(a1 + 4300);
    *(_BYTE *)(a1 + 4296) = BYTE4(v45);
    v36 = *(_QWORD *)(a1 + 55512);
    v48 = 0;
    v49 = 0;
    v47[2] = v35;
    v50 = 1;
    v47[0] = *(unsigned __int8 *)(v36 + 8);
    v47[1] = v34;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: P2P_PS_ATTR: opp ps %d ct window %d duration %d interval %d count %d single noa duration %d ps selection %x",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_set_p2p_opps",
      0,
      0,
      1);
    wlan_hdd_set_power_save(a1 + 2688, v47, v37, v38, v39, v40, v41, v42, v43, v44);
  }
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
