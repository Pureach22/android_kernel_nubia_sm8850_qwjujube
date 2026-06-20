__int64 __fastcall aw22xxx_read_chipid(__int64 a1)
{
  int v2; // w3
  __int64 result; // x0
  char v4; // w9
  __int64 v5; // x8
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  aw22xxx_i2c_write((__int64 *)a1, 255, 0);
  aw22xxx_i2c_write((__int64 *)a1, 1, 85);
  usleep_range_state(2000, 3000, 2);
  v2 = aw22xxx_i2c_read((_QWORD *)a1, 1, v6);
  if ( v2 < 0 )
    goto LABEL_2;
  if ( v6[0] == 118 )
    goto LABEL_4;
  printk(&unk_13F38, "aw22xxx_read_chipid");
  msleep(1);
  v2 = aw22xxx_i2c_read((_QWORD *)a1, 1, v6);
  if ( (v2 & 0x80000000) == 0 )
  {
    if ( v6[0] != 118 )
    {
      printk(&unk_13F38, "aw22xxx_read_chipid");
      msleep(1);
      goto LABEL_13;
    }
LABEL_4:
    printk(&unk_133ED, "aw22xxx_read_chipid");
    aw22xxx_i2c_read((_QWORD *)a1, 0, v6);
    if ( v6[0] == 24 )
    {
      v4 = 1;
      v5 = 0x38313132327761LL;
      goto LABEL_11;
    }
    if ( v6[0] == 39 )
    {
      v4 = 2;
      v5 = 0x37323132327761LL;
LABEL_11:
      *(_BYTE *)(a1 + 749) = v4;
      g_chip_id = v5;
      printk(&unk_137BD, "aw22xxx_read_chipid");
      result = 0;
      goto LABEL_14;
    }
    printk(&unk_12AF3, "aw22xxx_read_chipid");
LABEL_13:
    result = 4294967274LL;
    goto LABEL_14;
  }
LABEL_2:
  dev_err(*(_QWORD *)(a1 + 8), "%s: failed to read register AW22XXX_REG_ID: %d\n", "aw22xxx_read_chipid", v2);
  result = 4294967291LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
