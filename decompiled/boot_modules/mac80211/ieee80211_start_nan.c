__int64 __fastcall ieee80211_start_nan(__int64 a1, __int64 a2, _WORD *a3)
{
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v7; // x22
  _DWORD *v8; // x8
  unsigned int v9; // w22
  __int64 v10; // x9
  __int64 v11; // x1

  v3 = a2 - 16;
  result = ieee80211_check_combinations(a2 - 16, 0, 0, 0, 0xFFFFFFFFLL);
  if ( (result & 0x80000000) == 0 )
  {
    result = ieee80211_do_open(a2, 1);
    if ( !(_DWORD)result )
    {
      v7 = *(_QWORD *)(a2 + 1600);
      if ( (*(_BYTE *)(v7 + 1471) & 1) == 0
        && (*(_DWORD *)(a2 + 1608) & 0x20) == 0
        && (drv_start_nan___already_done & 1) == 0 )
      {
        v10 = *(_QWORD *)(a2 + 1592);
        drv_start_nan___already_done = 1;
        if ( v10 )
          v11 = v10 + 296;
        else
          v11 = a2 + 1624;
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v11);
        __break(0x800u);
      }
      v8 = *(_DWORD **)(*(_QWORD *)(v7 + 464) + 768LL);
      if ( *(v8 - 1) != -798033652 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _WORD *))v8)(v7, a2 + 4704, a3);
      if ( (_DWORD)result )
      {
        v9 = result;
        ieee80211_sdata_stop(v3);
        result = v9;
      }
      *(_WORD *)(a2 + 2248) = *a3;
    }
  }
  return result;
}
