__int64 bt_signal_handler()
{
  int v0; // w8
  __int64 v1; // x2
  __int64 result; // x0
  __int64 v3; // [xsp+8h] [xbp-38h] BYREF
  __int64 v4; // [xsp+10h] [xbp-30h]
  __int64 v5; // [xsp+18h] [xbp-28h]
  int v6; // [xsp+20h] [xbp-20h]
  int v7; // [xsp+24h] [xbp-1Ch]
  __int64 v8; // [xsp+28h] [xbp-18h]
  __int64 v9; // [xsp+30h] [xbp-10h]
  __int64 v10; // [xsp+38h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  v3 = 29;
  v0 = *(_DWORD *)(pwr_data + 292);
  v1 = *(_QWORD *)(pwr_data + 208);
  v8 = 0;
  v9 = 0;
  LODWORD(v4) = -1;
  v5 = 0;
  v7 = 0;
  v6 = v0;
  if ( (send_sig_info(29, &v3, v1) & 0x80000000) != 0 )
    result = printk(&unk_124B1, "bt_signal_handler");
  else
    result = printk(&unk_11364, "bt_signal_handler");
  _ReadStatusReg(SP_EL0);
  return result;
}
