__int64 __fastcall ieee80211_set_monitor_channel(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x9
  __int64 v8; // x20
  __int64 result; // x0
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // [xsp+8h] [xbp-48h] BYREF
  __int64 v15; // [xsp+10h] [xbp-40h]
  __int64 v16; // [xsp+18h] [xbp-38h]
  __int64 v17; // [xsp+20h] [xbp-30h]
  __int64 v18; // [xsp+28h] [xbp-28h]
  __int64 v19; // [xsp+30h] [xbp-20h]
  __int64 v20; // [xsp+38h] [xbp-18h]
  __int64 v21; // [xsp+40h] [xbp-10h]
  __int64 v22; // [xsp+48h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *a2;
    v3 = a2[1];
    v5 = a2[2];
    v6 = a2[3];
    v18 = 0;
    v19 = 0;
    v20 = 0;
    v21 = 0;
    v14 = v2;
    v15 = v3;
    v7 = *(_QWORD *)(a1 + 6928);
    v16 = v5;
    v17 = v6;
    if ( v7 == v2
      && *(_DWORD *)(a1 + 6936) == (_DWORD)v15
      && *(_DWORD *)(a1 + 6940) == HIDWORD(v15)
      && *(unsigned __int16 *)(a1 + 6956) == WORD2(v17)
      && *(_DWORD *)(a1 + 6944) == (_DWORD)v16
      && *(unsigned __int16 *)(a1 + 6958) == HIWORD(v17) )
    {
      goto LABEL_15;
    }
    v8 = *(_QWORD *)(a1 + 6920);
    if ( v8 )
    {
      if ( *(_QWORD *)(v8 + 4944) == v2
        && *(_DWORD *)(v8 + 4952) == (_DWORD)v15
        && *(_DWORD *)(v8 + 4956) == HIDWORD(v15)
        && *(unsigned __int16 *)(v8 + 4972) == WORD2(v17)
        && *(_DWORD *)(v8 + 4960) == (_DWORD)v16
        && *(unsigned __int16 *)(v8 + 4974) == HIWORD(v17) )
      {
LABEL_15:
        result = 0;
LABEL_18:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      ieee80211_link_release_channel(v8 + 3616);
      result = ieee80211_link_use_channel(v8 + 3616, &v14, 1, 0);
      if ( (_DWORD)result )
        goto LABEL_18;
    }
    v10 = v19;
    result = 0;
    *(_QWORD *)(a1 + 6960) = v18;
    *(_QWORD *)(a1 + 6968) = v10;
    v11 = v21;
    *(_QWORD *)(a1 + 6976) = v20;
    *(_QWORD *)(a1 + 6984) = v11;
    v12 = v15;
    *(_QWORD *)(a1 + 6928) = v14;
    *(_QWORD *)(a1 + 6936) = v12;
    v13 = v17;
    *(_QWORD *)(a1 + 6944) = v16;
    *(_QWORD *)(a1 + 6952) = v13;
    goto LABEL_18;
  }
  __break(0x800u);
  return ieee80211_scan();
}
