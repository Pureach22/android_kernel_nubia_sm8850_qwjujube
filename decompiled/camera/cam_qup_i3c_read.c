__int64 __fastcall cam_qup_i3c_read(__int64 a1, unsigned int a2, int *a3, unsigned int a4, unsigned int a5)
{
  unsigned int v6; // w23
  unsigned __int64 v10; // x21
  unsigned __int8 *v11; // x20
  __int64 v12; // x0
  int v13; // w7
  unsigned __int64 StatusReg; // x26
  __int64 v15; // x27

  if ( a4 - 5 < 0xFFFFFFFC || a5 - 5 <= 0xFFFFFFFB )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_read",
      108,
      "Failed with addr/data_type verification");
    return (unsigned int)-22;
  }
  v6 = a4;
  v10 = a5 + a4;
  v11 = (unsigned __int8 *)_kmalloc_noprof(v10, 3521);
  if ( !v11 )
    return (unsigned int)-12;
  while ( 1 )
  {
    if ( v6 == 3 )
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
      if ( v6 == 2 )
      {
        if ( !v10 )
          goto LABEL_39;
        *v11 = BYTE1(a2);
        if ( v10 == 1 )
          goto LABEL_39;
        v11[1] = a2;
      }
      else if ( v6 == 1 )
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
    v6 = cam_qup_i3c_rxdata(v12, v11, v6, a5);
    if ( v6 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_qup_i3c_read",
        134,
        "failed rc: %d",
        v6);
      goto LABEL_38;
    }
    if ( a5 != 3 )
      break;
    if ( v10 != 1 && v10 != 2 )
    {
      v13 = (*v11 << 16) | (v11[1] << 8) | v11[2];
      goto LABEL_35;
    }
LABEL_39:
    __break(1u);
    v10 = a5 + v6;
    StatusReg = _ReadStatusReg(SP_EL0);
    v15 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_qup_i3c_read__alloc_tag;
    v11 = (unsigned __int8 *)_kmalloc_noprof(v10, 3521);
    *(_QWORD *)(StatusReg + 80) = v15;
    if ( !v11 )
      return (unsigned int)-12;
  }
  if ( a5 == 2 )
  {
    if ( v10 != 1 )
    {
      v13 = __rev16(*(unsigned __int16 *)v11);
      goto LABEL_35;
    }
    goto LABEL_39;
  }
  if ( a5 == 1 )
  {
    v13 = *v11;
    goto LABEL_35;
  }
  if ( v10 < 4 )
    goto LABEL_39;
  v13 = bswap32(*(_DWORD *)v11);
LABEL_35:
  *a3 = v13;
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_qup_i3c_read",
      147,
      "addr = 0x%x data: 0x%x",
      a2);
LABEL_38:
  kfree(v11);
  return v6;
}
