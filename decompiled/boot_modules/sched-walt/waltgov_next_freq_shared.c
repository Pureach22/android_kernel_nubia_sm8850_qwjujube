__int64 __usercall waltgov_next_freq_shared@<X0>(
        __int64 result@<X0>,
        __int64 a2@<X1>,
        unsigned int a3@<W6>,
        char a4@<W7>,
        __int64 *a5@<X8>)
{
  __int64 *v5; // x10
  unsigned __int64 v6; // x11
  char *v7; // x19
  unsigned __int64 v8; // x21
  unsigned __int64 v9; // x24
  unsigned __int64 v10; // x25
  _QWORD *v11; // x26
  char *v12; // x27
  __int64 v13; // x28
  unsigned __int64 v14; // x9
  char v15; // w8
  char *v16; // x12
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x20
  __int64 v19; // x26
  int v20; // w22
  int v21; // w14
  unsigned __int64 v22; // x28
  char *v23; // x23
  char *v24; // x24
  unsigned __int64 v25; // x19
  int v26; // w21
  _BOOL4 v27; // w28
  __int64 v28; // x9
  char *v29; // x22
  bool v30; // zf
  bool v31; // cc
  int v32; // w8
  __int64 v33; // x9
  int v34; // w8
  __int64 v35; // x9
  __int64 v36; // x20
  char *v37; // x22
  char v38; // w0
  char *v39; // x16
  char v40; // w8
  char *v41; // x12
  __int64 v42; // x9
  unsigned __int64 v43; // x12
  unsigned __int64 v44; // x12
  char *v45; // x13
  bool v46; // cf
  char *v47; // x12
  __int64 v48; // x13
  unsigned __int64 v49; // x23
  __int64 v50; // x20
  char *v51; // x19
  unsigned int v52; // w9
  int v53; // w8
  unsigned __int64 v54; // x9
  __int64 v55; // x8
  unsigned int v56; // w9
  int v57; // w8
  unsigned int v58; // w8
  __int64 v59; // x9
  _DWORD *v60; // x8
  char v61; // w10
  unsigned __int64 v62; // x10
  unsigned __int64 v63; // x10
  __int64 v64; // x11
  char *v65; // x11
  unsigned __int64 StatusReg; // x20
  unsigned int v67; // w22
  __int64 v68; // x8
  __int64 v70; // [xsp+30h] [xbp-40h]
  unsigned __int64 v71; // [xsp+38h] [xbp-38h]
  __int64 v72; // [xsp+40h] [xbp-30h]
  unsigned __int64 v73; // [xsp+48h] [xbp-28h]
  int v74; // [xsp+54h] [xbp-1Ch]
  __int64 v75; // [xsp+58h] [xbp-18h]
  _DWORD *v76; // [xsp+60h] [xbp-10h]
  __int64 v77; // [xsp+60h] [xbp-10h]
  unsigned __int64 v78; // [xsp+68h] [xbp-8h]

  v14 = *(unsigned int *)(result + 16);
  if ( (unsigned int)v14 >= 0x20 )
    goto LABEL_155;
  v13 = *(_QWORD *)(result + 8);
  v12 = (char *)&_per_cpu_offset;
  v6 = (unsigned __int64)&cpu_scale;
  v15 = 0;
  v8 = 0;
  v11 = &waltgov_cpu;
  v73 = *(_QWORD *)((char *)&cpu_scale + *((_QWORD *)&_per_cpu_offset + v14));
  v16 = "pu=%d hyst_time=%llu nr_run=%lu cpu_util=%lu busy_hyst_time=%llu coloc_hyst_time=%llu util_hyst_time=%llu smart_freq_legacy_reason_hyst_ns=%llu\n";
  v74 = *(_DWORD *)(*(_QWORD *)(v13 + 40) + 220LL);
  LODWORD(v5) = v74 + 100;
  v70 = result;
  v75 = v13;
  v76 = *(_DWORD **)v13;
  v72 = v74 + 100;
  do
  {
    LODWORD(v14) = *v76;
    v17 = (unsigned int)(-1LL << v15) & *v76;
    if ( !(_DWORD)v17 )
      break;
    v7 = (char *)__clz(__rbit64(v17));
    v12 = (char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + (_QWORD)v7);
    v18 = *((_QWORD *)v12 + 8);
    v9 = *((_QWORD *)v12 + 3);
    if ( v74 )
    {
      v6 = (((v9 % 0x64 * v72) >> 2) * (unsigned __int128)0x28F5C28F5C28F5C3uLL) >> 64;
      v18 = v18 / 0x64 * v72 + v18 % 0x64 * v72 / 0x64;
      v9 = v9 / 0x64 * v72 + v9 % 0x64 * v72 / 0x64;
    }
    if ( v18 > v8 )
    {
      v8 = v18;
      *(_DWORD *)(v13 + 200) = (_DWORD)v7;
    }
    v19 = *((_QWORD *)v12 + 1);
    v20 = *((_DWORD *)v12 + 18);
    v10 = *((_QWORD *)v12 + 5);
    if ( sysctl_ed_boost_pct )
      v21 = (unsigned __int8)v12[57];
    else
      v21 = 0;
    v78 = *((_QWORD *)v12 + 4);
    v22 = (unsigned int)walt_scale_demand_divisor;
    if ( v12[56] == 1 )
    {
      if ( ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask
                                 + (((unsigned __int64)*((unsigned int *)v12 + 4) >> 3) & 0x1FFFFFF8)) >> *((_DWORD *)v12 + 4))
          & 1) == 0 )
        goto LABEL_15;
      v23 = v16;
      v71 = v9;
      v24 = v7;
      v25 = v8;
      v26 = v21;
      result = _sw_hweight64(*((unsigned int *)v16 + 950));
      v21 = v26;
      v8 = v25;
      v7 = v24;
      v9 = v71;
      v16 = v23;
      if ( !(_DWORD)result
        || ((unsigned int)~(LODWORD(_cpu_halt_mask[0]) | LODWORD(_cpu_partial_halt_mask[0])) & *((_QWORD *)v23 + 475)) != 0 )
      {
LABEL_15:
        *(_BYTE *)(v19 + 395) = 1;
        v12[80] = 1;
      }
    }
    if ( (v20 & 1) != 0 )
    {
      v28 = *(unsigned int *)(*(_QWORD *)(v19 + 40) + 176LL);
      v6 = v10 / v22;
      v27 = v10 / v22 >= *(_QWORD *)(v19 + 32) / 0x64uLL * v28 + *(_QWORD *)(v19 + 32) % 0x64uLL * v28 / 0x64;
    }
    else
    {
      v27 = 0;
    }
    v5 = _cpu_partial_halt_mask;
    if ( ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask
                               + (((unsigned __int64)*((unsigned int *)v12 + 4) >> 3) & 0x1FFFFFF8)) >> *((_DWORD *)v12 + 4))
        & 1) != 0 )
    {
      LODWORD(v10) = v21;
      v29 = v16;
      result = _sw_hweight64(*((unsigned int *)v16 + 950));
      if ( (_DWORD)result
        && ((unsigned int)~(LODWORD(_cpu_halt_mask[0]) | LODWORD(_cpu_partial_halt_mask[0])) & *((_QWORD *)v29 + 475)) == 0 )
      {
        v27 = 0;
      }
      v16 = v29;
      v21 = v10;
    }
    a5 = (__int64 *)v8;
    if ( *(_QWORD *)(v19 + 32) >= *(_QWORD *)(v19 + 64) )
    {
      a5 = (__int64 *)v8;
      if ( v27 )
      {
        LODWORD(v5) = 75;
        LODWORD(v6) = 5243;
        *(_BYTE *)(v19 + 396) = 1;
        v12[81] = 1;
        v30 = (unsigned __int16)(75 * (v18 % 0x64)) / 0x64u + 75 * (v18 / 0x64) > v9 || v73 == 0;
        v31 = v30 || v8 > v73;
        a5 = (__int64 *)v8;
        if ( !v31 )
        {
          v32 = *((_DWORD *)v12 + 4);
          v33 = *((_QWORD *)v12 + 1);
          LODWORD(v5) = 32;
          *((_DWORD *)v12 + 19) = 32;
          *(_DWORD *)(v33 + 200) = v32;
          a5 = (__int64 *)v73;
        }
      }
    }
    if ( *(_BYTE *)(*(_QWORD *)(v19 + 40) + 216LL) != 1 )
    {
      v13 = v75;
LABEL_38:
      v11 = &waltgov_cpu;
      goto LABEL_39;
    }
    v13 = v75;
    if ( !sysctl_sched_conservative_pl )
    {
      LODWORD(v6) = v78;
      if ( v78 )
      {
        v11 = &waltgov_cpu;
        if ( (unsigned __int64)a5 <= v78 )
        {
          v34 = *((_DWORD *)v12 + 4);
          v35 = *((_QWORD *)v12 + 1);
          LODWORD(v5) = 2;
          *((_DWORD *)v12 + 19) = 2;
          *(_DWORD *)(v35 + 200) = v34;
          a5 = (__int64 *)v78;
        }
        goto LABEL_39;
      }
      goto LABEL_38;
    }
    *(_BYTE *)(v19 + 397) = 1;
    v11 = &waltgov_cpu;
    v12[82] = 1;
LABEL_39:
    if ( v21 )
      *((_DWORD *)v12 + 19) |= 4u;
    v14 = *((unsigned int *)v12 + 4);
    if ( (unsigned int)v14 >= 0x20 )
      goto LABEL_155;
    v12 = (char *)&_per_cpu_offset;
    v5 = *((__int64 **)&_per_cpu_offset + v14);
    v14 = (unsigned __int64)a5;
    v15 = (_BYTE)v7 + 1;
    if ( v8 <= v14 )
      v8 = v14;
  }
  while ( (unsigned __int64)v7 < 0x1F );
  a5 = (__int64 *)*(unsigned int *)(v13 + 200);
  if ( (unsigned int)a5 >= 0x20 )
    goto LABEL_155;
  v9 = *(_QWORD *)v13;
  v36 = *((_QWORD *)&_per_cpu_offset + (_QWORD)a5);
  v7 = v16;
  v37 = (char *)&waltgov_cpu + v36;
  v38 = cpus_halted_by_client((_QWORD *)(*(_QWORD *)v13 + 8LL), 2u);
  v78 = v9;
  if ( (soc_flags & 0x400) == 0 )
    goto LABEL_51;
  if ( (v38 & 1) != 0 )
  {
    LODWORD(v7) = 0;
    if ( (*(_BYTE *)(v13 + 394) & 1) != 0 )
    {
      result = 0;
      goto LABEL_143;
    }
    v54 = *(_QWORD *)v13;
    *(_BYTE *)(v13 + 394) = 1;
    *(_DWORD *)(v54 + 624) = 0;
    result = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)v13 + 384LL) + 8LL);
    v55 = a2;
    *(_DWORD *)(v13 + 192) = result;
    *(_DWORD *)(v13 + 196) = result;
LABEL_142:
    *(_QWORD *)(v13 + 160) = v55;
    goto LABEL_143;
  }
  if ( *(_BYTE *)(v13 + 394) )
    *(_WORD *)(v13 + 393) = 1;
LABEL_51:
  v77 = v36;
  result = ((__int64 (__fastcall *)(unsigned __int64, __int64, unsigned __int64, _QWORD))walt_map_util_freq)(
             v8,
             v13,
             v73,
             *((unsigned int *)v37 + 4));
  LODWORD(v10) = result;
  v39 = v7;
  LODWORD(a5) = result;
  if ( *(_BYTE *)(v13 + 395) == 1 )
  {
    v40 = 0;
    LODWORD(v5) = -1;
    do
    {
      v6 = *(unsigned int *)v9 & (unsigned __int64)(-1LL << v40);
      if ( !v6 )
        break;
      LODWORD(a5) = *(_DWORD *)(*(_QWORD *)(v13 + 40) + 188LL);
      v6 = __clz(__rbit64(v6));
      if ( (unsigned int)a5 > (unsigned int)result )
      {
        v41 = (char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v6);
        if ( v41[80] == 1 )
        {
          v37 = (char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v6);
          *((_DWORD *)v41 + 19) |= 8u;
          goto LABEL_62;
        }
      }
      v40 = v6 + 1;
    }
    while ( v6 < 0x1F );
    LODWORD(a5) = result;
  }
LABEL_62:
  if ( *(_BYTE *)(v13 + 396) == 1 )
  {
    v42 = *(unsigned int *)v9;
    LOBYTE(v6) = 0;
    LODWORD(v5) = -1;
    do
    {
      v6 = -1LL << v6;
      if ( (v42 & v6) == 0 )
        break;
      v43 = __rbit64(v42 & v6);
      LODWORD(v6) = *(_DWORD *)(*(_QWORD *)(v13 + 40) + 180LL);
      v44 = __clz(v43);
      if ( (unsigned int)v6 > (unsigned int)a5 )
      {
        v45 = (char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v44);
        if ( v45[81] == 1 )
        {
          v37 = (char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v44);
          *((_DWORD *)v45 + 19) |= 0x10u;
          LODWORD(a5) = v6;
          break;
        }
      }
      LODWORD(v6) = v44 + 1;
    }
    while ( v44 < 0x1F );
  }
  LODWORD(v14) = *(unsigned __int8 *)(v13 + 397);
  if ( (_DWORD)v14 == 1 )
  {
    v14 = *(unsigned int *)v9;
    LOBYTE(v6) = 0;
    LODWORD(v5) = -1;
    do
    {
      v6 = v14 & (-1LL << v6);
      if ( !v6 )
        break;
      v6 = __clz(__rbit64(v6));
      v47 = (char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v6);
      v48 = *((unsigned int *)v47 + 4);
      if ( (unsigned int)v48 >= 0x20 )
        goto LABEL_155;
      v49 = *((_QWORD *)v47 + 4)
          * (unsigned __int64)*(unsigned int *)(**((_QWORD **)v47 + 1) + 40LL)
          / *(_QWORD *)((char *)&cpu_scale + *((_QWORD *)&_per_cpu_offset + v48));
      if ( (unsigned int)a5 < (unsigned int)v49 && v47[82] == 1 )
      {
        v37 = (char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v6);
        *((_DWORD *)v47 + 19) |= 2u;
        goto LABEL_78;
      }
      v46 = v6 >= 0x1F;
      LODWORD(v6) = v6 + 1;
    }
    while ( !v46 );
  }
  LODWORD(v49) = (_DWORD)a5;
LABEL_78:
  a5 = (__int64 *)*(unsigned int *)(v9 + 28);
  if ( (unsigned int)a5 >= 0x20 )
    goto LABEL_155;
  v7 = walt_rq;
  v50 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (_QWORD)a5) + 8];
  if ( (*(_DWORD *)(v50 + 24) & _cpu_partial_halt_mask[0]) != 0 )
  {
    v51 = v39;
    result = _sw_hweight64(*((unsigned int *)v39 + 950));
    if ( (_DWORD)result )
      LOBYTE(a5) = ((unsigned int)~(LODWORD(_cpu_halt_mask[0]) | LODWORD(_cpu_partial_halt_mask[0]))
                  & *((_QWORD *)v51 + 475)) == 0;
    else
      LOBYTE(a5) = 0;
    v7 = walt_rq;
  }
  else
  {
    LOBYTE(a5) = 0;
  }
  LODWORD(v9) = v49;
  if ( *(_BYTE *)(v70 + 58) != 1 )
    goto LABEL_92;
  v14 = *(unsigned int *)(v50 + 32);
  if ( (unsigned int)v14 > 3 )
    goto LABEL_155;
  LODWORD(v9) = v49;
  v52 = *((_DWORD *)&trailblazer_floor_freq + v14);
  if ( (unsigned int)v49 < v52 )
  {
    LODWORD(v9) = v49;
    if ( (sysctl_walt_features & 1) != 0 )
    {
      LODWORD(v9) = v52;
      *((_DWORD *)v37 + 19) |= 0x8000u;
    }
  }
LABEL_92:
  v5 = *(__int64 **)(v13 + 40);
  LODWORD(v14) = *((_DWORD *)v5 + 50);
  if ( !(_DWORD)v14 )
    LOBYTE(a5) = 1;
  if ( ((unsigned __int8)a5 & 1) == 0 )
  {
    LODWORD(v6) = *((_DWORD *)v5 + 51);
    if ( *((_DWORD *)v5 + 48) > (unsigned int)v6 )
      LODWORD(v6) = *((_DWORD *)v5 + 48);
    if ( (unsigned int)v49 < (unsigned int)v6 )
    {
      v53 = 0x20000;
      LODWORD(v9) = v6;
      goto LABEL_108;
    }
    LODWORD(v6) = *((_DWORD *)v5 + 52);
    if ( *((_DWORD *)v5 + 49) > (unsigned int)v6 )
      LODWORD(v6) = *((_DWORD *)v5 + 49);
    if ( (unsigned int)v49 < (unsigned int)v6 )
    {
      v53 = 1024;
      LODWORD(v9) = v6;
      goto LABEL_108;
    }
    if ( (unsigned int)v14 <= *((_DWORD *)v5 + 53) )
      LODWORD(v14) = *((_DWORD *)v5 + 53);
    if ( (unsigned int)v49 <= (unsigned int)v14 )
    {
      v53 = 2048;
      LODWORD(v9) = v14;
LABEL_108:
      LODWORD(v14) = *((_DWORD *)v37 + 19);
      *((_DWORD *)v37 + 19) = v14 | v53;
    }
  }
  a5 = (__int64 *)*(unsigned int *)(*(_QWORD *)v13 + 28LL);
  if ( (unsigned int)a5 >= 0x20 )
    goto LABEL_155;
  v11 = *(_QWORD **)&walt_rq[*((_QWORD *)&_per_cpu_offset + (_QWORD)a5) + 8];
  result = ((__int64 (__fastcall *)(_QWORD *))cluster_in_smart_lrpb)(v11);
  a5 = &freq_cap;
  if ( (result & 1) != 0 )
  {
    v11 = &waltgov_cpu;
    goto LABEL_120;
  }
  LODWORD(v5) = *(_DWORD *)(v11[60] + 24LL);
  v14 = *((unsigned int *)v11 + 8);
  if ( !(_DWORD)v5 )
  {
    if ( (unsigned int)v14 <= 3 )
    {
      LODWORD(v5) = 4096;
      v11 = &waltgov_cpu;
      v56 = *((_DWORD *)&freq_cap + v14 + 4);
      if ( v56 >= (unsigned int)v9 )
        goto LABEL_120;
      goto LABEL_119;
    }
    goto LABEL_155;
  }
  if ( (unsigned int)v14 > 3 )
    goto LABEL_155;
  LODWORD(v6) = *(_DWORD *)(v13 + 204);
  v11 = &waltgov_cpu;
  v56 = *((_DWORD *)&freq_cap + v14 + 4);
  if ( v56 > (unsigned int)v6 )
  {
    LODWORD(v5) = 4096;
    if ( v56 >= (unsigned int)v9 )
      goto LABEL_120;
LABEL_119:
    LODWORD(v6) = *((_DWORD *)v37 + 19);
    LODWORD(v9) = v56;
    LODWORD(v5) = v6 | (unsigned int)v5;
    *((_DWORD *)v37 + 19) = (_DWORD)v5;
    goto LABEL_120;
  }
  if ( v56 >= (unsigned int)v6 )
    LODWORD(v5) = 266240;
  else
    LODWORD(v5) = 0x40000;
  v56 = *(_DWORD *)(v13 + 204);
  if ( (unsigned int)v6 < (unsigned int)v9 )
    goto LABEL_119;
LABEL_120:
  v14 = *(unsigned int *)(v50 + 32);
  if ( (unsigned int)v14 > 3 )
    goto LABEL_155;
  LODWORD(v5) = *((_DWORD *)&freq_cap + v14 + 8);
  if ( (unsigned int)v9 <= (unsigned int)v5 )
    goto LABEL_124;
  *((_DWORD *)v37 + 19) |= 0x2000u;
  v14 = *(unsigned int *)(v50 + 32);
  if ( (unsigned int)v14 > 3 )
  {
LABEL_155:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v67 = result;
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_waltgov_next_freq(0, v78, v8, v73, v10, v9, a3, a4, (char)a5, v14, (int)v5, v6, result);
      v68 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v68;
      if ( !v68 || (result = v67, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(result);
        result = v67;
      }
    }
    goto LABEL_143;
  }
  LODWORD(v9) = (_DWORD)v5;
LABEL_124:
  if ( (unsigned int)v9 > *((_DWORD *)&freq_cap + v14) )
  {
    LODWORD(v9) = *((_DWORD *)&freq_cap + v14);
    *((_DWORD *)v37 + 19) |= 0x4000u;
  }
  if ( (v37[73] & 4) != 0 && (*(_QWORD *)&walt_rq[v77 + 640] || *(_QWORD *)&walt_rq[v77 + 648] != 1024) )
    *((_DWORD *)v37 + 19) |= 0x80000u;
  v57 = *(_DWORD *)(v13 + 196);
  if ( v57 && (_DWORD)v9 == v57 && *(_BYTE *)(v13 + 393) != 1 )
  {
    LODWORD(v7) = 0;
    result = 0;
  }
  else
  {
    result = cpufreq_driver_resolve_freq(v78, (unsigned int)v9);
    v58 = *(_DWORD *)(v13 + 192);
    if ( v58 == (_DWORD)result )
    {
      result = 0;
      LODWORD(v7) = 1;
    }
    else
    {
      v59 = a2 - *(_QWORD *)(v13 + 160);
      if ( (v58 >= (unsigned int)result || v59 >= *(_QWORD *)(v13 + 176))
        && (v58 <= (unsigned int)result || v59 >= *(_QWORD *)(v13 + 184)) )
      {
        v55 = a2;
        LODWORD(v7) = 1;
        *(_DWORD *)(v13 + 192) = result;
        *(_DWORD *)(v13 + 196) = v9;
        goto LABEL_142;
      }
      result = 0;
      *(_DWORD *)(v13 + 196) = 0;
      LODWORD(v7) = 1;
    }
  }
LABEL_143:
  if ( (_DWORD)v7 )
    *(_BYTE *)(v13 + 393) = 0;
  v60 = *(_DWORD **)v13;
  v61 = 0;
  do
  {
    v62 = (unsigned int)(-1LL << v61) & *v60;
    if ( !(_DWORD)v62 )
      break;
    v63 = __clz(__rbit64(v62));
    v64 = *(_QWORD *)&v12[8 * v63];
    v46 = v63 >= 0x1F;
    v61 = v63 + 1;
    v65 = (char *)v11 + v64;
    *(_DWORD *)(v65 + 79) = 0;
    *((_DWORD *)v65 + 19) = 0;
  }
  while ( !v46 );
  *(_WORD *)(v13 + 395) = 0;
  *(_BYTE *)(v13 + 397) = 0;
  return result;
}
