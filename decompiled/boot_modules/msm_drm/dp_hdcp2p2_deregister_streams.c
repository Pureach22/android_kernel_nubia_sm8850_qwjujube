__int64 __fastcall dp_hdcp2p2_deregister_streams(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  __int64 result; // x0
  _QWORD v4[7]; // [xsp+8h] [xbp-38h] BYREF

  v4[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[4] = a3;
  v4[5] = a2;
  memset(&v4[1], 0, 24);
  v4[0] = 16;
  result = dp_hdcp2p2_change_streams(a1, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
