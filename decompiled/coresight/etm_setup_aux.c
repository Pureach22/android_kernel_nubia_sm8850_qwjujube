__int64 __fastcall etm_setup_aux(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  unsigned __int64 v4; // x19
  __int64 v9; // x0
  __int64 v10; // x23
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 sink_by_id; // x24
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x25
  char v16; // w8
  __int64 v17; // x19
  __int64 v18; // x25
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x26
  __int64 v21; // x8
  __int64 v22; // x27
  unsigned __int64 v23; // x0
  __int64 default_sink; // x0
  _QWORD **v25; // x27
  unsigned __int64 v28; // x10
  unsigned __int64 v31; // x10
  unsigned __int64 v34; // x10
  unsigned __int64 v37; // x10
  unsigned __int64 v40; // x10
  int v41; // w9
  unsigned int v42; // w8
  __int64 v43; // x9
  _DWORD *v44; // x8
  __int64 v45; // x0
  unsigned __int64 v53; // x10
  __int64 v54; // [xsp+8h] [xbp-18h]
  char v55; // [xsp+10h] [xbp-10h]
  __int64 v56; // [xsp+18h] [xbp-8h]

  v4 = *(unsigned int *)(a1 + 668);
  v9 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  v10 = v9;
  if ( !v9 )
    return v10;
  if ( (_DWORD)v4 == -1 )
  {
    *(_QWORD *)(v9 + 32) = _cpu_present_mask;
  }
  else
  {
    _X9 = (unsigned __int64 *)(v9 + 32 + 8 * (v4 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v53 = __ldxr(_X9);
    while ( __stxr(v53 | (1LL << v4), _X9) );
  }
  v11 = pcpu_alloc_noprof(8, 8, 0, 3264);
  *(_QWORD *)(v10 + 64) = v11;
  if ( v11 )
  {
    *(_QWORD *)v10 = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v10 + 8) = v10 + 8;
    *(_QWORD *)(v10 + 16) = v10 + 8;
    v12 = *(unsigned int *)(a1 + 280);
    *(_QWORD *)(v10 + 24) = free_event_data;
    v55 = a4;
    if ( v12 )
      sink_by_id = coresight_get_sink_by_id(v12);
    else
      sink_by_id = 0;
    coresight_trace_id_perf_start();
    v14 = *(_QWORD *)(a1 + 280);
    v54 = a1;
    v15 = HIDWORD(v14);
    if ( HIDWORD(v14) )
    {
      if ( (unsigned int)cscfg_activate_config(HIDWORD(v14)) )
        goto LABEL_50;
      *(_DWORD *)(v10 + 56) = v15;
    }
    v16 = 0;
    v17 = 0;
    v18 = sink_by_id;
    v56 = a2;
    while ( 1 )
    {
      v19 = (unsigned int)(-1LL << v16) & *(_DWORD *)(v10 + 32);
      if ( !(_DWORD)v19 )
      {
LABEL_40:
        if ( !v18 )
          goto LABEL_50;
        v41 = __clz(__rbit64(*(unsigned int *)(v10 + 32)));
        v42 = *(_DWORD *)(v10 + 32) ? v41 : 32;
        if ( v42 >= nr_cpu_ids )
          goto LABEL_50;
        v43 = **(_QWORD **)(v18 + 24);
        v44 = *(_DWORD **)(v43 + 16);
        if ( !v44 || !*(_QWORD *)(v43 + 24) )
          goto LABEL_50;
        if ( *(v44 - 1) != -534238664 )
          __break(0x8228u);
        v45 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD))v44)(v18, v54, v56, a3, v55 & 1);
        *(_QWORD *)(v10 + 48) = v45;
        if ( !v45 )
        {
LABEL_50:
          queue_work_on(32, system_wq, v10);
          return 0;
        }
        return v10;
      }
      v20 = __clz(__rbit64(v19));
      v21 = _per_cpu_offset[v20];
      v22 = *(_QWORD *)((char *)&csdev_src + v21);
      if ( !v22 )
      {
        _X9 = (unsigned __int64 *)(v10 + 32);
        __asm { PRFM            #0x11, [X9] }
        do
          v28 = __ldxr(_X9);
        while ( __stxr(v28 & ~(1LL << v20), _X9) );
        goto LABEL_14;
      }
      if ( !sink_by_id )
      {
        default_sink = coresight_find_default_sink(*(_QWORD *)((char *)&csdev_src + v21));
        if ( !default_sink )
        {
          _X9 = (unsigned __int64 *)(v10 + 32);
          __asm { PRFM            #0x11, [X9] }
          do
            v37 = __ldxr(_X9);
          while ( __stxr(v37 & ~(1LL << v20), _X9) );
          v18 = 0;
          goto LABEL_14;
        }
        v18 = default_sink;
        if ( v17
          && (*(_DWORD *)(v17 + 12) != *(_DWORD *)(default_sink + 12)
           || **(_QWORD **)(v17 + 24) != **(_QWORD **)(default_sink + 24)) )
        {
          _X9 = (unsigned __int64 *)(v10 + 32);
          __asm { PRFM            #0x11, [X9] }
          do
            v40 = __ldxr(_X9);
          while ( __stxr(v40 & ~(1LL << v20), _X9) );
          goto LABEL_14;
        }
        v17 = default_sink;
      }
      v23 = coresight_build_path(v22, v18);
      if ( v23 < 0xFFFFFFFFFFFFF001LL )
      {
        v25 = (_QWORD **)v23;
        if ( (unsigned int)coresight_trace_id_get_cpu_id((unsigned int)v20) - 1 < 0x6F )
        {
          *(_QWORD *)(_per_cpu_offset[v20] + *(_QWORD *)(v10 + 64)) = v25;
        }
        else
        {
          _X9 = (unsigned __int64 *)(v10 + 32);
          __asm { PRFM            #0x11, [X9] }
          do
            v34 = __ldxr(_X9);
          while ( __stxr(v34 & ~(1LL << v20), _X9) );
          coresight_release_path(v25);
        }
      }
      else
      {
        _X9 = (unsigned __int64 *)(v10 + 32);
        __asm { PRFM            #0x11, [X9] }
        do
          v31 = __ldxr(_X9);
        while ( __stxr(v31 & ~(1LL << v20), _X9) );
      }
LABEL_14:
      v16 = v20 + 1;
      if ( v20 >= 0x1F )
        goto LABEL_40;
    }
  }
  kfree(v10);
  return 0;
}
