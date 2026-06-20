__int64 __fastcall rate_control_rate_update(__int64 result, __int64 a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 v5; // x21
  _QWORD *v6; // x25
  __int64 v10; // x24
  __int64 lock; // x0
  __int64 v12; // x23
  __int64 v13; // x0
  _DWORD *v14; // x8
  __int64 v15; // x0

  v5 = *(_QWORD *)(a3 + 136);
  v6 = *(_QWORD **)(result + 2536);
  if ( a4 )
  {
    __break(0x800u);
    if ( !v6 )
      goto LABEL_8;
  }
  else if ( !v6 )
  {
    goto LABEL_8;
  }
  if ( *(_QWORD *)(*v6 + 56LL) )
  {
    v10 = result;
    lock = _rcu_read_lock(result, a2);
    v12 = *(_QWORD *)(*(_QWORD *)(a3 + 80) + 5640LL);
    if ( !v12 )
    {
      __break(0x800u);
      return _rcu_read_unlock(lock);
    }
    raw_spin_lock_bh(a3 + 144);
    v13 = v6[1];
    v14 = *(_DWORD **)(*v6 + 56LL);
    if ( *(v14 - 1) != -775542235 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, _QWORD))v14)(v13, a2, v12, a3 + 2688, v5, a5);
    v15 = raw_spin_unlock_bh(a3 + 144);
    _rcu_read_unlock(v15);
    result = v10;
  }
LABEL_8:
  if ( *(_BYTE *)(a3 + 204) == 1 )
    return drv_sta_rc_update(result, *(_QWORD *)(a3 + 80), a3 + 2688, a5);
  return result;
}
