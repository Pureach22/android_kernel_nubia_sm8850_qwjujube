__int64 __fastcall qce_f8_multi_pkt_req(_QWORD *a1, unsigned __int16 *a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x28
  unsigned int v6; // w26
  unsigned int v7; // w25
  __int64 v8; // x23
  unsigned int v9; // w27
  unsigned int v13; // w0
  unsigned int v15; // w19
  __int64 v16; // x8
  __int64 v17; // x23
  const char **v18; // x25
  _BOOL4 v19; // w24
  char v20; // w0
  char v21; // w27
  unsigned int v27; // w9
  const char *v28; // x0
  const char *v29; // x2
  __int64 v30; // x24
  char v31; // w0
  __int64 v32; // x0
  char v33; // w25
  const char *v34; // x0
  const char *v35; // x2
  int v36; // w8
  __int64 v37; // x24
  __int64 v38; // x8
  int v39; // w9
  _DWORD *v40; // x11
  unsigned __int64 v41; // x8
  int v42; // w9
  __int64 v43; // x2
  unsigned __int64 v44; // x8
  _DWORD *v45; // x9
  int v46; // w12
  unsigned int v47; // w11
  __int64 v48; // x14
  __int64 v49; // x13
  __int64 v50; // x8
  unsigned __int64 v51; // x9
  _DWORD *v52; // x8
  int v53; // w10
  const char *v54; // x1
  __int64 v55; // x1
  unsigned int v57; // w9
  unsigned int v60; // w11
  __int64 v61; // [xsp+10h] [xbp-20h]
  unsigned int v62; // [xsp+18h] [xbp-18h]
  unsigned int v63; // [xsp+1Ch] [xbp-14h]
  __int64 v64; // [xsp+20h] [xbp-10h]
  __int64 v65; // [xsp+28h] [xbp-8h]

  v6 = *a2;
  v7 = a2[1];
  v8 = a4;
  v9 = a2[2];
  v13 = qce_alloc_req_info((__int64)a1, (__int64)a2, a3, a4);
  if ( (v13 & 0x80000000) != 0 )
  {
    LODWORD(v8) = -16;
    return (unsigned int)v8;
  }
  v15 = v13;
  *((_DWORD *)a2 + 15) = v13;
  if ( v13 >= 0xA )
    goto LABEL_62;
  _X20 = (__int64)&a1[929 * v13 + 328];
  *(_QWORD *)(_X20 + 7416) = 0;
  *(_QWORD *)(_X20 + 7421) = 0;
  _X8 = (unsigned int *)*((unsigned int *)a2 + 14);
  if ( (_DWORD)_X8 )
  {
    if ( (_DWORD)_X8 != 1 )
    {
      if ( v13 == 9 )
        goto LABEL_62;
      LODWORD(v8) = -22;
      *(_DWORD *)(_X20 + 8) = 5;
      __asm { PRFM            #0x11, [X20] }
      do
        v27 = __ldxr((unsigned int *)_X20);
      while ( __stlxr(0, (unsigned int *)_X20) );
      __dmb(0xBu);
      if ( v27 )
        return (unsigned int)v8;
      goto LABEL_61;
    }
    v16 = 6368;
    v62 = v9;
  }
  else
  {
    v62 = v9;
    v16 = 6144;
  }
  v63 = v7;
  v64 = a3;
  v65 = v8;
  v17 = *((_QWORD *)a2 + 1);
  v61 = v16;
  v18 = (const char **)*a1;
  v5 = a2[12] * v6;
  v19 = v17 != *((_QWORD *)a2 + 2);
  v20 = is_vmalloc_addr(v17);
  v21 = v20;
  if ( (v20 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    dma_map_single_attrs___already_done = 1;
    v28 = (const char *)dev_driver_string(v18);
    v29 = v18[14];
    if ( !v29 )
      v29 = *v18;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v28, v29);
    __break(0x800u);
    if ( (v21 & 1) != 0 )
      goto LABEL_11;
  }
  else if ( (v20 & 1) != 0 )
  {
LABEL_11:
    v8 = -1;
    goto LABEL_21;
  }
  v8 = dma_map_page_attrs(
         v18,
         ((unsigned __int64)((v17 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
         v17 & 0xFFF,
         v5,
         v19,
         0);
LABEL_21:
  *(_QWORD *)(_X20 + 7392) = v8;
  v30 = *((_QWORD *)a2 + 2);
  if ( *((_QWORD *)a2 + 1) == v30 )
  {
    v32 = 0;
  }
  else
  {
    v8 = *a1;
    v31 = is_vmalloc_addr(*((_QWORD *)a2 + 2));
    if ( (v31 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v33 = v31;
      dma_map_single_attrs___already_done = 1;
      v34 = (const char *)dev_driver_string(v8);
      v35 = *(const char **)(v8 + 112);
      if ( !v35 )
        v35 = *(const char **)v8;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v34, v35);
      __break(0x800u);
      if ( (v33 & 1) != 0 )
        goto LABEL_25;
    }
    else if ( (v31 & 1) != 0 )
    {
LABEL_25:
      v32 = -1;
      LODWORD(v8) = -1;
      goto LABEL_31;
    }
    v32 = dma_map_page_attrs(
            v8,
            ((unsigned __int64)((v30 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v30 & 0xFFF,
            v5,
            2,
            0);
    LODWORD(v8) = v32;
  }
LABEL_31:
  v36 = *((unsigned __int8 *)a1 + 68);
  *(_QWORD *)(_X20 + 7400) = v32;
  *(_DWORD *)(_X20 + 7408) = v5;
  if ( v36 != 1 )
  {
    LODWORD(v8) = -95;
    goto LABEL_54;
  }
  v37 = _X20 + v61;
  ((void (__fastcall *)(_QWORD *, unsigned __int16 *, _QWORD, _QWORD, _QWORD, __int64))ce_f8_setup)(
    a1,
    a2 + 4,
    v6,
    v63,
    v62,
    _X20 + v61);
  *(_QWORD *)(_X20 + 7312) = 0;
  *(_DWORD *)(_X20 + 7412) = v5;
  *(_QWORD *)(_X20 + 7304) = v65;
  _X8 = (_DWORD *)&unk_3;
  *(_QWORD *)(_X20 + 7328) = v64;
  *(_DWORD *)(_X20 + 8) = 3;
  if ( v15 == 9 )
    goto LABEL_62;
  v38 = (__int64)&a1[929 * v15 + 328];
  v39 = *((unsigned __int8 *)a1 + 68);
  *(_DWORD *)(v38 + 48) = 0;
  *(_DWORD *)(v38 + 80) = 0;
  if ( v39 == 1 )
  {
    v40 = *(_DWORD **)(_X20 + 40);
    v41 = *(_QWORD *)v37 - a1[2] + a1[3];
    v42 = *(unsigned __int16 *)(v37 + 216) | (v41 >> 16) & 0xF0000 | 0xC000000;
    *v40 = v41;
    v40[1] = v42;
    v43 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
    *(_DWORD *)(_X20 + 48) = v43;
    if ( (unsigned int)v43 < 0x200 )
    {
      LODWORD(v8) = 0;
      goto LABEL_54;
    }
    goto LABEL_51;
  }
  if ( !(_DWORD)v5 )
    goto LABEL_46;
  v44 = *(unsigned int *)(_X20 + 7392);
  v45 = *(_DWORD **)(_X20 + 40);
  v46 = 0;
  v47 = v5;
  do
  {
    if ( v46 == 512 )
    {
      v54 = "_qce_sps_add_data";
      v43 = 512;
      goto LABEL_53;
    }
    if ( v47 >= 0x7FC0 )
      v48 = 32704;
    else
      v48 = v47;
    v47 -= v48;
    *v45 = v44;
    v45[1] = v48 | (v44 >> 16) & 0xF0000;
    v45 += 2;
    v44 += v48;
    v49 = *(unsigned int *)(_X20 + 48);
    v46 = v49 + 1;
    *(_DWORD *)(_X20 + 48) = v49 + 1;
  }
  while ( v47 );
  if ( (_DWORD)v49 != -1 )
  {
    *(_DWORD *)(*(_QWORD *)(_X20 + 40) + 8 * v49 + 4) |= 0x50000000u;
    v50 = *(unsigned int *)(_X20 + 48);
    goto LABEL_47;
  }
LABEL_46:
  v50 = 0;
LABEL_47:
  v51 = *(_QWORD *)(_X20 + 7040) - a1[2] + a1[3];
  v52 = (_DWORD *)(*(_QWORD *)(_X20 + 40) + 8 * v50);
  v53 = *(unsigned __int16 *)(_X20 + 7256) | 0xA000000 | (v51 >> 16) & 0xF0000;
  *v52 = v51;
  v52[1] = v53;
  v43 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
  *(_DWORD *)(_X20 + 48) = v43;
  if ( (unsigned int)v43 >= 0x200 )
  {
LABEL_51:
    v54 = "_qce_sps_add_cmd";
LABEL_53:
    printk(&unk_15B74, v54, v43);
    LODWORD(v8) = -12;
    goto LABEL_54;
  }
  LODWORD(v8) = qce_sps_add_data((__int64)a1, (unsigned int)v8, v5, _X20 + 64, 0, 0);
  if ( !(_DWORD)v8 )
  {
    LODWORD(v8) = qce_sps_add_data((__int64)a1, a1[3] + *(unsigned int *)(_X20 + 7264) - a1[2], 0x80u, _X20 + 64, 0, 0);
    if ( !(_DWORD)v8 )
    {
      select_mode((__int64)a1, (__int64)&a1[929 * v15 + 328]);
      LODWORD(v8) = qce_sps_transfer((__int64)a1, v15);
      _X8 = (unsigned int *)a1 + 17379;
      goto LABEL_63;
    }
  }
  while ( 1 )
  {
LABEL_54:
    v55 = *(_QWORD *)(_X20 + 7400);
    if ( v55 )
      dma_unmap_page_attrs(*a1, v55, v5, 2, 0);
    dma_unmap_page_attrs(*a1, *(_QWORD *)(_X20 + 7392), v5, *((_QWORD *)a2 + 1) != *((_QWORD *)a2 + 2), 0);
    if ( v15 != 9 )
      break;
LABEL_62:
    __break(0x5512u);
LABEL_63:
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v60 = __ldxr(_X8);
      if ( v60 != 1 )
        break;
      if ( !__stlxr(0, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( !(_DWORD)v8 )
      return (unsigned int)v8;
  }
  *(_DWORD *)(_X20 + 8) = 5;
  __asm { PRFM            #0x11, [X20] }
  do
    v57 = __ldxr((unsigned int *)_X20);
  while ( __stlxr(0, (unsigned int *)_X20) );
  __dmb(0xBu);
  if ( !v57 )
LABEL_61:
    printk(&unk_15B49, "qce_free_req_info", v15);
  return (unsigned int)v8;
}
