__int64 __fastcall set_lcd_reset_processing(char a1, __int64 a2, __int64 a3)
{
  *(_BYTE *)(tpd_cdev + 24) = a1;
  return printk(unk_38D27, a1 & 1, a3);
}
