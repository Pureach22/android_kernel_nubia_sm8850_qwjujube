__int64 __fastcall lim_update_assoc_sta_datas(__int64 a1, __int64 a2, unsigned __int16 *a3, __int64 a4)
{
  __int64 v4; // x24
  int *v6; // x8
  int v8; // w26
  char v9; // w25
  __int16 v11; // w9
  unsigned int v13; // w8
  int v14; // w8
  char v15; // w8
  char v16; // w9
  int v17; // w8
  char v18; // w9
  char v19; // w9
  char v20; // w8
  char v21; // w8
  char v22; // w9
  unsigned int v23; // w8
  _BYTE *v24; // x23
  _BYTE *v25; // x1
  char v26; // w9
  __int64 vht_ch_width; // x0
  char v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x9
  char *v38; // x6
  __int64 v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 result; // x0
  char v49; // w8
  int v50; // w8
  __int16 v51; // w8
  unsigned int v52; // w23
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w22
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int omn_channel_width; // w22
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x8
  __int64 v104; // x11
  __int16 v105; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v106; // [xsp+18h] [xbp-8h]

  v4 = a4 + 4096;
  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 )
    v6 = (int *)(a4 + 7232);
  else
    v6 = (int *)(a1 + 4840);
  v8 = *v6;
  *(_BYTE *)(a2 + 344) = 0;
  v9 = *(_BYTE *)(a4 + 7024);
  v11 = *(_WORD *)a2 & 0xFFEF;
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(a4 + 172);
  v13 = *a3;
  *(_WORD *)(a2 + 22) = v13;
  *(_WORD *)a2 = v11 | (v13 >> 1) & 0x10;
  v14 = *(unsigned __int8 *)(a4 + 154);
  if ( (unsigned int)(v14 - 7) < 7 || v14 == 5 || !*(_BYTE *)(a4 + 154) )
  {
    v15 = *((_BYTE *)a3 + 244);
    v16 = *(_BYTE *)(a2 + 32);
    v105 = 0;
    *(_BYTE *)(a2 + 32) = v16 & 0xF7 | (8 * (v15 & 1));
    if ( *((_BYTE *)a3 + 244) )
    {
      v17 = *(_BYTE *)(a2 + 332) & 0xFE | (*((unsigned __int8 *)a3 + 245) >> 4) & 1;
      *(_BYTE *)(a2 + 332) = *(_BYTE *)(a2 + 332) & 0xFE | ((*((_BYTE *)a3 + 245) & 0x10) != 0);
      if ( *(_BYTE *)(a4 + 160) )
      {
        if ( (*(unsigned __int16 *)((char *)a3 + 245) & 2) != 0 )
          v18 = (2 * *((_BYTE *)a3 + 306)) & 8;
        else
          v18 = 0;
        v19 = *(_BYTE *)(a2 + 334) & 0xF7 | v18;
      }
      else
      {
        v19 = *(_BYTE *)(a2 + 334) & 0xF7;
      }
      *(_BYTE *)(a2 + 334) = v19;
      v20 = v17 & 0xEF | (16 * ((*(unsigned __int16 *)((char *)a3 + 245) & 0x8000) != 0));
      *(_BYTE *)(a2 + 332) = v20;
      *(_DWORD *)(a2 + 328) = (*(unsigned __int16 *)((char *)a3 + 245) >> 2) & 3;
      *(_BYTE *)(a2 + 333) = (*(unsigned __int16 *)((char *)a3 + 245) & 0x800) != 0;
      v21 = v20 & 0x1F | (32 * (*((_BYTE *)a3 + 247) >> 2));
      *(_BYTE *)(a2 + 332) = v21;
      *(_BYTE *)(a2 + 332) = (*(unsigned __int16 *)((char *)a3 + 245) >> 9) & 8 | v21 & 0xF7;
      *(_BYTE *)(a2 + 334) = v19 & 0xF8 | *((_BYTE *)a3 + 247) & 3;
      lim_fill_rx_highest_supported_rate(a1, &v105, (__int64)(a3 + 124));
      v22 = *(_BYTE *)(a2 + 334);
      *(_WORD *)(a2 + 304) = v105;
      *(_BYTE *)(a2 + 334) = (16 * (a3[153] & 3)) | v22 & 0xCF;
      if ( (*(_WORD *)(a4 + 7266) & 0x20) != 0 )
        v23 = *(_BYTE *)(a2 + 332) & 0xFB | (4 * ((*((unsigned __int8 *)a3 + 245) >> 5) & 1));
      else
        v23 = *(_BYTE *)(a2 + 332) & 0xFB;
      *(_BYTE *)(a2 + 332) = v23;
      if ( (*(_BYTE *)(a4 + 7266) & 0x40) != 0 )
        v23 = v23 & 0xFFFFFFFD | (2 * ((*((unsigned __int8 *)a3 + 245) >> 6) & 1));
      else
        LOBYTE(v23) = v23 & 0xFD;
      *(_BYTE *)(a2 + 332) = v23;
    }
  }
  if ( *((_BYTE *)a3 + 2296) )
  {
    v24 = a3 + 1148;
    v25 = a3 + 1156;
    if ( a3 == (unsigned __int16 *)-2296LL )
      goto LABEL_44;
  }
  else
  {
    if ( *((_BYTE *)a3 + 2420) )
      v24 = a3 + 1210;
    else
      v24 = nullptr;
    if ( *((_BYTE *)a3 + 2420) )
      v25 = a3 + 1218;
    else
      v25 = nullptr;
    if ( !v24 )
      goto LABEL_44;
  }
  if ( *(_BYTE *)(v4 + 3074) && *v24 )
  {
    v26 = *(_BYTE *)(a2 + 334);
    *(_BYTE *)(a2 + 32) = *(_BYTE *)(a2 + 32) & 0xEF | (16 * (*v24 & 1));
    *(_BYTE *)(a2 + 334) = v26 & 0xF8 | v24[4] & 7;
    if ( *(_BYTE *)(a4 + 160) )
    {
      if ( v25 && *v25 )
      {
        vht_ch_width = lim_get_vht_ch_width(v24, v25, a3 + 152, a3 + 122, (char *)a3 + 2335);
        v28 = lim_convert_phy_width_to_vht_width(vht_ch_width);
      }
      else
      {
        v28 = 0;
      }
      *(_BYTE *)(a2 + 345) = v28;
    }
    *(_BYTE *)(a2 + 355) = 0;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2680LL) == 1 && *((_BYTE *)a3 + 2464) && *((_BYTE *)a3 + 2468) )
      *(_BYTE *)(a2 + 355) = *((_BYTE *)a3 + 2469);
  }
LABEL_44:
  lim_update_stads_he_caps(a1, a2, a3, a4);
  v37 = *(_QWORD *)(a4 + 112);
  if ( *(_BYTE *)(a2 + 38) )
    v38 = (char *)(a3 + 1254);
  else
    v38 = nullptr;
  v39 = v37 + 4364;
  if ( !v37 )
    v39 = 0;
  if ( (unsigned int)lim_populate_peer_rate_set(
                       a1,
                       (_BYTE *)(a2 + 264),
                       (_BYTE *)a3 + 248,
                       0,
                       a4,
                       (__int64)v24,
                       v38,
                       v29,
                       v30,
                       v31,
                       v32,
                       v33,
                       v34,
                       v35,
                       v36,
                       0,
                       a2,
                       v39) )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: could not get rateset and extended rate set",
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               "lim_update_assoc_sta_datas");
    goto LABEL_83;
  }
  if ( (~*(unsigned __int16 *)(a2 + 310) & 0xC) != 0 )
    v49 = 2;
  else
    v49 = 1;
  *(_BYTE *)(a2 + 352) = v49;
  if ( v8 == 2 )
  {
    if ( (v50 = *(_WORD *)(a2 + 272) & 0x7F, (unsigned int)(v50 - 12) <= 0x3C)
      && ((1LL << ((unsigned __int8)v50 - 12)) & 0x1000001001001041LL) != 0
      || v50 == 108
      || v50 == 96 )
    {
      *(_WORD *)a2 |= 4u;
    }
  }
  v51 = *(_WORD *)a2 & 0xFF7D;
  *(_WORD *)a2 = v51;
  if ( (v9 & 1) != 0 && *((_BYTE *)a3 + 2286) )
  {
    qdf_mem_copy((void *)(a2 + 239), a3 + 16, 0x18u);
    v52 = sch_beacon_edca_process(a1, a3 + 16, a4);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Edca set update based on AssocRsp: status %d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "lim_update_assoc_sta_datas",
      v52);
    if ( v52 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Edca error in AssocResp",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "lim_update_assoc_sta_datas");
      v51 = *(_WORD *)a2;
    }
    else
    {
      v51 = *(_WORD *)a2 | 0x82;
    }
  }
  *(_WORD *)a2 = v51 & 0xFEBF;
  if ( (*(_BYTE *)(v4 + 2928) & 2) != 0 && *((_BYTE *)a3 + 2287) )
  {
    qdf_mem_copy((void *)(a2 + 239), a3 + 16, 0x18u);
    v69 = sch_beacon_edca_process(a1, a3 + 16, a4);
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: WME Edca set update based on AssocRsp: status %d",
               v70,
               v71,
               v72,
               v73,
               v74,
               v75,
               v76,
               v77,
               "lim_update_assoc_sta_datas",
               v69);
    if ( v69 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: WME Edca error in AssocResp - ignoring",
                 v78,
                 v79,
                 v80,
                 v81,
                 v82,
                 v83,
                 v84,
                 v85,
                 "lim_update_assoc_sta_datas");
      if ( (v9 & 1) == 0 )
        goto LABEL_76;
LABEL_72:
      if ( (*(_WORD *)a2 & 2) == 0 && (*(_BYTE *)(a2 + 32) & 8) != 0 )
        *(_WORD *)a2 |= 0x42u;
      goto LABEL_76;
    }
    *(_WORD *)a2 |= 0x42u;
    if ( (v9 & 1) != 0 )
      goto LABEL_72;
  }
  else
  {
    result = sch_set_default_edca_params(a1, a4);
    if ( (v9 & 1) != 0 )
      goto LABEL_72;
  }
LABEL_76:
  if ( (*(_BYTE *)(v4 + 2928) & 0x10) != 0 )
    *(_WORD *)a2 |= 0x400u;
  if ( *(_BYTE *)(v4 + 3074) && *((_BYTE *)a3 + 2335) )
  {
    omn_channel_width = lim_get_omn_channel_width((char *)a3 + 2335);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: OMN IE in (re)assoc rsp, ie width %d ch_width %d",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "lim_update_assoc_sta_datas",
      a3[1168] & 3,
      omn_channel_width);
    result = lim_update_omn_ie_ch_width(
               *(_QWORD *)(a4 + 16),
               omn_channel_width,
               v95,
               v96,
               v97,
               v98,
               v99,
               v100,
               v101,
               v102);
  }
  if ( *((_BYTE *)a3 + 2586) )
  {
    v103 = *(_QWORD *)(a3 + 1293);
    v104 = *(_QWORD *)(a3 + 1297);
    *(_QWORD *)(a2 + 823) = *(_QWORD *)((char *)a3 + 2599);
    *(_QWORD *)(a2 + 810) = v103;
    *(_QWORD *)(a2 + 818) = v104;
    result = lim_update_vdev_sr_elements(a4, a2, v78, v79, v80, v81, v82, v83, v84, v85);
  }
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return result;
}
