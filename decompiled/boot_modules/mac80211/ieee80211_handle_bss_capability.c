__int64 __fastcall ieee80211_handle_bss_capability(_QWORD *a1, __int64 a2, char a3, unsigned int a4)
{
  _BYTE *v4; // x23
  unsigned __int16 v8; // w21
  __int64 v9; // x24
  __int64 lock; // x0
  unsigned int **v11; // x8
  __int64 v12; // x22
  __int64 unlock; // x0
  __int64 v14; // x11
  int v15; // w10
  int v16; // w8
  __int64 result; // x0
  int v18; // w11
  int v20; // w9

  v4 = (_BYTE *)a1[118];
  v8 = a2;
  v9 = *(_QWORD *)(*a1 + 1616LL);
  lock = _rcu_read_lock(a1, a2);
  v11 = *(unsigned int ***)(a1[118] + 832LL);
  if ( !v11 )
  {
    _rcu_read_unlock(lock);
    return 0;
  }
  v12 = **v11;
  unlock = _rcu_read_unlock(lock);
  if ( (unsigned int)v12 >= 6 )
  {
    __break(0x5512u);
    return ieee80211_recalc_twt_req(unlock);
  }
  v14 = *(_QWORD *)(*(_QWORD *)(v9 + 72) + 8 * v12 + 328);
  if ( !v14 )
    return 0;
  if ( (a3 & 1) != 0 )
  {
    v15 = (a4 >> 1) & 1;
    v16 = (a4 & 4) == 0;
  }
  else
  {
    v16 = (v8 >> 5) & 1;
    v15 = 0;
  }
  v18 = *(_DWORD *)(v14 + 16);
  if ( v18 == 1 || v18 == 3 )
    v20 = 1;
  else
    v20 = (v8 >> 10) & 1;
  if ( (unsigned __int8)v4[45] == v15 )
  {
    result = 0;
  }
  else
  {
    result = 2;
    v4[45] = v15;
  }
  if ( (unsigned __int8)v4[46] != v16 )
  {
    result |= 4uLL;
    v4[46] = v16;
  }
  if ( (unsigned __int8)v4[47] != v20 )
  {
    result |= 8uLL;
    v4[47] = v20;
  }
  return result;
}
