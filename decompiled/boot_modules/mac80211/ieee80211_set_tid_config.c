__int64 __fastcall ieee80211_set_tid_config(__int64 a1, __int64 a2, _QWORD *a3)
{
  _DWORD *v3; // x9
  __int64 (*v5)(void); // x9
  __int64 v7; // x0
  __int64 v8; // x1

  v3 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a2 + 4304) + 464LL) + 840LL);
  if ( !v3 )
    return 4294967201LL;
  if ( *a3 )
  {
    if ( sta_info_get_bss(a2 + 2688, *a3) )
    {
      v5 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a2 + 4304) + 464LL) + 840LL);
      if ( *((_DWORD *)v5 - 1) != 1075597352 )
        __break(0x8229u);
      return v5();
    }
    else
    {
      return 4294967294LL;
    }
  }
  else
  {
    v7 = *(_QWORD *)(a2 + 4304);
    v8 = a2 + 7408;
    if ( *(v3 - 1) != 1075597352 )
      __break(0x8229u);
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD *))v3)(v7, v8, 0, a3);
  }
}
