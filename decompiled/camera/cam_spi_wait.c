__int64 __fastcall cam_spi_wait(__int64 a1, unsigned __int8 *a2, int a3)
{
  unsigned int v6; // w26
  unsigned int v7; // w8
  __int64 v8; // x8
  unsigned int v9; // w0
  unsigned int v10; // w19
  __int64 result; // x0
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_spi_wait",
      351,
      "op 0x%x wait start",
      *a2);
    if ( !a2[4] )
      goto LABEL_19;
  }
  else if ( !a2[4] )
  {
    goto LABEL_19;
  }
  v6 = 0;
  while ( 1 )
  {
    v8 = *(_QWORD *)(a1 + 24);
    v12[0] = 0;
    if ( *(_BYTE *)(v8 + 34) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_spi_read_status_reg",
        322,
        "not implemented yet");
      v10 = -6;
LABEL_14:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_spi_device_busy",
        337,
        "failed to read status reg");
      result = v10;
      goto LABEL_22;
    }
    v9 = cam_spi_tx_helper(a1, (_BYTE *)(v8 + 33), 0, v12, a3, 1u);
    if ( (v9 & 0x80000000) != 0 )
    {
      v10 = v9;
      goto LABEL_14;
    }
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 24) + 49LL) & v12[0]) == 0 )
      break;
    msleep(a2[3]);
    if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x4000000000LL,
        4,
        "cam_spi_wait",
        359,
        "op 0x%x wait",
        *a2);
    v7 = a2[4];
    if ( ++v6 >= v7 )
      goto LABEL_16;
  }
  v7 = a2[4];
LABEL_16:
  if ( v6 > v7 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_wait",
      362,
      "op %x timed out",
      *a2);
    result = 4294967186LL;
    goto LABEL_22;
  }
LABEL_19:
  result = 0;
  if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x4000000000LL,
      4,
      "cam_spi_wait",
      365,
      "op %x finished",
      *a2);
    result = 0;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
