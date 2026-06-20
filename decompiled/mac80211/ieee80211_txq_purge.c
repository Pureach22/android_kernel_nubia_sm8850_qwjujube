__int64 __fastcall ieee80211_txq_purge(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x21
  _QWORD *v5; // x8
  __int64 v6; // x0
  unsigned __int64 v7; // x8
  __int64 v8; // x20
  _QWORD *v9; // x8
  __int64 *v10; // x9
  __int64 v11; // x10
  unsigned __int64 v12; // x8

  raw_spin_lock_bh(a1 + 240);
  v4 = (_QWORD *)(a2 + 16);
  while ( 1 )
  {
    v5 = *(_QWORD **)a2;
    if ( *(_QWORD *)a2 == a2 )
    {
      v5 = (_QWORD *)*v4;
      if ( (_QWORD *)*v4 == v4 )
        break;
    }
    fq_flow_reset(a1 + 208, v5 - 1);
  }
  if ( *(_QWORD *)(a2 + 32) == a2 + 32 )
  {
    if ( !*(_DWORD *)(a2 + 104) )
      goto LABEL_7;
LABEL_16:
    __break(0x800u);
    if ( !*(_DWORD *)(a2 + 108) )
      goto LABEL_8;
LABEL_17:
    __break(0x800u);
    goto LABEL_8;
  }
  __break(0x800u);
  if ( *(_DWORD *)(a2 + 104) )
    goto LABEL_16;
LABEL_7:
  if ( *(_DWORD *)(a2 + 108) )
    goto LABEL_17;
LABEL_8:
  ieee80211_purge_tx_queue(a1, a2 + 200);
  v6 = raw_spin_unlock_bh(a1 + 240);
  v7 = *(unsigned __int8 *)(a2 + 249);
  if ( v7 < 5 )
  {
    v8 = a1 + 308;
    v6 = raw_spin_lock_bh(v8 + 4 * v7);
    v9 = *(_QWORD **)(a2 + 192);
    v10 = (__int64 *)(a2 + 184);
    if ( *v9 == a2 + 184 && (v11 = *v10, *(__int64 **)(*v10 + 8) == v10) )
    {
      *(_QWORD *)(v11 + 8) = v9;
      *v9 = v11;
    }
    else
    {
      v6 = _list_del_entry_valid_or_report(a2 + 184);
    }
    *(_QWORD *)(a2 + 184) = a2 + 184;
    *(_QWORD *)(a2 + 192) = v10;
    v12 = *(unsigned __int8 *)(a2 + 249);
    if ( v12 <= 4 )
      return raw_spin_unlock_bh(v8 + 4 * v12);
  }
  __break(0x5512u);
  return ieee80211_txq_set_params(v6);
}
