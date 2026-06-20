__int64 __fastcall qce_f8_req(const char ***a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x20
  __int64 result; // x0
  unsigned int v11; // w22
  __int64 v12; // x9
  __int64 v13; // x25
  unsigned int v19; // w9
  const char **v21; // x27
  _BOOL4 v22; // w26
  char v23; // w0
  char v24; // w22
  __int64 v25; // x25
  const char *v26; // x0
  const char *v27; // x2
  __int64 v28; // x26
  __int64 v29; // x27
  char v30; // w0
  __int64 v31; // x0
  const char *v32; // x0
  const char *v33; // x2
  __int64 v34; // x26
  __int64 v35; // x2
  __int64 v36; // x8
  int v37; // w9
  _DWORD *v38; // x11
  unsigned __int64 v39; // x8
  int v40; // w9
  unsigned int v41; // w8
  unsigned __int64 v42; // x9
  _DWORD *v43; // x10
  __int64 v44; // x13
  __int64 v45; // x8
  __int64 v46; // x1
  unsigned int v47; // w22
  __int64 v48; // x1
  __int64 v49; // x9
  __int64 v50; // x10
  __int64 v51; // x2
  unsigned int v53; // w9
  unsigned int v54; // w19
  const char *v55; // x1
  unsigned int v57; // w11
  __int64 v58; // [xsp+8h] [xbp-18h]
  char v59; // [xsp+8h] [xbp-18h]
  __int64 v60; // [xsp+10h] [xbp-10h]
  unsigned int v61; // [xsp+1Ch] [xbp-4h]

  v7 = a2;
  result = qce_alloc_req_info((__int64)a1, a2, a3, a4);
  if ( (result & 0x80000000) != 0 )
    return 4294967280LL;
  v11 = result;
  *(_DWORD *)(v7 + 52) = result;
  if ( (unsigned int)result >= 0xA )
    goto LABEL_68;
  _X19 = (__int64)&a1[929 * (unsigned int)result + 328];
  *(_QWORD *)(_X19 + 7416) = 0;
  *(_QWORD *)(_X19 + 7421) = 0;
  _X8 = *(unsigned int *)(v7 + 48);
  if ( (_DWORD)_X8 )
  {
    if ( (_DWORD)_X8 != 1 )
    {
      if ( (_DWORD)result == 9 )
        goto LABEL_68;
      *(_DWORD *)(_X19 + 8) = 5;
      __asm { PRFM            #0x11, [X19] }
      do
        v19 = __ldxr((unsigned int *)_X19);
      while ( __stlxr(0, (unsigned int *)_X19) );
      goto LABEL_17;
    }
    v12 = 6368;
    v13 = *(_QWORD *)v7;
    if ( !*(_QWORD *)v7 )
    {
LABEL_10:
      if ( (_DWORD)result == 9 )
        goto LABEL_68;
      *(_DWORD *)(_X19 + 8) = 5;
      __asm { PRFM            #0x11, [X19] }
      do
        v19 = __ldxr((unsigned int *)_X19);
      while ( __stlxr(0, (unsigned int *)_X19) );
LABEL_17:
      __dmb(0xBu);
      result = 4294967274LL;
      if ( !v19 )
      {
LABEL_63:
        v54 = result;
        printk(&unk_15B49, "qce_free_req_info", v11);
        return v54;
      }
      return result;
    }
  }
  else
  {
    v12 = 6144;
    v13 = *(_QWORD *)v7;
    if ( !*(_QWORD *)v7 )
      goto LABEL_10;
  }
  _X8 = *(unsigned __int8 *)(v7 + 24);
  if ( (unsigned int)_X8 >= 0x1F )
    goto LABEL_10;
  v60 = v12;
  v21 = *a1;
  v61 = result;
  v58 = *(unsigned __int16 *)(v7 + 16);
  v22 = v13 != *(_QWORD *)(v7 + 8);
  v23 = is_vmalloc_addr(v13);
  v24 = v23;
  if ( (v23 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    dma_map_single_attrs___already_done = 1;
    v26 = (const char *)dev_driver_string(v21);
    v27 = v21[14];
    if ( !v27 )
      v27 = *v21;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v26, v27);
    __break(0x800u);
    if ( (v24 & 1) != 0 )
      goto LABEL_22;
  }
  else if ( (v23 & 1) != 0 )
  {
LABEL_22:
    v25 = -1;
    goto LABEL_27;
  }
  v25 = dma_map_page_attrs(
          v21,
          ((unsigned __int64)((v13 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
          v13 & 0xFFF,
          v58,
          v22,
          0);
LABEL_27:
  *(_QWORD *)(_X19 + 7392) = v25;
  v28 = *(_QWORD *)(v7 + 8);
  if ( *(_QWORD *)v7 == v28 )
  {
    v31 = 0;
    goto LABEL_37;
  }
  v25 = (__int64)*a1;
  v29 = *(unsigned __int16 *)(v7 + 16);
  v30 = is_vmalloc_addr(*(_QWORD *)(v7 + 8));
  if ( (v30 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v59 = v30;
    dma_map_single_attrs___already_done = 1;
    v32 = (const char *)dev_driver_string(v25);
    v33 = *(const char **)(v25 + 112);
    if ( !v33 )
      v33 = *(const char **)v25;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v32, v33);
    __break(0x800u);
    if ( (v59 & 1) != 0 )
      goto LABEL_31;
LABEL_36:
    v31 = dma_map_page_attrs(
            v25,
            ((unsigned __int64)((v28 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v28 & 0xFFF,
            v29,
            2,
            0);
    LODWORD(v25) = v31;
    goto LABEL_37;
  }
  if ( (v30 & 1) == 0 )
    goto LABEL_36;
LABEL_31:
  v31 = -1;
  LODWORD(v25) = -1;
LABEL_37:
  *(_QWORD *)(_X19 + 7400) = v31;
  _X8 = *((unsigned __int8 *)a1 + 68);
  *(_DWORD *)(_X19 + 7408) = *(unsigned __int16 *)(v7 + 16);
  if ( (_DWORD)_X8 != 1 )
  {
    result = 4294967201LL;
    goto LABEL_55;
  }
  v34 = _X19 + v60;
  result = ((__int64 (__fastcall *)(const char ***, __int64, __int64, _QWORD, _QWORD, __int64))ce_f8_setup)(
             a1,
             v7,
             1,
             0,
             *(unsigned __int16 *)(v7 + 16),
             _X19 + v60);
  *(_QWORD *)(_X19 + 7328) = a3;
  *(_QWORD *)(_X19 + 7304) = a4;
  *(_QWORD *)(_X19 + 7312) = 0;
  *(_DWORD *)(_X19 + 8) = 3;
  _X8 = v61;
  *(_DWORD *)(_X19 + 7412) = *(unsigned __int16 *)(v7 + 16);
  if ( v61 != 9 )
  {
    v35 = 0;
    v36 = (__int64)&a1[929 * v61 + 328];
    v37 = *((unsigned __int8 *)a1 + 68);
    *(_DWORD *)(v36 + 48) = 0;
    *(_DWORD *)(v36 + 80) = 0;
    if ( v37 == 1
      && (v38 = *(_DWORD **)(_X19 + 40),
          v39 = (unsigned __int64)a1[3] + *(_QWORD *)v34 - (_QWORD)a1[2],
          v40 = *(unsigned __int16 *)(v34 + 216) | (v39 >> 16) & 0xF0000 | 0xC000000,
          *v38 = v39,
          v38[1] = v40,
          v35 = (unsigned int)(*(_DWORD *)(_X19 + 48) + 1),
          *(_DWORD *)(_X19 + 48) = v35,
          (unsigned int)v35 >= 0x200) )
    {
      v55 = "_qce_sps_add_cmd";
    }
    else
    {
      v41 = *(unsigned __int16 *)(v7 + 16);
      if ( !*(_WORD *)(v7 + 16) )
      {
LABEL_48:
        if ( (_DWORD)v35 )
        {
          v45 = *(_QWORD *)(_X19 + 40) + 8LL * (unsigned int)(v35 - 1);
          *(_DWORD *)(v45 + 4) |= 0x50000000u;
        }
        result = qce_sps_add_cmd((__int64)a1, 0x200u, _X19 + 7040, _X19 + 32);
        if ( !(_DWORD)result )
        {
          result = qce_sps_add_data((__int64)a1, (unsigned int)v25, *(unsigned __int16 *)(v7 + 16), _X19 + 64, 0, 0);
          if ( !(_DWORD)result )
          {
            result = qce_sps_add_data(
                       (__int64)a1,
                       (char *)a1[3] + *(unsigned int *)(_X19 + 7264) - (char *)a1[2],
                       0x80u,
                       _X19 + 64,
                       0,
                       0);
            if ( !(_DWORD)result )
            {
              select_mode((__int64)a1, _X19);
              result = qce_sps_transfer((__int64)a1, v61);
              _X8 = (unsigned __int64)a1 + 69516;
              goto LABEL_69;
            }
          }
        }
        goto LABEL_55;
      }
      v42 = *(unsigned int *)(_X19 + 7392);
      v43 = (_DWORD *)(*(_QWORD *)(_X19 + 40) + 8LL * (unsigned int)v35);
      while ( (_DWORD)v35 != 512 )
      {
        if ( v41 >= 0x7FC0 )
          v44 = 32704;
        else
          v44 = v41;
        v41 -= v44;
        *v43 = v42;
        v43[1] = v44 | (v42 >> 16) & 0xF0000;
        v43 += 2;
        v42 += v44;
        v35 = (unsigned int)(*(_DWORD *)(_X19 + 48) + 1);
        *(_DWORD *)(_X19 + 48) = v35;
        if ( !v41 )
          goto LABEL_48;
      }
      v55 = "_qce_sps_add_data";
    }
    printk(&unk_15B74, v55, v35);
    result = 4294967284LL;
    goto LABEL_55;
  }
LABEL_68:
  while ( 1 )
  {
    __break(0x5512u);
LABEL_69:
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v57 = __ldxr((unsigned int *)_X8);
      if ( v57 != 1 )
        break;
      if ( !__stlxr(0, (unsigned int *)_X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( !(_DWORD)result )
      return result;
LABEL_55:
    v46 = *(_QWORD *)(_X19 + 7400);
    if ( v46 )
    {
      v47 = result;
      dma_unmap_page_attrs(*a1, v46, *(unsigned __int16 *)(v7 + 16), 2, 0);
      result = v47;
    }
    v48 = *(_QWORD *)(_X19 + 7392);
    if ( v48 )
    {
      v49 = *(_QWORD *)v7;
      v50 = *(_QWORD *)(v7 + 8);
      v51 = *(unsigned __int16 *)(v7 + 16);
      v7 = (unsigned int)result;
      dma_unmap_page_attrs(*a1, v48, v51, v49 != v50, 0);
      result = (unsigned int)v7;
    }
    v11 = v61;
    if ( v61 != 9 )
    {
      *(_DWORD *)(_X19 + 8) = 5;
      __asm { PRFM            #0x11, [X19] }
      do
        v53 = __ldxr((unsigned int *)_X19);
      while ( __stlxr(0, (unsigned int *)_X19) );
      __dmb(0xBu);
      if ( v53 )
        return result;
      goto LABEL_63;
    }
  }
}
