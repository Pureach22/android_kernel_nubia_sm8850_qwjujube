__int64 __fastcall scm_add_rnr_channel_db(__int64 result, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // x21
  __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w23
  __int64 v15; // x20
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x9
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x8
  int v29; // w9
  unsigned __int8 *v30; // x8
  unsigned __int8 *v31; // x23
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x24
  __int64 v41; // x25
  __int64 v42; // x19
  int v43; // w2
  int v44; // w0
  int v45; // w26
  __int64 v46; // x0
  __int64 v47; // x20
  __int64 v48; // x8
  __int64 v49; // x20
  int v50; // w8
  int v51; // w9
  int v52; // w10
  int v53; // w11
  int v54; // w28
  _DWORD *v55; // x27
  _QWORD *v56; // x8
  bool v57; // zf
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x28
  int v68; // w8
  int v69; // w9
  int v70; // w10
  int v71; // w11
  int v72; // w12
  __int64 v73; // x12
  int v74; // w13
  const char *v75; // x2
  __int64 v76; // [xsp+0h] [xbp-70h]
  __int64 v77; // [xsp+8h] [xbp-68h]
  __int64 v78; // [xsp+10h] [xbp-60h]
  __int64 v79; // [xsp+18h] [xbp-58h]
  __int64 v80; // [xsp+20h] [xbp-50h]
  __int64 v81; // [xsp+28h] [xbp-48h]
  __int64 v82; // [xsp+30h] [xbp-40h]
  __int64 v83; // [xsp+40h] [xbp-30h]
  __int64 v84; // [xsp+48h] [xbp-28h]
  _QWORD *v85; // [xsp+50h] [xbp-20h] BYREF
  _QWORD *v86[3]; // [xsp+58h] [xbp-18h] BYREF

  v86[2] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 80);
  if ( !v2 )
    goto LABEL_71;
  v3 = result;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(result + 80), 3u);
  if ( !comp_private_obj )
  {
    result = qdf_trace_msg(
               0x15u,
               2u,
               "%s: %s:%u, Failed to get scan object",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "wlan_psoc_get_scan_obj_fl",
               "scm_add_rnr_channel_db",
               144);
    goto LABEL_71;
  }
  v14 = *(_DWORD *)(a2 + 1192);
  v15 = comp_private_obj;
  result = wlan_reg_is_6ghz_chan_freq(v14);
  if ( (result & 1) != 0 )
  {
    qdf_mutex_acquire(v15 + 23920);
    if ( !v14 || !wlan_reg_is_6ghz_chan_freq(v14) )
      goto LABEL_20;
    v16 = wlan_objmgr_psoc_get_comp_private_obj(v2, 3u);
    if ( !v16 )
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s:%u, Failed to get scan object",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_psoc_get_scan_obj_fl",
        "scm_get_rnr_channel_db",
        68);
      v27 = v15 + 23920;
      goto LABEL_70;
    }
    v25 = 60;
    v26 = v16 + 21032;
    while ( *(_DWORD *)v26 != v14 )
    {
      --v25;
      v26 += 48;
      if ( !v25 )
        goto LABEL_20;
    }
    if ( !v26 )
    {
LABEL_20:
      v27 = v15 + 23920;
      goto LABEL_70;
    }
    ++*(_DWORD *)(v26 + 4);
    *(_QWORD *)(v26 + 16) = *(_QWORD *)(a2 + 88);
    result = qdf_mutex_release(v15 + 23920);
  }
  if ( !*(_QWORD *)(a2 + 1760) )
    goto LABEL_71;
  v28 = *(_QWORD *)(a2 + 1336);
  if ( v28 )
  {
    v29 = *(unsigned __int8 *)(v28 + 1);
    v30 = (unsigned __int8 *)(v28 + 2);
    if ( v29 )
      v31 = v30;
    else
      v31 = nullptr;
  }
  else
  {
    v31 = nullptr;
  }
  v83 = v15;
  qdf_mutex_acquire(v15 + 23920);
  v40 = 0;
  v84 = a2;
  v41 = a2 + 136;
  while ( 1 )
  {
    v42 = v41 + 32 * v40;
    v43 = *(_DWORD *)(v42 + 4);
    if ( v43 )
    {
      v44 = wlan_reg_chan_opclass_to_freq_prefer_global(
              v3,
              v31,
              v43,
              *(_DWORD *)(v42 + 8),
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39);
      if ( !v44 )
      {
        v49 = jiffies;
        if ( scm_add_rnr_channel_db___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x15u,
            8u,
            "%s: Invalid op_class %d",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "scm_add_rnr_channel_db",
            *(unsigned int *)(v42 + 8));
          scm_add_rnr_channel_db___last_ticks = v49;
        }
        goto LABEL_24;
      }
      v45 = v44;
      if ( wlan_reg_is_6ghz_chan_freq(v44) )
        break;
    }
LABEL_24:
    if ( ++v40 == 33 )
      goto LABEL_69;
  }
  v46 = wlan_objmgr_psoc_get_comp_private_obj(v2, 3u);
  if ( !v46 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wlan_psoc_get_scan_obj_fl",
      "scm_get_rnr_channel_db",
      68);
    goto LABEL_24;
  }
  v47 = v46 + 21032;
  v48 = 60;
  while ( *(_DWORD *)v47 != v45 )
  {
    --v48;
    v47 += 48;
    if ( !v48 )
      goto LABEL_24;
  }
  if ( !v47 )
    goto LABEL_24;
  ++*(_DWORD *)(v47 + 4);
  if ( (*(_BYTE *)(v42 + 24) & 0xC) == 4 )
  {
    if ( v42 == -12 )
    {
      v52 = 0;
      v50 = 0;
      v51 = 0;
      v53 = 0;
    }
    else
    {
      v50 = *(unsigned __int8 *)(v42 + 12);
      v51 = *(unsigned __int8 *)(v42 + 13);
      v52 = *(unsigned __int8 *)(v42 + 14);
      v53 = *(unsigned __int8 *)(v42 + 17);
    }
    v73 = v84;
    v74 = *(_DWORD *)(v42 + 20);
    v75 = "%s: %02x:%02x:%02x:**:**:%02x(freq %d): skip nontx freq %d %02x:%02x:%02x:**:**:%02x short ssid %x";
LABEL_61:
    LODWORD(v82) = v74;
    LODWORD(v81) = v53;
    LODWORD(v80) = v52;
    LODWORD(v79) = v51;
    LODWORD(v78) = v50;
    LODWORD(v77) = v45;
    LODWORD(v76) = *(_DWORD *)(v73 + 1192);
    qdf_trace_msg(
      0x15u,
      8u,
      v75,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "scm_add_rnr_channel_db",
      *(unsigned __int8 *)(v73 + 1),
      *(unsigned __int8 *)(v73 + 2),
      *(unsigned __int8 *)(v73 + 3),
      *(unsigned __int8 *)(v73 + 6),
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82);
    goto LABEL_24;
  }
  v54 = *(_DWORD *)(v42 + 20);
  v85 = nullptr;
  v86[0] = nullptr;
  v55 = (_DWORD *)(v42 + 12);
  if ( !qdf_list_empty((_QWORD *)(v47 + 24)) )
  {
    qdf_list_peek_front((_QWORD *)(v47 + 24), v86);
    v56 = v86[0];
    if ( v86[0] )
    {
      while ( 1 )
      {
        v57 = *((_DWORD *)v56 + 7) == *v55 && *((unsigned __int16 *)v56 + 16) == *(unsigned __int16 *)(v42 + 16);
        if ( v57 && *((_DWORD *)v56 + 6) == v54 )
          break;
        if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v47 + 24), v86[0], &v85) )
        {
          v56 = v85;
          v85 = nullptr;
          v86[0] = v56;
          if ( v56 )
            continue;
        }
        goto LABEL_49;
      }
      if ( v42 == -12 )
      {
        v52 = 0;
        v50 = 0;
        v51 = 0;
        v53 = 0;
      }
      else
      {
        v50 = *(unsigned __int8 *)(v42 + 12);
        v51 = *(unsigned __int8 *)(v42 + 13);
        v52 = *(unsigned __int8 *)(v42 + 14);
        v53 = *(unsigned __int8 *)(v42 + 17);
      }
      v73 = v84;
      v74 = *(_DWORD *)(v42 + 20);
      v75 = "%s: %02x:%02x:%02x:**:**:%02x(freq %d): skip dup freq %d %02x:%02x:%02x:**:**:%02x short ssid %x";
      goto LABEL_61;
    }
  }
LABEL_49:
  if ( *(_DWORD *)(v47 + 40) < 0xFu )
  {
    v58 = _qdf_mem_malloc(0x28u, "scm_add_rnr_channel_db", 229);
    if ( !v58 )
      goto LABEL_69;
    v67 = v58;
    *(_QWORD *)(v58 + 16) = *(_QWORD *)(v84 + 88);
    if ( *v55 | *(unsigned __int16 *)(v42 + 16) )
      qdf_mem_copy((void *)(v58 + 28), (const void *)(v42 + 12), 6u);
    v68 = *(_DWORD *)(v42 + 20);
    if ( v68 )
      *(_DWORD *)(v67 + 24) = v68;
    if ( *(_BYTE *)(v42 + 24) )
      *(_BYTE *)(v67 + 34) = *(_BYTE *)(v42 + 24);
    if ( v42 == -12 )
    {
      v71 = 0;
      v69 = 0;
      v70 = 0;
      v72 = 0;
    }
    else
    {
      v69 = *(unsigned __int8 *)(v42 + 12);
      v70 = *(unsigned __int8 *)(v42 + 13);
      v71 = *(unsigned __int8 *)(v42 + 14);
      v72 = *(unsigned __int8 *)(v42 + 17);
    }
    LODWORD(v82) = *(_DWORD *)(v42 + 20);
    LODWORD(v81) = v72;
    LODWORD(v80) = v71;
    LODWORD(v79) = v70;
    LODWORD(v78) = v69;
    LODWORD(v77) = v45;
    LODWORD(v76) = *(_DWORD *)(v84 + 1192);
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x(freq %d): Add freq %d %02x:%02x:%02x:**:**:%02x short ssid %x",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "scm_add_rnr_channel_db",
      *(unsigned __int8 *)(v84 + 1),
      *(unsigned __int8 *)(v84 + 2),
      *(unsigned __int8 *)(v84 + 3),
      *(unsigned __int8 *)(v84 + 6),
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82);
    qdf_list_insert_back((_QWORD *)(v47 + 24), (_QWORD *)v67);
    goto LABEL_24;
  }
  LODWORD(v76) = *(_DWORD *)(v84 + 1192);
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: %02x:%02x:%02x:**:**:%02x(freq %d): List is full, skip",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "scm_add_rnr_channel_db",
    *(unsigned __int8 *)(v84 + 1),
    *(unsigned __int8 *)(v84 + 2),
    *(unsigned __int8 *)(v84 + 3),
    *(unsigned __int8 *)(v84 + 6),
    v76);
LABEL_69:
  v27 = v83 + 23920;
LABEL_70:
  result = qdf_mutex_release(v27);
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
