__int64 __fastcall ieee80211_tdls_chandef_vht_upgrade(__int64 a1, __int64 a2)
{
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 result; // x0
  unsigned int v8; // w8
  unsigned int v9; // w21
  int v10; // w10
  int v11; // w9
  int v12; // w11
  int v13; // w11
  int v14; // w11
  int v15; // w11
  int v16; // w11
  bool v17; // nf
  int v18; // w11
  int v19; // w9
  _QWORD *v20; // x22
  __int64 v21; // x9
  unsigned int v22; // w8
  __int64 v23; // x0
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // [xsp+8h] [xbp-38h] BYREF
  __int64 v27; // [xsp+10h] [xbp-30h]
  __int64 v28; // [xsp+18h] [xbp-28h]
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+2Ch] [xbp-14h] BYREF
  char v31; // [xsp+34h] [xbp-Ch]
  __int16 v32; // [xsp+35h] [xbp-Bh]
  char v33; // [xsp+37h] [xbp-9h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 1344);
  v5 = *(_QWORD *)(a2 + 1352);
  v26 = *(_QWORD *)(a2 + 1336);
  v27 = v4;
  v6 = *(_QWORD *)(a2 + 1360);
  v28 = v5;
  v29 = v6;
  result = ieee80211_sta_cap_chan_bw(a2 + 1640);
  if ( (result & 0xFFFFFFFE) != 6 )
  {
    v8 = v27;
    v9 = (unsigned int)result >= 3 ? 3 : result;
    if ( (unsigned int)v27 < v9 )
    {
      v10 = 5210;
      v11 = *(_DWORD *)(v26 + 4);
      v12 = v11 - 5210;
      if ( v11 - 5210 < 0 )
        v12 = 5210 - v11;
      if ( v12 < 31 )
        goto LABEL_24;
      v10 = 5290;
      v13 = v11 - 5290;
      if ( v11 - 5290 < 0 )
        v13 = 5290 - v11;
      if ( v13 < 31 )
        goto LABEL_24;
      v10 = 5530;
      v14 = v11 - 5530;
      if ( v11 - 5530 < 0 )
        v14 = 5530 - v11;
      if ( v14 < 31 )
        goto LABEL_24;
      v10 = 5610;
      v15 = v11 - 5610;
      if ( v11 - 5610 < 0 )
        v15 = 5610 - v11;
      if ( v15 < 31 )
        goto LABEL_24;
      v10 = 5690;
      v16 = v11 - 5690;
      if ( v11 - 5690 < 0 )
        v16 = 5690 - v11;
      if ( v16 < 31 )
        goto LABEL_24;
      v10 = 5775;
      v18 = v11 - 5775;
      v17 = v11 - 5775 < 0;
      v19 = 5775 - v11;
      if ( !v17 )
        v19 = v18;
      if ( v19 > 30 )
      {
        if ( !HIDWORD(v27) )
          goto LABEL_36;
      }
      else
      {
LABEL_24:
        v8 = 3;
        HIDWORD(v27) = v10;
        LODWORD(v28) = 0;
        LODWORD(v27) = 3;
      }
      v20 = (_QWORD *)(a2 + 1336);
      while ( 1 )
      {
        if ( v8 <= v9 )
        {
          if ( v8 <= *(_DWORD *)(a2 + 1344) )
            break;
          v21 = *(_QWORD *)(a1 + 1616);
          v22 = *(_DWORD *)(a1 + 24);
          v31 = 1;
          v23 = *(_QWORD *)(v21 + 72);
          v30 = v22;
          v32 = 0;
          v33 = 0;
          result = cfg80211_reg_check_beaconing(v23, &v26, &v30);
          if ( (result & 1) != 0 )
            break;
        }
        result = ieee80211_chandef_downgrade(&v26, 0);
        v8 = v27;
      }
      if ( v26 != *v20
        || v27 != *(_QWORD *)(a2 + 1344)
        || WORD2(v29) != *(unsigned __int16 *)(a2 + 1364)
        || (_DWORD)v28 != *(_DWORD *)(a2 + 1352)
        || HIWORD(v29) != *(unsigned __int16 *)(a2 + 1366) )
      {
        v24 = v27;
        *v20 = v26;
        *(_QWORD *)(a2 + 1344) = v24;
        v25 = v29;
        *(_QWORD *)(a2 + 1352) = v28;
        *(_QWORD *)(a2 + 1360) = v25;
      }
    }
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
