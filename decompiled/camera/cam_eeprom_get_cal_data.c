__int64 __fastcall cam_eeprom_get_cal_data(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  int v5; // w19
  int *v6; // x28
  unsigned __int64 v7; // x23
  int v8; // w25
  __int64 result; // x0
  int cpu_buf; // w0
  size_t v11; // x26
  __int64 v12; // x22
  size_t v13; // x6
  unsigned int v14; // w19
  const char *v15; // x5
  __int64 v16; // x4
  unsigned __int64 v17; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v18[2]; // [xsp+10h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a2 + 32);
  v17 = 0;
  v18[0] = 0;
  v6 = (int *)(a2 + v4 + 56);
  v5 = *v6;
  v7 = *(unsigned int *)(a2 + v4 + 68);
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10000,
      4,
      "cam_eeprom_get_cal_data",
      1110,
      "number of IO configs: %d:",
      *(_DWORD *)(a2 + 36));
    if ( *(_DWORD *)(a2 + 36) )
      goto LABEL_4;
LABEL_29:
    result = 0;
    goto LABEL_30;
  }
  if ( !*(_DWORD *)(a2 + 36) )
    goto LABEL_29;
LABEL_4:
  v8 = 0;
  while ( 1 )
  {
    if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10000,
        4,
        "cam_eeprom_get_cal_data",
        1113,
        "Direction: %d:",
        v6[56]);
    if ( v6[56] == 2 )
      break;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_get_cal_data",
      1157,
      "Invalid direction");
    result = 4294967274LL;
LABEL_6:
    if ( (unsigned int)++v8 >= *(_DWORD *)(a2 + 36) )
      goto LABEL_30;
  }
  cpu_buf = cam_mem_get_cpu_buf(v5, v18, &v17);
  if ( cpu_buf )
  {
    v14 = cpu_buf;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_get_cal_data",
      1119,
      "Fail in get buffer: %d",
      cpu_buf);
    result = v14;
    goto LABEL_30;
  }
  v11 = v17 - v7;
  if ( v17 <= v7 )
  {
    v15 = "Not enough buffer";
    v16 = 1123;
    goto LABEL_27;
  }
  if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 0x10000,
      4,
      "cam_eeprom_get_cal_data",
      1131,
      "buf_addr : %pK, buf_size : %zu\n",
      v18[0]);
    v12 = v18[0];
    if ( !v18[0] )
    {
LABEL_25:
      v15 = "invalid buffer to copy data";
      v16 = 1136;
      goto LABEL_27;
    }
  }
  else
  {
    v12 = v18[0];
    if ( !v18[0] )
      goto LABEL_25;
  }
  v13 = *(unsigned int *)(a1 + 4328);
  if ( v11 >= v13 )
  {
    if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10000,
        4,
        "cam_eeprom_get_cal_data",
        1152,
        "copy the data, len:%d",
        v13);
      v13 = *(unsigned int *)(a1 + 4328);
    }
    memcpy((void *)(v12 + v7), *(const void **)(a1 + 4320), v13);
    cam_mem_put_cpu_buf(v5);
    result = 0;
    goto LABEL_6;
  }
  v15 = "failed to copy, Invalid size";
  v16 = 1145;
LABEL_27:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x10000,
    1,
    "cam_eeprom_get_cal_data",
    v16,
    v15);
  cam_mem_put_cpu_buf(v5);
  result = 4294967274LL;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
