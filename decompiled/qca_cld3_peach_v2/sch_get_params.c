__int64 __fastcall sch_get_params(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x23
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  unsigned __int8 *v25; // x9
  unsigned __int8 *v26; // x10
  const char *v27; // x5
  unsigned __int8 *v28; // x24
  unsigned __int8 *v29; // x25
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x21
  _DWORD *v39; // x22
  int v40; // w2
  int v41; // w9
  int v42; // w10
  int v43; // w8
  int v44; // w9
  int v45; // w8
  int v46; // w10
  int v47; // w8
  int v48; // w9
  int v49; // w8
  int v50; // w10
  int v51; // w8
  int v52; // w9
  int v53; // w8
  int v54; // w10
  int v55; // w8
  int v56; // w9
  __int64 result; // x0
  __int16 v58; // [xsp+Ch] [xbp-24h] BYREF
  char v59; // [xsp+Eh] [xbp-22h]
  __int64 v60; // [xsp+10h] [xbp-20h] BYREF
  __int64 v61; // [xsp+18h] [xbp-18h]
  unsigned __int8 v62; // [xsp+20h] [xbp-10h]
  __int64 v63; // [xsp+28h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 8);
  v15 = *(_QWORD *)(a1 + 21624);
  v59 = 0;
  v58 = 0;
  wlan_reg_get_cc_and_src(v15, &v58, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( cds_is_etsi_europe_country((unsigned __int8 *)&v58) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: switch to ETSI EUROPE profile country code %c%c",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "sch_get_params",
      (unsigned __int8)v58,
      HIBYTE(v58));
    v24 = 3;
  }
  else
  {
    v24 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5672LL);
    if ( v24 >= 4 )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Invalid EDCA_PROFILE %d, using %d instead",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sch_get_params",
        v24,
        0);
      v24 = 0;
    }
  }
  v25 = (unsigned __int8 *)&unk_B35878;
  if ( v24 == 3 )
  {
    v25 = (unsigned __int8 *)&unk_B35828;
    v26 = (unsigned __int8 *)&unk_B359A8;
  }
  else
  {
    v26 = (unsigned __int8 *)&dp_getmodulation__vht_bw_mod;
  }
  if ( v24 == 1 )
    v27 = "WMM";
  else
    v27 = "HiPerf";
  if ( v24 == 1 )
    v28 = (unsigned __int8 *)&dp_getmodulation__he_bw_mod;
  else
    v28 = v25;
  if ( v24 == 1 )
    v29 = (unsigned __int8 *)&unk_B357E8;
  else
    v29 = v26;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: EdcaProfile: Using %d (%s)",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "sch_get_params",
    v24,
    v27);
  v38 = 0;
  v39 = (_DWORD *)(a2 + 32);
  if ( !a3 )
    v28 = v29;
  while ( 1 )
  {
    v62 = 0;
    v40 = v28[4 * v38];
    v60 = 0;
    v61 = 0;
    if ( (unsigned int)wlan_mlme_get_edca_params(
                         (unsigned int *)(v14 + 16),
                         &v60,
                         v40,
                         v30,
                         v31,
                         v32,
                         v33,
                         v34,
                         v35,
                         v36,
                         v37) )
      break;
    v41 = BYTE1(v60);
    ++v38;
    v42 = BYTE2(v60);
    *(v39 - 8) = (unsigned __int8)v60;
    *(v39 - 7) = v41;
    v43 = BYTE3(v60);
    v44 = BYTE4(v60);
    *(v39 - 6) = v42;
    *(v39 - 5) = v43;
    v45 = BYTE5(v60);
    v46 = BYTE6(v60);
    *(v39 - 4) = v44;
    *(v39 - 3) = v45;
    v47 = HIBYTE(v60);
    v48 = (unsigned __int8)v61;
    *(v39 - 2) = v46;
    *(v39 - 1) = v47;
    v49 = BYTE1(v61);
    v50 = BYTE2(v61);
    *v39 = v48;
    v39[1] = v49;
    v51 = BYTE3(v61);
    v52 = BYTE4(v61);
    v39[2] = v50;
    v39[3] = v51;
    v53 = BYTE5(v61);
    v54 = BYTE6(v61);
    v39[4] = v52;
    v39[5] = v53;
    v55 = HIBYTE(v61);
    v56 = v62;
    v39[6] = v54;
    v39[7] = v55;
    v39[8] = v56;
    v39 += 17;
    if ( v38 == 4 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: GetParams: local=%d, profile = %d Done",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "sch_get_params",
        a3,
        v24);
      result = 0;
      goto LABEL_23;
    }
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Get failed for ac:%d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "sch_get_params",
    (unsigned int)v38);
  result = 16;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
