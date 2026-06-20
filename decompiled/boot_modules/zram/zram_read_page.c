__int64 __fastcall zram_read_page(__int64 *a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v6; // x23
  __int64 v9; // x25
  __int64 v10; // x9
  int v11; // w8
  __int64 v12; // x23
  _QWORD *v13; // x26
  __int64 v14; // x1
  unsigned int v15; // w22
  __int64 v16; // x19
  __int64 v17; // x24
  __int64 v18; // x0
  unsigned __int64 v19; // x3
  __int64 v20; // x8
  __int64 v21; // x12
  unsigned __int64 v22; // x14
  __int64 v23; // x13
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x1
  int v27; // w0
  unsigned __int64 v35; // x9

  v6 = 16LL * a3;
  v9 = a3;
  raw_spin_lock(*a1 + v6 + 12);
  v10 = *a1;
  v11 = *(_DWORD *)(*a1 + v6 + 8);
  if ( (v11 & 0x4000) != 0 )
  {
    raw_spin_unlock(v10 + 16 * v9 + 12);
    v12 = *(_QWORD *)(*a1 + 16 * v9);
  }
  else
  {
    a4 = *(_QWORD *)(v10 + 16 * v9);
    if ( (v11 & 0x2000) != 0 || !a4 )
    {
      memset64(
        ((a2 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL,
        *(_QWORD *)(v10 + 16 * v9),
        512);
      v15 = 0;
      goto LABEL_21;
    }
    v12 = v11 & 0x1FFF;
    if ( (v11 & 0x1FFF) == 0x1000 )
    {
      v13 = a1 + 1;
      v14 = zs_map_object(a1[1], *(_QWORD *)(v10 + 16 * v9), 1);
      copy_page(((a2 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL, v14);
      v15 = 0;
LABEL_20:
      zs_unmap_object(*v13, a4);
LABEL_21:
      raw_spin_unlock(*a1 + 16 * v9 + 12);
      if ( (v15 & 0x80000000) == 0 )
        return v15;
LABEL_28:
      __break(0x800u);
      panic("Decompression failed! err=%d, page=%u\n", v15, a3);
    }
    if ( (v11 & 0x180000) == 0 )
    {
      v17 = zcomp_stream_get((__int64 *)a1[2]);
      v13 = a1 + 1;
      v18 = zs_map_object(a1[1], a4, 1);
      v19 = ((a2 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
      if ( *((_BYTE *)a1 + 234) == 1 )
      {
        v20 = v18 << 8 >> 8;
        v21 = (__int64)(v19 << 8) >> 8;
        v22 = (unsigned __int64)(v20 + 0x8000000000LL) >> 38;
        v23 = memstart_addr + v20 + 0x8000000000LL;
        v24 = v20 - kimage_voffset;
        if ( v22 )
          v25 = v24;
        else
          v25 = v23;
        if ( (unsigned __int64)(v21 + 0x8000000000LL) >> 38 )
          v26 = v21 - kimage_voffset;
        else
          v26 = memstart_addr + v21 + 0x8000000000LL;
        v27 = qpace_urgent_decompress(v25, v26, v12);
        v15 = v27 & (v27 >> 31);
      }
      else
      {
        v15 = zcomp_decompress(v17, v18, (unsigned int)v12, v19);
      }
      zcomp_stream_put();
      goto LABEL_20;
    }
    __break(0x5512u);
  }
  _X8 = (unsigned __int64 *)(a1 + 25);
  __asm { PRFM            #0x11, [X8] }
  do
    v35 = __ldxr(_X8);
  while ( __stxr(v35 + 1, _X8) );
  if ( !a4 )
  {
    v15 = -5;
    __break(0x800u);
    goto LABEL_28;
  }
  v16 = bio_alloc_bioset(a1[33], 1, *(unsigned int *)(a4 + 16), 3072, &fs_bio_set);
  *(_QWORD *)(v16 + 32) = 8 * v12;
  _bio_add_page();
  bio_chain(v16, a4);
  submit_bio(v16);
  return 0;
}
