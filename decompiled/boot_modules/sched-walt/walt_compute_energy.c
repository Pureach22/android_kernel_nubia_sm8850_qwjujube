__int64 __fastcall walt_compute_energy(__int64 a1, unsigned int a2, _QWORD *a3, _QWORD *a4, __int64 a5, __int64 a6)
{
  char *v8; // x28
  _QWORD *v10; // x21
  __int64 v12; // x1
  __int64 result; // x0
  char *v14; // x3
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  __int64 v17; // x10
  char v18; // w13
  unsigned __int64 v19; // x9
  __int64 v20; // x26
  __int64 v21; // x10
  bool v22; // cf
  unsigned __int64 v23; // x13
  unsigned __int64 v24; // x13
  _BYTE *v25; // x15
  unsigned __int64 v26; // x14
  unsigned __int64 v27; // x17
  __int64 v28; // x16
  unsigned __int64 v29; // x15
  unsigned __int64 v30; // x16
  unsigned __int64 v31; // x10
  int v32; // w11
  int v33; // w8
  unsigned __int64 v34; // x9
  unsigned __int64 v35; // x12
  __int64 v36; // x8
  unsigned __int64 v37; // x13
  __int64 v38; // x0
  __int64 v39; // x11
  __int64 v40; // x9
  __int64 v41; // x8
  unsigned __int64 *v42; // x11
  unsigned __int64 v43; // x10
  __int64 v44; // x12
  unsigned __int64 v45; // x9
  __int64 v46; // x10
  unsigned __int64 v47; // t1
  __int64 v48; // x12
  bool v49; // zf
  unsigned __int64 v50; // x8
  __int64 v51; // [xsp+0h] [xbp-50h]
  __int64 v52; // [xsp+8h] [xbp-48h]
  __int64 v53; // [xsp+18h] [xbp-38h]
  __int64 v54; // [xsp+20h] [xbp-30h]
  char v55; // [xsp+28h] [xbp-28h]
  unsigned __int64 v57; // [xsp+38h] [xbp-18h]
  unsigned int v58; // [xsp+44h] [xbp-Ch]
  __int64 v59; // [xsp+48h] [xbp-8h]

  if ( !a3 )
    return 0;
  if ( (_UNKNOWN *)a1 == &init_task )
    v8 = (char *)&vendor_data_pad;
  else
    v8 = (char *)(a1 + 5184);
  v10 = a3;
  v12 = 0;
  result = 0;
  v14 = v8 + 100;
  v51 = a6 + 32;
  v52 = a6 + 64;
  v53 = a6 + 96;
  while ( 1 )
  {
    v16 = *(unsigned int *)(*v10 + 32LL);
    if ( (v16 & *a4) == 0
      && ((*(_QWORD *)(*v10 + 32LL + (((unsigned __int64)*(unsigned int *)(a1 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(a1 + 40))
        & 1) == 0 )
    {
      goto LABEL_8;
    }
    v17 = *(unsigned int *)(a1 + 40);
    if ( ((unsigned int)v17 | a2) >= 0x20 )
      goto LABEL_70;
    v18 = 0;
    v19 = 0;
    v20 = 0;
    v21 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v17) + 8];
    do
    {
      v23 = _cpu_online_mask & (unsigned int)(-1LL << v18) & (unsigned int)v16;
      if ( !v23 )
        break;
      v24 = __clz(__rbit64(v23));
      v25 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v24)];
      v26 = *((_QWORD *)v25 + 5);
      if ( *(_DWORD *)(a1 + 144) && !*(_BYTE *)(a1 + 273) && *(_DWORD *)(a1 + 40) == (_DWORD)v24 )
      {
        if ( (_DWORD)v24 != a2 )
          v26 = (v26 - *((unsigned __int16 *)v8 + 79)) & ~((__int64)(v26 - *((unsigned __int16 *)v8 + 79)) >> 63);
      }
      else if ( (_DWORD)v24 == a2 )
      {
        v26 += *((unsigned __int16 *)v8 + 79);
      }
      v27 = *((_QWORD *)v25 + 79);
      v28 = *((unsigned int *)v8 + 34);
      v29 = *(_QWORD *)(a5 + 8 * v24);
      if ( v26 >= v27 )
        v26 = v27;
      if ( (_DWORD)v28 )
      {
        if ( v21 != *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + a2) + 8] )
        {
          if ( (unsigned int)v24 >= 8 )
            goto LABEL_70;
          v29 = (v29 - *(unsigned int *)&v14[4 * v24]) & ~((__int64)(v29 - *(unsigned int *)&v14[4 * v24]) >> 63);
          v30 = v29 + v28;
          if ( (_DWORD)v24 == a2 )
            v29 = v30;
        }
      }
      else if ( (_DWORD)v24 == a2 )
      {
        v29 += *((unsigned int *)v8 + 7);
      }
      v20 += v26;
      if ( v19 <= v29 )
        v19 = v29;
      v22 = v24 >= 0x1F;
      v18 = v24 + 1;
    }
    while ( !v22 );
    v31 = (unsigned int)walt_scale_demand_divisor;
    if ( a6 )
    {
      if ( (unsigned int)v12 >= 4 )
        goto LABEL_70;
      v32 = __clz(__rbit64(v16));
      if ( *(_DWORD *)(*v10 + 32LL) )
        v33 = v32;
      else
        v33 = 32;
      *(_DWORD *)(v53 + 4LL * (unsigned int)v12) = v33;
    }
    if ( v20 )
      break;
    v15 = 0;
LABEL_7:
    result += v15;
    v12 = (unsigned int)(v12 + 1);
LABEL_8:
    v10 = (_QWORD *)v10[1];
    if ( !v10 )
      return result;
  }
  if ( !*(_DWORD *)(*v10 + 32LL) )
    goto LABEL_70;
  v34 = v19 / v31;
  v35 = __clz(__rbit64(*(unsigned int *)(*v10 + 32LL)));
  v36 = *((_QWORD *)&_per_cpu_offset + v35);
  if ( (*(_QWORD *)((char *)&arch_freq_scale + v36) * *(_QWORD *)((char *)&cpu_scale + v36)) >> 10 > v34 )
    v34 = (*(_QWORD *)((char *)&arch_freq_scale + v36) * *(_QWORD *)((char *)&cpu_scale + v36)) >> 10;
  if ( v34 >= 0x3FF )
    v37 = 1023;
  else
    v37 = v34;
  if ( (walt_disabled & 1) != 0 )
  {
    v50 = 0;
    if ( !a6 )
      goto LABEL_65;
    goto LABEL_63;
  }
  v59 = result;
  v57 = v37;
  v58 = v12;
  v54 = *(_QWORD *)&walt_rq[v36 + 8];
  v55 = v35;
  v38 = em_cpu_get((unsigned int)v35);
  if ( !v38 )
  {
    result = v59;
    v12 = v58;
    v50 = 0;
    v14 = v8 + 100;
    v37 = v57;
    if ( !a6 )
      goto LABEL_65;
LABEL_63:
    if ( (unsigned int)v12 >= 4 )
      goto LABEL_70;
    *(_QWORD *)(a6 + 8LL * (unsigned int)v12) = v20;
    *(_QWORD *)(v52 + 8LL * (unsigned int)v12) = v50;
    *(_QWORD *)(v51 + 8LL * (unsigned int)v12) = v37;
    goto LABEL_65;
  }
  v39 = *(_QWORD *)v38;
  v40 = *(unsigned int *)(v38 + 8);
  if ( (int)v40 < 1 )
  {
    result = v59;
    v12 = v58;
    LODWORD(v50) = 0;
    v14 = v8 + 100;
    v37 = v57;
LABEL_59:
    v50 = (unsigned int)v50;
    if ( ((*(_QWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1)) >> v55) & 1) != 0
      && v37 > (unsigned int)sysctl_em_inflate_thres )
    {
      v50 = (unsigned int)sysctl_em_inflate_pct * (unsigned __int64)((unsigned int)v50 % 0x64) / 0x64
          + (unsigned int)sysctl_em_inflate_pct * (unsigned __int64)((unsigned int)v50 / 0x64);
    }
    if ( a6 )
      goto LABEL_63;
LABEL_65:
    v15 = v50 * v20;
    goto LABEL_7;
  }
  v37 = v57;
  v41 = 0;
  result = v59;
  v12 = v58;
  v42 = (unsigned __int64 *)(v39 + 32);
  v14 = v8 + 100;
  v43 = v37 * ((unsigned __int64)*(unsigned int *)(v54 + 40) >> 10) + ((v37 * (*(_DWORD *)(v54 + 40) & 0x3FFLL)) >> 10);
  v44 = 4 * v40;
  v45 = v43 + (v43 >> 2);
  v46 = v44 - 4;
  while ( v41 != 400 )
  {
    v47 = *v42;
    v42 += 5;
    v48 = v41 + 4;
    if ( v47 < v45 )
    {
      v49 = v46 == v41;
      v41 += 4;
      if ( !v49 )
        continue;
    }
    LODWORD(v50) = *(_DWORD *)(v54 + v48 + 68);
    goto LABEL_59;
  }
LABEL_70:
  __break(0x5512u);
  return check_for_higher_capacity_0(result, v12);
}
