__int64 __fastcall ieee80211_add_link_station(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 bss; // x0
  __int64 result; // x0
  __int64 v7; // x21
  unsigned int v8; // w0
  __int64 v9; // x1
  unsigned int v10; // w19

  if ( !a1 )
  {
    __break(0x800u);
    MEMORY[0x14C4E64]();
    JUMPOUT(0x3A8F8);
  }
  bss = sta_info_get_bss(a2 + 2688, *(_QWORD *)a3);
  if ( !bss )
    return 4294967294LL;
  if ( !*(_WORD *)(bss + 2872) )
    return 4294967274LL;
  if ( (((unsigned __int64)*(unsigned __int16 *)(bss + 2872) >> *(_DWORD *)(a3 + 8)) & 1) != 0 )
    return 4294967182LL;
  v7 = bss;
  result = ieee80211_sta_allocate_link();
  if ( !(_DWORD)result )
  {
    v8 = sta_link_apply_parameters(a1 + 1536, v7, 0, a3);
    v9 = *(unsigned int *)(a3 + 8);
    if ( v8 )
    {
      v10 = v8;
      ieee80211_sta_free_link(v7, v9);
      return v10;
    }
    else
    {
      return ieee80211_sta_activate_link(v7, v9);
    }
  }
  return result;
}
