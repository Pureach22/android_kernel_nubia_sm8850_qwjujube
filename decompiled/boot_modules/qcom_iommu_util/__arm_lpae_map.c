__int64 __fastcall _arm_lpae_map(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        __int64 a8,
        unsigned __int64 *a9,
        __int64 a10,
        unsigned int a11,
        _QWORD *a12,
        __int64 *a13)
{
  int v13; // w8
  int v14; // w22
  __int64 *v15; // x27
  char v16; // w9
  __int64 v18; // x24
  int v19; // w11
  unsigned int v20; // w10
  __int64 *v21; // x20
  __int64 v22; // x24
  __int64 v23; // x0
  __int64 v24; // x9
  __int64 v25; // x27
  unsigned __int64 v26; // x8
  __int64 v27; // x9
  int v28; // w26
  __int64 v29; // x25
  __int64 v30; // x23
  _QWORD *v31; // x21
  unsigned int v32; // w22
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x25
  unsigned __int64 v36; // x12
  __int64 v37; // x9
  __int64 v38; // x8
  __int64 v39; // x26
  __int64 v40; // x22
  __int64 v41; // x24
  int v42; // w27
  int v43; // w8
  __int64 v44; // x22
  __int64 i; // x10
  __int64 v46; // x8
  __int64 j; // x10
  __int64 v49; // x26
  unsigned __int64 v50; // x25
  __int64 v51; // x0
  unsigned __int64 v52; // x24
  __int64 v53; // x0
  __int64 v54; // x9
  __int64 v55; // x26
  unsigned __int64 v56; // x8
  __int64 v57; // x9
  __int64 v58; // x27
  int v59; // w25
  int v60; // w24
  __int64 v61; // x10
  unsigned __int64 v62; // x9
  int v63; // w8
  __int64 v64; // x10
  unsigned __int64 v66; // x11
  __int64 result; // x0
  __int64 v68; // x0
  void (__fastcall *v69)(__int64, unsigned __int64, unsigned __int64, __int64); // x8
  __int64 v70; // x8
  unsigned __int64 v71; // x11
  __int64 v72; // x8
  unsigned __int64 v73; // x1
  __int64 v74; // x9
  __int64 v75; // x13
  __int64 v76; // x14
  __int64 v77; // x15
  __int64 *v78; // x17
  __int64 v79; // x0
  __int64 v80; // x8
  __int64 v81; // x19
  unsigned __int64 v82; // x12
  __int64 v83; // x9
  __int64 v84; // x8
  int v85; // w20
  __int64 v86; // x1
  unsigned int v87; // w9
  __int64 v88; // x8
  __int64 v89; // x11
  __int64 v90; // x12
  __int64 v91; // x13
  __int64 *v92; // x15
  __int64 v93; // x0
  __int64 v94; // x8
  __int64 v95; // x19
  unsigned __int64 v96; // x12
  __int64 v97; // x9
  __int64 v98; // x8
  __int64 v99; // x1
  unsigned int v100; // w9
  __int64 v101; // [xsp+30h] [xbp-30h]
  __int64 v102; // [xsp+38h] [xbp-28h]
  __int64 v103; // [xsp+40h] [xbp-20h]
  __int64 v104; // [xsp+40h] [xbp-20h]
  int v105; // [xsp+4Ch] [xbp-14h]
  __int64 v106; // [xsp+50h] [xbp-10h]
  __int64 v107; // [xsp+50h] [xbp-10h]
  __int64 v108; // [xsp+50h] [xbp-10h]
  unsigned __int64 v109; // [xsp+58h] [xbp-8h]
  unsigned __int64 v110; // [xsp+58h] [xbp-8h]
  unsigned __int64 v111; // [xsp+58h] [xbp-8h]
  unsigned __int64 v112; // [xsp+58h] [xbp-8h]

  v13 = *(_DWORD *)(a1 + 208);
  v14 = 4 - a7;
  v15 = a13;
  v16 = v13 * (4 - a7) + 3;
  v18 = 1LL << v16;
  if ( *(_DWORD *)(a1 + 204) == a7 )
    v19 = *(_DWORD *)(a1 + 200) - v13;
  else
    LOBYTE(v19) = 0;
  v20 = (a2 >> v16) & ~(-1 << (v19 + v13));
  v21 = (__int64 *)(a8 + 8LL * v20);
  if ( v18 != a4 )
  {
    if ( a7 >= 3 )
    {
      __break(0x800u);
      return 4294967274LL;
    }
    v30 = *v21;
    v31 = a12;
    v32 = a11;
    if ( *v21 )
    {
      if ( (v30 & 0x80000000000000LL) == 0 && (*(_BYTE *)(a1 + 48) & 1) == 0 )
      {
        v33 = *(_QWORD *)(a1 + 64);
        if ( (*(_BYTE *)(v33 + 844) & 0x40) == 0 )
        {
          v34 = (__int64)((_QWORD)v21 << 8) >> 8;
          v110 = a2;
          v35 = a3;
          v36 = (unsigned __int64)(v34 + 0x8000000000LL) >> 38;
          v37 = memstart_addr + v34 + 0x8000000000LL;
          v38 = v34 - kimage_voffset;
          v39 = a4;
          v40 = a6;
          if ( !v36 )
            v38 = v37;
          v41 = a5;
          v42 = a7;
          _dma_sync_single_for_device(v33, v38, 8, 1);
          a7 = v42;
          v15 = a13;
          a6 = v40;
          v31 = a12;
          a2 = v110;
          v32 = a11;
          a5 = v41;
          a3 = v35;
          a4 = v39;
        }
      }
    }
    else
    {
      v107 = a3;
      v111 = a2;
      v105 = a7;
      v49 = 8LL << v13;
      v102 = a5;
      v101 = a6;
      v104 = a4;
      raw_spin_unlock_irqrestore(a1 + 248, *a12);
      v50 = _arm_lpae_alloc_pages(a1, v49, a11, a1 + 16);
      *a12 = raw_spin_lock_irqsave(a1 + 248);
      if ( !v50 )
        return 4294967284LL;
      v51 = arm_lpae_install_table(v50, v21, 0, a1 + 16, 0, a1, a12);
      if ( !v51 )
      {
        v68 = *(_QWORD *)(a1 + 8);
        v69 = **(void (__fastcall ***)(__int64, unsigned __int64, unsigned __int64, __int64))(a1 + 240);
        if ( *((_DWORD *)v69 - 1) != -716079766 )
          __break(0x8228u);
        v69(v68, v50, -v18 & v111, v18);
        a5 = v102;
        a4 = v104;
        a2 = v111;
        a6 = v101;
        a3 = v107;
        v32 = a11;
        a7 = v105;
        return _arm_lpae_map(a1, a2, a3, a4, a5, a6, (unsigned int)(a7 + 1), v50, v21, a10, v32, v31, v15);
      }
      v30 = v51;
      if ( *(_BYTE *)(a1 + 48) == 1 )
      {
        v52 = ((__int64)(v50 << 8) >> 8) + 0x8000000000LL;
      }
      else
      {
        v70 = (__int64)(v50 << 8) >> 8;
        v52 = v70 + 0x8000000000LL;
        v71 = (unsigned __int64)(v70 + 0x8000000000LL) >> 38;
        v72 = v70 - kimage_voffset;
        if ( v71 )
          v73 = v72;
        else
          v73 = memstart_addr + v52;
        dma_unmap_page_attrs(*(_QWORD *)(a1 + 64), v73, v49, 1, 0);
      }
      qcom_io_pgtable_free_page((v52 >> 12 << 6) - 0x140000000LL);
      a5 = v102;
      a4 = v104;
      a6 = v101;
      a3 = v107;
      a2 = v111;
      a7 = v105;
    }
    if ( (v30 & 3) == 1 )
    {
      __break(0x800u);
      return 4294967279LL;
    }
    v74 = v30 & 0xFFFFFFFFF000LL;
    if ( (unsigned __int64)(8LL << *(_DWORD *)(a1 + 208)) >= 0x10000 )
      v74 = v30 & 0x7FFFFF0000LL;
    v50 = (v74 - memstart_addr) | 0xFFFFFF8000000000LL;
    return _arm_lpae_map(a1, a2, a3, a4, a5, a6, (unsigned int)(a7 + 1), v50, v21, a10, v32, v31, v15);
  }
  if ( a10 )
  {
    if ( a7 == 3 )
    {
      v22 = 1LL << (2 * (unsigned __int8)v13 + 3);
      if ( *(_QWORD *)(a10 + 16) )
      {
        if ( (*(_BYTE *)(a1 + 48) & 1) == 0 )
        {
          v23 = *(_QWORD *)(a1 + 64);
          if ( (*(_BYTE *)(v23 + 844) & 0x40) == 0 )
          {
            v24 = (__int64)(*(_QWORD *)(a10 + 32) << 8) >> 8;
            v106 = a3;
            v109 = a2;
            v103 = a4;
            v25 = a6;
            v26 = v24 + 0x8000000000LL;
            v27 = v24 - kimage_voffset;
            v28 = a5;
            v29 = a8;
            if ( !(v26 >> 38) )
              v27 = v26 + memstart_addr;
            _dma_sync_single_for_device(v23, v27, 8LL * *(unsigned int *)(a10 + 40), 1);
            a3 = v106;
            a2 = v109;
            a6 = v25;
            v15 = a13;
            a4 = v103;
            a8 = v29;
            a7 = 3;
            LODWORD(a5) = v28;
          }
        }
      }
      *(_QWORD *)(a10 + 16) = a8;
      *(_QWORD *)(a10 + 24) = a9;
      *(_DWORD *)(a10 + 8) = a4;
      *(_QWORD *)(a10 + 32) = v21;
      *(_QWORD *)a10 = (-v22 & a2) + v22;
      *(_DWORD *)(a10 + 40) = a5;
      if ( (int)a5 < 1 )
        goto LABEL_79;
    }
    else
    {
      if ( *(_QWORD *)(a10 + 16) )
      {
        if ( (*(_BYTE *)(a1 + 48) & 1) == 0 )
        {
          v53 = *(_QWORD *)(a1 + 64);
          if ( (*(_BYTE *)(v53 + 844) & 0x40) == 0 )
          {
            v54 = (__int64)(*(_QWORD *)(a10 + 32) << 8) >> 8;
            v108 = a3;
            v112 = a2;
            v55 = a4;
            v56 = v54 + 0x8000000000LL;
            v57 = v54 - kimage_voffset;
            v58 = a6;
            v59 = a5;
            v60 = a7;
            if ( !(v56 >> 38) )
              v57 = v56 + memstart_addr;
            _dma_sync_single_for_device(v53, v57, 8LL * *(unsigned int *)(a10 + 40), 1);
            a3 = v108;
            a2 = v112;
            a6 = v58;
            v15 = a13;
            a7 = v60;
            LODWORD(a5) = v59;
            a4 = v55;
          }
        }
      }
      *(_QWORD *)(a10 + 32) = 0;
      *(_QWORD *)(a10 + 40) = 0;
      *(_QWORD *)(a10 + 16) = 0;
      *(_QWORD *)(a10 + 24) = 0;
      *(_QWORD *)a10 = 0;
      *(_QWORD *)(a10 + 8) = 0;
      if ( (int)a5 < 1 )
      {
LABEL_79:
        if ( a7 != 3 && (*(_BYTE *)(a1 + 48) & 1) == 0 )
        {
          v79 = *(_QWORD *)(a1 + 64);
          if ( (*(_BYTE *)(v79 + 844) & 0x40) == 0 )
          {
            v80 = (__int64)((_QWORD)v21 << 8) >> 8;
            v81 = a4;
            v82 = (unsigned __int64)(v80 + 0x8000000000LL) >> 38;
            v83 = memstart_addr + v80 + 0x8000000000LL;
            v84 = v80 - kimage_voffset;
            v85 = a5;
            if ( v82 )
              v86 = v84;
            else
              v86 = v83;
            _dma_sync_single_for_device(v79, v86, 8LL * (int)a5, 1);
            LODWORD(a5) = v85;
            a4 = v81;
          }
        }
        if ( a9 )
        {
          v87 = ((*a9 >> 42) & 0x1C00 | ((unsigned int)*a9 >> 2) & 0x3FF) + a5;
          *a9 = (4 * (v87 & 0x3FF)) | ((unsigned __int64)((v87 >> 10) & 7) << 52) | *a9 & 0xFF8FFFFFFFFFF003LL;
        }
        result = 0;
        if ( v15 )
        {
          v88 = *v15 + a4;
LABEL_104:
          *v15 = v88;
          return result;
        }
        return result;
      }
    }
    v61 = 0;
    v62 = a5 & 0x7FFFFFFF;
    do
    {
      if ( (v21[v61] & 1) != 0 )
      {
        _warn_printk(
          "Bad pte: 0x%llx at IOVA: 0x%llx Lvl: %d\n",
          v21[v61],
          (v61 << ((unsigned __int8)*(_DWORD *)(a1 + 208) * (unsigned __int8)v14 + 3)) + a2,
          a7);
        __break(0x800u);
        return 4294967279LL;
      }
      ++v61;
    }
    while ( v62 != v61 );
    v63 = *(_DWORD *)(a1 + 208) * v14 + 3;
    v64 = 3;
    if ( *(_DWORD *)a1 == 5 || a7 != 3 )
      v64 = 1;
    if ( v62 >= 2 )
    {
      v75 = 0;
      v66 = v62 - (a5 & 1);
      do
      {
        v76 = v75 << v63;
        v77 = (v75 + 1) << v63;
        v78 = &v21[v75];
        v75 += 2;
        *v78 = v64 | a6 | ((v76 + a3) | ((unsigned __int64)(v76 + a3) >> 36)) & 0xFFFFFFFFF000LL;
        v78[1] = v64 | a6 | ((v77 + a3) | ((unsigned __int64)(v77 + a3) >> 36)) & 0xFFFFFFFFF000LL;
      }
      while ( v75 != v66 );
      if ( (a5 & 1) == 0 )
        goto LABEL_79;
    }
    else
    {
      v66 = 0;
    }
    do
    {
      v21[v66] = v64 | a6 | (((v66 << v63) + a3) | (((v66 << v63) + a3) >> 36)) & 0xFFFFFFFFF000LL;
      ++v66;
    }
    while ( v62 != v66 );
    goto LABEL_79;
  }
  v43 = (1LL << v13) - v20;
  if ( v43 >= (int)a5 )
    v44 = (unsigned int)a5;
  else
    v44 = (unsigned int)v43;
  if ( (int)v44 >= 1 )
  {
    for ( i = 0; i != v44; ++i )
    {
      if ( (v21[i] & 1) != 0 )
      {
        _warn_printk("Bad pte: 0x%llx at IOVA: 0x%llx Lvl: %d\n", v21[i], (i << v16) + a2, a7);
        __break(0x800u);
        return 4294967279LL;
      }
    }
    v46 = 3;
    if ( *(_DWORD *)a1 == 5 || a7 != 3 )
      v46 = 1;
    if ( (_DWORD)v44 == 1 )
    {
      for ( j = 0; j != v44; ++j )
LABEL_93:
        v21[j] = v46 | a6 | (((j << v16) + a3) | ((unsigned __int64)((j << v16) + a3) >> 36)) & 0xFFFFFFFFF000LL;
      goto LABEL_94;
    }
    v89 = 0;
    j = v44 & 0x7FFFFFFE;
    do
    {
      v90 = v89 << v16;
      v91 = (v89 + 1) << v16;
      v92 = &v21[v89];
      v89 += 2;
      *v92 = v46 | a6 | ((v90 + a3) | ((unsigned __int64)(v90 + a3) >> 36)) & 0xFFFFFFFFF000LL;
      v92[1] = v46 | a6 | ((v91 + a3) | ((unsigned __int64)(v91 + a3) >> 36)) & 0xFFFFFFFFF000LL;
    }
    while ( v89 != j );
    if ( j != v44 )
      goto LABEL_93;
  }
LABEL_94:
  if ( (*(_BYTE *)(a1 + 48) & 1) == 0 )
  {
    v93 = *(_QWORD *)(a1 + 64);
    if ( (*(_BYTE *)(v93 + 844) & 0x40) == 0 )
    {
      v94 = (__int64)((_QWORD)v21 << 8) >> 8;
      v95 = a4;
      v96 = (unsigned __int64)(v94 + 0x8000000000LL) >> 38;
      v97 = memstart_addr + v94 + 0x8000000000LL;
      v98 = v94 - kimage_voffset;
      if ( v96 )
        v99 = v98;
      else
        v99 = v97;
      _dma_sync_single_for_device(v93, v99, 8LL * (int)v44, 1);
      a4 = v95;
    }
  }
  if ( a9 )
  {
    v100 = ((*a9 >> 42) & 0x1C00 | ((unsigned int)*a9 >> 2) & 0x3FF) + v44;
    *a9 = (4 * (v100 & 0x3FF)) | ((unsigned __int64)((v100 >> 10) & 7) << 52) | *a9 & 0xFF8FFFFFFFFFF003LL;
  }
  result = 0;
  if ( a13 )
  {
    v88 = *a13 + (int)v44 * a4;
    goto LABEL_104;
  }
  return result;
}
