_BYTE *__fastcall _ieee80211_beacon_add_tim(_QWORD *a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v4; // x24
  bool v9; // w23
  int v10; // w8
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x20
  bool v14; // w8
  __int64 v15; // x21
  __int64 lock; // x0
  unsigned int **v17; // x8
  __int64 v18; // x22
  _BYTE *result; // x0
  __int64 v20; // x8
  __int64 v21; // x9
  unsigned int v22; // w9
  unsigned int v23; // w10
  unsigned int v25; // w23
  const void *v26; // x21
  void *v27; // x0

  v4 = a1[118];
  if ( *(int *)(a2 + 280) < 1 )
  {
    v9 = 1;
    if ( (a4 & 1) != 0 )
      goto LABEL_8;
  }
  else
  {
    v9 = find_first_bit(a2, 2008) == 2008;
    if ( (a4 & 1) != 0 )
      goto LABEL_8;
  }
  v10 = *(_DWORD *)(a2 + 284);
  if ( !v10 )
    v10 = *(unsigned __int8 *)(v4 + 49);
  *(_DWORD *)(a2 + 284) = v10 - 1;
LABEL_8:
  v11 = skb_put(a3, 5);
  v13 = v11;
  *(_WORD *)v11 = 773;
  *(_BYTE *)(v11 + 2) = *(_DWORD *)(a2 + 284);
  *(_BYTE *)(v11 + 3) = *(_BYTE *)(v4 + 49);
  if ( *(_DWORD *)(a2 + 284) )
  {
    v14 = 0;
    *(_BYTE *)(a2 + 288) = 0;
    if ( v9 )
    {
LABEL_10:
      *(_BYTE *)(v11 + 4) = v14;
      v15 = *(_QWORD *)(*a1 + 1616LL);
      lock = _rcu_read_lock(v11, v12);
      v17 = *(unsigned int ***)(a1[118] + 832LL);
      if ( v17 )
      {
        v18 = **v17;
        result = (_BYTE *)_rcu_read_unlock(lock);
        if ( (unsigned int)v18 >= 6 )
        {
          __break(0x5512u);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          _ReadStatusReg(TPIDR_EL2);
          JUMPOUT(0xAB20C);
        }
        v20 = *(_QWORD *)(*(_QWORD *)(v15 + 72) + 8 * v18 + 328);
      }
      else
      {
        result = (_BYTE *)_rcu_read_unlock(lock);
        v20 = 0;
      }
      if ( *(_DWORD *)(v20 + 16) != 4 )
      {
        *(_BYTE *)(v13 + 1) = 4;
        result = (_BYTE *)skb_put(a3, 1);
        *result = 0;
      }
      return result;
    }
  }
  else
  {
    v14 = *(_QWORD *)(a2 + 256) != a2 + 256;
    *(_BYTE *)(a2 + 288) = v14;
    if ( v9 )
      goto LABEL_10;
  }
  v21 = 0;
  while ( !*(_BYTE *)(a2 + v21) )
  {
    if ( ++v21 == 251 )
    {
      v22 = 0;
      goto LABEL_19;
    }
  }
  v22 = v21 & 0xFE;
  v23 = v22;
  if ( v22 > 0xFA )
    goto LABEL_23;
LABEL_19:
  v23 = 250;
  while ( !*(_BYTE *)(a2 + v23) )
  {
    if ( v23-- <= v22 )
    {
      v23 = v22;
      break;
    }
  }
LABEL_23:
  v25 = v23 - v22;
  v26 = (const void *)(a2 + v22);
  *(_BYTE *)(v11 + 4) = v22 | v14;
  v27 = (void *)skb_put(a3, v23 - v22 + 1);
  result = memcpy(v27, v26, v25 + 1);
  *(_BYTE *)(v13 + 1) = v25 + 4;
  return result;
}
