__int64 __fastcall aw9620x_check_isp_go_reg(__int64 a1)
{
  int v2; // w20
  __int64 result; // x0
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v2 = 100;
  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  while ( !(unsigned int)aw9620x_i2c_read(a1, 0x4714u, &v4) )
  {
    if ( !v4 )
    {
      if ( (v2 & 0x80000000) == 0 )
      {
        result = 0;
        goto LABEL_8;
      }
LABEL_9:
      dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] check_isp_go_reg err!\n", "aw9620x_check_isp_go_reg", 1079);
      goto LABEL_11;
    }
    _const_udelay(4295000);
    if ( --v2 == -1 )
      goto LABEL_9;
  }
  dev_printk(&unk_134C0, *(_QWORD *)(a1 + 48), "[%s:%d] write 0xff20 err\n", "aw9620x_check_isp_go_reg", 1070);
LABEL_11:
  result = 0xFFFFFFFFLL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
