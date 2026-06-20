__int64 __fastcall ieee80211_txq_remove_vlan(__int64 result, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // x19
  __int64 *v4; // x23
  __int64 *i; // x25
  __int64 **v6; // x21
  __int64 *v7; // x27
  __int64 *v8; // x8
  __int64 **v9; // x9
  __int64 *v10; // x22
  __int64 *j; // x24
  __int64 *v12; // t1
  __int64 **v13; // x21
  __int64 *v14; // x26
  __int64 *v15; // x8
  __int64 **v16; // x9

  if ( *(_DWORD *)(a2 + 4720) == 4 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)(a2 + 2032) + 3592LL);
    if ( v2 )
    {
      v3 = result;
      v4 = (__int64 *)(a2 + 4720);
      raw_spin_lock_bh(result + 240);
      for ( i = *(__int64 **)(v2 - 232); i != (__int64 *)(v2 - 232); i = (__int64 *)*i )
      {
        v6 = (__int64 **)i[2];
        if ( v6 != (__int64 **)(i + 2) )
        {
          do
          {
            v7 = *v6;
            if ( v6[8] == v4 )
            {
              --*((_DWORD *)i + 8);
              v8 = *v6;
              v9 = (__int64 **)v6[1];
              *v6 = nullptr;
              v6[1] = nullptr;
              v8[1] = (__int64)v9;
              *v9 = v8;
              fq_adjust_removal(v3 + 208, i - 1, v6);
              ieee80211_free_txskb(v3, (__int64)v6);
            }
            v6 = (__int64 **)v7;
          }
          while ( v7 != i + 2 );
        }
      }
      v12 = *(__int64 **)(v2 - 216);
      v10 = (__int64 *)(v2 - 216);
      for ( j = v12; j != v10; j = (__int64 *)*j )
      {
        v13 = (__int64 **)j[2];
        if ( v13 != (__int64 **)(j + 2) )
        {
          do
          {
            v14 = *v13;
            if ( v13[8] == v4 )
            {
              --*((_DWORD *)j + 8);
              v15 = *v13;
              v16 = (__int64 **)v13[1];
              *v13 = nullptr;
              v13[1] = nullptr;
              v15[1] = (__int64)v16;
              *v16 = v15;
              fq_adjust_removal(v3 + 208, j - 1, v13);
              ieee80211_free_txskb(v3, (__int64)v13);
            }
            v13 = (__int64 **)v14;
          }
          while ( v14 != j + 2 );
        }
      }
      return raw_spin_unlock_bh(v3 + 240);
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
