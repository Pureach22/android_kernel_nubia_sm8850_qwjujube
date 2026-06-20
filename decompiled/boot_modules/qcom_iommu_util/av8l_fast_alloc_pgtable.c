__int64 __fastcall av8l_fast_alloc_pgtable(unsigned __int64 a1)
{
  __int64 v2; // x24
  int v3; // w9
  int v4; // w8
  unsigned int v5; // w8
  char v6; // w9
  unsigned int v7; // w8
  int v8; // w9
  int v9; // w9
  int v10; // w9
  unsigned __int64 v11; // t2
  unsigned int v12; // w8
  unsigned __int64 v13; // x20
  unsigned __int64 v14; // x21
  __int64 *v15; // x25
  __int64 v16; // x22
  __int64 v17; // x8
  __int64 v18; // x0
  unsigned __int64 StatusReg; // x19
  unsigned __int64 v25; // x1
  unsigned __int64 v26; // x28
  __int64 v27; // x19
  unsigned __int64 v28; // x26
  __int64 v29; // x20
  unsigned __int64 v30; // x27
  __int64 v31; // x8
  unsigned __int64 v32; // x0
  unsigned __int64 v33; // x21
  __int64 v35; // x10
  int v36; // w11
  int v37; // w27
  unsigned __int64 v38; // x21
  unsigned __int64 v39; // x25
  signed int v40; // w22
  __int64 v41; // x8
  unsigned __int64 v42; // x0
  unsigned __int64 v43; // x20
  __int64 v45; // x3
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x10
  __int64 v49; // x8
  __int64 v50; // x11
  unsigned __int64 v51; // x9
  __int64 v52; // x8
  unsigned __int64 v53; // x12
  __int64 v54; // x9
  __int64 v55; // x19
  __int64 v56; // x22
  __int64 v57; // x8
  __int64 v59; // x0
  unsigned __int64 v60; // x19
  __int64 v61; // x20
  __int64 (__fastcall *v62)(_QWORD); // x0
  int v64; // [xsp+18h] [xbp-38h]
  unsigned __int64 v65; // [xsp+20h] [xbp-30h]
  __int64 *v66; // [xsp+38h] [xbp-18h]
  unsigned __int64 v67; // [xsp+40h] [xbp-10h]
  unsigned __int64 v68; // [xsp+48h] [xbp-8h]

  v2 = _kmalloc_cache_noprof(gen_pool_avail, 3264, 280);
  if ( !v2 )
    return v2;
  while ( 1 )
  {
    *(_QWORD *)(v2 + 160) = 0;
    *(_QWORD *)(v2 + 168) = 0;
    *(_QWORD *)(v2 + 128) = av8l_fast_map_pages;
    *(_QWORD *)(v2 + 136) = &av8l_fast_unmap_pages;
    *(_QWORD *)(v2 + 144) = av8l_fast_iova_to_phys;
    *(_QWORD *)(v2 + 152) = 0;
    v3 = *(unsigned __int8 *)(a1 + 32);
    *(_DWORD *)(a1 + 24) = 32;
    v4 = *(_DWORD *)(a1 + 80);
    *(_QWORD *)(v2 + 176) = 0;
    *(_QWORD *)(v2 + 184) = 0;
    *(_QWORD *)(v2 + 192) = 0;
    *(_QWORD *)(a1 + 16) = 4096;
    if ( v3 == 1 )
    {
      v5 = v4 & 0xFFFFF81F | 0x2E0;
      v6 = *(_BYTE *)(a1 + 8);
      *(_DWORD *)(a1 + 80) = v5;
      if ( (v6 & 0x40) != 0 )
      {
        __break(0x800u);
LABEL_80:
        kfree(v2);
        return 0;
      }
    }
    else
    {
      v7 = v4 & 0xFFFFF81F;
      v8 = (*(_BYTE *)(a1 + 8) & 0x40) != 0 ? 192 : 64;
      v5 = v7 | v8;
    }
    v9 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 80) = v5 & 0xFFFFFFE7;
    HIDWORD(v11) = v9 - 32;
    LODWORD(v11) = v9 - 32;
    v10 = v11 >> 1;
    if ( v10 > 4 )
    {
      switch ( v10 )
      {
        case 5:
          v12 = v5 & 0xFFFFFFE0 | 3;
          break;
        case 6:
          v12 = v5 & 0xFFFFFFE0 | 4;
          break;
        case 8:
          v12 = v5 & 0xFFFFFFE0 | 5;
          break;
        default:
          goto LABEL_80;
      }
    }
    else if ( v10 )
    {
      if ( v10 == 2 )
      {
        v12 = v5 & 0xFFFFFFE0 | 1;
      }
      else
      {
        if ( v10 != 4 )
          goto LABEL_80;
        v12 = v5 & 0xFFFFFFE0 | 2;
      }
    }
    else
    {
      v12 = v5 & 0xFFFFFFE0;
    }
    v14 = *(_QWORD *)(a1 + 136);
    v13 = *(_QWORD *)(a1 + 144);
    *(_DWORD *)(a1 + 80) = v12 & 0xFFFE07FF | 0x10000;
    *(_QWORD *)(a1 + 88) = -200999100;
    v68 = v13;
    v15 = (__int64 *)_kmalloc_large_noprof(16424, 73728);
    if ( !v15 )
    {
      v15 = (__int64 *)vmalloc_noprof(16424);
      if ( !v15 )
        goto LABEL_80;
    }
    v16 = _alloc_pages_noprof(3520, 0, 0, 0);
    if ( !v16 )
      goto LABEL_79;
    mod_node_page_state(&contig_page_data, 41, 1);
    v17 = *(_QWORD *)(v16 + 8);
    v18 = v16;
    if ( (v17 & 1) != 0 )
      v18 = v17 - 1;
    StatusReg = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    _lruvec_stat_mod_folio(v18, 40, 1);
    _WriteStatusReg(DAIF, StatusReg);
    *v15 = v16;
    v25 = ((v16 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
    *(_QWORD *)(v2 + 200) = v25;
    if ( v14 >= v13 )
      break;
    v26 = (unsigned int)v14 >> 30;
    v27 = v2 + 208;
    v28 = v13 - 1;
    v66 = v15;
    v67 = a1;
    v29 = 0;
    v30 = v14;
    v65 = v14;
    _ReadStatusReg(SP_EL0);
    do
    {
      a1 = _alloc_pages_noprof(3520, 0, 0, 0);
      if ( !a1 )
      {
        v37 = v29 + 1;
        goto LABEL_39;
      }
      mod_node_page_state(&contig_page_data, 41, 1);
      v31 = *(_QWORD *)(a1 + 8);
      v32 = a1;
      if ( (v31 & 1) != 0 )
        v32 = v31 - 1;
      v33 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      _lruvec_stat_mod_folio(v32, 40, 1);
      _WriteStatusReg(DAIF, v33);
      v15[v29 + 1] = a1;
      if ( (unsigned int)(5 - v26) - 1LL == v29 )
        goto LABEL_77;
      v35 = memstart_addr >> 6;
      *(_QWORD *)(v27 + 8 * v26 + 8 * v29) = ((a1 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL
                                           | 0xFF00000000000000LL;
      if ( (v30 | 0x3FFFFFFF) >= v28 )
        v30 = v68;
      else
        v30 = (v30 & 0xFFFFFFFFC0000000LL) + 0x40000000;
      *(_QWORD *)(*(_QWORD *)(v2 + 200) + 8 * v26 + 8 * v29++) = ((a1 + (v35 & 0x3FFFFFFFFFFFFC0LL) + 0x140000000LL) << 6)
                                                               | 3;
    }
    while ( v30 < v68 );
    v37 = v29 + 1;
    av8l_clean_range(v67, *(_QWORD *)(v2 + 200), *(_QWORD *)(v2 + 200) + 32LL);
    v38 = v65;
    v13 = v68;
    _ReadStatusReg(SP_EL0);
    v64 = v37;
    while ( 1 )
    {
      v39 = (v38 | 0x3FFFFFFF) >= v28 ? v13 : (v38 & 0xFFFFFFFFC0000000LL) + 0x40000000;
      if ( v38 < v39 )
        break;
LABEL_56:
      if ( v26 == 4 )
        goto LABEL_77;
      if ( 8 * v26 - 72 < 0xFFFFFFFFFFFFFEE8LL )
        goto LABEL_76;
      a1 = v67;
      av8l_clean_range(v67, *(_QWORD *)(v27 + 8 * v26), *(_QWORD *)(v27 + 8 * v26) + 4096LL);
      v13 = v68;
      ++v26;
      v38 = v39;
      if ( v39 >= v68 )
      {
        v15 = v66;
        v36 = v64;
        v14 = v65;
        goto LABEL_60;
      }
    }
    v40 = ((unsigned int)v38 >> 21) & 0x1FF;
    while ( 1 )
    {
      a1 = _alloc_pages_noprof(3520, 0, 0, 0);
      if ( !a1 )
        break;
      mod_node_page_state(&contig_page_data, 41, 1);
      v41 = *(_QWORD *)(a1 + 8);
      v42 = a1;
      if ( (v41 & 1) != 0 )
        v42 = v41 - 1;
      v43 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      _lruvec_stat_mod_folio(v42, 40, 1);
      _WriteStatusReg(DAIF, v43);
      if ( v37 == 2053 || (unsigned __int64)(8LL * v37) > 0x4028 )
        goto LABEL_76;
      v66[v37] = a1;
      av8l_clean_range(
        v67,
        ((a1 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL,
        (((a1 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + 4096);
      if ( v26 > 3 )
        goto LABEL_77;
      ++v37;
      if ( (v38 | 0x1FFFFF) >= v28 )
        v38 = v68;
      else
        v38 = (v38 & 0xFFFFFFFFFFE00000LL) + 0x200000;
      *(_QWORD *)(*(_QWORD *)(v27 + 8 * v26) + 8LL * v40++) = ((a1
                                                              + ((memstart_addr >> 6) & 0x3FFFFFFFFFFFFC0LL)
                                                              + 0x140000000LL) << 6)
                                                            | 3;
      if ( v38 >= v39 )
        goto LABEL_56;
    }
LABEL_39:
    v15 = v66;
LABEL_67:
    if ( v37 < 1 )
    {
LABEL_79:
      kvfree(v15);
      goto LABEL_80;
    }
    v55 = 0;
    while ( v55 != 2053 )
    {
      v56 = v15[v55];
      if ( v56 )
      {
        mod_node_page_state(&contig_page_data, 41, -1);
        v57 = *(_QWORD *)(v56 + 8);
        a1 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        if ( (v57 & 1) != 0 )
          v59 = v57 - 1;
        else
          v59 = v56;
        _lruvec_stat_mod_folio(v59, 40, 0xFFFFFFFFLL);
        _WriteStatusReg(DAIF, a1);
        _free_pages(v56, 0);
      }
      if ( v37 == ++v55 )
        goto LABEL_79;
    }
LABEL_76:
    __break(1u);
LABEL_77:
    __break(0x5512u);
    v60 = _ReadStatusReg(SP_EL0);
    v61 = *(_QWORD *)(v60 + 80);
    v62 = gen_pool_avail;
    *(_QWORD *)(v60 + 80) = &av8l_fast_alloc_pgtable_data__alloc_tag;
    v2 = _kmalloc_cache_noprof(v62, 3264, 280);
    *(_QWORD *)(v60 + 80) = v61;
    if ( !v2 )
      return v2;
  }
  av8l_clean_range(a1, v25, v25 + 32);
  v36 = 1;
  v37 = 1;
LABEL_60:
  if ( arm64_use_ng_mappings )
    v45 = 0x68000000000F03LL;
  else
    v45 = 0x68000000000703LL;
  v46 = vmap(&v15[v36], (unsigned int)(v37 - v36), 1, v45);
  *(_QWORD *)(v2 + 240) = v46;
  if ( !v46 )
    goto LABEL_67;
  v47 = *(_QWORD *)(v2 + 200);
  v48 = memstart_addr;
  *(_QWORD *)(v2 + 248) = v15;
  v49 = v47 << 8 >> 8;
  v50 = kimage_voffset;
  *(_QWORD *)(v2 + 264) = v14;
  *(_QWORD *)(v2 + 272) = v13;
  *(_DWORD *)(v2 + 256) = v37;
  v51 = v49 + 0x8000000000LL;
  v52 = v49 - v50;
  v53 = v51 >> 38;
  v54 = v51 + v48;
  if ( !v53 )
    v52 = v54;
  *(_QWORD *)(a1 + 72) = v52;
  return v2;
}
