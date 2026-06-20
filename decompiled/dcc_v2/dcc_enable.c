__int64 __fastcall dcc_enable(__int64 *a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  unsigned int v4; // w8
  _BYTE *v5; // x9
  int v6; // w11
  unsigned int v7; // w10
  int v8; // w8
  unsigned int v9; // w28
  __int64 v10; // x27
  _QWORD *v11; // x9
  int v12; // w9
  unsigned int v13; // w23
  unsigned int v14; // w26
  unsigned int v15; // w8
  __int64 v16; // x0
  int v17; // w9
  unsigned int v18; // w8
  _QWORD **v19; // x9
  int v20; // w8
  _QWORD *v21; // x10
  unsigned int v22; // w28
  int v23; // w9
  unsigned int v24; // w1
  unsigned int v25; // w10
  unsigned int v26; // w9
  int v27; // w11
  unsigned int v28; // w9
  unsigned int v29; // w10
  int v30; // w1
  char v31; // w11
  int v32; // w12
  int v33; // w13
  int v34; // w16
  unsigned int v35; // w14
  unsigned int v36; // w17
  int v37; // w15
  int v38; // w15
  int v39; // w14
  int *v40; // x0
  unsigned int v41; // w0
  int v42; // w2
  unsigned int v43; // w1
  unsigned int v44; // w17
  int v45; // w1
  unsigned int v46; // w3
  char v47; // w4
  int v48; // w1
  int v49; // w3
  int v50; // w3
  unsigned int v51; // w2
  int v52; // w4
  unsigned int v53; // w0
  unsigned int v54; // w28
  int v55; // w11
  unsigned int v56; // w10
  int v57; // w10
  int v58; // w11
  int v59; // w0
  int v60; // w8
  int v61; // w9
  int v62; // w10
  unsigned int v63; // w9
  int v64; // w9
  int v65; // w9
  int v66; // w11
  __int64 v67; // x9
  unsigned __int64 v68; // x10
  int v69; // w11
  __int64 v70; // x9
  unsigned __int64 v71; // x10
  int v72; // w11
  __int64 v73; // x9
  unsigned __int64 v74; // x10
  int v75; // w8
  unsigned int v76; // w9
  int v77; // w13
  int v78; // w8
  unsigned int v79; // w10
  int v80; // w9
  __int64 v81; // x8
  int v82; // w10
  int v83; // w12
  unsigned int v84; // w11
  int v85; // w12
  int v86; // w9
  unsigned int v87; // w11
  int v88; // w10
  __int64 v89; // x8
  int v91; // w9
  int v92; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v93; // [xsp+18h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[2];
  v92 = 0;
  v3 = *(_QWORD *)(v2 + 744);
  mutex_lock(a1 + 3);
  v4 = *((_DWORD *)a1 + 82);
  if ( !v4 )
    goto LABEL_194;
  v5 = (_BYTE *)a1[15];
  if ( (*v5 & 1) == 0 )
  {
    v6 = 1;
    do
    {
      v7 = v6;
      if ( v4 == v6 )
        break;
      ++v6;
    }
    while ( v5[v7] != 1 );
    if ( v7 >= v4 )
    {
LABEL_194:
      _memset_io(a1[9], 222, *((unsigned int *)a1 + 20));
      if ( !*((_DWORD *)a1 + 82) )
      {
        v9 = 0;
LABEL_179:
        *((_DWORD *)a1 + 87) = 4 * *((_DWORD *)a1 + 27);
        goto LABEL_180;
      }
    }
  }
  v8 = 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = v8;
    v11 = (_QWORD *)(a1[39] + 16LL * v8);
    if ( (_QWORD *)*v11 == v11 )
      goto LABEL_10;
    if ( *(_BYTE *)(a1[15] + v8) != 1 )
      break;
    dev_err(a1[2], "List %d is already enabled\n", v8);
LABEL_10:
    v8 = v10 + 1;
    if ( (unsigned int)(v10 + 1) >= *((_DWORD *)a1 + 82) )
      goto LABEL_179;
  }
  v12 = *((_DWORD *)a1 + 26);
  v13 = v8 << 7;
  v14 = (v8 << 7) | 0x34;
  if ( v12 == 1 )
  {
    v15 = v13 | 0x2C;
  }
  else
  {
    v15 = (v8 << 7) | 0x34;
    if ( !v12 )
      v15 = v13 | 0x1C;
  }
  v16 = a1[2];
  if ( (*(_DWORD *)(*a1 + v15) & 1) != 0 )
  {
    dev_err(v16, "List %d is already locked\n", v10);
    goto LABEL_10;
  }
  dev_info(v16, "DCC list passed %d\n", v10);
  v17 = *((_DWORD *)a1 + 26);
  if ( v17 == 1 )
  {
    v18 = v13 | 0x2C;
  }
  else
  {
    v18 = ((_DWORD)v10 << 7) | 0x34;
    if ( !v17 )
      v18 = v13 | 0x1C;
  }
  *(_DWORD *)(*a1 + v18) = 1;
  v19 = (_QWORD **)(a1[39] + 16 * v10);
  v20 = *((_DWORD *)a1 + 27);
  v21 = *v19;
  v22 = 4 * v20;
  if ( *v19 == v19 )
  {
    v23 = 0;
LABEL_25:
    v24 = *((_DWORD *)a1 + 20);
    if ( v24 - 4 < v22 )
      goto LABEL_185;
    *(_DWORD *)(a1[9] + v22) = -1073741824;
    v25 = v22 + 4;
    if ( *(_DWORD *)(a1[11] + 4 * v10) || *(_DWORD *)(a1[12] + 4 * v10) )
    {
      v24 = *((_DWORD *)a1 + 20);
      v26 = v25 >> 2;
      *((_DWORD *)a1 + 27) = v25 >> 2;
      if ( v25 > v24 )
      {
        v22 += 4;
LABEL_185:
        _memset_io(a1[9], 0, v24);
        dev_err(a1[2], "DCC SRAM oversteps, 0x%x (0x%x)\n", v22, *((unsigned int *)a1 + 20));
        goto LABEL_186;
      }
    }
    else
    {
      v22 = v25 + v23;
      v24 = *((_DWORD *)a1 + 20);
      *((_DWORD *)a1 + 27) = (v25 + v23) >> 2;
      if ( v25 + v23 > v24 )
        goto LABEL_185;
      v26 = v25 >> 2;
    }
    v27 = *((_DWORD *)a1 + 26);
    *((_DWORD *)a1 + 28) = v26;
    v28 = v13 | 0x3C;
    if ( v27 == 1 )
    {
      v29 = ((_DWORD)v10 << 7) | 0x34;
    }
    else
    {
      v29 = v13 | 0x3C;
      if ( !v27 )
        v29 = v13 | 0x24;
    }
    v54 = v13 | 0x40;
    *(_DWORD *)(*a1 + v29) = v20 + (*((_DWORD *)a1 + 21) >> 2);
    v55 = *((_DWORD *)a1 + 26);
    if ( v55 == 1 )
    {
      v56 = v13 | 0x38;
    }
    else
    {
      v56 = v13 | 0x40;
      if ( !v55 )
        v56 = v13 | 0x28;
    }
    *(_DWORD *)(*a1 + v56) = *((_DWORD *)a1 + 28) + (*((_DWORD *)a1 + 21) >> 2);
    v57 = *((_DWORD *)a1 + 26);
    v58 = v13 | 0x44;
    if ( v57 != 1 )
    {
      v28 = v13 | 0x44;
      if ( !v57 )
        v28 = v13 | 0x2C;
    }
    *(_DWORD *)(*a1 + v28) = 4095;
    if ( (*(_DWORD *)(*a1 + 4) & 0x80) == 0 )
    {
      v9 = 0;
      goto LABEL_112;
    }
    v59 = of_property_read_variable_u32_array(v3, "qcom,transaction_timeout", &v92, 1, 0);
    if ( v59 < 0 )
    {
      v60 = 63;
      v92 = 63;
    }
    else
    {
      v60 = v92;
      if ( !v92 )
      {
        v58 = v13 | 0x44;
        v9 = 0;
        goto LABEL_112;
      }
    }
    v61 = *((_DWORD *)a1 + 26);
    if ( v61 != 1 )
    {
      if ( v61 )
        v54 = v13 | 0x48;
      else
        v54 = v13 | 0x30;
    }
    v58 = v13 | 0x44;
    *(_DWORD *)(*a1 + v54) = v60;
    v9 = v59 & (v59 >> 31);
LABEL_112:
    v62 = *((_DWORD *)a1 + 26);
    if ( v62 == 1 )
    {
      v63 = v58;
    }
    else
    {
      v63 = v13 | 0x4C;
      if ( !v62 )
        v63 = v13 | 0x30;
    }
    *(_DWORD *)(*a1 + v63) = 0;
    v64 = *((_DWORD *)a1 + 26);
    if ( v64 == 1 )
    {
      v65 = 72;
LABEL_120:
      v14 = v13 | v65;
    }
    else if ( v64 )
    {
      v65 = 80;
      goto LABEL_120;
    }
    *(_DWORD *)(*a1 + v14) = 7;
    dev_info(a1[2], "All values written to enable.\n");
    __dsb(0xFu);
    *(_BYTE *)(a1[15] + v10) = 1;
    if ( *(_DWORD *)(a1[12] + 4 * v10) == 1 )
    {
      if ( (dcc_ready(a1) & 1) == 0 )
        dev_err(a1[2], "DCC is not ready\n");
      v66 = *((_DWORD *)a1 + 26);
      if ( v66 == 1 )
      {
        v67 = 88;
LABEL_128:
        v68 = ((unsigned __int64)*((unsigned __int8 *)a1 + 332) << 7) | v67;
      }
      else
      {
        if ( !v66 )
        {
          v67 = 68;
          goto LABEL_128;
        }
        v68 = ((unsigned __int64)*((unsigned __int8 *)a1 + 332) << 7) | 0x60;
      }
      *(_DWORD *)(*a1 + v68) = 1;
      if ( (dcc_ready(a1) & 1) == 0 )
        dev_err(a1[2], "DCC is not ready\n");
      v69 = *((_DWORD *)a1 + 26);
      if ( v69 )
      {
        if ( v69 == 1 )
        {
          v70 = 88;
          goto LABEL_136;
        }
        v71 = ((unsigned __int64)*((unsigned __int8 *)a1 + 332) << 7) | 0x60;
      }
      else
      {
        v70 = 68;
LABEL_136:
        v71 = ((unsigned __int64)*((unsigned __int8 *)a1 + 332) << 7) | v70;
      }
      *(_DWORD *)(*a1 + v71) = 1;
      v72 = *((_DWORD *)a1 + 26);
      if ( v72 == 1 )
      {
        v73 = 72;
LABEL_142:
        v74 = ((unsigned __int64)*((unsigned __int8 *)a1 + 332) << 7) | v73;
      }
      else
      {
        if ( !v72 )
        {
          v73 = 52;
          goto LABEL_142;
        }
        v74 = ((unsigned __int64)*((unsigned __int8 *)a1 + 332) << 7) | 0x50;
      }
      *(_DWORD *)(*a1 + v74) = 2;
      if ( (a1[19] & 1) == 0 )
      {
        v75 = *((_DWORD *)a1 + 26);
        if ( v75 == 1 )
        {
          v76 = v13 | 0x44;
        }
        else
        {
          v76 = v13 | 0x4C;
          if ( !v75 )
            v76 = v13 | 0x30;
        }
        *(_DWORD *)(*a1 + v76) = 2;
      }
    }
    v77 = *((_DWORD *)a1 + 26);
    if ( v77 == 2 )
    {
      *(_DWORD *)(*a1 + v13 + 108) = *(unsigned __int8 *)(a1[47] + v10);
      v78 = *((_DWORD *)a1 + 26);
      if ( v78 == 1 )
      {
        v79 = v13 | 0x60;
      }
      else if ( v78 )
      {
        v79 = v13 | 0x68;
      }
      else
      {
        v79 = v13 | 0x4C;
      }
      *(_DWORD *)(*a1 + v79) = *(unsigned __int8 *)(a1[42] + v10);
      v85 = *((_DWORD *)a1 + 26);
      v86 = *(_DWORD *)(a1[12] + 4 * v10);
      v87 = v13 | 0x38;
      v88 = 16 * *(_DWORD *)(a1[11] + 4 * v10);
      v89 = *a1;
      if ( *(_BYTE *)(a1[16] + v10) == 1 )
      {
        if ( v85 == 1 )
        {
          v87 = v13 | 0x30;
        }
        else if ( !v85 )
        {
          v87 = v13 | 0x20;
        }
        *(_DWORD *)(v89 + v87) = v88 | v86 | 0x100;
      }
      else
      {
        if ( v85 == 1 )
        {
          v87 = v13 | 0x30;
        }
        else if ( !v85 )
        {
          v87 = v13 | 0x20;
        }
        *(_DWORD *)(v89 + v87) = (v86 | v88) & 0xFFFFFEFF;
      }
    }
    else
    {
      v80 = *(unsigned __int8 *)(a1[42] + v10) << 8;
      v81 = *a1;
      v82 = 16 * *(_DWORD *)(a1[11] + 4 * v10);
      v83 = *(_DWORD *)(a1[12] + 4 * v10);
      v84 = v13 | 0x38;
      if ( *(_BYTE *)(a1[16] + v10) == 1 )
      {
        if ( v77 == 1 )
        {
          v84 = v13 | 0x30;
        }
        else if ( !v77 )
        {
          v84 = v13 | 0x20;
        }
        *(_DWORD *)(v81 + v84) = v82 | v83 | v80 | 0x200;
      }
      else
      {
        if ( v77 == 1 )
        {
          v84 = v13 | 0x30;
        }
        else if ( !v77 )
        {
          v84 = v13 | 0x20;
        }
        *(_DWORD *)(v81 + v84) = (v80 | v83 | v82) & 0xFFFFFDFF;
      }
    }
    goto LABEL_10;
  }
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v23 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  do
  {
    v38 = *((_DWORD *)v21 - 2);
    switch ( v38 )
    {
      case 1:
        if ( v34 )
        {
          v24 = *((_DWORD *)a1 + 20);
          if ( v24 - 4 < v22 )
            goto LABEL_185;
          *(_DWORD *)(a1[9] + v22) = v34;
          v22 += 4;
        }
        if ( (v31 & 1) != 0 )
        {
          v24 = *((_DWORD *)a1 + 20);
          if ( v24 - 4 < v22 )
            goto LABEL_185;
          v36 = 0;
          v34 = 0;
          v31 = 0;
          v37 = 0;
          v23 += (v23 - v33) * v32;
          v33 = 0;
          v39 = ((-1LL << *((_BYTE *)a1 + 344)) + 0x10000000) & (v32 << *((_BYTE *)a1 + 344)) | ((v22 - v35) >> 2);
          v40 = (int *)(a1[9] + v22);
          v22 += 4;
          *v40 = v39 | 0x40000000;
          v35 = 0;
        }
        else
        {
          v36 = 0;
          v34 = 0;
          v37 = 0;
          v35 = v22;
          v33 = v23;
          v32 = *((_DWORD *)v21 - 6) - 1;
          v31 = 1;
        }
        break;
      case 3:
        if ( v34 )
        {
          v24 = *((_DWORD *)a1 + 20);
          if ( v24 - 4 < v22 )
            goto LABEL_185;
          v36 = 0;
          v37 = 0;
          *(_DWORD *)(a1[9] + v22) = v34;
          v22 += 4;
        }
        else
        {
          v37 = v30;
        }
        v24 = *((_DWORD *)a1 + 20);
        if ( v24 - 4 < v22 )
          goto LABEL_185;
        v50 = *((_DWORD *)v21 - 8);
        v51 = *((_DWORD *)v21 - 9);
        if ( *((_BYTE *)v21 - 12) )
          v52 = 805306368;
        else
          v52 = 0x10000000;
        *(_DWORD *)(a1[9] + v22) = v52 & 0xF0000000 | (*((_DWORD *)v21 - 10) >> 4);
        v24 = *((_DWORD *)a1 + 20);
        v53 = v22 + 4;
        if ( v24 - 4 < v22 + 4
          || (*(_DWORD *)(a1[9] + v53) = ((v50 & 0x7F) << 8) | (unsigned __int8)(v51 >> 2) | v34 | 0xC0008000,
              v24 = *((_DWORD *)a1 + 20),
              v53 = v22 + 8,
              v24 - 4 < v22 + 8) )
        {
LABEL_182:
          v22 = v53;
          goto LABEL_185;
        }
        v34 = 0;
        v22 += 12;
        *(_DWORD *)(a1[9] + v53) = *((_DWORD *)v21 - 5);
        break;
      case 2:
        if ( v34 )
        {
          v24 = *((_DWORD *)a1 + 20);
          if ( v24 - 4 < v22 )
            goto LABEL_185;
          v36 = 0;
          v37 = 0;
          *(_DWORD *)(a1[9] + v22) = v34;
          v22 += 4;
        }
        else
        {
          v37 = v30;
        }
        v24 = *((_DWORD *)a1 + 20);
        if ( v24 - 4 < v22 )
          goto LABEL_185;
        *(_DWORD *)(a1[9] + v22) = 0x80000000;
        v24 = *((_DWORD *)a1 + 20);
        if ( v24 - 4 < v22 + 4 )
        {
          v22 += 4;
          goto LABEL_185;
        }
        *(_DWORD *)(a1[9] + v22 + 4) = *((_DWORD *)v21 - 4);
        v24 = *((_DWORD *)a1 + 20);
        v53 = v22 + 8;
        if ( v24 - 4 < v22 + 8 )
          goto LABEL_182;
        v34 = 0;
        v22 += 12;
        *(_DWORD *)(a1[9] + v53) = *((_DWORD *)v21 - 5);
        break;
      default:
        v41 = *((_DWORD *)v21 - 9) >> 2;
        v42 = *((_DWORD *)v21 - 8);
        if ( *((_BYTE *)v21 - 12) )
          v37 = (*((_DWORD *)v21 - 10) >> 4) | 0x20000000;
        else
          v37 = *((_DWORD *)v21 - 10) >> 4;
        if ( !v30 || v30 != v37 || v36 > v41 )
        {
          if ( v34 )
          {
            v24 = *((_DWORD *)a1 + 20);
            if ( v24 - 4 < v22 )
              goto LABEL_185;
            *(_DWORD *)(a1[9] + v22) = v34;
            v22 += 4;
          }
          v24 = *((_DWORD *)a1 + 20);
          if ( v24 - 4 < v22 )
            goto LABEL_185;
          v36 = 0;
          v34 = 0;
          *(_DWORD *)(a1[9] + v22) = v37;
          v22 += 4;
        }
        v43 = v41 - v36;
        if ( v41 - v36 > 0xFF || (v44 = *((_DWORD *)v21 - 8), v44 >= 0x80) )
        {
          dev_err(
            a1[2],
            "DCC: Programming error Base: 0x%x, offset 0x%x\n",
            *((unsigned int *)v21 - 10),
            *((unsigned int *)v21 - 9));
          goto LABEL_186;
        }
        v45 = v43 | (v44 << 8);
        v46 = v34 & 0x7FFF | 0xC0000000;
        if ( v34 )
          v47 = 15;
        else
          v47 = 0;
        v48 = v45 << v47;
        if ( !v34 )
          v46 = -1073709056;
        v49 = v48 | v46;
        if ( v34 )
        {
          v24 = *((_DWORD *)a1 + 20);
          if ( v24 - 4 < v22 )
            goto LABEL_185;
          *(_DWORD *)(a1[9] + v22) = v49;
          v44 = *((_DWORD *)v21 - 8);
          v22 += 4;
          v49 = 0;
        }
        v23 += 4 * v42;
        v36 = v41 + v44 - 1;
        v34 = v49;
        break;
    }
    v21 = (_QWORD *)*v21;
    v30 = v37;
  }
  while ( v21 != (_QWORD *)(a1[39] + 16 * v10) );
  if ( v34 )
  {
    v24 = *((_DWORD *)a1 + 20);
    if ( v24 - 4 < v22 )
      goto LABEL_185;
    *(_DWORD *)(a1[9] + v22) = v34;
    if ( (v31 & 1) == 0 )
    {
      v22 += 4;
      goto LABEL_25;
    }
  }
  else if ( (v31 & 1) == 0 )
  {
    goto LABEL_25;
  }
  dev_err(a1[2], "DCC: Programming error: Loop unterminated\n");
LABEL_186:
  v91 = *((_DWORD *)a1 + 26);
  if ( v91 == 1 )
  {
    v14 = v13 | 0x2C;
  }
  else if ( !v91 )
  {
    v14 = v13 | 0x1C;
  }
  *(_DWORD *)(*a1 + v14) = 0;
  dev_info(a1[2], "DCC ram programming failed\n");
  v9 = -22;
LABEL_180:
  mutex_unlock(a1 + 3);
  _ReadStatusReg(SP_EL0);
  return v9;
}
