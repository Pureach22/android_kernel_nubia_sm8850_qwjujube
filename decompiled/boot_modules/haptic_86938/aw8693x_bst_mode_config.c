__int64 __fastcall aw8693x_bst_mode_config(__int64 a1, char a2)
{
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      printk(&unk_16576, "haptic_hv", 504, "aw8693x_bst_mode_config");
      return i2c_w_bits(a1, 6, 4294967263LL, 32);
    }
    else
    {
      return printk(&unk_14799, "haptic_hv", 516, "aw8693x_bst_mode_config");
    }
  }
  else
  {
    printk(&unk_143C9, "haptic_hv", 510, "aw8693x_bst_mode_config");
    return i2c_w_bits(a1, 6, 4294967263LL, 0);
  }
}
