__int64 __fastcall slim_writeb(__int64 a1, __int16 a2, char a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  char v6; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v7[5]; // [xsp+8h] [xbp-28h] BYREF

  v7[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a3;
  v7[0] = 0x10000;
  v7[1] = 0;
  LOWORD(v7[0]) = a2;
  v7[2] = &v6;
  v7[3] = 0;
  result = slim_xfer_msg(a1, (unsigned __int16 *)v7, 0x68u, a4, a5);
  _ReadStatusReg(SP_EL0);
  return result;
}
