__int64 __fastcall VI530X_Start_Offset_Calibration(__int64 a1)
{
  int v2; // w1
  int v3; // w2
  int v4; // w1
  int v5; // w2
  int v6; // w20
  int v7; // w22
  int v8; // w9
  int v9; // w1
  int v10; // w2
  int v11; // w1
  int v12; // w2
  int v13; // w1
  int v14; // w2
  int v15; // w1
  int v16; // w2
  int v17; // w1
  int v18; // w2
  int v19; // w1
  int v20; // w2
  int v21; // w1
  int v22; // w2
  int v23; // w1
  int v24; // w2
  int v25; // w1
  int v26; // w2
  int v27; // w1
  int v28; // w2
  int v29; // w1
  int v30; // w2
  int v31; // w1
  int v32; // w2
  int v33; // w1
  int v34; // w2
  int v35; // w1
  int v36; // w2
  int v37; // w1
  int v38; // w2
  int v39; // w1
  int v40; // w2
  int v41; // w1
  int v42; // w2
  int v43; // w1
  int v44; // w2
  int v45; // w1
  int v46; // w2
  int v47; // w1
  int v48; // w2
  int v49; // w1
  int v50; // w2
  int v51; // w1
  int v52; // w2
  int v53; // w1
  int v54; // w2
  int v55; // w1
  int v56; // w2
  int v57; // w1
  int v58; // w2
  int v59; // w1
  int v60; // w2
  int v61; // w1
  int v62; // w2
  int v63; // w1
  int v64; // w2
  int v65; // w1
  int v66; // w2
  int v67; // w1
  int v68; // w2
  int v69; // w1
  int v70; // w2
  int v71; // w1
  int v72; // w2
  int v73; // w1
  int v74; // w2
  int v75; // w1
  int v76; // w2
  int v77; // w8
  unsigned int v78; // w11
  unsigned int v79; // w13
  unsigned int v80; // w12
  __int16 *v81; // x9
  __int16 *v82; // x10
  unsigned int v83; // w14
  bool v84; // cf
  unsigned int v85; // w11
  unsigned int v86; // w11
  unsigned int v87; // w12
  __int64 v88; // x14
  __int64 v89; // x13
  int v90; // w13
  int v91; // w10
  int v92; // w9
  int v93; // w9
  void *v94; // x0
  int v95; // w9
  unsigned int v96; // w20
  void *v98; // x0
  char v99[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v100; // [xsp+8h] [xbp-28h] BYREF
  __int64 v101; // [xsp+10h] [xbp-20h]
  __int64 v102; // [xsp+18h] [xbp-18h]
  __int64 v103; // [xsp+20h] [xbp-10h]
  __int64 v104; // [xsp+28h] [xbp-8h]

  v104 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  v99[0] = 0;
  vi530x_write_reg_offset(a1, 12, 0, 1);
  vi530x_write_reg_offset(a1, 12, 1, 1);
  vi530x_write_reg_offset(a1, 12, 2, 36);
  vi530x_write_reg_offset(a1, 12, 3, 0);
  vi530x_write_byte(a1, 10, 9);
  _const_udelay((const char *)0x147AEB8);
  if ( (unsigned int)VI530X_Start_Continuous_Measure(a1, v2, v3) )
  {
    v98 = &unk_403DC1;
LABEL_63:
    printk(v98);
    v96 = -4;
    goto LABEL_60;
  }
  v6 = 0;
  v7 = 0;
  while ( 1 )
  {
    do
    {
      _const_udelay("d: %u rc: %d", v4, v5);
      _const_udelay("d: %u rc: %d", v9, v10);
      _const_udelay("d: %u rc: %d", v11, v12);
      _const_udelay("d: %u rc: %d", v13, v14);
      _const_udelay("d: %u rc: %d", v15, v16);
      _const_udelay("d: %u rc: %d", v17, v18);
      _const_udelay("d: %u rc: %d", v19, v20);
      _const_udelay("d: %u rc: %d", v21, v22);
      _const_udelay("d: %u rc: %d", v23, v24);
      _const_udelay("d: %u rc: %d", v25, v26);
      _const_udelay("d: %u rc: %d", v27, v28);
      _const_udelay("d: %u rc: %d", v29, v30);
      _const_udelay("d: %u rc: %d", v31, v32);
      _const_udelay("d: %u rc: %d", v33, v34);
      _const_udelay("d: %u rc: %d", v35, v36);
      _const_udelay("d: %u rc: %d", v37, v38);
      _const_udelay("d: %u rc: %d", v39, v40);
      _const_udelay("d: %u rc: %d", v41, v42);
      _const_udelay("d: %u rc: %d", v43, v44);
      _const_udelay("d: %u rc: %d", v45, v46);
      _const_udelay("d: %u rc: %d", v47, v48);
      _const_udelay("d: %u rc: %d", v49, v50);
      _const_udelay("d: %u rc: %d", v51, v52);
      _const_udelay("d: %u rc: %d", v53, v54);
      _const_udelay("d: %u rc: %d", v55, v56);
      _const_udelay("d: %u rc: %d", v57, v58);
      _const_udelay("d: %u rc: %d", v59, v60);
      _const_udelay("d: %u rc: %d", v61, v62);
      _const_udelay("d: %u rc: %d", v63, v64);
      _const_udelay("d: %u rc: %d", v65, v66);
      _const_udelay("d: %u rc: %d", v67, v68);
      _const_udelay("d: %u rc: %d", v69, v70);
      _const_udelay("d: %u rc: %d", v71, v72);
      _const_udelay("d: %u rc: %d", v73, v74);
      _const_udelay("d: %u rc: %d", v75, v76);
      if ( (unsigned int)vi530x_read_byte(a1, 3, v99) )
      {
        v94 = &unk_3FC695;
        goto LABEL_55;
      }
    }
    while ( (v99[0] & 1) == 0 );
    if ( (unsigned int)vi530x_read_multibytes(a1, 12, &v100, 32) )
      break;
    v77 = SWORD2(v101);
    v78 = HIDWORD(v103);
    if ( SWORD2(v101) <= 35 && HIDWORD(v103) < 10000 * (unsigned int)*(unsigned __int8 *)(a1 + 256) )
    {
      v77 = *(unsigned __int16 *)((char *)&v100 + 1);
      v78 = v101;
    }
    v79 = (BYTE3(v103) << 16) | (BYTE2(v103) << 8) | BYTE1(v103);
    v80 = ((unsigned __int8)v103 << 16) | (HIBYTE(v102) << 8) | BYTE6(v102);
    if ( v79 <= 0x1F40 )
      v81 = (__int16 *)&unk_457430;
    else
      v81 = (__int16 *)&unk_457448;
    if ( v79 <= 0x1F40 )
      v82 = (__int16 *)&unk_45743C;
    else
      v82 = (__int16 *)&unk_457454;
    if ( v80 )
    {
      v83 = (v79 >> 3) * *(unsigned __int8 *)(a1 + 256);
      v84 = v78 >= v83;
      v85 = v78 - v83;
      if ( v85 != 0 && v84 )
      {
        v86 = 16 * v85 / v80;
        if ( v79 <= 0x1F40 )
          v87 = 500;
        else
          v87 = 160;
        if ( v86 < v87 )
        {
          v88 = 0;
          goto LABEL_28;
        }
        if ( v79 <= 0x1F40 )
          v87 = 800;
        else
          v87 = 350;
        if ( v86 < v87 )
        {
          v88 = 1;
          v89 = 2;
          goto LABEL_29;
        }
        if ( v79 <= 0x1F40 )
          v87 = 1128;
        else
          v87 = 700;
        if ( v86 < v87 )
        {
          v88 = 2;
          v89 = 3;
          goto LABEL_29;
        }
        if ( v79 <= 0x1F40 )
          v87 = 1734;
        else
          v87 = 1200;
        if ( v86 < v87 )
        {
          v88 = 3;
          v89 = 4;
          goto LABEL_29;
        }
        if ( v86 < 0x7D0 )
        {
          v87 = 2000;
          v88 = 4;
          v89 = 5;
          goto LABEL_29;
        }
        if ( v79 <= 0x1F40 )
          v93 = 10;
        else
          v93 = 30;
        v92 = (int)((v86 - v87) * v93) / (int)(2000 - v87);
        if ( v79 <= 0x1F40 )
          v91 = 25;
        else
          v91 = 40;
      }
      else
      {
        v86 = 0;
        v88 = 0;
        if ( v79 <= 0x1F40 )
          v87 = 500;
        else
          v87 = 160;
LABEL_28:
        v89 = 1;
LABEL_29:
        v90 = v82[v89];
        v91 = v82[v88];
        v92 = (int)((v86 - v81[v88]) * (v90 - v91)) / (int)(v87 - v81[v88]);
      }
      v8 = v92 + v91;
      goto LABEL_4;
    }
    v8 = 0;
LABEL_4:
    ++v7;
    v6 += v77 + v8;
    if ( v7 == 30 )
      goto LABEL_56;
  }
  v94 = &unk_4424DD;
LABEL_55:
  printk(v94);
LABEL_56:
  if ( (unsigned int)vi530x_write_byte(a1, 10, 31) )
  {
    printk(&unk_42313F);
    v98 = &unk_427326;
    goto LABEL_63;
  }
  v95 = *(_DWORD *)(a1 + 228);
  *(_WORD *)(a1 + 42) = ((__int16)((unsigned int)(34953 * (__int16)v6) >> 16) >> 4)
                      + (((v6 + ((unsigned int)(-30583 * (__int16)v6) >> 16)) & 0x8000) >> 15)
                      - *(_WORD *)(a1 + 44);
  if ( v95 )
    printk(&unk_3E7EF5);
  v96 = 0;
LABEL_60:
  vi530x_write_reg_offset(a1, 12, 0, 1);
  vi530x_write_reg_offset(a1, 12, 1, 1);
  vi530x_write_reg_offset(a1, 12, 2, 36);
  vi530x_write_reg_offset(a1, 12, 3, 1);
  vi530x_write_byte(a1, 10, 9);
  _const_udelay((const char *)0x147AEB8);
  _ReadStatusReg(SP_EL0);
  return v96;
}
