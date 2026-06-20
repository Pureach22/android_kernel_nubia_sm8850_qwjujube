__int64 __fastcall ll_lt_sap_high_ap_availability_ser_cmd_remove(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  unsigned int v11[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = a1;
  v14 = 0;
  v11[0] = 0;
  v12 = 0;
  v11[1] = a2;
  result = wlan_serialization_remove_cmd(v11, a3, a4, a5, a6, a7, a8, a9, a10);
  _ReadStatusReg(SP_EL0);
  return result;
}
