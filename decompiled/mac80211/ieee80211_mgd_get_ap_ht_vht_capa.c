__int64 __fastcall ieee80211_mgd_get_ap_ht_vht_capa(__int64 unlock, __int64 a2, __int64 a3)
{
  unsigned int ***v3; // x20
  __int64 v4; // x19
  __int64 v5; // x21
  __int64 v7; // x22
  __int64 elem; // x0
  unsigned int v9; // w19
  bool v10; // zf
  unsigned int **v11; // x9

  if ( (unsigned int)a3 >= 0xF )
    goto LABEL_22;
  v3 = (unsigned int ***)(a2 + ((unsigned __int64)(unsigned int)a3 << 6));
  v4 = (__int64)*v3;
  v5 = ***v3;
  if ( (_DWORD)v5 == 3 || *((_DWORD *)v3 + 12) < 2u )
    return 0;
  v7 = unlock;
  _rcu_read_lock(unlock, a2);
  elem = ieee80211_bss_get_elem(v4, 61);
  if ( !elem || *(unsigned __int8 *)(elem + 1) < 0x16u )
    goto LABEL_8;
  *((_BYTE *)v3 + 14) = *(_BYTE *)(elem + 3);
  unlock = _rcu_read_unlock(elem);
  if ( *((_DWORD *)v3 + 12) >= 3u )
  {
    if ( (unsigned int)v5 <= 5 )
    {
      if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 1616) + 72LL) + 8 * v5 + 328) + 52LL) == 1 )
      {
        _rcu_read_lock(unlock, a2);
        elem = ieee80211_bss_get_elem(v4, 191);
        if ( elem )
          v10 = 0;
        else
          v10 = (_DWORD)v5 == 0;
        if ( v10 )
          v9 = 0;
        else
          v9 = -22;
        if ( !elem )
          goto LABEL_9;
        if ( *(unsigned __int8 *)(elem + 1) >= 0xCu )
        {
          v11 = *(unsigned int ***)(elem + 2);
          v9 = 0;
          *(_DWORD *)((char *)v3 + 23) = *(_DWORD *)(elem + 10);
          *(unsigned int ***)((char *)v3 + 15) = v11;
          goto LABEL_9;
        }
LABEL_8:
        v9 = -22;
LABEL_9:
        _rcu_read_unlock(elem);
        return v9;
      }
      return 0;
    }
LABEL_22:
    __break(0x5512u);
    return ieee80211_setup_assoc_link(unlock, a2, a3);
  }
  return 0;
}
