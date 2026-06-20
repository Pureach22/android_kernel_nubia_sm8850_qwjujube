__int64 __fastcall cam_qup_i2c_read_seq(__int64 a1, int a2, __int64 a3, int a4, int a5)
{
  unsigned int v6; // w21
  unsigned __int64 v10; // x20
  int v11; // w25
  int v12; // w3
  _BYTE *v13; // x19
  __int64 v14; // x0
  int v15; // w0
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x11
  _BYTE *v22; // x10
  unsigned __int64 v23; // x12
  __int16 v24; // w13
  unsigned __int64 StatusReg; // x26
  __int64 v26; // x27

  if ( (unsigned int)(a4 - 5) <= 0xFFFFFFFB )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_read_seq",
      167,
      "Failed with addr_type verification");
    return 4294967282LL;
  }
  v6 = a5;
  if ( (unsigned int)(a5 - 20481) <= 0xFFFFAFFF )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_read_seq",
      173,
      "num_byte:0x%x max supported:0x%x",
      a5,
      20480);
    return 4294967282LL;
  }
  v10 = (unsigned int)(a5 + a4);
  v11 = a4;
  v13 = (_BYTE *)_kmalloc_noprof(v10, 3520);
  if ( !v13 )
    return 4294967284LL;
  while ( v11 == 3 )
  {
    if ( v10 )
    {
      *v13 = BYTE2(a2);
      if ( v10 != 1 )
      {
        v13[1] = BYTE1(a2);
        if ( v10 != 2 )
        {
          v14 = a1;
          v13[2] = a2;
          goto LABEL_23;
        }
      }
    }
LABEL_37:
    __break(1u);
    v10 = v6 + v12;
    StatusReg = _ReadStatusReg(SP_EL0);
    v26 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_qup_i2c_read_seq__alloc_tag;
    v11 = v12;
    v13 = (_BYTE *)_kmalloc_noprof(v10, 3520);
    *(_QWORD *)(StatusReg + 80) = v26;
    if ( !v13 )
      return 4294967284LL;
  }
  v14 = a1;
  if ( v11 == 2 )
  {
    if ( v10 )
    {
      *v13 = BYTE1(a2);
      if ( v10 != 1 )
      {
        v13[1] = a2;
        goto LABEL_23;
      }
    }
    goto LABEL_37;
  }
  if ( v11 == 1 )
  {
    if ( v10 )
    {
      *v13 = a2;
      goto LABEL_23;
    }
    goto LABEL_37;
  }
  if ( !v10 )
    goto LABEL_37;
  *v13 = HIBYTE(a2);
  if ( v10 == 1 )
    goto LABEL_37;
  v13[1] = BYTE2(a2);
  if ( v10 == 2 )
    goto LABEL_37;
  v13[2] = BYTE1(a2);
  if ( v10 < 4 )
    goto LABEL_37;
  v13[3] = a2;
LABEL_23:
  v15 = cam_qup_i2c_rxdata(v14, (__int64)v13, v11, v6);
  if ( (v15 & 0x80000000) == 0 )
  {
    v16 = v6;
    v17 = v6 - 1LL;
    if ( v10 < v17 )
      v17 = v10;
    if ( v17 > 1 )
    {
      v19 = v17 + 1;
      v20 = v19 & 1;
      if ( (v19 & 1) == 0 )
        v20 = 2;
      v21 = a3 + 1;
      v18 = v19 - v20;
      v22 = v13 + 1;
      v23 = v18;
      do
      {
        v24 = *(_WORD *)(v22 - 1);
        v23 -= 2LL;
        v22 += 2;
        *(_WORD *)(v21 - 1) = v24;
        v21 += 2;
      }
      while ( v23 );
      v6 = v15;
    }
    else
    {
      v6 = v15;
      v18 = 0;
    }
    while ( v10 > v18 )
    {
      *(_BYTE *)(a3 + v18) = v13[v18];
      if ( v16 == ++v18 )
        goto LABEL_36;
    }
    goto LABEL_37;
  }
  v6 = v15;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "cam_qup_i2c_read_seq",
    199,
    "failed rc: %d",
    v15);
LABEL_36:
  kfree(v13);
  return v6;
}
