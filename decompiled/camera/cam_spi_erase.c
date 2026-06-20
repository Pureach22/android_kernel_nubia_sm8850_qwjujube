__int64 __fastcall cam_spi_erase(__int64 a1, unsigned int a2, unsigned int a3, int a4)
{
  __int64 v4; // x24
  unsigned int v5; // w26
  unsigned int v6; // w25
  unsigned int v7; // w20
  __int64 v10; // x1
  _BYTE *v11; // x1
  int v12; // t1
  unsigned int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w0
  const char *v17; // x5
  unsigned int v18; // w19
  __int64 v19; // x4

  v4 = *(_QWORD *)(a1 + 24);
  v5 = a4 + a2;
  v6 = *(_DWORD *)(v4 + 52);
  v7 = a2 / v6 * v6;
  if ( v7 >= a4 + a2 )
    return 0;
  while ( 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_erase",
      607,
      "%s: erasing 0x%x size: %d\n",
      "cam_spi_erase",
      v7,
      v6);
    v10 = *(_QWORD *)(a1 + 24);
    v12 = *(unsigned __int8 *)(v10 + 28);
    v11 = (_BYTE *)(v10 + 28);
    if ( v12 )
    {
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 24) + 29LL) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x4000000000LL,
          1,
          "cam_spi_write_enable",
          379,
          "not implemented yet");
        return 4294967274LL;
      }
      v13 = cam_spi_tx_helper(a1, v11, 0, nullptr, a3, 0);
      if ( (v13 & 0x80000000) != 0 )
        break;
    }
    v14 = cam_spi_tx_helper(a1, (_BYTE *)(v4 + 38), v7, nullptr, a3, 0);
    if ( (v14 & 0x80000000) != 0 )
    {
      v17 = "%s: erase failed\n";
      v18 = v14;
      v19 = 614;
LABEL_11:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_spi_erase",
        v19,
        v17,
        "cam_spi_erase");
      return v18;
    }
    v15 = cam_spi_wait(a1, v4 + 38, a3);
    if ( (v15 & 0x80000000) != 0 )
    {
      v17 = "%s: erase timedout\n";
      v18 = v15;
      v19 = 619;
      goto LABEL_11;
    }
    v7 += v6;
    if ( v7 >= v5 )
      return 0;
  }
  v18 = v13;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "cam_spi_write_enable",
    385,
    "write enable failed");
  return v18;
}
