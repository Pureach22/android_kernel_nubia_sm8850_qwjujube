__int64 __fastcall cam_qup_i2c_read(__int64 a1, unsigned int a2, int *a3, unsigned int a4, unsigned int a5)
{
  unsigned __int64 v10; // x21
  unsigned __int8 *v11; // x20
  __int64 v12; // x0
  int v14; // w0
  int v15; // w7
  unsigned int v16; // w22
  unsigned __int64 StatusReg; // x26
  __int64 v18; // x27

  if ( a4 - 5 < 0xFFFFFFFC || a5 - 5 <= 0xFFFFFFFB )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_read",
      108,
      "Failed with addr/data_type verification");
    return 4294967274LL;
  }
  v10 = a5 + a4;
  v11 = (unsigned __int8 *)_kmalloc_noprof(v10, 3520);
  if ( !v11 )
    return 4294967284LL;
  while ( 1 )
  {
    if ( a4 == 3 )
    {
      if ( !v10 )
        goto LABEL_39;
      *v11 = BYTE2(a2);
      if ( v10 == 1 )
        goto LABEL_39;
      v11[1] = BYTE1(a2);
      if ( v10 == 2 )
        goto LABEL_39;
      v12 = a1;
      v11[2] = a2;
    }
    else
    {
      v12 = a1;
      if ( a4 == 2 )
      {
        if ( !v10 )
          goto LABEL_39;
        *v11 = BYTE1(a2);
        if ( v10 == 1 )
          goto LABEL_39;
        v11[1] = a2;
      }
      else if ( a4 == 1 )
      {
        if ( !v10 )
          goto LABEL_39;
        *v11 = a2;
      }
      else
      {
        if ( !v10 )
          goto LABEL_39;
        *v11 = HIBYTE(a2);
        if ( v10 == 1 )
          goto LABEL_39;
        v11[1] = BYTE2(a2);
        if ( v10 == 2 )
          goto LABEL_39;
        v11[2] = BYTE1(a2);
        if ( v10 < 4 )
          goto LABEL_39;
        v11[3] = a2;
      }
    }
    v14 = cam_qup_i2c_rxdata(v12, v11, a4, a5);
    if ( v14 < 0 )
    {
      v16 = v14;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_qup_i2c_read",
        135,
        "failed rc: %d",
        v14);
      goto LABEL_38;
    }
    if ( a5 != 3 )
      break;
    if ( v10 != 1 && v10 != 2 )
    {
      v16 = v14;
      v15 = (*v11 << 16) | (v11[1] << 8) | v11[2];
      goto LABEL_35;
    }
LABEL_39:
    __break(1u);
    v10 = a5 + a4;
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_qup_i2c_read__alloc_tag;
    v11 = (unsigned __int8 *)_kmalloc_noprof(v10, 3520);
    *(_QWORD *)(StatusReg + 80) = v18;
    if ( !v11 )
      return 4294967284LL;
  }
  if ( a5 == 2 )
  {
    if ( v10 != 1 )
    {
      v16 = v14;
      v15 = __rev16(*(unsigned __int16 *)v11);
      goto LABEL_35;
    }
    goto LABEL_39;
  }
  if ( a5 == 1 )
  {
    v15 = *v11;
    v16 = v14;
    goto LABEL_35;
  }
  if ( v10 < 4 )
    goto LABEL_39;
  v16 = v14;
  v15 = bswap32(*(_DWORD *)v11);
LABEL_35:
  *a3 = v15;
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_qup_i2c_read",
      149,
      "addr = 0x%x data: 0x%x",
      a2);
LABEL_38:
  kfree(v11);
  return v16;
}
