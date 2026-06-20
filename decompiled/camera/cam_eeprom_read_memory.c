__int64 __fastcall cam_eeprom_read_memory(__int64 a1, __int64 *a2)
{
  int v2; // w8
  __int64 v4; // x25
  __int64 v5; // x21
  __int64 v6; // x26
  int v8; // w8
  __int64 result; // x0
  int v10; // w27
  _DWORD *v11; // x22
  int v12; // w8
  int v13; // w8
  int v14; // w8
  int v15; // w8
  int v16; // w8
  unsigned int v17; // w24
  int v18; // w8
  int v19; // w8
  unsigned int v20; // w22
  const char *v21; // x5
  unsigned int v22; // w19
  __int64 v23; // x4
  const char *v24; // x5
  __int64 v25; // x4
  __int64 v26; // [xsp+0h] [xbp-40h] BYREF
  __int64 v27; // [xsp+8h] [xbp-38h]
  __int64 *v28; // [xsp+10h] [xbp-30h] BYREF
  __int64 v29; // [xsp+18h] [xbp-28h]
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_DWORD *)a2 + 2);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = nullptr;
  v26 = 0;
  if ( !v2 )
  {
    result = 0;
    goto LABEL_29;
  }
  v4 = *a2;
  v5 = a2[2];
  v6 = *(_QWORD *)(a1 + 3384);
  v8 = 0;
  result = 0;
  while ( 1 )
  {
    v10 = v8;
    if ( (debug_mdl & 0x10000) != 0 && !debug_priority )
    {
      v20 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10000,
        4,
        "cam_eeprom_read_memory",
        46,
        "slave-addr = 0x%X",
        *(_DWORD *)(v4 + 100LL * v8 + 96));
      result = v20;
    }
    v11 = (_DWORD *)(v4 + 100LL * v10);
    v12 = v11[24];
    if ( v12 )
    {
      *(_WORD *)(v6 + 8) = v12;
      result = cam_eeprom_update_i2c_info(a1, (unsigned __int16 *)(v6 + 8));
      if ( (_DWORD)result )
      {
        v21 = "failed: to update i2c info rc %d";
        v22 = result;
        v23 = 54;
LABEL_27:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x10000,
          1,
          "cam_eeprom_read_memory",
          v23,
          v21,
          v22);
        result = v22;
        goto LABEL_29;
      }
    }
    if ( *v11 )
    {
      HIDWORD(v29) = v11[2];
      v13 = v11[4];
      LODWORD(v29) = 1;
      LODWORD(v30) = v13;
      LODWORD(v26) = v11[1];
      HIDWORD(v26) = v11[3];
      v14 = v11[5];
      v28 = &v26;
      LODWORD(v27) = v14;
      result = camera_io_dev_write(a1 + 3664, &v28);
      if ( (_DWORD)result )
      {
        v21 = "page write failed rc %d";
        v22 = result;
        v23 = 71;
        goto LABEL_27;
      }
    }
    if ( v11[6] )
    {
      HIDWORD(v29) = v11[8];
      v15 = v11[10];
      LODWORD(v29) = 1;
      LODWORD(v30) = v15;
      LODWORD(v26) = v11[7];
      HIDWORD(v26) = v11[9];
      v16 = v11[11];
      v28 = &v26;
      LODWORD(v27) = v16;
      result = camera_io_dev_write(a1 + 3664, &v28);
      if ( (_DWORD)result )
      {
        v21 = "page enable failed rc %d";
        v22 = result;
        v23 = 88;
        goto LABEL_27;
      }
    }
    if ( v11[12] )
    {
      v17 = camera_io_dev_poll(
              a1 + 3664,
              (unsigned int)v11[13],
              (unsigned int)v11[15],
              0,
              (unsigned int)v11[14],
              (unsigned int)v11[16],
              (unsigned int)v11[17]);
      result = 0;
      if ( v17 )
        break;
    }
    if ( v11[18] )
    {
      result = camera_io_dev_read_seq(
                 a1 + 3664,
                 (unsigned int)v11[19],
                 v5,
                 (unsigned int)v11[20],
                 (unsigned int)v11[22]);
      if ( (result & 0x80000000) != 0 )
      {
        v21 = "read failed rc %d";
        v22 = result;
        v23 = 114;
        goto LABEL_27;
      }
      v5 += (unsigned int)v11[18];
    }
    if ( v11[6] )
    {
      HIDWORD(v29) = v11[8];
      v18 = v11[10];
      LODWORD(v29) = 1;
      LODWORD(v30) = v18;
      v26 = (unsigned int)v11[7];
      v19 = v11[11];
      v28 = &v26;
      LODWORD(v27) = v19;
      v17 = camera_io_dev_write(a1 + 3664, &v28);
      result = 0;
      if ( v17 )
      {
        v24 = "page disable failed rc %d";
        v25 = 133;
        goto LABEL_28;
      }
    }
    v8 = v10 + 1;
    if ( (unsigned int)(v10 + 1) >= *((_DWORD *)a2 + 2) )
      goto LABEL_29;
  }
  v24 = "poll failed rc %d";
  v25 = 101;
LABEL_28:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    0x10000,
    1,
    "cam_eeprom_read_memory",
    v25,
    v24,
    v17);
  result = v17;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
