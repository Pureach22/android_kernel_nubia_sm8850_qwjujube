__int64 __fastcall nl80211_tdls_channel_switch(__int64 a1, _QWORD *a2)
{
  _BYTE *v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  int v5; // w8
  __int64 v6; // x8
  __int64 result; // x0
  unsigned int v9; // w8
  _DWORD *v10; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+10h] [xbp-30h]
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+2Ch] [xbp-14h] BYREF
  char v15; // [xsp+34h] [xbp-Ch]
  __int16 v16; // [xsp+35h] [xbp-Bh]
  char v17; // [xsp+37h] [xbp-9h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_BYTE *)a2[6];
  v3 = a2[7];
  v12 = 0;
  v13 = 0;
  v10 = nullptr;
  v11 = 0;
  v4 = *(_QWORD *)(v3 + 992);
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 768LL) || (v2[1103] & 0x10) == 0 || (v5 = *(_DWORD *)(v4 + 8), v5 != 8) && v5 != 2 )
  {
    result = 4294967201LL;
    goto LABEL_14;
  }
  v6 = a2[4];
  if ( !*(_QWORD *)(v6 + 48) || !*(_QWORD *)(v6 + 1712) )
    goto LABEL_12;
  result = nl80211_parse_chandef((__int64)v2, (__int64)a2, 0, (__int64)&v10);
  if ( !(_DWORD)result )
  {
    if ( *v10 || (unsigned int)v11 <= 1 )
    {
      v9 = *(_DWORD *)(v4 + 8);
      v15 = 1;
      v14 = v9;
      v16 = 0;
      v17 = 0;
      if ( (cfg80211_reg_check_beaconing((__int64)(v2 + 992), (__int64)&v10, (unsigned int *)&v14) & 1) != 0
        && !(unsigned int)((__int64 (__fastcall *)(_QWORD, _DWORD **, _QWORD))cfg80211_chandef_dfs_required)(
                            *(_QWORD *)v4,
                            &v10,
                            *(unsigned int *)(v4 + 8)) )
      {
        result = rdev_tdls_channel_switch(
                   v2,
                   v3,
                   *(_QWORD *)(a2[4] + 48LL) + 4LL,
                   *(unsigned __int8 *)(*(_QWORD *)(a2[4] + 1712LL) + 4LL),
                   &v10);
        goto LABEL_14;
      }
    }
LABEL_12:
    result = 4294967274LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
