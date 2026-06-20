__int64 __fastcall fwol_cfg_on_psoc_enable(__int64 a1)
{
  _BYTE *comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _BYTE *v11; // x20
  __int64 values; // x0
  int v13; // w9
  int v14; // w8
  int v15; // w8
  __int64 v16; // x0
  __int64 v17; // x21
  size_t v18; // x0
  unsigned __int64 v19; // x2
  size_t v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  char *v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  char *v38; // x22
  unsigned int v39; // w23
  unsigned int v40; // w8
  __int64 result; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  char v52; // w9
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // [xsp+8h] [xbp-C8h] BYREF
  __int64 v56; // [xsp+10h] [xbp-C0h] BYREF
  unsigned int v57; // [xsp+1Ch] [xbp-B4h] BYREF
  char *stringp; // [xsp+20h] [xbp-B0h] BYREF
  char string[8]; // [xsp+28h] [xbp-A8h] BYREF
  __int64 v60; // [xsp+30h] [xbp-A0h]
  __int64 v61; // [xsp+38h] [xbp-98h]
  __int64 v62; // [xsp+40h] [xbp-90h]
  __int64 v63; // [xsp+48h] [xbp-88h]
  __int64 v64; // [xsp+50h] [xbp-80h]
  __int64 v65; // [xsp+58h] [xbp-78h]
  __int64 v66; // [xsp+60h] [xbp-70h]
  __int64 v67; // [xsp+68h] [xbp-68h]
  __int64 v68; // [xsp+70h] [xbp-60h]
  __int64 v69; // [xsp+78h] [xbp-58h]
  __int64 v70; // [xsp+80h] [xbp-50h]
  __int64 v71; // [xsp+88h] [xbp-48h]
  __int64 v72; // [xsp+90h] [xbp-40h]
  __int64 v73; // [xsp+98h] [xbp-38h]
  __int64 v74; // [xsp+A0h] [xbp-30h]
  __int64 v75; // [xsp+A8h] [xbp-28h]
  __int64 v76; // [xsp+B0h] [xbp-20h]
  __int64 v77; // [xsp+B8h] [xbp-18h]
  __int64 v78; // [xsp+C0h] [xbp-10h]
  __int64 v79; // [xsp+C8h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v56 = 0;
  comp_private_obj = (_BYTE *)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Du);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x66u, 2u, "%s: Failed to get FWOL Obj", v3, v4, v5, v6, v7, v8, v9, v10, "fwol_cfg_on_psoc_enable");
    result = 16;
LABEL_36:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = comp_private_obj;
  *comp_private_obj = *(_DWORD *)(cfg_psoc_get_values(a1) + 1196);
  v11[1] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1200);
  *((_WORD *)v11 + 1) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1204);
  *((_WORD *)v11 + 2) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1208);
  *((_WORD *)v11 + 3) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1212);
  *((_WORD *)v11 + 4) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1216);
  *((_WORD *)v11 + 5) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1220);
  *((_WORD *)v11 + 6) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1224);
  *((_WORD *)v11 + 7) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1228);
  *((_WORD *)v11 + 8) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1232);
  *((_WORD *)v11 + 9) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1236);
  v11[20] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1240);
  v11[21] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1241);
  *((_WORD *)v11 + 16) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2552);
  *((_WORD *)v11 + 22) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2556);
  *((_WORD *)v11 + 17) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2560);
  *((_WORD *)v11 + 23) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2564);
  *((_WORD *)v11 + 18) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2568);
  *((_WORD *)v11 + 24) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2572);
  *((_WORD *)v11 + 19) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2576);
  *((_WORD *)v11 + 25) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2580);
  *((_WORD *)v11 + 20) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2584);
  *((_WORD *)v11 + 26) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2588);
  *((_WORD *)v11 + 21) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2592);
  *((_WORD *)v11 + 27) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2596);
  v11[24] = *(_BYTE *)(cfg_psoc_get_values(a1) + 2600);
  *((_DWORD *)v11 + 7) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2604);
  *((_WORD *)v11 + 40) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2632);
  *((_DWORD *)v11 + 14) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2608);
  *((_DWORD *)v11 + 15) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2612);
  *((_DWORD *)v11 + 16) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2616);
  *((_DWORD *)v11 + 17) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2620);
  *((_DWORD *)v11 + 18) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2624);
  *((_DWORD *)v11 + 19) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2628);
  v11[83] = *(_DWORD *)(cfg_psoc_get_values(a1) + 2636);
  v11[84] = *(_DWORD *)(cfg_psoc_get_values(a1) + 2640);
  *((_DWORD *)v11 + 22) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2644);
  v11[92] = *(_DWORD *)(cfg_psoc_get_values(a1) + 2648);
  v11[96] = *(_BYTE *)(cfg_psoc_get_values(a1) + 2353);
  *((_DWORD *)v11 + 25) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2356);
  *((_DWORD *)v11 + 26) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2360);
  *((_DWORD *)v11 + 27) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2364);
  *((_DWORD *)v11 + 28) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2368);
  *((_DWORD *)v11 + 29) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2372);
  *((_DWORD *)v11 + 30) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2376);
  *((_DWORD *)v11 + 31) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2380);
  values = cfg_psoc_get_values(a1);
  v13 = *((_DWORD *)v11 + 25);
  v14 = *(_DWORD *)(values + 2384);
  *((_DWORD *)v11 + 32) = v14;
  if ( !v13
    && !*((_DWORD *)v11 + 26)
    && !*((_DWORD *)v11 + 27)
    && !*((_DWORD *)v11 + 28)
    && !*((_DWORD *)v11 + 29)
    && !*((_DWORD *)v11 + 30)
    && !(*((_DWORD *)v11 + 31) | v14) )
  {
    goto LABEL_14;
  }
  v15 = *((_DWORD *)v11 + 31);
  if ( (v15 & 0x20000000) != 0 )
  {
    v16 = cfg_psoc_get_values(a1);
    if ( strlen((const char *)(v16 + 2388)) < 8 )
    {
LABEL_14:
      v11[96] = 0;
      goto LABEL_15;
    }
    v15 = *((_DWORD *)v11 + 31);
  }
  if ( (v15 & 0x20000000) == 0 && *(_BYTE *)(cfg_psoc_get_values(a1) + 2388) )
    goto LABEL_14;
LABEL_15:
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  *(_QWORD *)string = 0;
  v60 = 0;
  v57 = 0;
  v17 = cfg_psoc_get_values(a1);
  v18 = strnlen((const char *)(v17 + 2388), 0xA0u);
  if ( v18 == -1 )
  {
    _fortify_panic(2, -1, 0);
LABEL_38:
    v20 = _fortify_panic(7, 160, v19);
    goto LABEL_39;
  }
  if ( v18 == 160 )
    v19 = 160;
  else
    v19 = v18 + 1;
  if ( v19 >= 0xA1 )
    goto LABEL_38;
  sized_strscpy(string, v17 + 2388, v19);
  stringp = string;
  *((_DWORD *)v11 + 33) = 0;
  v20 = strnlen(string, 0xA0u);
  if ( v20 >= 0xA1 )
  {
LABEL_39:
    _fortify_panic(2, 160, v20 + 1);
    goto LABEL_40;
  }
  if ( !(_BYTE)v20 )
  {
    qdf_trace_msg(
      0x66u,
      8u,
      "%s: NO OUIs to parse",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "fwol_parse_probe_req_ouis");
LABEL_35:
    fwol_init_neighbor_report_cfg(a1, (_DWORD *)v11 + 50, v30, v31, v32, v33, v34, v35, v36, v37);
    v11[232] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1242);
    v11[233] = *(_DWORD *)(cfg_psoc_get_values(a1) + 2348);
    v11[234] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1243);
    v11[235] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1244);
    v11[236] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1248);
    v11[237] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1252);
    *((_WORD *)v11 + 119) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1256);
    *((_WORD *)v11 + 120) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1260);
    v11[242] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1264);
    v11[243] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1265);
    v11[244] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1266);
    v11[245] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1267);
    *((_WORD *)v11 + 123) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1268);
    *((_WORD *)v11 + 124) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1272);
    *((_WORD *)v11 + 125) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1276);
    v42 = cfg_psoc_get_values(a1);
    qdf_uint8_array_parse((_BYTE *)(v42 + 1280), (__int64)(v11 + 252), 512, &v56);
    v11[764] = v56;
    v43 = cfg_psoc_get_values(a1);
    qdf_uint8_array_parse((_BYTE *)(v43 + 1824), (__int64)(v11 + 765), 512, &v55);
    v11[1277] = v55;
    *((_DWORD *)v11 + 321) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1800);
    v11[1288] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1804);
    v11[1289] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1805);
    v11[1290] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1806);
    v11[1291] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1808);
    *((_DWORD *)v11 + 323) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1812);
    fwol_init_adapt_dwelltime_in_cfg(a1, v11 + 1296, v44, v45, v46, v47, v48, v49, v50, v51);
    v11[1279] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1793);
    *((_DWORD *)v11 + 320) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1796);
    v11[1278] = *(_BYTE *)(cfg_psoc_get_values(a1) + 1816);
    *((_DWORD *)v11 + 327) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1820);
    *((_DWORD *)v11 + 328) = *(_DWORD *)(cfg_psoc_get_values(a1) + 2340);
    v52 = *(_BYTE *)(cfg_psoc_get_values(a1) + 2344);
    *((_QWORD *)v11 + 178) = 0xFFFFFFFF00000000LL;
    v11[1316] = v52;
    v53 = cfg_psoc_get_values(a1);
    result = 0;
    v11[1317] = *(_BYTE *)(v53 + 2352);
    goto LABEL_36;
  }
  if ( (unsigned __int8)v20 != 160 )
  {
    v29 = strsep(&stringp, " ");
    if ( v29 )
    {
      v38 = v29;
      v39 = 0;
      while ( 1 )
      {
        if ( strlen(v38) == 8 && !(unsigned int)kstrtouint(v38, 16, &v57) )
        {
          v40 = v39 + 1;
          *(_DWORD *)&v11[4 * v39 + 136] = bswap32(v57);
          v39 = v40;
          if ( v40 > 0xF )
            break;
        }
        v38 = strsep(&stringp, " ");
        if ( !v38 )
        {
          v40 = v39;
          if ( !v39 )
            goto LABEL_34;
          break;
        }
      }
      *((_DWORD *)v11 + 33) = v40;
    }
    else
    {
LABEL_34:
      v11[96] = 0;
    }
    goto LABEL_35;
  }
LABEL_40:
  v54 = _fortify_panic(4, 160, 161);
  return fwol_cfg_on_psoc_disable(v54);
}
