__int64 __fastcall aw9620x_sensy_config_set(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  char v7; // w8
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( !(unsigned int)kstrtouint(a3, 0, &v8) )
  {
    dev_printk(&unk_142BB, *(_QWORD *)(v5 - 8), "[%s:%d] flag = %d\n", "aw9620x_sensy_config_set", 4066, v8);
    mutex_lock(&aw_update_lock);
    switch ( v8 )
    {
      case 3:
        aw9620x_i2c_write(v5 - 56, 0x1D20u, 11);
        v7 = 3;
        break;
      case 2:
        aw9620x_i2c_write(v5 - 56, 0x1D20u, 12);
        v7 = 2;
        break;
      case 1:
        aw9620x_i2c_write(v5 - 56, 0x1D20u, 13);
        v7 = 1;
        break;
      default:
        dev_printk(&unk_134C0, *(_QWORD *)(v5 - 8), "[%s:%d] input err\n", "aw9620x_sensy_config_set", 4079);
        goto LABEL_10;
    }
    *(_BYTE *)(v5 + 616) = v7;
LABEL_10:
    mutex_unlock(&aw_update_lock);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
