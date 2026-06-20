__int64 __fastcall qce_process_sha_req(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w19
  _QWORD *v6; // x21
  __int64 v7; // x23
  __int64 v8; // x24
  __int64 v9; // x25
  unsigned int v11; // w0
  unsigned int *v12; // x22
  __int64 *v13; // x8
  _QWORD *v14; // x5
  __int64 v15; // x4
  __int64 v16; // x28
  __int64 v17; // x0
  __int64 v18; // x25
  _QWORD *v19; // x24
  int v20; // w26
  unsigned int *v21; // x3
  _QWORD *v22; // x25
  __int64 v23; // x24
  __int64 v24; // x2
  __int64 v25; // x8
  __int64 v26; // x8
  unsigned int v27; // w9
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x10
  int v31; // w12
  int v32; // w10
  unsigned int v33; // w11
  __int64 v34; // x12
  int v35; // w12
  __int64 v36; // x12
  int v37; // w14
  unsigned int v38; // w9
  int v39; // w10
  int v40; // w9
  unsigned int v41; // w15
  _DWORD *v42; // x10
  int *v43; // x12
  unsigned __int8 *v44; // x14
  unsigned __int64 v45; // x13
  unsigned int v51; // w9
  unsigned int v52; // w16
  int v53; // w15
  int v54; // w14
  unsigned int v55; // w11
  unsigned int v56; // w16
  unsigned int v57; // w17
  unsigned int v58; // w0
  unsigned int v59; // w11
  unsigned int v60; // w12
  unsigned int v61; // w13
  unsigned int v62; // w14
  unsigned int v63; // w15
  char v64; // w17
  unsigned int *v65; // x16
  unsigned int v66; // w0
  unsigned int v67; // w1
  _DWORD *v68; // x1
  __int64 v69; // x11
  __int64 v70; // x11
  unsigned int v71; // w12
  int v72; // w9
  int v73; // w10
  __int64 v74; // x10
  __int64 v75; // x9
  int v76; // w11
  unsigned __int64 v77; // x9
  _DWORD *v78; // x11
  int v79; // w8
  __int64 v80; // x2
  unsigned int v81; // w8
  unsigned __int64 v82; // x12
  _DWORD *v83; // x9
  unsigned __int64 v84; // x10
  __int64 v85; // x13
  int v86; // w8
  __int64 v87; // x8
  unsigned __int64 v88; // x8
  _DWORD *v89; // x9
  int v90; // w10
  __int64 v91; // x2
  __int64 v92; // x8
  unsigned __int64 v93; // x9
  _DWORD *v94; // x8
  __int64 v95; // x8
  int v96; // w24
  unsigned int v98; // w9
  const char *v100; // x1
  __int64 v101; // x13
  unsigned int v103; // w10
  __int64 v104; // [xsp+10h] [xbp-60h]
  __int64 v105; // [xsp+20h] [xbp-50h]
  __int64 v106; // [xsp+28h] [xbp-48h] BYREF
  __int64 v107; // [xsp+30h] [xbp-40h]
  __int64 v108; // [xsp+38h] [xbp-38h]
  __int64 v109; // [xsp+40h] [xbp-30h]
  __int64 v110; // [xsp+48h] [xbp-28h]
  __int64 v111; // [xsp+50h] [xbp-20h]
  __int64 v112; // [xsp+58h] [xbp-18h]
  __int64 v113; // [xsp+60h] [xbp-10h]
  __int64 v114; // [xsp+68h] [xbp-8h]

  v8 = a2;
  v9 = a1;
  _X27 = a1 + 69516;
  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v11 = qce_alloc_req_info(a1, a2, a3, a4);
    if ( (v11 & 0x80000000) != 0 )
    {
      LODWORD(v7) = -16;
      goto LABEL_140;
    }
    *(_DWORD *)(v8 + 92) = v11;
    v12 = (unsigned int *)(v8 + 92);
    if ( v11 >= 0xA )
      goto LABEL_158;
    v13 = (__int64 *)(v8 + 80);
    v14 = (_QWORD *)v8;
  }
  else
  {
    v11 = 8;
    *(_DWORD *)(_X27 + 144) = 8;
    v12 = (unsigned int *)(_X27 + 144);
    v14 = (_QWORD *)(_X27 + 52);
    v13 = (__int64 *)(_X27 + 132);
  }
  v15 = v9 + 2624;
  v16 = *v13;
  _X20 = v9 + 2624 + 7432LL * v11;
  v4 = v11;
  *(_QWORD *)(_X20 + 7416) = 0;
  *(_BYTE *)(_X20 + 7428) = 0;
  *(_DWORD *)(_X20 + 7424) = *((_DWORD *)v14 + 12);
  LODWORD(v7) = *((_DWORD *)v14 + 18);
  if ( (int)v7 < 1 )
  {
    *(_DWORD *)(_X20 + 7352) = 0;
    v21 = (unsigned int *)(_X20 + 7352);
  }
  else
  {
    v17 = v14[3];
    v6 = (_QWORD *)v9;
    v18 = v8;
    v19 = v14;
    v20 = 0;
    v105 = v15;
    do
    {
      ++v20;
      LODWORD(v7) = v7 - *(_DWORD *)(v17 + 12);
      v17 = sg_next(v17);
    }
    while ( (int)v7 > 0 );
    v21 = (unsigned int *)(_X20 + 7352);
    *(_DWORD *)(_X20 + 7352) = v20;
    if ( (unsigned int)(v20 - 1) > 0x7FFFFFFE )
    {
      v15 = v105;
      v14 = v19;
      v8 = v18;
      v9 = (__int64)v6;
    }
    else
    {
      v104 = v18;
      v7 = *v6;
      v22 = v19;
      v23 = v19[3];
      do
      {
        if ( !v23 )
          break;
        dma_map_sg_attrs(v7, v23, 1, 1, 0);
        --v20;
        v23 = sg_next(v23);
      }
      while ( v20 );
      v21 = (unsigned int *)(_X20 + 7352);
      v8 = v104;
      v15 = v105;
      v14 = v22;
      v9 = (__int64)v6;
    }
  }
  if ( *(_BYTE *)(v9 + 68) != 1 )
  {
    LODWORD(v7) = -95;
    goto LABEL_131;
  }
  if ( v4 >= 9 )
    goto LABEL_158;
  v24 = *((unsigned int *)v14 + 2);
  if ( (int)v24 <= 1 )
  {
    if ( !(_DWORD)v24 )
    {
      v25 = 2240;
      goto LABEL_33;
    }
    if ( (_DWORD)v24 == 1 )
    {
      v25 = 2464;
      goto LABEL_33;
    }
    goto LABEL_50;
  }
  if ( (_DWORD)v24 == 2 )
  {
    v25 = 2688;
    goto LABEL_33;
  }
  if ( (_DWORD)v24 == 3 )
  {
    v25 = 2912;
    goto LABEL_33;
  }
  if ( (_DWORD)v24 != 4 )
  {
LABEL_50:
    printk(&unk_15222, "qce_process_sha_req", v24);
    LODWORD(v7) = -22;
    *(_DWORD *)(_X20 + 8) = 5;
    __asm { PRFM            #0x11, [X20] }
    do
      v51 = __ldxr((unsigned int *)_X20);
    while ( __stlxr(0, (unsigned int *)_X20) );
    __dmb(0xBu);
    if ( v51 )
      goto LABEL_140;
LABEL_141:
    printk(&unk_15B49, "qce_free_req_info", v4);
    goto LABEL_140;
  }
  v25 = 3360;
  if ( *((_DWORD *)v14 + 16) == 16 )
    v25 = 3136;
LABEL_33:
  v26 = v15 + 7432LL * v4 + 96 + v25;
  if ( !v26 )
    goto LABEL_50;
  v27 = *v12;
  if ( *v12 >= 0xA )
    goto LABEL_158;
  v112 = 0;
  v113 = 0;
  v28 = v15 + 7432LL * v27;
  v110 = 0;
  v111 = 0;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v29 = *(unsigned int *)(v28 + 7420);
  if ( (unsigned int)v29 >= 6 )
    goto LABEL_158;
  v30 = v9 + 4 * v29;
  if ( *(_BYTE *)(_X27 + 745) )
    v31 = 15360;
  else
    v31 = 0;
  v32 = ((v31 & 0x1FFFF | ((unsigned __int16)(*(_DWORD *)(v9 + 400) >> 3) << 17)) - 0x20000)
      | (32 * *(_DWORD *)(v30 + 316));
  v33 = *((_DWORD *)v14 + 16);
  v34 = *(_QWORD *)(v26 + 8);
  *(_DWORD *)(v9 + 148) = v32 | 0xE;
  *(_DWORD *)(v9 + 152) = v32 | 0x20E;
  *(_DWORD *)(v34 + 4) = v32 | 0xE;
  *(_DWORD *)(*(_QWORD *)(v26 + 16) + 4LL) = *(_DWORD *)(v9 + 152);
  if ( *(_BYTE *)(v9 + 73) == 1 )
    *(_DWORD *)(*(_QWORD *)(v26 + 120) + 4LL) = *(_DWORD *)(v28 + 7424);
  v35 = *((_DWORD *)v14 + 2);
  if ( (unsigned int)(v35 - 2) > 2 )
  {
    v39 = 0;
    v40 = 0;
    if ( (*((_BYTE *)v14 + 69) & 1) != 0 )
      goto LABEL_80;
    goto LABEL_78;
  }
  v36 = *(_QWORD *)(v26 + 208);
  v37 = *(unsigned __int8 *)(v36 + 3);
  *(_DWORD *)v36 = *(_DWORD *)(_X27 + 740) & (*(_DWORD *)(v9 + 88) + 106784) & 0xFFFFFF | ((unsigned __int8)v37 << 24);
  v38 = *((_DWORD *)v14 + 22);
  if ( (v38 & 1) != 0 )
  {
    v39 = 0;
    *(_DWORD *)v36 = *(_DWORD *)(_X27 + 740) & (*(_DWORD *)(v9 + 88) + 110592) & 0xFFFFFF | (v37 << 24);
    goto LABEL_76;
  }
  if ( (v38 & 2) != 0 )
  {
    v39 = (v38 >> 1) & 1;
    goto LABEL_76;
  }
  v41 = *((_DWORD *)v14 + 16);
  v42 = *(_DWORD **)(v26 + 168);
  v43 = (int *)&v106;
  v44 = (unsigned __int8 *)v14[7];
  if ( v41 >= 4 )
  {
    v52 = v41 >> 2;
    v45 = 0;
    do
    {
      if ( v45 > 0x3F )
        goto LABEL_155;
      --v52;
      *(_DWORD *)((char *)&v106 + v45) = bswap32(*(_DWORD *)&v44[v45]);
      v45 += 4LL;
    }
    while ( v52 );
    v44 += v45;
    v43 = (int *)((char *)&v106 + v45);
  }
  else
  {
    v45 = 0;
  }
  v53 = v41 & 3;
  switch ( v53 )
  {
    case 1:
      v54 = *v44 << 24;
      break;
    case 2:
      v54 = (*v44 << 24) | (v44[1] << 16);
      break;
    case 3:
      v54 = (*v44 << 24) | (v44[1] << 16) | (v44[2] << 8);
      break;
    default:
      goto LABEL_66;
  }
  if ( v45 > 0x3C )
LABEL_155:
    __break(1u);
  *v43 = v54;
LABEL_66:
  if ( v33 < 4 )
    goto LABEL_75;
  v55 = v33 >> 2;
  v42[1] = v106;
  if ( v55 == 1
    || (v42[5] = HIDWORD(v106), v55 == 2)
    || (v42[9] = v107, v55 == 3)
    || (v42[13] = HIDWORD(v107), v55 == 4)
    || (v42[17] = v108, v55 == 5)
    || (v42[21] = HIDWORD(v108), v55 == 6)
    || (v42[25] = v109, v55 == 7)
    || (v42[29] = HIDWORD(v109), v55 == 8) )
  {
LABEL_75:
    v39 = 0;
    goto LABEL_76;
  }
  v101 = _X27;
  v42[33] = v110;
  if ( v55 == 9 )
  {
    v39 = 0;
  }
  else
  {
    v6 = (_QWORD *)v9;
    v9 = (__int64)v14;
    _X27 = v8;
    v42[37] = HIDWORD(v110);
    if ( v55 != 10 )
    {
      v42[41] = v111;
      if ( v55 != 11 )
      {
        v42[45] = HIDWORD(v111);
        if ( v55 != 12 )
        {
          v42[49] = v112;
          if ( v55 != 13 )
          {
            v42[53] = HIDWORD(v112);
            if ( v55 != 14 )
            {
              v42[57] = v113;
              if ( v55 != 15 )
              {
                v42[61] = HIDWORD(v113);
                if ( v55 != 16 )
                  goto LABEL_158;
                _X27 = v101;
                v9 = (__int64)v6;
                goto LABEL_75;
              }
            }
          }
        }
      }
    }
    v39 = 0;
    _X27 = v101;
    v9 = (__int64)v6;
  }
LABEL_76:
  v35 = *((_DWORD *)v14 + 2);
  if ( v35 == 4 )
    goto LABEL_107;
  v40 = v38 & 1;
  if ( (*((_BYTE *)v14 + 69) & 1) == 0 )
  {
LABEL_78:
    if ( (v14[9] & 0x3F) != 0 )
    {
      LODWORD(v7) = -5;
      goto LABEL_131;
    }
  }
LABEL_80:
  LODWORD(v7) = -22;
  if ( v35 > 1 )
  {
    if ( v35 == 3 )
    {
LABEL_88:
      if ( (*((_BYTE *)v14 + 68) & 1) != 0 )
      {
        v59 = 1779033703;
        v60 = -1150833019;
        v61 = 1013904242;
        v62 = -1521486534;
        v63 = 1359893119;
        v58 = 1541459225;
        v57 = 528734635;
        v56 = -1694144372;
        goto LABEL_95;
      }
      v64 = 0;
LABEL_92:
      v65 = (unsigned int *)v14[2];
      v59 = bswap32(*v65);
      v60 = bswap32(v65[1]);
      v61 = bswap32(v65[2]);
      v62 = bswap32(v65[3]);
      v63 = bswap32(v65[4]);
      if ( (v64 & 1) != 0 )
      {
        v56 = 0;
        v57 = 0;
        v58 = 0;
      }
      else
      {
        v66 = v65[6];
        v67 = v65[7];
        v56 = bswap32(v65[5]);
        v57 = bswap32(v66);
        v58 = bswap32(v67);
      }
      goto LABEL_95;
    }
    if ( v35 != 2 )
      goto LABEL_131;
  }
  else if ( v35 )
  {
    if ( v35 != 1 )
      goto LABEL_131;
    goto LABEL_88;
  }
  if ( (*((_BYTE *)v14 + 68) & 1) == 0 )
  {
    v64 = 1;
    goto LABEL_92;
  }
  v56 = 0;
  v57 = 0;
  v58 = 0;
  v59 = 1732584193;
  v60 = -271733879;
  v61 = -1732584194;
  v62 = 271733878;
  v63 = -1009589776;
LABEL_95:
  v68 = *(_DWORD **)(v26 + 176);
  v68[1] = v59;
  v68[5] = v60;
  v68[9] = v61;
  v68[13] = v62;
  v68[17] = v63;
  if ( (*((_DWORD *)v14 + 2) | 2) == 3 )
  {
    v68[21] = v56;
    v68[25] = v57;
    v68[29] = v58;
  }
  v69 = *(_QWORD *)(v26 + 192);
  *(_DWORD *)(v69 + 4) = *((_DWORD *)v14 + 8);
  *(_DWORD *)(v69 + 20) = *((_DWORD *)v14 + 9);
  v70 = *(_QWORD *)(v26 + 144);
  v71 = *(_DWORD *)(v70 + 4) & 0xFFF0FFFF;
  if ( *((_BYTE *)v14 + 69) )
    v71 |= 0x10000u;
  if ( *((_BYTE *)v14 + 68) )
    v71 |= 0x20000u;
  if ( v40 )
    v72 = v71 | 0x40000;
  else
    v72 = v71;
  if ( v39 )
    v72 |= 0x80000u;
  *(_DWORD *)(v70 + 4) = v72;
LABEL_107:
  *(_DWORD *)(*(_QWORD *)(v26 + 152) + 4LL) = *((_DWORD *)v14 + 18);
  *(_DWORD *)(*(_QWORD *)(v26 + 24) + 4LL) = 0;
  *(_DWORD *)(*(_QWORD *)(v26 + 160) + 4LL) = 0;
  v73 = *((_DWORD *)v14 + 18);
  if ( !v73 )
    v73 = *(_DWORD *)(v9 + 400);
  *(_DWORD *)(*(_QWORD *)(v26 + 200) + 4LL) = v73;
  v12 = v21;
  *(_QWORD *)(_X20 + 7328) = v16;
  v74 = v15 + 7432LL * v4;
  v6 = v14;
  v75 = *v14;
  *(_QWORD *)(_X20 + 7312) = 0;
  *(_DWORD *)(_X20 + 8) = 0;
  *(_QWORD *)(_X20 + 7304) = v75;
  LODWORD(v75) = *(unsigned __int8 *)(v9 + 68);
  v76 = *((_DWORD *)v14 + 18);
  *(_DWORD *)(v74 + 48) = 0;
  *(_DWORD *)(v74 + 80) = 0;
  *(_DWORD *)(_X20 + 7412) = v76;
  if ( (_DWORD)v75 == 1 )
  {
    v77 = *(_QWORD *)v26 - *(_QWORD *)(v9 + 16) + *(_QWORD *)(v9 + 24);
    v78 = *(_DWORD **)(_X20 + 40);
    v79 = *(unsigned __int16 *)(v26 + 216) | (v77 >> 16) & 0xF0000 | 0xC000000;
    *v78 = v77;
    v78[1] = v79;
    v80 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
    *(_DWORD *)(_X20 + 48) = v80;
    if ( (unsigned int)v80 >= 0x200 )
    {
      printk(&unk_15B74, "_qce_sps_add_cmd", v80);
      LODWORD(v7) = -12;
      v21 = v12;
      v14 = v6;
      goto LABEL_131;
    }
  }
  LODWORD(v7) = qce_sps_add_sg_data((_DWORD *)v9, *(_QWORD *)(v16 + 56), *(_DWORD *)(v16 + 48), _X20 + 32);
  v21 = v12;
  v14 = v6;
  if ( !(_DWORD)v7 )
  {
    if ( *(_DWORD *)(v16 + 48) || (v81 = *(_DWORD *)(v9 + 400)) == 0 )
    {
LABEL_120:
      v86 = *(_DWORD *)(_X20 + 48);
      if ( v86 )
      {
        v87 = *(_QWORD *)(_X20 + 40) + 8LL * (unsigned int)(v86 - 1);
        *(_DWORD *)(v87 + 4) |= 0x50000000u;
      }
      if ( *(_BYTE *)(v9 + 128) == 1 )
      {
        v88 = *(_QWORD *)(_X20 + 7040) - *(_QWORD *)(v9 + 16) + *(_QWORD *)(v9 + 24);
        v89 = (_DWORD *)(*(_QWORD *)(_X20 + 40) + 8LL * *(unsigned int *)(_X20 + 48));
        v90 = *(unsigned __int16 *)(_X20 + 7256) | 0xA000000 | (v88 >> 16) & 0xF0000;
        *v89 = v88;
        v89[1] = v90;
        v91 = (unsigned int)(*(_DWORD *)(_X20 + 48) + 1);
        *(_DWORD *)(_X20 + 48) = v91;
        if ( (unsigned int)v91 >= 0x200 )
        {
          v100 = "_qce_sps_add_cmd";
          goto LABEL_145;
        }
      }
      v92 = *(unsigned int *)(_X20 + 80);
      if ( (_DWORD)v92 != 512 )
      {
        v93 = *(_QWORD *)(v9 + 24) + *(unsigned int *)(_X20 + 7264) - *(_QWORD *)(v9 + 16);
        v94 = (_DWORD *)(*(_QWORD *)(_X20 + 72) + 8 * v92);
        *v94 = v93;
        v94[1] = (v93 >> 16) & 0xF0000 | 0x80;
        v95 = *(unsigned int *)(_X20 + 80);
        *(_DWORD *)(_X20 + 80) = v95 + 1;
        if ( v8 )
        {
          select_mode(v9, _X20);
          LODWORD(v7) = qce_sps_transfer(v9, v4);
          goto LABEL_159;
        }
        if ( (_DWORD)v95 != -1 )
          *(_DWORD *)(*(_QWORD *)(_X20 + 72) + 8 * v95 + 4) |= 0x80000000;
        LODWORD(v7) = qce_sps_transfer(v9, v4);
        goto LABEL_130;
      }
    }
    else
    {
      v82 = *(unsigned int *)(_X20 + 48);
      v83 = (_DWORD *)(*(_QWORD *)(_X20 + 40) + 8 * v82);
      v84 = *(_QWORD *)(v9 + 24) + *(unsigned int *)(_X20 + 7280) - *(_QWORD *)(v9 + 16);
      while ( (_DWORD)v82 != 512 )
      {
        v82 = v84 >> 16;
        if ( v81 >= 0x7FC0 )
          v85 = 32704;
        else
          v85 = v81;
        v81 -= v85;
        *v83 = v84;
        v83[1] = v85 | v82 & 0xF0000;
        v83 += 2;
        v84 += v85;
        LODWORD(v82) = *(_DWORD *)(_X20 + 48) + 1;
        *(_DWORD *)(_X20 + 48) = v82;
        if ( !v81 )
          goto LABEL_120;
      }
    }
    v100 = "_qce_sps_add_data";
    v91 = 512;
LABEL_145:
    printk(&unk_15B74, v100, v91);
    v14 = v6;
    v21 = v12;
    LODWORD(v7) = -12;
    goto LABEL_131;
  }
  while ( 1 )
  {
LABEL_131:
    v96 = *v21;
    if ( *v21 && v96 >= 1 )
    {
      v6 = *(_QWORD **)v9;
      v12 = (unsigned int *)v14[3];
      do
      {
        if ( !v12 )
          break;
        dma_unmap_sg_attrs(v6, v12, 1, 1, 0);
        --v96;
        v12 = (unsigned int *)sg_next(v12);
      }
      while ( v96 );
    }
    if ( v4 < 9 )
      break;
LABEL_158:
    __break(0x5512u);
LABEL_159:
    __asm { PRFM            #0x11, [X27] }
    while ( 1 )
    {
      v103 = __ldxr((unsigned int *)_X27);
      if ( v103 != 1 )
        break;
      if ( !__stlxr(0, (unsigned int *)_X27) )
      {
        __dmb(0xBu);
        break;
      }
    }
LABEL_130:
    v21 = v12;
    v14 = v6;
    if ( !(_DWORD)v7 )
      goto LABEL_140;
  }
  *(_DWORD *)(_X20 + 8) = 5;
  __asm { PRFM            #0x11, [X20] }
  do
    v98 = __ldxr((unsigned int *)_X20);
  while ( __stlxr(0, (unsigned int *)_X20) );
  __dmb(0xBu);
  if ( !v98 )
    goto LABEL_141;
LABEL_140:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
