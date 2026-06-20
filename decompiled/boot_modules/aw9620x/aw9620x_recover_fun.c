__int64 __fastcall aw9620x_recover_fun(__int64 a1, int a2)
{
  __int64 v4; // x1
  int v5; // w0
  __int64 v6; // x1
  __int64 result; // x0
  unsigned int v8; // w21
  unsigned int v10; // w20
  __int64 v11; // x1
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 48);
  v12 = 0;
  dev_printk(&unk_134C0, v4, "[%s:%d] %s enter\n", "aw9620x_recover_fun", 900, "aw9620x_recover_fun");
  if ( (unsigned int)aw9620x_i2c_write(a1, 0xFF20u, 1006698495) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_recover_fun", 903);
  }
  else
  {
    v5 = aw9620x_i2c_read(a1, 0x4744u, &v12);
    v6 = *(_QWORD *)(a1 + 48);
    if ( v5 < 0 )
    {
      dev_printk(&unk_134C0, v6, "[%s:%d] read REG_UPDATA_DIS err: %d\n", "aw9620x_recover_fun", 909, 0xFFFFFFFFLL);
    }
    else
    {
      v8 = v12;
      dev_printk(&unk_13D4F, v6, "[%s:%d] trim  reg_data:0x%08X\n", "aw9620x_recover_fun", 913, v12);
      if ( HIBYTE(v8) == 255 || a2 == 0 )
        v10 = v8 & 0xFFFFFF;
      else
        v10 = v8;
      dev_printk(
        &unk_13D4F,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] trim new_reg_data:0x%08X\n",
        "aw9620x_recover_fun",
        926,
        v10);
      v11 = *(_QWORD *)(a1 + 48);
      if ( v10 == v8 )
      {
        dev_printk(&unk_13D4F, v11, "[%s:%d] trim reg_data ok, no need update\n", "aw9620x_recover_fun", 935);
      }
      else
      {
        dev_printk(&unk_13D4F, v11, "[%s:%d] trim reg_data error, need update\n", "aw9620x_recover_fun", 929);
        if ( (unsigned int)aw9620x_i2c_write(a1, 0x4744u, v10) )
          dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write REG_UPDATA_DIS err\n", "aw9620x_recover_fun", 932);
      }
      if ( (aw9620x_i2c_write(a1, 0xFF20u, 1006694417) & 0x80000000) == 0 )
      {
        result = 0;
        goto LABEL_18;
      }
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] write 0xff20 err: %d\n",
        "aw9620x_recover_fun",
        940,
        0xFFFFFFFFLL);
    }
  }
  result = 0xFFFFFFFFLL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
