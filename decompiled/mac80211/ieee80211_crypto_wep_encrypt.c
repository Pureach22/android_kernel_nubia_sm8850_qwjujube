__int64 __fastcall ieee80211_crypto_wep_encrypt(_QWORD *a1)
{
  _QWORD *i; // x20
  __int64 v3; // x8

  ieee80211_tx_set_protected((__int64)a1);
  for ( i = (_QWORD *)a1[1]; i != a1 + 1; i = (_QWORD *)*i )
  {
    v3 = i[9];
    if ( v3 )
    {
      if ( (*(_WORD *)(v3 + 16) & 0x22) != 0
        && !ieee80211_wep_add_iv(a1[4], (__int64)i, *(unsigned __int8 *)(a1[7] + 555LL), *(_BYTE *)(a1[7] + 551LL)) )
      {
        return 1;
      }
    }
    else if ( (unsigned int)ieee80211_wep_encrypt(
                              a1[4],
                              (__int64)i,
                              (const void *)(a1[7] + 556LL),
                              *(unsigned __int8 *)(a1[7] + 555LL),
                              *(char *)(a1[7] + 551LL)) )
    {
      return 1;
    }
  }
  return 0;
}
