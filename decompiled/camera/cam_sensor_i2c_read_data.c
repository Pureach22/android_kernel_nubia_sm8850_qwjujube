__int64 __fastcall cam_sensor_i2c_read_data(_QWORD **a1, __int64 a2)
{
  _QWORD *v2; // x25
  unsigned int seq; // w22
  char *v6; // x23
  unsigned int v7; // w7
  int v8; // w8
  __int64 v9; // x4
  unsigned int v10; // w8
  __int64 v11; // x6
  __int64 v12; // x28
  unsigned __int64 v13; // x27
  __int64 v14; // x8
  const void *v15; // x24
  unsigned int v16; // w22
  int v17; // w0
  __int64 v18; // x3
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  _DWORD *v22; // x8
  unsigned int v23; // w0
  const char *v24; // x5
  __int64 v25; // x4
  const char *v26; // x5
  __int64 v27; // x4
  _QWORD v29[2]; // [xsp+10h] [xbp-40h] BYREF
  int v30; // [xsp+20h] [xbp-30h]
  __int64 v31; // [xsp+24h] [xbp-2Ch]
  __int64 v32; // [xsp+2Ch] [xbp-24h]
  int v33; // [xsp+34h] [xbp-1Ch]
  _QWORD v34[3]; // [xsp+38h] [xbp-18h] BYREF

  v34[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  if ( *a1 == a1 )
  {
    seq = 0;
    goto LABEL_30;
  }
  seq = 0;
  while ( 1 )
  {
    v6 = (char *)*(v2 - 6);
    v7 = *((_DWORD *)v2 - 10);
    if ( !v6 || !v7 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_i2c_read_data",
        1045,
        "Invalid input buffer, buffer: %pK, length: %d",
        (const void *)*(v2 - 6),
        v7);
      goto LABEL_29;
    }
    v8 = *((_DWORD *)v2 - 2);
    if ( v8 == 4 )
    {
      v16 = *((_DWORD *)v2 - 16);
      if ( v16 > v7 )
      {
        v26 = "Invalid buffer size, readLen: %d, bufLen: %d";
        v27 = 1090;
        v11 = v16;
        goto LABEL_28;
      }
      v17 = strncmp((const char *)(a2 + 32), "ov64b40", 7u);
      v22 = (_DWORD *)*(v2 - 9);
      if ( !v17 && *v22 == 19731 )
      {
        v31 = 0;
        v34[0] = 0x100004D12LL;
        v34[1] = 0;
        v29[0] = v34;
        v32 = 0;
        v29[1] = 0x200000001LL;
        v30 = 1;
        v33 = 0;
        v23 = camera_io_dev_write_continuous((int *)a2, v29, 2, v18, v19, v20, v21);
        if ( (v23 & 0x80000000) != 0 )
        {
          seq = v23;
          v24 = "Failed to write sensor temperature I2C settings: %d";
          v25 = 1099;
          goto LABEL_24;
        }
        v22 = (_DWORD *)*(v2 - 9);
        v16 = *((_DWORD *)v2 - 16);
      }
      seq = camera_io_dev_read_seq(
              a2,
              (unsigned int)*v22,
              (__int64)v6,
              *((unsigned int *)v2 - 15),
              *((unsigned int *)v2 - 14),
              v16);
      if ( (seq & 0x80000000) == 0 )
        goto LABEL_4;
      v24 = "failed: seq read I2C settings: %d";
      v25 = 1113;
LABEL_24:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        0x800000000LL,
        1,
        "cam_sensor_i2c_read_data",
        v25,
        v24,
        seq);
      goto LABEL_30;
    }
    if ( v8 != 3 )
      goto LABEL_4;
    v9 = *((unsigned int *)v2 - 14);
    v10 = *((_DWORD *)v2 - 16);
    v11 = v10 * (unsigned int)v9;
    if ( (unsigned int)v11 > v7 || (unsigned int)v11 < v10 )
      break;
    if ( v10 )
    {
      v12 = 0;
      v13 = 0;
      while ( 1 )
      {
        v14 = *(v2 - 9);
        v15 = (const void *)(v14 + v12 + 4);
        seq = camera_io_dev_read(a2, *(unsigned int *)(v14 + v12), (__int64)v15, *((unsigned int *)v2 - 15), v9, 0);
        if ( (seq & 0x80000000) != 0 )
          break;
        v9 = *((unsigned int *)v2 - 14);
        if ( (unsigned int)v9 <= 4 )
        {
          memcpy(v6, v15, *((unsigned int *)v2 - 14));
          v9 = *((unsigned int *)v2 - 14);
          v6 += v9;
        }
        ++v13;
        v12 += 16;
        if ( v13 >= *((unsigned int *)v2 - 16) )
          goto LABEL_4;
      }
      v24 = "Failed: random read I2C settings: %d";
      v25 = 1073;
      goto LABEL_24;
    }
LABEL_4:
    v2 = (_QWORD *)*v2;
    if ( v2 == a1 )
      goto LABEL_30;
  }
  v26 = "Invalid size, readLen:%d, bufLen:%d, size: %d";
  v27 = 1057;
LABEL_28:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    0x800000000LL,
    1,
    "cam_sensor_i2c_read_data",
    v27,
    v26,
    v11);
LABEL_29:
  seq = -22;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return seq;
}
