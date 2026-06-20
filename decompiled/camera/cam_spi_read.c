__int64 __fastcall cam_spi_read(__int64 a1, int a2, int *a3, int a4, unsigned int a5)
{
  _QWORD *v6; // x27
  _QWORD *v7; // x26
  __int64 v8; // x19
  unsigned int v9; // w28
  unsigned __int64 v10; // x24
  _BYTE *v11; // x22
  __int64 v12; // x2
  const void *v13; // x25
  int v14; // w7
  __int64 result; // x0
  unsigned int v16; // w0
  int v17; // w7
  int *v18; // x8
  int v19; // w9
  int v20; // w10
  __int64 v21; // x2
  unsigned __int64 StatusReg; // x21
  __int64 v23; // x23
  unsigned int v24; // [xsp+24h] [xbp-1BCh]
  __int64 v26; // [xsp+38h] [xbp-1A8h]
  _QWORD v28[11]; // [xsp+48h] [xbp-198h] BYREF
  _QWORD v29[5]; // [xsp+A0h] [xbp-140h] BYREF
  unsigned int v30; // [xsp+C8h] [xbp-118h]
  int v31; // [xsp+CCh] [xbp-114h]
  __int64 v32; // [xsp+D0h] [xbp-110h]
  __int64 v33; // [xsp+D8h] [xbp-108h]
  __int64 v34; // [xsp+E0h] [xbp-100h]
  __int64 v35; // [xsp+E8h] [xbp-F8h]
  __int64 v36; // [xsp+F0h] [xbp-F0h]
  __int64 v37; // [xsp+F8h] [xbp-E8h]
  __int64 v38; // [xsp+100h] [xbp-E0h]
  __int64 v39; // [xsp+108h] [xbp-D8h]
  __int64 v40; // [xsp+110h] [xbp-D0h]
  __int64 v41; // [xsp+118h] [xbp-C8h]
  __int64 v42; // [xsp+120h] [xbp-C0h]
  _QWORD v43[3]; // [xsp+128h] [xbp-B8h] BYREF
  _QWORD v44[2]; // [xsp+140h] [xbp-A0h] BYREF
  int v45; // [xsp+150h] [xbp-90h]
  int v46; // [xsp+154h] [xbp-8Ch]
  __int64 v47; // [xsp+158h] [xbp-88h]
  __int64 v48; // [xsp+160h] [xbp-80h]
  __int64 v49; // [xsp+168h] [xbp-78h]
  __int64 v50; // [xsp+170h] [xbp-70h]
  __int64 v51; // [xsp+178h] [xbp-68h]
  __int64 v52; // [xsp+180h] [xbp-60h]
  __int64 v53; // [xsp+188h] [xbp-58h]
  __int64 v54; // [xsp+190h] [xbp-50h]
  __int64 v55; // [xsp+198h] [xbp-48h]
  __int64 v56; // [xsp+1A0h] [xbp-40h]
  __int64 v57; // [xsp+1A8h] [xbp-38h]
  _QWORD v58[3]; // [xsp+1B0h] [xbp-30h] BYREF
  int dest; // [xsp+1C8h] [xbp-18h] BYREF
  char v60; // [xsp+1CCh] [xbp-14h]
  __int64 v61; // [xsp+1D0h] [xbp-10h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 0;
  dest = 0;
  if ( (unsigned int)(a4 - 5) < 0xFFFFFFFC || a5 - 5 <= 0xFFFFFFFB )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_read",
      255,
      "Failed with addr/data_type verification");
    result = 4294967274LL;
    goto LABEL_55;
  }
  LODWORD(v6) = a4;
  LODWORD(v7) = a2;
  v8 = *(_QWORD *)(a1 + 24);
  LOBYTE(v9) = *(_BYTE *)(v8 + 48);
  v26 = *(_QWORD *)v8;
  v10 = *(unsigned __int8 *)(v8 + 9) + (unsigned int)*(unsigned __int8 *)(v8 + 10) + 1;
  v11 = (_BYTE *)_kmalloc_noprof(v10, 3521);
  if ( !v11 )
  {
LABEL_52:
    LODWORD(v8) = -12;
LABEL_53:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_read",
      263,
      "failed %d",
      v8);
LABEL_54:
    result = (unsigned int)v8;
    goto LABEL_55;
  }
  while ( 1 )
  {
    v13 = (const void *)_kmalloc_noprof(a5, 3521);
    if ( !v13 )
    {
      kfree(v11);
      goto LABEL_52;
    }
    v14 = *(unsigned __int8 *)(v8 + 8);
    *v11 = v14;
    if ( *(_BYTE *)(v8 + 9) )
    {
      switch ( (_DWORD)v6 )
      {
        case 3:
          if ( v10 == 1 || (v11[1] = BYTE2(v7), v10 == 2) || (v11[2] = BYTE1(v7), v10 < 4) )
          {
LABEL_48:
            __break(1u);
            goto LABEL_49;
          }
          v11[3] = (_BYTE)v7;
          break;
        case 2:
          if ( v10 == 1 )
            goto LABEL_48;
          v11[1] = BYTE1(v7);
          if ( v10 == 2 )
            goto LABEL_48;
          v11[2] = (_BYTE)v7;
          break;
        case 1:
          if ( v10 == 1 )
            goto LABEL_48;
          v11[1] = (_BYTE)v7;
          break;
        default:
          if ( v10 == 1 )
            goto LABEL_48;
          v11[1] = BYTE3(v7);
          if ( v10 == 2 )
            goto LABEL_48;
          v11[2] = BYTE2(v7);
          if ( v10 < 4 )
            goto LABEL_48;
          v11[3] = BYTE1(v7);
          if ( v10 == 4 )
            goto LABEL_48;
          v11[4] = (_BYTE)v7;
          break;
      }
    }
    v24 = (unsigned int)v7;
    if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
    {
      if ( v10 < 4 )
        goto LABEL_48;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000000000LL,
        4,
        "cam_spi_tx_read",
        223,
        "tx(%u): %02x %02x %02x %02x",
        v10,
        v14,
        (unsigned __int8)v11[1],
        (unsigned __int8)v11[2],
        (unsigned __int8)v11[3]);
    }
    v6 = v44;
    v7 = v28;
    while ( 1 )
    {
      v58[2] = 0;
      v57 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v51 = 0;
      v52 = 0;
      v49 = 0;
      v50 = 0;
      v47 = 0;
      v48 = 0;
      v44[1] = 0;
      v46 = 0;
      v29[3] = 0;
      v32 = 0;
      v33 = 0;
      v34 = 0;
      v35 = 0;
      v36 = 0;
      v37 = 0;
      v38 = 0;
      v39 = 0;
      v40 = 0;
      v41 = 0;
      v42 = 0;
      v43[2] = 0;
      v44[0] = v11;
      v29[4] = v13;
      v31 = 0;
      v45 = v10;
      v30 = a5;
      v29[2] = 0;
      memset(&v28[2], 0, 72);
      v29[0] = v29;
      v29[1] = v29;
      v58[1] = v28;
      v28[0] = v58;
      v28[1] = v43;
      v43[0] = v28;
      v43[1] = v58;
      v58[0] = v43;
      v16 = spi_sync(v26, v28);
      if ( !v16 )
        break;
      v9 = (unsigned __int8)v9 + 255;
      if ( !(v9 >> 8) )
        break;
      msleep(*(unsigned __int8 *)(*(_QWORD *)(a1 + 24) + 47LL));
    }
    v8 = v16;
    if ( (v16 & 0x80000000) != 0 )
      break;
    v12 = a5;
    if ( a5 < 6 )
    {
      memcpy(&dest, v13, a5);
      goto LABEL_34;
    }
LABEL_49:
    _fortify_panic(17, 5, v12);
    _fortify_panic(16, 5, v21);
    StatusReg = _ReadStatusReg(SP_EL0);
    v23 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_spi_tx_read__alloc_tag;
    v11 = (_BYTE *)_kmalloc_noprof(v10, 3521);
    *(_QWORD *)(StatusReg + 80) = v23;
    if ( !v11 )
      goto LABEL_52;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "cam_spi_tx_read",
    230,
    "failed %d",
    v16);
LABEL_34:
  kfree(v11);
  kfree(v13);
  if ( (v8 & 0x80000000) != 0 )
    goto LABEL_53;
  v17 = (unsigned __int8)dest;
  result = (unsigned int)v8;
  if ( a5 == 1 )
  {
    v18 = a3;
  }
  else
  {
    v18 = a3;
    if ( a5 == 3 )
    {
      v19 = ((unsigned __int8)dest << 16) | (BYTE1(dest) << 8);
      v20 = BYTE2(dest);
    }
    else
    {
      if ( a5 == 2 )
      {
        v17 = BYTE1(dest) | ((unsigned __int8)dest << 8);
        goto LABEL_43;
      }
      v19 = ((unsigned __int8)dest << 24) | (BYTE1(dest) << 16) | (BYTE2(dest) << 8);
      v20 = HIBYTE(dest);
    }
    v17 = v19 | v20;
  }
LABEL_43:
  *v18 = v17;
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_spi_read",
      277,
      "addr 0x%x, data %u",
      v24);
    goto LABEL_54;
  }
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
