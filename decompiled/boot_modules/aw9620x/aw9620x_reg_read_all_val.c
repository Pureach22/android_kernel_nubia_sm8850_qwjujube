__int64 __fastcall aw9620x_reg_read_all_val(__int64 a1, _DWORD *a2, unsigned __int16 a3)
{
  int val; // w0
  __int64 v7; // x1
  __int64 result; // x0

  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_reg_read_all_val", 2020);
  if ( (unsigned int)aw9620x_i2c_write(a1, 0xFF20u, 1006694801) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_reg_read_all_val", 2025);
  }
  else if ( (unsigned int)aw9620x_i2c_write(a1, 0x4820u, 4) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] config PMU_CFG reg err\n", "aw9620x_reg_read_all_val", 2031);
  }
  else
  {
    val = aw9620x_reg_read_val(a1, a2, a3);
    v7 = *(_QWORD *)(a1 + 48);
    if ( val )
    {
      dev_printk(&unk_142BB, v7, "[%s:%d] reg_read_bin err\n", "aw9620x_reg_read_all_val", 2037);
    }
    else
    {
      dev_printk(
        &unk_142BB,
        v7,
        "[%s:%d] addr = 0x%04x read data = 0x%08x\n",
        "aw9620x_reg_read_all_val",
        2041,
        a3,
        *a2);
      result = aw9620x_i2c_write(a1, 0xFF20u, 1006694417);
      if ( !(_DWORD)result )
        return result;
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_reg_read_all_val", 2045);
    }
  }
  return 0xFFFFFFFFLL;
}
