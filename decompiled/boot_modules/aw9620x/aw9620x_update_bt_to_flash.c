__int64 __fastcall aw9620x_update_bt_to_flash(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x1
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+8h] [xbp-38h] BYREF
  int v8; // [xsp+18h] [xbp-28h]
  int v9; // [xsp+1Ch] [xbp-24h]
  _QWORD *v10; // [xsp+20h] [xbp-20h]
  _QWORD v11[3]; // [xsp+28h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  v7[1] = a2;
  v4 = *(_QWORD *)(a1 + 48);
  v11[0] = 2040;
  v11[1] = 0x7FC000007F8LL;
  v10 = v11;
  v8 = a3;
  v9 = 0;
  if ( a2 )
  {
    dev_printk(&unk_142BB, v4, "[%s:%d] update_data_len = %d\n", "aw9620x_update_bt_to_flash", 1575, a3);
    result = aw9620x_flash_update(a1, (unsigned __int8 *)v7);
  }
  else
  {
    dev_printk(&unk_142BB, v4, "[%s:%d] w_bin_offset is null err\n", "aw9620x_update_bt_to_flash", 1571);
    result = 0xFFFFFFFFLL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
