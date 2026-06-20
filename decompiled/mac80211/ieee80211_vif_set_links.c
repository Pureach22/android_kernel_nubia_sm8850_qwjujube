__int64 __fastcall ieee80211_vif_set_links(unsigned __int16 *inited, unsigned int a2, unsigned int a3)
{
  __int64 v4; // x19
  unsigned int v5; // w20
  unsigned __int16 v6; // w10
  unsigned int v7; // w23
  char v8; // w8
  unsigned __int64 v9; // x21
  __int64 v10; // x25
  _QWORD *v11; // x28
  _QWORD *StatusReg; // x27
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x8
  bool v15; // zf
  __int64 v16; // x10
  char v17; // w8
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x10
  __int64 v24; // x9
  __int64 v25; // x11
  __int64 v26; // x10
  __int64 v27; // x9
  __int64 v28; // x11
  __int64 v29; // x10
  __int64 v30; // x9
  __int64 v31; // x11
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x11
  __int64 v35; // x10
  __int64 v36; // x9
  __int64 v37; // x11
  __int64 v38; // x9
  __int64 v39; // x11
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x12
  char v42; // w8
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x23
  __int64 v45; // x24
  __int64 v46; // x2
  unsigned __int64 v47; // x8
  __int64 v48; // x10
  unsigned __int64 v49; // x11
  __int64 v50; // x12
  __int64 v51; // x9
  __int64 v52; // x10
  __int64 v53; // x8
  __int64 v54; // x9
  __int64 v55; // x10
  __int64 v56; // x8
  __int64 v57; // x10
  __int64 v58; // x8
  __int64 v59; // x10
  __int64 v60; // x8
  __int64 v61; // x10
  __int64 v62; // x8
  __int64 v63; // x9
  __int64 v64; // x10
  __int64 v65; // x8
  __int64 v66; // x10
  __int64 v67; // x8
  __int64 v68; // x10
  __int64 v70; // x23
  __int64 i; // x21
  __int64 v72; // x23
  unsigned int v73; // w0
  unsigned int v74; // [xsp+Ch] [xbp-214h]
  unsigned __int16 v75; // [xsp+10h] [xbp-210h]
  unsigned __int64 v77; // [xsp+18h] [xbp-208h]
  _QWORD *v78[2]; // [xsp+20h] [xbp-200h] BYREF
  __int64 v79; // [xsp+30h] [xbp-1F0h]
  __int64 v80; // [xsp+38h] [xbp-1E8h]
  __int64 v81; // [xsp+40h] [xbp-1E0h]
  __int64 v82; // [xsp+48h] [xbp-1D8h]
  __int64 v83; // [xsp+50h] [xbp-1D0h]
  __int64 v84; // [xsp+58h] [xbp-1C8h]
  __int64 v85; // [xsp+60h] [xbp-1C0h]
  __int64 v86; // [xsp+68h] [xbp-1B8h]
  __int64 v87; // [xsp+70h] [xbp-1B0h]
  __int64 v88; // [xsp+78h] [xbp-1A8h]
  __int64 v89; // [xsp+80h] [xbp-1A0h]
  __int64 v90; // [xsp+88h] [xbp-198h]
  __int64 v91; // [xsp+90h] [xbp-190h]
  __int64 v92; // [xsp+98h] [xbp-188h]
  __int64 v93; // [xsp+A0h] [xbp-180h]
  __int64 v94; // [xsp+A8h] [xbp-178h]
  __int64 v95; // [xsp+B0h] [xbp-170h]
  __int64 v96; // [xsp+B8h] [xbp-168h]
  __int64 v97; // [xsp+C0h] [xbp-160h]
  __int64 v98; // [xsp+C8h] [xbp-158h]
  __int64 v99; // [xsp+D0h] [xbp-150h]
  __int64 v100; // [xsp+D8h] [xbp-148h]
  __int64 v101; // [xsp+E0h] [xbp-140h]
  __int64 v102; // [xsp+E8h] [xbp-138h]
  __int64 v103; // [xsp+F0h] [xbp-130h]
  __int64 v104; // [xsp+F8h] [xbp-128h]
  __int64 v105; // [xsp+100h] [xbp-120h]
  __int64 v106; // [xsp+108h] [xbp-118h]
  __int64 v107; // [xsp+110h] [xbp-110h]
  __int64 v108; // [xsp+118h] [xbp-108h]
  __int64 v109; // [xsp+120h] [xbp-100h]
  __int64 v110; // [xsp+128h] [xbp-F8h]
  __int64 v111; // [xsp+130h] [xbp-F0h]
  __int64 v112; // [xsp+138h] [xbp-E8h]
  __int64 v113; // [xsp+140h] [xbp-E0h]
  __int64 v114; // [xsp+148h] [xbp-D8h]
  __int64 v115; // [xsp+150h] [xbp-D0h]
  __int64 v116; // [xsp+158h] [xbp-C8h]
  __int64 v117; // [xsp+160h] [xbp-C0h]
  __int64 v118; // [xsp+168h] [xbp-B8h]
  __int64 v119; // [xsp+170h] [xbp-B0h]
  __int64 v120; // [xsp+178h] [xbp-A8h]
  __int64 v121; // [xsp+180h] [xbp-A0h]
  __int64 v122; // [xsp+188h] [xbp-98h]
  __int64 v123; // [xsp+190h] [xbp-90h]
  __int64 v124; // [xsp+198h] [xbp-88h]
  __int64 v125; // [xsp+1A0h] [xbp-80h]
  __int64 v126; // [xsp+1A8h] [xbp-78h]
  __int64 v127; // [xsp+1B0h] [xbp-70h]
  __int64 v128; // [xsp+1B8h] [xbp-68h]
  __int64 v129; // [xsp+1C0h] [xbp-60h]
  __int64 v130; // [xsp+1C8h] [xbp-58h]
  __int64 v131; // [xsp+1D0h] [xbp-50h]
  __int64 v132; // [xsp+1D8h] [xbp-48h]
  __int64 v133; // [xsp+1E0h] [xbp-40h]
  __int64 v134; // [xsp+1E8h] [xbp-38h]
  __int64 v135; // [xsp+1F0h] [xbp-30h]
  __int64 v136; // [xsp+1F8h] [xbp-28h]
  __int64 v137; // [xsp+200h] [xbp-20h]
  __int64 v138; // [xsp+208h] [xbp-18h]
  __int64 v139; // [xsp+210h] [xbp-10h]

  v4 = (__int64)inited;
  v139 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = inited[2900];
  v6 = inited[2901];
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
  v127 = 0;
  v128 = 0;
  v125 = 0;
  v126 = 0;
  v123 = 0;
  v124 = 0;
  v121 = 0;
  v122 = 0;
  v119 = 0;
  v120 = 0;
  v117 = 0;
  v118 = 0;
  v115 = 0;
  v116 = 0;
  v113 = 0;
  v114 = 0;
  v111 = 0;
  v112 = 0;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v106 = 0;
  v103 = 0;
  v104 = 0;
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  v89 = 0;
  v90 = 0;
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  if ( v5 == (unsigned __int16)a2 && inited[2902] == (unsigned __int16)a3 )
  {
    v7 = 0;
    goto LABEL_42;
  }
  v75 = v6;
  v8 = 0;
  v9 = -1;
  v10 = (unsigned __int16)a2 & (unsigned __int16)~(_WORD)v5 & 0x7FFF;
  v11 = &ieee80211_vif_update_links__alloc_tag;
  v77 = v5 & ~(unsigned __int16)a2 | (v5 == 0);
  StatusReg = (_QWORD *)_ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v13 = (-1LL << v8) & v10;
    if ( !v13 )
    {
LABEL_12:
      v16 = *(_QWORD *)(v4 + 5784);
      v17 = 0;
      v18 = *(_QWORD *)(v4 + 5792);
      v19 = *(_QWORD *)(v4 + 4568);
      v9 = v4 + 3616;
      v121 = *(_QWORD *)(v4 + 5776);
      v122 = v16;
      v20 = *(_QWORD *)(v4 + 5744);
      v21 = *(_QWORD *)(v4 + 5752);
      v123 = v18;
      v22 = *(_QWORD *)(v4 + 5768);
      v117 = v20;
      v118 = v21;
      v23 = *(_QWORD *)(v4 + 5712);
      v119 = *(_QWORD *)(v4 + 5760);
      v120 = v22;
      v24 = *(_QWORD *)(v4 + 5720);
      v25 = *(_QWORD *)(v4 + 5736);
      v113 = v23;
      v114 = v24;
      v26 = *(_QWORD *)(v4 + 5680);
      v115 = *(_QWORD *)(v4 + 5728);
      v116 = v25;
      v27 = *(_QWORD *)(v4 + 5688);
      v28 = *(_QWORD *)(v4 + 5704);
      v109 = v26;
      v110 = v27;
      v29 = *(_QWORD *)(v4 + 4664);
      v111 = *(_QWORD *)(v4 + 5696);
      v112 = v28;
      v30 = *(_QWORD *)(v4 + 4672);
      v31 = *(_QWORD *)(v4 + 4680);
      v106 = v29;
      v107 = v30;
      v32 = *(_QWORD *)(v4 + 4632);
      v33 = *(_QWORD *)(v4 + 4640);
      v108 = v31;
      v34 = *(_QWORD *)(v4 + 4656);
      v102 = v32;
      v103 = v33;
      v35 = *(_QWORD *)(v4 + 4600);
      v104 = *(_QWORD *)(v4 + 4648);
      v105 = v34;
      v36 = *(_QWORD *)(v4 + 4608);
      v37 = *(_QWORD *)(v4 + 4624);
      v98 = v35;
      v99 = v36;
      StatusReg = (_QWORD *)(v4 + 5680);
      v100 = *(_QWORD *)(v4 + 4616);
      v101 = v37;
      v38 = *(_QWORD *)(v4 + 4576);
      v39 = *(_QWORD *)(v4 + 4592);
      v11 = (_QWORD *)(v4 + 4568);
      v94 = v19;
      v95 = v38;
      v96 = *(_QWORD *)(v4 + 4584);
      v97 = v39;
      do
      {
        v40 = (-1LL << v17) & v77 & 0x7FFF;
        if ( !v40 )
          break;
        v41 = __clz(__rbit64(v40));
        if ( v11[v41] != v9 )
        {
          if ( v41 > 0xE )
            goto LABEL_27;
          *(&v79 + v41) = v11[v41];
        }
        v17 = v41 + 1;
        v11[v41] = 0;
        StatusReg[v41] = 0;
      }
      while ( v41 < 0xE );
      v74 = a3;
      v42 = 0;
      do
      {
        v43 = (-1LL << v42) & v10;
        if ( !v43 )
          break;
        v44 = __clz(__rbit64(v43));
        if ( v5 && v11[v44] == v9 )
        {
          __break(0x800u);
          if ( v44 > 0xE )
            goto LABEL_27;
        }
        else if ( v44 > 0xE )
        {
          goto LABEL_27;
        }
        v45 = *(&v124 + v44);
        inited = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))ieee80211_link_init)(
                                       v4,
                                       (unsigned int)v44,
                                       v45,
                                       v45 + 952);
        if ( *(_DWORD *)(*(_QWORD *)v45 + 4720LL) == 2 )
          inited = (unsigned __int16 *)((__int64 (__fastcall *)(__int64))ieee80211_mgd_setup_link)(v45);
        v42 = v44 + 1;
      }
      while ( v44 != 14 );
LABEL_28:
      if ( !(_WORD)a2 )
      {
        atomic_store(v4 + 4808, (unsigned __int64 *)(v4 + 5680));
        atomic_store(v9, (unsigned __int64 *)(v4 + 4568));
        *(_QWORD *)(v4 + 4560) = v4 + 4808;
        *(_QWORD *)(v4 + 4808) = v4 + 4720;
        *(_QWORD *)(v4 + 3616) = v4;
        *(_DWORD *)(v4 + 3624) = 0;
        *(_DWORD *)(v4 + 4832) = 0;
        *(_QWORD *)(v4 + 3760) = v4 + 3760;
        *(_QWORD *)(v4 + 3768) = v4 + 3760;
        *(_QWORD *)(v4 + 3776) = ieee80211_csa_finalize_work;
        *(_QWORD *)(v4 + 3848) = v4 + 3848;
        *(_QWORD *)(v4 + 3856) = v4 + 3848;
        *(_QWORD *)(v4 + 3864) = ieee80211_color_change_finalize_work;
        *(_QWORD *)(v4 + 3872) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v4 + 3880) = v4 + 3880;
        *(_QWORD *)(v4 + 3888) = v4 + 3880;
        *(_QWORD *)(v4 + 3896) = ieee80211_color_collision_detection_work;
        init_timer_key(v4 + 3904, &delayed_work_timer_fn, 0x200000, 0, 0);
        *(_QWORD *)(v4 + 3632) = v4 + 3632;
        *(_QWORD *)(v4 + 3640) = v4 + 3632;
        *(_QWORD *)(v4 + 3648) = v4 + 3648;
        *(_QWORD *)(v4 + 3656) = v4 + 3648;
        inited = (unsigned __int16 *)init_timer_key(v4 + 4112, &wiphy_delayed_work_timer, 0, 0, 0);
        *(_QWORD *)(v4 + 4080) = v4 + 4080;
        *(_QWORD *)(v4 + 4088) = v4 + 4080;
        *(_QWORD *)(v4 + 4096) = ieee80211_dfs_cac_timer_work;
      }
      v46 = v74;
      v47 = 0;
      while ( 1 )
      {
        if ( v47 <= 0xD )
        {
          v48 = v11[v47];
          if ( v48 )
            break;
        }
LABEL_31:
        if ( ++v47 == 15 )
        {
          v78[0] = v78;
          v78[1] = v78;
          if ( (v77 & 1) != 0 )
          {
            if ( v79 )
              v70 = v79;
            else
              v70 = v9;
            if ( v70 )
            {
              ieee80211_remove_link_keys(v70, (__int64 *)v78);
              inited = (unsigned __int16 *)((__int64 (__fastcall *)(__int64))ieee80211_link_stop)(v70);
            }
            else
            {
              __break(0x800u);
            }
          }
          for ( i = 1; i != 15; ++i )
          {
            if ( ((v77 >> i) & 1) != 0 )
            {
              v72 = *(&v79 + i);
              if ( v72 )
              {
                ieee80211_remove_link_keys(*(&v79 + i), (__int64 *)v78);
                inited = (unsigned __int16 *)((__int64 (__fastcall *)(__int64))ieee80211_link_stop)(v72);
              }
              else
              {
                __break(0x800u);
              }
            }
          }
          synchronize_rcu(inited);
          ieee80211_free_key_list(*(_QWORD *)(v4 + 1616), v78);
          ieee80211_set_vif_links_bitmaps(v4, a2, v74);
          v73 = drv_change_vif_links(
                  *(_QWORD *)(v4 + 1616),
                  v4,
                  v75 & (unsigned __int16)v5,
                  *(_WORD *)(v4 + 5802) & (unsigned __int16)a2);
          v46 = v74;
          v7 = v73;
          if ( !v73 )
          {
            if ( !(_WORD)a2 )
              goto LABEL_41;
            goto LABEL_42;
          }
LABEL_39:
          v51 = v107;
          v52 = v108;
          v11[12] = v106;
          v11[13] = v51;
          v53 = v102;
          v54 = v103;
          v11[14] = v52;
          v11[8] = v53;
          v11[9] = v54;
          v55 = v105;
          v11[10] = v104;
          v11[11] = v55;
          v56 = v99;
          v11[4] = v98;
          v11[5] = v56;
          v57 = v101;
          v11[6] = v100;
          v11[7] = v57;
          v58 = v95;
          *v11 = v94;
          v11[1] = v58;
          v59 = v97;
          v11[2] = v96;
          v11[3] = v59;
          v60 = v122;
          v61 = v123;
          StatusReg[12] = v121;
          StatusReg[13] = v60;
          v62 = v117;
          v63 = v118;
          StatusReg[14] = v61;
          StatusReg[8] = v62;
          StatusReg[9] = v63;
          v64 = v120;
          StatusReg[10] = v119;
          StatusReg[11] = v64;
          v65 = v114;
          StatusReg[4] = v113;
          StatusReg[5] = v65;
          v66 = v116;
          StatusReg[6] = v115;
          StatusReg[7] = v66;
          v67 = v110;
          *StatusReg = v109;
          StatusReg[1] = v67;
          v68 = v112;
          StatusReg[2] = v111;
          StatusReg[3] = v68;
          ieee80211_set_vif_links_bitmaps(v4, v5, v46);
          v92 = 0;
          v93 = 0;
          v90 = 0;
          v91 = 0;
          v88 = 0;
          v89 = 0;
          v86 = 0;
          v87 = 0;
          v84 = 0;
          v85 = 0;
          v82 = 0;
          v83 = 0;
          v80 = 0;
          v81 = 0;
          v79 = 0;
          goto LABEL_40;
        }
      }
      v49 = v47;
      while ( 1 )
      {
        v50 = *(_QWORD *)(v4 + 4576 + 8 * v49);
        if ( v50 )
        {
          if ( !(*(_DWORD *)(*(_QWORD *)(v50 + 944) + 28LL) ^ *(_DWORD *)(*(_QWORD *)(v48 + 944) + 28LL)
               | *(unsigned __int16 *)(*(_QWORD *)(v50 + 944) + 32LL)
               ^ *(unsigned __int16 *)(*(_QWORD *)(v48 + 944) + 32LL)) )
            break;
        }
        if ( ++v49 == 14 )
          goto LABEL_31;
      }
      v7 = -114;
      goto LABEL_39;
    }
    inited = (unsigned __int16 *)_kmalloc_cache_noprof(_cpu_online_mask, 3520, 1824);
    if ( !inited )
      break;
    v14 = __clz(__rbit64(v13));
    if ( v14 > 0xE )
    {
LABEL_27:
      __break(1u);
      goto LABEL_28;
    }
    v15 = v14 == 14;
    *(&v124 + v14) = (__int64)inited;
    v8 = v14 + 1;
    if ( v15 )
      goto LABEL_12;
  }
  v7 = -12;
LABEL_40:
  kfree(v124);
  v124 = 0;
  kfree(v125);
  v125 = 0;
  kfree(v126);
  v126 = 0;
  kfree(v127);
  v127 = 0;
  kfree(v128);
  v128 = 0;
  kfree(v129);
  v129 = 0;
  kfree(v130);
  v130 = 0;
  kfree(v131);
  v131 = 0;
  kfree(v132);
  v132 = 0;
  kfree(v133);
  v133 = 0;
  kfree(v134);
  v134 = 0;
  kfree(v135);
  v135 = 0;
  kfree(v136);
  v136 = 0;
  kfree(v137);
  v137 = 0;
  kfree(v138);
  v138 = 0;
  if ( !v5 )
  {
LABEL_41:
    atomic_store(v4 + 4808, (unsigned __int64 *)(v4 + 5680));
    atomic_store(v4 + 3616, (unsigned __int64 *)(v4 + 4568));
    *(_QWORD *)(v4 + 4560) = v4 + 4808;
    *(_QWORD *)(v4 + 4808) = v4 + 4720;
    *(_QWORD *)(v4 + 3616) = v4;
    *(_DWORD *)(v4 + 3624) = 0;
    *(_DWORD *)(v4 + 4832) = 0;
    *(_QWORD *)(v4 + 3760) = v4 + 3760;
    *(_QWORD *)(v4 + 3768) = v4 + 3760;
    *(_QWORD *)(v4 + 3776) = ieee80211_csa_finalize_work;
    *(_QWORD *)(v4 + 3848) = v4 + 3848;
    *(_QWORD *)(v4 + 3856) = v4 + 3848;
    *(_QWORD *)(v4 + 3864) = ieee80211_color_change_finalize_work;
    *(_QWORD *)(v4 + 3872) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v4 + 3880) = v4 + 3880;
    *(_QWORD *)(v4 + 3888) = v4 + 3880;
    *(_QWORD *)(v4 + 3896) = ieee80211_color_collision_detection_work;
    init_timer_key(v4 + 3904, &delayed_work_timer_fn, 0x200000, 0, 0);
    *(_QWORD *)(v4 + 3632) = v4 + 3632;
    *(_QWORD *)(v4 + 3640) = v4 + 3632;
    *(_QWORD *)(v4 + 3648) = v4 + 3648;
    *(_QWORD *)(v4 + 3656) = v4 + 3648;
    init_timer_key(v4 + 4112, &wiphy_delayed_work_timer, 0, 0, 0);
    *(_QWORD *)(v4 + 4080) = v4 + 4080;
    *(_QWORD *)(v4 + 4088) = v4 + 4080;
    *(_QWORD *)(v4 + 4096) = ieee80211_dfs_cac_timer_work;
  }
LABEL_42:
  kfree(v79);
  kfree(v80);
  kfree(v81);
  kfree(v82);
  kfree(v83);
  kfree(v84);
  kfree(v85);
  kfree(v86);
  kfree(v87);
  kfree(v88);
  kfree(v89);
  kfree(v90);
  kfree(v91);
  kfree(v92);
  kfree(v93);
  _ReadStatusReg(SP_EL0);
  return v7;
}
