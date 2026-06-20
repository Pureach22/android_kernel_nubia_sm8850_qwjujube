__int64 __fastcall kgsl_paged_vmfault(_QWORD *a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v7; // x8
  __int64 v8; // x23
  unsigned __int64 v9; // x19
  __int64 v10; // x9
  __int64 v11; // x8
  int inserted; // w0
  __int64 v14; // x8
  unsigned int v15; // w9
  __int64 result; // x0
  unsigned int v17; // w20
  __int64 v18; // x24
  __int64 v19; // x2
  unsigned __int64 mapping_page_gfp; // x0
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned __int64 v23; // x8
  unsigned int v26; // w20
  unsigned int v27; // w20
  unsigned int v33; // w9
  unsigned int v36; // w9
  unsigned int v39; // w10
  unsigned int v42; // w9

  v3 = *(_QWORD *)(a3 + 24) - *a2;
  if ( a1[5] <= (unsigned __int64)(unsigned int)v3 )
    return 2;
  raw_spin_lock((char *)a1 + 108);
  v7 = a1[12];
  v8 = (unsigned int)v3 >> 12;
  v9 = *(_QWORD *)(v7 + 8 * v8);
  if ( !v9 )
  {
    v18 = *(_QWORD *)(a2[12] + 256LL);
    _X8 = (unsigned int *)(a1 + 6);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stxr(v36 | 0x1000, _X8) );
    raw_spin_unlock((char *)a1 + 108);
    if ( kgsl_sharedmem_noretry_flag )
      v19 = 76994;
    else
      v19 = 3266;
    mapping_page_gfp = shmem_read_mapping_page_gfp(*(_QWORD *)(a1[14] + 24LL), v8, v19);
    if ( mapping_page_gfp <= 0xFFFFFFFFFFFFF000LL )
    {
      v9 = mapping_page_gfp;
      ((void (__fastcall *)(_QWORD, unsigned __int64, __int64, _QWORD))kgsl_page_sync)(
        a1[10],
        mapping_page_gfp,
        4096,
        0);
      raw_spin_lock((char *)a1 + 108);
      v21 = a1[12];
      if ( !*(_QWORD *)(v21 + 8 * v8) )
      {
        *(_QWORD *)(v21 + 8 * v8) = v9;
        _X8 = (unsigned int *)(v18 + 400);
        __asm { PRFM            #0x11, [X8] }
        do
          v39 = __ldxr(_X8);
        while ( __stxr(v39 - 1, _X8) );
        v22 = *(_QWORD *)(v9 + 8);
        v23 = v9;
        if ( (v22 & 1) != 0 )
          v23 = v22 - 1;
        _X8 = (unsigned int *)(v23 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
          v42 = __ldxr(_X8);
        while ( __stxr(v42 + 1, _X8) );
      }
      goto LABEL_6;
    }
    return 2;
  }
  v10 = *(_QWORD *)(v9 + 8);
  v11 = *(_QWORD *)(v7 + 8 * v8);
  if ( (v10 & 1) != 0 )
    v11 = v10 - 1;
  _X8 = (unsigned int *)(v11 + 52);
  __asm { PRFM            #0x11, [X8] }
  do
    v33 = __ldxr(_X8);
  while ( __stxr(v33 + 1, _X8) );
LABEL_6:
  raw_spin_unlock((char *)a1 + 108);
  inserted = vm_insert_page(a2, *(_QWORD *)(a3 + 24), v9);
  _NF = inserted != -16 && inserted < 0;
  v14 = *(_QWORD *)(v9 + 8);
  if ( _NF )
    v15 = 2;
  else
    v15 = 256;
  if ( inserted == -12 )
    result = 1;
  else
    result = v15;
  if ( (v14 & 1) != 0 )
    v9 = v14 - 1;
  _X8 = (unsigned int *)(v9 + 52);
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v26 = __ldxr(_X8);
    v27 = v26 - 1;
  }
  while ( __stlxr(v27, _X8) );
  __dmb(0xBu);
  if ( !v27 )
  {
    v17 = result;
    _folio_put(v9);
    return v17;
  }
  return result;
}
