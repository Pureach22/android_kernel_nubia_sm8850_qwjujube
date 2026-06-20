__int64 __fastcall sta_set_rate_info_tx(__int64 result, char *a2, __int64 a3)
{
  int v3; // w8
  __int64 v4; // x22
  char *v5; // x19
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 lock; // x0
  unsigned int **v9; // x8
  __int64 v10; // x22
  __int64 v11; // x3
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned int v14; // w8
  char v15; // w8

  *(_WORD *)a3 = 0;
  v3 = *(unsigned __int16 *)(a2 + 1) >> 5;
  if ( (v3 & 8) != 0 )
  {
    *(_WORD *)a3 = 1;
    *(_BYTE *)(a3 + 4) = *a2;
    goto LABEL_13;
  }
  if ( (v3 & 0x100) != 0 )
  {
    *(_WORD *)a3 = 2;
    *(_BYTE *)(a3 + 4) = *a2 & 0xF;
    *(_BYTE *)(a3 + 5) = ((unsigned int)*a2 >> 4) + 1;
    goto LABEL_13;
  }
  v4 = *(_QWORD *)(result + 80);
  v5 = a2;
  v6 = a3;
  v7 = *(_QWORD *)(v4 + 1616);
  if ( *(_WORD *)(v4 + 5800) )
    __break(0x800u);
  lock = _rcu_read_lock();
  v9 = *(unsigned int ***)(v4 + 5640);
  if ( !v9 )
  {
    result = _rcu_read_unlock(lock);
    a3 = v6;
    a2 = v5;
    goto LABEL_13;
  }
  v10 = **v9;
  result = _rcu_read_unlock(lock);
  if ( (unsigned int)v10 < 6 )
  {
    a3 = v6;
    a2 = v5;
    v12 = *(_QWORD *)(*(_QWORD *)(v7 + 72) + 8 * v10 + 328);
    if ( v12 )
    {
      v13 = *(_QWORD *)(v12 + 8);
      if ( v13 || (__break(0x800u), (v13 = *(_QWORD *)(v12 + 8)) != 0) )
        *(_WORD *)(v6 + 2) = *(_WORD *)(v13 + 12LL * *v5 + 4);
    }
LABEL_13:
    v14 = *(unsigned __int16 *)(a2 + 1);
    if ( ((v14 >> 5) & 0x20) != 0 )
    {
      v15 = 3;
    }
    else if ( ((v14 >> 5) & 0x200) != 0 )
    {
      v15 = 4;
    }
    else
    {
      if ( ((__int16)v14 & 0x80000000) == 0 )
      {
        *(_BYTE *)(a3 + 6) = 0;
        if ( (*(_WORD *)(a2 + 1) & 0x1000) == 0 )
          return result;
LABEL_22:
        *(_WORD *)a3 |= 4u;
        return result;
      }
      v15 = 5;
    }
    *(_BYTE *)(a3 + 6) = v15;
    if ( (*(_WORD *)(a2 + 1) & 0x1000) == 0 )
      return result;
    goto LABEL_22;
  }
  __break(0x5512u);
  if ( (v11 & 0x2000000000000000LL) == 0 )
    JUMPOUT(0x32E4C);
  return _ieee80211_request_smps_mgd(result);
}
