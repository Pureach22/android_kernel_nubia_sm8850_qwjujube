__int64 __fastcall ieee80211_txq_schedule_start(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  char v5; // w20
  __int64 v6; // x19
  __int64 v7; // x22
  _DWORD *v8; // x21
  __int64 v9; // x8
  __int16 v10; // w9
  _WORD *v11; // x8
  int v12; // w8
  _QWORD *v13; // x10
  bool v14; // cf
  __int16 v15; // w9

  if ( (unsigned __int8)a2 < 5u )
  {
    v5 = a2;
    v6 = a1;
    v7 = (unsigned __int8)a2;
    v8 = (_DWORD *)(a1 + 4LL * (unsigned __int8)a2);
    a1 = raw_spin_lock_bh(v8 + 77);
    if ( (*(_BYTE *)(*(_QWORD *)(v6 + 72) + 117LL) & 1) != 0 )
    {
      v12 = -2;
      v13 = (_QWORD *)(v6 + 16 * v7 + 328);
      do
      {
        v13 = (_QWORD *)*v13;
        ++v12;
      }
      while ( v13 != (_QWORD *)(v6 + 16 * v7 + 328) );
      if ( v5 != 4 )
      {
        v14 = v8[112] >= v8[106] + ((unsigned int)(v8[102] * v12) >> 1);
        v11 = (_WORD *)(v6 + 2 * v7 + 392);
        if ( v14 )
        {
          *v11 = 0;
          return raw_spin_unlock_bh(v8 + 77);
        }
        v15 = *v11 + 1;
        *v11 = v15;
        if ( !v15 )
          goto LABEL_11;
        return raw_spin_unlock_bh(v8 + 77);
      }
    }
    else
    {
      v9 = v6 + 2 * v7;
      v10 = *(_WORD *)(v9 + 392) + 1;
      *(_WORD *)(v9 + 392) = v10;
      if ( v5 != 4 )
      {
        v11 = (_WORD *)(v9 + 392);
        if ( !v10 )
LABEL_11:
          *v11 = 1;
        return raw_spin_unlock_bh(v8 + 77);
      }
    }
  }
  __break(0x5512u);
  return _ieee80211_subif_start_xmit(a1, a2, a3, a4, a5);
}
