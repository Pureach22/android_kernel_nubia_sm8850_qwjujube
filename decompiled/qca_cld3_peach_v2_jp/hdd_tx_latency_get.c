__int64 __fastcall hdd_tx_latency_get(
        __int64 a1,
        __int64 a2,
        _WORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x19
  __int64 v24; // x27
  char *v25; // x25
  int v26; // w8
  char v27; // w20
  unsigned int v28; // w22
  int v29; // w8
  int v30; // w24
  unsigned __int16 *v31; // x25
  unsigned int v32; // w9
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int16 *v42; // x26
  __int64 v43; // x0
  __int64 v44; // x22
  __int64 v45; // x8
  unsigned __int64 StatusReg; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  _QWORD *v55; // x1
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  unsigned __int8 *v65; // x8
  unsigned __int64 v66; // x20
  const void *v67; // x23
  char v68; // w28
  __int64 v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x24
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x8
  char v88; // w20
  char *v89; // x24
  __int64 v90; // x0
  __int64 v91; // x25
  const char *v92; // x2
  _QWORD *v93; // x21
  _QWORD *v94; // x23
  __int64 v95; // x0
  __int64 v96; // x21
  __int64 v97; // x23
  __int64 v98; // x20
  _WORD *v99; // x24
  __int64 v100; // x21
  unsigned int v101; // w23
  _QWORD *v102; // x26
  __int64 v103; // x8
  _DWORD *v104; // x8
  __int64 v105; // x1
  unsigned int v106; // w0
  __int64 v107; // x20
  _QWORD *v108; // x21
  _QWORD *v109; // x22
  unsigned int v110; // w19
  _QWORD *v111; // x19
  _QWORD *v112; // x21
  _QWORD *v113; // x19
  _QWORD *v114; // x21
  __int64 v115; // x20
  _QWORD *v117; // [xsp+8h] [xbp-B8h]
  __int64 v118; // [xsp+10h] [xbp-B0h]
  _QWORD v119[2]; // [xsp+18h] [xbp-A8h] BYREF
  __int64 v120; // [xsp+28h] [xbp-98h]
  _QWORD *v121; // [xsp+30h] [xbp-90h] BYREF
  _QWORD *v122; // [xsp+38h] [xbp-88h] BYREF
  unsigned __int16 *v123; // [xsp+40h] [xbp-80h]
  __int64 v124; // [xsp+48h] [xbp-78h]
  __int64 v125; // [xsp+50h] [xbp-70h]
  __int64 v126; // [xsp+58h] [xbp-68h]
  __int64 v127; // [xsp+60h] [xbp-60h]
  __int64 v128; // [xsp+68h] [xbp-58h]
  __int64 v129; // [xsp+70h] [xbp-50h]
  __int64 v130; // [xsp+78h] [xbp-48h]
  __int64 v131; // [xsp+80h] [xbp-40h]
  __int64 v132; // [xsp+88h] [xbp-38h]
  __int64 v133; // [xsp+90h] [xbp-30h]
  __int64 v134; // [xsp+98h] [xbp-28h]
  __int64 v135; // [xsp+A0h] [xbp-20h]
  __int64 v136; // [xsp+A8h] [xbp-18h]
  __int64 v137; // [xsp+B0h] [xbp-10h]

  v137 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"hdd_tx_latency_get", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    v28 = -22;
    goto LABEL_113;
  }
  v23 = context;
  v24 = a2 + 52824;
  v25 = "s_thermal_cdev_register";
  v119[0] = v119;
  v119[1] = v119;
  v120 = 0;
  v118 = a1;
  if ( a3 )
  {
    v26 = *(_DWORD *)(a2 + 40);
    v123 = nullptr;
    v124 = 0;
    v122 = nullptr;
    if ( v26 )
      v27 = *(_BYTE *)(*(_QWORD *)v24 + 8LL);
    else
      v27 = -1;
    v30 = (unsigned __int16)(*a3 - 4);
    if ( (unsigned int)v30 >= 4 )
    {
      v31 = a3 + 2;
      while ( 1 )
      {
        v32 = *v31;
        v28 = 0;
        if ( v32 < 4 || v30 < v32 )
          goto LABEL_71;
        v33 = _nla_parse(&v122, 2, v31 + 2, (unsigned __int16)(v32 - 4), &tx_latency_link_policy, 31, 0);
        if ( v33 )
          break;
        v42 = v123;
        if ( !v123 )
        {
          v92 = "%s: Missing link mac remote attribute";
          goto LABEL_66;
        }
        if ( (unsigned int)*v123 - 4 <= 5 )
        {
          v92 = "%s: Attribute link mac remote is invalid";
LABEL_66:
          qdf_trace_msg(0x33u, 2u, v92, v34, v35, v36, v37, v38, v39, v40, v41, "hdd_tx_latency_get_links_from_attr");
LABEL_67:
          v28 = -22;
          goto LABEL_69;
        }
        v43 = _qdf_mem_malloc(0x18u, "hdd_tx_latency_link_list_add", 12040);
        if ( !v43 )
        {
          v28 = -12;
LABEL_69:
          v93 = (_QWORD *)v119[0];
          if ( (_QWORD *)v119[0] != v119 )
          {
            do
            {
              v94 = (_QWORD *)*v93;
              qdf_list_remove_node((__int64)v119, v93);
              _qdf_mem_free((__int64)v93);
              v93 = v94;
            }
            while ( v94 != v119 );
          }
          goto LABEL_71;
        }
        v44 = v43;
        qdf_mem_copy((void *)(v43 + 17), v42 + 2, 6u);
        *(_BYTE *)(v44 + 16) = v27;
        qdf_list_insert_back(v119, (_QWORD *)v44);
        v45 = (*v31 + 3) & 0x1FFFC;
        v30 -= v45;
        v31 = (unsigned __int16 *)((char *)v31 + v45);
        if ( v30 <= 3 )
          goto LABEL_20;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Attribute parse failed, ret %d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "hdd_tx_latency_get_links_from_attr",
        v33);
      goto LABEL_67;
    }
LABEL_20:
    v28 = 0;
LABEL_71:
    v25 = "s_thermal_cdev_register";
    if ( !v28 )
      goto LABEL_72;
    goto LABEL_109;
  }
  v29 = *(_DWORD *)(a2 + 40);
  v28 = -524;
  if ( v29 > 1 )
  {
    if ( v29 != 2 )
    {
      if ( v29 != 3 )
        goto LABEL_109;
      goto LABEL_23;
    }
LABEL_54:
    if ( !a2 || (*(_QWORD *)(a2 + 1640) & 1) == 0 )
      goto LABEL_72;
    while ( 1 )
    {
      if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                            *(_BYTE *)(a2 + 52840),
                            (__int64)"hdd_tx_latency_get_links_for_sta",
                            v15,
                            v16,
                            v17,
                            v18,
                            v19,
                            v20,
                            v21,
                            v22)
        && hdd_cm_is_vdev_associated((_DWORD *)(a2 + 52832)) )
      {
        v88 = *(_BYTE *)(a2 + 52840);
        v89 = v25;
        v90 = _qdf_mem_malloc(0x18u, "hdd_tx_latency_link_list_add", 12040);
        if ( !v90 )
        {
          v113 = (_QWORD *)v119[0];
          v28 = -12;
          if ( (_QWORD *)v119[0] != v119 )
          {
            do
            {
              v114 = (_QWORD *)*v113;
              qdf_list_remove_node((__int64)v119, v113);
              _qdf_mem_free((__int64)v113);
              v113 = v114;
            }
            while ( v114 != v119 );
          }
          goto LABEL_109;
        }
        v91 = v90;
        qdf_mem_copy((void *)(v90 + 17), (const void *)(a2 + 53132), 6u);
        *(_BYTE *)(v91 + 16) = v88;
        qdf_list_insert_back(v119, (_QWORD *)v91);
        v25 = v89;
      }
      if ( (unsigned __int8)~(-910593773 * ((unsigned int)(a2 - *(_DWORD *)(a2 + 52832)) >> 4))
        || (*(_QWORD *)(a2 + 1640) & 1) == 0 )
      {
        goto LABEL_72;
      }
    }
  }
  if ( !v29 )
    goto LABEL_54;
  if ( v29 != 1 )
    goto LABEL_109;
LABEL_23:
  v117 = context;
  v121 = nullptr;
  v122 = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 38872);
  }
  else
  {
    raw_spin_lock_bh(a2 + 38872);
    *(_QWORD *)(a2 + 38880) |= 1uLL;
  }
  hdd_get_front_sta_info_no_lock((_QWORD *)(a2 + 38848), &v122);
  v55 = v122;
  if ( v122 )
  {
    hdd_take_sta_info_ref(a2 + 38848, (__int64)v122, 0, 0x16u, v47, v48, v49, v50, v51, v52, v53, v54);
    v55 = v122;
  }
  hdd_get_next_sta_info_no_lock((_QWORD *)(a2 + 38848), v55, &v121);
  if ( v121 )
    hdd_take_sta_info_ref(a2 + 38848, (__int64)v121, 0, 0x16u, v56, v57, v58, v59, v60, v61, v62, v63);
  v64 = *(_QWORD *)(a2 + 38880);
  if ( (v64 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 38880) = v64 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 38872);
    v65 = (unsigned __int8 *)v122;
    if ( v122 )
      goto LABEL_33;
LABEL_107:
    v28 = 0;
    goto LABEL_108;
  }
  raw_spin_unlock(a2 + 38872);
  v65 = (unsigned __int8 *)v122;
  if ( !v122 )
    goto LABEL_107;
LABEL_33:
  v66 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v67 = v65 + 32;
    if ( v65[32] == 255 && v65[33] == 255 && v65[34] == 255 && v65[35] == 255 && v65[36] == 255 && v65[37] == 255 )
      goto LABEL_42;
    v68 = *(_BYTE *)(*(_QWORD *)v24 + 8LL);
    v69 = _qdf_mem_malloc(0x18u, "hdd_tx_latency_link_list_add", 12040);
    if ( !v69 )
      break;
    v78 = v69;
    qdf_mem_copy((void *)(v69 + 17), v67, 6u);
    *(_BYTE *)(v78 + 16) = v68;
    qdf_list_insert_back(v119, (_QWORD *)v78);
LABEL_42:
    hdd_put_sta_info_ref(a2 + 38848, (__int64 *)&v122, 1, 0x16u, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v66 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v66 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 38872);
    }
    else
    {
      raw_spin_lock_bh(a2 + 38872);
      *(_QWORD *)(a2 + 38880) |= 1uLL;
    }
    v122 = v121;
    hdd_get_next_sta_info_no_lock((_QWORD *)(a2 + 38848), v121, &v121);
    if ( v121 )
      hdd_take_sta_info_ref(a2 + 38848, (__int64)v121, 0, 0x16u, v79, v80, v81, v82, v83, v84, v85, v86);
    v87 = *(_QWORD *)(a2 + 38880);
    if ( (v87 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 38880) = v87 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 38872);
    }
    else
    {
      raw_spin_unlock(a2 + 38872);
    }
    v65 = (unsigned __int8 *)v122;
    if ( !v122 )
      goto LABEL_107;
  }
  hdd_put_sta_info_ref(a2 + 38848, (__int64 *)&v122, 1, 0x16u, v70, v71, v72, v73, v74, v75, v76, v77);
  v108 = (_QWORD *)v119[0];
  if ( (_QWORD *)v119[0] != v119 )
  {
    v25 = "s_thermal_cdev_register";
    do
    {
      v109 = (_QWORD *)*v108;
      qdf_list_remove_node((__int64)v119, v108);
      _qdf_mem_free((__int64)v108);
      v108 = v109;
    }
    while ( v109 != v119 );
    v28 = -12;
    goto LABEL_109;
  }
  v28 = -12;
LABEL_108:
  v23 = v117;
  v25 = "s_thermal_cdev_register";
  if ( v28 )
    goto LABEL_109;
LABEL_72:
  if ( (_DWORD)v120 )
  {
    v95 = _cfg80211_alloc_reply_skb(v118, 103, 197, ((212 * (_DWORD)v120 + 7) & 0xFFFFFFFC) + 16);
    if ( !v95 )
    {
      v28 = -12;
      goto LABEL_109;
    }
    v96 = *(_QWORD *)(v95 + 216);
    v97 = *(unsigned int *)(v95 + 208);
    v98 = v95;
    v135 = 0;
    v136 = 0;
    v133 = 0;
    v134 = 0;
    v131 = 0;
    v132 = 0;
    v129 = 0;
    v130 = 0;
    v127 = 0;
    v128 = 0;
    v125 = 0;
    v126 = 0;
    v123 = nullptr;
    v124 = 0;
    v122 = nullptr;
    v28 = -12;
    if ( (nla_put(v95, 32773, 0, 0) & 0x80000000) == 0 )
    {
      v99 = (_WORD *)(v96 + v97);
      if ( v96 + v97 )
      {
        v100 = v119[0];
        if ( (_QWORD *)v119[0] == v119 )
        {
LABEL_86:
          *v99 = *(_WORD *)(v98 + 216) + *(_DWORD *)(v98 + 208) - (_WORD)v99;
LABEL_99:
          v28 = cfg80211_vendor_cmd_reply(v98);
          goto LABEL_109;
        }
        v101 = 0;
        while ( 1 )
        {
          v102 = *(_QWORD **)v100;
          qdf_list_remove_node((__int64)v119, (_QWORD *)v100);
          if ( !*v23 || (v103 = *(_QWORD *)(*v23 + 32LL)) == 0 || (v104 = *(_DWORD **)(v103 + 360)) == nullptr )
          {
            v110 = 16;
            goto LABEL_98;
          }
          v105 = *(unsigned __int8 *)(v100 + 16);
          if ( *(v104 - 1) != 929617773 )
            __break(0x8228u);
          v106 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD **))v104)(v23, v105, v100 + 17, &v122);
          if ( v106 )
            break;
          v28 = hdd_tx_latency_fill_link_stats(v98, &v122, v101);
          _qdf_mem_free(v100);
          if ( v28 )
            goto LABEL_100;
          ++v101;
          v100 = (__int64)v102;
          if ( v102 == v119 )
            goto LABEL_86;
        }
        v110 = v106;
LABEL_98:
        _qdf_mem_free(v100);
        v28 = qdf_status_to_os_return(v110);
        if ( !v28 )
          goto LABEL_99;
      }
    }
LABEL_100:
    sk_skb_reason_drop(0, v98, 2);
    v111 = (_QWORD *)v119[0];
    if ( (_QWORD *)v119[0] != v119 )
    {
      do
      {
        v112 = (_QWORD *)*v111;
        qdf_list_remove_node((__int64)v119, v111);
        _qdf_mem_free((__int64)v111);
        v111 = v112;
      }
      while ( v112 != v119 );
    }
  }
  else
  {
    v107 = *((_QWORD *)v25 + 448);
    if ( hdd_tx_latency_get___last_ticks - v107 + 125 < 0 )
    {
      qdf_trace_msg(0x33u, 2u, "%s: no valid peers", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_tx_latency_get");
      hdd_tx_latency_get___last_ticks = v107;
    }
    v28 = -22;
  }
LABEL_109:
  if ( (_DWORD)v120 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "qdf_list_destroy");
  v115 = *((_QWORD *)v25 + 448);
  if ( hdd_tx_latency_get___last_ticks_393 - v115 + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: get stats with ret %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_tx_latency_get",
      v28);
    hdd_tx_latency_get___last_ticks_393 = v115;
  }
LABEL_113:
  _ReadStatusReg(SP_EL0);
  return v28;
}
