__int64 __fastcall hif_pci_irq_set_affinity_hint(
        __int64 result,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v12; // x8
  __int64 v14; // x19
  unsigned __int64 v15; // x23
  unsigned __int64 v16; // x24
  _QWORD *v17; // x22
  char v18; // w9
  unsigned __int64 v19; // x22
  int v20; // w8
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x20
  unsigned __int64 v23; // x22
  int v24; // w8
  char v25; // w25
  unsigned __int64 v26; // x9
  char v27; // w9
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x21
  int v30; // w9
  unsigned __int64 v31; // x21
  _QWORD *v32; // x20
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x20
  __int64 v35; // x26
  __int64 v36; // x22
  _QWORD v37[2]; // [xsp+10h] [xbp-10h] BYREF

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = result;
  if ( (a3 & 1) != 0 )
    v15 = 6;
  else
    v15 = 1;
  v37[1] = v12;
  LODWORD(v12) = *(_DWORD *)(result + 16);
  v37[0] = 0;
  if ( (_DWORD)v12 )
  {
    v16 = 0;
    v17 = (_QWORD *)(result + 2728);
    do
    {
      if ( v16 == 26 )
LABEL_42:
        __break(0x5512u);
      result = (__int64)qdf_cpumask_clear(v17);
      v12 = *(unsigned int *)(v14 + 16);
      ++v16;
      ++v17;
    }
    while ( v16 < v12 );
  }
  if ( !a2 || (a3 & 1) == 0 )
    goto LABEL_26;
  qdf_cpumask_clear(v37);
  v18 = 0;
  v19 = a2;
  v20 = _cpu_online_mask;
  do
  {
    v21 = (unsigned int)(-1LL << v18) & v20;
    if ( !(_DWORD)v21 )
      break;
    v22 = __clz(__rbit64(v21));
    if ( ((v19 >> v22) & 1) != 0 )
    {
      qdf_cpumask_set_cpu((unsigned int)v22, (__int64)v37);
      v20 = _cpu_online_mask;
    }
    v18 = v22 + 1;
  }
  while ( v22 < 0x1F );
  result = qdf_cpumask_empty(v37);
  LODWORD(v12) = *(_DWORD *)(v14 + 16);
  if ( (result & 1) != 0 )
  {
LABEL_26:
    if ( !(_DWORD)v12 )
      goto LABEL_41;
    v23 = 0;
    v24 = _cpu_online_mask;
    v25 = 0;
    do
    {
      v27 = 0;
      do
      {
        v28 = (unsigned int)(-1LL << v27) & v24;
        if ( !(_DWORD)v28 )
          break;
        v29 = __clz(__rbit64(v28));
        v30 = cpu_topology[12 * (unsigned int)v29 + 2];
        if ( (v30 & 0x80000000) == 0 && ((v15 >> v30) & 1) != 0 )
        {
          if ( v23 > 0x19 )
            goto LABEL_42;
          result = qdf_cpumask_set_cpu((unsigned int)v29, v14 + 2728 + 8 * v23);
          v24 = _cpu_online_mask;
          v25 = 1;
        }
        v27 = v29 + 1;
      }
      while ( v29 < 0x1F );
      v26 = *(unsigned int *)(v14 + 16);
      ++v23;
    }
    while ( v23 < v26 );
    if ( !(_DWORD)v26 )
      goto LABEL_41;
LABEL_33:
    v34 = 0;
    v35 = v14 + 120;
    v36 = v14 + 2728;
    while ( 1 )
    {
      if ( (v25 & 1) != 0 )
      {
        if ( v34 > 0x18 )
          goto LABEL_42;
        result = hif_affinity_mgr_set_qrg_irq_affinity(
                   *(_QWORD *)(v14 + 8),
                   *(_DWORD *)(v35 + 4 * v34),
                   *(_DWORD *)(v14 + 232),
                   v34,
                   v36);
        if ( (_DWORD)result )
          result = qdf_trace_msg(
                     0x38u,
                     8u,
                     "%s: Set affinity %*pbl fails for IRQ %d ",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "hif_pci_irq_set_affinity_hint",
                     nr_cpu_ids,
                     v36,
                     *(unsigned int *)(v35 + 4 * v34));
      }
      else
      {
        if ( v34 > 0x18 )
          goto LABEL_42;
        result = qdf_trace_msg(
                   0x38u,
                   8u,
                   "%s: Offline CPU: Set affinity fails for IRQ: %d",
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   "hif_pci_irq_set_affinity_hint",
                   *(unsigned int *)(v35 + 4 * v34));
      }
      ++v34;
      v36 += 8;
      if ( v34 >= *(unsigned int *)(v14 + 16) )
        goto LABEL_41;
    }
  }
  if ( (_DWORD)v12 )
  {
    v31 = 0;
    v32 = (_QWORD *)(v14 + 2728);
    do
    {
      if ( v31 == 26 )
        goto LABEL_42;
      result = (__int64)qdf_cpumask_copy(v32, v37);
      v33 = *(unsigned int *)(v14 + 16);
      ++v31;
      ++v32;
    }
    while ( v31 < v33 );
    v25 = 1;
    if ( (_DWORD)v33 )
      goto LABEL_33;
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
