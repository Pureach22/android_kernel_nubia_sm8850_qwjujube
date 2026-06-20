__int64 __fastcall slim_write(__int64 a1, unsigned __int16 a2, char a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  v6[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[1] = 0;
  v6[0] = a2;
  BYTE2(v6[0]) = a3;
  v6[2] = a4;
  v6[3] = 0;
  result = slim_xfer_msg(a1, (unsigned __int16 *)v6, 0x68u, a4, a5);
  _ReadStatusReg(SP_EL0);
  return result;
}
