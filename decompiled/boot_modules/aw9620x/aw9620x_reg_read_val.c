__int64 __fastcall aw9620x_reg_read_val(__int64 a1, _DWORD *a2, unsigned __int16 a3)
{
  int v6; // w2
  __int64 result; // x0

  if ( (unsigned int)aw9620x_i2c_write(a1, 0x4704u, a3) )
  {
    dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] config PMU_CFG regerr\n", "aw9620x_reg_read_val", 1229);
  }
  else
  {
    if ( a3 >> 14 )
      v6 = 35;
    else
      v6 = 3;
    if ( (unsigned int)aw9620x_i2c_write(a1, 0x4710u, v6) )
    {
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] config ISP_CMD reg err\n", "aw9620x_reg_read_val", 1239);
    }
    else if ( (unsigned int)aw9620x_i2c_write(a1, 0x4714u, 1) )
    {
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] config ISP_CMD reg err\n", "aw9620x_reg_read_val", 1245);
    }
    else if ( (unsigned int)aw9620x_check_isp_go_reg(a1) )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] config check_isp_go_reg err\n",
        "aw9620x_reg_read_val",
        1251);
    }
    else
    {
      result = aw9620x_i2c_read(a1, 0x470Cu, a2);
      if ( !(_DWORD)result )
        return result;
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] config ISP_CMD reg err\n", "aw9620x_reg_read_val", 1257);
    }
  }
  return 0xFFFFFFFFLL;
}
