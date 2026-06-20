_DWORD *__fastcall start_qcrypto_process(_DWORD *result, __int64 a2)
{
  unsigned __int64 StatusReg; // x19
  _DWORD *v3; // x28
  __int64 v5; // x8
  __int64 v6; // x26
  __int64 v7; // x19
  __int64 v8; // x25
  _QWORD *v9; // x0
  __int64 v10; // x1
  __int64 (**v11)(void); // x8
  _QWORD *v12; // x27
  unsigned int v13; // w8
  unsigned __int8 v20; // w10
  _QWORD *v21; // x8
  _QWORD *v22; // x1
  _QWORD *v23; // x2
  _QWORD *v24; // x9
  _QWORD *v25; // x24
  int v26; // w21
  int v27; // w8
  void (__fastcall *v28)(__int64, __int64); // x8
  int v29; // w26
  __int64 (*v30)(void); // x8
  _QWORD *v31; // x21
  __int64 v32; // x19
  __int64 v33; // x12
  _DWORD *v34; // x13
  __int64 v35; // x9
  __int64 v36; // x25
  unsigned int v37; // w22
  int v38; // w8
  int v39; // w21
  int v40; // w28
  __int64 v41; // x9
  _DWORD *v42; // x10
  int v43; // w11
  int v44; // w12
  __int64 v45; // x8
  int v46; // w11
  __int64 v47; // x1
  __int64 v48; // x19
  __int64 v49; // x9
  int v50; // w12
  unsigned int v51; // w8
  unsigned int v52; // w10
  int v53; // w13
  _QWORD *v54; // x8
  int v55; // w13
  int v56; // w11
  int v57; // w10
  unsigned int v58; // w22
  __int64 v59; // x9
  __int64 v60; // x10
  int v61; // w12
  __int64 v62; // x25
  int v63; // w8
  char v64; // w10
  int v65; // w11
  char v66; // w8
  char v67; // w9
  int v68; // w3
  int v69; // w9
  _QWORD *v70; // x8
  unsigned int v71; // w21
  unsigned __int64 v72; // x1
  unsigned __int64 v73; // x22
  int v74; // w2
  __int64 v75; // x8
  unsigned int v76; // w10
  unsigned int v77; // w9
  __int64 v78; // x26
  _DWORD *v79; // x21
  __int64 v80; // x0
  __int64 v81; // x11
  int v82; // w9
  int v83; // w11
  int v84; // w8
  unsigned int v85; // w22
  char *v86; // x25
  int v87; // w9
  int v88; // w21
  int v89; // w22
  __int64 v90; // x26
  __int64 v91; // x0
  int v92; // w28
  __int64 v93; // x21
  __int64 v94; // x0
  unsigned __int64 *v95; // x8
  unsigned __int64 v96; // x9
  __int64 v97; // x10
  int v98; // w11
  _QWORD *v99; // x9
  unsigned int v102; // w8
  unsigned int v103; // w8
  unsigned __int8 v106; // w10
  __int64 v107; // x8
  unsigned int v110; // w9
  _DWORD *v111; // [xsp+8h] [xbp-138h]
  _DWORD *v112; // [xsp+8h] [xbp-138h]
  __int64 v113; // [xsp+10h] [xbp-130h]
  _DWORD *v114; // [xsp+20h] [xbp-120h]
  __int64 v115; // [xsp+20h] [xbp-120h]
  __int64 (**v116)(void); // [xsp+38h] [xbp-108h]
  __int64 v117; // [xsp+40h] [xbp-100h]
  __int128 v118; // [xsp+48h] [xbp-F8h]
  __int64 (**v119)(void); // [xsp+58h] [xbp-E8h]
  _QWORD *v120; // [xsp+60h] [xbp-E0h]
  __int64 *v121; // [xsp+68h] [xbp-D8h]
  _QWORD *v122; // [xsp+68h] [xbp-D8h]
  _QWORD *v123; // [xsp+68h] [xbp-D8h]
  __int64 (__fastcall *v124)(int, void *); // [xsp+78h] [xbp-C8h] BYREF
  __int64 (__fastcall *v125)(int, int, void *); // [xsp+80h] [xbp-C0h]
  __int64 v126; // [xsp+88h] [xbp-B8h]
  _DWORD *v127; // [xsp+90h] [xbp-B0h]
  unsigned __int64 v128; // [xsp+98h] [xbp-A8h]
  __int64 v129; // [xsp+A0h] [xbp-A0h]
  __int64 v130; // [xsp+A8h] [xbp-98h]
  __int64 v131; // [xsp+B0h] [xbp-90h]
  __int64 v132; // [xsp+B8h] [xbp-88h]
  __int64 v133; // [xsp+C0h] [xbp-80h]
  __int64 v134; // [xsp+C8h] [xbp-78h] BYREF
  __int64 v135; // [xsp+D0h] [xbp-70h]
  __int64 v136; // [xsp+D8h] [xbp-68h]
  __int64 v137; // [xsp+E0h] [xbp-60h]
  __int64 v138; // [xsp+E8h] [xbp-58h]
  _QWORD *v139; // [xsp+F0h] [xbp-50h]
  __int64 v140; // [xsp+F8h] [xbp-48h]
  __int64 v141; // [xsp+100h] [xbp-40h]
  __int64 v142; // [xsp+108h] [xbp-38h]
  __int64 v143; // [xsp+110h] [xbp-30h]
  __int64 v144; // [xsp+118h] [xbp-28h]
  __int64 v145; // [xsp+120h] [xbp-20h]
  __int64 v146; // [xsp+128h] [xbp-18h]
  __int64 v147; // [xsp+130h] [xbp-10h]

  v147 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result[71] )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v3 = result;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    {
      LODWORD(v5) = *(_DWORD *)(StatusReg + 40);
      if ( (unsigned int)v5 >= 7 )
        v5 = 7;
      else
        v5 = (unsigned int)v5;
    }
    else
    {
      v5 = 8;
    }
    *((_QWORD *)&v118 + 1) = v5;
    v6 = raw_spin_lock_irqsave(result + 13);
    if ( (*(_BYTE *)(a2 + 252) & 1) == 0 )
    {
      v7 = a2 + 48;
      v116 = (__int64 (**)(void))(v3 + 48);
      v119 = nullptr;
      v117 = a2 + 48;
      *(_QWORD *)&v118 = v3 + 87;
      do
      {
        if ( *(_DWORD *)(a2 + 248) >= *(_DWORD *)(a2 + 236) )
          break;
        v8 = *(_QWORD *)(a2 + 64) == v7 ? 0LL : *(_QWORD *)(a2 + 64);
        if ( *(_DWORD *)(a2 + 112) != 1 )
          break;
        v9 = (_QWORD *)crypto_dequeue_request(v7);
        if ( !v9 )
        {
          v11 = *((__int64 (***)(void))v3 + 26);
          if ( v11 == v116 )
            v11 = nullptr;
          v119 = v11;
          v9 = (_QWORD *)crypto_dequeue_request(v116);
          if ( !v9 )
            break;
        }
        if ( !*(_DWORD *)(a2 + 236) )
          goto LABEL_149;
        v12 = *(_QWORD **)(a2 + 240);
        v13 = 0;
        while ( 1 )
        {
          _X9 = (unsigned __int8 *)v12 + 4;
          __asm { PRFM            #0x11, [X9] }
          do
            v20 = __ldxr(_X9);
          while ( __stlxr(1u, _X9) );
          __dmb(0xBu);
          if ( !v20 )
            break;
          ++v13;
          v12 += 5;
          if ( v13 >= *(_DWORD *)(a2 + 236) )
            goto LABEL_149;
        }
        _X9 = (unsigned int *)(a2 + 248);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v102 = __ldxr(_X9);
          v103 = v102 + 1;
        }
        while ( __stlxr(v103, _X9) );
        __dmb(0xBu);
        if ( v103 > *(_DWORD *)(a2 + 260) )
          *(_DWORD *)(a2 + 260) = v103;
        if ( !v12 )
        {
LABEL_149:
          printk(&unk_12747, v10);
          break;
        }
        v21 = (_QWORD *)v9[4];
        v22 = (_QWORD *)v21[5];
        v23 = v21 + 4;
        v120 = v21 + 4;
        v24 = (_QWORD *)*v22;
        if ( (*(_DWORD *)(v21[3] + 32LL) & 0xF) == 5 )
        {
          v25 = v9 + 6;
          v26 = 5;
          if ( v22 != v9 + 6 && v25 != v23 && v24 == v23 )
          {
            v21[5] = v25;
            v9[6] = v23;
            v9[7] = v22;
            goto LABEL_38;
          }
        }
        else
        {
          v25 = v9 + 10;
          v26 = *(_DWORD *)(v21[3] + 32LL) & 0xF;
          if ( v22 != v9 + 10 && v25 != v23 && v24 == v23 )
          {
            v21[5] = v25;
            v9[10] = v23;
            v9[11] = v22;
LABEL_38:
            *v22 = v25;
            goto LABEL_39;
          }
        }
        _list_add_valid_or_report(v25);
        v9 = v99;
LABEL_39:
        v25[3] = v9;
        *((_DWORD *)v25 + 8) = -115;
        v12[2] = v9;
        v12[1] = a2;
        v12[3] = v25;
        v121 = v12 + 2;
        v27 = *(_DWORD *)(a2 + 224);
        *(_BYTE *)(a2 + 232) = 1;
        *(_BYTE *)(a2 + 252) = 1;
        *(_DWORD *)(a2 + 224) = v27 + 1;
        ++*(_DWORD *)(v118 + 4LL * *((_QWORD *)&v118 + 1));
        __dmb(0xBu);
        raw_spin_unlock_irqrestore(v3 + 13, v6);
        if ( v8 )
        {
          v28 = *(void (__fastcall **)(__int64, __int64))(v8 + 16);
          if ( *((_DWORD *)v28 - 1) != 1607364836 )
            __break(0x8228u);
          v28(v8, 4294967181LL);
        }
        result = v119;
        v29 = v26;
        if ( v119 )
        {
          v30 = v119[2];
          if ( *((_DWORD *)v30 - 1) != 1607364836 )
            __break(0x8228u);
          result = (_DWORD *)v30();
        }
        v31 = v12 + 2;
        switch ( v29 )
        {
          case 3:
            v145 = 0;
            v146 = 0;
            v143 = 0;
            v144 = 0;
            v141 = 0;
            v142 = 0;
            v140 = 0;
            v138 = 0;
            v139 = nullptr;
            v136 = 0;
            v137 = 0;
            v134 = 0;
            v135 = 0;
            v132 = 0;
            v133 = 0;
            v130 = 0;
            v131 = 0;
            v128 = 0;
            v129 = 0;
            v126 = 0;
            v127 = nullptr;
            v48 = *v121;
            v125 = nullptr;
            v124 = (__int64 (__fastcall *)(int, void *))&unk_2;
            v49 = *(_QWORD *)(v48 + 32);
            *(_QWORD *)(v48 + 120) = a2;
            v50 = *(_DWORD *)(v48 + 216);
            v125 = (__int64 (__fastcall *)(int, int, void *))&qce_aead_complete;
            v51 = *(_DWORD *)(v48 + 208);
            v52 = *(_DWORD *)(v48 + 212);
            v53 = *(_DWORD *)(v49 + 216);
            v127 = (_DWORD *)v48;
            v137 = v49 + 152;
            v128 = __PAIR64__(v52, v51);
            v54 = *(_QWORD **)(v48 + 128);
            LODWORD(v138) = v53;
            v55 = *(_DWORD *)(v49 + 224);
            LODWORD(v129) = v50;
            v139 = v54;
            v130 = v49 + 72;
            LODWORD(v131) = v55;
            v56 = *(_DWORD *)(v49 - 8);
            HIDWORD(v129) = *(_DWORD *)(v49 + 68);
            HIDWORD(v131) = v56;
            if ( v50 != 4 )
            {
              v7 = v117;
              LODWORD(v140) = *(_DWORD *)(*(_QWORD *)(v49 + 24) - 16LL);
              LODWORD(v143) = *(_DWORD *)(v49 + 64);
              goto LABEL_128;
            }
            LODWORD(v140) = 16;
            if ( v52 )
              v57 = v56;
            else
              v57 = 0;
            LODWORD(v143) = *(_DWORD *)(v49 + 64);
            v58 = *(_DWORD *)(v48 + 52) - v57;
            LODWORD(v141) = v58;
            v59 = *v54;
            v60 = v54[1];
            v61 = *(_DWORD *)(v48 + 48);
            v62 = *(unsigned __int8 *)v54;
            v63 = *(_DWORD *)(v48 + 160);
            v132 = v59;
            v133 = v60;
            v64 = ((4 * v56) & 0xF8) - 8;
            if ( v63 )
              v65 = v61 - 8;
            else
              v65 = v61;
            v66 = v59 | v64;
            v67 = v59 | v64 | 0x40;
            if ( v65 )
              v66 = v67;
            LOBYTE(v132) = v66;
            if ( (unsigned int)v62 <= 0xF )
            {
              v71 = v62 + 1;
              result = memset((char *)&v134 - v62 - 1, 0, v62 + 1);
              if ( (unsigned int)v62 <= 2 )
              {
                if ( 1 << (8 * v71) < v58 )
                {
                  v7 = v117;
                  v31 = v122;
                  v68 = -75;
                  break;
                }
              }
              else
              {
                v71 = 4;
              }
              if ( 80 - (unsigned __int64)v71 <= 0xB8 )
                v72 = v71 + 104LL;
              else
                v72 = 0;
              if ( v72 < v71 )
              {
                result = (_DWORD *)_fortify_panic(17);
LABEL_153:
                __break(1u);
                return (_DWORD *)list_add_tail(result);
              }
              memcpy((char *)&v134 - v71, (char *)&v124 - v71, v71);
              v31 = v123;
              if ( !(_DWORD)v115 )
              {
                LODWORD(v135) = 0;
                *(_QWORD *)(v48 + 200) = 0;
                goto LABEL_125;
              }
              v73 = (unsigned int)(v115 + 100);
              result = (_DWORD *)_kmalloc_noprof(v73, 2336);
              *(_QWORD *)(v48 + 200) = result;
              if ( result )
              {
                v74 = v115;
                v75 = *(_QWORD *)(v48 + 64);
                if ( (unsigned int)v115 >> 8 >= 0xFF )
                {
                  if ( v73 < 6 )
                    goto LABEL_153;
                  LOWORD(v76) = -257;
                  *(_DWORD *)((char *)result + 2) = bswap32(v115);
                  v77 = 6;
                }
                else
                {
                  if ( v73 < 2 )
                    goto LABEL_153;
                  v76 = bswap32(v115) >> 16;
                  v77 = 2;
                }
                v85 = 0;
                *(_WORD *)result = v76;
                LODWORD(v135) = (v115 + v77 + 15) & 0xFFFFFFF0;
                if ( (int)v115 >= 1 && v75 )
                {
                  v86 = (char *)result + v77;
                  v87 = 1;
                  v88 = 1;
                  v89 = v115;
                  v90 = v75;
                  v91 = v75;
                  v112 = v3;
                  do
                  {
                    v92 = v87;
                    v89 -= *(_DWORD *)(v91 + 12);
                    v91 = ((__int64 (*)(void))sg_next)();
                    --v88;
                    if ( v89 < 1 )
                      break;
                    v87 = v92 + 1;
                  }
                  while ( v91 );
                  if ( v88 == 1 )
                  {
                    v85 = 0;
                  }
                  else
                  {
                    v93 = v115;
                    v85 = 0;
                    do
                    {
                      v94 = sg_copy_to_buffer(v90, 1, v86, v93);
                      v86 += v94;
                      v93 -= v94;
                      v85 += v94;
                      --v92;
                      v90 = sg_next(v90);
                    }
                    while ( v92 );
                  }
                  v3 = v112;
                  v29 = 3;
                  v31 = v123;
                  v74 = v115;
                }
                if ( v85 != v74 )
                  printk(&unk_12B4A, v85);
LABEL_125:
                v95 = (unsigned __int64 *)(v48 + 168);
                v96 = *(_QWORD *)(v48 + 168);
                v97 = *(_QWORD *)(v48 + 200);
                v136 = v48 + 168;
                if ( v97 )
                {
                  v98 = v135;
                  *(_DWORD *)(v48 + 176) = v97 & 0xFFF;
                  *(_DWORD *)(v48 + 180) = v98;
                  v96 = ((unsigned __int64)((v97 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
                }
                v7 = v117;
                *v95 = v96 & 0xFFFFFFFFFFFFFFFCLL | 2;
LABEL_128:
                result = (_DWORD *)qce_aead_req(*(_QWORD *)(a2 + 16), &v124);
                v68 = (int)result;
                break;
              }
              v68 = -12;
            }
            else
            {
              v68 = -22;
            }
            v7 = v117;
            break;
          case 15:
            v134 = 0;
            v135 = 0;
            v132 = 0;
            v133 = 0;
            v130 = 0;
            v131 = 0;
            v128 = 0;
            v129 = 0;
            v126 = 0;
            v127 = nullptr;
            v41 = *v121;
            v124 = qce_ahash_complete;
            v125 = nullptr;
            v42 = *(_DWORD **)(v41 + 56);
            v43 = *(_DWORD *)(v41 + 200);
            v44 = *(unsigned __int8 *)(v41 + 225);
            *(_QWORD *)(v41 + 120) = a2;
            v126 = v41 + 456;
            v127 = v42;
            v45 = *(_QWORD *)(v41 + 32);
            LODWORD(v128) = v43;
            HIDWORD(v128) = *(_DWORD *)(v41 + 204);
            LODWORD(v42) = *(unsigned __int8 *)(v41 + 224);
            LODWORD(v129) = *(_DWORD *)(v41 + 208);
            v46 = *(_DWORD *)(v41 + 212);
            BYTE4(v132) = (_DWORD)v42 != 0;
            BYTE5(v132) = v44 != 0;
            LODWORD(v42) = *(_DWORD *)(v41 + 48);
            v134 = v41;
            HIDWORD(v129) = v46;
            LODWORD(v133) = (_DWORD)v42;
            LODWORD(v135) = *(_DWORD *)(v45 + 64);
            v47 = *(unsigned int *)(v45 + 68);
            if ( (int)v47 <= 1 )
            {
              if ( !(_DWORD)v47 )
              {
                v131 = 0;
                goto LABEL_86;
              }
              if ( (_DWORD)v47 == 1 )
              {
                LODWORD(v125) = 1;
LABEL_86:
                result = (_DWORD *)qce_process_sha_req(*(_QWORD *)(a2 + 16), &v124);
                v68 = (int)result;
                break;
              }
LABEL_129:
              printk(&unk_12387, v47);
              goto LABEL_86;
            }
            if ( (_DWORD)v47 == 2 )
            {
              v69 = 2;
            }
            else
            {
              if ( (_DWORD)v47 != 3 )
                goto LABEL_129;
              v69 = 3;
            }
            LODWORD(v125) = v69;
            v131 = v45 + 80;
            LODWORD(v132) = 64;
            goto LABEL_86;
          case 5:
            v145 = 0;
            v146 = 0;
            v143 = 0;
            v144 = 0;
            v141 = 0;
            v142 = 0;
            v140 = 0;
            v138 = 0;
            v139 = nullptr;
            v136 = 0;
            v137 = 0;
            v134 = 0;
            v135 = 0;
            v132 = 0;
            v133 = 0;
            v130 = 0;
            v131 = 0;
            v128 = 0;
            v129 = 0;
            v126 = 0;
            v127 = nullptr;
            v32 = *v121;
            v124 = nullptr;
            v125 = nullptr;
            *(_QWORD *)(v32 + 88) = a2;
            v33 = *(_QWORD *)(v32 + 32);
            v34 = (_DWORD *)(v32 - 32);
            if ( (*(_BYTE *)(*(_QWORD *)(a2 + 32) + 25LL) & 1) == 0 )
            {
              v70 = *(_QWORD **)(v32 - 24);
              LODWORD(v36) = *(_DWORD *)(v32 - 32);
LABEL_106:
              LODWORD(v124) = 0;
              v125 = qce_sk_cipher_complete;
              v127 = v34;
              v128 = *(_QWORD *)(v32 + 176);
              v82 = *(_DWORD *)(v33 + 216);
              v83 = *(_DWORD *)(v32 + 184);
              v137 = v33 + 152;
              LODWORD(v138) = v82;
              v139 = v70;
              LODWORD(v129) = v83;
              v84 = *(_DWORD *)(*(_QWORD *)(v33 + 24) - 16LL);
              v141 = (unsigned int)v36;
              LODWORD(v140) = v84;
              LODWORD(v143) = *(_DWORD *)(v33 + 64);
              if ( v82 || *(_DWORD *)(*(_QWORD *)(a2 + 32) + 8LL) )
              {
                result = (_DWORD *)qce_ablk_cipher_req(*(_QWORD *)(a2 + 16), &v124);
                v7 = v117;
                v68 = (int)result;
              }
              else
              {
                v7 = v117;
                v68 = -22;
              }
              break;
            }
            v35 = *(_QWORD *)(v32 - 8);
            v113 = *(_QWORD *)(v32 + 32);
            v114 = (_DWORD *)(v32 - 32);
            *(_QWORD *)(v32 + 192) = *(_QWORD *)(v32 - 16);
            *(_QWORD *)(v32 + 200) = v35;
            result = (_DWORD *)_kmalloc_noprof((unsigned int)(*v34 + 64), 2336);
            *(_QWORD *)(v32 + 272) = result;
            if ( result )
            {
              result = *(_DWORD **)(v32 - 16);
              LODWORD(v36) = *(_DWORD *)(v32 - 32);
              v37 = 0;
              if ( result && (int)v36 >= 1 )
              {
                v38 = 1;
                v39 = 1;
                v111 = v3;
                do
                {
                  v40 = v38;
                  LODWORD(v36) = v36 - result[3];
                  result = (_DWORD *)sg_next(result);
                  --v39;
                  if ( (int)v36 < 1 )
                    break;
                  v38 = v40 + 1;
                }
                while ( result );
                v34 = (_DWORD *)(v32 - 32);
                v36 = (unsigned int)*v114;
                if ( v39 == 1 )
                {
                  v3 = v111;
                  v37 = 0;
                }
                else
                {
                  v78 = *(_QWORD *)(v32 + 272);
                  v79 = *(_DWORD **)(v32 - 16);
                  v37 = 0;
                  do
                  {
                    v80 = sg_copy_to_buffer(v79, 1, v78, v36);
                    v78 += v80;
                    v36 -= v80;
                    v37 += v80;
                    result = (_DWORD *)sg_next(v79);
                    --v40;
                    v79 = result;
                  }
                  while ( v40 );
                  v34 = (_DWORD *)(v32 - 32);
                  v3 = v111;
                  v29 = 5;
                  LODWORD(v36) = *v114;
                }
                v31 = v12 + 2;
                v33 = v113;
              }
              else
              {
                v33 = v113;
                v34 = (_DWORD *)(v32 - 32);
              }
              if ( (_DWORD)v36 != v37 )
              {
                result = (_DWORD *)printk(&unk_12B4A, v37);
                v34 = (_DWORD *)(v32 - 32);
                v33 = v113;
                LODWORD(v36) = *v114;
              }
              v81 = *(_QWORD *)(v32 + 272) & 0xFFFLL;
              *(_QWORD *)(v32 + 208) = (((unsigned __int64)(((__int64)(*(_QWORD *)(v32 + 272) << 8) >> 8)
                                                          + 0x8000000000LL) >> 12 << 6)
                                      - 0x140000000LL)
                                     | 2;
              v70 = *(_QWORD **)(v32 - 24);
              *(_DWORD *)(v32 + 216) = v81;
              *(_DWORD *)(v32 + 220) = v36;
              *(_QWORD *)(v32 + 96) = v70;
              *(_QWORD *)(v32 - 16) = v32 + 208;
              *(_QWORD *)(v32 - 8) = v32 + 208;
              goto LABEL_106;
            }
            v7 = v117;
            v68 = -12;
            break;
          default:
            v68 = -22;
            break;
        }
        *(_BYTE *)(a2 + 252) = 0;
        __dmb(0xBu);
        ++*(_QWORD *)(a2 + 80);
        if ( !v68 )
          goto LABEL_151;
        ++*(_QWORD *)(a2 + 88);
        _X9 = (unsigned __int8 *)v12 + 4;
        *v31 = 0;
        v31[1] = 0;
        __asm { PRFM            #0x11, [X9] }
        do
          v106 = __ldxr(_X9);
        while ( __stlxr(0, _X9) );
        __dmb(0xBu);
        if ( v106 )
        {
          _X8 = (unsigned int *)(a2 + 248);
          __asm { PRFM            #0x11, [X8] }
          do
            v110 = __ldxr(_X8);
          while ( __stxr(v110 - 1, _X8) );
        }
        else
        {
          printk(&unk_11D20, v12);
          v7 = v117;
        }
        v107 = 17;
        if ( v29 == 15 )
          v107 = 32;
        if ( v29 == 5 )
          v107 = 26;
        ++qcrypto_stat[v107];
        qcrypto_tfm_complete(a2, v120, v25);
        v6 = raw_spin_lock_irqsave(v3 + 13);
      }
      while ( *(_BYTE *)(a2 + 252) != 1 );
    }
    result = (_DWORD *)raw_spin_unlock_irqrestore(v3 + 13, v6);
  }
LABEL_151:
  _ReadStatusReg(SP_EL0);
  return result;
}
