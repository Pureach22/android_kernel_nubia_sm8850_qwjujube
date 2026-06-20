__int64 __fastcall kgsl_alloc_pages(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v4; // x20
  _QWORD *v5; // x22
  unsigned __int64 v6; // x23
  unsigned __int64 v7; // x0
  unsigned int v8; // w24
  __int64 v9; // x8
  unsigned __int64 v10; // x9
  bool v11; // cc
  unsigned __int64 v12; // x26
  __int64 v13; // x27
  int v14; // w28
  unsigned int v15; // w25
  unsigned __int64 StatusReg; // x10
  unsigned __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x2
  unsigned __int64 mapping_page_gfp; // x0
  unsigned __int64 v21; // x24
  __int64 v22; // x26
  unsigned __int64 v23; // x8
  unsigned int v24; // w9
  unsigned int v25; // w24
  unsigned int v26; // w9
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x25
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x9
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x10
  unsigned __int64 v35; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x9
  unsigned __int64 v38; // x9
  __int64 v39; // x10
  unsigned __int64 v40; // x11
  _QWORD *v41; // x8
  unsigned __int64 v42; // x10
  __int64 v43; // x11
  __int64 *v44; // x10
  __int64 v45; // x11
  unsigned __int64 v46; // x9
  unsigned __int64 v47; // x12
  __int64 v48; // x25
  char v49; // w10
  unsigned __int64 v50; // x8
  __int64 v51; // x8
  unsigned __int64 v52; // x11
  unsigned __int64 v53; // x24
  __int64 v54; // x0
  _QWORD *i; // x9
  _QWORD *v56; // x8
  __int64 v57; // x10
  unsigned __int64 v58; // x23
  unsigned __int64 v59; // x21
  unsigned __int64 v60; // x8
  __int64 v61; // x22
  __int64 v62; // x0
  unsigned __int64 v69; // x9
  unsigned __int64 v70; // [xsp+8h] [xbp-58h]
  unsigned __int64 v71; // [xsp+18h] [xbp-48h]
  int v72; // [xsp+20h] [xbp-40h]
  unsigned int v73; // [xsp+24h] [xbp-3Ch]
  unsigned __int64 v74; // [xsp+28h] [xbp-38h]
  _QWORD *v75; // [xsp+30h] [xbp-30h]
  unsigned __int64 v76; // [xsp+38h] [xbp-28h] BYREF
  __int64 v77; // [xsp+40h] [xbp-20h]
  __int64 v78; // [xsp+48h] [xbp-18h]
  __int64 v79; // [xsp+50h] [xbp-10h]
  __int64 v80; // [xsp+58h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ((*(_QWORD *)(a1 + 40) >> 12 << 32) & 0x8000000000000000LL) != 0 )
    goto LABEL_120;
  v4 = (8LL * (*(_QWORD *)(a1 + 40) >> 12)) & 0x7FFFFFFFFLL;
  v5 = (_QWORD *)_kvmalloc_node_noprof(v4, 0, 3520, 0xFFFFFFFFLL);
  if ( !v5 )
    goto LABEL_120;
  while ( 2 )
  {
    v6 = *(_QWORD *)(a1 + 40);
    if ( a1 && (*(_DWORD *)(a1 + 48) & 0x10) != 0 )
    {
      if ( !v6 )
      {
LABEL_105:
        v14 = 0;
LABEL_106:
        *(_QWORD *)a2 = v5;
        v8 = v14;
        if ( *(_QWORD *)(a1 + 112) )
        {
LABEL_107:
          for ( i = *(_QWORD **)(a1 + 192); i != (_QWORD *)(a1 + 192); i = *(_QWORD **)(a1 + 192) )
          {
            v56 = (_QWORD *)i[1];
            if ( (_QWORD *)*v56 == i && (v57 = *i, *(_QWORD **)(*i + 8LL) == i) )
            {
              *(_QWORD *)(v57 + 8) = v56;
              *v56 = v57;
            }
            else
            {
              _list_del_entry_valid_or_report(i);
            }
            *i = 0xDEAD000000000100LL;
            i[1] = 0xDEAD000000000122LL;
            kgsl_free_page(a1, i - 1);
          }
        }
        goto LABEL_121;
      }
    }
    else
    {
      v7 = shmem_file_setup("kgsl-3d0", *(_QWORD *)(a1 + 40), 0x200000);
      v8 = v7;
      *(_QWORD *)(a1 + 112) = v7;
      if ( v7 > 0xFFFFFFFFFFFFF000LL )
      {
        *(_QWORD *)(a1 + 112) = 0;
        kvfree(v5);
        goto LABEL_121;
      }
      *(_QWORD *)(a1 + 192) = a1 + 192;
      *(_QWORD *)(a1 + 200) = a1 + 192;
      *(_QWORD *)(**(_QWORD **)(v7 + 24) + 704LL) = a1;
      v9 = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 24LL);
LABEL_123:
      _X8 = (unsigned __int64 *)(v9 + 144);
      __asm { PRFM            #0x11, [X8] }
      do
        v69 = __ldxr(_X8);
      while ( __stxr(v69 | 8, _X8) );
      if ( !v6 )
        goto LABEL_105;
    }
    v70 = a2;
    a2 = 1LL << ((unsigned __int8)__clz(v6) ^ 0x3Fu);
    if ( (unsigned int)a2 <= 0x1000 )
    {
      a2 = 4096;
    }
    else
    {
      v10 = (unsigned int)a2;
      while ( v10 > v6 || (a2 & 0x1FFFFF) == 0 )
      {
        v10 = (unsigned int)a2 >> 1;
        v11 = (unsigned int)a2 > 0x2001;
        a2 = (unsigned int)v10;
        if ( !v11 )
        {
          a2 = 4096;
          break;
        }
      }
    }
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v71 = v4 + 1;
    v15 = (*(_QWORD *)(a1 + 40) >> 12) - *(_DWORD *)(a1 + 104);
    v72 = 0;
    v73 = 20;
    StatusReg = _ReadStatusReg(SP_EL0);
    v74 = StatusReg;
    v75 = v5;
    while ( 1 )
    {
      if ( (*(_QWORD *)StatusReg & 1) != 0 )
      {
        v17 = *(unsigned __int8 *)(StatusReg + 2449);
        if ( (v17 & 1) != 0 )
          goto LABEL_93;
      }
      v18 = *(_QWORD *)(a1 + 112);
      if ( !v18 )
        break;
      if ( kgsl_sharedmem_noretry_flag )
        v19 = 76994;
      else
        v19 = 3266;
      mapping_page_gfp = shmem_read_mapping_page_gfp(*(_QWORD *)(v18 + 24), (unsigned int)v14, v19);
      v21 = mapping_page_gfp;
      if ( mapping_page_gfp < 0xFFFFFFFFFFFFF001LL )
      {
        if ( *(_QWORD *)(a1 + 40) == 4096 || *(_QWORD *)(a1 + 192) == a1 + 192 && v15 >= 2 )
          clear_page(((mapping_page_gfp << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL);
        v48 = *(_QWORD *)(a1 + 80);
        if ( v48 )
        {
          v78 = 0;
          v79 = 0;
          v76 = 0;
          v77 = 0;
          sg_init_table(&v76, 1);
          if ( (v21 & 3) != 0 )
          {
            __break(0x800u);
            goto LABEL_123;
          }
          v76 = v76 & 3 | v21;
          v49 = *(_BYTE *)(v48 + 844);
          v77 = 0x100000000000LL;
          v78 = ((v21 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
          if ( (v49 & 0x40) == 0 )
            _dma_sync_sg_for_device(v48, &v76, 1, 1);
        }
        v17 = v4 - v12;
        if ( v4 < v12 || v17 < 8 )
          goto LABEL_117;
        *v5 = v21;
        v5 = v75;
        LODWORD(v21) = 1;
        LODWORD(a2) = 4096;
LABEL_71:
        v6 -= (unsigned int)a2;
        v14 += v21;
        *(_DWORD *)(a1 + 104) += v21;
        if ( !v6 )
        {
          a2 = v70;
          goto LABEL_106;
        }
        a2 = 1LL << ((unsigned __int8)__clz(v6) ^ 0x3Fu);
        if ( (unsigned int)a2 <= 0x1000 )
        {
          StatusReg = v74;
LABEL_80:
          a2 = 4096;
        }
        else
        {
          StatusReg = v74;
          v50 = (unsigned int)a2;
          while ( v50 > v6 || __clz(__rbit32(a2)) > v73 )
          {
            v50 = (unsigned int)a2 >> 1;
            v11 = (unsigned int)a2 > 0x2001;
            a2 = (unsigned int)v50;
            if ( !v11 )
              goto LABEL_80;
          }
        }
        goto LABEL_19;
      }
      v5 = v75;
LABEL_57:
      if ( (_DWORD)v21 == -11 )
      {
        StatusReg = v74;
        goto LABEL_19;
      }
      if ( (int)v21 > 0 )
        goto LABEL_71;
LABEL_90:
      v17 = ((_DWORD)v21 != -12) | (unsigned int)v72;
      if ( ((_DWORD)v21 != -12) | v72 & 1 )
        goto LABEL_93;
      _flush_workqueue(qword_3A908);
      StatusReg = v74;
      v72 = 1;
LABEL_19:
      v12 = 8LL * v14;
      v13 = v14;
      v17 = *(_QWORD *)(a1 + 40) >> 12;
      v5 = (_QWORD *)((char *)v5 + v12);
      v15 = v17 - *(_DWORD *)(a1 + 104);
      if ( !v5 )
        goto LABEL_93;
    }
    v22 = *(_QWORD *)(a1 + 80);
    v23 = (int)a2 - 1LL;
    v24 = 64 - __clz(v23 >> 12);
    if ( v23 >= 0x1000 )
      v25 = v24;
    else
      v25 = 0;
    if ( v25 )
      v26 = 335874;
    else
      v26 = 3266;
    if ( kgsl_sharedmem_noretry_flag )
      v27 = v26 | 0x12000;
    else
      v27 = v26;
    v28 = _alloc_pages_noprof(v27, v25, 0, 0);
    v29 = v28;
    if ( !v28 )
    {
      if ( v25 )
      {
        v5 = v75;
        v51 = 1LL << ((52 - v25) ^ 0x3F);
        a2 = 4096;
        if ( (unsigned int)v51 > 0x1000 )
        {
          v52 = (unsigned int)(1LL << ((52 - v25) ^ 0x3F));
          while ( v52 > 4096LL << ((unsigned __int8)v25 - 1) || __clz(__rbit32(v51)) > v25 + 11 )
          {
            v52 = (unsigned int)v51 >> 1;
            v11 = (unsigned int)v51 > 0x2001;
            LODWORD(v51) = (unsigned int)v51 >> 1;
            if ( !v11 )
            {
              a2 = 4096;
              goto LABEL_92;
            }
          }
          a2 = (unsigned int)v51;
        }
LABEL_92:
        StatusReg = v74;
        v73 = 31 - __clz(a2);
        goto LABEL_19;
      }
      v5 = v75;
      LODWORD(v21) = -12;
      goto LABEL_90;
    }
    kgsl_zero_page(v28, v25, v22);
    if ( (int)a2 >= 4096 )
    {
      v30 = 8 * v13;
      v21 = (unsigned int)a2 >> 12;
      v31 = v4 - 8 * v13;
      _CF = v31 <= 7;
      v33 = 7 - v31;
      if ( !_CF )
        v33 = 0;
      v34 = v71 - v30;
      v35 = v4 + v33;
      if ( v71 < v30 )
        v34 = 0;
      v36 = (v35 - v30) >> 3;
      if ( v36 >= (v34 + 7) >> 3 )
        v36 = (v34 + 7) >> 3;
      v37 = 0;
      if ( v21 - 1 < v36 )
        v36 = v21 - 1;
      if ( v36 >= 2 )
      {
        v38 = v36 + 1;
        v39 = (v36 + 1) & 1;
        if ( !v39 )
          v39 = 2;
        v40 = ~v36;
        v41 = v5 + 1;
        v37 = v38 - v39;
        v42 = v40 + v39;
        v43 = v29;
        do
        {
          v42 += 2LL;
          *(v41 - 1) = v43;
          *v41 = v43 + 64;
          v41 += 2;
          v43 += 128;
        }
        while ( v42 );
      }
      v44 = &v5[v37];
      v45 = v29 + (v37 << 6);
      v17 = 8 * (v13 + v37);
      v5 = v75;
      v46 = v21 - v37;
      v47 = v4 - v17;
      while ( v4 >= v17 )
      {
        _CF = v47 >= 8;
        v47 -= 8LL;
        if ( !_CF )
          break;
        *v44++ = v45;
        --v46;
        v17 += 8LL;
        v45 += 64;
        if ( !v46 )
          goto LABEL_57;
      }
      goto LABEL_117;
    }
LABEL_93:
    if ( v14 < 1 )
    {
LABEL_99:
      kvfree(v75);
      if ( (kgsl_sharedmem_noretry_flag & 1) == 0
        && (unsigned int)__ratelimit(&kgsl_alloc_pages__rs, "_kgsl_alloc_pages") )
      {
        printk(&unk_13A91F);
        v54 = *(_QWORD *)(a1 + 112);
        if ( !v54 )
        {
LABEL_103:
          v8 = -12;
          if ( *(_QWORD *)(a1 + 112) )
            goto LABEL_107;
          goto LABEL_121;
        }
      }
      else
      {
        v54 = *(_QWORD *)(a1 + 112);
        if ( !v54 )
          goto LABEL_103;
      }
      fput(v54);
      goto LABEL_103;
    }
    a2 = 0;
    v53 = v4;
    while ( v4 >= a2 )
    {
      _CF = v53 >= 8;
      v53 -= 8LL;
      if ( !_CF )
        break;
      kgsl_free_page(a1, *(_QWORD *)((char *)v75 + a2));
      a2 += 8LL;
      if ( 8LL * (unsigned int)v14 == a2 )
        goto LABEL_99;
    }
LABEL_117:
    __break(1u);
    v58 = a2;
    v59 = _ReadStatusReg(SP_EL0);
    v60 = v17 << 32;
    v61 = *(_QWORD *)(v59 + 80);
    *(_QWORD *)(v59 + 80) = &kgsl_alloc_pages__alloc_tag;
    if ( (v60 & 0x8000000000000000LL) != 0 )
    {
      v4 = 0;
      v62 = 0;
    }
    else
    {
      v4 = v60 >> 29;
      v62 = _kvmalloc_node_noprof(v60 >> 29, 0, 3520, 0xFFFFFFFFLL);
    }
    *(_QWORD *)(v59 + 80) = v61;
    v5 = (_QWORD *)v62;
    a2 = v58;
    if ( v62 )
      continue;
    break;
  }
LABEL_120:
  v8 = -12;
LABEL_121:
  _ReadStatusReg(SP_EL0);
  return v8;
}
