void __fastcall ieee80211_del_nan_func(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 next; // x0
  unsigned int v6; // w21
  __int64 v7; // x20
  _DWORD *v8; // x8
  __int64 v9; // x9
  __int64 v10; // x1
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 4704) == 12 && (*(_QWORD *)(a2 + 1616) & 1) != 0 )
  {
    raw_spin_lock_bh(a2 + 2252);
    v11 = 0;
    next = idr_get_next(a2 + 2256, &v11);
    if ( next )
    {
      while ( *(_QWORD *)(next + 104) != a3 )
      {
        ++v11;
        next = idr_get_next(a2 + 2256, &v11);
        if ( !next )
          goto LABEL_6;
      }
      v6 = *(unsigned __int8 *)(next + 98);
      raw_spin_unlock_bh(a2 + 2252);
      if ( v6 )
      {
        v7 = *(_QWORD *)(a2 + 1600);
        if ( (*(_BYTE *)(v7 + 1471) & 1) == 0
          && (*(_DWORD *)(a2 + 1608) & 0x20) == 0
          && (drv_del_nan_func___already_done & 1) == 0 )
        {
          v9 = *(_QWORD *)(a2 + 1592);
          drv_del_nan_func___already_done = 1;
          if ( v9 )
            v10 = v9 + 296;
          else
            v10 = a2 + 1624;
          _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v10);
          __break(0x800u);
        }
        v8 = *(_DWORD **)(*(_QWORD *)(v7 + 464) + 800LL);
        if ( v8 )
        {
          if ( *(v8 - 1) != 1723173787 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v8)(v7, a2 + 4704, v6);
        }
      }
    }
    else
    {
LABEL_6:
      raw_spin_unlock_bh(a2 + 2252);
    }
  }
  _ReadStatusReg(SP_EL0);
}
