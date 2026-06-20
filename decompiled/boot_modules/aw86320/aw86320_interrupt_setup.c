__int64 __fastcall aw86320_interrupt_setup(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x5
  __int64 v4; // x6
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x5
  __int64 v8; // x6
  unsigned int v9; // w0
  unsigned int v10; // w0
  __int64 v11; // x5
  __int64 v12; // x6
  unsigned int v13; // w0
  unsigned int v14; // w0
  __int64 v15; // x5
  __int64 v16; // x6
  unsigned int v17; // w0
  unsigned int v18; // w0
  __int64 v19; // x5
  __int64 v20; // x6
  unsigned int v21; // w0
  unsigned int v22; // w0
  __int64 v23; // x5
  __int64 v24; // x6
  unsigned int v25; // w0
  unsigned int v26; // w0
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 result; // x0
  __int64 v30; // x4
  void *v31; // x0
  __int64 v32; // x2
  __int64 v33; // x4
  void *v34; // x0
  __int64 v35; // x2
  __int64 v36; // x4
  void *v37; // x0
  __int64 v38; // x2
  __int64 v39; // x4
  void *v40; // x0
  __int64 v41; // x2
  __int64 v42; // x4
  void *v43; // x0
  __int64 v44; // x2
  __int64 v45; // x4
  void *v46; // x0
  __int64 v47; // x2
  __int64 v48; // x4
  void *v49; // x0
  __int64 v50; // x2
  _WORD v51[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v52; // [xsp+8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = 0;
  v2 = haptic_i2c_read(a1, 5, v51);
  if ( (v2 & 0x80000000) != 0 )
  {
    v30 = v2;
    v31 = &unk_A1EE;
    v32 = 175;
  }
  else
  {
    v5 = haptic_i2c_write(a1, 5, v51[0] & 0xFDFF);
    if ( (v5 & 0x80000000) == 0 )
      goto LABEL_3;
    v30 = v5;
    v31 = &unk_A45E;
    v32 = 184;
  }
  printk(v31, "aw86320", v32, "haptic_i2c_write_bits", v30, v3, v4);
LABEL_3:
  v51[0] = 0;
  v6 = haptic_i2c_read(a1, 5, v51);
  if ( (v6 & 0x80000000) != 0 )
  {
    v33 = v6;
    v34 = &unk_A1EE;
    v35 = 175;
  }
  else
  {
    v9 = haptic_i2c_write(a1, 5, v51[0] & 0xFEFF);
    if ( (v9 & 0x80000000) == 0 )
      goto LABEL_5;
    v33 = v9;
    v34 = &unk_A45E;
    v35 = 184;
  }
  printk(v34, "aw86320", v35, "haptic_i2c_write_bits", v33, v7, v8);
LABEL_5:
  v51[0] = 0;
  v10 = haptic_i2c_read(a1, 5, v51);
  if ( (v10 & 0x80000000) != 0 )
  {
    v36 = v10;
    v37 = &unk_A1EE;
    v38 = 175;
  }
  else
  {
    v13 = haptic_i2c_write(a1, 5, v51[0] & 0xFF7F);
    if ( (v13 & 0x80000000) == 0 )
      goto LABEL_7;
    v36 = v13;
    v37 = &unk_A45E;
    v38 = 184;
  }
  printk(v37, "aw86320", v38, "haptic_i2c_write_bits", v36, v11, v12);
LABEL_7:
  v51[0] = 0;
  v14 = haptic_i2c_read(a1, 5, v51);
  if ( (v14 & 0x80000000) != 0 )
  {
    v39 = v14;
    v40 = &unk_A1EE;
    v41 = 175;
  }
  else
  {
    v17 = haptic_i2c_write(a1, 5, v51[0] & 0xFFBF);
    if ( (v17 & 0x80000000) == 0 )
      goto LABEL_9;
    v39 = v17;
    v40 = &unk_A45E;
    v41 = 184;
  }
  printk(v40, "aw86320", v41, "haptic_i2c_write_bits", v39, v15, v16);
LABEL_9:
  v51[0] = 0;
  v18 = haptic_i2c_read(a1, 5, v51);
  if ( (v18 & 0x80000000) != 0 )
  {
    v42 = v18;
    v43 = &unk_A1EE;
    v44 = 175;
  }
  else
  {
    v21 = haptic_i2c_write(a1, 5, v51[0] & 0xFFDF);
    if ( (v21 & 0x80000000) == 0 )
      goto LABEL_11;
    v42 = v21;
    v43 = &unk_A45E;
    v44 = 184;
  }
  printk(v43, "aw86320", v44, "haptic_i2c_write_bits", v42, v19, v20);
LABEL_11:
  v51[0] = 0;
  v22 = haptic_i2c_read(a1, 5, v51);
  if ( (v22 & 0x80000000) != 0 )
  {
    v45 = v22;
    v46 = &unk_A1EE;
    v47 = 175;
  }
  else
  {
    v25 = haptic_i2c_write(a1, 5, v51[0] & 0xFFEF);
    if ( (v25 & 0x80000000) == 0 )
      goto LABEL_13;
    v45 = v25;
    v46 = &unk_A45E;
    v47 = 184;
  }
  printk(v46, "aw86320", v47, "haptic_i2c_write_bits", v45, v23, v24);
LABEL_13:
  v51[0] = 0;
  v26 = haptic_i2c_read(a1, 5, v51);
  if ( (v26 & 0x80000000) != 0 )
  {
    v48 = v26;
    v49 = &unk_A1EE;
    v50 = 175;
LABEL_36:
    result = printk(v49, "aw86320", v50, "haptic_i2c_write_bits", v48, v27, v28);
    goto LABEL_15;
  }
  result = haptic_i2c_write(a1, 5, v51[0] & 0xFFF7);
  if ( (result & 0x80000000) != 0 )
  {
    v48 = (unsigned int)result;
    v49 = &unk_A45E;
    v50 = 184;
    goto LABEL_36;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
