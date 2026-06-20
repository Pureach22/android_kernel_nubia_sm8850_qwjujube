__int64 __fastcall walt_lb_find_busiest_cpu(__int64 a1, _DWORD *a2, _DWORD *a3, char a4)
{
  unsigned int v7; // w21
  unsigned int v8; // w9
  unsigned int v9; // w22
  _BOOL4 v10; // w16
  _BYTE *v11; // x12
  char v12; // w10
  _BYTE *v13; // x13
  _BOOL4 v14; // w21
  char v15; // w9
  unsigned __int64 v16; // x21
  __int64 result; // x0
  unsigned __int64 v18; // x9
  bool v19; // cf
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x20
  __int64 v22; // x9
  int v23; // w10
  char v25; // w21
  unsigned __int64 v26; // x2
  __int64 v27; // x23
  __int64 v28; // x8
  unsigned __int64 v29; // x9
  int v30; // w10
  int v31; // w15
  __int64 v32; // x21
  unsigned __int64 v33; // x26
  _BYTE *v34; // x28
  __int64 v35; // x6
  _BYTE *v36; // x30
  char *v37; // x24
  unsigned __int64 v38; // x21
  unsigned __int64 v39; // x22
  __int64 v40; // x6
  __int64 v41; // x30
  __int64 v42; // x24
  char v43; // w2
  unsigned __int64 v44; // x11
  __int64 v45; // x22
  __int64 v46; // x9
  unsigned __int64 v47; // x24
  int v48; // w25
  unsigned __int64 v49; // x2
  unsigned __int64 v50; // x20
  __int64 v51; // x2
  char *v52; // x6
  _BYTE *v53; // x5
  __int64 v54; // x7
  unsigned __int64 v55; // x2
  unsigned __int64 v56; // x4
  char *v57; // x6
  unsigned __int16 *v58; // x6
  __int64 v59; // x5
  __int64 v60; // x5
  unsigned __int64 v61; // x6
  int v62; // w4

  v7 = a1;
  v8 = __clz(__rbit64((unsigned int)*a2));
  if ( *a2 )
    v9 = v8;
  else
    v9 = 32;
  if ( (check_for_higher_capacity(a1, v9) & 1) != 0 )
  {
    v10 = (a4 & 1) != 0 || available_idle_cpu(v7) != 0;
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v28 = 0;
    v29 = 0;
    v30 = 0;
    v31 = 0;
    result = 0xFFFFFFFFLL;
    _ReadStatusReg(SP_EL0);
    do
    {
      v32 = -1LL << v25;
      if ( ((unsigned int)v32 & *a2) == 0 )
        break;
      v33 = __clz(__rbit64((unsigned int)v32 & *a2));
      if ( (_cpu_active_mask & (1LL << v33)) != 0 )
      {
        v34 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v33)];
        v35 = *((_QWORD *)&_per_cpu_offset + v33);
        ++v30;
        v36 = &walt_rq[v35];
        v37 = (char *)&runqueues + v35;
        v38 = *(_QWORD *)&walt_rq[v35 + 40];
        v39 = *(_QWORD *)&walt_rq[v35 + 632];
        v40 = *(unsigned int *)((char *)&runqueues + v35 + 532);
        v28 += v38;
        v27 += v39;
        v29 += v40;
        if ( !*((_DWORD *)v37 + 894) && ((unsigned int)v40 > 1 || *((_DWORD *)v34 + 6) && v10) )
        {
          if ( (walt_rotation_enabled & 1) != 0 )
            goto LABEL_52;
          v41 = *(unsigned int *)(*((_QWORD *)v36 + 1) + 32LL);
          if ( (unsigned int)v41 >= 4 )
            goto LABEL_101;
          v42 = v38 >= v39 ? v39 : v38;
          if ( v42 * (unsigned __int64)(unsigned int)sched_capacity_margin_up[v41] > v39 << 10
            || sysctl_sched_asymcap_boost
            && (_DWORD)v41 != min_possible_cluster_id
            && (_cpu_partial_halt_mask[0] & (1LL << v33)) == 0 )
          {
LABEL_52:
            if ( v38 >= v26 )
            {
              v31 = *((_DWORD *)v34 + 6);
              v26 = v38;
              result = (unsigned int)v33;
            }
          }
        }
      }
      v25 = v33 + 1;
    }
    while ( v33 < 0x1F );
    if ( (walt_rotation_enabled & 1) != 0 || v31 )
    {
      if ( v31 && (_DWORD)result != -1 )
        *a3 = 1;
      return result;
    }
    if ( (_DWORD)result == -1 || !sysctl_sched_asymcap_boost )
      goto LABEL_61;
    if ( (unsigned int)result < 0x20 )
    {
      if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)result) + 8] + 32LL) != min_possible_cluster_id
        && (((unsigned __int64)_cpu_partial_halt_mask[0] >> result) & 1) == 0 )
      {
        return result;
      }
LABEL_61:
      if ( v29 <= v30 || 1280 * v28 < (unsigned __int64)(v27 << 10) )
        return 0xFFFFFFFFLL;
      return result;
    }
LABEL_101:
    __break(0x5512u);
    return find_first_idle_if_others_are_busy();
  }
  if ( (((unsigned __int64)_cpu_partial_halt_mask[0] >> v9) & 1) != 0 )
  {
    if ( v7 >= 0x20 )
      goto LABEL_101;
    if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v7) + 8] + 32LL) == min_possible_cluster_id )
      goto LABEL_18;
  }
  if ( v9 >= 0x20 )
    goto LABEL_101;
  v11 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v9)];
  v12 = v7;
  if ( *(_DWORD *)(*((_QWORD *)v11 + 1) + 32LL) == min_possible_cluster_id
    && ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask + (((unsigned __int64)v7 >> 3) & 0x1FFFFFF8)) >> v7) & 1) != 0 )
  {
    goto LABEL_18;
  }
  if ( v7 >= 0x20 )
    goto LABEL_101;
  v13 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v7)];
  if ( *((_QWORD *)v11 + 79) <= *((_QWORD *)v13 + 79) )
  {
LABEL_18:
    v15 = 0;
    v16 = 0;
    result = 0xFFFFFFFFLL;
    _ReadStatusReg(SP_EL0);
    do
    {
      v20 = (unsigned int)(-1LL << v15) & *a2;
      if ( !(_DWORD)v20 )
        break;
      v21 = __clz(__rbit64(v20));
      v22 = *((_QWORD *)&_per_cpu_offset + v21);
      v23 = *(_DWORD *)((char *)&runqueues + v22 + 532);
      if ( ((((unsigned __int64)_cpu_halt_mask[0] >> v21) & 1) == 0 || !v23)
        && (*(_DWORD *)((char *)&runqueues + v22 + 4) < 2u || v23 == 0) )
      {
        continue;
      }
      v18 = *(_QWORD *)&walt_rq[v22 + 40];
      v19 = v18 >= v16;
      if ( v18 > v16 )
        v16 = v18;
      if ( v19 )
        result = (unsigned int)v21;
      else
        result = (unsigned int)result;
      v15 = v21 + 1;
    }
    while ( v21 < 0x1F );
    return result;
  }
  v14 = sysctl_sched_asymcap_boost
     && *(_DWORD *)(*((_QWORD *)v13 + 1) + 32LL) != min_possible_cluster_id
     && (((unsigned __int64)_cpu_partial_halt_mask[0] >> v7) & 1) == 0;
  if ( (((unsigned __int64)_cpu_partial_halt_mask[0] >> v12) & 1) != 0 )
    return 0xFFFFFFFFLL;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  result = 0xFFFFFFFFLL;
  _ReadStatusReg(SP_EL0);
  do
  {
    v49 = (unsigned int)(-1LL << v43) & *a2;
    if ( !(_DWORD)v49 )
      break;
    v50 = __clz(__rbit64(v49));
    if ( ((_cpu_active_mask >> v50) & 1) == 0 )
      goto LABEL_73;
    v51 = *((_QWORD *)&_per_cpu_offset + v50);
    ++v48;
    v52 = (char *)&runqueues + v51;
    v53 = &walt_rq[v51];
    v54 = *(unsigned int *)((char *)&runqueues + v51 + 532);
    v55 = *(_QWORD *)&walt_rq[v51 + 40];
    v56 = *((_QWORD *)v53 + 79);
    v46 += v55;
    v45 += v56;
    v47 += v54;
    if ( (unsigned int)v54 < 2 )
      goto LABEL_73;
    if ( (_DWORD)v54 == 2 )
    {
      v57 = *((char **)v52 + 418);
      v58 = (unsigned __int16 *)(v57 == (char *)&init_task ? &vendor_data_pad : v57 + 5184);
      if ( v58[79] < 0x66u )
        goto LABEL_73;
    }
    if ( (walt_rotation_enabled & 1) != 0 )
    {
      if ( v55 < v44 )
        goto LABEL_73;
    }
    else
    {
      v59 = *(unsigned int *)(*((_QWORD *)v53 + 1) + 32LL);
      if ( (unsigned int)v59 >= 4 )
        goto LABEL_101;
      v60 = (unsigned int)sched_capacity_margin_up[v59];
      if ( v55 >= v56 )
        v61 = v56;
      else
        v61 = v55;
      v62 = v61 * v60 > v56 << 10 || v14;
      if ( v62 != 1 || v55 < v44 )
        goto LABEL_73;
    }
    v44 = v55;
    result = (unsigned int)v50;
LABEL_73:
    v43 = v50 + 1;
  }
  while ( v50 < 0x1F );
  if ( (((unsigned __int8)walt_rotation_enabled | v14) & 1) == 0
    && (v47 <= v48 || 1280 * v46 < (unsigned __int64)(v45 << 10)) )
  {
    return 0xFFFFFFFFLL;
  }
  return result;
}
