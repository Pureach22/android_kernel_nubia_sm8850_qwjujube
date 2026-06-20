__int64 __fastcall _arm_lpae_unmap(
        _DWORD *a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        __int64 a7,
        __int64 a8)
{
  char v9; // w28
  _DWORD *v10; // x20
  int v11; // w8
  int v12; // w21
  int v13; // w11
  __int64 v14; // x9
  unsigned __int64 *v15; // x23
  unsigned __int64 v16; // x13
  __int64 v17; // x19
  int v18; // w10
  __int64 v19; // x21
  __int64 v20; // x28
  int v21; // w19
  __int64 v22; // x8
  unsigned __int64 v23; // x25
  __int64 v24; // x0
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x12
  __int64 v27; // x9
  __int64 v28; // x1
  __int64 v30; // x9
  __int64 v31; // x9
  __int64 v32; // x10
  unsigned __int64 v33; // x27
  unsigned __int64 v34; // x22
  int v35; // w8
  unsigned int v36; // w8
  __int64 v38; // x8
  unsigned __int64 v39; // x26
  __int64 v40; // x25
  __int64 result; // x0
  __int64 v42; // x16
  __int64 v43; // x22
  int v44; // w9
  int v45; // w15
  int v46; // w11
  __int64 v47; // x9
  __int64 v48; // x5
  unsigned __int64 v49; // x6
  unsigned int v50; // w8
  unsigned __int64 v51; // x24
  int v52; // w25
  unsigned __int64 v53; // x21
  __int64 v54; // x19
  __int64 v55; // x0
  unsigned __int64 v56; // x21
  __int64 v57; // x19
  __int64 v58; // x1
  unsigned int v59; // w9
  int v60; // w8
  char v61; // w9
  char v62; // w8
  __int64 v63; // x24
  __int64 v64; // x0
  __int64 v65; // x8
  unsigned __int64 v66; // x21
  __int64 v67; // x9
  __int64 v68; // x19
  unsigned __int64 v69; // x12
  __int64 v70; // x8
  __int64 v71; // x9
  __int64 v72; // x1
  __int64 v73; // x23
  __int64 v74; // x9
  __int64 v75; // x1
  void (__fastcall *v76)(__int64, unsigned __int64); // x8
  __int64 v77; // x0
  __int64 v78; // x3
  _DWORD *v79; // x8
  __int64 v80; // x0
  void (__fastcall *v81)(__int64, unsigned __int64, unsigned __int64, __int64); // x8
  __int64 v82; // x6
  int v83; // w14
  int v84; // w0
  int v85; // w14
  __int64 v86; // x26
  __int64 v87; // x21
  __int64 v88; // x12
  __int64 v89; // x28
  unsigned int v90; // w27
  __int64 v91; // x19
  __int64 v92; // x11
  unsigned __int64 v93; // x25
  __int64 v95; // x9
  __int64 v96; // x0
  unsigned __int64 v97; // x9
  unsigned __int64 v98; // x12
  __int64 v99; // x9
  __int64 v100; // x1
  __int64 v101; // x0
  unsigned __int64 v102; // x22
  __int64 v103; // x21
  __int64 v104; // x0
  void (__fastcall **v105)(__int64, unsigned __int64, __int64); // x10
  void (__fastcall *v106)(__int64, unsigned __int64, __int64); // x9
  __int64 v107; // x2
  __int64 v108; // x23
  unsigned __int64 v109; // x19
  __int64 v110; // x8
  __int64 v111; // x8
  unsigned __int64 v112; // x1
  __int64 v113; // x9
  __int64 v114; // [xsp+0h] [xbp-70h]
  int v115; // [xsp+8h] [xbp-68h]
  int v116; // [xsp+10h] [xbp-60h]
  unsigned __int64 v117; // [xsp+18h] [xbp-58h]
  __int64 v118; // [xsp+20h] [xbp-50h]
  __int64 v119; // [xsp+30h] [xbp-40h]
  unsigned __int64 v120; // [xsp+40h] [xbp-30h]
  unsigned __int64 v121; // [xsp+48h] [xbp-28h]
  unsigned int v122; // [xsp+54h] [xbp-1Ch]
  int v123; // [xsp+58h] [xbp-18h]
  __int64 v124; // [xsp+58h] [xbp-18h]
  __int64 v125; // [xsp+60h] [xbp-10h]
  __int64 v126; // [xsp+60h] [xbp-10h]
  __int64 v127; // [xsp+68h] [xbp-8h]

  v127 = a2;
  if ( a6 == 4 )
    goto LABEL_141;
  v9 = 4 - a6;
  v10 = a1;
  v11 = a1[51];
  v12 = a1[52];
  if ( v11 == a6 )
    v13 = a1[50] - v12;
  else
    LOBYTE(v13) = 0;
  v14 = (unsigned int)(a3 >> (v12 * (4 - (unsigned __int8)a6) + 3)) & ~(-1 << (v13 + v12));
  v15 = (unsigned __int64 *)(a7 + 8LL * (unsigned int)v14);
  v16 = *v15;
  if ( !*v15 )
    goto LABEL_141;
  v17 = 1LL << v12;
  if ( 1LL << (v12 * (4 - (unsigned __int8)a6) + 3) != a4 )
  {
    v31 = *v15 & 3;
    if ( a6 == 2 && v31 != 1 )
    {
      v32 = v16 & 0xFFFFFFFFF000LL;
      if ( (unsigned __int64)(8LL << v12) >= 0x10000 )
        v32 = v16 & 0x7FFFFF0000LL;
      v33 = v32 - memstart_addr;
      v34 = (v32 - memstart_addr) | 0xFFFFFF8000000000LL;
      if ( v11 == 3 )
        v35 = a1[50] - v12;
      else
        LOBYTE(v35) = 0;
      v50 = (a3 >> ((unsigned __int8)v12 + 3)) & ~(-1 << (v35 + v12));
      v51 = v34 + 8LL * v50;
      if ( (int)(v17 - v50) >= (int)a5 )
        v52 = a5;
      else
        v52 = v17 - v50;
      if ( v52 >= 1 )
      {
        v53 = a3;
        v54 = a4;
        memset((void *)(v34 + 8LL * v50), 0, 8LL * (unsigned int)v52);
        a3 = v53;
        a4 = v54;
      }
      if ( (v10[12] & 1) == 0 )
      {
        v55 = *((_QWORD *)v10 + 8);
        if ( (*(_BYTE *)(v55 + 844) & 0x40) == 0 )
        {
          v56 = a3;
          v57 = a4;
          if ( (v51 + 0x8000000000LL) >> 38 )
            v58 = v51 - kimage_voffset;
          else
            v58 = memstart_addr + v51 + 0x8000000000LL;
          _dma_sync_single_for_device(v55, v58, 8LL * v52, 1);
          a3 = v56;
          a4 = v57;
        }
      }
      v59 = ((*v15 >> 42) & 0x1C00 | ((unsigned int)*v15 >> 2) & 0x3FF) - v52;
      *v15 = *v15 & 0xFF8FFFFFFFFFF003LL | (4 * (v59 & 0x3FF)) | ((unsigned __int64)((v59 >> 10) & 7) << 52);
      if ( (v59 & 0x1FFF) == 0 )
      {
        v60 = v10[52];
        *v15 = 0;
        v61 = v60 * v9 + 3;
        v62 = *((_BYTE *)v10 + 48);
        v63 = 1LL << v61;
        if ( (v62 & 1) != 0 || (v64 = *((_QWORD *)v10 + 8), (*(_BYTE *)(v64 + 844) & 0x40) != 0) )
        {
          v66 = a3;
          v68 = a4;
        }
        else
        {
          v65 = (__int64)((_QWORD)v15 << 8) >> 8;
          v66 = a3;
          v67 = v65 + 0x8000000000LL;
          v68 = a4;
          v69 = (unsigned __int64)(v65 + 0x8000000000LL) >> 38;
          v70 = v65 - kimage_voffset;
          v71 = memstart_addr + v67;
          if ( v69 )
            v72 = v70;
          else
            v72 = v71;
          _dma_sync_single_for_device(v64, v72, 8, 1);
          v62 = *((_BYTE *)v10 + 48);
        }
        v73 = *((_QWORD *)v10 + 1);
        if ( (v62 & 1) == 0 )
        {
          v74 = 52;
          if ( v10[51] == 3 )
            v74 = 50;
          if ( ((v33 >> 38) & 1) != 0 )
            v75 = v34 - kimage_voffset;
          else
            v75 = memstart_addr + (v33 & 0x7FFFFFFFFFLL);
          dma_unmap_page_attrs(*((_QWORD *)v10 + 8), v75, 8LL << v10[v74], 1, 0);
        }
        v76 = **((void (__fastcall ***)(__int64, unsigned __int64))v10 + 29);
        if ( *((_DWORD *)v76 - 1) != -72220 )
          __break(0x8228u);
        v76(v73, v33 | 0xFFFFFF8000000000LL);
        v77 = *((_QWORD *)v10 + 1);
        v78 = 1LL << (2 * *((_BYTE *)v10 + 208) + 3);
        v79 = *(_DWORD **)(*((_QWORD *)v10 + 30) + 8LL);
        if ( *(v79 - 1) != -716079766 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, unsigned __int64, _QWORD, __int64))v79)(v77, v33 | 0xFFFFFF8000000000LL, 0, v78);
        v80 = *((_QWORD *)v10 + 1);
        v81 = *(void (__fastcall **)(__int64, unsigned __int64, unsigned __int64, __int64))(*((_QWORD *)v10 + 30) + 8LL);
        if ( *((_DWORD *)v81 - 1) != -716079766 )
          __break(0x8228u);
        v81(v80, v33 | 0xFFFFFF8000000000LL, -v63 & v66, v63);
        a4 = v68;
      }
      return v52 * a4;
    }
    if ( *a1 != 5 && a6 == 3 )
      v38 = 3;
    else
      v38 = 1;
    if ( v31 != v38 )
    {
      v47 = v16 & 0xFFFFFFFFF000LL;
      v48 = (unsigned int)(a6 + 1);
      if ( (unsigned __int64)(8LL << v12) >= 0x10000 )
        v47 = v16 & 0x7FFFFF0000LL;
      v49 = (v47 - memstart_addr) | 0xFFFFFF8000000000LL;
      return _arm_lpae_unmap(a1, a2, a3, a4, a5, v48, v49, a8);
    }
    v120 = *v15;
    v124 = a8;
    v118 = a5;
    v122 = a6 + 1;
    if ( a6 != 3 )
    {
      v39 = a3;
      v40 = a4;
      result = _arm_lpae_alloc_pages(a1, 8LL << v12, 2080, a1 + 4);
      if ( !result )
        return result;
      v42 = result;
      v43 = 1LL << (v12 * (3 - (unsigned __int8)a6) + 3);
      if ( v43 == v40 )
      {
        v44 = v10[52];
        v45 = a6 + 1;
        if ( v10[51] == v122 )
          v46 = v10[50] - v44;
        else
          LOBYTE(v46) = 0;
        v82 = v124;
        v84 = (v39 >> (v44 * (3 - (unsigned __int8)a6) + 3)) & ~(-1 << (v46 + v44));
        if ( (int)v17 - v84 >= (int)v118 )
          v83 = v118;
        else
          v83 = v17 - v84;
      }
      else
      {
        v82 = v124;
        v45 = a6 + 1;
        v83 = 0;
        v84 = -1;
      }
      v114 = 8LL << v12;
      v117 = v39;
      v126 = v40;
      v121 = v42;
      v115 = v83;
      v116 = v84;
      if ( (int)v17 < 1 )
      {
        v90 = 0;
      }
      else
      {
        v85 = v83 + v84;
        v86 = v84;
        v87 = v42 << 8;
        v88 = v85;
        v89 = 0;
        v90 = 0;
        v91 = v17 & 0x7FFFFFFF;
        v92 = v120 & 0x60000000000FFCLL;
        v119 = v85;
        if ( (unsigned __int64)(8LL << v10[52]) >= 0x10000 )
          v93 = v120 & 0xFFFFFFFF0000LL
              | ((unsigned __int64)(unsigned __int16)((v120 & 0xFFFFFFFFF000LL) >> 12) << 48) & 0xFFFFFFFFF0000LL;
        else
          v93 = v120 & 0xFFFFFFFFF000LL;
        do
        {
          if ( v89 < v86 || v89 >= v88 )
          {
            if ( *v10 != 5 && v45 == 3 )
              v95 = 3;
            else
              v95 = 1;
            *(_QWORD *)(v42 + 8 * v89) = v95 | v92 | (v93 | (v93 >> 36)) & 0xFFFFFFFFF000LL;
            if ( (v10[12] & 1) == 0 )
            {
              v96 = *((_QWORD *)v10 + 8);
              if ( (*(_BYTE *)(v96 + 844) & 0x40) == 0 )
              {
                v97 = (v87 >> 8) + 0x8000000000LL;
                v98 = v97 >> 38;
                v99 = memstart_addr + v97;
                if ( v98 )
                  v100 = (v87 >> 8) - kimage_voffset;
                else
                  v100 = v99;
                _dma_sync_single_for_device(v96, v100, 8, 1);
                v88 = v119;
                v92 = v120 & 0x60000000000FFCLL;
                v42 = v121;
                v45 = a6 + 1;
                v82 = v124;
              }
            }
            ++v90;
          }
          ++v89;
          v93 += v43;
          v87 += 2048;
        }
        while ( v91 != v89 );
      }
      v101 = arm_lpae_install_table(v42, v15, v120, v10 + 4, v90, v10, v82);
      if ( v101 == v120 )
      {
        v102 = v117;
        a5 = v118;
        v103 = v126;
        if ( (v116 & 0x80000000) == 0 )
        {
          v104 = *((_QWORD *)v10 + 1);
          v105 = *((void (__fastcall ***)(__int64, unsigned __int64, __int64))v10 + 30);
          v106 = *v105;
          v107 = (3562 - (1LL << (v10[52] * (2 - (unsigned __int8)a6) + 3))) & v117;
          if ( *((_DWORD *)*v105 - 1) != -716079766 )
            __break(0x8229u);
          v106(v104, v121, v107);
          return v115 * v126;
        }
        v49 = v121;
      }
      else
      {
        v103 = v126;
        v108 = v101;
        v102 = v117;
        if ( *((_BYTE *)v10 + 48) == 1 )
        {
          v109 = ((__int64)(v121 << 8) >> 8) + 0x8000000000LL;
        }
        else
        {
          v110 = (__int64)(v121 << 8) >> 8;
          v109 = v110 + 0x8000000000LL;
          v111 = v110 - kimage_voffset;
          if ( v109 >> 38 )
            v112 = v111;
          else
            v112 = memstart_addr + v109;
          dma_unmap_page_attrs(*((_QWORD *)v10 + 8), v112, v114, 1, 0);
        }
        qcom_io_pgtable_free_page((v109 >> 12 << 6) - 0x140000000LL);
        if ( (~(_BYTE)v108 & 3) != 0 )
          return 0;
        a5 = v118;
        v113 = v108 & 0xFFFFFFFFF000LL;
        if ( (unsigned __int64)(8LL << v10[52]) >= 0x10000 )
          v113 = v108 & 0x7FFFFF0000LL;
        v49 = (v113 - memstart_addr) | 0xFFFFFF8000000000LL;
      }
      a2 = v127;
      v48 = v122;
      a1 = v10;
      a8 = v124;
      a3 = v102;
      a4 = v103;
      return _arm_lpae_unmap(a1, a2, a3, a4, a5, v48, v49, a8);
    }
LABEL_141:
    __break(0x800u);
    return 0;
  }
  if ( (int)v17 - (int)v14 >= (int)a5 )
    v18 = a5;
  else
    v18 = v17 - v14;
  if ( v18 < 1 )
  {
    v36 = 0;
  }
  else
  {
    v123 = v18;
    v19 = 0;
    v20 = (v14 << 11) + (a7 << 8);
    v125 = a4;
    if ( (int)v17 - (int)v14 >= (__int64)(int)a5 )
      v21 = a5;
    else
      v21 = v17 - v14;
    while ( 1 )
    {
      v23 = v15[v19];
      if ( !v23 )
        break;
      v15[v19] = 0;
      if ( (v10[12] & 1) == 0 )
      {
        v24 = *((_QWORD *)v10 + 8);
        if ( (*(_BYTE *)(v24 + 844) & 0x40) == 0 )
        {
          v25 = (v20 >> 8) + 0x8000000000LL;
          v26 = v25 >> 38;
          v27 = memstart_addr + v25;
          if ( v26 )
            v28 = (v20 >> 8) - kimage_voffset;
          else
            v28 = v27;
          _dma_sync_single_for_device(v24, v28, 8, 1);
        }
      }
      if ( *v10 != 5 && a6 == 3 )
        v30 = 3;
      else
        v30 = 1;
      if ( (v23 & 3) == v30 )
      {
        if ( !v127 || (*(_BYTE *)(v127 + 40) & 1) == 0 )
          __dmb(0xAu);
      }
      else
      {
        v22 = v23 & 0xFFFFFFFFF000LL;
        if ( (unsigned __int64)(8LL << v10[52]) >= 0x10000 )
          v22 = (0x1000000001LL * (v23 & 0xFFFFFFFFF000LL)) & 0x7FFFFF0000LL;
        _arm_lpae_free_pgtable(v10, (unsigned int)(a6 + 1), (v22 - memstart_addr) | 0xFFFFFF8000000000LL, 1);
      }
      ++v19;
      v20 += 2048;
      if ( v21 == (_DWORD)v19 )
      {
        a4 = v125;
        v36 = v123;
        return v36 * a4;
      }
    }
    __break(0x800u);
    a4 = v125;
    v36 = v19;
  }
  return v36 * a4;
}
