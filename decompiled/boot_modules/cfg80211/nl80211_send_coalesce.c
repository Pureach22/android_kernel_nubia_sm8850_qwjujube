__int64 __fastcall nl80211_send_coalesce(__int64 a1, __int64 a2)
{
  int *v2; // x8
  int v3; // w10
  int v4; // w9
  int v5; // w12
  int v6; // w8
  int v7; // w11
  __int64 result; // x0
  _DWORD v9[6]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(int **)(a2 + 2352);
  if ( v2 )
  {
    v3 = *v2;
    v9[5] = v2[1];
    v4 = v2[2];
    v5 = v2[3];
    v7 = v2[4];
    v6 = v2[5];
    v9[0] = v3;
    v9[1] = v4;
    v9[2] = v7;
    v9[3] = v5;
    v9[4] = v6;
    if ( (unsigned int)nla_put(a1, 182, 24, v9) )
      result = 4294967191LL;
    else
      result = 0;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
