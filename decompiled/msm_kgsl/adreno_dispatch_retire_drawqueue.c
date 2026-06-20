__int64 __fastcall adreno_dispatch_retire_drawqueue(__int64 a1, _DWORD *a2)
{
  unsigned int v4; // w19
  unsigned int v5; // w8
  __int64 v6; // x23
  __int64 v7; // x28
  __int64 v8; // x24
  __int64 v9; // x26
  __int64 v10; // x25
  __int64 v11; // x8
  unsigned __int64 v12; // x7
  const char *v13; // x2
  __int64 v14; // x9
  int v15; // w3
  __int64 v16; // x9
  const char *v17; // x4
  unsigned __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 *v21; // x8
  __int64 v22; // x8
  __int64 v23; // x2
  __int64 v24; // x8
  __int64 v25; // x8
  unsigned __int64 v28; // x9
  unsigned int v31; // w9
  unsigned __int64 v38; // x9

  _ReadStatusReg(SP_EL0);
  _ReadStatusReg(SP_EL0);
  v4 = 0;
  v5 = a2[257];
  while ( !a2 )
  {
LABEL_3:
    if ( v5 >= 0x80 )
LABEL_39:
      __break(0x5512u);
    v6 = *(_QWORD *)&a2[2 * v5];
    if ( (kgsl_check_timestamp(a1, *(_QWORD *)(v6 + 8), *(unsigned int *)(v6 + 20)) & 1) == 0 )
      goto LABEL_38;
    v7 = *(_QWORD *)(v6 + 8);
    v8 = *(_QWORD *)(v7 + 1536);
    if ( !*(_QWORD *)(v6 + 80) )
    {
      if ( (*(_QWORD *)(v6 + 56) & 8) == 0 )
        goto LABEL_7;
      goto LABEL_20;
    }
    _X8 = (unsigned __int64 *)(v7 + 32);
    __asm { PRFM            #0x11, [X8] }
    do
      v38 = __ldxr(_X8);
    while ( __stxr(v38 | 0x10000, _X8) );
    v11 = *(_QWORD *)(v6 + 8);
    v12 = *(_QWORD *)(v6 + 80);
    if ( v11 )
    {
      v16 = *(_QWORD *)(v11 + 24);
      if ( v16 )
        v13 = (const char *)(v16 + 16);
      else
        v13 = "unknown";
      v14 = *(_QWORD *)(v16 + 8);
      if ( v14 )
      {
LABEL_11:
        v15 = *(_DWORD *)(v14 + 112);
        goto LABEL_17;
      }
    }
    else
    {
      v13 = "unknown";
      v14 = MEMORY[0x183560000F4F70];
      if ( MEMORY[0x183560000F4F70] )
        goto LABEL_11;
    }
    v15 = 0;
LABEL_17:
    v17 = (const char *)&unk_13C708;
    v18 = __clz(__rbit64(v12));
    if ( v18 <= 7 )
      v17 = off_156FF0[v18];
    dev_err(
      *(_QWORD *)a1,
      "%s[%d]: gpu %s ctx %u ts %u policy %lX\n",
      v13,
      v15,
      v17,
      *(_DWORD *)(v11 + 4),
      *(_DWORD *)(v6 + 20),
      v12);
    if ( (*(_QWORD *)(v6 + 56) & 8) == 0 )
    {
LABEL_7:
      v9 = 0;
      v10 = 0;
      goto LABEL_21;
    }
LABEL_20:
    v19 = *(unsigned int *)(v6 + 144);
    v20 = *(_QWORD *)(*(_QWORD *)(a1 + 20448) + 8LL);
    __dsb(0xDu);
    v21 = (__int64 *)(v20 + 32 * v19);
    v9 = *v21;
    v10 = v21[1];
LABEL_21:
    if ( (*(_BYTE *)(v7 + 202) & 2) == 0 )
      kgsl_work_period_update(a1, *(_QWORD *)(*(_QWORD *)(v7 + 24) + 488LL));
    v22 = *(_QWORD *)(*(_QWORD *)(v7 + 24) + 8LL);
    if ( v22 )
      v23 = *(unsigned int *)(v22 + 112);
    else
      v23 = 0;
    msm_perf_events_update(
      0,
      3,
      v23,
      *(unsigned int *)(v7 + 4),
      *(unsigned int *)(v6 + 20),
      (*(_QWORD *)(v6 + 24) >> 8) & 1LL);
    if ( (*(_BYTE *)(v6 + 25) & 1) != 0 )
    {
      _X8 = (unsigned __int64 *)(*(_QWORD *)(v7 + 24) + 384LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v28 = __ldxr(_X8);
      while ( __stxr(v28 + 1, _X8) );
      _X8 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(v7 + 24) + 488LL) + 44LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v31 = __ldxr(_X8);
      while ( __stxr(v31 + 1, _X8) );
    }
    adreno_get_rptr(v8);
    log_kgsl_cmdbatch_retired_event(
      *(unsigned int *)(v7 + 4),
      *(unsigned int *)(v6 + 20),
      *(unsigned int *)(v7 + 8),
      *(_QWORD *)(v6 + 24),
      v9,
      v10);
    v24 = *(unsigned int *)(v7 + 1608);
    if ( (unsigned int)v24 >= 7 )
      goto LABEL_39;
    *(_QWORD *)(v7 + 8 * v24 + 1552) = v10 - *(_QWORD *)(v6 + 152);
    *(_DWORD *)(v7 + 1608) = (*(_DWORD *)(v7 + 1608) + 1) % 7;
    kgsl_drawobj_destroy(
      v6,
      *(unsigned int *)(*(_QWORD *)(v6 + 8) + 4LL),
      *(unsigned int *)(*(_QWORD *)(v6 + 8) + 8LL),
      *(unsigned int *)(v6 + 20));
    --*(_DWORD *)(a1 + 19896);
    v25 = (unsigned int)a2[257];
    --a2[256];
    if ( (unsigned int)v25 > 0x7F )
      goto LABEL_39;
    *(_QWORD *)&a2[2 * v25] = 0;
    ++v4;
    v5 = ((unsigned __int8)a2[257] + 1) & 0x7F;
    a2[257] = v5;
  }
  if ( v5 != a2[258] )
    goto LABEL_3;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v4;
}
