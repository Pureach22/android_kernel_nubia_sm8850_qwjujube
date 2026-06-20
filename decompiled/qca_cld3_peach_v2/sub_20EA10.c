__int64 __fastcall sub_20EA10(__int64 a1, __int64 _X1, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v10; // x6

  __asm { LDLARH          W6, [X1] }
  v10 = _OFF;
  __asm { LDLARH          W6, [X1] }
  return wlan_reg_conv_supported_6g_pwr_type_to_ap_pwr_type(a1, _X1, a3, a4, a5, a6, v10);
}
