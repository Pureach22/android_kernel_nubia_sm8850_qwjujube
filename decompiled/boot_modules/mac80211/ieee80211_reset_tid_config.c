__int64 __fastcall ieee80211_reset_tid_config(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(__int64, __int64); // x8
  __int64 (*v5)(void); // x9
  __int64 v7; // x0
  __int64 v8; // x1

  v3 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(*(_QWORD *)(a2 + 4304) + 464LL) + 848LL);
  if ( !v3 )
    return 4294967201LL;
  if ( a3 )
  {
    if ( sta_info_get_bss(a2 + 2688, a3) )
    {
      v5 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a2 + 4304) + 464LL) + 848LL);
      if ( *((_DWORD *)v5 - 1) != -845819322 )
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
    if ( *((_DWORD *)v3 - 1) != -845819322 )
      __break(0x8228u);
    return v3(v7, v8);
  }
}
