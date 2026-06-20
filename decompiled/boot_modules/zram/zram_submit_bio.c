__int64 __fastcall zram_submit_bio(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  __int64 v3; // x20
  int v4; // w21
  __int64 v5; // x0
  unsigned int v6; // w26
  unsigned __int64 v7; // x25
  __int64 v8; // x22
  size_t v9; // x0
  __int16 v10; // w23
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x23
  int v15; // w8
  unsigned int v16; // w8
  __int64 v17; // x25
  unsigned __int64 v23; // x9
  unsigned int v24; // w10
  int v25; // w8
  __int64 v26; // x8
  __int64 v27; // x28
  unsigned int v28; // w22
  unsigned int v29; // w9
  unsigned int v30; // w27
  unsigned int v31; // w8
  __int64 (__fastcall *v32)(); // x10
  unsigned int v33; // w8
  __int64 v34; // x1
  unsigned int v36; // w8
  __int64 started; // x0
  unsigned int v38; // w24
  unsigned int v39; // w25
  unsigned __int64 v40; // x23
  int v41; // w21
  int v42; // w12
  __int64 v43; // x8
  int v44; // w9
  int v45; // w10
  __int64 v46; // x8
  unsigned int v47; // w9
  unsigned int v48; // w10
  int v49; // w11
  __int64 v50; // x9
  unsigned int v51; // w11
  __int64 v52; // x22
  unsigned int v53; // w27
  __int64 v54; // x22
  unsigned int v55; // w8
  __int64 v56; // x2
  __int64 v57; // x1
  unsigned int v58; // w10
  int v59; // w8
  int v60; // w12
  __int64 v61; // x8
  int v62; // w9
  int v63; // w10
  __int64 v64; // x8
  unsigned int v65; // w9
  unsigned int v66; // w10
  int v67; // w11
  __int64 v68; // x9
  unsigned int v69; // w11
  unsigned int v70; // w22
  __int64 v71; // x27
  __int64 v72; // x28
  __int64 v73; // x9
  unsigned __int64 v74; // x23
  const void **v75; // x24
  int v76; // w0
  __int64 v77; // x1
  unsigned __int64 v78; // x0
  unsigned __int64 v79; // x0
  unsigned __int64 v82; // x9
  int v83; // w24
  __int64 v84; // x24
  unsigned __int64 total_pages; // x0
  unsigned __int64 v86; // x8
  unsigned __int64 v90; // x9
  unsigned __int64 v91; // x8
  void *v92; // x0
  size_t v93; // x2
  const void *v94; // x1
  __int64 v95; // x8
  int v96; // w21
  char v97; // w27
  unsigned __int64 v100; // x10
  unsigned __int64 v103; // x9
  unsigned __int64 v106; // x9
  unsigned int v107; // w8
  unsigned __int64 v110; // x9
  unsigned __int64 v113; // x9
  __int64 v114; // x0
  _QWORD *v115; // x21
  __int64 v116; // x19
  unsigned __int64 v119; // x9
  unsigned __int64 v122; // x9
  int v124; // w8
  __int64 v125; // x19
  int v127; // w8
  unsigned __int64 v130; // x9
  unsigned __int64 v133; // x9
  unsigned __int64 v137; // x9
  __int64 v138; // [xsp+8h] [xbp-48h]
  _QWORD *v139; // [xsp+10h] [xbp-40h]
  int v140; // [xsp+1Ch] [xbp-34h]
  unsigned int v141; // [xsp+20h] [xbp-30h]
  __int64 v142; // [xsp+20h] [xbp-30h]
  size_t n; // [xsp+28h] [xbp-28h] BYREF
  __int64 v144; // [xsp+30h] [xbp-20h]
  __int64 v145; // [xsp+38h] [xbp-18h]
  __int64 v146; // [xsp+40h] [xbp-10h]
  __int64 v147; // [xsp+48h] [xbp-8h]

  v1 = result;
  v147 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int8 *)(result + 16);
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 8) + 16LL) + 88LL);
  if ( v2 > 2 )
  {
    if ( v2 == 3 || v2 == 9 )
    {
      v12 = *(_QWORD *)(result + 32);
      v13 = *(unsigned int *)(result + 40);
      v14 = v12 >> 3;
      v15 = (v12 & 7) << 9;
      if ( v15 )
      {
        v16 = 4096 - v15;
        if ( (unsigned int)v13 <= v16 )
          goto LABEL_139;
        v13 -= v16;
        LODWORD(v14) = v14 + 1;
      }
      if ( v13 >= 0x1000 )
      {
        do
        {
          v17 = 16LL * (unsigned int)v14;
          raw_spin_lock(*(_QWORD *)v3 + v17 + 12);
          zram_free_page((_QWORD *)v3, (unsigned int)v14);
          raw_spin_unlock(*(_QWORD *)v3 + v17 + 12);
          _X8 = (unsigned __int64 *)(v3 + 128);
          __asm { PRFM            #0x11, [X8] }
          do
            v23 = __ldxr(_X8);
          while ( __stxr(v23 + 1, _X8) );
          v13 -= 4096LL;
          LODWORD(v14) = v14 + 1;
        }
        while ( v13 > 0xFFF );
      }
LABEL_138:
      result = bio_endio(v1);
      goto LABEL_139;
    }
LABEL_44:
    __break(0x800u);
    goto LABEL_138;
  }
  if ( !*(_BYTE *)(result + 16) )
  {
    started = bio_start_io_acct(result);
    v38 = *(_DWORD *)(v1 + 40);
    v39 = *(_DWORD *)(v1 + 44);
    v40 = *(_QWORD *)(v1 + 32);
    v41 = *(_DWORD *)(v1 + 48);
    v142 = started;
    do
    {
      v42 = (v40 & 7) << 9;
      v43 = *(_QWORD *)(v1 + 120) + 16LL * v39;
      v45 = *(_DWORD *)(v43 + 8);
      v44 = *(_DWORD *)(v43 + 12);
      v46 = *(_QWORD *)v43;
      v47 = v44 + v41;
      v48 = v45 - v41;
      v49 = v47 & 0xFFF;
      v50 = v47 >> 12;
      if ( v38 < v48 )
        v48 = v38;
      v51 = 4096 - v49;
      v52 = v46 + (v50 << 6);
      if ( v48 >= v51 )
        v48 = v51;
      if ( v48 >= 4096 - v42 )
        v53 = 4096 - v42;
      else
        v53 = v48;
      zram_read_page(v3, v46 + (v50 << 6), v40 >> 3, v1);
      flush_dcache_page(v52);
      v54 = 16LL * (unsigned int)(v40 >> 3);
      raw_spin_lock(*(_QWORD *)v3 + v54 + 12);
      *(_DWORD *)(*(_QWORD *)v3 + v54 + 8) &= ~0x20000u;
      raw_spin_unlock(*(_QWORD *)v3 + v54 + 12);
      v55 = *(unsigned __int8 *)(v1 + 16);
      if ( v55 > 9 || ((1 << v55) & 0x228) == 0 )
      {
        if ( v53 + v41 == *(_DWORD *)(*(_QWORD *)(v1 + 120) + 16LL * v39 + 8) )
        {
          ++v39;
          v41 = 0;
        }
        else
        {
          v41 += v53;
        }
      }
      v38 -= v53;
      v40 += v53 >> 9;
    }
    while ( v38 );
    v56 = *(_QWORD *)(v1 + 8);
    v57 = v142;
LABEL_136:
    v114 = v1;
LABEL_137:
    bio_end_io_acct_remapped(v114, v57, v56);
    goto LABEL_138;
  }
  if ( v2 != 1 )
    goto LABEL_44;
  v4 = *(unsigned __int8 *)(v3 + 234);
  v5 = bio_start_io_acct(result);
  v6 = *(_DWORD *)(v1 + 40);
  v7 = *(_QWORD *)(v1 + 32);
  v8 = v5;
  v140 = *(_DWORD *)(v1 + 48);
  v141 = *(_DWORD *)(v1 + 44);
  if ( v4 != 1 )
  {
    v138 = v5;
    while ( 1 )
    {
      v60 = (v7 & 7) << 9;
      v61 = *(_QWORD *)(v1 + 120) + 16LL * v141;
      v63 = *(_DWORD *)(v61 + 8);
      v62 = *(_DWORD *)(v61 + 12);
      v64 = *(_QWORD *)v61;
      LODWORD(n) = 0;
      v65 = v62 + v140;
      v66 = v63 - v140;
      v67 = v65 & 0xFFF;
      v68 = v65 >> 12;
      if ( v6 < v66 )
        v66 = v6;
      v69 = 4096 - v67;
      if ( v66 >= v69 )
        v66 = v69;
      if ( v66 >= 4096 - v60 )
        v70 = 4096 - v60;
      else
        v70 = v66;
      v71 = (((v64 + (v68 << 6)) << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL;
      v72 = *(_QWORD *)(v71 | 0xFF00000000000000LL);
      if ( v72 == *(_QWORD *)((char *)&unk_FF8 + (v71 | 0xFF00000000000000LL)) )
      {
        v73 = 8;
        while ( v72 == *(_QWORD *)((v71 | 0xFF00000000000000LL) + v73) )
        {
          v73 += 8;
          if ( v73 == 4088 )
          {
            _X8 = (unsigned __int64 *)(v3 + 136);
            __asm { PRFM            #0x11, [X8] }
            do
              v113 = __ldxr(_X8);
            while ( __stxr(v113 + 1, _X8) );
            v74 = -12;
            v97 = 13;
            v96 = 1;
            goto LABEL_113;
          }
        }
      }
      v74 = -12;
      while ( 1 )
      {
        v75 = (const void **)zcomp_stream_get(*(__int64 **)(v3 + 16));
        v76 = zcomp_compress(v75, v71 | 0xFF00000000000000LL, &n);
        if ( v76 )
        {
          v83 = v76;
          zcomp_stream_put();
          printk(&unk_B31C);
          zs_free(*(_QWORD *)(v3 + 8), v74);
          if ( (v83 & 0x80000000) == 0 )
          {
            v84 = (unsigned int)(v7 >> 3);
            goto LABEL_126;
          }
          goto LABEL_134;
        }
        v77 = (unsigned int)n;
        if ( huge_class_size <= (unsigned __int64)(unsigned int)n )
        {
          v77 = 4096;
          LODWORD(n) = 4096;
        }
        if ( v74 < 0xFFFFFFFFFFFFF001LL )
          goto LABEL_96;
        v78 = zs_malloc(*(_QWORD *)(v3 + 8), v77, 10250);
        if ( v78 < 0xFFFFFFFFFFFFF001LL )
          break;
        zcomp_stream_put();
        _X8 = (unsigned __int64 *)(v3 + 176);
        __asm { PRFM            #0x11, [X8] }
        do
          v82 = __ldxr(_X8);
        while ( __stxr(v82 + 1, _X8) );
        v79 = zs_malloc(*(_QWORD *)(v3 + 8), (unsigned int)n, 3082);
        if ( v79 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_134;
        v74 = v79;
        if ( (_DWORD)n == 4096 )
        {
          v75 = (const void **)zcomp_stream_get(*(__int64 **)(v3 + 16));
          goto LABEL_96;
        }
      }
      v74 = v78;
LABEL_96:
      total_pages = zs_get_total_pages(*(_QWORD *)(v3 + 8));
      v86 = *(_QWORD *)(v3 + 168);
      if ( v86 < total_pages )
      {
        do
        {
          _X10 = (unsigned __int64 *)(v3 + 168);
          __asm { PRFM            #0x11, [X10] }
          do
          {
            v90 = __ldxr(_X10);
            if ( v90 != v86 )
              goto LABEL_98;
          }
          while ( __stlxr(total_pages, _X10) );
          __dmb(0xBu);
LABEL_98:
          _ZF = v90 == v86;
          v86 = v90;
        }
        while ( !_ZF && v90 < total_pages );
      }
      v91 = *(_QWORD *)(v3 + 96);
      if ( v91 )
      {
        if ( total_pages > v91 )
          break;
      }
      v92 = (void *)zs_map_object(*(_QWORD *)(v3 + 8), v74, 2);
      v93 = (unsigned int)n;
      if ( (_DWORD)n == 4096 )
      {
        v93 = 4096;
        v94 = (const void *)(v71 | 0xFF00000000000000LL);
      }
      else
      {
        v94 = *v75;
      }
      memcpy(v92, v94, v93);
      zcomp_stream_put();
      zs_unmap_object(*(_QWORD *)(v3 + 8), v74);
      v95 = (unsigned int)n;
      _X9 = (unsigned __int64 *)(v3 + 104);
      __asm { PRFM            #0x11, [X9] }
      do
        v100 = __ldxr(_X9);
      while ( __stxr(v100 + v95, _X9) );
      v96 = 0;
      v72 = 0;
      v97 = 0;
LABEL_113:
      v84 = (unsigned int)(v7 >> 3);
      raw_spin_lock(*(_QWORD *)v3 + 16 * v84 + 12);
      zram_free_page((_QWORD *)v3, v84);
      if ( (_DWORD)n == 4096 )
      {
        *(_DWORD *)(*(_QWORD *)v3 + 16 * v84 + 8) |= 0x10000u;
        _X8 = (unsigned __int64 *)(v3 + 144);
        __asm { PRFM            #0x11, [X8] }
        do
          v103 = __ldxr(_X8);
        while ( __stxr(v103 + 1, _X8) );
        _X8 = (unsigned __int64 *)(v3 + 152);
        __asm { PRFM            #0x11, [X8] }
        do
          v106 = __ldxr(_X8);
        while ( __stxr(v106 + 1, _X8) );
        if ( !v96 )
        {
LABEL_124:
          *(_QWORD *)(*(_QWORD *)v3 + 16 * v84) = v74;
          *(_DWORD *)(*(_QWORD *)v3 + 16 * v84 + 8) = *(_DWORD *)(*(_QWORD *)v3 + 16 * v84 + 8) & 0xFFFFE000 | n;
          goto LABEL_125;
        }
      }
      else if ( !v96 )
      {
        goto LABEL_124;
      }
      *(_DWORD *)(*(_QWORD *)v3 + 16 * v84 + 8) |= 1 << v97;
      *(_QWORD *)(*(_QWORD *)v3 + 16 * v84) = v72;
LABEL_125:
      raw_spin_unlock(*(_QWORD *)v3 + 16 * v84 + 12);
      _X8 = (unsigned __int64 *)(v3 + 160);
      __asm { PRFM            #0x11, [X8] }
      do
        v110 = __ldxr(_X8);
      while ( __stxr(v110 + 1, _X8) );
LABEL_126:
      raw_spin_lock(*(_QWORD *)v3 + 16 * v84 + 12);
      *(_DWORD *)(*(_QWORD *)v3 + 16 * v84 + 8) &= ~0x20000u;
      raw_spin_unlock(*(_QWORD *)v3 + 16 * v84 + 12);
      v107 = *(unsigned __int8 *)(v1 + 16);
      if ( v107 > 9 || ((1 << v107) & 0x228) == 0 )
      {
        if ( v70 + v140 == *(_DWORD *)(*(_QWORD *)(v1 + 120) + 16LL * v141 + 8) )
          v58 = v141 + 1;
        else
          v58 = v141;
        if ( v70 + v140 == *(_DWORD *)(*(_QWORD *)(v1 + 120) + 16LL * v141 + 8) )
          v59 = 0;
        else
          v59 = v70 + v140;
        v140 = v59;
        v141 = v58;
      }
      v6 -= v70;
      v7 += v70 >> 9;
      if ( !v6 )
        goto LABEL_135;
    }
    zcomp_stream_put();
    zs_free(*(_QWORD *)(v3 + 8), v74);
LABEL_134:
    _X8 = (unsigned __int64 *)(v3 + 120);
    __asm { PRFM            #0x11, [X8] }
    do
      v119 = __ldxr(_X8);
    while ( __stxr(v119 + 1, _X8) );
    *(_BYTE *)(v1 + 25) = 10;
LABEL_135:
    v56 = *(_QWORD *)(v1 + 8);
    v57 = v138;
    goto LABEL_136;
  }
  v145 = 0;
  v146 = 0;
  v144 = 0;
  v9 = _kmalloc_cache_noprof(qpace_queue_compress, 3264, 32);
  n = v9;
  if ( !v9 )
  {
    _X8 = (unsigned __int64 *)(v3 + 120);
    __asm { PRFM            #0x11, [X8] }
    do
      v122 = __ldxr(_X8);
    while ( __stxr(v122 + 1, _X8) );
    v56 = *(_QWORD *)(v1 + 8);
    v114 = v1;
    v57 = v8;
    *(_BYTE *)(v1 + 25) = 10;
    goto LABEL_137;
  }
  v10 = (_WORD)v7 << 9;
  *(_QWORD *)v9 = v3;
  *(_QWORD *)(v9 + 8) = v1;
  v139 = (_QWORD *)v9;
  *(_QWORD *)(v9 + 16) = v8;
  *(_DWORD *)(v9 + 24) = 1;
  _X20 = (unsigned int *)(v9 + 24);
  v146 = -12;
  while ( 1 )
  {
    v26 = *(_QWORD *)(v1 + 120) + 16LL * v141;
    v27 = *(_QWORD *)v26;
    v28 = *(_DWORD *)(v26 + 12) + v140;
    v29 = *(_DWORD *)(v26 + 8) - v140;
    if ( v6 < v29 )
      v29 = v6;
    v30 = v29 >= 4096 - (v28 & 0xFFF) ? 4096 - (v28 & 0xFFF) : v29;
    __asm { PRFM            #0x11, [X20] }
    do
      v36 = __ldxr(_X20);
    while ( __stxr(v36 + 1, _X20) );
    if ( v36 )
    {
      if ( (((v36 + 1) | v36) & 0x80000000) == 0 )
        goto LABEL_29;
      v34 = 1;
    }
    else
    {
      v34 = 2;
    }
    refcount_warn_saturate(_X20, v34);
LABEL_29:
    v31 = 4096 - (v10 & 0xE00);
    if ( v30 < v31 )
      v31 = v30;
    if ( v31 != 4096 )
      break;
    v32 = off_3E8;
    LODWORD(v145) = v7 >> 3;
    v144 = v27 + ((unsigned __int64)(v28 >> 12) << 6);
    if ( *((_DWORD *)off_3E8 - 1) != 2061822016 )
      __break(0x822Au);
    result = ((__int64 (__fastcall *)(_QWORD *))v32)(&n);
    if ( (_DWORD)result )
    {
      v115 = v139;
      *(_BYTE *)(v139[1] + 25LL) = 10;
      __asm { PRFM            #0x11, [X20] }
      do
        v124 = __ldxr(_X20);
      while ( __stlxr(v124 - 1, _X20) );
      if ( v124 != 1 )
        goto LABEL_154;
      __dmb(9u);
      if ( *(_BYTE *)(v139[1] + 25LL) == 10 )
      {
        _X8 = (unsigned __int64 *)(*v139 + 120LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v133 = __ldxr(_X8);
        while ( __stxr(v133 + 1, _X8) );
      }
LABEL_143:
      v116 = v115[1];
      bio_end_io_acct_remapped(v116, v115[2], *(_QWORD *)(v116 + 8));
      bio_endio(v116);
      result = kfree(v115);
      goto LABEL_163;
    }
    v33 = *(unsigned __int8 *)(v1 + 16);
    if ( v33 > 9 || ((1 << v33) & 0x228) == 0 )
    {
      v24 = v141;
      if ( v140 + 4096 == *(_DWORD *)(*(_QWORD *)(v1 + 120) + 16LL * v141 + 8) )
      {
        v24 = v141 + 1;
        v25 = 0;
      }
      else
      {
        v25 = v140 + 4096;
      }
      v140 = v25;
      v141 = v24;
    }
    v6 -= 4096;
    v10 += 4096;
    v7 += 8LL;
    if ( !v6 )
      goto LABEL_163;
  }
  result = printk(&unk_B1DD);
  v115 = v139;
  *(_BYTE *)(v139[1] + 25LL) = 10;
  __asm { PRFM            #0x11, [X20] }
  do
    v124 = __ldxr(_X20);
  while ( __stlxr(v124 - 1, _X20) );
  if ( v124 == 1 )
  {
    __dmb(9u);
    if ( *(_BYTE *)(v139[1] + 25LL) == 10 )
    {
      _X8 = (unsigned __int64 *)(*v139 + 120LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v137 = __ldxr(_X8);
      while ( __stxr(v137 + 1, _X8) );
    }
    goto LABEL_143;
  }
LABEL_154:
  if ( v124 <= 0 )
    result = refcount_warn_saturate(_X20, 3);
LABEL_163:
  __asm { PRFM            #0x11, [X20] }
  do
    v127 = __ldxr(_X20);
  while ( __stlxr(v127 - 1, _X20) );
  if ( v127 == 1 )
  {
    __dmb(9u);
    if ( *(_BYTE *)(v139[1] + 25LL) == 10 )
    {
      _X8 = (unsigned __int64 *)(*v139 + 120LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v130 = __ldxr(_X8);
      while ( __stxr(v130 + 1, _X8) );
    }
    v125 = v139[1];
    bio_end_io_acct_remapped(v125, v139[2], *(_QWORD *)(v125 + 8));
    bio_endio(v125);
    result = kfree(v139);
  }
  else if ( v127 <= 0 )
  {
    result = refcount_warn_saturate(_X20, 3);
  }
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return result;
}
