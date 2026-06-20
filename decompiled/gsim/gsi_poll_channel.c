__int64 __fastcall gsi_poll_channel(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  result = gsi_poll_n_channel(a1, a2, 1, &v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
