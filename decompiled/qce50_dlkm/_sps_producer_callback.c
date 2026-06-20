_QWORD *__fastcall sps_producer_callback(_QWORD *result)
{
  __int64 v1; // x2
  unsigned int v2; // w19
  _QWORD *v3; // x24
  __int64 v4; // x8
  int v6; // w9
  _DWORD *v8; // x21
  __int64 v9; // x20
  unsigned int *v10; // x8
  char v11; // w10
  unsigned int v12; // w0
  unsigned int v13; // w9
  __int64 v14; // x2
  unsigned int v20; // w9
  __int64 *v22; // x1
  __int64 v23; // x0
  __int64 (__fastcall *v24)(__int64, __int64 *, __int64 *); // x26
  __int64 v25; // x20
  _QWORD *v26; // x22
  _QWORD *v27; // x23
  __int64 v28; // x21
  int v29; // w27
  char v30; // w9
  __int64 v31; // x10
  __int64 v32; // x11
  __int64 v33; // x9
  unsigned __int64 v34; // x9
  _DWORD *v35; // x11
  __int64 v36; // x9
  _QWORD *v37; // x19
  __int64 v38; // x20
  __int64 v39; // x21
  _QWORD *v40; // x22
  _QWORD *v41; // x23
  int v42; // w27
  __int64 v43; // x1
  __int64 v44; // x20
  __int64 v45; // x1
  unsigned int v46; // w0
  __int64 v47; // x2
  unsigned int v49; // w9
  __int64 v51; // x20
  int v52; // w26
  _DWORD *v53; // x23
  __int64 v54; // x21
  _QWORD *v55; // x22
  __int64 *v56; // x8
  __int64 v57; // x9
  __int64 v58; // x11
  __int64 v59; // x12
  char v60; // w10
  unsigned int v61; // w0
  unsigned int v62; // w9
  __int64 v63; // x2
  unsigned int v65; // w9
  unsigned int v68; // w9
  void *v69; // x0
  const char *v70; // x1
  int v71; // w27
  _BOOL4 v72; // w23
  _QWORD *v73; // x21
  int v74; // w23
  __int64 v75; // x22
  __int64 *v76; // x8
  __int64 v77; // x9
  __int64 v78; // x11
  __int64 v79; // x12
  unsigned int v80; // w0
  __int64 v81; // x8
  unsigned int v82; // w9
  __int64 v83; // x2
  unsigned int v85; // w9
  __int64 *v87; // x1
  __int64 v88; // x0
  __int64 v89; // x9
  __int64 v90; // x9
  __int64 v91; // x10
  unsigned int v93; // w9
  __int64 *v95; // x2
  int v96; // w27
  _BOOL4 v97; // w23
  unsigned int v98; // w0
  __int64 v99; // x9
  unsigned int v100; // w8
  __int64 v101; // x2
  int v102; // w8
  unsigned int v104; // w9
  __int64 v106; // x8
  __int64 v107; // x9
  __int64 v108; // x8
  unsigned int v110; // w9
  void *v112; // x0
  unsigned __int64 v113; // x8
  __int64 v114; // x8
  __int64 v115; // x9
  __int64 *v116; // x9
  __int64 v117; // x9
  __int64 v118; // x10
  int v119; // w8
  unsigned int v121; // w9
  unsigned int v124; // w9
  unsigned int v126; // w9
  unsigned int v129; // w9
  unsigned int v132; // w9
  unsigned int v136; // w10
  unsigned int v138; // w10
  unsigned int v140; // w10
  unsigned int v142; // w10
  unsigned int v144; // w10
  unsigned int v146; // w10
  unsigned int v148; // w10
  unsigned int v150; // w10
  unsigned int v152; // w10
  unsigned int v154; // w10
  unsigned int v156; // w10
  unsigned int v158; // w10
  unsigned int v160; // w10
  _QWORD v161[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v162; // [xsp+18h] [xbp-28h] BYREF
  __int64 v163; // [xsp+20h] [xbp-20h]
  __int64 v164; // [xsp+28h] [xbp-18h]
  __int64 v165; // [xsp+30h] [xbp-10h]
  __int64 v166; // [xsp+38h] [xbp-8h]

  v166 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = result[3];
  if ( WORD1(v1) != 57005 )
  {
    v69 = &unk_157DF;
    v70 = "_sps_producer_callback";
LABEL_96:
    result = (_QWORD *)printk(v69, v70, v1);
    goto LABEL_170;
  }
  v2 = (unsigned __int8)result[3];
  if ( v2 >= 9 )
  {
    v69 = &unk_157DF;
LABEL_94:
    v70 = "_sps_producer_callback";
    goto LABEL_95;
  }
  v3 = (_QWORD *)*result;
  v4 = *result + 7432LL * (unsigned __int8)result[3];
  if ( !*(_DWORD *)(v4 + 2624) )
  {
    v69 = &unk_14AC0;
    goto LABEL_94;
  }
  _X25 = v4 + 2624;
  if ( (*(_BYTE *)(v4 + 2628) & 1) == 0 )
  {
    v69 = &unk_162C9;
    goto LABEL_94;
  }
  v6 = *(_DWORD *)(v4 + 2632);
  _X8 = *(unsigned __int16 *)(v4 + 10044);
  *(_BYTE *)(_X25 + 4) = 0;
  if ( (unsigned int)(v6 - 1) <= 1 && !*(_DWORD *)(_X25 + 16) )
  {
    v30 = *(_BYTE *)(_X25 + 7429);
    *(_DWORD *)(_X25 + 16) = 2;
    if ( (v30 & 1) != 0 )
      goto LABEL_170;
    v32 = v3[2];
    v31 = v3[3];
    v33 = *(unsigned int *)(_X25 + 7264);
    *(_DWORD *)(_X25 + 80) = 0;
    v34 = v31 + v33 - v32;
    v35 = *(_DWORD **)(_X25 + 72);
    *v35 = v34;
    v35[1] = (v34 >> 16) & 0xF0000 | 0x80;
    v36 = *(unsigned int *)(_X25 + 80);
    *(_DWORD *)(_X25 + 80) = v36 + 1;
    if ( (_DWORD)v36 != -1 )
      *(_DWORD *)(*(_QWORD *)(_X25 + 72) + 8 * v36 + 4) |= 0x80000000;
    if ( (unsigned int)_X8 <= 5 )
    {
      v37 = &v3[23 * (unsigned int)_X8];
      result = (_QWORD *)sps_transfer(v37[52], _X25 + 64);
      if ( (_DWORD)result )
        result = (_QWORD *)printk(&unk_1591C, "_sps_producer_callback", v37[52]);
      goto LABEL_170;
    }
    goto LABEL_237;
  }
  if ( v6 <= 1 )
  {
    if ( v6 )
    {
      if ( v6 != 1 )
      {
LABEL_85:
        *(_DWORD *)(_X25 + 8) = 5;
        __asm { PRFM            #0x11, [X25] }
        do
          v68 = __ldxr((unsigned int *)_X25);
        while ( __stlxr(0, (unsigned int *)_X25) );
        __dmb(0xBu);
        if ( v68 )
        {
          if ( v2 == 8 )
            goto LABEL_170;
          _X8 = (unsigned __int64)(v3 + 8690);
          goto LABEL_238;
        }
        v69 = &unk_15B49;
        v70 = "qce_free_req_info";
        goto LABEL_95;
      }
      v162 = 0;
      v163 = 0;
      v24 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64 *))(_X25 + 7304);
      v25 = *(_QWORD *)(_X25 + 7328);
      if ( *(_BYTE *)(_X25 + 7430) == 1 )
      {
        v26 = *(_QWORD **)(v25 + 16);
        v27 = *(_QWORD **)(v25 + 24);
        v28 = *v3;
        if ( v26 == v27 )
        {
          v27 = *(_QWORD **)(v25 + 16);
        }
        else
        {
          v29 = *(_DWORD *)(_X25 + 7356);
          if ( v29 >= 1 )
          {
            do
            {
              if ( !v27 )
                break;
              dma_unmap_sg_attrs(v28, v27, 1, 2, 0);
              result = (_QWORD *)sg_next(v27);
              --v29;
              v27 = result;
            }
            while ( v29 );
            v26 = *(_QWORD **)(v25 + 16);
            v27 = *(_QWORD **)(v25 + 24);
            v28 = *v3;
          }
        }
        v96 = *(_DWORD *)(_X25 + 7352);
        v97 = v26 != v27;
        if ( v96 >= 1 )
        {
          do
          {
            if ( !v26 )
              break;
            dma_unmap_sg_attrs(v28, v26, 1, v97, 0);
            result = (_QWORD *)sg_next(v26);
            --v96;
            v26 = result;
          }
          while ( v96 );
        }
      }
      if ( (v3[16] & 1) == 0 && *((_BYTE *)v3 + 68) == 1 )
      {
        _X8 = *(unsigned __int16 *)(_X25 + 7420);
        if ( (unsigned int)_X8 > 5 )
          goto LABEL_237;
        v98 = sps_transfer_one(
                v3[23 * *(unsigned __int16 *)(_X25 + 7420) + 190],
                *(_QWORD *)(_X25 + 7040) + v3[3] - v3[2],
                0,
                0,
                2560);
        if ( v98 )
        {
          printk(&unk_14FAC, "_qce_unlock_other_pipes", v98);
          *(_DWORD *)(_X25 + 8) = 5;
          __asm { PRFM            #0x11, [X25] }
          do
            v129 = __ldxr((unsigned int *)_X25);
          while ( __stlxr(0, (unsigned int *)_X25) );
          __dmb(0xBu);
          if ( v129 )
          {
            if ( v2 != 8 )
            {
              _X8 = (unsigned int *)(v3 + 8690);
              __asm { PRFM            #0x11, [X8] }
              do
                v156 = __ldxr(_X8);
              while ( __stxr(v156 - 1, _X8) );
            }
          }
          else
          {
            printk(&unk_15B49, "qce_free_req_info", v2);
          }
          v88 = v25;
          v87 = nullptr;
          goto LABEL_222;
        }
      }
      v99 = *(_QWORD *)(_X25 + 7288);
      v100 = *(_DWORD *)(v99 + 96);
      *(_DWORD *)(v99 + 96) = 0;
      if ( *(_BYTE *)(_X25 + 7429) == 1 )
      {
        v101 = bswap32(v100);
        if ( (v101 & 0x104001) != 0 )
          printk(&unk_1566E, "_ablk_cipher_complete", v101);
      }
      if ( *(_QWORD *)(_X25 + 20) )
        printk(&unk_15DAB, "_ablk_cipher_complete", *(unsigned int *)(_X25 + 20));
      v102 = *(_DWORD *)(_X25 + 7388);
      if ( v102 == 1 )
      {
        *(_DWORD *)(_X25 + 8) = 5;
        __asm { PRFM            #0x11, [X25] }
        do
          v104 = __ldxr((unsigned int *)_X25);
        while ( __stlxr(0, (unsigned int *)_X25) );
        __dmb(0xBu);
        if ( v104 )
        {
          if ( v2 != 8 )
          {
            _X8 = (unsigned int *)(v3 + 8690);
            __asm { PRFM            #0x11, [X8] }
            do
              v144 = __ldxr(_X8);
            while ( __stxr(v144 - 1, _X8) );
          }
        }
        else
        {
          printk(&unk_15B49, "qce_free_req_info", v2);
        }
        v88 = v25;
        v87 = nullptr;
LABEL_152:
        v95 = nullptr;
LABEL_167:
        if ( *((_DWORD *)v24 - 1) != -1252068556 )
          __break(0x823Au);
        result = (_QWORD *)v24(v88, v87, v95);
        goto LABEL_170;
      }
      if ( !*((_DWORD *)v3 + 101) && *((_DWORD *)v3 + 102) <= 5u )
      {
        if ( !v102 )
        {
          if ( *(_DWORD *)(_X25 + 7384) == 1 )
          {
            v106 = *(_QWORD *)(_X25 + 7376);
            v107 = *(_QWORD *)(_X25 + 7368);
LABEL_159:
            v162 = v107;
            v163 = v106;
LABEL_160:
            if ( *(_DWORD *)_X25 )
            {
              *(_DWORD *)(_X25 + 8) = 5;
              __asm { PRFM            #0x11, [X25] }
              do
                v110 = __ldxr((unsigned int *)_X25);
              while ( __stlxr(0, (unsigned int *)_X25) );
              __dmb(0xBu);
              if ( v110 )
              {
                if ( v2 != 8 )
                {
                  _X8 = (unsigned int *)(v3 + 8690);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v150 = __ldxr(_X8);
                  while ( __stxr(v150 - 1, _X8) );
                }
              }
              else
              {
                printk(&unk_15B49, "qce_free_req_info", v2);
              }
              v95 = &v162;
              v88 = v25;
              v87 = nullptr;
              goto LABEL_167;
            }
            v69 = &unk_14AC0;
            v70 = "_ablk_cipher_complete";
LABEL_95:
            v1 = v2;
            goto LABEL_96;
          }
          v113 = (((**(_QWORD **)(v25 + 16) << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
               + *(unsigned int *)(*(_QWORD *)(v25 + 16) + 8LL)
               + (unsigned __int64)*(unsigned int *)(*(_QWORD *)(v25 + 16) + 12LL);
          v115 = *(_QWORD *)(v113 - 16);
          v114 = *(_QWORD *)(v113 - 8);
          v162 = v115;
          v163 = v114;
          v102 = *(_DWORD *)(_X25 + 7388);
        }
        if ( (v102 & 0xFFFFFFFE) == 2 )
        {
          v116 = *(__int64 **)(v25 + 8);
          v118 = *v116;
          v117 = v116[1];
          v162 = v118;
          v163 = v117;
          if ( v102 == 3 )
            v119 = 1;
          else
            v119 = *(_DWORD *)v25 >> 4;
          HIDWORD(v163) = bswap32(bswap32(HIDWORD(v163)) + v119);
        }
        goto LABEL_160;
      }
      v108 = *(_QWORD *)(_X25 + 7288);
      v107 = *(_QWORD *)(v108 + 80);
      v106 = *(_QWORD *)(v108 + 88);
      goto LABEL_159;
    }
    v51 = *(_QWORD *)(_X25 + 7328);
    if ( !v51 )
    {
      result = (_QWORD *)printk(&unk_160AE, "_sha_complete", v1);
      goto LABEL_170;
    }
    v52 = *(_DWORD *)(_X25 + 7352);
    v53 = *(_DWORD **)(_X25 + 7304);
    if ( v52 >= 1 )
    {
      v54 = *v3;
      v55 = *(_QWORD **)(v51 + 56);
      do
      {
        if ( !v55 )
          break;
        dma_unmap_sg_attrs(v54, v55, 1, 1, 0);
        result = (_QWORD *)sg_next(v55);
        --v52;
        v55 = result;
      }
      while ( v52 );
    }
    v56 = *(__int64 **)(_X25 + 7288);
    v57 = v56[3];
    v58 = *v56;
    v59 = v56[1];
    v164 = v56[2];
    v165 = v57;
    LODWORD(v57) = *((_DWORD *)v56 + 16);
    v60 = *((_BYTE *)v3 + 128);
    v162 = v58;
    v163 = v59;
    v161[0] = _byteswap_uint64(__PAIR64__(v57, *((_DWORD *)v56 + 17)));
    if ( (v60 & 1) == 0 && *((_BYTE *)v3 + 68) == 1 )
    {
      _X8 = *(unsigned __int16 *)(_X25 + 7420);
      if ( (unsigned int)_X8 > 5 )
        goto LABEL_237;
      v61 = sps_transfer_one(
              v3[23 * *(unsigned __int16 *)(_X25 + 7420) + 190],
              *(_QWORD *)(_X25 + 7040) + v3[3] - v3[2],
              0,
              0,
              2560);
      if ( v61 )
      {
        printk(&unk_14FAC, "_qce_unlock_other_pipes", v61);
        *(_DWORD *)(_X25 + 8) = 5;
        __asm { PRFM            #0x11, [X25] }
        do
          v132 = __ldxr((unsigned int *)_X25);
        while ( __stlxr(0, (unsigned int *)_X25) );
        __dmb(0xBu);
        if ( v132 )
        {
          if ( v2 != 8 )
          {
            _X8 = (unsigned int *)(v3 + 8690);
            __asm { PRFM            #0x11, [X8] }
            do
              v160 = __ldxr(_X8);
            while ( __stxr(v160 - 1, _X8) );
          }
        }
        else
        {
          printk(&unk_15B49, "qce_free_req_info", v2);
        }
        if ( *(v53 - 1) != -1252068556 )
          __break(0x8237u);
        result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD *, __int64))v53)(
                             v51,
                             &v162,
                             v161,
                             4294967290LL);
        goto LABEL_170;
      }
      v56 = *(__int64 **)(_X25 + 7288);
    }
    v62 = *((_DWORD *)v56 + 24);
    *((_DWORD *)v56 + 24) = 0;
    v63 = bswap32(v62);
    if ( (v63 & 0x104001) != 0 )
    {
      v112 = &unk_1512F;
    }
    else
    {
      v63 = *(unsigned int *)(_X25 + 20);
      if ( !(_DWORD)v63 )
      {
        if ( *(_DWORD *)_X25 )
          goto LABEL_77;
        goto LABEL_184;
      }
      v112 = &unk_15C6C;
    }
    printk(v112, "_sha_complete", v63);
    if ( *(_DWORD *)_X25 )
    {
LABEL_77:
      *(_DWORD *)(_X25 + 8) = 5;
      __asm { PRFM            #0x11, [X25] }
      do
        v65 = __ldxr((unsigned int *)_X25);
      while ( __stlxr(0, (unsigned int *)_X25) );
      __dmb(0xBu);
      if ( v65 )
      {
        if ( v2 != 8 )
        {
          _X8 = (unsigned int *)(v3 + 8690);
          __asm { PRFM            #0x11, [X8] }
          do
            v142 = __ldxr(_X8);
          while ( __stxr(v142 - 1, _X8) );
        }
      }
      else
      {
        printk(&unk_15B49, "qce_free_req_info", v2);
      }
      if ( *(v53 - 1) != -1252068556 )
        __break(0x8237u);
      result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD *))v53)(v51, &v162, v161);
      goto LABEL_170;
    }
LABEL_184:
    v69 = &unk_14AC0;
    v70 = "_sha_complete";
    goto LABEL_95;
  }
  if ( v6 == 2 )
  {
    v164 = 0;
    v165 = 0;
    v162 = 0;
    v163 = 0;
    v38 = *(_QWORD *)(_X25 + 7328);
    v24 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64 *))(_X25 + 7304);
    v39 = *v3;
    v40 = *(_QWORD **)(v38 + 64);
    v41 = *(_QWORD **)(v38 + 72);
    if ( v40 == v41 )
    {
      v41 = *(_QWORD **)(v38 + 64);
    }
    else
    {
      v42 = *(_DWORD *)(_X25 + 7356);
      if ( v42 >= 1 )
      {
        do
        {
          if ( !v41 )
            break;
          dma_unmap_sg_attrs(v39, v41, 1, 2, 0);
          result = (_QWORD *)sg_next(v41);
          --v42;
          v41 = result;
        }
        while ( v42 );
        v40 = *(_QWORD **)(v38 + 64);
        v41 = *(_QWORD **)(v38 + 72);
        v39 = *v3;
      }
    }
    v71 = *(_DWORD *)(_X25 + 7352);
    v72 = v40 != v41;
    if ( v71 >= 1 )
    {
      do
      {
        if ( !v40 )
          break;
        dma_unmap_sg_attrs(v39, v40, 1, v72, 0);
        result = (_QWORD *)sg_next(v40);
        --v71;
        v40 = result;
      }
      while ( v71 );
    }
    v73 = *(_QWORD **)(_X25 + 7344);
    if ( v73 )
    {
      v74 = *(_DWORD *)(_X25 + 7336);
      if ( v74 >= 1 )
      {
        v75 = *v3;
        do
        {
          if ( !v73 )
            break;
          dma_unmap_sg_attrs(v75, v73, 1, 1, 0);
          result = (_QWORD *)sg_next(v73);
          --v74;
          v73 = result;
        }
        while ( v74 );
      }
    }
    v76 = *(__int64 **)(_X25 + 7288);
    v77 = v76[3];
    v78 = *v76;
    v79 = v76[1];
    v164 = v76[2];
    v165 = v77;
    v162 = v78;
    v163 = v79;
    if ( *(_DWORD *)(_X25 + 7384) == 1 )
    {
      if ( *((_BYTE *)v3 + 128) == 1 )
      {
        if ( (v3[16] & 1) != 0 )
          goto LABEL_116;
      }
      else
      {
        result = (_QWORD *)readl_relaxed((unsigned int *)(v3[10] + 106752LL));
        if ( (v3[16] & 1) != 0 )
          goto LABEL_116;
      }
    }
    else if ( (v3[16] & 1) != 0 )
    {
      goto LABEL_116;
    }
    if ( *((_BYTE *)v3 + 68) != 1 )
      goto LABEL_116;
    _X8 = *(unsigned __int16 *)(_X25 + 7420);
    if ( (unsigned int)_X8 > 5 )
      goto LABEL_237;
    v80 = sps_transfer_one(
            v3[23 * *(unsigned __int16 *)(_X25 + 7420) + 190],
            *(_QWORD *)(_X25 + 7040) + v3[3] - v3[2],
            0,
            0,
            2560);
    if ( !v80 )
    {
LABEL_116:
      v81 = *(_QWORD *)(_X25 + 7288);
      v82 = *(_DWORD *)(v81 + 96);
      *(_DWORD *)(v81 + 96) = 0;
      v83 = bswap32(v82);
      if ( (v83 & 0x104001) != 0 )
      {
        printk(&unk_14CA7, "_aead_complete", v83);
      }
      else
      {
        if ( !*(_QWORD *)(_X25 + 20) )
        {
          if ( *(_DWORD *)_X25 )
          {
LABEL_119:
            if ( *(_DWORD *)(_X25 + 7388) != 4 )
            {
              v89 = *(_QWORD *)(_X25 + 7288);
              v91 = *(_QWORD *)(v89 + 80);
              v90 = *(_QWORD *)(v89 + 88);
              v161[0] = v91;
              v161[1] = v90;
              *(_DWORD *)(_X25 + 8) = 5;
              __asm { PRFM            #0x11, [X25] }
              do
                v93 = __ldxr((unsigned int *)_X25);
              while ( __stlxr(0, (unsigned int *)_X25) );
              __dmb(0xBu);
              if ( v93 )
              {
                if ( v2 != 8 )
                {
                  _X8 = (unsigned int *)(v3 + 8690);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v148 = __ldxr(_X8);
                  while ( __stxr(v148 - 1, _X8) );
                }
              }
              else
              {
                printk(&unk_15B49, "qce_free_req_info", v2);
              }
              v87 = &v162;
              v95 = v161;
              v88 = v38;
              goto LABEL_167;
            }
            *(_DWORD *)(_X25 + 8) = 5;
            __asm { PRFM            #0x11, [X25] }
            do
              v85 = __ldxr((unsigned int *)_X25);
            while ( __stlxr(0, (unsigned int *)_X25) );
            __dmb(0xBu);
            if ( v85 )
            {
              if ( v2 != 8 )
              {
                _X8 = (unsigned int *)(v3 + 8690);
                __asm { PRFM            #0x11, [X8] }
                do
                  v146 = __ldxr(_X8);
                while ( __stxr(v146 - 1, _X8) );
              }
            }
            else
            {
              printk(&unk_15B49, "qce_free_req_info", v2);
            }
            v87 = &v162;
            v88 = v38;
            goto LABEL_152;
          }
          goto LABEL_180;
        }
        printk(&unk_156A3, "_aead_complete", *(unsigned int *)(_X25 + 20));
      }
      if ( *(_DWORD *)_X25 )
        goto LABEL_119;
LABEL_180:
      v69 = &unk_14AC0;
      v70 = "_aead_complete";
      goto LABEL_95;
    }
    printk(&unk_14FAC, "_qce_unlock_other_pipes", v80);
    *(_DWORD *)(_X25 + 8) = 5;
    __asm { PRFM            #0x11, [X25] }
    do
      v121 = __ldxr((unsigned int *)_X25);
    while ( __stlxr(0, (unsigned int *)_X25) );
    __dmb(0xBu);
    if ( v121 )
    {
      if ( v2 != 8 )
      {
        _X8 = (unsigned int *)(v3 + 8690);
        __asm { PRFM            #0x11, [X8] }
        do
          v152 = __ldxr(_X8);
        while ( __stxr(v152 - 1, _X8) );
      }
    }
    else
    {
      printk(&unk_15B49, "qce_free_req_info", v2);
    }
    v87 = &v162;
    v88 = v38;
LABEL_222:
    v95 = nullptr;
    goto LABEL_167;
  }
  if ( v6 == 3 )
  {
    v43 = *(_QWORD *)(_X25 + 7400);
    v8 = *(_DWORD **)(_X25 + 7304);
    v44 = *(_QWORD *)(_X25 + 7328);
    if ( v43 )
      result = (_QWORD *)dma_unmap_page_attrs(*v3, v43, *(unsigned int *)(_X25 + 7408), 2, 0);
    v45 = *(_QWORD *)(_X25 + 7392);
    if ( v45 )
      result = (_QWORD *)dma_unmap_page_attrs(
                           *v3,
                           v45,
                           *(unsigned int *)(_X25 + 7408),
                           *(_QWORD *)(_X25 + 7400) != 0,
                           0);
    if ( (v3[16] & 1) != 0 || *((_BYTE *)v3 + 68) != 1 )
      goto LABEL_52;
    _X8 = *(unsigned __int16 *)(_X25 + 7420);
    if ( (unsigned int)_X8 <= 5 )
    {
      v46 = sps_transfer_one(
              v3[23 * *(unsigned __int16 *)(_X25 + 7420) + 190],
              *(_QWORD *)(_X25 + 7040) + v3[3] - v3[2],
              0,
              0,
              2560);
      if ( v46 )
      {
        printk(&unk_14FAC, "_qce_unlock_other_pipes", v46);
        *(_DWORD *)(_X25 + 8) = 5;
        __asm { PRFM            #0x11, [X25] }
        do
          v124 = __ldxr((unsigned int *)_X25);
        while ( __stlxr(0, (unsigned int *)_X25) );
        __dmb(0xBu);
        if ( v124 )
        {
          if ( v2 != 8 )
          {
            _X8 = (unsigned int *)(v3 + 8690);
            __asm { PRFM            #0x11, [X8] }
            do
              v158 = __ldxr(_X8);
            while ( __stxr(v158 - 1, _X8) );
          }
          goto LABEL_60;
        }
        goto LABEL_175;
      }
LABEL_52:
      v47 = bswap32(*(_DWORD *)(*(_QWORD *)(_X25 + 7288) + 96LL));
      if ( (v47 & 0x104001) != 0 )
      {
        printk(&unk_161DB, "_f8_complete", v47);
      }
      else if ( *(_QWORD *)(_X25 + 20) )
      {
        printk(&unk_160DE, "_f8_complete", *(unsigned int *)(_X25 + 20));
      }
      *(_DWORD *)(*(_QWORD *)(_X25 + 7288) + 96LL) = 0;
      *(_DWORD *)(*(_QWORD *)(_X25 + 7288) + 100LL) = 0;
      *(_DWORD *)(_X25 + 8) = 5;
      __asm { PRFM            #0x11, [X25] }
      do
        v49 = __ldxr((unsigned int *)_X25);
      while ( __stlxr(0, (unsigned int *)_X25) );
      __dmb(0xBu);
      if ( v49 )
      {
        if ( v2 != 8 )
        {
          _X8 = (unsigned int *)(v3 + 8690);
          __asm { PRFM            #0x11, [X8] }
          do
            v140 = __ldxr(_X8);
          while ( __stxr(v140 - 1, _X8) );
        }
        goto LABEL_60;
      }
LABEL_175:
      printk(&unk_15B49, "qce_free_req_info", v2);
LABEL_60:
      v23 = v44;
      v22 = nullptr;
LABEL_61:
      if ( *(v8 - 1) != -1252068556 )
        __break(0x8235u);
      result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))v8)(v23, v22, 0);
      goto LABEL_170;
    }
LABEL_237:
    __break(0x5512u);
LABEL_238:
    __asm { PRFM            #0x11, [X8] }
    do
      v136 = __ldxr((unsigned int *)_X8);
    while ( __stxr(v136 - 1, (unsigned int *)_X8) );
    goto LABEL_170;
  }
  if ( v6 != 4 )
    goto LABEL_85;
  v8 = *(_DWORD **)(_X25 + 7304);
  v9 = *(_QWORD *)(_X25 + 7328);
  result = (_QWORD *)dma_unmap_page_attrs(*v3, *(_QWORD *)(_X25 + 7392), *(unsigned int *)(_X25 + 7408), 1, 0);
  v10 = *(unsigned int **)(_X25 + 7288);
  v11 = *((_BYTE *)v3 + 128);
  LODWORD(v162) = bswap32(*v10);
  if ( (v11 & 1) != 0 || *((_BYTE *)v3 + 68) != 1 )
    goto LABEL_16;
  _X8 = *(unsigned __int16 *)(_X25 + 7420);
  if ( (unsigned int)_X8 > 5 )
    goto LABEL_237;
  v12 = sps_transfer_one(
          v3[23 * *(unsigned __int16 *)(_X25 + 7420) + 190],
          *(_QWORD *)(_X25 + 7040) + v3[3] - v3[2],
          0,
          0,
          2560);
  if ( !v12 )
  {
    v10 = *(unsigned int **)(_X25 + 7288);
LABEL_16:
    v13 = v10[24];
    v10[24] = 0;
    v14 = bswap32(v13);
    if ( (v14 & 0x104001) != 0 )
    {
      printk(&unk_15951, "_f9_complete", v14);
    }
    else if ( *(_QWORD *)(_X25 + 20) )
    {
      printk(&unk_16213, "_f9_complete", *(unsigned int *)(_X25 + 20));
    }
    *(_DWORD *)(_X25 + 8) = 5;
    __asm { PRFM            #0x11, [X25] }
    do
      v20 = __ldxr((unsigned int *)_X25);
    while ( __stlxr(0, (unsigned int *)_X25) );
    __dmb(0xBu);
    if ( v20 )
    {
      if ( v2 != 8 )
      {
        _X8 = (unsigned int *)(v3 + 8690);
        __asm { PRFM            #0x11, [X8] }
        do
          v138 = __ldxr(_X8);
        while ( __stxr(v138 - 1, _X8) );
      }
    }
    else
    {
      printk(&unk_15B49, "qce_free_req_info", v2);
    }
    v22 = &v162;
    v23 = v9;
    goto LABEL_61;
  }
  printk(&unk_14FAC, "_qce_unlock_other_pipes", v12);
  *(_DWORD *)(_X25 + 8) = 5;
  __asm { PRFM            #0x11, [X25] }
  do
    v126 = __ldxr((unsigned int *)_X25);
  while ( __stlxr(0, (unsigned int *)_X25) );
  __dmb(0xBu);
  if ( v126 )
  {
    if ( v2 != 8 )
    {
      _X8 = (unsigned int *)(v3 + 8690);
      __asm { PRFM            #0x11, [X8] }
      do
        v154 = __ldxr(_X8);
      while ( __stxr(v154 - 1, _X8) );
    }
  }
  else
  {
    printk(&unk_15B49, "qce_free_req_info", v2);
  }
  if ( *(v8 - 1) != -1252068556 )
    __break(0x8235u);
  result = (_QWORD *)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v8)(v9, 0, 0, 4294967290LL);
LABEL_170:
  _ReadStatusReg(SP_EL0);
  return result;
}
