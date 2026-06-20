__int64 __fastcall _ieee80211_request_smps_mgd(__int64 a1, __int64 a2, unsigned int a3)
{
  int v3; // w8
  __int64 result; // x0
  int v5; // w20
  unsigned int v6; // w19
  __int64 lock; // x0
  __int64 v10; // x10
  __int64 *v11; // x9
  __int64 *v12; // x10
  __int64 v13; // x0
  char v14; // w24
  unsigned int v15; // w8
  __int64 v16; // x8
  __int64 v17; // x4
  char v18; // w8

  if ( *(_DWORD *)(a1 + 4720) == 2 )
  {
    v3 = *(_DWORD *)(a2 + 8);
    if ( *(_WORD *)(a1 + 5800) )
    {
      if ( (((unsigned __int64)*(unsigned __int16 *)(a1 + 5802) >> v3) & 1) == 0 )
        return 0;
    }
    else if ( v3 )
    {
      return 0;
    }
    v5 = *(_DWORD *)(a2 + 544);
    *(_DWORD *)(a2 + 544) = a3;
    if ( (*(_BYTE *)(a1 + 5872) & 0x10) != 0
      || a3 && v5 == a3
      || (*(_BYTE *)(a1 + 2477) & 8) == 0
      || !*(_DWORD *)(*(_QWORD *)(a2 + 944) + 144LL) )
    {
      return 0;
    }
    v6 = a3;
    lock = _rcu_read_lock(a1, a2);
    v10 = *(_QWORD *)(a1 + 1616);
    v11 = *(__int64 **)(v10 + 1616);
    v12 = (__int64 *)(v10 + 1616);
    if ( v11 == v12 )
    {
LABEL_21:
      _rcu_read_unlock(lock);
      v15 = v6;
      v14 = 0;
      if ( !v6 )
        v6 = 1;
      if ( v15 )
      {
        v16 = a2;
        v13 = a1;
        if ( !*(_WORD *)(a1 + 5800) )
        {
LABEL_30:
          v17 = 0xFFFFFFFFLL;
          goto LABEL_31;
        }
LABEL_25:
        v17 = *(unsigned int *)(v16 + 8);
LABEL_31:
        result = ieee80211_send_smps_action(v13, v6, v13 + 4802, v13 + 4802, v17);
        if ( (_DWORD)result )
        {
          *(_DWORD *)(a2 + 544) = v5;
          return result;
        }
        v18 = v14 ^ 1;
        if ( v6 == 1 )
          v18 = 1;
        if ( (v18 & 1) == 0 )
          ieee80211_teardown_tdls_peers(a2);
        return 0;
      }
      v13 = a1;
      if ( *(_BYTE *)(a1 + 2496) )
        v6 = 3;
      else
        v6 = 1;
    }
    else
    {
      while ( *((_BYTE *)v11 + 2712) != 1 || v11[10] != a1 || *((_BYTE *)v11 + 204) != 1 || (v11[27] & 8) == 0 )
      {
        v11 = (__int64 *)*v11;
        if ( v11 == v12 )
          goto LABEL_21;
      }
      _rcu_read_unlock(lock);
      v13 = a1;
      v14 = 1;
      if ( !v6 )
        v6 = 1;
    }
    v16 = a2;
    if ( !*(_WORD *)(v13 + 5800) )
      goto LABEL_30;
    goto LABEL_25;
  }
  __break(0x800u);
  return 4294967274LL;
}
