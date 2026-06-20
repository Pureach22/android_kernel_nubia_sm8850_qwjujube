__int64 __fastcall aw9620x_read_chipid(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x1
  unsigned int v4; // w19
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // x1
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v9 = 0;
  dev_printk(&unk_142BB, v2, "[%s:%d] enter\n", "aw9620x_read_chipid", 806);
  if ( (aw9620x_i2c_read(a1, 0xFF00u, &v9) & 0x80000000) != 0 )
  {
    v3 = *(_QWORD *)(a1 + 48);
    v4 = -1;
    dev_printk(&unk_134C0, v3, "[%s:%d] read CHIP ID failed: %d\n", "aw9620x_read_chipid", 810, -1);
  }
  else
  {
    switch ( v9 )
    {
      case 539124232:
        v7 = *(_QWORD *)(a1 + 48);
        *(_QWORD *)(a1 + 673) = 0x38303236395741LL;
        dev_printk(&unk_142BB, v7, "[%s:%d] AW96208CSR CHIP ID : 0x%x\n", "aw9620x_read_chipid", 826, 539124232);
        break;
      case 539124229:
        v6 = *(_QWORD *)(a1 + 48);
        *(_QWORD *)(a1 + 673) = 0x35303236395741LL;
        dev_printk(&unk_142BB, v6, "[%s:%d] AW96205DNR CHIP ID : 0x%x\n", "aw9620x_read_chipid", 822, 539124229);
        break;
      case 539124227:
        v5 = *(_QWORD *)(a1 + 48);
        *(_QWORD *)(a1 + 673) = 0x33303236395741LL;
        dev_printk(&unk_142BB, v5, "[%s:%d] AW96203CSR CHIP ID : 0x%x\n", "aw9620x_read_chipid", 818, 539124227);
        break;
      default:
        dev_printk(
          &unk_142BB,
          *(_QWORD *)(a1 + 48),
          "[%s:%d] no chipid,need update root and frimware,CHIP ID : 0x%x\n",
          "aw9620x_read_chipid",
          830,
          v9);
        v4 = -2;
        goto LABEL_11;
    }
    v4 = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v4;
}
