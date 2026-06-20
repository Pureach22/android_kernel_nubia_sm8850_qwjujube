__int64 __fastcall si_object_do_invoke(char *s, unsigned __int64 a2, __int64 a3, __int64 a4, _DWORD *a5)
{
  int v10; // w0
  int v11; // w9
  int v12; // w10
  __int64 v14; // x8
  int v15; // w10
  unsigned int v16; // w9
  unsigned __int64 v17; // x8
  __int64 v18; // x11
  __int64 v19; // x11
  unsigned int v20; // w12
  __int64 v21; // x8
  int v22; // w10
  int v23; // w11
  __int64 i; // x11
  int v25; // w11
  size_t v26; // x24
  __int64 result; // x0
  __int64 v28; // x9
  __int64 v29; // x8
  void *v30; // x0
  __int64 v31; // x9
  int v32; // w8
  int v33; // w21
  unsigned __int64 v34; // x26
  __int64 v35; // x10
  int *v37; // x21
  int v38; // w23
  __int64 v39; // x20
  unsigned __int64 v40; // x8
  int v41; // w27
  __int64 v42; // x21
  unsigned int *v43; // x10
  unsigned __int64 v45; // x8
  __int64 v46; // x9
  char *v47; // x24
  size_t v48; // x25
  unsigned __int64 v49; // x26
  unsigned __int64 v50; // x8
  size_t v51; // x26
  unsigned __int64 v52; // x8
  unsigned __int64 v56; // x9
  unsigned __int64 v57; // x8
  unsigned __int64 v59; // x9
  _DWORD *v60; // x23
  int v61; // w11
  int v62; // w10
  unsigned __int64 v63; // x13
  __int64 v64; // x12
  unsigned int *v65; // x15
  _DWORD *v66; // x12
  unsigned int v67; // w14
  __int64 v68; // t1
  int v69; // w24
  int v70; // w12
  unsigned int *v71; // x13
  __int64 v72; // x12
  __int64 v73; // t1
  int v74; // w25
  int v75; // w9
  _DWORD *v76; // x23
  int v77; // w20
  int v78; // w20
  int v79; // w8
  int v80; // w8
  int v81; // w10
  char v82; // w9
  int v83; // w11
  char *v84; // x24
  int v85; // w8
  unsigned int v86; // w9
  int v87; // w25
  unsigned int v88; // w9
  char *v89; // x8
  _DWORD *v90; // x10
  unsigned __int64 v91; // x8
  _DWORD *v92; // x10
  unsigned int v93; // t1
  unsigned int v94; // w8
  int v95; // w9
  int v97; // w9
  int v99; // w26
  char *v100; // x8
  int v101; // w21
  int v102; // w0
  int v103; // w8
  int v104; // w25
  unsigned __int64 v105; // x26
  _DWORD *v106; // x8
  __int64 v107; // x0
  __int64 v108; // x1
  __int64 v109; // x1
  __int64 v110; // x2
  __int64 v111; // x3
  __int64 v112; // x4
  __int64 v113; // x5
  __int64 v114; // x6
  __int64 v115; // x7
  __int64 v116; // x26
  unsigned __int64 v117; // x25
  int v118; // w8
  unsigned int v119; // w8
  unsigned int v120; // w10
  unsigned int v122; // w9
  __int64 (*v123)(void); // x8
  int v124; // w28
  __int64 v125; // x23
  unsigned __int64 v126; // x8
  _QWORD *v127; // x12
  unsigned __int64 v128; // x10
  unsigned int *v129; // x11
  unsigned int v130; // t1
  unsigned __int64 v131; // x9
  char *v132; // x10
  unsigned int *v133; // x11
  unsigned int v134; // t1
  unsigned __int64 v135; // x21
  char *v136; // x25
  unsigned int *v137; // x27
  unsigned int v138; // t1
  unsigned __int64 v139; // x9
  char *v140; // x8
  char *v141; // x8
  __int64 v142; // x0
  __int64 v143; // x2
  __int64 (__fastcall *v144)(__int64, unsigned __int64, __int64, char *); // x8
  int v145; // w21
  int v146; // w9
  __int64 v147; // x8
  unsigned __int64 v148; // x0
  int v149; // w8
  int updated; // w0
  int v151; // w24
  int v152; // w23
  int v153; // w9
  int v154; // w20
  __int64 j; // x8
  int v156; // w8
  unsigned __int64 v157; // x20
  __int64 v158; // x24
  __int64 (__fastcall *v159)(__int64, _DWORD *, _QWORD, __int64, _QWORD); // x8
  __int64 v160; // x0
  __int64 v161; // t1
  __int64 v162; // x8
  unsigned __int64 v163; // [xsp+8h] [xbp-68h]
  __int64 v164; // [xsp+20h] [xbp-50h]
  _DWORD *v165; // [xsp+28h] [xbp-48h]
  unsigned __int64 v166; // [xsp+38h] [xbp-38h]
  unsigned __int64 StatusReg; // [xsp+48h] [xbp-28h]
  int *v168; // [xsp+48h] [xbp-28h]
  unsigned int *v169; // [xsp+50h] [xbp-20h]
  int v170; // [xsp+50h] [xbp-20h]
  __int64 v171; // [xsp+58h] [xbp-18h] BYREF
  int v172; // [xsp+60h] [xbp-10h] BYREF
  unsigned int v173; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v174; // [xsp+68h] [xbp-8h]

  v174 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 < 2 || *(_DWORD *)(a2 + 12) != 1) && (!a2 || a2 != 1 && *(_DWORD *)(a2 + 12) != 8) )
  {
    result = 4294967274LL;
    goto LABEL_29;
  }
  v172 = 0;
  v171 = 0;
  memset(s, 0, 0x6A0u);
  v10 = ida_alloc_range(&si_object_invoke_ctxs_ida, 10, 0xFFFFFFFFLL, 3264);
  v11 = 0;
  *(_DWORD *)s = v10;
  do
    v12 = v11;
  while ( *(_DWORD *)(a4 + 24LL * v11++) );
  v14 = v12;
  v15 = -1;
  do
    v16 = *(_DWORD *)(a4 + 24LL * ++v15);
  while ( v16 > 1 );
  v17 = (8 * v14 + 19) & 0xFFFFFFFFFFFFFFF8LL;
  if ( v16 )
  {
    v18 = v15;
    do
    {
      v19 = *(_QWORD *)(a4 + 24 * v18 + 16);
      do
        v20 = *(_DWORD *)(a4 + 24LL * ++v15);
      while ( v20 >= 2 );
      v21 = v19 + v17;
      v18 = v15;
      v17 = (v21 + 7) & 0xFFFFFFFFFFFFFFF8LL;
    }
    while ( v20 );
  }
  v22 = -1;
  while ( 1 )
  {
    v23 = *(_DWORD *)(a4 + 24LL * ++v22);
    if ( !v23 )
      break;
    if ( v23 == 2 )
    {
      for ( i = v22; ; i = v22 )
      {
        v17 = (v17 + *(_QWORD *)(a4 + 24 * i + 16) + 7) & 0xFFFFFFFFFFFFFFF8LL;
        while ( 1 )
        {
          v25 = *(_DWORD *)(a4 + 24LL * ++v22);
          if ( v25 == 2 )
            break;
          if ( !v25 )
            goto LABEL_24;
        }
      }
    }
  }
LABEL_24:
  v26 = (v17 + 4095) & 0xFFFFFFFFFFFFF000LL;
  if ( (unsigned int)qtee_shmbridge_allocate_shm(v26, s + 1624) )
  {
LABEL_27:
    ida_free(&si_object_invoke_ctxs_ida, *(unsigned int *)s);
    result = 4294967284LL;
    goto LABEL_29;
  }
  if ( (unsigned int)qtee_shmbridge_allocate_shm(0x8000, s + 1672) )
  {
    qtee_shmbridge_free_shm(s + 1624);
    goto LABEL_27;
  }
  v28 = *((_QWORD *)s + 210);
  v29 = *((_QWORD *)s + 203);
  v30 = *((void **)s + 204);
  *((_QWORD *)s + 201) = v26;
  *((_QWORD *)s + 206) = v28;
  v31 = *((_QWORD *)s + 209);
  *((_QWORD *)s + 202) = v29;
  *((_QWORD *)s + 200) = v30;
  *((_QWORD *)s + 207) = 0x8000;
  *((_QWORD *)s + 208) = v31;
  memset(v30, 0, v26);
  memset(*((void **)s + 206), 0, *((_QWORD *)s + 207));
  v32 = 0;
  v33 = 11;
  *((_QWORD *)s + 197) = s + 1576;
  *((_QWORD *)s + 198) = s + 1576;
  v34 = *((_QWORD *)s + 201);
  v169 = *((unsigned int **)s + 200);
  do
  {
    v35 = 24LL * v32++;
    v33 += 8;
  }
  while ( *(_DWORD *)(a4 + v35) );
  v164 = a3;
  v173 = 0;
  _X0 = get_object_id(a2, &v173);
  if ( (_DWORD)_X0 )
    goto LABEL_33;
  v165 = a5;
  v38 = -1;
  do
    v39 = a4 + 24LL * ++v38;
  while ( *(_DWORD *)v39 > 1u );
  LODWORD(v40) = v33 & 0xFFFFFFF8;
  v41 = 0;
  if ( *(_DWORD *)v39 )
  {
    v166 = v34;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v42 = (unsigned int)v40;
      v43 = &v169[2 * v41 + 3];
      *v43 = v40;
      _CF = v34 >= (unsigned int)v40;
      v45 = v34 - (unsigned int)v40;
      v46 = *(_QWORD *)(v39 + 16);
      v43[1] = v46;
      if ( v45 == 0 || !_CF || (unsigned int)v46 >= v45 )
        goto LABEL_66;
      v47 = (char *)v169 + v42;
      if ( *(_BYTE *)(v39 + 4) )
      {
        v48 = *(_QWORD *)(v39 + 16);
        if ( v48 >> 31 )
        {
          __break(0x800u);
LABEL_270:
          LODWORD(v37) = -14;
          goto LABEL_271;
        }
        v49 = *(_QWORD *)(v39 + 8);
        _check_object_size((char *)v169 + v42, *(_QWORD *)(v39 + 16), 0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v50 = v49, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v50 = v49 & ((__int64)(v49 << 8) >> 8);
        if ( 0x8000000000LL - v48 < v50 )
        {
          v51 = v48;
LABEL_48:
          _X0 = (__int64)memset(&v47[v48 - v51], 0, v51);
          if ( v51 )
            goto LABEL_270;
          goto LABEL_52;
        }
        v52 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v56 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v56 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v56);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v52);
        _X0 = _arch_copy_from_user(v47, v49 & 0xFF7FFFFFFFFFFFFFLL, v48);
        v51 = _X0;
        v57 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v59 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v59 - 4096);
        _WriteStatusReg(TTBR1_EL1, v59);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v57);
        if ( _X0 )
          goto LABEL_48;
      }
      else
      {
        _X0 = (__int64)memcpy((char *)v169 + v42, *(const void **)(v39 + 8), *(_QWORD *)(v39 + 16));
      }
LABEL_52:
      v40 = *(_QWORD *)(v39 + 16);
      do
        v39 = a4 + 24LL * ++v38;
      while ( *(_DWORD *)v39 >= 2u );
      v34 = v166;
      ++v41;
      LODWORD(v40) = ((v42 | 7) + v40) & 0xFFFFFFF8;
    }
    while ( *(_DWORD *)v39 );
  }
  v60 = v165;
  v61 = -1;
  while ( 1 )
  {
    v62 = *(_DWORD *)(a4 + 24LL * ++v61);
    if ( !v62 )
      break;
    if ( v62 == 2 )
    {
      v63 = (unsigned int)v40;
      v64 = a4 + 24LL * v61;
      v65 = &v169[2 * v41 + 3];
      *v65 = v40;
      v68 = *(_QWORD *)(v64 + 16);
      v66 = (_DWORD *)(v64 + 16);
      v67 = v68;
      v65[1] = v68;
      if ( v34 > (unsigned int)v40 )
      {
        v69 = v41;
        LODWORD(v37) = -12;
        while ( v34 - v63 > v67 )
        {
          ++v69;
          v40 = ((_DWORD)v40 + *v66 + 7) & 0xFFFFFFF8;
          do
          {
            v70 = *(_DWORD *)(a4 + 24LL * ++v61);
            if ( !v70 )
              goto LABEL_68;
          }
          while ( v70 != 2 );
          v71 = &v169[2 * v69 + 3];
          v72 = a4 + 24LL * v61;
          *v71 = v40;
          v73 = *(_QWORD *)(v72 + 16);
          v66 = (_DWORD *)(v72 + 16);
          v67 = v73;
          v71[1] = v73;
          v63 = v40;
          if ( v34 <= v40 )
            goto LABEL_271;
        }
      }
LABEL_66:
      LODWORD(v37) = -12;
      goto LABEL_271;
    }
  }
  v69 = v41;
LABEL_68:
  v74 = -1;
  do
  {
    v75 = *(_DWORD *)(a4 + 24LL * ++v74);
    if ( !v75 )
    {
      LOBYTE(v77) = v69;
      goto LABEL_84;
    }
  }
  while ( v75 != 3 );
  v76 = v169 + 3;
  _X0 = get_object_id(*(_QWORD *)(a4 + 24LL * v74 + 8), &v169[2 * v69 + 3]);
  v77 = v69;
  if ( (_DWORD)_X0 )
  {
LABEL_72:
    xa_erase(&xa_si_objects, v173);
    v78 = v77 - 1;
    if ( v78 >= v69 )
    {
      LODWORD(v37) = -28;
      do
        xa_erase(&xa_si_objects, (unsigned int)v76[2 * v78--]);
      while ( v78 >= v69 );
      goto LABEL_271;
    }
LABEL_33:
    LODWORD(v37) = -28;
    goto LABEL_271;
  }
  v77 = v69;
LABEL_78:
  ++v77;
  while ( 1 )
  {
    v79 = *(_DWORD *)(a4 + 24LL * ++v74);
    if ( !v79 )
      break;
    if ( v79 == 3 )
    {
      _X0 = get_object_id(*(_QWORD *)(a4 + 24LL * v74 + 8), &v76[2 * v77]);
      if ( (_DWORD)_X0 )
        goto LABEL_72;
      goto LABEL_78;
    }
  }
  v60 = v165;
LABEL_84:
  v80 = -1;
  do
  {
    v81 = *(_DWORD *)(a4 + 24LL * ++v80);
    if ( !v81 )
    {
      v82 = v77;
      goto LABEL_93;
    }
  }
  while ( v81 != 4 );
  v82 = v77;
LABEL_88:
  ++v82;
  while ( 1 )
  {
    v83 = *(_DWORD *)(a4 + 24LL * ++v80);
    if ( !v83 )
      break;
    if ( v83 == 4 )
      goto LABEL_88;
  }
LABEL_93:
  *v169 = v173;
  v169[1] = v164;
  v169[2] = v41 & 0xF
          | (unsigned __int8)(16 * ((v69 - v41) & 0xF))
          | ((((_BYTE)v77 - (_BYTE)v69) & 0xF) << 8) & 0xFFF
          | (((v82 - (_BYTE)v77) & 0xF) << 12);
  v37 = *((int **)s + 206);
  v168 = v37;
  v84 = s + 16;
  v170 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( (s[4] & 1) == 0 )
      goto LABEL_165;
    v85 = *((_DWORD *)s + 398);
    if ( v85 > -13 )
    {
      if ( v85 > -5 )
      {
        if ( v85 != -4 )
        {
          if ( !v85 )
          {
            v86 = -1;
            do
              ++v86;
            while ( *(_DWORD *)&v84[24 * v86] > 1u );
            if ( v86 > 0x40 )
              goto LABEL_272;
            v87 = 0;
            while ( *(_DWORD *)&v84[24 * v86] )
            {
              do
                ++v86;
              while ( *(_DWORD *)&v84[24 * v86] >= 2u );
              ++v87;
              if ( v86 >= 0x41 )
                goto LABEL_272;
            }
            v88 = -1;
            do
              ++v88;
            while ( (*(_DWORD *)&v84[24 * v88] | 2) != 2 );
            if ( v88 > 0x40 )
              goto LABEL_272;
            v60 = (_DWORD *)(*((_QWORD *)s + 206) + 16LL);
            while ( 1 )
            {
              v89 = &v84[24 * v88];
              if ( !*(_DWORD *)v89 )
                break;
              v90 = &v60[2 * v87];
              v91 = *((_QWORD *)v89 + 2);
              v93 = v90[1];
              v92 = v90 + 1;
              if ( v91 > v93 )
              {
                v85 = 2;
                v170 = -22;
                goto LABEL_164;
              }
              ++v87;
              *v92 = v91;
              do
                ++v88;
              while ( (*(_DWORD *)&v84[24 * v88] | 2) != 2 );
              if ( v88 >= 0x41 )
                goto LABEL_272;
            }
            v94 = -1;
            do
              v95 = *(_DWORD *)&v84[24 * ++v94];
            while ( v95 != 3 && v95 != 0 );
            if ( v94 > 0x40 )
              goto LABEL_272;
            while ( *(_DWORD *)&v84[24 * v94] )
            {
              ++v87;
              do
                v97 = *(_DWORD *)&v84[24 * ++v94];
              while ( v97 != 3 && v97 != 0 );
              if ( v94 >= 0x41 )
                goto LABEL_272;
            }
            LODWORD(v37) = -1;
            do
              LODWORD(v37) = (_DWORD)v37 + 1;
            while ( (*(_DWORD *)&v84[24 * (int)v37] | 4) != 4 );
            if ( (unsigned int)v37 > 0x40 )
            {
LABEL_272:
              __break(0x5512u);
              v157 = _ReadStatusReg(SP_EL0);
              if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                               + (((unsigned __int64)*(unsigned int *)(v157 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v157 + 40))
                  & 1) != 0 )
              {
                ++*(_DWORD *)(v157 + 16);
                v158 = qword_B8F0;
                if ( qword_B8F0 )
                {
                  do
                  {
                    v159 = *(__int64 (__fastcall **)(__int64, _DWORD *, _QWORD, __int64, _QWORD))v158;
                    v160 = *(_QWORD *)(v158 + 8);
                    if ( *(_DWORD *)(*(_QWORD *)v158 - 4LL) != -1522261380 )
                      __break(0x8228u);
                    _X0 = v159(v160, v60, (unsigned int)a4, v164, (unsigned int)v37);
                    v161 = *(_QWORD *)(v158 + 24);
                    v158 += 24;
                  }
                  while ( v161 );
                }
                v162 = *(_QWORD *)(v157 + 16) - 1LL;
                *(_DWORD *)(v157 + 16) = v162;
                if ( !v162 || !*(_QWORD *)(v157 + 16) )
                  preempt_schedule_notrace(_X0);
              }
              goto LABEL_271;
            }
            v99 = v87;
            while ( 1 )
            {
              v100 = &v84[24 * (unsigned int)v37];
              if ( !*(_DWORD *)v100 )
              {
                v170 = 0;
                v85 = 0;
                goto LABEL_164;
              }
              _X0 = get_object_id(*((_QWORD *)v100 + 1), &v60[2 * v99]);
              if ( (_DWORD)_X0 )
                break;
              ++v99;
              do
                LODWORD(v37) = (_DWORD)v37 + 1;
              while ( (*(_DWORD *)&v84[24 * (int)v37] | 4) != 4 );
              if ( (unsigned int)v37 >= 0x41 )
                goto LABEL_272;
            }
            v101 = v99 - 1;
            if ( v99 - 1 >= v87 )
            {
              do
              {
                xa_erase(&xa_si_objects, (unsigned int)v60[2 * v101--]);
                v85 = -99;
                v170 = -28;
              }
              while ( v101 >= v87 );
            }
            else
            {
              v85 = -99;
              v170 = -28;
            }
            goto LABEL_164;
          }
LABEL_121:
          v170 = *((_DWORD *)s + 398);
          if ( v85 < 0 )
            v85 = 1;
          goto LABEL_164;
        }
        v170 = -4;
        v85 = -91;
      }
      else if ( v85 == -12 )
      {
        v170 = -12;
        v85 = -97;
      }
      else
      {
        if ( v85 != -9 )
          goto LABEL_121;
        v170 = -9;
        v85 = -96;
      }
    }
    else
    {
      if ( v85 > -20 )
      {
        if ( v85 == -19 )
        {
          v170 = -19;
          v85 = -90;
          goto LABEL_164;
        }
        if ( v85 != -16 )
          goto LABEL_121;
LABEL_107:
        v170 = *((_DWORD *)s + 398);
        v85 = -99;
        goto LABEL_164;
      }
      if ( v85 == -28 )
        goto LABEL_107;
      if ( v85 != -22 )
        goto LABEL_121;
      v170 = -22;
      v85 = 2;
    }
LABEL_164:
    v37 = v168;
    v60 = v165;
    *v168 = v85;
LABEL_165:
    _append__async_reqs(s);
    v102 = si_object_invoke_ctx_invoke((__int64)s, (__int64)v60, (__int64)&v171, (__int64)&v172);
    v103 = *((_DWORD *)s + 1);
    v104 = v102;
    if ( (v103 & 1) != 0 )
    {
      v105 = *((_QWORD *)s + 1);
      if ( v105 )
      {
        if ( (v103 & 2) != 0 )
        {
          v106 = *(_DWORD **)(*(_QWORD *)(v105 + 24) + 24LL);
          if ( v106 )
          {
            v107 = *(unsigned int *)s;
            v108 = *((_QWORD *)s + 1);
            if ( *(v106 - 1) != -172122193 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _QWORD))v106)(v107, v108, v104 | (unsigned int)v170);
          }
        }
        put_si_object(v105);
        v103 = *((_DWORD *)s + 1);
      }
      v103 &= 0xFFFFFFFC;
      *((_QWORD *)s + 1) = 0;
      *((_DWORD *)s + 1) = v103;
    }
    if ( v104 )
      break;
    *((_DWORD *)s + 1) = v103 | 4;
    _release__async_queued_reqs(s);
    if ( v171 != 3 )
    {
      if ( (unsigned __int64)(v171 - 1) > 1 )
      {
        updated = 0;
      }
      else
      {
        updated = qseecom_process_listener_from_smcinvoke(v60, &v171, &v172);
        if ( updated )
        {
          v151 = updated;
          printk(&unk_B358, "si_object_do_invoke");
          updated = v151;
        }
      }
      if ( !*v60 )
      {
        updated = update_args(a4, s);
        if ( updated )
        {
          v152 = -1;
          while ( 1 )
          {
            v153 = *(_DWORD *)(a4 + 24LL * ++v152);
            if ( !v153 )
              break;
            if ( v153 == 4 )
            {
              v154 = updated;
              for ( j = v152; ; j = v152 )
              {
                put_si_object(*(_QWORD *)(a4 + 24 * j + 8));
                updated = v154;
                while ( 1 )
                {
                  v156 = *(_DWORD *)(a4 + 24LL * ++v152);
                  if ( v156 == 4 )
                    break;
                  if ( !v156 )
                    goto LABEL_258;
                }
              }
            }
          }
        }
      }
LABEL_258:
      LODWORD(v37) = updated;
      _fetch__async_reqs(s);
      goto LABEL_271;
    }
    *((_DWORD *)s + 1) |= 1u;
    _X0 = _fetch__async_reqs(s);
    v116 = (unsigned int)v37[1];
    if ( (v116 & 0x80000000) != 0 )
    {
      _X0 = (__int64)qtee_get_si_object((unsigned int)v116, v109, v110, v111, v112, v113, v114, v115);
      if ( _X0 )
      {
        *((_QWORD *)s + 1) = _X0;
        v117 = _X0;
        _X0 = (unsigned int)v37[2];
        v118 = (unsigned __int16)v37[2];
        if ( v118 == 65534 )
        {
          if ( v117 >= 2 )
          {
            _X0 = v117 + 8;
            v119 = *(_DWORD *)(v117 + 8);
            if ( v119 )
            {
              do
              {
                __asm { PRFM            #0x11, [X0] }
                do
                  v122 = __ldxr((unsigned int *)_X0);
                while ( v122 == v119 && __stxr(v119 + 1, (unsigned int *)_X0) );
                v120 = v119;
                if ( v122 == v119 )
                  break;
                v120 = 0;
                v119 = v122;
              }
              while ( v122 );
            }
            else
            {
              v120 = 0;
            }
            if ( (((v120 + 1) | v120) & 0x80000000) != 0 )
              _X0 = refcount_warn_saturate(_X0, 0);
          }
          goto LABEL_236;
        }
        if ( v118 == 0xFFFF )
        {
          xa_erase(&xa_si_objects, v116);
          _X0 = put_si_object(v117);
LABEL_236:
          v124 = 0;
          goto LABEL_239;
        }
        v123 = *(__int64 (**)(void))(*(_QWORD *)(v117 + 24) + 8LL);
        if ( v123 )
        {
          if ( *((_DWORD *)v123 - 1) != -757638360 )
            __break(0x8228u);
          _X0 = v123();
          if ( (_DWORD)_X0 )
          {
            v124 = -22;
            goto LABEL_239;
          }
        }
        v125 = *((_QWORD *)s + 206);
        v126 = *(unsigned int *)(v125 + 12);
        if ( (v126 & 0xF) != 0 )
        {
          v127 = s + 32;
          v128 = 0;
          v129 = (unsigned int *)(v125 + 20);
          do
          {
            ++v128;
            *(v127 - 1) = v125 + *(v129 - 1);
            v130 = *v129;
            v129 += 2;
            *((_DWORD *)v127 - 4) = 1;
            *v127 = v130;
            v127 += 3;
            v126 = *(unsigned int *)(v125 + 12);
            v131 = v126 & 0xF;
          }
          while ( v128 < v131 );
        }
        else
        {
          v131 = 0;
        }
        if ( (unsigned __int8)v126 >> 4 )
        {
          v132 = &s[24 * (unsigned int)v131 + 32];
          v133 = (unsigned int *)(v125 + 8 * v131 + 20);
          do
          {
            ++v131;
            *((_QWORD *)v132 - 1) = v125 + *(v133 - 1);
            v134 = *v133;
            v133 += 2;
            *((_DWORD *)v132 - 4) = 2;
            *(_QWORD *)v132 = v134;
            v132 += 24;
            v126 = *(unsigned int *)(v125 + 12);
            v135 = ((unsigned __int8)v126 >> 4) + (v126 & 0xF);
          }
          while ( v131 < v135 );
        }
        else
        {
          v135 = ((unsigned __int8)v126 >> 4) + v131;
        }
        if ( ((v126 >> 8) & 0xF) != 0 )
        {
          v163 = v117;
          v136 = &s[24 * (unsigned int)v135 + 24];
          v124 = 0;
          v137 = (unsigned int *)(v125 + 8 * v135 + 16);
          do
          {
            v138 = *v137;
            v137 += 2;
            _X0 = init_si_object(v136, v138);
            *((_DWORD *)v136 - 2) = 3;
            ++v135;
            v126 = *(unsigned int *)(v125 + 12);
            if ( (_DWORD)_X0 )
              v124 = _X0;
            v136 += 24;
            v139 = ((unsigned __int8)v126 >> 4) + (v126 & 0xF) + ((v126 >> 8) & 0xF);
          }
          while ( v135 < v139 );
          v117 = v163;
        }
        else
        {
          v124 = 0;
          v139 = v135;
        }
        v37 = v168;
        if ( (v126 & 0xF000) != 0 )
        {
          v140 = &v84[24 * (unsigned int)v139];
          do
          {
            *(_DWORD *)v140 = 4;
            v140 += 24;
            ++v139;
          }
          while ( v139 < ((unsigned __int8)*(_DWORD *)(v125 + 12) >> 4)
                       + (*(_DWORD *)(v125 + 12) & 0xF)
                       + ((*(_DWORD *)(v125 + 12) >> 8) & 0xF)
                       + (unsigned int)((unsigned __int16)*(_DWORD *)(v125 + 12) >> 12) );
        }
        v60 = v165;
        *(_DWORD *)&v84[24 * (unsigned int)v139] = 0;
        if ( v124 )
        {
          LODWORD(v37) = -1;
          do
            LODWORD(v37) = (_DWORD)v37 + 1;
          while ( *(_DWORD *)&v84[24 * (int)v37] > 1u );
          if ( (unsigned int)v37 > 0x40 )
            goto LABEL_272;
          while ( 1 )
          {
            v141 = &v84[24 * (unsigned int)v37];
            if ( !*(_DWORD *)v141 )
              break;
            _X0 = put_si_object(*((_QWORD *)v141 + 1));
            do
              LODWORD(v37) = (_DWORD)v37 + 1;
            while ( *(_DWORD *)&v84[24 * (int)v37] >= 2u );
            if ( (unsigned int)v37 >= 0x41 )
              goto LABEL_272;
          }
          v37 = v168;
        }
        else
        {
          v142 = *(unsigned int *)s;
          v143 = (unsigned int)v168[2];
          v144 = *(__int64 (__fastcall **)(__int64, unsigned __int64, __int64, char *))(*(_QWORD *)(v117 + 24) + 16LL);
          if ( *((_DWORD *)v144 - 1) != -784462101 )
            __break(0x8228u);
          _X0 = v144(v142, v117, v143, s + 16);
          v124 = _X0;
          if ( !(_DWORD)_X0 )
          {
            *((_DWORD *)s + 1) |= 2u;
            goto LABEL_239;
          }
        }
        if ( (unsigned int)(v124 + 516) <= 4 && ((0x1Du >> (v124 + 4)) & 1) != 0 )
          v124 = -4;
LABEL_239:
        *((_DWORD *)s + 398) = v124;
      }
      else
      {
        *((_DWORD *)s + 398) = -22;
      }
    }
    else
    {
      *((_DWORD *)s + 398) = -22;
    }
  }
  _revive__async_queued_reqs(s);
  if ( (s[4] & 4) != 0 )
  {
    LODWORD(v37) = -19;
  }
  else
  {
    v145 = -1;
    while ( 1 )
    {
      v146 = *(_DWORD *)(a4 + 24LL * ++v145);
      if ( !v146 )
        break;
      if ( v146 == 3 )
      {
        v147 = v145;
LABEL_245:
        v148 = *(_QWORD *)(a4 + 24 * v147 + 8);
        if ( v148 >= 2 && *(_DWORD *)(v148 + 12) == 2 )
          put_si_object(v148);
        while ( 1 )
        {
          v149 = *(_DWORD *)(a4 + 24LL * ++v145);
          if ( !v149 )
            goto LABEL_255;
          if ( v149 == 3 )
          {
            v147 = v145;
            goto LABEL_245;
          }
        }
      }
    }
LABEL_255:
    LODWORD(v37) = -11;
  }
LABEL_271:
  ida_free(&si_object_invoke_ctxs_ida, *(unsigned int *)s);
  qtee_shmbridge_free_shm(s + 1624);
  qtee_shmbridge_free_shm(s + 1672);
  result = (unsigned int)v37;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
