__int64 __fastcall aw9620x_update_fw_to_flash(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x1
  __int64 result; // x0
  unsigned __int8 v6[8]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v7; // [xsp+10h] [xbp-30h]
  int v8; // [xsp+18h] [xbp-28h]
  int v9; // [xsp+1Ch] [xbp-24h]
  _QWORD *v10; // [xsp+20h] [xbp-20h]
  _QWORD v11[3]; // [xsp+28h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a2;
  v4 = *(_QWORD *)(a1 + 48);
  v11[0] = 0x800000037F8LL;
  v11[1] = 0x3FFC00003FF8LL;
  v6[0] = 1;
  v8 = a3;
  v9 = 0x2000;
  memset(&v6[1], 0, 7);
  v10 = v11;
  dev_printk(&unk_142BB, v4, "[%s:%d] update_data_len = %d\n", "aw9620x_update_fw_to_flash", 1596, a3);
  result = aw9620x_flash_update(a1, v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
