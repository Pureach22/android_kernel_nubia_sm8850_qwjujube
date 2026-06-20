__int64 __fastcall sta_set_sinfo(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x25
  __int64 v4; // x8
  __int64 v5; // x27
  __int64 v8; // x20
  __int64 v9; // x22
  __int64 v10; // x28
  char v11; // w11
  unsigned __int64 v12; // x11
  unsigned __int64 v13; // x11
  bool v14; // cf
  __int64 v15; // x23
  __int64 (__fastcall *v16)(__int64, __int64, __int64, __int64); // x8
  __int64 v17; // x8
  int seconds; // w0
  __int64 v19; // x10
  __int64 v20; // x9
  char v21; // w13
  unsigned __int64 v22; // x13
  unsigned __int64 v23; // x13
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v27; // x8
  int v28; // w9
  int v29; // w9
  int v30; // w9
  int v31; // w10
  __int16 v32; // w9
  int v33; // w9
  char v34; // w12
  int v35; // w10
  unsigned __int64 v36; // x12
  unsigned __int64 v37; // x12
  __int64 v38; // x14
  __int64 v39; // x8
  __int64 v40; // x9
  __int64 v41; // x8
  int v42; // w9
  unsigned int v43; // w9
  __int64 v44; // x9
  __int64 v45; // x9
  char v46; // w12
  unsigned __int64 v47; // x12
  unsigned __int64 v48; // x12
  unsigned __int64 v49; // x9
  unsigned __int64 v50; // x11
  unsigned int v51; // w10
  __int64 v52; // x12
  __int64 v53; // x9
  __int64 v54; // x9
  __int64 v55; // x9
  __int64 v56; // x10
  __int64 v57; // x9
  char v58; // w12
  int v59; // w10
  unsigned __int64 v60; // x12
  unsigned __int64 v61; // x12
  __int64 v62; // x14
  int v63; // w9
  char v64; // w12
  int v65; // w10
  unsigned __int64 v66; // x12
  unsigned __int64 v67; // x12
  __int64 v68; // x14
  __int64 v69; // x9
  __int64 v70; // x9
  __int64 v71; // x9
  __int64 v72; // x9
  __int64 v73; // x9
  __int64 v74; // x10
  __int64 v75; // x9
  __int64 v76; // x9
  __int64 v77; // x9
  __int64 v78; // x10
  __int64 v79; // x11
  __int64 v80; // x11
  __int64 v81; // x9
  char v82; // w10
  char v83; // w8
  __int16 v84; // w8
  int v85; // w8
  __int64 result; // x0
  __int64 v87; // x8
  char v88; // w9
  unsigned int v89; // w9
  __int64 i; // x23
  __int64 v91; // x21
  __int64 v92; // x28
  int v93; // w8
  __int64 v94; // x9
  char v95; // w11
  __int64 v96; // x10
  unsigned __int64 v97; // x11
  unsigned __int64 v98; // x11
  __int64 v99; // x13
  __int64 v100; // x0
  __int64 v101; // x1
  int *v102; // x0
  __int64 v103; // x9
  __int64 v104; // x1
  __int64 v105; // x8
  unsigned __int64 StatusReg; // [xsp+28h] [xbp-8h]

  v3 = *(_QWORD *)(a1 + 80);
  v4 = *(_QWORD *)(a1 + 1744);
  v5 = a1 + 1752;
  v8 = a1;
  v9 = *(_QWORD *)(v3 + 1616);
  v10 = a1 + 1752;
  if ( v4 )
  {
    v11 = 0;
    v10 = a1 + 1752;
    do
    {
      v12 = _cpu_possible_mask & (unsigned __int64)(-1LL << v11);
      if ( !v12 )
        break;
      v13 = __clz(__rbit64(v12));
      if ( (__int64)(*(_QWORD *)(v10 + 8) - *(_QWORD *)(_per_cpu_offset[v13] + v4 + 8)) < 0 )
        v10 = _per_cpu_offset[v13] + v4;
      v14 = v13 >= 0x1F;
      v11 = v13 + 1;
    }
    while ( !v14 );
  }
  *(_DWORD *)(a2 + 116) = *(_DWORD *)(v9 + 1992);
  if ( *(_DWORD *)(v3 + 4720) == 2 )
    *(_QWORD *)(a2 + 184) = *(unsigned int *)(v3 + 4476);
  if ( v3 )
  {
    v15 = v3;
    if ( *(_DWORD *)(v3 + 4720) == 4 )
      v15 = *(_QWORD *)(v3 + 2032) - 2264LL;
  }
  else
  {
    v15 = 0;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v15 + 1616) + 1471LL) & 1) != 0
    || (*(_DWORD *)(v15 + 1624) & 0x20) != 0
    || (drv_sta_statistics___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(v15 + 1624) & 0x20) == 0 )
      goto LABEL_22;
  }
  else
  {
    v103 = *(_QWORD *)(v15 + 1608);
    drv_sta_statistics___already_done = 1;
    if ( v103 )
      v104 = v103 + 296;
    else
      v104 = v15 + 1640;
    a1 = _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v104);
    __break(0x800u);
    if ( (*(_BYTE *)(v15 + 1624) & 0x20) == 0 )
      goto LABEL_22;
  }
  while ( 1 )
  {
    v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(v9 + 464) + 328LL);
    if ( v16 )
    {
      if ( *((_DWORD *)v16 - 1) != 356076970 )
        __break(0x8228u);
      a1 = v16(v9, v15 + 4720, v8 + 2688, a2);
    }
LABEL_22:
    v17 = *(_QWORD *)a2;
    *(_QWORD *)a2 |= 0x40010038002uLL;
    if ( *(_DWORD *)(v3 + 4720) == 2 )
    {
      *(_DWORD *)(a2 + 136) = *(_DWORD *)(v3 + 4480);
      *(_QWORD *)a2 = v17 | 0x40010078002LL;
    }
    seconds = ktime_get_seconds(a1);
    v19 = v5;
    *(_DWORD *)(a2 + 8) = seconds - *(_DWORD *)(v8 + 448);
    *(_QWORD *)(a2 + 16) = *(_QWORD *)(v8 + 440);
    v20 = *(_QWORD *)(v8 + 1744);
    if ( v20 )
    {
      v21 = 0;
      v19 = v5;
      do
      {
        v22 = _cpu_possible_mask & (unsigned __int64)(-1LL << v21);
        if ( !v22 )
          break;
        v23 = __clz(__rbit64(v22));
        if ( (__int64)(*(_QWORD *)(v19 + 8) - *(_QWORD *)(_per_cpu_offset[v23] + v20 + 8)) < 0 )
          v19 = _per_cpu_offset[v23] + v20;
        v14 = v23 >= 0x1F;
        v21 = v23 + 1;
      }
      while ( !v14 );
    }
    v24 = *(_QWORD *)(v8 + 2304);
    v25 = *(_QWORD *)(v19 + 8);
    if ( v24 - v25 < 0 || v24 == 0 )
      v24 = v25;
    a1 = jiffies_to_msecs(jiffies - v24);
    v27 = *(_QWORD *)a2;
    *(_DWORD *)(a2 + 12) = a1;
    if ( (v27 & 0x1000008) != 0 )
    {
      if ( (v27 & 0x400) != 0 )
        goto LABEL_39;
LABEL_38:
      *(_DWORD *)(a2 + 88) = 0;
      v27 |= 0x400uLL;
      v28 = *(_DWORD *)(v8 + 2328);
      *(_DWORD *)(a2 + 88) = v28;
      v29 = v28 + *(_DWORD *)(v8 + 2336);
      *(_DWORD *)(a2 + 88) = v29;
      v30 = v29 + *(_DWORD *)(v8 + 2344);
      *(_DWORD *)(a2 + 88) = v30;
      v31 = *(_DWORD *)(v8 + 2352);
      *(_QWORD *)a2 = v27;
      *(_DWORD *)(a2 + 88) = v30 + v31;
      goto LABEL_39;
    }
    *(_QWORD *)(a2 + 32) = 0;
    v27 |= 0x1000000uLL;
    v53 = *(_QWORD *)(v8 + 2360);
    *(_QWORD *)(a2 + 32) = v53;
    v54 = v53 + *(_QWORD *)(v8 + 2368);
    *(_QWORD *)(a2 + 32) = v54;
    v55 = v54 + *(_QWORD *)(v8 + 2376);
    *(_QWORD *)(a2 + 32) = v55;
    v56 = *(_QWORD *)(v8 + 2384);
    *(_QWORD *)a2 = v27;
    *(_QWORD *)(a2 + 32) = v55 + v56;
    if ( (v27 & 0x400) == 0 )
      goto LABEL_38;
LABEL_39:
    if ( (v27 & 0x800004) != 0 )
    {
      if ( (v27 & 0x200) != 0 )
        goto LABEL_41;
    }
    else
    {
      v57 = *(_QWORD *)(a2 + 24) + *(_QWORD *)(v8 + 1808);
      *(_QWORD *)(a2 + 24) = v57;
      if ( *(_QWORD *)(v8 + 1744) )
      {
        v58 = 0;
        v59 = _cpu_possible_mask;
        do
        {
          v60 = (unsigned int)(-1LL << v58) & v59;
          if ( !(_DWORD)v60 )
            break;
          v61 = __clz(__rbit64(v60));
          v62 = _per_cpu_offset[v61];
          v14 = v61 >= 0x1F;
          v58 = v61 + 1;
          v57 += *(_QWORD *)(v62 + *(_QWORD *)(v8 + 1744) + 56);
          *(_QWORD *)(a2 + 24) = v57;
        }
        while ( !v14 );
      }
      v27 |= 0x800000uLL;
      *(_QWORD *)a2 = v27;
      if ( (v27 & 0x200) != 0 )
      {
LABEL_41:
        if ( (v27 & 0x800) != 0 )
          goto LABEL_42;
        goto LABEL_101;
      }
    }
    v63 = *(_DWORD *)(v8 + 1752);
    *(_DWORD *)(a2 + 84) = v63;
    if ( *(_QWORD *)(v8 + 1744) )
    {
      v64 = 0;
      v65 = _cpu_possible_mask;
      do
      {
        v66 = (unsigned int)(-1LL << v64) & v65;
        if ( !(_DWORD)v66 )
          break;
        v67 = __clz(__rbit64(v66));
        v68 = _per_cpu_offset[v67];
        v14 = v67 >= 0x1F;
        v64 = v67 + 1;
        v63 += *(_DWORD *)(v68 + *(_QWORD *)(v8 + 1744));
        *(_DWORD *)(a2 + 84) = v63;
      }
      while ( !v14 );
    }
    v27 |= 0x200uLL;
    *(_QWORD *)a2 = v27;
    if ( (v27 & 0x800) != 0 )
    {
LABEL_42:
      if ( (v27 & 0x1000) != 0 )
        goto LABEL_43;
      goto LABEL_102;
    }
LABEL_101:
    v69 = *(_QWORD *)(v8 + 2008);
    v27 |= 0x800uLL;
    *(_QWORD *)a2 = v27;
    *(_DWORD *)(a2 + 92) = v69;
    if ( (v27 & 0x1000) != 0 )
    {
LABEL_43:
      if ( (v27 & 0x100000000LL) != 0 )
        goto LABEL_44;
      goto LABEL_103;
    }
LABEL_102:
    v70 = *(_QWORD *)(v8 + 2000);
    v27 |= 0x1000uLL;
    *(_QWORD *)a2 = v27;
    *(_DWORD *)(a2 + 96) = v70;
    if ( (v27 & 0x100000000LL) != 0 )
    {
LABEL_44:
      if ( (v27 & 0x8000000000LL) != 0 )
        goto LABEL_45;
      goto LABEL_104;
    }
LABEL_103:
    v27 |= 0x100000000uLL;
    v71 = *(_QWORD *)(a2 + 176) + *(_QWORD *)(v8 + 528);
    *(_QWORD *)(a2 + 176) = v71;
    v72 = v71 + *(_QWORD *)(v8 + 568);
    *(_QWORD *)(a2 + 176) = v72;
    v73 = v72 + *(_QWORD *)(v8 + 608);
    *(_QWORD *)(a2 + 176) = v73;
    v74 = *(_QWORD *)(v8 + 648);
    *(_QWORD *)a2 = v27;
    *(_QWORD *)(a2 + 176) = v73 + v74;
    if ( (v27 & 0x8000000000LL) != 0 )
    {
LABEL_45:
      if ( (v27 & 0x10000000000LL) != 0 )
        goto LABEL_47;
LABEL_46:
      v32 = *(_WORD *)(v8 + 688);
      v27 |= 0x10000000000uLL;
      *(_QWORD *)a2 = v27;
      *(_WORD *)(a2 + 210) = v32;
      goto LABEL_47;
    }
LABEL_104:
    v27 |= 0x8000000000uLL;
    v75 = *(_QWORD *)(a2 + 168) + *(_QWORD *)(v8 + 536);
    *(_QWORD *)(a2 + 168) = v75;
    v76 = v75 + *(_QWORD *)(v8 + 576);
    *(_QWORD *)(a2 + 168) = v76;
    v77 = v76 + *(_QWORD *)(v8 + 616);
    *(_QWORD *)(a2 + 168) = v77;
    v78 = *(_QWORD *)(v8 + 656);
    *(_QWORD *)a2 = v27;
    *(_QWORD *)(a2 + 168) = v77 + v78;
    if ( (v27 & 0x10000000000LL) == 0 )
      goto LABEL_46;
LABEL_47:
    v33 = *(_DWORD *)(v8 + 1784);
    *(_DWORD *)(a2 + 100) = v33;
    if ( *(_QWORD *)(v8 + 1744) )
    {
      v34 = 0;
      v35 = _cpu_possible_mask;
      do
      {
        v36 = (unsigned int)(-1LL << v34) & v35;
        if ( !(_DWORD)v36 )
          break;
        v37 = __clz(__rbit64(v36));
        v38 = _per_cpu_offset[v37];
        v14 = v37 >= 0x1F;
        v34 = v37 + 1;
        v33 += *(_DWORD *)(v38 + *(_QWORD *)(v8 + 1744) + 32);
        *(_DWORD *)(a2 + 100) = v33;
      }
      while ( !v14 );
    }
    if ( *(_DWORD *)(v3 + 4720) == 2 && (*(_BYTE *)(v3 + 5872) & 1) == 0 )
    {
      *(_QWORD *)a2 = v27 | 0x60000000;
      a1 = ieee80211_ave_rssi(v3 + 4720);
      *(_BYTE *)(a2 + 192) = a1;
    }
    v39 = *(_QWORD *)(v8 + 72);
    if ( (*(_QWORD *)(v39 + 96) & 0x10) != 0 )
    {
      v41 = *(_QWORD *)a2;
      if ( (*(_QWORD *)a2 & 0x80) != 0 )
        goto LABEL_59;
LABEL_58:
      v42 = *(_DWORD *)(v10 + 40);
      v41 |= 0x80uLL;
      *(_QWORD *)a2 = v41;
      *(_BYTE *)(a2 + 45) = v42;
      goto LABEL_59;
    }
    v40 = *(_QWORD *)(v39 + 96);
    v41 = *(_QWORD *)a2;
    if ( (v40 & 8) == 0 )
      goto LABEL_62;
    if ( (v41 & 0x80) == 0 )
      goto LABEL_58;
LABEL_59:
    if ( !*(_QWORD *)(v8 + 1744) && (v41 & 0x2000) == 0 )
    {
      v43 = *(_DWORD *)(v8 + 1952);
      v41 |= 0x2000uLL;
      *(_QWORD *)a2 = v41;
      *(_BYTE *)(a2 + 46) = -(v43 >> 10);
    }
LABEL_62:
    if ( *(_BYTE *)(v10 + 44) && (v41 & 0x6000000) == 0 )
    {
      v44 = v41 | 0x2000000;
      *(_QWORD *)a2 = v41 | 0x2000000;
      if ( !*(_QWORD *)(v8 + 1744) )
      {
        v44 = v41 | 0x6000000;
        *(_QWORD *)a2 = v41 | 0x6000000;
      }
      *(_BYTE *)(a2 + 47) = *(_BYTE *)(v10 + 44);
      *(_BYTE *)(a2 + 48) = *(_BYTE *)(v10 + 45);
      *(_BYTE *)(a2 + 52) = -(*(_DWORD *)(v8 + 1960) >> 10);
      *(_BYTE *)(a2 + 49) = *(_BYTE *)(v10 + 46);
      *(_BYTE *)(a2 + 53) = -(*(_DWORD *)(v8 + 1968) >> 10);
      *(_BYTE *)(a2 + 50) = *(_BYTE *)(v10 + 47);
      *(_BYTE *)(a2 + 54) = -(*(_DWORD *)(v8 + 1976) >> 10);
      *(_BYTE *)(a2 + 51) = *(_BYTE *)(v10 + 48);
      *(_BYTE *)(a2 + 55) = -(*(_DWORD *)(v8 + 1984) >> 10);
      v41 = v44;
    }
    if ( (v41 & 0x100) == 0
      && !*(_WORD *)(v8 + 2872)
      && (*(char *)(v8 + 2392) & 0x80000000) == 0
      && (*(_WORD *)(v8 + 2393) & 0x1F) != 0 )
    {
      a1 = sta_set_rate_info_tx(v8, (char *)(v8 + 2392), a2 + 56);
      v41 = *(_QWORD *)a2 | 0x100LL;
      *(_QWORD *)a2 = v41;
    }
    if ( (v41 & 0x4000) != 0 || *(_WORD *)(v8 + 2872) )
      goto LABEL_122;
    v45 = *(_QWORD *)(v8 + 1744);
    if ( v45 )
    {
      v46 = 0;
      do
      {
        v47 = _cpu_possible_mask & (unsigned __int64)(-1LL << v46);
        if ( !v47 )
          break;
        v48 = __clz(__rbit64(v47));
        if ( (__int64)(*(_QWORD *)(v5 + 8) - *(_QWORD *)(_per_cpu_offset[v48] + v45 + 8)) < 0 )
          v5 = _per_cpu_offset[v48] + v45;
        v14 = v48 >= 0x1F;
        v46 = v48 + 1;
      }
      while ( !v14 );
    }
    v49 = *(unsigned int *)(v5 + 52);
    if ( !(_DWORD)v49 )
      goto LABEL_122;
    v50 = (v49 >> 14) & 7;
    v51 = ((unsigned int)v49 >> 8) & 0x1F;
    v52 = *(_QWORD *)(v8 + 72);
    *(_BYTE *)(a2 + 76) = BYTE1(v49) & 0x1F;
    if ( v50 > 2 )
    {
      switch ( v50 )
      {
        case 6uLL:
          *(_WORD *)(a2 + 70) = 128;
          *(_BYTE *)(a2 + 74) = v49 & 0xF;
          *(_BYTE *)(a2 + 75) = (unsigned __int8)v49 >> 4;
          *(_BYTE *)(a2 + 81) = ((unsigned int)v49 >> 21) & 3;
          *(_BYTE *)(a2 + 82) = ((unsigned int)v49 >> 17) & 0xF;
          break;
        case 4uLL:
          *(_WORD *)(a2 + 70) = 16;
          *(_BYTE *)(a2 + 74) = v49 & 0xF;
          *(_BYTE *)(a2 + 75) = (unsigned __int8)v49 >> 4;
          *(_BYTE *)(a2 + 77) = ((unsigned int)v49 >> 20) & 3;
          *(_BYTE *)(a2 + 79) = ((unsigned int)v49 >> 17) & 7;
          *(_BYTE *)(a2 + 78) = (v49 & 0x400000) != 0;
          break;
        case 3uLL:
          *(_WORD *)(a2 + 70) = 2;
          *(_BYTE *)(a2 + 74) = v49 & 0xF;
          *(_BYTE *)(a2 + 75) = (unsigned __int8)v49 >> 4;
          if ( (v49 & 0x2000) != 0 )
            *(_WORD *)(a2 + 70) = 6;
          break;
      }
      goto LABEL_121;
    }
    if ( v50 != 1 )
      break;
    v79 = (unsigned __int8)v49 >> 4;
    if ( (unsigned int)v79 < 6 )
    {
      v80 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v52 + 72) + 8 * v79 + 328) + 8LL);
      if ( v80 )
      {
        v81 = v80 + 12 * (v49 & 0xF);
        if ( v51 == 1 )
          v82 = 2;
        else
          v82 = v51 == 2;
        *(_WORD *)(a2 + 72) = ((unsigned int)*(unsigned __int16 *)(v81 + 4) + ~(-1 << v82)) >> v82;
      }
      else
      {
        __break(0x800u);
        v41 = *(_QWORD *)a2;
      }
      goto LABEL_121;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      a1 = _traceiter_drv_sta_statistics(0, v9, v15, v8 + 2688);
      v105 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v105;
      if ( !v105 || !*(_QWORD *)(StatusReg + 16) )
        a1 = preempt_schedule_notrace(a1);
    }
  }
  if ( v50 == 2 )
  {
    *(_BYTE *)(a2 + 74) = v49;
    *(_WORD *)(a2 + 70) = 1;
    if ( (v49 & 0x2000) != 0 )
      *(_WORD *)(a2 + 70) = 5;
  }
LABEL_121:
  *(_QWORD *)a2 = v41 | 0x4000;
LABEL_122:
  if ( (a3 & 1) != 0 && !(unsigned int)cfg80211_sinfo_alloc_tid_stats(a2, 3264) )
  {
    for ( i = 0; ; ++i )
    {
      v91 = *(_QWORD *)(a2 + 200) + 88 * i;
      v92 = *(_QWORD *)(v8 + 72);
      v93 = *(_DWORD *)v91;
      if ( (*(_DWORD *)v91 & 2) != 0 )
      {
        if ( (v93 & 4) == 0 )
          goto LABEL_164;
      }
      else
      {
        v94 = *(_QWORD *)(v91 + 8) + *(_QWORD *)(v8 + 1816 + 8 * i);
        *(_QWORD *)(v91 + 8) = v94;
        if ( *(_QWORD *)(v8 + 1744) )
        {
          v95 = 0;
          v96 = _cpu_possible_mask;
          do
          {
            v97 = v96 & (-1LL << v95);
            if ( !v97 )
              break;
            v98 = __clz(__rbit64(v97));
            v99 = _per_cpu_offset[v98];
            v14 = v98 >= 0x1F;
            v95 = v98 + 1;
            v94 += *(_QWORD *)(v99 + *(_QWORD *)(v8 + 1744) + 8 * i + 64);
            *(_QWORD *)(v91 + 8) = v94;
          }
          while ( !v14 );
        }
        v93 |= 2u;
        *(_DWORD *)v91 = v93;
        if ( (v93 & 4) == 0 )
        {
LABEL_164:
          v93 |= 4u;
          *(_DWORD *)v91 = v93;
          *(_QWORD *)(v91 + 16) = *(_QWORD *)(v8 + 2416 + 8 * i);
          if ( (v93 & 8) != 0 )
            goto LABEL_167;
          goto LABEL_165;
        }
      }
      if ( (v93 & 8) != 0 )
        goto LABEL_167;
LABEL_165:
      if ( (*(_QWORD *)(v92 + 96) & 0x10000) != 0 )
      {
        v93 |= 8u;
        *(_DWORD *)v91 = v93;
        *(_QWORD *)(v91 + 24) = *(_QWORD *)(v8 + 2032 + 8 * i);
      }
LABEL_167:
      if ( (v93 & 0x10) == 0 && (*(_QWORD *)(v92 + 96) & 0x10000) != 0 )
      {
        *(_DWORD *)v91 = v93 | 0x10;
        *(_QWORD *)(v91 + 32) = *(_QWORD *)(v8 + 2168 + 8 * i);
      }
      if ( i == 16 )
        break;
      v100 = raw_spin_lock_bh(v92 + 240);
      _rcu_read_lock(v100, v101);
      *(_DWORD *)v91 |= 0x40u;
      v102 = ieee80211_fill_txq_stats((int *)(v91 + 40), (_DWORD *)(*(_QWORD *)(v8 + 2736 + 8 * i) - 232LL));
      _rcu_read_unlock(v102);
      raw_spin_unlock_bh(v92 + 240);
    }
  }
  *(_BYTE *)(a2 + 104) = 0;
  v83 = *(_BYTE *)(v3 + 4853);
  *(_BYTE *)(a2 + 104) = v83;
  if ( *(_BYTE *)(v3 + 4854) == 1 )
  {
    v83 |= 2u;
    *(_BYTE *)(a2 + 104) = v83;
  }
  if ( *(_BYTE *)(v3 + 4855) == 1 )
    *(_BYTE *)(a2 + 104) = v83 | 4;
  *(_BYTE *)(a2 + 105) = *(_BYTE *)(v3 + 4857);
  v84 = *(_WORD *)(v3 + 4858);
  *(_QWORD *)(a2 + 108) = 254;
  *(_WORD *)(a2 + 106) = v84;
  if ( (*(_QWORD *)(v8 + 216) & 8) != 0 )
  {
    v85 = 2;
    *(_DWORD *)(a2 + 112) = 2;
    if ( (*(_QWORD *)(v8 + 216) & 0x10) == 0 )
      goto LABEL_133;
    goto LABEL_132;
  }
  v85 = 0;
  if ( (*(_QWORD *)(v8 + 216) & 0x10) != 0 )
  {
LABEL_132:
    v85 |= 4u;
    *(_DWORD *)(a2 + 112) = v85;
  }
LABEL_133:
  if ( *(_BYTE *)(v8 + 2698) != 1 )
  {
    if ( (*(_QWORD *)(v8 + 216) & 0x80) == 0 )
      goto LABEL_135;
LABEL_149:
    v85 |= 0x10u;
    *(_DWORD *)(a2 + 112) = v85;
    if ( (*(_QWORD *)(v8 + 216) & 1) != 0 )
      goto LABEL_150;
LABEL_136:
    if ( (*(_QWORD *)(v8 + 216) & 2) == 0 )
      goto LABEL_137;
LABEL_151:
    v85 |= 0x80u;
    *(_DWORD *)(a2 + 112) = v85;
    if ( (*(_QWORD *)(v8 + 216) & 0x800) == 0 )
      goto LABEL_139;
LABEL_138:
    *(_DWORD *)(a2 + 112) = v85 | 0x40;
    goto LABEL_139;
  }
  v85 |= 8u;
  *(_DWORD *)(a2 + 112) = v85;
  if ( (*(_QWORD *)(v8 + 216) & 0x80) != 0 )
    goto LABEL_149;
LABEL_135:
  if ( (*(_QWORD *)(v8 + 216) & 1) == 0 )
    goto LABEL_136;
LABEL_150:
  v85 |= 0x20u;
  *(_DWORD *)(a2 + 112) = v85;
  if ( (*(_QWORD *)(v8 + 216) & 2) != 0 )
    goto LABEL_151;
LABEL_137:
  if ( (*(_QWORD *)(v8 + 216) & 0x800) != 0 )
    goto LABEL_138;
LABEL_139:
  result = sta_get_expected_throughput(v8);
  v87 = *(_QWORD *)a2;
  if ( (_DWORD)result )
  {
    v87 |= 0x8000000uLL;
    *(_DWORD *)(a2 + 164) = result;
    *(_QWORD *)a2 = v87;
  }
  if ( (v87 & 0x400000000LL) == 0 && *(_BYTE *)(v8 + 2313) == 1 )
  {
    v88 = *(_BYTE *)(v8 + 2312);
    v87 |= 0x400000000uLL;
    *(_QWORD *)a2 = v87;
    *(_BYTE *)(a2 + 208) = v88;
  }
  if ( (v87 & 0x800000000LL) == 0 && *(_BYTE *)(v8 + 2313) == 1 )
  {
    v89 = *(_DWORD *)(v8 + 2320);
    *(_QWORD *)a2 = v87 | 0x800000000LL;
    *(_BYTE *)(a2 + 209) = -(v89 >> 10);
  }
  return result;
}
