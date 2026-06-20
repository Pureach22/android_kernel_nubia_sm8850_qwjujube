__int64 __fastcall aw9620x_awrw_set(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v6; // x25
  int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x1
  unsigned __int8 v10; // w8
  unsigned __int8 v11; // w9
  int v12; // w11
  unsigned int v13; // w8
  unsigned __int64 v14; // x21
  __int64 v15; // x0
  __int64 v16; // x8
  int v17; // w0
  char v18; // w23
  __int64 v19; // x8
  __int64 v20; // x9
  int v21; // w10
  __int16 v22; // w11
  __int64 v23; // x0
  int v24; // w0
  bool v25; // zf
  unsigned __int8 v27; // w22
  unsigned int v28; // w23
  unsigned int v29; // w24
  size_t v30; // x20
  char v31; // w28
  __int64 v32; // x8
  __int64 v33; // x9
  __int64 v34; // x10
  __int16 v35; // w11
  __int16 v36; // w12
  __int16 v37; // w13
  __int64 v38; // x0
  int v39; // w0
  __int64 v40; // x1
  size_t v41; // x1
  int v42; // w0
  char *v43; // x1
  __int64 v44; // [xsp+10h] [xbp-40h]
  __int64 v45; // [xsp+18h] [xbp-38h] BYREF
  __int64 v46; // [xsp+20h] [xbp-30h] BYREF
  __int64 v47; // [xsp+28h] [xbp-28h] BYREF
  __int64 v48; // [xsp+30h] [xbp-20h]
  __int64 v49; // [xsp+38h] [xbp-18h]
  __int64 v50; // [xsp+40h] [xbp-10h]
  __int64 v51; // [xsp+48h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v45 = 0;
  v46 = 0;
  v7 = sscanf(s, "0x%02x 0x%02x 0x%02x 0x%02x", (char *)&v46 + 4, &v46, (char *)&v45 + 4, &v45);
  v8 = *(_QWORD *)(v6 - 8);
  if ( v7 != 4 )
  {
    dev_printk(&unk_134C0, v8, "[%s:%d] sscanf parse err\n", "aw9620x_awrw_set", 2890);
    goto LABEL_15;
  }
  dev_printk(
    &unk_142BB,
    v8,
    "[%s:%d] aw9620x 0x%02x 0x%02x 0x%02x 0x%02x\n",
    "aw9620x_awrw_set",
    2895,
    HIDWORD(v46),
    v46,
    HIDWORD(v45),
    v45);
  if ( HIDWORD(v46) >= 2 )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(v6 - 8), "[%s:%d] parameter err\n", "aw9620x_awrw_set", 2898);
    goto LABEL_15;
  }
  *(_BYTE *)(v6 + 568) = BYTE4(v46);
  v9 = *(_QWORD *)(v6 + 576);
  v10 = v46;
  *(_BYTE *)(v6 + 569) = v46;
  v11 = BYTE4(v45);
  *(_BYTE *)(v6 + 570) = BYTE4(v45);
  v12 = (unsigned __int8)v45;
  *(_BYTE *)(v6 + 571) = v45;
  v13 = v12 * v11 + v10;
  *(_DWORD *)(v6 + 572) = v13;
  if ( v9 )
  {
    devm_kfree(*(_QWORD *)(v6 - 8), v9);
    v13 = *(_DWORD *)(v6 + 572);
    *(_QWORD *)(v6 + 576) = 0;
  }
  v14 = v13;
  v15 = devm_kmalloc(*(_QWORD *)(v6 - 8), v13, 3520);
  *(_QWORD *)(v6 + 576) = v15;
  if ( !v15 )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(v6 - 8), "[%s:%d] devm_kzalloc error\n", "aw9620x_awrw_set", 2921);
    goto LABEL_15;
  }
  v16 = v15;
  v17 = v6 - 56;
  if ( *(_BYTE *)(v6 + 568) != 1 )
  {
    if ( !*(_BYTE *)(v6 + 568) )
    {
      if ( (unsigned int)aw9620x_awrw_data_analysis(v17, s) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(v6 - 8), "[%s:%d] awrw_write error\n", "aw9620x_awrw_set", 2928);
LABEL_36:
        v40 = *(_QWORD *)(v6 + 576);
        if ( !v40 )
          goto LABEL_15;
      }
      else
      {
        v18 = 5;
        while ( 1 )
        {
          v19 = *(_QWORD *)(v6 - 16);
          v20 = *(_QWORD *)(v6 + 576);
          v21 = *(_DWORD *)(v6 + 572);
          v47 = 0;
          v22 = *(_WORD *)(v19 + 2);
          v23 = *(_QWORD *)(v19 + 24);
          v48 = v20;
          WORD2(v47) = v21;
          LOWORD(v47) = v22;
          v24 = i2c_transfer(v23, &v47, 1);
          if ( (v24 & 0x80000000) == 0 )
            break;
          dev_printk(
            &unk_134C0,
            *(_QWORD *)(v6 - 8),
            "[%s:%d] aw9620x i2c write seq error %d\n",
            "i2c_write_seq",
            650,
            v24);
          usleep_range_state(2000, 3000, 2);
          v25 = v18-- == 0;
          if ( v25 )
            goto LABEL_35;
        }
        if ( v18 < 0 )
        {
LABEL_35:
          dev_printk(&unk_134C0, *(_QWORD *)(v6 - 8), "[%s:%d] i2c write error!\n", "i2c_write_seq", 657);
          goto LABEL_36;
        }
        v40 = *(_QWORD *)(v6 + 576);
        if ( !v40 )
          goto LABEL_15;
      }
      devm_kfree(*(_QWORD *)(v6 - 8), v40);
      *(_QWORD *)(v6 + 576) = 0;
    }
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return a4;
  }
  v27 = *(_BYTE *)(v6 + 569);
  v28 = *(unsigned __int8 *)(v6 + 570);
  v29 = *(unsigned __int8 *)(v6 + 571);
  v44 = v16;
  if ( (unsigned int)aw9620x_awrw_data_analysis(v17, s) )
  {
LABEL_31:
    dev_printk(&unk_134C0, *(_QWORD *)(v6 - 8), "[%s:%d] awrw_read error\n", "aw9620x_awrw_set", 2937);
    goto LABEL_15;
  }
  v30 = v29 * (unsigned __int64)v28;
  v31 = 5;
  while ( 1 )
  {
    v32 = *(_QWORD *)(v6 - 16);
    v33 = *(_QWORD *)(v6 + 576);
    v34 = *(unsigned __int8 *)(v6 + 569);
    v35 = *(unsigned __int8 *)(v6 + 570);
    v36 = *(unsigned __int8 *)(v6 + 571);
    v48 = 0;
    v49 = 0;
    v47 = 0;
    v37 = *(_WORD *)(v32 + 2);
    v48 = v33;
    WORD2(v47) = v34;
    v50 = v33 + v34;
    v38 = *(_QWORD *)(v32 + 24);
    LOWORD(v47) = v37;
    LOWORD(v49) = v37;
    WORD1(v49) = 1;
    HIDWORD(v49) = (unsigned __int16)(v36 * v35);
    v39 = i2c_transfer(v38, &v47, 2);
    if ( (v39 & 0x80000000) == 0 )
      break;
    dev_printk(&unk_134C0, *(_QWORD *)(v6 - 8), "[%s:%d] aw9620x i2c write error %d\n", "i2c_read_seq", 676, v39);
    usleep_range_state(2000, 3000, 2);
    v25 = v31-- == 0;
    if ( v25 )
      goto LABEL_26;
  }
  if ( (v31 & 0x80) == 0 )
    goto LABEL_15;
LABEL_26:
  dev_printk(&unk_134C0, *(_QWORD *)(v6 - 8), "[%s:%d] i2c write error!\n", "i2c_read_seq", 683);
  if ( v14 >= v27 )
    v41 = v14 - v27;
  else
    v41 = 0;
  if ( v41 >= v30 )
  {
    memset((void *)(v44 + v27), 255, v30);
    goto LABEL_31;
  }
  v42 = _fortify_panic(15);
  return aw9620x_awrw_data_analysis(v42, v43);
}
