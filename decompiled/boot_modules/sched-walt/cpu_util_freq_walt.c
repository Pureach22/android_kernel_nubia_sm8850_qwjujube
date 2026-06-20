unsigned __int64 __fastcall cpu_util_freq_walt(unsigned int a1, unsigned __int64 *a2, __int64 a3)
{
  unsigned int v3; // w25
  __int64 v4; // x23
  __int64 v6; // x22
  unsigned __int64 *v7; // x8
  unsigned __int64 v8; // x28
  unsigned __int64 v9; // x24
  char v10; // w8
  unsigned __int64 v11; // x22
  unsigned __int64 v12; // x23
  unsigned __int64 v13; // x27
  unsigned __int64 v14; // x26
  unsigned __int64 v15; // x25
  unsigned __int64 v16; // x28
  unsigned __int64 v17; // x0
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x24
  unsigned __int64 v20; // x0
  __int64 v21; // x19
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x13
  __int64 v26; // x12
  __int64 v27; // x8
  char *v28; // x15
  unsigned __int64 v29; // x14
  unsigned __int64 v30; // x11
  char *v31; // x16
  __int64 v32; // x8
  __int64 v33; // x10
  char *v34; // x14
  char *v35; // x11
  __int64 v36; // x4
  __int64 v37; // x8
  unsigned __int64 v38; // x8
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x10
  int v42; // w8
  char v43; // w9
  unsigned __int64 v44; // x9
  unsigned __int64 v45; // x23
  unsigned __int64 v46; // x0
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x9
  char v50; // [xsp+0h] [xbp-80h]
  unsigned __int64 v51; // [xsp+8h] [xbp-78h]
  unsigned int v52; // [xsp+14h] [xbp-6Ch]
  unsigned __int64 v54; // [xsp+28h] [xbp-58h] BYREF
  unsigned __int64 v55; // [xsp+30h] [xbp-50h]
  __int64 v56; // [xsp+38h] [xbp-48h]
  __int64 v57; // [xsp+40h] [xbp-40h]
  __int64 v58; // [xsp+48h] [xbp-38h]
  unsigned __int64 v59; // [xsp+50h] [xbp-30h] BYREF
  unsigned __int64 v60; // [xsp+58h] [xbp-28h]
  __int64 v61; // [xsp+60h] [xbp-20h]
  __int64 v62; // [xsp+68h] [xbp-18h]
  __int64 v63; // [xsp+70h] [xbp-10h]
  __int64 v64; // [xsp+78h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v59 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v54 = 0;
  if ( a1 >= 0x20 )
    goto LABEL_82;
  v3 = a1;
  v4 = a1;
  v6 = *(_QWORD *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + a1) + 8);
  if ( (((__int64 (__fastcall *)(__int64))cluster_in_smart_lrpb)(v6) & 1) != 0 )
    v7 = (unsigned __int64 *)(v6 + 56);
  else
    v7 = (unsigned __int64 *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v4) + 632);
  v8 = *v7;
  v9 = _cpu_util_freq_walt(v3, a2, a3, 1);
  if ( (enable_load_sync(v3) & 1) == 0 )
  {
    v14 = 0;
    v13 = 0;
    v21 = 1LL << v4;
    v11 = 0;
    goto LABEL_57;
  }
  v50 = v4;
  v51 = v8;
  v10 = 0;
  v11 = 0;
  v52 = v3;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  do
  {
    v18 = (unsigned int)(-1LL << v10) & (unsigned int)pipeline_sync_cpus;
    if ( !(_DWORD)v18 )
      break;
    v19 = __clz(__rbit64(v18));
    if ( ((*(_QWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1)) >> v19) & 1) != 0 )
    {
      v20 = _cpu_util_freq_walt((unsigned int)v19, &v54, a3, 0);
      if ( v12 <= v20 )
        v12 = v20;
      if ( v15 <= v54 )
        v15 = v54;
      if ( v16 <= v55 )
        v16 = v55;
    }
    else
    {
      v17 = _cpu_util_freq_walt((unsigned int)v19, &v59, a3, 0);
      if ( v11 <= v17 )
        v11 = v17;
      if ( v13 <= v59 )
        v13 = v59;
      if ( v14 <= v60 )
        v14 = v60;
    }
    v10 = v19 + 1;
  }
  while ( v19 < 0x1F );
  v22 = num_sched_clusters - 2;
  if ( (unsigned int)sched_ravg_window < 0xF42400 )
  {
    if ( (unsigned int)v22 <= 3 )
    {
      v23 = (unsigned int)(num_sched_clusters - 1);
      if ( (unsigned int)v23 < 4 )
      {
        v24 = 16 * v22;
        v25 = 16LL * (unsigned int)(num_sched_clusters - 1);
        v26 = 4LL * (unsigned int)(num_sched_clusters - 1);
        v27 = 4 * v22;
        v28 = (char *)&load_sync_low_pct;
        v29 = *(unsigned int *)((char *)&load_sync_util_thres + v24 + v26);
        v30 = *(unsigned int *)((char *)&load_sync_util_thres + v25 + v27);
        v31 = (char *)&load_sync_high_pct;
        goto LABEL_31;
      }
    }
LABEL_82:
    __break(0x5512u);
  }
  if ( (unsigned int)v22 >= 4 )
    goto LABEL_82;
  v23 = (unsigned int)(num_sched_clusters - 1);
  if ( (unsigned int)v23 >= 4 )
    goto LABEL_82;
  v24 = 16 * v22;
  v25 = 16LL * (unsigned int)(num_sched_clusters - 1);
  v26 = 4LL * (unsigned int)(num_sched_clusters - 1);
  v27 = 4 * v22;
  v28 = (char *)&load_sync_low_pct_60fps;
  v29 = *(unsigned int *)((char *)&load_sync_util_thres_60fps + v24 + v26);
  v30 = *(unsigned int *)((char *)&load_sync_util_thres_60fps + v25 + v27);
  v31 = (char *)&load_sync_high_pct_60fps;
LABEL_31:
  v32 = v25 + v27;
  v33 = v24 + v26;
  if ( v11 <= v29 )
    v34 = v28;
  else
    v34 = v31;
  if ( v12 <= v30 )
    v35 = v28;
  else
    v35 = v31;
  v36 = *(int *)&v34[v33];
  v37 = *(int *)&v35[v32];
  v21 = 1LL << v50;
  if ( (*(_QWORD *)(*(_QWORD *)cpu_array + 8 * v23) & (1LL << v50)) != 0 )
  {
    if ( v12 <= v11 / 0x64 * v36 + v11 % 0x64 * v36 / 0x64 )
      v9 = v11 / 0x64 * v36 + v11 % 0x64 * v36 / 0x64;
    else
      v9 = v12;
    if ( v15 <= v13 / 0x64 * v36 + v13 % 0x64 * v36 / 0x64 )
      v38 = v13 / 0x64 * v36 + v13 % 0x64 * v36 / 0x64;
    else
      v38 = v15;
    v39 = v14 / 0x64 * v36 + v14 % 0x64 * v36 / 0x64;
    if ( v16 > v39 )
      v39 = v16;
    *a2 = v38;
    a2[1] = v39;
  }
  else
  {
    if ( v11 <= v12 / 0x64 * v37 + v12 % 0x64 * v37 / 0x64 )
      v9 = v12 / 0x64 * v37 + v12 % 0x64 * v37 / 0x64;
    else
      v9 = v11;
    if ( v13 <= v15 / 0x64 * v37 + v15 % 0x64 * v37 / 0x64 )
      v40 = v15 / 0x64 * v37 + v15 % 0x64 * v37 / 0x64;
    else
      v40 = v13;
    v41 = v16 / 0x64 * v37 + v16 % 0x64 * v37 / 0x64;
    if ( v14 > v41 )
      v41 = v14;
    *a2 = v40;
    a2[1] = v41;
  }
  v3 = v52;
  v8 = v51;
LABEL_57:
  if ( (asym_cap_sibling_cpus & v21) != 0
    && (!(unsigned int)_sw_hweight64((unsigned int)part_haltable_cpus)
     || (~((unsigned int)_cpu_halt_mask | (unsigned int)_cpu_partial_halt_mask) & (unsigned int)part_haltable_cpus) != 0) )
  {
    v42 = asym_cap_sibling_cpus;
    v43 = 0;
    do
    {
      v44 = (unsigned int)(-1LL << v43) & v42;
      if ( !(_DWORD)v44 )
        break;
      v45 = __clz(__rbit64(v44));
      if ( (_DWORD)v45 != v3 )
      {
        v46 = _cpu_util_freq_walt((unsigned int)v45, &v59, a3, 0);
        if ( v11 <= v46 )
          v11 = v46;
        if ( v13 <= v59 )
          v13 = v59;
        v42 = asym_cap_sibling_cpus;
        if ( v14 <= v60 )
          v14 = v60;
      }
      v43 = v45 + 1;
    }
    while ( v45 < 0x1F );
    v47 = *a2;
    v48 = a2[1];
    if ( v9 <= v11 )
      v9 = v11;
    if ( v47 <= v13 )
      v47 = v13;
    if ( v48 <= v14 )
      v48 = v14;
    *a2 = v47;
    a2[1] = v48;
  }
  _ReadStatusReg(SP_EL0);
  if ( v9 >= v8 )
    return v8;
  else
    return v9;
}
