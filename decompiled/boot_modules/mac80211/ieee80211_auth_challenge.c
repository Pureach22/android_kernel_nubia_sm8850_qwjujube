__int64 __fastcall ieee80211_auth_challenge(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w9
  __int64 result; // x0
  __int64 v8; // x20
  int v9; // w9
  char v10; // [xsp+8h] [xbp-38h]
  char v11; // [xsp+10h] [xbp-30h]
  __int64 v12; // [xsp+2Ch] [xbp-14h] BYREF
  int v13; // [xsp+34h] [xbp-Ch]
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 2480);
  v5 = *(_QWORD *)(a1 + 1616);
  v12 = 0;
  v6 = *(_DWORD *)(v4 + 44);
  WORD1(v12) = 176;
  v13 = v6;
  result = cfg80211_find_elem_match(16, a2 + 30, (unsigned int)(a3 - 30), 0, 0, 0);
  if ( result )
  {
    v8 = result;
    *(_WORD *)(v4 + 22) = 4;
    drv_mgd_prepare_tx(*(_QWORD *)(a1 + 1616), a1, (__int64)&v12);
    if ( (*(_QWORD *)(v5 + 96) & 0x10000LL) != 0 )
      v9 = 1048577;
    else
      v9 = 0;
    v11 = *(_BYTE *)(v4 + 38);
    v10 = *(_BYTE *)(v4 + 37);
    result = ieee80211_send_auth(
               a1,
               3,
               *(unsigned __int16 *)(v4 + 20),
               0,
               v8,
               *(unsigned __int8 *)(v8 + 1) + 2LL,
               v4 + 48,
               v4 + 48,
               v4 + 24,
               v10,
               v11,
               v9);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
