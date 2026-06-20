__int64 __fastcall qce_ablk_cipher_req(__int64 a1, __int64 a2)
{
  __int64 v3; // x23
  unsigned int *v4; // x26
  unsigned int v7; // w0
  unsigned int v8; // w19
  __int64 v9; // x27
  unsigned int v10; // w3
  int v11; // w9
  int v12; // w8
  unsigned int v13; // w8
  int v14; // w8
  __int64 v15; // x0
  int v16; // w28
  __int64 v17; // x24
  __int64 v18; // x25
  __int64 v19; // x0
  int v20; // w25
  __int64 v21; // x24
  int v22; // w8
  int v23; // w8
  int v24; // w9
  __int64 v25; // x2
  int v26; // w3
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 v30; // x9
  __int64 v31; // x12
  __int64 v32; // x11
  __int64 v33; // x10
  __int64 v34; // x9
  __int64 v35; // x24
  int v36; // w0
  int v37; // w8
  __int64 v38; // x8
  int v39; // w9
  __int64 v40; // x2
  __int64 v41; // x8
  _DWORD *v42; // x11
  unsigned __int64 v43; // x8
  int v44; // w9
  unsigned int v45; // w8
  unsigned __int64 v46; // x9
  _DWORD *v47; // x10
  __int64 v48; // x13
  __int64 v49; // x8
  unsigned __int64 v50; // x8
  _DWORD *v51; // x9
  int v52; // w10
  unsigned int v53; // w9
  __int64 v54; // x14
  char v55; // w10
  unsigned __int64 v56; // x11
  _DWORD *v57; // x12
  unsigned int v58; // w15
  int v59; // w8
  unsigned int *v60; // x8
  const char *v61; // x1
  int v62; // w25
  __int64 v63; // x24
  int v64; // w25
  __int64 v65; // x24
  unsigned int v70; // w9
  unsigned int v73; // w10

  v4 = *(unsigned int **)(a2 + 24);
  _X22 = a2;
  v7 = qce_alloc_req_info();
  if ( (v7 & 0x80000000) != 0 )
  {
    LODWORD(v3) = -16;
    return (unsigned int)v3;
  }
  v8 = v7;
  *(_DWORD *)(_X22 + 176) = v7;
  if ( v7 >= 0xA )
    goto LABEL_126;
  v9 = a1 + 2624;
  v10 = *(_DWORD *)(_X22 + 156);
  _X20 = a1 + 2624 + 7432LL * v7;
  v11 = *(unsigned __int8 *)(a1 + 73);
  *(_DWORD *)(_X20 + 7416) = v10;
  v12 = *(_DWORD *)(_X22 + 152);
  *(_BYTE *)(_X20 + 7428) = v12 == 2;
  if ( v11 == 1 && v12 == 2 )
  {
    v13 = 0;
  }
  else if ( v10 >= 6 )
  {
    printk(&unk_14FD3, "qce_choose_pipe_from_op", v7);
    v10 = 0;
    v13 = 0;
    *(_DWORD *)(_X20 + 7416) = 0;
  }
  else
  {
    v13 = v10;
  }
  *(_DWORD *)(_X20 + 7420) = v13;
  v14 = *(_DWORD *)(_X22 + 116);
  if ( v14 == -1 )
  {
    if ( v10 > 5 )
      goto LABEL_126;
    v14 = legacy_op_to_key_index[v10];
  }
  *(_DWORD *)(_X20 + 7424) = v14;
  *(_QWORD *)(_X20 + 7352) = 0;
  LODWORD(v3) = *v4;
  if ( (int)*v4 < 1 )
  {
    v16 = 0;
  }
  else
  {
    v15 = *((_QWORD *)v4 + 2);
    v16 = 0;
    do
    {
      ++v16;
      LODWORD(v3) = v3 - *(_DWORD *)(v15 + 12);
      v15 = ((__int64 (*)(void))sg_next)();
    }
    while ( (int)v3 > 0 );
  }
  *(_DWORD *)(_X20 + 7352) = v16;
  if ( (*(_BYTE *)(_X22 + 180) & 1) == 0 )
  {
    *(_BYTE *)(_X20 + 7430) = 1;
    v17 = *((_QWORD *)v4 + 2);
    LODWORD(v3) = v17 != *((_QWORD *)v4 + 3);
    if ( v16 >= 1 )
    {
      v18 = *(_QWORD *)a1;
      do
      {
        if ( !v17 )
          break;
        dma_map_sg_attrs(v18, v17, 1, (unsigned int)v3, 0);
        --v16;
        v17 = sg_next(v17);
      }
      while ( v16 );
    }
  }
  v19 = *((_QWORD *)v4 + 3);
  if ( *((_QWORD *)v4 + 2) == v19 )
  {
    v22 = *(_DWORD *)(_X20 + 7352);
LABEL_34:
    *(_DWORD *)(_X20 + 7356) = v22;
    goto LABEL_35;
  }
  LODWORD(v3) = *v4;
  if ( (int)*v4 < 1 )
  {
    v22 = 0;
    goto LABEL_34;
  }
  v20 = 0;
  do
  {
    ++v20;
    LODWORD(v3) = v3 - *(_DWORD *)(v19 + 12);
    v19 = sg_next(v19);
  }
  while ( (int)v3 > 0 );
  *(_DWORD *)(_X20 + 7356) = v20;
  if ( (*(_BYTE *)(_X22 + 180) & 1) == 0 && (unsigned int)(v20 - 1) <= 0x7FFFFFFE )
  {
    v3 = *(_QWORD *)a1;
    v21 = *((_QWORD *)v4 + 3);
    do
    {
      if ( !v21 )
        break;
      dma_map_sg_attrs(v3, v21, 1, 2, 0);
      --v20;
      v21 = sg_next(v21);
    }
    while ( v20 );
  }
LABEL_35:
  v23 = *(_DWORD *)(_X22 + 36);
  v24 = *(_DWORD *)(a1 + 404);
  *(_DWORD *)(_X20 + 7384) = v23;
  if ( !v24 && *(_DWORD *)(a1 + 408) <= 5u && v23 == 1 && !*(_DWORD *)(_X22 + 40) )
  {
    v30 = *((_QWORD *)v4 + 2);
    v31 = *(unsigned int *)(v30 + 12);
    v32 = ((*(_QWORD *)v30 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL;
    v33 = *(_QWORD *)((v32 | 0xFF00000000000000LL) + *(unsigned int *)(v30 + 8) + v31 - 8);
    *(_QWORD *)(_X20 + 7368) = *(_QWORD *)((v32 | 0xFF00000000000000LL) + *(unsigned int *)(v30 + 8) + v31 - 16);
    *(_QWORD *)(_X20 + 7376) = v33;
  }
  if ( *(_BYTE *)(a1 + 68) != 1 )
  {
    LODWORD(v3) = -95;
    goto LABEL_109;
  }
  v25 = *(unsigned int *)(_X22 + 32);
  v26 = *(_DWORD *)(_X22 + 40);
  if ( (_DWORD)v25 != 2 )
  {
    if ( (_DWORD)v25 != 1 )
    {
      if ( !(_DWORD)v25 )
      {
        _ZF = v26 == 1;
        v28 = 1344;
        v29 = 1568;
        goto LABEL_52;
      }
LABEL_102:
      printk(&unk_14AF2, "qce_ablk_cipher_req", v25);
      qce_free_req_info(a1, v8, 0, v60);
      LODWORD(v3) = -22;
      return (unsigned int)v3;
    }
    _ZF = v26 == 1;
    v28 = 1792;
    v29 = 2016;
LABEL_52:
    if ( _ZF )
      v28 = v29;
    goto LABEL_54;
  }
  if ( v26 <= 1 )
  {
    if ( v26 )
    {
      if ( v26 != 1 )
        goto LABEL_102;
      v29 = 448;
      _ZF = *(_DWORD *)(_X22 + 112) == 16;
      v28 = 672;
      goto LABEL_52;
    }
  }
  else if ( v26 != 2 )
  {
    if ( v26 == 3 )
    {
      v29 = 896;
      _ZF = (*(_DWORD *)(_X22 + 112) & 0xFFFFFFFE) == 32;
      v28 = 1120;
    }
    else
    {
      if ( v26 != 4 )
        goto LABEL_102;
      v29 = 5376;
      _ZF = *(_DWORD *)(_X22 + 112) == 16;
      v28 = 5600;
    }
    goto LABEL_52;
  }
  v28 = 224;
  if ( *(_DWORD *)(_X22 + 112) == 16 )
    v28 = 0;
LABEL_54:
  v34 = v9 + 7432LL * v8 + 96;
  v35 = v34 + v28;
  if ( !(v34 + v28) )
    goto LABEL_102;
  v36 = ce_setup_cipher(a1, _X22, *v4, 0, v34 + v28);
  if ( v36 < 0 )
  {
    LODWORD(v3) = v36;
    goto LABEL_109;
  }
  v37 = *(_DWORD *)(_X22 + 40);
  *(_QWORD *)(_X20 + 7328) = v4;
  *(_DWORD *)(_X20 + 7388) = v37;
  *(_QWORD *)(_X20 + 7304) = *(_QWORD *)(_X22 + 8);
  v38 = *(_QWORD *)(_X22 + 16);
  *(_DWORD *)(_X20 + 8) = 1;
  *(_QWORD *)(_X20 + 7312) = v38;
  *(_DWORD *)(_X20 + 7412) = *v4;
  if ( v8 == 9 )
    goto LABEL_126;
  v39 = *(unsigned __int8 *)(a1 + 68);
  v40 = 0;
  v41 = v9 + 7432LL * v8;
  *(_DWORD *)(v41 + 48) = 0;
  *(_DWORD *)(v41 + 80) = 0;
  if ( v39 == 1 )
  {
    v42 = *(_DWORD **)(_X20 + 40);
    v43 = *(_QWORD *)v35 - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24);
    v44 = *(unsigned __int16 *)(v35 + 216) | (v43 >> 16) & 0xF0000 | 0xC000000;
    *v42 = v43;
    v42[1] = v44;
    v40 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
    *(_DWORD *)(_X20 + 48) = v40;
    if ( (unsigned int)v40 >= 0x200 )
      goto LABEL_105;
  }
  v45 = *v4;
  if ( *v4 )
  {
    v46 = *(_QWORD *)(*((_QWORD *)v4 + 2) + 16LL);
    v47 = (_DWORD *)(*(_QWORD *)(_X20 + 40) + 8LL * (unsigned int)v40);
    while ( (_DWORD)v40 != 512 )
    {
      if ( v45 >= 0x7FC0 )
        v48 = 32704;
      else
        v48 = v45;
      v45 -= v48;
      *v47 = v46;
      v47[1] = v48 | (v46 >> 16) & 0xF0000;
      v47 += 2;
      v46 += v48;
      v40 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
      *(_DWORD *)(_X20 + 48) = v40;
      if ( !v45 )
        goto LABEL_66;
    }
    v61 = "_qce_sps_add_data";
LABEL_108:
    printk(&unk_15B74, v61, v40);
    LODWORD(v3) = -12;
    goto LABEL_109;
  }
LABEL_66:
  _X22 = a1 + 69516;
  if ( (_DWORD)v40 )
  {
    v49 = *(_QWORD *)(_X20 + 40) + 8LL * (unsigned int)(v40 - 1);
    *(_DWORD *)(v49 + 4) |= 0x50000000u;
  }
  if ( *(_DWORD *)(a1 + 408) == 6
    && !*(_DWORD *)(a1 + 404)
    && !*(_DWORD *)(a1 + 412)
    && *(_BYTE *)(a1 + 70304) == 1
    && (*(_BYTE *)(_X20 + 48) & 1) == 0 )
  {
    LODWORD(v3) = qce_sps_add_cmd(a1, 0, _X20 + 7040, _X20 + 32);
    if ( (_DWORD)v3 )
      goto LABEL_109;
  }
  if ( *(_BYTE *)(a1 + 128) == 1 )
  {
    v50 = *(_QWORD *)(_X20 + 7040) - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24);
    v51 = (_DWORD *)(*(_QWORD *)(_X20 + 40) + 8LL * *(unsigned int *)(_X20 + 48));
    v52 = *(unsigned __int16 *)(_X20 + 7256) | 0xA000000 | (v50 >> 16) & 0xF0000;
    *v51 = v50;
    v51[1] = v52;
    v40 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
    *(_DWORD *)(_X20 + 48) = v40;
    if ( (unsigned int)v40 >= 0x200 )
    {
LABEL_105:
      v61 = "_qce_sps_add_cmd";
      goto LABEL_108;
    }
  }
  v53 = *v4;
  if ( *v4 )
  {
    v54 = *(unsigned int *)(_X20 + 80);
    v55 = *(_BYTE *)(_X20 + 7429);
    v56 = *(_QWORD *)(*((_QWORD *)v4 + 3) + 16LL);
    v57 = (_DWORD *)(*(_QWORD *)(_X20 + 72) + 8 * v54);
    while ( (_DWORD)v54 != 512 )
    {
      v58 = 32704;
      if ( v53 <= 0x7FC0 )
      {
        v58 = v53;
        if ( *(_DWORD *)(a1 + 408) == 6 )
        {
          v58 = v53;
          if ( !*(_DWORD *)(a1 + 404) )
          {
            v58 = v53;
            if ( !*(_DWORD *)(a1 + 412) )
            {
              v58 = v53;
              if ( *(_BYTE *)(a1 + 70304) == 1 )
              {
                if ( (v54 & 1) != 0 )
                  v58 = v53 >> v55;
                else
                  v58 = v53 >> (v55 ^ 1);
              }
            }
          }
        }
      }
      v53 -= v58;
      *v57 = v56;
      v57[1] = v58 | (v56 >> 16) & 0xF0000;
      v57 += 2;
      v56 += v58;
      LODWORD(v54) = *(_DWORD *)(_X20 + 80) + 1;
      *(_DWORD *)(_X20 + 80) = v54;
      if ( !v53 )
        goto LABEL_95;
    }
    v61 = "_qce_sps_add_data";
    v40 = 512;
    goto LABEL_108;
  }
LABEL_95:
  if ( (*(_BYTE *)(a1 + 128) & 1) != 0 || *v4 <= 0x7FC0 )
  {
    v59 = *(unsigned __int8 *)(_X20 + 7429);
    *(_DWORD *)(_X20 + 16) = 2;
    if ( v59 == 1 )
    {
      LODWORD(v3) = qce_sps_add_data(
                      a1,
                      *(_QWORD *)(a1 + 24) + *(unsigned int *)(_X20 + 7264) - *(_QWORD *)(a1 + 16),
                      128,
                      _X20 + 64,
                      0,
                      0);
      if ( (_DWORD)v3 )
        goto LABEL_109;
    }
  }
  else
  {
    *(_DWORD *)(_X20 + 16) = 0;
  }
  select_mode(a1, a1 + 2624 + 7432LL * v8);
  LODWORD(v3) = qce_sps_transfer(a1, v8);
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X22] }
    while ( 1 )
    {
      v73 = __ldxr((unsigned int *)_X22);
      if ( v73 != 1 )
        break;
      if ( !__stlxr(0, (unsigned int *)_X22) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( !(_DWORD)v3 )
      return (unsigned int)v3;
LABEL_109:
    if ( *(_BYTE *)(_X20 + 7430) == 1 )
    {
      _X22 = *((_QWORD *)v4 + 3);
      if ( *((_QWORD *)v4 + 2) != _X22 )
      {
        v62 = *(_DWORD *)(_X20 + 7356);
        if ( v62 > 0 )
        {
          v63 = *(_QWORD *)a1;
          do
          {
            if ( !_X22 )
              break;
            dma_unmap_sg_attrs(v63, _X22, 1, 2, 0);
            --v62;
            _X22 = sg_next(_X22);
          }
          while ( v62 );
        }
      }
      v64 = *(_DWORD *)(_X20 + 7352);
      if ( v64 )
      {
        v65 = *((_QWORD *)v4 + 2);
        _X22 = v65 != *((_QWORD *)v4 + 3);
        if ( v64 >= 1 )
        {
          a1 = *(_QWORD *)a1;
          do
          {
            if ( !v65 )
              break;
            dma_unmap_sg_attrs(a1, v65, 1, (unsigned int)_X22, 0);
            --v64;
            v65 = sg_next(v65);
          }
          while ( v64 );
        }
      }
    }
    if ( v8 != 9 )
    {
      *(_DWORD *)(_X20 + 8) = 5;
      __asm { PRFM            #0x11, [X20] }
      do
        v70 = __ldxr((unsigned int *)_X20);
      while ( __stlxr(0, (unsigned int *)_X20) );
      __dmb(0xBu);
      if ( !v70 )
        printk(&unk_15B49, "qce_free_req_info", v8);
      return (unsigned int)v3;
    }
LABEL_126:
    __break(0x5512u);
  }
}
