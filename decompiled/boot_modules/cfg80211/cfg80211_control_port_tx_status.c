__int64 __fastcall cfg80211_control_port_tx_status(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        char a5,
        unsigned int a6)
{
  __int64 result; // x0
  _QWORD v7[5]; // [xsp+8h] [xbp-38h] BYREF
  char v8; // [xsp+30h] [xbp-10h]
  _BYTE v9[7]; // [xsp+31h] [xbp-Fh] BYREF
  __int64 v10; // [xsp+38h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = a2;
  v7[1] = 0;
  v7[2] = 0;
  v7[3] = a3;
  v7[4] = a4;
  v8 = a5;
  memset(v9, 0, sizeof(v9));
  result = ((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD, __int64))nl80211_frame_tx_status)(a1, v7, a6, 139);
  _ReadStatusReg(SP_EL0);
  return result;
}
