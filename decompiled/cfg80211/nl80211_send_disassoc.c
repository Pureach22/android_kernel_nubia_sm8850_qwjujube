__int64 __fastcall nl80211_send_disassoc(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5, unsigned int a6)
{
  __int64 result; // x0
  _QWORD v7[3]; // [xsp+0h] [xbp-40h] BYREF
  int v8; // [xsp+18h] [xbp-28h]
  __int64 v9; // [xsp+1Ch] [xbp-24h]
  __int64 v10; // [xsp+24h] [xbp-1Ch]
  int v11; // [xsp+2Ch] [xbp-14h]
  char v12; // [xsp+30h] [xbp-10h]
  _BYTE v13[7]; // [xsp+31h] [xbp-Fh] BYREF
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 40;
  v7[1] = a3;
  v7[2] = a4;
  v8 = -1;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = a5;
  memset(v13, 0, sizeof(v13));
  result = nl80211_send_mlme_event(a1, a2, (unsigned int *)v7, a6);
  _ReadStatusReg(SP_EL0);
  return result;
}
