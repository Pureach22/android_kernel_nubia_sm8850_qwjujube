__int64 __fastcall rtc6226_rds_handler(__int64 a1)
{
  char *v1; // x23
  unsigned __int64 v2; // x21
  __int64 v3; // x20
  unsigned int v5; // w9
  int v6; // w10
  __int64 result; // x0
  int v8; // w8
  unsigned int v9; // w8
  unsigned int v10; // w20
  int v11; // w9
  int v12; // w9
  int v13; // w9
  int v14; // w24
  char v15; // w8
  int v16; // w9
  __int64 v17; // x22
  __int64 v18; // x3
  __int64 v19; // x1
  unsigned __int64 v20; // x0
  __int16 v21; // x10^2
  __int64 v22; // x2
  int v23; // w8
  __int16 v24; // w25
  _QWORD *v25; // x28
  unsigned __int64 v26; // x22
  __int64 v27; // x26
  char v28; // w8
  int v29; // w9
  __int16 v30; // w10
  char v31; // w24
  int v32; // w9
  unsigned __int64 v33; // x8
  __int64 v34; // x10
  unsigned int v35; // w13
  unsigned int v36; // w11
  __int64 v37; // x12
  bool v38; // w10
  __int64 v39; // x13
  int v40; // w14
  unsigned __int64 v41; // x10
  int v42; // w12
  __int64 v43; // x13
  __int64 v44; // x15
  __int16 v45; // w11
  size_t v46; // x25
  int v47; // w13
  __int64 v48; // x11
  __int64 v49; // x12
  __int64 v50; // x11
  __int64 v51; // x12
  __int64 v52; // x11
  __int64 v53; // x13
  __int64 v54; // x11
  __int64 v55; // x12
  __int16 v56; // w9
  __int64 v57; // x11
  __int64 v58; // x13
  size_t v59; // x2
  __int64 v60; // x11
  __int64 v61; // x12
  __int64 v62; // x25
  __int64 v63; // x25
  int v64; // w0
  __int64 v65; // x8
  int v66; // w26
  __int64 v67; // x23
  char v68; // w22
  __int16 v69; // w9
  unsigned int v70; // w8
  int v71; // w8
  _BYTE *v72; // x0
  char v73; // w8
  _BYTE *v74; // x20
  unsigned int v75; // w8
  int v76; // w9
  int v77; // w8
  __int64 v78; // x10
  int v79; // w12
  int v80; // w11
  _BYTE *v81; // x13
  char v82; // w10
  char v83; // w13
  size_t v84; // x2
  char v85; // w8
  char v86; // w9
  __int64 v87; // x22
  __int64 v88; // x22
  int v89; // w23
  char v90; // w8
  void *v91; // x0
  const char *v92; // x1
  unsigned __int64 v93; // x8
  __int64 v94; // x23
  __int64 v95; // x22
  int v96; // w9
  __int64 v97; // x22
  int v98; // w12
  _BYTE *v99; // x13
  unsigned __int64 StatusReg; // x24
  __int64 v101; // x25
  char *v102; // [xsp+0h] [xbp-90h]
  int v103; // [xsp+8h] [xbp-88h] BYREF
  int v104; // [xsp+Ch] [xbp-84h] BYREF
  char v105[4]; // [xsp+10h] [xbp-80h] BYREF
  int v106; // [xsp+14h] [xbp-7Ch] BYREF
  _QWORD v107[15]; // [xsp+18h] [xbp-78h] BYREF

  v2 = a1 - 2056;
  v107[14] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v106 = 0;
  if ( a1 == 2056 )
  {
    v91 = &unk_D9D4;
    v92 = "rtc6226_rds_handler";
LABEL_138:
    result = printk(v91, v92);
    goto LABEL_139;
  }
  v3 = a1 - 184;
  mutex_lock(a1 - 184);
  if ( (rtc6226_get_all_registers(v2) & 0x80000000) != 0 )
  {
    printk(&unk_DA1B, "rtc6226_get_rds");
  }
  else
  {
    v5 = *(unsigned __int16 *)(a1 - 272);
    v6 = *(_DWORD *)(a1 - 266);
    *(_DWORD *)(a1 + 498) = *(_DWORD *)(a1 - 270);
    *(_DWORD *)(a1 + 502) = v6;
    *(_BYTE *)(a1 + 796) = v5 >> 14;
    *(_BYTE *)(a1 + 797) = (v5 >> 12) & 3;
    *(_BYTE *)(a1 + 798) = (v5 >> 10) & 3;
    *(_BYTE *)(a1 + 799) = BYTE1(v5) & 3;
  }
  result = mutex_unlock(v3);
  if ( *(unsigned __int8 *)(a1 + 796) <= 1u )
  {
    v8 = *(unsigned __int16 *)(a1 + 498);
    if ( *(unsigned __int16 *)(a1 + 494) != v8 )
      *(_WORD *)(a1 + 494) = v8;
  }
  if ( *(_BYTE *)(a1 + 797) )
    goto LABEL_139;
  v9 = *(unsigned __int16 *)(a1 + 500);
  v10 = v9 >> 11;
  if ( ((v9 >> 11) & 1) != 0 )
  {
    v11 = *(unsigned __int16 *)(a1 + 502);
    if ( *(unsigned __int16 *)(a1 + 494) != v11 )
      *(_WORD *)(a1 + 494) = v11;
  }
  v12 = (v9 >> 5) & 0x1F;
  if ( *(unsigned __int8 *)(a1 + 496) != v12 )
    *(_BYTE *)(a1 + 496) = v12;
  if ( v9 >> 11 > 3 )
  {
    switch ( v10 )
    {
      case 4u:
        v18 = 4 * (v9 & 0xF);
        v19 = (v9 >> 4) & 1;
        v20 = v2;
        v21 = bswap32(*(unsigned __int16 *)(a1 + 504)) >> 16;
        v22 = 4;
        LOWORD(v106) = bswap32(*(unsigned __int16 *)(a1 + 502)) >> 16;
        HIWORD(v106) = v21;
        break;
      case 5u:
        v69 = *(_WORD *)(a1 + 504);
        v18 = 2 * (v9 & 0xF);
        *(_BYTE *)(a1 + 602) = 13;
        v19 = (v9 >> 4) & 1;
        *(_BYTE *)(a1 + 666) = 13;
        v20 = v2;
        v22 = 2;
        HIBYTE(v106) = 0;
        LOBYTE(v106) = HIBYTE(v69);
        *(_WORD *)((char *)&v106 + 1) = (unsigned __int8)v69;
        *(_BYTE *)(a1 + 730) = 2;
        break;
      case 6u:
        v13 = *(unsigned __int16 *)(a1 + 504);
        v14 = v9 & 0x1F;
        if ( v13 == 19415 )
        {
          v96 = *(unsigned __int8 *)(a1 + 800);
          *(_BYTE *)(a1 + 1061) = (*(_WORD *)(a1 + 502) & 0x2000) != 0;
          if ( v14 != v96 )
          {
            LOBYTE(v107[0]) = 19;
            v97 = raw_spin_lock_irqsave(a1 - 80);
            LODWORD(v1) = _kfifo_in(a1 + 1104, v107, 1);
            result = raw_spin_unlock_irqrestore(a1 - 80, v97);
            if ( (_DWORD)v1 )
              result = _wake_up(a1 + 464, 1, 1, 0);
            *(_BYTE *)(a1 + 800) = v14;
          }
        }
        else if ( v13 == 25938 )
        {
          v15 = *(_BYTE *)(a1 + 502);
          v16 = *(unsigned __int8 *)(a1 + 801);
          *(_BYTE *)(a1 + 1060) = v15 & 1;
          *(_BYTE *)(a1 + 1062) = (v15 & 2) != 0;
          if ( v14 != v16 )
          {
            LOBYTE(v107[0]) = 19;
            v17 = raw_spin_lock_irqsave(a1 - 80);
            LODWORD(v1) = _kfifo_in(a1 + 1104, v107, 1);
            result = raw_spin_unlock_irqrestore(a1 - 80, v17);
            if ( (_DWORD)v1 )
              result = _wake_up(a1 + 464, 1, 1, 0);
            *(_BYTE *)(a1 + 801) = v14;
          }
        }
        goto LABEL_71;
      default:
LABEL_25:
        result = printk(&unk_CD65, "rtc6226_rds_handler");
        goto LABEL_71;
    }
    result = rt_handler(v20, v19, v22, v18, &v106);
    goto LABEL_71;
  }
  if ( !v10 )
  {
    if ( *(unsigned __int8 *)(a1 + 798) > 2u )
      goto LABEL_67;
    v23 = *(_DWORD *)(a1 - 64);
    v24 = *(unsigned __int8 *)(a1 + 503);
    memset(v107, 0, 107);
    v103 = v23;
    v104 = 0;
    rtc6226_get_freq(v2, &v104);
    v25 = (_QWORD *)(a1 + 156);
    v26 = a1 + 44;
    v27 = a1 - 80;
    v1 = (char *)v107 + 7;
    v28 = 1;
    result = 87500;
    while ( 1 )
    {
      v31 = v28;
      if ( (unsigned __int16)(v24 - 225) <= 0x18u )
      {
        v29 = v104;
        v30 = *(_WORD *)(a1 + 494);
        *(_BYTE *)(a1 + 144) = 0;
        *(_BYTE *)(a1 + 145) = v24 + 32;
        *(_DWORD *)(a1 + 152) = v29;
        *(_WORD *)(a1 + 148) = v30;
      }
      else
      {
        if ( (unsigned __int16)(v24 - 1) > 0xCBu )
          goto LABEL_30;
        v32 = *(_DWORD *)(a1 + 152);
        if ( !v32 )
          goto LABEL_30;
        v33 = *(unsigned __int8 *)(a1 + 146);
        if ( (unsigned int)v33 > 0x18 )
          goto LABEL_30;
        v34 = *(unsigned int *)(a1 - 308);
        if ( (unsigned int)v34 > 2
          || (v35 = 10 * *(unsigned __int16 *)(a1 - 28), v36 = (unsigned __int16)(100 * v24) + 87500, v36 < v35)
          || 10 * (unsigned int)*(unsigned __int16 *)(a1 - 26) < v36
          || (v36 - v35) % dword_C8C8[v34] )
        {
          ++*(_BYTE *)(a1 + 144);
        }
        else
        {
          if ( *(_BYTE *)(a1 + 146) )
          {
            v37 = 0;
            v38 = 0;
            v39 = *(unsigned __int8 *)(a1 + 146);
            do
            {
              if ( v37 == 25 )
                goto LABEL_134;
              if ( *((_DWORD *)v25 + v37) == v36 )
                break;
              v38 = ++v37 >= v33;
            }
            while ( v33 != v37 );
            v40 = *(unsigned __int8 *)(a1 + 144);
            if ( !v38 )
            {
              *(_BYTE *)(a1 + 144) = v40 + 1;
              goto LABEL_30;
            }
          }
          else
          {
            v40 = *(unsigned __int8 *)(a1 + 144);
            v39 = 0;
          }
          v41 = v33 + 1;
          v42 = *(unsigned __int8 *)(a1 + 145);
          *((_DWORD *)v25 + v39) = v36;
          *(_BYTE *)(a1 + 146) = v33 + 1;
          if ( v40 + (_DWORD)v33 + 1 == v42 )
          {
            if ( *(_DWORD *)(a1 + 40) != v32 )
              goto LABEL_61;
            if ( *(_BYTE *)(a1 + 34) )
            {
              v43 = 0;
              while ( 1 )
              {
                if ( v43 == 25 )
                  goto LABEL_134;
                v44 = 0;
                while ( 1 )
                {
                  if ( v44 == 25 )
                    goto LABEL_134;
                  if ( *(_DWORD *)(v26 + 4 * v43) == *((_DWORD *)v25 + v44) )
                    break;
                  if ( v41 == ++v44 )
                    goto LABEL_61;
                }
                if ( (_DWORD)v41 == (unsigned __int8)v44 )
                  break;
                if ( ++v43 == *(unsigned __int8 *)(a1 + 34) )
                  goto LABEL_30;
              }
LABEL_61:
              v45 = *(_WORD *)(a1 + 148);
              *(_BYTE *)(a1 + 33) = v42;
              v46 = (unsigned int)(4 * v41);
              *(_QWORD *)(a1 + 124) = 0;
              *(_QWORD *)(a1 + 132) = 0;
              v47 = *(_DWORD *)(a1 + 252);
              *(_WORD *)(a1 + 36) = v45;
              v48 = *(_QWORD *)(a1 + 236);
              v49 = *(_QWORD *)(a1 + 244);
              *(_QWORD *)(a1 + 92) = 0;
              *(_QWORD *)(a1 + 100) = 0;
              *(_DWORD *)(a1 + 140) = 0;
              *(_QWORD *)(a1 + 124) = v48;
              *(_QWORD *)(a1 + 132) = v49;
              v50 = *(_QWORD *)(a1 + 204);
              v51 = *(_QWORD *)(a1 + 212);
              *(_DWORD *)(a1 + 140) = v47;
              *(_QWORD *)(a1 + 108) = 0;
              *(_QWORD *)(a1 + 116) = 0;
              *(_QWORD *)(a1 + 92) = v50;
              *(_QWORD *)(a1 + 100) = v51;
              v52 = *(_QWORD *)(a1 + 220);
              v53 = *(_QWORD *)(a1 + 228);
              *(_QWORD *)(a1 + 60) = 0;
              *(_QWORD *)(a1 + 68) = 0;
              *(_DWORD *)(a1 + 40) = v32;
              *(_QWORD *)(a1 + 108) = v52;
              *(_QWORD *)(a1 + 116) = v53;
              v55 = *(_QWORD *)(a1 + 172);
              v54 = *(_QWORD *)(a1 + 180);
              LODWORD(v107[0]) = v32;
              v56 = *(_WORD *)(a1 + 494);
              *(_QWORD *)(a1 + 76) = 0;
              *(_QWORD *)(a1 + 84) = 0;
              *(_QWORD *)(a1 + 60) = v55;
              *(_QWORD *)(a1 + 68) = v54;
              v57 = *(_QWORD *)(a1 + 188);
              v58 = *(_QWORD *)(a1 + 196);
              WORD2(v107[0]) = v56;
              if ( (_DWORD)v33 == 24 )
                v59 = 0;
              else
                v59 = 100 - v46;
              *(_QWORD *)v26 = 0;
              *(_QWORD *)(a1 + 52) = 0;
              *(_QWORD *)(a1 + 76) = v57;
              *(_QWORD *)(a1 + 84) = v58;
              v60 = *v25;
              v61 = *(_QWORD *)(a1 + 164);
              *(_BYTE *)(a1 + 34) = v41;
              BYTE6(v107[0]) = v33 + 1;
              *(_QWORD *)v26 = v60;
              *(_QWORD *)(a1 + 52) = v61;
              memset(&v1[v46], 0, v59);
              v102 = v1;
              memcpy(v1, (const void *)(a1 + 44), v46);
              v62 = raw_spin_lock_irqsave(&v103);
              _kfifo_in(a1 + 1200, v107, 4 * (unsigned int)BYTE6(v107[0]) + 7);
              raw_spin_unlock_irqrestore(&v103, v62);
              v105[0] = 15;
              v63 = raw_spin_lock_irqsave(v27);
              v64 = _kfifo_in(a1 + 1104, v105, 1);
              v65 = v27;
              v66 = v64;
              v67 = v65;
              raw_spin_unlock_irqrestore(v65, v63);
              if ( v66 )
                _wake_up(a1 + 464, 1, 1, 0);
              v27 = v67;
              v1 = v102;
              result = 87500;
            }
          }
        }
      }
LABEL_30:
      v24 = *(unsigned __int8 *)(a1 + 502);
      v28 = 0;
      if ( (v31 & 1) == 0 )
        goto LABEL_67;
    }
  }
  if ( v10 != 1 )
    goto LABEL_25;
LABEL_67:
  if ( *(unsigned __int8 *)(a1 + 799) <= 2u )
  {
    v68 = *(_BYTE *)(a1 + 500);
    rtc6226_update_ps(v2, 2 * (v68 & 3u), *(unsigned __int8 *)(a1 + 505));
    result = rtc6226_update_ps(v2, (2 * (v68 & 3)) | 1u, *(unsigned __int8 *)(a1 + 504));
  }
LABEL_71:
  if ( !*(_BYTE *)(a1 + 800) || v10 != *(unsigned __int8 *)(a1 + 800) )
  {
    if ( !*(_BYTE *)(a1 + 801) || v10 != *(unsigned __int8 *)(a1 + 801) )
      goto LABEL_139;
    v76 = *(_WORD *)(a1 + 500) & 0x1F;
    if ( v76 )
    {
      v77 = *(unsigned __int8 *)(a1 + 1059);
      if ( v76 != v77 )
      {
        v90 = 0;
        *(_BYTE *)(a1 + 1058) = 0;
        goto LABEL_114;
      }
    }
    else
    {
      LOBYTE(v77) = 0;
      *(_WORD *)(a1 + 1058) = 0;
    }
    v78 = *(unsigned __int8 *)(a1 + 1058);
    if ( v78 == 255 )
      goto LABEL_139;
    v79 = *(unsigned __int16 *)(a1 + 502);
    v80 = *(unsigned __int8 *)(a1 + 1060);
    v81 = (_BYTE *)(a1 + 802 + v78);
    v81[1] = v79;
    v82 = *(_BYTE *)(a1 + 1058);
    *v81 = BYTE1(v79);
    *(_BYTE *)(a1 + 1058) = v82 + 2;
    if ( !v80 && v79 == 13 )
      goto LABEL_93;
    if ( v80 != 1 )
      goto LABEL_124;
    if ( (v79 & 0xFF00) == 0xD00 )
    {
LABEL_93:
      *(_BYTE *)(a1 + 1058) = v82;
      v83 = v82;
      goto LABEL_94;
    }
    if ( (unsigned __int8)v79 != 13 )
    {
LABEL_124:
      if ( v82 == -3 )
        goto LABEL_139;
      v98 = *(unsigned __int16 *)(a1 + 504);
      v99 = (_BYTE *)(a1 + 802 + (unsigned __int8)(v82 + 2));
      v99[1] = v98;
      v82 = *(_BYTE *)(a1 + 1058);
      *v99 = BYTE1(v98);
      v83 = v82 + 2;
      *(_BYTE *)(a1 + 1058) = v82 + 2;
      if ( !v80 && v98 == 13 )
        goto LABEL_93;
      if ( v80 != 1 )
        goto LABEL_131;
      if ( (v98 & 0xFF00) == 0xD00 )
        goto LABEL_93;
      if ( (unsigned __int8)v98 != 13 )
      {
LABEL_131:
        if ( v76 != 31 && v98 != 13 )
        {
LABEL_101:
          v90 = v77 + 1;
LABEL_114:
          *(_BYTE *)(a1 + 1059) = v90;
          goto LABEL_139;
        }
LABEL_94:
        if ( v83 )
        {
          v26 = *(unsigned __int8 *)(a1 + 1058);
          result = _kmalloc_noprof(v26 + 3, 2080);
          v2 = result;
          if ( result )
          {
            v84 = *(unsigned __int8 *)(a1 + 1058);
            v85 = *(_BYTE *)(a1 + 1060);
            v86 = *(_BYTE *)(a1 + 1062);
            *(_BYTE *)result = v84;
            *(_BYTE *)(result + 1) = v85;
            *(_BYTE *)(result + 2) = v86;
            if ( v26 < v84 )
              goto LABEL_135;
            memcpy((void *)(result + 3), (const void *)(a1 + 802), v84);
            v87 = raw_spin_lock_irqsave(a1 - 36);
            _kfifo_in(a1 + 1368, v2, (unsigned int)*(unsigned __int8 *)(a1 + 1058) + 3);
            raw_spin_unlock_irqrestore(a1 - 36, v87);
            LOBYTE(v107[0]) = 21;
            v88 = raw_spin_lock_irqsave(a1 - 80);
            v89 = _kfifo_in(a1 + 1104, v107, 1);
            raw_spin_unlock_irqrestore(a1 - 80, v88);
            if ( v89 )
              _wake_up(a1 + 464, 1, 1, 0);
            result = kfree(v2);
          }
        }
        LOBYTE(v77) = 0;
        *(_BYTE *)(a1 + 1058) = 0;
        goto LABEL_101;
      }
    }
    ++v82;
    goto LABEL_93;
  }
  v70 = *(unsigned __int16 *)(a1 + 502);
  v26 = (v70 >> 13) & 0xFFFFFFC7 | (8 * (*(_WORD *)(a1 + 500) & 7));
  LODWORD(v1) = ((unsigned __int8)(v70 >> 11) | (unsigned __int8)(32 * v70)) & 0x3F;
  if ( !((unsigned int)v1 | (unsigned int)v26) )
  {
    v91 = &unk_CE95;
LABEL_137:
    v92 = "rtc6226_rt_plus";
    goto LABEL_138;
  }
  if ( (_DWORD)v26 )
    v71 = 3;
  else
    v71 = 0;
  if ( (_DWORD)v1 )
    v71 += 3;
  v2 = (unsigned int)(v71 + 2);
  v72 = (_BYTE *)_kmalloc_noprof(v2, 2080);
  if ( !v72 )
  {
LABEL_136:
    v91 = &unk_DC20;
    goto LABEL_137;
  }
  while ( 1 )
  {
    v73 = *(_BYTE *)(a1 + 1061);
    v74 = v72;
    *v72 = v2;
    v72[1] = v73;
    if ( !(_DWORD)v26 )
      break;
    if ( v2 != 2 )
    {
      v72[2] = v26;
      if ( v2 >= 4 )
      {
        v75 = *(unsigned __int16 *)(a1 + 502);
        v72[3] = (v75 >> 7) & 0x3F;
        if ( v2 != 4 )
        {
          v26 = 5;
          v72[4] = (v75 >> 1) & 0x3F;
          if ( !(_DWORD)v1 )
            goto LABEL_108;
          goto LABEL_104;
        }
      }
    }
LABEL_133:
    __break(1u);
LABEL_134:
    __break(0x5512u);
LABEL_135:
    _fortify_panic(17, v26);
    StatusReg = _ReadStatusReg(SP_EL0);
    v101 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &rtc6226_rt_plus__alloc_tag;
    v72 = (_BYTE *)_kmalloc_noprof(v2, 2080);
    *(_QWORD *)(StatusReg + 80) = v101;
    if ( !v72 )
      goto LABEL_136;
  }
  v26 = 2;
  if ( !(_DWORD)v1 )
    goto LABEL_108;
LABEL_104:
  if ( v2 <= (unsigned int)v26 )
    goto LABEL_133;
  v72[(unsigned int)v26] = (_BYTE)v1;
  if ( v2 <= (unsigned __int64)(unsigned int)v26 + 1 )
    goto LABEL_133;
  v93 = (unsigned int)v26 + 2LL;
  v72[(unsigned int)v26 + 1] = (*(unsigned __int16 *)(a1 + 504) >> 5) & 0x3F;
  if ( v2 <= v93 )
    goto LABEL_133;
  LODWORD(v26) = v26 + 3;
  v72[v93] = *(_BYTE *)(a1 + 504) & 0x1F;
LABEL_108:
  v94 = raw_spin_lock_irqsave(a1 - 40);
  _kfifo_in(a1 + 1344, v74, (unsigned int)v26);
  raw_spin_unlock_irqrestore(a1 - 40, v94);
  LOBYTE(v107[0]) = 20;
  v95 = raw_spin_lock_irqsave(a1 - 80);
  LODWORD(v94) = _kfifo_in(a1 + 1104, v107, 1);
  raw_spin_unlock_irqrestore(a1 - 80, v95);
  if ( (_DWORD)v94 )
    _wake_up(a1 + 464, 1, 1, 0);
  result = kfree(v74);
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return result;
}
