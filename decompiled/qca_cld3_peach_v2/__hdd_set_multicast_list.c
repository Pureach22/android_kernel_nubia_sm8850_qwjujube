__int64 __fastcall _hdd_set_multicast_list(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x20
  __int64 v11; // x19
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w27
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned __int8 v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  char v64; // w8
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 *v74; // x25
  unsigned int v75; // w22
  __int64 v76; // x26
  __int64 v77; // x23
  unsigned __int8 *v78; // x8
  unsigned __int8 *v79; // x9
  int v80; // w11
  __int64 v81; // x5
  __int64 v82; // x6
  __int64 v83; // x7
  int v84; // w8
  bool v85; // zf
  __int64 v86; // [xsp+0h] [xbp-20h]
  int v87; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v88; // [xsp+18h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(result + 2712);
  if ( *(_BYTE *)(v9 + 185) == 1 )
  {
    v10 = jiffies;
    if ( _hdd_set_multicast_list___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Device is system suspended",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "__hdd_set_multicast_list");
      _hdd_set_multicast_list___last_ticks = v10;
    }
    goto LABEL_20;
  }
  v11 = result;
  v12 = *(_QWORD *)v9;
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: enter(%s)",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "__hdd_set_multicast_list",
             result + 296);
  if ( curr_con_mode == 5 )
    goto LABEL_20;
  result = _wlan_hdd_validate_context(v9, (__int64)"__hdd_set_multicast_list", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( (_DWORD)result )
    goto LABEL_20;
  result = _hdd_validate_adapter(
             v11 + 2688,
             (__int64)"__hdd_set_multicast_list",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28);
  if ( (_DWORD)result )
    goto LABEL_20;
  if ( *(_DWORD *)(v9 + 1464) == 2 )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Driver module is closed",
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               "__hdd_set_multicast_list");
LABEL_20:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  result = _qdf_mem_malloc(0xD0u, "__hdd_set_multicast_list", 6991);
  if ( !result )
    goto LABEL_20;
  v37 = result;
  qdf_spin_lock_bh_6(v11 + 42288);
  if ( *(_BYTE *)(v11 + 42088) )
    hdd_disable_and_flush_mc_addr_list(v11 + 2688, 6);
  if ( (*(_BYTE *)(v11 + 177) & 2) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: allow all multicast frames",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "__hdd_set_multicast_list");
    hdd_disable_and_flush_mc_addr_list(v11 + 2688, 6);
    v46 = 0;
LABEL_16:
    *(_BYTE *)(v11 + 42088) = v46;
    *(_QWORD *)v37 = v12;
    v64 = *(_BYTE *)(*(_QWORD *)(v11 + 55520) + 8LL);
    *(_DWORD *)(v37 + 12) = v46;
    *(_BYTE *)(v37 + 8) = v64;
    v65 = hdd_cache_mc_addr_list(v37);
    if ( v65 )
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Failed to cache MC address list for vdev %u; errno:%d",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "__hdd_set_multicast_list",
        *(unsigned __int8 *)(*(_QWORD *)(v11 + 55520) + 8LL),
        v65);
    else
      hdd_enable_mc_addr_filtering(v11 + 2688, 6);
    goto LABEL_19;
  }
  v87 = *(_DWORD *)(v11 + 896);
  v46 = v87;
  if ( v87 > (unsigned __int8)ucfg_pmo_max_mc_addr_supported(v12) )
  {
    v55 = ucfg_pmo_max_mc_addr_supported(v12);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Exceeded max MC filter addresses (%d). Allowing all MC frames by disabling MC address filtering",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "__hdd_set_multicast_list",
      v55);
    hdd_disable_and_flush_mc_addr_list(v11 + 2688, 6);
    *(_BYTE *)(v11 + 42088) = 0;
LABEL_19:
    qdf_spin_unlock_bh_4(v11 + 42288);
    result = _qdf_mem_free(v37);
    goto LABEL_20;
  }
  v74 = *(__int64 **)(v11 + 880);
  if ( v74 == (__int64 *)(v11 + 880) || !v87 )
  {
LABEL_31:
    if ( *(_DWORD *)(v11 + 2728) == 11 )
    {
      hdd_set_derived_multicast_list(v12, v11 + 2688, v37, &v87);
      v46 = v87;
    }
    goto LABEL_16;
  }
  v75 = 0;
  v76 = 0;
  v77 = 6LL * (unsigned int)v87 - 6;
  while ( v76 != 192 )
  {
    v78 = (unsigned __int8 *)(v37 + v76);
    *(_DWORD *)(v37 + v76 + 16) = 0;
    v79 = (unsigned __int8 *)(v37 + v76 + 16);
    *((_WORD *)v79 + 2) = 0;
    v80 = *((_DWORD *)v74 + 10);
    *((_WORD *)v79 + 2) = *((_WORD *)v74 + 22);
    *(_DWORD *)v79 = v80;
    if ( v37 + v76 == -16 )
    {
      v83 = 0;
      v81 = 0;
      v82 = 0;
      v84 = 0;
    }
    else
    {
      v81 = *v79;
      v82 = v78[17];
      v83 = v78[18];
      v84 = v78[21];
    }
    LODWORD(v86) = v84;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: mlist[%d] = %02x:%02x:%02x:**:**:%02x",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "__hdd_set_multicast_list",
      v75,
      v81,
      v82,
      v83,
      v86);
    v74 = (__int64 *)*v74;
    if ( v74 != (__int64 *)(v11 + 880) )
    {
      v85 = v77 == v76;
      v76 += 6;
      ++v75;
      if ( !v85 )
        continue;
    }
    goto LABEL_31;
  }
  __break(0x5512u);
  return hdd_netdev_update_features();
}
