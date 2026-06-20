__int64 __fastcall aw9620x_reg_write_val_to_flash(__int64 a1, unsigned int a2, unsigned int a3, unsigned __int8 *a4)
{
  int v8; // w22
  __int64 result; // x0
  int v10; // w4

  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_reg_write_val_to_flash", 1191);
  v8 = *a4;
  if ( (unsigned int)aw9620x_i2c_write(a1, 0xFF20u, 1006694801) )
  {
    v10 = 1094;
LABEL_14:
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_close_write_flash_protect", v10);
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] close_write_flash_protect err\n",
      "aw9620x_reg_write_val_to_flash",
      1195);
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned int)aw9620x_i2c_write(a1, 0x4820u, 6) )
  {
    v10 = 1101;
    goto LABEL_14;
  }
  if ( !v8 && (unsigned int)aw9620x_i2c_write(a1, 0x4794u, 1516468565) )
  {
    v10 = 1109;
    goto LABEL_14;
  }
  if ( (unsigned int)aw9620x_reg_write_to_flash_once(a1, a2, a3) )
  {
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] write aw9620x_reg_write_bin_once err\n",
      "aw9620x_reg_write_val_to_flash",
      1201);
  }
  else if ( (unsigned int)aw9620x_i2c_write(a1, 0x4820u, 4) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0x4820 err\n", "aw9620x_reg_write_val_to_flash", 1208);
  }
  else
  {
    result = aw9620x_i2c_write(a1, 0xFF20u, 1006694417);
    if ( !(_DWORD)result )
      return result;
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_reg_write_val_to_flash", 1214);
  }
  return 0xFFFFFFFFLL;
}
