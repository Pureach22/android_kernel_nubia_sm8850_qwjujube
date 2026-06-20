__int64 __fastcall ieee80211_ibss_finish_sta(__int64 a1)
{
  __int64 v1; // x19
  __int16 v2; // w9
  __int64 v3; // x20
  int v5; // [xsp+0h] [xbp-10h] BYREF
  __int16 v6; // [xsp+4h] [xbp-Ch]
  __int64 v7; // [xsp+8h] [xbp-8h]

  v1 = a1;
  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_WORD *)(a1 + 2692);
  v3 = *(_QWORD *)(a1 + 80);
  v5 = *(_DWORD *)(a1 + 2688);
  v6 = v2;
  if ( (*(_QWORD *)(a1 + 216) & 0x100000) != 0 )
    __break(0x800u);
  if ( (unsigned int)sta_info_move_state(a1, 2) )
  {
    __break(0x800u);
    if ( (*(_QWORD *)(v1 + 216) & 0x100000) == 0 )
      goto LABEL_5;
  }
  else if ( (*(_QWORD *)(v1 + 216) & 0x100000) == 0 )
  {
    goto LABEL_5;
  }
  __break(0x800u);
LABEL_5:
  if ( (unsigned int)sta_info_move_state(v1, 3) )
    __break(0x800u);
  if ( (*(_BYTE *)(*(_QWORD *)(v1 + 80) + 2343LL) & 1) == 0 )
  {
    if ( (*(_QWORD *)(v1 + 216) & 0x100000) != 0 )
      __break(0x800u);
    if ( (unsigned int)sta_info_move_state(v1, 4) )
      __break(0x800u);
  }
  rate_control_rate_init(v1);
  if ( (unsigned int)sta_info_insert_rcu(v1) )
    v1 = sta_info_get(v3, &v5);
  _ReadStatusReg(SP_EL0);
  return v1;
}
