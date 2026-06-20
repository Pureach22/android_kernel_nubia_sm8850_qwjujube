__int64 __fastcall wlan_vdev_mlme_ser_cancel_request(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  unsigned int v12[4]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = a1;
  v12[2] = 0;
  v12[3] = a3;
  v12[0] = 0;
  v12[1] = a2;
  v14 = 2;
  result = wlan_serialization_cancel_request(v12, a4, a5, a6, a7, a8, a9, a10, a11);
  _ReadStatusReg(SP_EL0);
  return result;
}
