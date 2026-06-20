__int64 __fastcall cam_spi_page_program(
        __int64 a1,
        unsigned int a2,
        const void *a3,
        unsigned int a4,
        unsigned __int16 a5,
        unsigned __int8 *s)
{
  unsigned int v9; // w25
  __int64 *v10; // x27
  char v11; // w28
  char v12; // w22
  char v13; // w26
  __int64 *v14; // x9
  __int64 result; // x0
  const void *v16; // x25
  unsigned int v17; // w0
  unsigned __int8 v18; // w8
  const void *v19; // x22
  __int64 v20; // x26
  unsigned int v21; // w19
  int v22; // w0
  unsigned int v23; // w19
  const void *v24; // x24
  unsigned int v25; // [xsp+24h] [xbp-11Ch]
  __int64 v27; // [xsp+30h] [xbp-110h]
  _QWORD v28[3]; // [xsp+A8h] [xbp-98h] BYREF
  _QWORD v29[11]; // [xsp+C0h] [xbp-80h] BYREF
  _QWORD v30[5]; // [xsp+118h] [xbp-28h] BYREF

  v9 = a2;
  v30[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 24);
  v11 = *((_BYTE *)v10 + 48);
  v12 = *((_BYTE *)v10 + 24);
  v13 = *((_BYTE *)v10 + 25);
  v27 = *v10;
  v14 = v10;
  if ( (debug_mdl & 0x4000000000LL) != 0 )
  {
    v14 = *(__int64 **)(a1 + 24);
    if ( !debug_priority )
    {
      v24 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000000000LL,
        4,
        "cam_spi_page_program",
        414,
        "addr 0x%x, size 0x%x",
        a2,
        a5);
      v14 = *(__int64 **)(a1 + 24);
      a3 = v24;
    }
  }
  if ( *((_BYTE *)v14 + 28) )
  {
    if ( *((_BYTE *)v14 + 29) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_spi_write_enable",
        379,
        "not implemented yet");
      result = 4294967274LL;
      goto LABEL_25;
    }
    v25 = v9;
    v16 = a3;
    v17 = cam_spi_tx_helper(a1, (_BYTE *)v14 + 28, 0, nullptr, a4, 0);
    a3 = v16;
    v9 = v25;
    if ( (v17 & 0x80000000) != 0 )
    {
      v21 = v17;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_spi_write_enable",
        385,
        "write enable failed");
      result = v21;
      goto LABEL_25;
    }
  }
  v18 = v12 + v13 + 1;
  v19 = a3;
  v20 = v18;
  memset(s, 0, v18);
  *s = *((_BYTE *)v10 + 23);
  if ( *((_BYTE *)v10 + 24) )
  {
    switch ( a4 )
    {
      case 3u:
        s[3] = v9;
        s[1] = BYTE2(v9);
        s[2] = BYTE1(v9);
        break;
      case 2u:
        *(_WORD *)(s + 1) = bswap32(v9) >> 16;
        break;
      case 1u:
        s[1] = v9;
        break;
      default:
        *(_DWORD *)(s + 1) = bswap32(v9);
        break;
    }
  }
  memcpy(&s[v20], v19, a5);
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_spi_page_program",
      423,
      "tx(%u): %02x %02x %02x %02x",
      a5,
      *s,
      s[1],
      s[2],
      s[3]);
  while ( 1 )
  {
    v28[2] = 0;
    v30[2] = 0;
    memset(&v29[2], 0, 72);
    v30[0] = v30;
    v30[1] = v30;
    v29[1] = v28;
    v28[0] = v29;
    v28[1] = v29;
    v29[0] = v28;
    v22 = spi_sync(v27, v29);
    if ( !v22 )
      goto LABEL_24;
    if ( !v11 )
      break;
    --v11;
    cam_spi_wait(a1, (char *)v10 + 23, a4);
    msleep(*(unsigned __int8 *)(*(_QWORD *)(a1 + 24) + 47LL));
  }
  if ( (v22 & 0x80000000) == 0 )
  {
LABEL_24:
    result = cam_spi_wait(a1, (char *)v10 + 23, a4);
    goto LABEL_25;
  }
  v23 = v22;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "cam_spi_page_program",
    438,
    "failed %d",
    v22);
  result = v23;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
