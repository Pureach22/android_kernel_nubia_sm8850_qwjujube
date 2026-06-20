__int64 __fastcall eusb2_repeater_init(_QWORD *a1)
{
  unsigned __int64 v2; // x21
  unsigned __int64 v3; // x21
  __int64 v4; // x3
  int updated; // w0
  __int64 v6; // x3
  int v7; // w0
  __int64 v8; // x3
  int v9; // w0
  __int64 v10; // x3
  int v11; // w0
  __int64 v12; // x3
  int v13; // w0
  __int64 v14; // x3
  int v15; // w0
  __int64 v16; // x3
  int v17; // w0
  __int64 v18; // x3
  int v19; // w0
  __int64 v20; // x3
  int v21; // w0
  __int64 v22; // x3
  int v23; // w0
  __int64 v24; // x3
  int v25; // w0
  __int64 v26; // x3
  int v27; // w0
  __int64 v28; // x0
  __int64 v29; // x1
  int v30; // w0
  int v31; // w8
  __int64 v32; // x0
  __int64 v33; // x3
  __int64 v34; // x23
  unsigned __int64 i; // x22
  __int64 v36; // x8
  __int64 v37; // x0
  int v38; // w24
  __int64 v39; // x1
  int v40; // w0
  int v41; // w0
  int v42; // w3
  int v43; // w0
  int v44; // w0
  int v45; // w0
  int v46; // w0
  int v47; // w0
  const char *v48; // x2
  __int64 v50; // x23
  unsigned __int64 v51; // x22
  __int64 v52; // x8
  __int64 v53; // x0
  int v54; // w24
  __int64 v55; // x1
  int v56; // w0
  _BYTE v57[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v58[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v59[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v60; // [xsp+18h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((unsigned __int8 *)a1 + 168);
  v57[0] = 0;
  if ( v2 )
  {
    v34 = a1[19];
    for ( i = 0; i < v2; i += 2LL )
    {
      v36 = v34 + 4 * i;
      v37 = a1[11];
      v38 = *(unsigned __int16 *)(v36 + 4);
      v39 = v38 + (unsigned int)*((unsigned __int16 *)a1 + 48);
      v58[0] = *(_DWORD *)v36;
      v40 = regmap_bulk_write(v37, v39, v58, 1);
      if ( v40 )
        dev_err(*a1, "bulk write failed: addr=0x%04x, ret=%d\n", v38 + *((unsigned __int16 *)a1 + 48), v40);
    }
  }
  if ( a1[22] )
    user_input_param_override();
  if ( (a1[2] & 1) != 0 )
  {
    v3 = *((unsigned __int8 *)a1 + 169);
    if ( *((_BYTE *)a1 + 169) )
    {
      v50 = a1[20];
      v51 = 0;
      do
      {
        v52 = v50 + 4 * v51;
        v53 = a1[11];
        v54 = *(unsigned __int16 *)(v52 + 4);
        v55 = v54 + (unsigned int)*((unsigned __int16 *)a1 + 48);
        v59[0] = *(_DWORD *)v52;
        v56 = regmap_bulk_write(v53, v55, v59, 1);
        if ( v56 )
          dev_err(*a1, "bulk write failed: addr=0x%04x, ret=%d\n", v54 + *((unsigned __int16 *)a1 + 48), v56);
        v51 += 2LL;
      }
      while ( v51 < v3 );
    }
  }
  v4 = *((unsigned __int8 *)a1 + 136);
  if ( (unsigned int)v4 <= 7 )
  {
    updated = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 80, 7, v4, 0, 0, 0);
    if ( updated )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 80, updated);
  }
  v6 = *((unsigned __int8 *)a1 + 137);
  if ( (unsigned int)v6 <= 0xF )
  {
    v7 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 81, 15, v6, 0, 0, 0);
    if ( v7 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 81, v7);
  }
  v8 = *((unsigned __int8 *)a1 + 138);
  if ( (unsigned int)v8 <= 7 )
  {
    v9 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 82, 7, v8, 0, 0, 0);
    if ( v9 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 82, v9);
  }
  v10 = *((unsigned __int8 *)a1 + 139);
  if ( (unsigned int)v10 <= 7 )
  {
    v11 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 83, 7, v10, 0, 0, 0);
    if ( v11 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 83, v11);
  }
  v12 = *((unsigned __int8 *)a1 + 140);
  if ( (unsigned int)v12 <= 7 )
  {
    v13 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 84, 7, v12, 0, 0, 0);
    if ( v13 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 84, v13);
  }
  v14 = *((unsigned __int8 *)a1 + 141);
  if ( (unsigned int)v14 <= 3 )
  {
    v15 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 85, 3, v14, 0, 0, 0);
    if ( v15 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 85, v15);
  }
  v16 = *((unsigned __int8 *)a1 + 142);
  if ( (unsigned int)v16 <= 3 )
  {
    v17 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 86, 3, v16, 0, 0, 0);
    if ( v17 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 86, v17);
  }
  v18 = *((unsigned __int8 *)a1 + 143);
  if ( (unsigned int)v18 <= 7 )
  {
    v19 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 87, 7, v18, 0, 0, 0);
    if ( v19 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 87, v19);
  }
  v20 = *((unsigned __int8 *)a1 + 144);
  if ( (unsigned int)v20 <= 3 )
  {
    v21 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 88, 3, v20, 0, 0, 0);
    if ( v21 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 88, v21);
  }
  v22 = *((unsigned __int8 *)a1 + 145);
  if ( (unsigned int)v22 <= 3 )
  {
    v23 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 89, 3, v22, 0, 0, 0);
    if ( v23 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 89, v23);
  }
  v24 = *((unsigned __int8 *)a1 + 146);
  if ( (unsigned int)v24 <= 3 )
  {
    v25 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 90, 3, v24, 0, 0, 0);
    if ( v25 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 90, v25);
  }
  v26 = *((unsigned __int8 *)a1 + 147);
  if ( (unsigned int)v26 <= 3 )
  {
    v27 = regmap_update_bits_base(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 91, 3, v26, 0, 0, 0);
    if ( v27 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 91, v27);
  }
  v28 = a1[11];
  v29 = (unsigned int)*((unsigned __int16 *)a1 + 48) + 232;
  if ( (a1[2] & 1) != 0 )
  {
    v41 = regmap_update_bits_base(v28, v29, 64, 64, 0, 0, 0);
    if ( v41 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 232, v41);
    v31 = *((unsigned __int16 *)a1 + 48);
    v32 = a1[11];
    v33 = 64;
  }
  else
  {
    v30 = regmap_update_bits_base(v28, v29, 64, 0, 0, 0, 0);
    if ( v30 )
      dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 232, v30);
    v31 = *((unsigned __int16 *)a1 + 48);
    v32 = a1[11];
    v33 = 0;
  }
  v42 = regmap_update_bits_base(v32, (unsigned int)(v31 + 237), 64, v33, 0, 0, 0);
  if ( v42 )
    dev_err(*a1, "write failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 237, v42);
  v43 = regmap_bulk_read(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 8, v57, 1);
  if ( v43 )
    dev_err(*a1, "read failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 8, v43);
  if ( (v57[0] & 0x80000000) != 0 )
    goto LABEL_73;
  usleep_range_state(10, 20, 2);
  v44 = regmap_bulk_read(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 8, v57, 1);
  if ( v44 )
    dev_err(*a1, "read failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 8, v44);
  if ( (v57[0] & 0x80000000) != 0 )
    goto LABEL_73;
  usleep_range_state(10, 20, 2);
  v45 = regmap_bulk_read(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 8, v57, 1);
  if ( v45 )
    dev_err(*a1, "read failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 8, v45);
  if ( (v57[0] & 0x80000000) != 0 )
    goto LABEL_73;
  usleep_range_state(10, 20, 2);
  v46 = regmap_bulk_read(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 8, v57, 1);
  if ( v46 )
    dev_err(*a1, "read failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 8, v46);
  if ( (v57[0] & 0x80000000) != 0 )
  {
LABEL_73:
    v48 = "OK";
  }
  else
  {
    usleep_range_state(10, 20, 2);
    v47 = regmap_bulk_read(a1[11], (unsigned int)*((unsigned __int16 *)a1 + 48) + 8, v57, 1);
    if ( v47 )
      dev_err(*a1, "read failed: addr=0x%04x, ret=%d\n", *((unsigned __int16 *)a1 + 48) + 8, v47);
    v48 = "OK";
    if ( (v57[0] & 0x80000000) == 0 )
    {
      usleep_range_state(10, 20, 2);
      if ( v57[0] < 0 )
        v48 = "OK";
      else
        v48 = "NOT OK";
    }
  }
  dev_info(*a1, "eUSB2 repeater status:%s\n", v48);
  _ReadStatusReg(SP_EL0);
  return 0;
}
