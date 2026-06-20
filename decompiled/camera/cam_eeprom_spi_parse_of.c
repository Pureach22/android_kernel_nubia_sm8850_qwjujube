__int64 __fastcall cam_eeprom_spi_parse_of(__int64 *a1)
{
  __int64 v2; // x8
  char v3; // w9
  char v4; // w8
  char v5; // w10
  __int64 v6; // x9
  char v7; // w8
  char v8; // w9
  char v9; // w8
  char v10; // w10
  __int64 v11; // x9
  char v12; // w8
  char v13; // w9
  char v14; // w8
  char v15; // w10
  __int64 v16; // x9
  char v17; // w8
  char v18; // w9
  char v19; // w8
  char v20; // w10
  __int64 v21; // x9
  char v22; // w8
  unsigned int v23; // w0
  char v24; // w9
  char v25; // w8
  char v26; // w10
  __int64 v27; // x9
  char v28; // w8
  unsigned int v29; // w0
  char v30; // w9
  char v31; // w8
  char v32; // w10
  __int64 v33; // x9
  char v34; // w8
  unsigned int v35; // w0
  char v36; // w9
  char v37; // w8
  char v38; // w10
  __int64 v39; // x9
  char v40; // w8
  unsigned int v41; // w0
  char v42; // w9
  __int64 result; // x0
  const char *v44; // x5
  __int64 v45; // x4
  const char *v46; // x5
  unsigned int v47; // w19
  __int64 v48; // x4
  __int64 v49; // [xsp+0h] [xbp-20h] BYREF
  __int64 v50; // [xsp+8h] [xbp-18h]
  int v51; // [xsp+10h] [xbp-10h]
  __int64 v52; // [xsp+18h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v51 = 0;
  v49 = 0;
  v50 = 0;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v2 + 744), "spiop-read", &v49, 5, 0) & 0x80000000) != 0 )
  {
    v44 = "Failed to get read data";
    v45 = 36;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_spi_parse_of",
      v45,
      v44);
    result = 4294967282LL;
    goto LABEL_15;
  }
  v3 = BYTE4(v49);
  *((_BYTE *)a1 + 8) = v49;
  v4 = v50;
  v5 = BYTE4(v50);
  *((_BYTE *)a1 + 9) = v3;
  v6 = *a1;
  *((_BYTE *)a1 + 10) = v4;
  v7 = v51;
  *((_BYTE *)a1 + 11) = v5;
  *((_BYTE *)a1 + 12) = v7;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v6 + 744), "spiop-readseq", &v49, 5, 0) & 0x80000000) != 0 )
  {
    v44 = "Failed to get readseq data";
    v45 = 45;
    goto LABEL_14;
  }
  v8 = BYTE4(v49);
  *((_BYTE *)a1 + 13) = v49;
  v9 = v50;
  v10 = BYTE4(v50);
  *((_BYTE *)a1 + 14) = v8;
  v11 = *a1;
  *((_BYTE *)a1 + 15) = v9;
  v12 = v51;
  *((_BYTE *)a1 + 16) = v10;
  *((_BYTE *)a1 + 17) = v12;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v11 + 744), "spiop-queryid", &v49, 5, 0) & 0x80000000) != 0 )
  {
    v44 = "Failed to get queryid data";
    v45 = 54;
    goto LABEL_14;
  }
  v13 = BYTE4(v49);
  *((_BYTE *)a1 + 18) = v49;
  v14 = v50;
  v15 = BYTE4(v50);
  *((_BYTE *)a1 + 19) = v13;
  v16 = *a1;
  *((_BYTE *)a1 + 20) = v14;
  v17 = v51;
  *((_BYTE *)a1 + 21) = v15;
  *((_BYTE *)a1 + 22) = v17;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v16 + 744), "spiop-pprog", &v49, 5, 0) & 0x80000000) != 0 )
  {
    v44 = "Failed to get page program data";
    v45 = 63;
    goto LABEL_14;
  }
  v18 = BYTE4(v49);
  *((_BYTE *)a1 + 23) = v49;
  v19 = v50;
  v20 = BYTE4(v50);
  *((_BYTE *)a1 + 24) = v18;
  v21 = *a1;
  *((_BYTE *)a1 + 25) = v19;
  v22 = v51;
  *((_BYTE *)a1 + 26) = v20;
  *((_BYTE *)a1 + 27) = v22;
  v23 = of_property_read_variable_u32_array(*(_QWORD *)(v21 + 744), "spiop-wenable", &v49, 5, 0);
  if ( (v23 & 0x80000000) != 0 )
  {
    v46 = "Failed to get write enable data";
    v47 = v23;
    v48 = 72;
LABEL_20:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x10000,
      1,
      "cam_eeprom_spi_parse_of",
      v48,
      v46);
    result = v47;
    goto LABEL_15;
  }
  v24 = BYTE4(v49);
  *((_BYTE *)a1 + 28) = v49;
  v25 = v50;
  v26 = BYTE4(v50);
  *((_BYTE *)a1 + 29) = v24;
  v27 = *a1;
  *((_BYTE *)a1 + 30) = v25;
  v28 = v51;
  *((_BYTE *)a1 + 31) = v26;
  *((_BYTE *)a1 + 32) = v28;
  v29 = of_property_read_variable_u32_array(*(_QWORD *)(v27 + 744), "spiop-readst", &v49, 5, 0);
  if ( (v29 & 0x80000000) != 0 )
  {
    v46 = "Failed to get readdst data";
    v47 = v29;
    v48 = 81;
    goto LABEL_20;
  }
  v30 = BYTE4(v49);
  *((_BYTE *)a1 + 33) = v49;
  v31 = v50;
  v32 = BYTE4(v50);
  *((_BYTE *)a1 + 34) = v30;
  v33 = *a1;
  *((_BYTE *)a1 + 35) = v31;
  v34 = v51;
  *((_BYTE *)a1 + 36) = v32;
  *((_BYTE *)a1 + 37) = v34;
  v35 = of_property_read_variable_u32_array(*(_QWORD *)(v33 + 744), "spiop-erase", &v49, 5, 0);
  if ( (v35 & 0x80000000) != 0 )
  {
    v46 = "Failed to get erase data";
    v47 = v35;
    v48 = 90;
    goto LABEL_20;
  }
  v36 = BYTE4(v49);
  *((_BYTE *)a1 + 38) = v49;
  v37 = v50;
  v38 = BYTE4(v50);
  *((_BYTE *)a1 + 39) = v36;
  v39 = *a1;
  *((_BYTE *)a1 + 40) = v37;
  v40 = v51;
  *((_BYTE *)a1 + 41) = v38;
  *((_BYTE *)a1 + 42) = v40;
  v41 = of_property_read_variable_u32_array(*(_QWORD *)(v39 + 744), "eeprom-id", &v49, 2, 0);
  if ( (v41 & 0x80000000) != 0 )
  {
    v46 = "Failed to get eeprom id";
    v47 = v41;
    v48 = 97;
    goto LABEL_20;
  }
  v42 = BYTE4(v49);
  result = 0;
  *((_BYTE *)a1 + 45) = v49;
  *((_BYTE *)a1 + 43) = v42;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
