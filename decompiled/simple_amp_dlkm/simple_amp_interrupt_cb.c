__int64 __fastcall simple_amp_interrupt_cb(__int64 a1, unsigned int a2)
{
  _QWORD *v4; // x23
  __int64 v5; // x21
  unsigned int v6; // w0
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  char v12; // w8
  bool v13; // zf
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x27
  char v17; // w8
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x26
  int v20; // w21
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v31; // x3
  void *v32; // x0
  __int64 v33; // x3
  void *v34; // x0
  __int64 v35; // x3
  void *v36; // x0
  __int64 v37; // x3
  void *v38; // x0
  __int64 v39; // x3
  void *v40; // x0
  __int64 v41; // x3
  void *v42; // x0
  int v43; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-28h] BYREF
  __int64 v45; // [xsp+10h] [xbp-20h] BYREF
  __int64 v46; // [xsp+18h] [xbp-18h] BYREF
  unsigned int v47; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+28h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD **)(a1 + 224);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  v5 = *v4;
  v43 = 0;
  v47 = 0;
  v6 = regmap_read(v5, 1079510055, &v47);
  if ( v6 )
  {
    v31 = v6;
    v32 = &unk_CF69;
  }
  else
  {
    if ( !(unsigned int)__ratelimit(&simple_amp_read_print_registers__rs, "simple_amp_read_print_registers") )
      goto LABEL_3;
    v31 = v47;
    v32 = &unk_CE09;
  }
  printk(v32, "simple_amp_read_print_registers", 1079510055, v31);
LABEL_3:
  v7 = regmap_read(v5, 1079510057, &v47);
  if ( v7 )
  {
    v33 = v7;
    v34 = &unk_CF69;
  }
  else
  {
    if ( !(unsigned int)__ratelimit(&simple_amp_read_print_registers__rs, "simple_amp_read_print_registers") )
      goto LABEL_5;
    v33 = v47;
    v34 = &unk_CE09;
  }
  printk(v34, "simple_amp_read_print_registers", 1079510057, v33);
LABEL_5:
  v8 = regmap_read(v5, 1079510064, &v47);
  if ( v8 )
  {
    v35 = v8;
    v36 = &unk_CF69;
  }
  else
  {
    if ( !(unsigned int)__ratelimit(&simple_amp_read_print_registers__rs, "simple_amp_read_print_registers") )
      goto LABEL_7;
    v35 = v47;
    v36 = &unk_CE09;
  }
  printk(v36, "simple_amp_read_print_registers", 1079510064, v35);
LABEL_7:
  v9 = regmap_read(v5, 1079510066, &v47);
  if ( v9 )
  {
    v37 = v9;
    v38 = &unk_CF69;
  }
  else
  {
    if ( !(unsigned int)__ratelimit(&simple_amp_read_print_registers__rs, "simple_amp_read_print_registers") )
      goto LABEL_9;
    v37 = v47;
    v38 = &unk_CE09;
  }
  printk(v38, "simple_amp_read_print_registers", 1079510066, v37);
LABEL_9:
  v10 = regmap_read(v5, 1079510074, &v47);
  if ( v10 )
  {
    v39 = v10;
    v40 = &unk_CF69;
  }
  else
  {
    if ( !(unsigned int)__ratelimit(&simple_amp_read_print_registers__rs, "simple_amp_read_print_registers") )
      goto LABEL_11;
    v39 = v47;
    v40 = &unk_CE09;
  }
  printk(v40, "simple_amp_read_print_registers", 1079510074, v39);
LABEL_11:
  v11 = regmap_read(v5, 1079510076, &v47);
  if ( v11 )
  {
    v41 = v11;
    v42 = &unk_CF69;
LABEL_56:
    printk(v42, "simple_amp_read_print_registers", 1079510076, v41);
    goto LABEL_13;
  }
  if ( (unsigned int)__ratelimit(&simple_amp_read_print_registers__rs, "simple_amp_read_print_registers") )
  {
    v41 = v47;
    v42 = &unk_CE09;
    goto LABEL_56;
  }
LABEL_13:
  swr_read(a1, a2, 88, &v46, 1);
  swr_read(a1, a2, 89, &v45, 1);
  swr_read(a1, a2, 90, &v44, 1);
  if ( (v46 & 0x9C) != 0 || (v45 & 0x74) != 0 )
  {
    v12 = 0;
    do
    {
      v14 = (unsigned __int8)((-1LL << v12) & v46);
      v13 = v14 == 0;
      v15 = __clz(__rbit64(v14));
      if ( v13 )
        v16 = 8;
      else
        v16 = v15;
      if ( (unsigned int)v16 > 7 )
        break;
      if ( v16 > 0x18 )
LABEL_57:
        __break(1u);
      dev_err(v4[1], "interrupt %s triggered\n", simple_amp_interrupts[v16]);
      if ( (_DWORD)v16 == 2 )
        msleep(100);
      v12 = v16 + 1;
    }
    while ( v16 < 7 );
    v17 = 0;
    do
    {
      v18 = (unsigned __int8)((-1LL << v17) & v45);
      if ( !v18 )
        break;
      v19 = __clz(__rbit64(v18));
      if ( (v19 | 8) > 0x17 )
        goto LABEL_57;
      dev_err(v4[1], "interrupt %s triggered\n", simple_amp_interrupts[v19 | 8]);
      v17 = v19 + 1;
    }
    while ( v19 < 7 );
    if ( (v46 & 0x9C) != 0 )
      swr_write(a1, a2, 88, &v46);
    v20 = 1;
  }
  else
  {
    v20 = 0;
  }
  if ( (v45 & 0x74) != 0 )
    swr_write(a1, a2, 89, &v45);
  if ( (v44 & 0x70) != 0 )
    swr_write(a1, a2, 90, &v44);
  if ( v20 )
  {
    regmap_read(*v4, 1079510051, &v43);
    v21 = *v4;
    v43 &= ~8u;
    regmap_write(v21, 1079510051);
    v22 = *v4;
    v43 |= 8u;
    regmap_write(v22, 1079510051);
    v23 = *v4;
    v43 &= ~8u;
    regmap_write(v23, 1079510051);
    regmap_read(*v4, 1079510058, &v43);
    v24 = *v4;
    v43 &= ~4u;
    regmap_write(v24, 1079510058);
    v25 = *v4;
    v43 |= 4u;
    regmap_write(v25, 1079510058);
    v26 = *v4;
    v43 &= ~4u;
    regmap_write(v26, 1079510058);
    regmap_read(*v4, 1079510068, &v43);
    v27 = *v4;
    v43 &= ~4u;
    regmap_write(v27, 1079510068);
    v28 = *v4;
    v43 |= 4u;
    regmap_write(v28, 1079510068);
    v29 = *v4;
    v43 &= ~4u;
    regmap_write(v29, 1079510068);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
