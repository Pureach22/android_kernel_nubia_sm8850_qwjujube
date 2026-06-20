__int64 __fastcall ieee80211_tx_prepare_skb(__int64 a1, __int64 a2, __int64 a3, char a4, _QWORD *a5)
{
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  int v14; // w8
  unsigned __int64 v15; // x9
  unsigned int v16; // w8
  __int64 v17; // x8
  _QWORD *v18; // x8
  __int64 *v19; // x1
  __int64 v20; // x8
  _QWORD *v21; // x9
  __int64 result; // x0
  __int64 v23; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v24[2]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v25; // [xsp+18h] [xbp-38h]
  __int64 v26; // [xsp+20h] [xbp-30h]
  __int64 v27; // [xsp+28h] [xbp-28h]
  __int64 v28; // [xsp+30h] [xbp-20h]
  __int64 v29; // [xsp+38h] [xbp-18h]
  __int64 v30; // [xsp+40h] [xbp-10h]
  __int64 v31; // [xsp+48h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v24[0] = 0;
  v24[1] = 0;
  v23 = 0;
  v10 = ieee80211_tx_prepare(a2 - 4720, &v23, 0, a3);
  if ( (_DWORD)v10 == 1 )
    goto LABEL_19;
  v14 = *(_DWORD *)(a3 + 44);
  v15 = *(unsigned __int16 *)(a3 + 124);
  *(_QWORD *)(a3 + 64) = a2;
  v16 = v14 & 0xFFFFFFF8 | a4 & 7;
  *(_DWORD *)(a3 + 44) = v16;
  if ( v15 < 4 )
  {
    *(_DWORD *)(a3 + 44) = v16 & 0xFFE1FFFF | ((*(_BYTE *)(a2 + v15 + 1130) & 0xF) << 17);
    if ( !(unsigned int)invoke_tx_handlers_early(&v23) && !(unsigned int)invoke_tx_handlers_late(&v23) )
    {
      if ( a5 )
      {
        if ( v28 )
          v17 = v28 + 2688;
        else
          v17 = 0;
        *a5 = v17;
      }
      v18 = (_QWORD *)v24[0];
      if ( (_QWORD *)v24[0] == v24 )
        v19 = nullptr;
      else
        v19 = (__int64 *)v24[0];
      if ( v19 )
      {
        LODWORD(v25) = v25 - 1;
        v20 = *v19;
        v21 = (_QWORD *)v19[1];
        *v19 = 0;
        v19[1] = 0;
        *(_QWORD *)(v20 + 8) = v21;
        *v21 = v20;
        v18 = (_QWORD *)v24[0];
      }
      if ( v19 == (__int64 *)a3 && v18 == v24 )
      {
        result = 1;
LABEL_20:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      __break(0x800u);
      ieee80211_free_txskb(a1, (__int64)v19);
      ieee80211_purge_tx_queue(a1, (__int64)v24);
    }
LABEL_19:
    result = 0;
    goto LABEL_20;
  }
  __break(0x5512u);
  return ieee80211_tx_prepare(v10, v11, v12, v13);
}
