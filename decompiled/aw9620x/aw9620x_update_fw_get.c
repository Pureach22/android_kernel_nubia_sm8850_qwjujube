__int64 __fastcall aw9620x_update_fw_get(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x20
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v6 = 0;
  if ( (aw9620x_i2c_read(v4 - 56, 0x1A10u, &v6) & 0x80000000) != 0 )
    dev_printk(&unk_142BB, *(_QWORD *)(v4 - 8), "[%s:%d] read firmware version err\n", "aw9620x_update_fw_get", 3573);
  LODWORD(result) = snprintf(a3, 0x1000u, "reg firmware_version:0x%08x\n", v6);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
