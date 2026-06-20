__int64 __fastcall aw882xx_dev_parse_check_acf(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w20
  __int64 v6; // x2
  __int64 v7; // x22
  __int64 v8; // x8
  void *v9; // x0
  const char *v10; // x1
  __int64 v11; // x22
  int v12; // w23
  __int64 v13; // x24
  int v14; // w23
  __int64 v15; // x24
  __int64 v16; // x10
  unsigned int v17; // w21
  _DWORD *v18; // x26
  __int64 v19; // x8
  const char *v20; // x20
  int v21; // w10
  int v22; // w9
  signed int v23; // w8
  int v24; // w11
  __int64 v25; // x12
  int v26; // w10
  int v27; // w9
  signed int v28; // w8
  int v29; // w12
  __int64 v30; // x13
  __int64 v31; // x9
  unsigned int v32; // w21
  _DWORD *v33; // x25
  __int64 v34; // x8

  if ( !a1 )
  {
    printk(&unk_28170, "aw882xx_dev_parse_check_acf", a3);
    return 4294967284LL;
  }
  v4 = *(_DWORD *)a1;
  if ( *(_DWORD *)a1 <= 0x4Fu )
  {
    printk(&unk_287D3, "aw882xx_dev_parse_check_acf", v4);
    return 4294967274LL;
  }
  v6 = *(unsigned int *)(a1 + 68);
  if ( (_DWORD)v6 == 0x1000000 )
  {
    v11 = a1 + 4;
    if ( *(_DWORD *)(a1 + 4) != 169212168 )
    {
      v9 = &unk_25D22;
      v10 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
      goto LABEL_17;
    }
    v8 = *(unsigned int *)(a1 + 64);
    v6 = (unsigned int)(*(_DWORD *)(a1 + 56) + v8);
    if ( (unsigned int)v6 > v4 )
    {
      v9 = &unk_28C61;
      v10 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
      goto LABEL_13;
    }
    v14 = *(_DWORD *)(a1 + 60);
    if ( !v14 )
    {
      if ( (_DWORD)v6 == v4 )
      {
LABEL_39:
        v20 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
        goto LABEL_56;
      }
LABEL_40:
      v9 = &unk_25152;
      v10 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
      goto LABEL_17;
    }
    v15 = v11 + v8;
    if ( v14 == 1 || v14 - 1 < 0 )
    {
      v28 = 0;
    }
    else
    {
      v26 = 0;
      v27 = 0;
      v28 = v14 & 0xFFFFFFFE;
      do
      {
        v29 = v26 + 1;
        v30 = v15 + 96LL * v26;
        v26 += 2;
        LODWORD(v6) = *(_DWORD *)(v30 + 32) + v6;
        v27 += *(_DWORD *)(v15 + 96LL * v29 + 32);
      }
      while ( v28 != v26 );
      v6 = (unsigned int)(v27 + v6);
      if ( v14 == v28 )
      {
LABEL_30:
        if ( (_DWORD)v6 == v4 )
        {
          v17 = 0;
          while ( 1 )
          {
            v18 = (_DWORD *)(v15 + 96LL * (int)v17);
            v19 = (unsigned int)v18[9];
            if ( v18[8] + (int)v19 > v4 )
            {
              v9 = &unk_24ACD;
              v10 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
              v6 = v17;
              goto LABEL_17;
            }
            if ( v18[10] != (unsigned __int8)aw_dev_parse_crc8_check(v11 + v19) )
              break;
            if ( v14 == ++v17 )
              goto LABEL_39;
          }
          printk(&unk_23F16, "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0", v17);
          return 4294967274LL;
        }
        goto LABEL_40;
      }
    }
    do
    {
      v16 = v15 + 96LL * v28++;
      v6 = (unsigned int)(*(_DWORD *)(v16 + 32) + v6);
    }
    while ( v14 != v28 );
    goto LABEL_30;
  }
  if ( (_DWORD)v6 != 1 )
  {
    printk(&unk_259FC, "aw882xx_dev_parse_check_acf", v6);
    return 4294967274LL;
  }
  v7 = a1 + 4;
  if ( *(_DWORD *)(a1 + 4) != 169212168 )
  {
    v9 = &unk_25D22;
    v10 = "aw_dev_parse_check_acf_by_hdr";
    goto LABEL_17;
  }
  v8 = *(unsigned int *)(a1 + 64);
  v6 = (unsigned int)(*(_DWORD *)(a1 + 56) + v8);
  if ( (unsigned int)v6 > v4 )
  {
    v9 = &unk_28C61;
    v10 = "aw_dev_parse_check_acf_by_hdr";
LABEL_13:
    v6 = (unsigned int)v8;
LABEL_17:
    printk(v9, v10, v6);
    return 4294967274LL;
  }
  v12 = *(_DWORD *)(a1 + 60);
  if ( v12 )
  {
    v13 = v7 + v8;
    if ( v12 == 1 || v12 - 1 < 0 )
    {
      v23 = 0;
      goto LABEL_48;
    }
    v21 = 0;
    v22 = 0;
    v23 = v12 & 0xFFFFFFFE;
    do
    {
      v24 = v21 + 1;
      v25 = v21;
      v21 += 2;
      LODWORD(v6) = *(_DWORD *)(v13 + (v25 << 6) + 32) + v6;
      v22 += *(_DWORD *)(v13 + ((__int64)v24 << 6) + 32);
    }
    while ( v23 != v21 );
    while ( 1 )
    {
      v6 = (unsigned int)(v22 + v6);
      if ( v12 == v23 )
        break;
LABEL_48:
      v31 = v23++;
      v22 = *(_DWORD *)(v13 + (v31 << 6) + 32);
    }
    if ( (_DWORD)v6 == v4 )
    {
      v32 = 0;
      while ( 1 )
      {
        v33 = (_DWORD *)(v13 + ((__int64)(int)v32 << 6));
        v34 = (unsigned int)v33[9];
        if ( v33[8] + (int)v34 > v4 )
        {
          v9 = &unk_24ACD;
          v10 = "aw_dev_parse_check_acf_by_hdr";
          v6 = v32;
          goto LABEL_17;
        }
        if ( v33[10] != (unsigned __int8)aw_dev_parse_crc8_check(v7 + v34) )
          break;
        if ( v12 == ++v32 )
          goto LABEL_55;
      }
      printk(&unk_23F16, "aw_dev_parse_check_acf_by_hdr", v32);
      return 4294967274LL;
    }
    goto LABEL_57;
  }
  if ( (_DWORD)v6 != v4 )
  {
LABEL_57:
    v9 = &unk_25152;
    v10 = "aw_dev_parse_check_acf_by_hdr";
    goto LABEL_17;
  }
LABEL_55:
  v20 = "aw_dev_parse_check_acf_by_hdr";
LABEL_56:
  printk(&unk_269AD, v20, a1 + 8);
  printk(&unk_24B15, v20, a1 + 32);
  printk(&unk_273B3, v20, *(unsigned __int8 *)(a1 + 51));
  printk(&unk_25A2A, v20, *(unsigned int *)(a1 + 52));
  return 0;
}
