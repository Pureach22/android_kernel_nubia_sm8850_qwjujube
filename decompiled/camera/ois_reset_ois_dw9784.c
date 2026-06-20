__int64 __fastcall ois_reset_ois_dw9784(__int64 *a1)
{
  int v2; // w1
  int v3; // w2
  int v4; // w1
  int v5; // w2
  int v6; // w1
  int v7; // w2
  int v8; // w1
  int v9; // w2
  int v10; // w1
  int v11; // w2
  int v12; // w1
  int v13; // w2
  int v14; // w1
  int v15; // w2
  int v16; // w1
  int v17; // w2
  int v18; // w1
  int v19; // w2
  int v20; // w1
  int v21; // w2
  int v22; // w1
  int v23; // w2
  int v24; // w1
  int v25; // w2
  int v26; // w1
  int v27; // w2
  int v28; // w1
  int v29; // w2
  int v30; // w1
  int v31; // w2
  int v32; // w1
  int v33; // w2
  int v34; // w1
  int v35; // w2
  int v36; // w1
  int v37; // w2
  int v38; // w1
  int v39; // w2
  int v40; // w1
  int v41; // w2
  int v42; // w1
  int v43; // w2
  int v44; // w1
  int v45; // w2
  int v46; // w1
  int v47; // w2
  int v48; // w1
  int v49; // w2
  int v50; // w1
  int v51; // w2
  __int64 v52; // x20
  __int64 result; // x0

  printk(&unk_432C4C);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656, 53250, 1, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay((const char *)0x1062560);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656, 53249, 1, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  _const_udelay("d: %u rc: %d", v2, v3);
  _const_udelay("d: %u rc: %d", v4, v5);
  _const_udelay("d: %u rc: %d", v6, v7);
  _const_udelay("d: %u rc: %d", v8, v9);
  _const_udelay("d: %u rc: %d", v10, v11);
  _const_udelay("d: %u rc: %d", v12, v13);
  _const_udelay("d: %u rc: %d", v14, v15);
  _const_udelay("d: %u rc: %d", v16, v17);
  _const_udelay("d: %u rc: %d", v18, v19);
  _const_udelay("d: %u rc: %d", v20, v21);
  _const_udelay("d: %u rc: %d", v22, v23);
  _const_udelay("d: %u rc: %d", v24, v25);
  _const_udelay("d: %u rc: %d", v26, v27);
  _const_udelay("d: %u rc: %d", v28, v29);
  _const_udelay("d: %u rc: %d", v30, v31);
  _const_udelay("d: %u rc: %d", v32, v33);
  _const_udelay("d: %u rc: %d", v34, v35);
  _const_udelay("d: %u rc: %d", v36, v37);
  _const_udelay("d: %u rc: %d", v38, v39);
  _const_udelay("d: %u rc: %d", v40, v41);
  _const_udelay("d: %u rc: %d", v42, v43);
  _const_udelay("d: %u rc: %d", v44, v45);
  _const_udelay("d: %u rc: %d", v46, v47);
  _const_udelay("d: %u rc: %d", v48, v49);
  _const_udelay("d: %u rc: %d", v50, v51);
  v52 = *a1;
  if ( !strncmp((const char *)(*a1 + 4516), "ois_ov64b40_qwbarley", 0x14u)
    && (zte_cam_cci_i2c_write(v52 + 3656, 28704, 0, 2, 2) & 0x80000000) != 0 )
  {
    printk(&unk_41BA38);
  }
  if ( (zte_cam_cci_i2c_write(*a1 + 3656, 60401, 22266, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656, 29156, 750, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  if ( (zte_cam_cci_i2c_write(*a1 + 3656, 28690, 1, 2, 2) & 0x80000000) != 0 )
    printk(&unk_41BA38);
  result = zte_cam_cci_i2c_write(*a1 + 3656, 28689, 0, 2, 2);
  if ( (result & 0x80000000) != 0 )
    return printk(&unk_41BA38);
  return result;
}
