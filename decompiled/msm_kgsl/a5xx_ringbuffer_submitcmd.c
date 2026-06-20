__int64 __fastcall a5xx_ringbuffer_submitcmd(__int64 a1, __int64 a2, char a3, __int64 a4)
{
  int v7; // w23
  int v10; // w20
  _QWORD *v11; // x9
  __int64 v12; // x25
  unsigned __int64 v13; // x26
  _DWORD *v14; // x0
  int v15; // w9
  __int64 v16; // x10
  __int64 v17; // x9
  int v18; // w12
  __int64 v19; // x9
  unsigned __int64 v20; // x11
  __int64 v21; // x12
  __int64 v22; // x10
  __int64 v23; // x14
  __int64 v24; // x13
  unsigned __int64 v25; // x11
  __int64 v26; // x16
  int v27; // w13
  _DWORD *v28; // x13
  __int64 v29; // x10
  __int64 *v30; // x11
  unsigned __int64 v31; // x12
  unsigned __int64 v33; // x12
  unsigned __int64 v34; // x13
  bool v35; // cf
  unsigned __int64 v36; // x13
  unsigned __int64 v37; // x12
  bool v38; // cf
  unsigned __int64 v39; // x12
  unsigned __int64 v40; // x14
  bool v41; // cf
  unsigned __int64 v42; // x14
  int v43; // w13
  unsigned __int64 v44; // x14
  bool v45; // cf
  unsigned __int64 v46; // x14
  unsigned __int64 v47; // x11
  bool v48; // cf
  unsigned __int64 v49; // x11
  unsigned __int64 v50; // x11
  bool v51; // cf
  unsigned __int64 v52; // x11
  unsigned __int64 v53; // x12
  bool v54; // cf
  unsigned __int64 v55; // x12
  unsigned __int64 v56; // x12
  bool v57; // cf
  unsigned __int64 v58; // x12
  unsigned __int64 v59; // x12
  bool v60; // cf
  unsigned __int64 v61; // x12
  unsigned __int64 v62; // x10
  bool v63; // cf
  unsigned __int64 v64; // x10
  unsigned __int64 v65; // x11
  bool v66; // cf
  unsigned __int64 v67; // x11
  unsigned __int64 v68; // x12
  bool v69; // cf
  unsigned __int64 v70; // x12
  int v71; // w10
  unsigned __int64 v72; // x11
  __int64 v73; // x13
  _DWORD *v74; // x10
  __int64 v75; // x12
  unsigned __int64 v76; // x15
  int v77; // w16
  __int64 v78; // x12
  unsigned __int64 v79; // x11
  int v80; // w9
  __int64 v81; // x12
  __int64 v82; // x9
  __int64 v83; // x14
  __int64 v84; // x13
  unsigned __int64 v85; // x11
  int v86; // w8
  _DWORD *v87; // x8
  __int64 v88; // x9
  unsigned __int64 v89; // x9
  bool v90; // cf
  unsigned __int64 v91; // x9
  unsigned __int64 v92; // x9
  bool v93; // cf
  unsigned __int64 v94; // x9
  unsigned int v95; // w8
  unsigned int v96; // w26
  unsigned int v101; // w9
  __int64 v102; // x8
  __int64 v103; // x26
  __int64 v104; // x8
  __int64 v105; // x8
  int v106; // w9
  __int64 v107; // x12
  _DWORD *v108; // x26
  __int64 v109; // x11
  __int64 v110; // x12
  unsigned int v111; // w8
  __int64 v112; // x11
  __int64 v113; // x11
  __int64 v114; // x12
  int v115; // w13
  const void *v116; // x25
  unsigned int v117; // w23
  unsigned __int64 StatusReg; // x27
  __int64 v119; // x28
  _DWORD *v121; // [xsp+8h] [xbp-98h]
  _DWORD *v122; // [xsp+8h] [xbp-98h]
  _QWORD *v123; // [xsp+10h] [xbp-90h]
  __int64 v124; // [xsp+10h] [xbp-90h]
  __int128 v125; // [xsp+18h] [xbp-88h] BYREF
  __int64 v126; // [xsp+28h] [xbp-78h]
  __int64 v127; // [xsp+30h] [xbp-70h]
  _DWORD v128[6]; // [xsp+38h] [xbp-68h] BYREF
  __int64 v129; // [xsp+50h] [xbp-50h]
  __int64 v130; // [xsp+58h] [xbp-48h]
  __int64 v131; // [xsp+60h] [xbp-40h]
  __int64 v132; // [xsp+68h] [xbp-38h]
  __int64 v133; // [xsp+70h] [xbp-30h]
  __int64 v134; // [xsp+78h] [xbp-28h]
  __int64 v135; // [xsp+80h] [xbp-20h]
  __int64 v136; // [xsp+88h] [xbp-18h]
  __int64 v137; // [xsp+90h] [xbp-10h]
  __int64 v138; // [xsp+98h] [xbp-8h]

  LOBYTE(v7) = a3;
  v138 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _X22 = *(_QWORD *)(a2 + 8);
  if ( (a3 & 0x10) != 0 )
  {
    v10 = 0;
  }
  else
  {
    v10 = -1;
    v11 = (_QWORD *)(a2 + 88);
    do
    {
      v11 = (_QWORD *)*v11;
      ++v10;
    }
    while ( v11 != (_QWORD *)(a2 + 88) );
  }
  v12 = *(_QWORD *)(_X22 + 1536);
  v13 = 20 * v10 + 128;
  v14 = (_DWORD *)_kmalloc_noprof(v13, 3264);
  if ( !v14 )
  {
LABEL_169:
    v117 = -12;
    goto LABEL_170;
  }
  while ( 1 )
  {
    if ( v13 < 4 )
      goto LABEL_168;
    v123 = (_QWORD *)a4;
    *v14 = 1880096769;
    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 4 )
      goto LABEL_168;
    a4 = 1883144195;
    v14[1] = 783149758;
    if ( (v7 & 0x40) != 0 )
    {
      if ( v13 < 8 )
        goto LABEL_168;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 8 )
        goto LABEL_168;
      v16 = *(unsigned int *)(a2 + 144);
      v17 = *(_QWORD *)(*(_QWORD *)(a1 + 20448) + 24LL);
      v14[2] = 1883144195;
      if ( v13 < 0xC || (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0xC )
        goto LABEL_168;
      v14[3] = 1234;
      v18 = **(_DWORD **)(a1 + 14264) <= 0x212u ? 1234 : 1074267346;
      v14[3] = v18;
      if ( v13 < 0x10 )
        goto LABEL_168;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
        goto LABEL_168;
      v19 = v17 + 32 * v16;
      v14[4] = v19;
      if ( v13 < 0x14 || (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x14 )
        goto LABEL_168;
      v14[5] = HIDWORD(v19);
      v15 = 6;
      if ( (v7 & 0x20) == 0 )
      {
LABEL_11:
        if ( v10 )
          goto LABEL_40;
        goto LABEL_66;
      }
    }
    else
    {
      v15 = 2;
      if ( (v7 & 0x20) == 0 )
        goto LABEL_11;
    }
    v20 = *(_QWORD *)(v12 + 1304);
    if ( v20 <= 0xFFFFFFFFFFFFF000LL )
    {
      v21 = *(_QWORD *)(v20 + 24);
      v22 = (unsigned int)(16 * *(_DWORD *)(v12 + 1312));
      v23 = *(_QWORD *)(v20 + 8) + v22;
      v24 = *(_QWORD *)(a2 + 136);
      *(_DWORD *)v23 = 1883144195;
      *(_DWORD *)(v23 + 4) = 1234;
      v25 = 4LL * (unsigned int)v15;
      v26 = v24 + 24;
      if ( **(_DWORD **)(a1 + 14264) <= 0x212u )
        v27 = 1234;
      else
        v27 = 1074267346;
      *(_DWORD *)(v23 + 4) = v27;
      *(_QWORD *)(v23 + 8) = v26;
      if ( v13 < v25 )
        goto LABEL_168;
      if ( v13 - v25 < 4 )
        goto LABEL_168;
      v28 = &v14[v25 / 4];
      v14[v15] = 1891598339;
      if ( v13 < (v25 | 4) )
        goto LABEL_168;
      if ( v13 - (v25 | 4) < 4 )
        goto LABEL_168;
      v29 = v21 + v22;
      v28[1] = v29;
      if ( v13 < v25 + 8 )
        goto LABEL_168;
      if ( v13 - (v25 + 8) < 4 )
        goto LABEL_168;
      v28[2] = HIDWORD(v29);
      if ( v13 < v25 + 12 || v13 - (v25 + 12) < 4 )
        goto LABEL_168;
      v28[3] = 4;
      *(_DWORD *)(v12 + 1312) = (unsigned __int8)(*(_DWORD *)(v12 + 1312) + 1);
      v15 += 4;
      if ( !v10 )
        goto LABEL_66;
LABEL_40:
      v30 = *(__int64 **)(a2 + 88);
      if ( v30 != (__int64 *)(a2 + 88) )
      {
        while ( 1 )
        {
          if ( (v30[7] & 2) != 0 || (v7 & 0x80) == 0 && (v30[6] & 2) != 0 )
          {
            v31 = 4LL * v15;
            _CF = v13 >= v31;
            v33 = v13 - v31;
            if ( v15 < 0 || !_CF || v33 < 4 )
              goto LABEL_168;
            v14[v15++] = 1880096772;
          }
          v34 = 4LL * v15;
          v35 = v13 >= v34;
          v36 = v13 - v34;
          if ( v15 < 0 )
            goto LABEL_168;
          if ( !v35 )
            goto LABEL_168;
          if ( v36 < 4 )
            goto LABEL_168;
          v14[v15] = 1891598339;
          v37 = 4LL * (v15 + 1);
          v38 = v13 >= v37;
          v39 = v13 - v37;
          if ( v15 + 1 < 0 )
            goto LABEL_168;
          if ( !v38 )
            goto LABEL_168;
          if ( v39 < 4 )
            goto LABEL_168;
          v40 = 4LL * (v15 + 2);
          v14[v15 + 1] = v30[4];
          v41 = v13 >= v40;
          v42 = v13 - v40;
          if ( v15 + 2 < 0 )
            goto LABEL_168;
          if ( !v41 )
            goto LABEL_168;
          if ( v42 < 4 )
            goto LABEL_168;
          v43 = v15 + 3;
          v44 = 4LL * (v15 + 3);
          v14[v15 + 2] = *((_DWORD *)v30 + 9);
          v45 = v13 >= v44;
          v46 = v13 - v44;
          if ( v15 + 3 < 0 || !v45 || v46 < 4 )
            goto LABEL_168;
          v15 += 4;
          v14[v43] = (*((_DWORD *)v30 + 10) >> 2) & 0xFFFFF;
          v30 = (__int64 *)*v30;
          if ( v30 == (__int64 *)(a2 + 88) )
            goto LABEL_66;
        }
      }
      goto LABEL_66;
    }
    if ( v10 )
      goto LABEL_40;
LABEL_66:
    v47 = 4LL * v15;
    v48 = v13 >= v47;
    v49 = v13 - v47;
    if ( (v15 & 0x80000000) == 0 && v48 && v49 >= 4 )
    {
      v14[v15] = 1894547461;
      v50 = 4LL * (v15 + 1);
      v51 = v13 >= v50;
      v52 = v13 - v50;
      if ( ((v15 + 1) & 0x80000000) == 0 && v51 && v52 >= 4 )
      {
        v14[v15 + 1] = 0;
        v53 = 4LL * (v15 + 2);
        v54 = v13 >= v53;
        v55 = v13 - v53;
        if ( ((v15 + 2) & 0x80000000) == 0 && v54 && v55 >= 4 )
        {
          v14[v15 + 2] = 0;
          v56 = 4LL * (v15 + 3);
          v57 = v13 >= v56;
          v58 = v13 - v56;
          if ( ((v15 + 3) & 0x80000000) == 0 && v57 && v58 >= 4 )
          {
            v14[v15 + 3] = 0;
            v59 = 4LL * (v15 + 4);
            v60 = v13 >= v59;
            v61 = v13 - v59;
            if ( ((v15 + 4) & 0x80000000) == 0 && v60 && v61 >= 4 )
            {
              v14[v15 + 4] = 0;
              v62 = 4LL * (v15 + 5);
              v63 = v13 >= v62;
              v64 = v13 - v62;
              if ( ((v15 + 5) & 0x80000000) == 0 && v63 && v64 >= 4 )
              {
                v14[v15 + 5] = 0;
                v65 = 4LL * (v15 + 6);
                v66 = v13 >= v65;
                v67 = v13 - v65;
                if ( ((v15 + 6) & 0x80000000) == 0 && v66 && v67 >= 4 )
                {
                  v68 = 4LL * (v15 + 7);
                  v14[v15 + 6] = 1880883201;
                  v69 = v13 >= v68;
                  v70 = v13 - v68;
                  if ( ((v15 + 7) & 0x80000000) == 0 && v69 && v70 >= 4 )
                  {
                    v71 = v15 + 8;
                    v14[v15 + 7] = 1;
                    if ( (v7 & 0x40) != 0 )
                    {
                      v72 = 4LL * v71;
                      if ( v71 < 0 )
                        goto LABEL_168;
                      if ( v13 < v72 )
                        goto LABEL_168;
                      if ( v13 - v72 < 4 )
                        goto LABEL_168;
                      v73 = *(unsigned int *)(a2 + 144);
                      v74 = &v14[v72 / 4];
                      v75 = *(_QWORD *)(*(_QWORD *)(a1 + 20448) + 24LL);
                      v14[v72 / 4] = 1883144195;
                      if ( v13 < v72 + 4 || v13 - (v72 + 4) < 4 )
                        goto LABEL_168;
                      v74[1] = 1234;
                      v76 = v72 + 8;
                      v77 = **(_DWORD **)(a1 + 14264) <= 0x212u ? 1234 : 1074267346;
                      v74[1] = v77;
                      if ( v13 < v76 )
                        goto LABEL_168;
                      if ( v13 - v76 < 4 )
                        goto LABEL_168;
                      v78 = v75 + 32 * v73;
                      v74[2] = v78 + 8;
                      if ( v13 < v72 + 12 || v13 - (v72 + 12) < 4 )
                        goto LABEL_168;
                      v74[3] = (unsigned __int64)(v78 + 8) >> 32;
                      v71 = v15 + 12;
                    }
                    if ( (v7 & 0x20) != 0 )
                    {
                      v79 = *(_QWORD *)(v12 + 1304);
                      if ( v79 <= 0xFFFFFFFFFFFFF000LL )
                      {
                        v81 = *(_QWORD *)(v79 + 24);
                        v82 = (unsigned int)(16 * *(_DWORD *)(v12 + 1312));
                        v83 = *(_QWORD *)(a2 + 136) + 32LL;
                        v84 = *(_QWORD *)(v79 + 8) + v82;
                        *(_DWORD *)v84 = 1883144195;
                        *(_DWORD *)(v84 + 4) = 1234;
                        v85 = 4LL * v71;
                        if ( **(_DWORD **)(a1 + 14264) <= 0x212u )
                          v86 = 1234;
                        else
                          v86 = 1074267346;
                        *(_DWORD *)(v84 + 4) = v86;
                        *(_QWORD *)(v84 + 8) = v83;
                        if ( v71 < 0 )
                          goto LABEL_168;
                        if ( v13 < v85 )
                          goto LABEL_168;
                        if ( v13 - v85 < 4 )
                          goto LABEL_168;
                        v87 = &v14[v85 / 4];
                        v14[v71] = 1891598339;
                        if ( v13 < v85 + 4 )
                          goto LABEL_168;
                        if ( v13 - (v85 + 4) < 4 )
                          goto LABEL_168;
                        v88 = v81 + v82;
                        v87[1] = v88;
                        if ( v13 < v85 + 8 )
                          goto LABEL_168;
                        if ( v13 - (v85 + 8) < 4 )
                          goto LABEL_168;
                        v87[2] = HIDWORD(v88);
                        if ( v13 < v85 + 12 || v13 - (v85 + 12) < 4 )
                          goto LABEL_168;
                        v80 = 4;
                        v87[3] = 4;
                        *(_DWORD *)(v12 + 1312) = (unsigned __int8)(*(_DWORD *)(v12 + 1312) + 1);
                      }
                      else
                      {
                        v80 = 0;
                      }
                      v71 += v80;
                    }
                    v89 = 4LL * v71;
                    v90 = v13 >= v89;
                    v91 = v13 - v89;
                    if ( (v71 & 0x80000000) == 0 && v90 && v91 >= 4 )
                    {
                      v7 = v71;
                      v14[v71] = 1880096769;
                      v92 = 4LL * (v71 + 1);
                      v93 = v13 >= v92;
                      v94 = v13 - v92;
                      if ( ((v71 + 1) & 0x80000000) == 0 && v93 && v94 >= 4 )
                        break;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_168:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v124 = a4;
    v119 = *(_QWORD *)(StatusReg + 80);
    v13 = 20 * v10 + 128;
    *(_QWORD *)(StatusReg + 80) = &a5xx_ringbuffer_submitcmd__alloc_tag;
    v14 = (_DWORD *)_kmalloc_noprof(v13, 3264);
    *(_QWORD *)(StatusReg + 80) = v119;
    a4 = v124;
    if ( !v14 )
      goto LABEL_169;
  }
  v14[v71 + 1] = 717151917;
  if ( *(_QWORD *)(v12 + 176) == _X22 )
  {
LABEL_165:
    v116 = v14;
    adreno_drawobj_set_constraint(a1, a2);
    v117 = a5xx_ringbuffer_addcmds(a1, *(_DWORD **)(_X22 + 1536), _X22, a3, v116, v7 + 2, *(_DWORD *)(a2 + 20), v123);
    v14 = v116;
    goto LABEL_170;
  }
  if ( !_X22 || (*(_QWORD *)(_X22 + 32) & 2) != 0 )
    goto LABEL_167;
  v95 = *(_DWORD *)_X22;
  if ( *(_DWORD *)_X22 )
  {
    do
    {
      __asm { PRFM            #0x11, [X22] }
      do
        v101 = __ldxr((unsigned int *)_X22);
      while ( v101 == v95 && __stxr(v95 + 1, (unsigned int *)_X22) );
      v96 = v95;
      if ( v101 == v95 )
        break;
      v96 = 0;
      v95 = v101;
    }
    while ( v101 );
  }
  else
  {
    v96 = 0;
  }
  if ( (((v96 + 1) | v96) & 0x80000000) != 0 )
  {
    v122 = v14;
    refcount_warn_saturate(_X22, 0);
    v14 = v122;
    if ( !v96 )
      goto LABEL_167;
LABEL_151:
    v102 = *(_QWORD *)(_X22 + 24);
    v127 = 0;
    memset(v128, 0, sizeof(v128));
    v103 = *(_QWORD *)(v102 + 64);
    v104 = *(_QWORD *)(v12 + 176);
    v136 = 0;
    v137 = 0;
    v134 = 0;
    v135 = 0;
    v132 = 0;
    v133 = 0;
    v131 = 0;
    v129 = 0;
    v130 = 0;
    v126 = 0;
    v125 = 0u;
    if ( v104 )
      v104 = *(_QWORD *)(*(_QWORD *)(v104 + 24) + 64LL);
    if ( v104 == v103 )
      goto LABEL_163;
    if ( v103 )
    {
      v105 = *(_QWORD *)(v103 + 96);
      if ( v105 )
      {
        v105 = *(_QWORD *)(v105 + 48);
        if ( v105 )
        {
          v121 = v14;
          if ( *(_DWORD *)(v105 - 4) != 1831526433 )
            __break(0x8228u);
          v105 = ((__int64 (__fastcall *)(__int64))v105)(v103);
          v14 = v121;
        }
      }
    }
    else
    {
      v105 = 0;
    }
    if ( *(_QWORD *)(a1 + 72) == v103 )
    {
LABEL_163:
      v108 = v14;
      v111 = 0;
    }
    else
    {
      v106 = *(_DWORD *)(_X22 + 4);
      v126 = 0x7013800070268000LL;
      v127 = 0x148083101LL;
      v107 = *(_QWORD *)(a1 + 48);
      v128[0] = 1883078661;
      v108 = v14;
      v109 = *(_QWORD *)(v107 + 24);
      v110 = *(int *)(v12 + 28);
      LODWORD(v125) = 1892909059;
      *(_QWORD *)((char *)&v125 + 4) = v105;
      *(_QWORD *)&v128[3] = v105;
      HIDWORD(v125) = v106;
      v128[5] = v106;
      v129 = 0x7013800070268000LL;
      v130 = 1208496385;
      *(_QWORD *)&v128[1] = v109 + 32 * v110 + 16;
      v111 = 18;
    }
    *((_DWORD *)&v125 + v111) = 1880096769;
    *((_DWORD *)&v125 + (v111 | 1)) = 783138543;
    v112 = *(_QWORD *)(a1 + 40);
    *((_DWORD *)&v125 + v111 + 2) = 1883078659;
    v113 = *(_QWORD *)(v112 + 24);
    v114 = v113 + 40LL * *(int *)(v12 + 28) + 32552;
    *((_DWORD *)&v125 + v111 + 3) = v114;
    *((_DWORD *)&v125 + (v111 | 4)) = HIDWORD(v114);
    v115 = *(_DWORD *)(_X22 + 4);
    *((_DWORD *)&v125 + v111 + 6) = 1883078659;
    v113 += 32;
    *((_DWORD *)&v125 + v111 + 7) = v113;
    *((_DWORD *)&v125 + (v111 | 8)) = HIDWORD(v113);
    *((_DWORD *)&v125 + (v111 | 9)) = v115;
    *((_DWORD *)&v125 + v111 + 10) = 1074697473;
    *((_DWORD *)&v125 + (v111 | 5)) = v115;
    *((_DWORD *)&v125 + v111 + 11) = 18;
    a5xx_ringbuffer_addcmds(a1, (_DWORD *)v12, 0, 1, &v125, v111 | 0xC, 0, nullptr);
    adreno_put_drawctxt_on_timestamp(a1, *(_QWORD *)(v12 + 176), v12, *(unsigned int *)(v12 + 36));
    v14 = v108;
    *(_QWORD *)(v12 + 176) = _X22;
    goto LABEL_165;
  }
  if ( v96 )
    goto LABEL_151;
LABEL_167:
  v117 = -2;
LABEL_170:
  kfree(v14);
  _ReadStatusReg(SP_EL0);
  return v117;
}
