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
  __int64 v24; // x25
  int v25; // w8
  char v26; // w20
  unsigned int v27; // w22
  int v28; // w8
  int v29; // w24
  unsigned __int16 *v30; // x25
  unsigned int v31; // w9
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int16 *v41; // x26
  __int64 v42; // x0
  __int64 v43; // x22
  __int64 v44; // x8
  unsigned __int64 StatusReg; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  _QWORD *v54; // x1
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x8
  unsigned __int8 *v64; // x8
  unsigned __int64 v65; // x20
  const void *v66; // x23
  char v67; // w28
  __int64 v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x24
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x8
  __int64 v87; // x24
  const char *v88; // x2
  _QWORD *v89; // x21
  _QWORD *v90; // x19
  _QWORD *v91; // x21
  _QWORD *v92; // x19
  _QWORD *v93; // x22
  char v94; // w19
  __int64 v95; // x0
  __int64 v96; // x25
  __int64 v97; // x8
  __int64 v98; // x9
  __int64 v99; // x10
  _QWORD *v100; // x19
  _QWORD *v101; // x21
  __int64 v102; // x20
  __int64 v104; // x0
  _QWORD *v105; // x23
  __int64 v106; // x19
  __int64 v107; // x21
  __int64 v108; // x20
  _WORD *v109; // x24
  __int64 v110; // x21
  _QWORD *v111; // x19
  unsigned int v112; // w23
  _QWORD *v113; // x26
  __int64 v114; // x8
  _DWORD *v115; // x8
  __int64 v116; // x1
  unsigned int v117; // w0
  __int64 v118; // x20
  unsigned int v119; // w19
  _QWORD *v120; // x19
  _QWORD *v121; // x21
  __int64 v122; // [xsp+0h] [xbp-B0h]
  _QWORD v123[2]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v124; // [xsp+18h] [xbp-98h]
  _QWORD *v125; // [xsp+20h] [xbp-90h] BYREF
  _QWORD *v126; // [xsp+28h] [xbp-88h] BYREF
  unsigned __int16 *v127; // [xsp+30h] [xbp-80h]
  __int64 v128; // [xsp+38h] [xbp-78h]
  __int64 v129; // [xsp+40h] [xbp-70h]
  __int64 v130; // [xsp+48h] [xbp-68h]
  __int64 v131; // [xsp+50h] [xbp-60h]
  __int64 v132; // [xsp+58h] [xbp-58h]
  __int64 v133; // [xsp+60h] [xbp-50h]
  __int64 v134; // [xsp+68h] [xbp-48h]
  __int64 v135; // [xsp+70h] [xbp-40h]
  __int64 v136; // [xsp+78h] [xbp-38h]
  __int64 v137; // [xsp+80h] [xbp-30h]
  __int64 v138; // [xsp+88h] [xbp-28h]
  __int64 v139; // [xsp+90h] [xbp-20h]
  __int64 v140; // [xsp+98h] [xbp-18h]
  __int64 v141; // [xsp+A0h] [xbp-10h]

  v141 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"hdd_tx_latency_get", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    v27 = -22;
    goto LABEL_96;
  }
  v23 = context;
  v24 = a2 + 52832;
  v123[0] = v123;
  v123[1] = v123;
  v124 = 0;
  v122 = a1;
  if ( !a3 )
  {
    v28 = *(_DWORD *)(a2 + 40);
    v27 = -524;
    if ( v28 > 1 )
    {
      if ( v28 != 2 )
      {
        if ( v28 != 3 )
          goto LABEL_92;
        goto LABEL_23;
      }
    }
    else if ( v28 )
    {
      if ( v28 != 1 )
        goto LABEL_92;
LABEL_23:
      v125 = nullptr;
      v126 = nullptr;
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
      hdd_get_front_sta_info_no_lock((_QWORD *)(a2 + 38848), &v126);
      v54 = v126;
      if ( v126 )
      {
        hdd_take_sta_info_ref(a2 + 38848, (__int64)v126, 0, 0x16u, v46, v47, v48, v49, v50, v51, v52, v53);
        v54 = v126;
      }
      hdd_get_next_sta_info_no_lock((_QWORD *)(a2 + 38848), v54, &v125);
      if ( v125 )
        hdd_take_sta_info_ref(a2 + 38848, (__int64)v125, 0, 0x16u, v55, v56, v57, v58, v59, v60, v61, v62);
      v63 = *(_QWORD *)(a2 + 38880);
      if ( (v63 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 38880) = v63 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 38872);
        v64 = (unsigned __int8 *)v126;
        if ( !v126 )
          goto LABEL_90;
      }
      else
      {
        raw_spin_unlock(a2 + 38872);
        v64 = (unsigned __int8 *)v126;
        if ( !v126 )
          goto LABEL_90;
      }
      v65 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v66 = v64 + 32;
        if ( v64[32] != 255 || v64[33] != 255 || v64[34] != 255 || v64[35] != 255 || v64[36] != 255 || v64[37] != 255 )
        {
          v67 = *(_BYTE *)(*(_QWORD *)v24 + 8LL);
          v68 = _qdf_mem_malloc(0x18u, "hdd_tx_latency_link_list_add", 12040);
          if ( !v68 )
          {
            hdd_put_sta_info_ref(a2 + 38848, (__int64 *)&v126, 1, 0x16u, v69, v70, v71, v72, v73, v74, v75, v76);
            v91 = (_QWORD *)v123[0];
            if ( (_QWORD *)v123[0] == v123 )
            {
              v27 = -12;
            }
            else
            {
              do
              {
                v92 = (_QWORD *)*v91;
                qdf_list_remove_node((__int64)v123, v91);
                _qdf_mem_free((__int64)v91);
                v91 = v92;
              }
              while ( v92 != v123 );
              v27 = -12;
            }
            goto LABEL_92;
          }
          v77 = v68;
          qdf_mem_copy((void *)(v68 + 17), v66, 6u);
          *(_BYTE *)(v77 + 16) = v67;
          qdf_list_insert_back(v123, (_QWORD *)v77);
        }
        hdd_put_sta_info_ref(a2 + 38848, (__int64 *)&v126, 1, 0x16u, v15, v16, v17, v18, v19, v20, v21, v22);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v65 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v65 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a2 + 38872);
        }
        else
        {
          raw_spin_lock_bh(a2 + 38872);
          *(_QWORD *)(a2 + 38880) |= 1uLL;
        }
        v126 = v125;
        hdd_get_next_sta_info_no_lock((_QWORD *)(a2 + 38848), v125, &v125);
        if ( v125 )
          hdd_take_sta_info_ref(a2 + 38848, (__int64)v125, 0, 0x16u, v78, v79, v80, v81, v82, v83, v84, v85);
        v86 = *(_QWORD *)(a2 + 38880);
        if ( (v86 & 1) != 0 )
        {
          *(_QWORD *)(a2 + 38880) = v86 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a2 + 38872);
        }
        else
        {
          raw_spin_unlock(a2 + 38872);
        }
        v64 = (unsigned __int8 *)v126;
        if ( !v126 )
          goto LABEL_90;
      }
    }
    if ( a2 )
    {
      if ( (*(_QWORD *)(a2 + 1640) & 1) != 0 )
      {
        v87 = a2 + 52840;
        goto LABEL_76;
      }
      if ( (v87 = a2 + 58928, a2 != -58928) && (*(_QWORD *)(a2 + 1640) & 2) != 0
        || (v87 = a2 + 65016, a2 != -65016) && (*(_QWORD *)(a2 + 1640) & 4) != 0 )
      {
        while ( 1 )
        {
LABEL_76:
          if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                                *(_BYTE *)(v87 + 8),
                                (__int64)"hdd_tx_latency_get_links_for_sta",
                                v15,
                                v16,
                                v17,
                                v18,
                                v19,
                                v20,
                                v21,
                                v22)
            && hdd_cm_is_vdev_associated((_DWORD *)v87) )
          {
            v93 = v23;
            v94 = *(_BYTE *)(v87 + 8);
            v95 = _qdf_mem_malloc(0x18u, "hdd_tx_latency_link_list_add", 12040);
            if ( !v95 )
            {
              v100 = (_QWORD *)v123[0];
              v27 = -12;
              if ( (_QWORD *)v123[0] != v123 )
              {
                do
                {
                  v101 = (_QWORD *)*v100;
                  qdf_list_remove_node((__int64)v123, v100);
                  _qdf_mem_free((__int64)v100);
                  v100 = v101;
                }
                while ( v101 != v123 );
              }
              goto LABEL_92;
            }
            v96 = v95;
            qdf_mem_copy((void *)(v95 + 17), (const void *)(v87 + 308), 6u);
            *(_BYTE *)(v96 + 16) = v94;
            qdf_list_insert_back(v123, (_QWORD *)v96);
            v23 = v93;
          }
          if ( (unsigned __int8)(73 * ((unsigned int)(v87 - *(_DWORD *)v87 - 52840) >> 3) + 1) <= 2u )
          {
            v97 = (unsigned __int8)(73 * ((unsigned int)(v87 - *(_DWORD *)v87 - 52840) >> 3) + 1);
            v87 = 0;
            v98 = a2 + 52840 + 6088LL * (unsigned int)v97;
            do
            {
              if ( v87 )
                break;
              v99 = *(_QWORD *)(a2 + 1640) >> v97++;
              v87 = (v99 << 63 >> 63) & v98;
              v98 += 6088;
            }
            while ( v97 != 3 );
            if ( v87 )
              continue;
          }
          goto LABEL_97;
        }
      }
    }
    goto LABEL_97;
  }
  v25 = *(_DWORD *)(a2 + 40);
  v127 = nullptr;
  v128 = 0;
  v126 = nullptr;
  if ( v25 )
    v26 = *(_BYTE *)(*(_QWORD *)v24 + 8LL);
  else
    v26 = -1;
  v29 = (unsigned __int16)(*a3 - 4);
  if ( (unsigned int)v29 >= 4 )
  {
    v30 = a3 + 2;
    while ( 1 )
    {
      v31 = *v30;
      v27 = 0;
      if ( v31 < 4 || v29 < v31 )
        goto LABEL_91;
      v32 = _nla_parse(&v126, 2, v30 + 2, (unsigned __int16)(v31 - 4), &tx_latency_link_policy, 31, 0);
      if ( v32 )
        break;
      v41 = v127;
      if ( !v127 )
      {
        v88 = "%s: Missing link mac remote attribute";
        goto LABEL_64;
      }
      if ( (unsigned int)*v127 - 4 <= 5 )
      {
        v88 = "%s: Attribute link mac remote is invalid";
LABEL_64:
        qdf_trace_msg(
          0x33u,
          2u,
          v88,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "hdd_tx_latency_get_links_from_attr",
          v122);
LABEL_65:
        v27 = -22;
LABEL_67:
        v89 = (_QWORD *)v123[0];
        if ( (_QWORD *)v123[0] == v123 )
          goto LABEL_91;
        do
        {
          v90 = (_QWORD *)*v89;
          qdf_list_remove_node((__int64)v123, v89);
          _qdf_mem_free((__int64)v89);
          v89 = v90;
        }
        while ( v90 != v123 );
        goto LABEL_92;
      }
      v42 = _qdf_mem_malloc(0x18u, "hdd_tx_latency_link_list_add", 12040);
      if ( !v42 )
      {
        v27 = -12;
        goto LABEL_67;
      }
      v43 = v42;
      qdf_mem_copy((void *)(v42 + 17), v41 + 2, 6u);
      *(_BYTE *)(v43 + 16) = v26;
      qdf_list_insert_back(v123, (_QWORD *)v43);
      v44 = (*v30 + 3) & 0x1FFFC;
      v29 -= v44;
      v30 = (unsigned __int16 *)((char *)v30 + v44);
      if ( v29 <= 3 )
        goto LABEL_90;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Attribute parse failed, ret %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "hdd_tx_latency_get_links_from_attr",
      v32,
      v122);
    goto LABEL_65;
  }
LABEL_90:
  v27 = 0;
LABEL_91:
  if ( v27 )
  {
LABEL_92:
    if ( !(_DWORD)v124 )
      goto LABEL_94;
    goto LABEL_93;
  }
LABEL_97:
  if ( !(_DWORD)v124 )
  {
    v118 = jiffies;
    if ( hdd_tx_latency_get___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x33u, 2u, "%s: no valid peers", v15, v16, v17, v18, v19, v20, v21, v22, "hdd_tx_latency_get");
      hdd_tx_latency_get___last_ticks = v118;
    }
    v27 = -22;
    if ( !(_DWORD)v124 )
      goto LABEL_94;
    goto LABEL_93;
  }
  v104 = _cfg80211_alloc_reply_skb(v122, 103, 197, ((212 * (_DWORD)v124 + 7) & 0xFFFFFFFC) + 16);
  if ( !v104 )
  {
    v27 = -12;
    if ( !(_DWORD)v124 )
      goto LABEL_94;
LABEL_93:
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
      "qdf_list_destroy",
      v122);
    goto LABEL_94;
  }
  v105 = v23;
  v106 = *(_QWORD *)(v104 + 216);
  v107 = *(unsigned int *)(v104 + 208);
  v108 = v104;
  v139 = 0;
  v140 = 0;
  v137 = 0;
  v138 = 0;
  v135 = 0;
  v136 = 0;
  v133 = 0;
  v134 = 0;
  v131 = 0;
  v132 = 0;
  v129 = 0;
  v130 = 0;
  v127 = nullptr;
  v128 = 0;
  v126 = nullptr;
  v27 = -12;
  if ( (nla_put(v104, 32773, 0, 0) & 0x80000000) != 0 || (v109 = (_WORD *)(v106 + v107)) == nullptr )
  {
LABEL_121:
    sk_skb_reason_drop(0, v108, 2);
    v120 = (_QWORD *)v123[0];
    if ( (_QWORD *)v123[0] != v123 )
    {
      do
      {
        v121 = (_QWORD *)*v120;
        qdf_list_remove_node((__int64)v123, v120);
        _qdf_mem_free((__int64)v120);
        v120 = v121;
      }
      while ( v121 != v123 );
    }
    goto LABEL_92;
  }
  v110 = v123[0];
  if ( (_QWORD *)v123[0] == v123 )
  {
LABEL_111:
    *v109 = *(_WORD *)(v108 + 216) + *(_DWORD *)(v108 + 208) - (_WORD)v109;
  }
  else
  {
    v111 = v105;
    v112 = 0;
    while ( 1 )
    {
      v113 = *(_QWORD **)v110;
      qdf_list_remove_node((__int64)v123, (_QWORD *)v110);
      if ( !*v111 || (v114 = *(_QWORD *)(*v111 + 32LL)) == 0 || (v115 = *(_DWORD **)(v114 + 360)) == nullptr )
      {
        v119 = 16;
        goto LABEL_120;
      }
      v116 = *(unsigned __int8 *)(v110 + 16);
      if ( *(v115 - 1) != 929617773 )
        __break(0x8228u);
      v117 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD **))v115)(v111, v116, v110 + 17, &v126);
      if ( v117 )
        break;
      v27 = hdd_tx_latency_fill_link_stats(v108, &v126, v112);
      _qdf_mem_free(v110);
      if ( v27 )
        goto LABEL_121;
      ++v112;
      v110 = (__int64)v113;
      if ( v113 == v123 )
        goto LABEL_111;
    }
    v119 = v117;
LABEL_120:
    _qdf_mem_free(v110);
    v27 = qdf_status_to_os_return(v119);
    if ( v27 )
      goto LABEL_121;
  }
  v27 = cfg80211_vendor_cmd_reply(v108);
  if ( (_DWORD)v124 )
    goto LABEL_93;
LABEL_94:
  v102 = jiffies;
  if ( hdd_tx_latency_get___last_ticks_423 - jiffies + 125 < 0 )
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
      v27);
    hdd_tx_latency_get___last_ticks_423 = v102;
  }
LABEL_96:
  _ReadStatusReg(SP_EL0);
  return v27;
}
