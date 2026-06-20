__int64 __fastcall qce_f9_req(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v11; // w19
  __int64 v12; // x28
  int v13; // w8
  __int64 v14; // x8
  __int64 v15; // x27
  __int64 v16; // x26
  char v17; // w0
  unsigned int v23; // w9
  const char *v24; // x0
  const char *v25; // x2
  int v26; // w8
  unsigned int v27; // w8
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x8
  int v31; // w9
  int v32; // w10
  int v33; // w10
  __int64 v34; // x8
  __int64 v35; // x13
  unsigned int v36; // w14
  _DWORD *v37; // x12
  unsigned int v38; // w11
  __int64 v39; // x10
  __int64 v40; // x2
  __int64 v41; // x9
  int v42; // w10
  unsigned __int64 v43; // x9
  _DWORD *v44; // x11
  int v45; // w8
  unsigned int v46; // w8
  unsigned __int64 v47; // x9
  _DWORD *v48; // x10
  __int64 v49; // x13
  __int64 v50; // x8
  __int64 v51; // x8
  unsigned __int64 v52; // x9
  _DWORD *v53; // x8
  int v54; // w10
  __int64 v55; // x8
  unsigned __int64 v56; // x9
  _DWORD *v57; // x8
  const char *v58; // x1
  unsigned int v59; // w23
  unsigned int v61; // w9
  unsigned int v62; // w20
  unsigned int v64; // w10
  char v65; // [xsp+4h] [xbp-Ch]
  __int64 v66; // [xsp+8h] [xbp-8h]

  result = qce_alloc_req_info(a1, a2, a3, a4);
  if ( (result & 0x80000000) != 0 )
    return 4294967280LL;
  v11 = result;
  *(_DWORD *)(a2 + 48) = result;
  if ( (unsigned int)result >= 0xA )
    goto LABEL_58;
  v12 = a1 + 2624;
  _X20 = a1 + 2624 + 7432LL * (unsigned int)result;
  v13 = *(_DWORD *)(a2 + 44);
  if ( v13 )
  {
    if ( v13 != 1 )
    {
      if ( (_DWORD)result == 9 )
        goto LABEL_58;
      result = 4294967274LL;
      *(_DWORD *)(_X20 + 8) = 5;
      __asm { PRFM            #0x11, [X20] }
      do
        v23 = __ldxr((unsigned int *)_X20);
      while ( __stlxr(0, (unsigned int *)_X20) );
      __dmb(0xBu);
      if ( !v23 )
      {
LABEL_57:
        v62 = result;
        printk(&unk_15B49, "qce_free_req_info", v11);
        return v62;
      }
      return result;
    }
    v14 = 6816;
  }
  else
  {
    v14 = 6592;
  }
  v66 = v14;
  _X25 = *(const char ***)a1;
  *(_QWORD *)(_X20 + 7416) = 0;
  *(_QWORD *)(_X20 + 7421) = 0;
  v15 = *(_QWORD *)a2;
  v16 = *(unsigned __int16 *)(a2 + 8);
  v17 = is_vmalloc_addr(*(_QWORD *)a2);
  if ( (v17 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v65 = v17;
    dma_map_single_attrs___already_done = 1;
    v24 = (const char *)dev_driver_string(_X25);
    v25 = _X25[14];
    if ( !v25 )
      v25 = *_X25;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v24, v25);
    __break(0x800u);
    if ( (v65 & 1) != 0 )
      goto LABEL_11;
  }
  else if ( (v17 & 1) != 0 )
  {
LABEL_11:
    result = -1;
    goto LABEL_21;
  }
  result = dma_map_page_attrs(
             _X25,
             ((unsigned __int64)((v15 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
             v15 & 0xFFF,
             v16,
             1,
             0);
LABEL_21:
  *(_QWORD *)(_X20 + 7392) = result;
  v26 = *(unsigned __int8 *)(a1 + 68);
  *(_DWORD *)(_X20 + 7408) = *(unsigned __int16 *)(a2 + 8);
  if ( v26 != 1 )
  {
    LODWORD(result) = -95;
    goto LABEL_52;
  }
  v27 = *(_DWORD *)(a2 + 48);
  if ( v27 >= 0xA )
    goto LABEL_58;
  v28 = *(unsigned int *)(v12 + 7432LL * v27 + 7420);
  if ( (unsigned int)v28 >= 6 )
    goto LABEL_58;
  _X25 = (const char **)(a1 + 69516);
  v29 = 264;
  if ( !*(_DWORD *)(a2 + 44) )
    v29 = 260;
  v30 = a1 + 4 * v28;
  v31 = *(_DWORD *)(a1 + v29);
  if ( *(_BYTE *)(a1 + 70261) )
    v32 = 15360;
  else
    v32 = 0;
  v33 = ((v32 & 0x1FFFF | ((unsigned __int16)(*(_DWORD *)(a1 + 400) >> 3) << 17)) - 0x20000)
      | (32 * *(_DWORD *)(v30 + 316));
  v34 = _X20 + v66;
  v35 = *(_QWORD *)(_X20 + v66 + 8);
  *(_DWORD *)(a1 + 148) = v33 | 0xE;
  *(_DWORD *)(a1 + 152) = v33 | 0x20E;
  *(_DWORD *)(v35 + 4) = v33 | 0xE;
  *(_DWORD *)(*(_QWORD *)(_X20 + v66 + 16) + 4LL) = *(_DWORD *)(a1 + 152);
  LODWORD(v35) = *(_DWORD *)(a2 + 36);
  v36 = *(_DWORD *)(a2 + 40);
  v37 = *(_DWORD **)(_X20 + v66 + 176);
  v38 = bswap32(*(_DWORD *)(a2 + 32));
  v37[1] = bswap32(*(_DWORD *)(a2 + 28));
  v37[5] = v38;
  v37[9] = bswap32(v35);
  v37[13] = bswap32(v36);
  v37[17] = *(unsigned __int8 *)(a2 + 10);
  v39 = *(_QWORD *)(_X20 + v66 + 192);
  *(_DWORD *)(v39 + 4) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v39 + 20) = *(_DWORD *)(a2 + 20);
  if ( *(_DWORD *)(a2 + 24) == 1 )
    v31 |= 0x800000u;
  *(_DWORD *)(*(_QWORD *)(v34 + 144) + 4LL) = v31;
  *(_DWORD *)(*(_QWORD *)(v34 + 152) + 4LL) = *(unsigned __int16 *)(a2 + 8);
  *(_DWORD *)(*(_QWORD *)(v34 + 160) + 4LL) = 0;
  *(_DWORD *)(*(_QWORD *)(v34 + 200) + 4LL) = *(unsigned __int16 *)(a2 + 8);
  **(_DWORD **)(v34 + 208) = *(_DWORD *)(a1 + 70256) & (*(_DWORD *)(a1 + 88) + 106784) & 0xFFFFFF
                           | (*(unsigned __int8 *)(*(_QWORD *)(v34 + 208) + 3LL) << 24);
  *(_QWORD *)(_X20 + 7328) = a3;
  *(_QWORD *)(_X20 + 7304) = a4;
  *(_QWORD *)(_X20 + 7312) = 0;
  *(_DWORD *)(_X20 + 8) = 4;
  *(_DWORD *)(_X20 + 7412) = *(unsigned __int16 *)(a2 + 8);
  if ( v11 == 9 )
    goto LABEL_58;
  v40 = 0;
  v41 = v12 + 7432LL * v11;
  v42 = *(unsigned __int8 *)(a1 + 68);
  *(_DWORD *)(v41 + 48) = 0;
  *(_DWORD *)(v41 + 80) = 0;
  if ( v42 == 1 )
  {
    v43 = *(_QWORD *)v34 - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24);
    v44 = *(_DWORD **)(_X20 + 40);
    v45 = *(unsigned __int16 *)(v34 + 216) | (v43 >> 16) & 0xF0000 | 0xC000000;
    *v44 = v43;
    v44[1] = v45;
    v40 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
    *(_DWORD *)(_X20 + 48) = v40;
    if ( (unsigned int)v40 >= 0x200 )
      goto LABEL_48;
  }
  v46 = *(unsigned __int16 *)(a2 + 8);
  if ( *(_WORD *)(a2 + 8) )
  {
    v47 = *(unsigned int *)(_X20 + 7392);
    v48 = (_DWORD *)(*(_QWORD *)(_X20 + 40) + 8LL * (unsigned int)v40);
    while ( (_DWORD)v40 != 512 )
    {
      if ( v46 >= 0x7FC0 )
        v49 = 32704;
      else
        v49 = v46;
      v46 -= v49;
      *v48 = v47;
      v48[1] = v49 | (v47 >> 16) & 0xF0000;
      v48 += 2;
      v47 += v49;
      v40 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
      *(_DWORD *)(_X20 + 48) = v40;
      if ( !v46 )
        goto LABEL_41;
    }
    v58 = "_qce_sps_add_data";
LABEL_51:
    printk(&unk_15B74, v58, v40);
    LODWORD(result) = -12;
    goto LABEL_52;
  }
LABEL_41:
  if ( (_DWORD)v40 )
  {
    v50 = *(_QWORD *)(_X20 + 40) + 8LL * (unsigned int)(v40 - 1);
    *(_DWORD *)(v50 + 4) |= 0x50000000u;
    v51 = *(unsigned int *)(_X20 + 48);
  }
  else
  {
    v51 = 0;
  }
  v52 = *(_QWORD *)(_X20 + 7040) - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24);
  v53 = (_DWORD *)(*(_QWORD *)(_X20 + 40) + 8 * v51);
  v54 = *(unsigned __int16 *)(_X20 + 7256) | 0xA000000 | (v52 >> 16) & 0xF0000;
  *v53 = v52;
  v53[1] = v54;
  v40 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
  *(_DWORD *)(_X20 + 48) = v40;
  if ( (unsigned int)v40 >= 0x200 )
  {
LABEL_48:
    v58 = "_qce_sps_add_cmd";
    goto LABEL_51;
  }
  v55 = *(unsigned int *)(_X20 + 80);
  if ( (_DWORD)v55 == 512 )
  {
    v58 = "_qce_sps_add_data";
    v40 = 512;
    goto LABEL_51;
  }
  v56 = *(_QWORD *)(a1 + 24) + *(unsigned int *)(_X20 + 7264) - *(_QWORD *)(a1 + 16);
  v57 = (_DWORD *)(*(_QWORD *)(_X20 + 72) + 8 * v55);
  *v57 = v56;
  v57[1] = (v56 >> 16) & 0xF0000 | 0x80;
  ++*(_DWORD *)(_X20 + 80);
  select_mode(a1, a1 + 2624 + 7432LL * v11);
  result = qce_sps_transfer(a1, v11);
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X25] }
    while ( 1 )
    {
      v64 = __ldxr((unsigned int *)_X25);
      if ( v64 != 1 )
        break;
      if ( !__stlxr(0, (unsigned int *)_X25) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( !(_DWORD)result )
      return result;
LABEL_52:
    v59 = result;
    result = dma_unmap_page_attrs(*(_QWORD *)a1, *(_QWORD *)(_X20 + 7392), *(unsigned __int16 *)(a2 + 8), 1, 0);
    if ( v11 != 9 )
    {
      result = v59;
      *(_DWORD *)(_X20 + 8) = 5;
      __asm { PRFM            #0x11, [X20] }
      do
        v61 = __ldxr((unsigned int *)_X20);
      while ( __stlxr(0, (unsigned int *)_X20) );
      __dmb(0xBu);
      if ( !v61 )
        goto LABEL_57;
      return result;
    }
LABEL_58:
    __break(0x5512u);
  }
}
