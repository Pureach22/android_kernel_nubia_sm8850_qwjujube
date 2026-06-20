__int64 __fastcall aw_parsing_bin_file(__int64 a1)
{
  __int64 v2; // x3
  unsigned int v4; // w20
  __int64 v5; // x3
  int v6; // w0
  __int64 v7; // x3
  int v8; // w8
  unsigned int v9; // w19
  void *v10; // x0
  __int64 v11; // x2
  unsigned __int64 v12; // x20
  _DWORD *v13; // x23
  unsigned int v14; // w0
  __int64 v15; // x0
  int v16; // w8
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int v19; // w0
  __int64 v20; // x3

  printk(&unk_14FD6, "aw_parsing_bin_file", 454, "V0.0.7-V1.0.4");
  if ( !a1 )
  {
    printk(&unk_1377E, "aw_parsing_bin_file", 456, v2);
    return 4294967288LL;
  }
  v4 = *(_DWORD *)(a1 + 8428);
  *(_QWORD *)a1 = a1 + 8424;
  *(_QWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  printk(&unk_143CB, "aw_check_bin_header_version", 435, v4);
  if ( v4 != 0x1000000 )
  {
    printk(&unk_1297C, "aw_check_bin_header_version", 444, v5);
    v6 = -1;
LABEL_8:
    v9 = v6;
    v10 = &unk_13EAE;
    v11 = 467;
LABEL_9:
    printk(v10, "aw_parsing_bin_file", v11, v7);
    return v9;
  }
  v6 = ((__int64 (__fastcall *)(__int64))aw_parse_bin_header_1_0_0)(a1);
  if ( v6 < 0 )
    goto LABEL_8;
  v8 = *(_DWORD *)(a1 + 8);
  *(_QWORD *)a1 = 0;
  if ( v8 )
  {
    v12 = 0;
    v13 = (_DWORD *)(a1 + 40);
    while ( 1 )
    {
      v14 = ((__int64 (__fastcall *)(__int64, _QWORD))aw_check_sum)(a1, (unsigned int)v12);
      if ( (v14 & 0x80000000) != 0 )
      {
        v9 = v14;
        v10 = &unk_13218;
        v11 = 477;
        goto LABEL_9;
      }
      v15 = printk(&unk_12FBC, "aw_check_data_version", 134, v7);
      if ( v12 == 100 )
        break;
      if ( *(v13 - 1) != 1 )
      {
        printk(&unk_135A0, "aw_check_data_version", 140, v7);
        printk(&unk_11BB7, "aw_parsing_bin_file", 483, v20);
        return 4294967292LL;
      }
      v16 = *(v13 - 2);
      if ( v16 == 33 )
      {
        v19 = ((__int64 (__fastcall *)(__int64, _QWORD))aw_check_soc_app_num_v1)(a1, (unsigned int)v12);
        if ( (v19 & 0x80000000) != 0 )
        {
          v9 = v19;
          v10 = &unk_1212C;
          v11 = 512;
          goto LABEL_9;
        }
      }
      else if ( v16 == 16 )
      {
        v18 = ((__int64 (__fastcall *)(__int64, _QWORD))aw_check_dsp_reg_num_v1)(a1, (unsigned int)v12);
        if ( (v18 & 0x80000000) != 0 )
        {
          v9 = v18;
          v10 = &unk_1500D;
          v11 = 503;
          goto LABEL_9;
        }
      }
      else if ( v16 )
      {
        v13[10] = *v13;
      }
      else
      {
        v17 = ((__int64 (__fastcall *)(__int64, _QWORD))aw_check_register_num_v1)(a1, (unsigned int)v12);
        if ( (v17 & 0x80000000) != 0 )
        {
          v9 = v17;
          v10 = &unk_13AFE;
          v11 = 494;
          goto LABEL_9;
        }
      }
      ++v12;
      v13 += 21;
      if ( v12 >= *(unsigned int *)(a1 + 8) )
        goto LABEL_6;
    }
    __break(0x5512u);
    return aw9620x_flash_update(v15);
  }
  else
  {
LABEL_6:
    printk(&unk_145CB, "aw_parsing_bin_file", 521, v7);
    return 0;
  }
}
