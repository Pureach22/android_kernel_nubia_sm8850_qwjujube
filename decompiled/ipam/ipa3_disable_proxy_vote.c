__int64 __fastcall ipa3_disable_proxy_vote(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x0
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  v4 = kstrtos8_from_user(a2, a3, 0, v6);
  if ( (_DWORD)v4 )
  {
    v3 = (int)v4;
  }
  else if ( v6[0] == 1 )
  {
    ipa3_proxy_clk_unvote(v4);
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
