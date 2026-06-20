__int64 __fastcall ieee80211_add_nan_func(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v6; // w21
  __int64 v7; // x21
  __int64 (__fastcall *v8)(__int64, __int64, __int64); // x9
  unsigned int v9; // w21
  __int64 v10; // x9
  __int64 v11; // x1

  if ( *(_DWORD *)(a2 + 4704) != 12 )
    return 4294967201LL;
  if ( (*(_QWORD *)(a2 + 1616) & 1) == 0 )
    return 4294967196LL;
  raw_spin_lock_bh(a2 + 2252);
  v6 = idr_alloc(a2 + 2256, a3, 1, (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a2 + 1600) + 170LL) + 1, 2080);
  raw_spin_unlock_bh(a2 + 2252);
  result = v6;
  if ( (v6 & 0x80000000) == 0 )
  {
    *(_BYTE *)(a3 + 98) = v6;
    if ( !(_BYTE)v6 )
      __break(0x800u);
    v7 = *(_QWORD *)(a2 + 1600);
    if ( (*(_BYTE *)(v7 + 1471) & 1) == 0
      && (*(_DWORD *)(a2 + 1608) & 0x20) == 0
      && (drv_add_nan_func___already_done & 1) == 0 )
    {
      v10 = *(_QWORD *)(a2 + 1592);
      drv_add_nan_func___already_done = 1;
      if ( v10 )
        v11 = v10 + 296;
      else
        v11 = a2 + 1624;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v11);
      __break(0x800u);
    }
    if ( *(_QWORD *)(*(_QWORD *)(v7 + 464) + 792LL) )
    {
      v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v7 + 464) + 792LL);
      if ( *((_DWORD *)v8 - 1) != -1628156260 )
        __break(0x8229u);
      result = v8(v7, a2 + 4704, a3);
      if ( !(_DWORD)result )
        return result;
    }
    else
    {
      LODWORD(result) = -95;
    }
    v9 = result;
    raw_spin_lock_bh(a2 + 2252);
    idr_remove(a2 + 2256, *(unsigned __int8 *)(a3 + 98));
    raw_spin_unlock_bh(a2 + 2252);
    return v9;
  }
  return result;
}
