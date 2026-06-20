__int64 __fastcall aw9620x_reg_write_to_flash_once(__int64 a1, unsigned __int16 a2, int a3)
{
  __int64 result; // x0

  if ( (unsigned int)aw9620x_i2c_write(a1, 0x4704u, a2) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_reg_write_to_flash_once", 1125);
  }
  else if ( (unsigned int)aw9620x_i2c_write(a1, 0x4708u, a3) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_reg_write_to_flash_once", 1132);
  }
  else if ( (unsigned int)aw9620x_i2c_write(a1, 0x4710u, 12) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_reg_write_to_flash_once", 1139);
  }
  else if ( (unsigned int)aw9620x_i2c_write(a1, 0x4714u, 1) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_reg_write_to_flash_once", 1146);
  }
  else
  {
    result = aw9620x_check_isp_go_reg(a1);
    if ( !(_DWORD)result )
      return result;
    dev_printk(
      &unk_134C0,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] check_isp_go_reg err\n",
      "aw9620x_reg_write_to_flash_once",
      1152);
  }
  return 0xFFFFFFFFLL;
}
