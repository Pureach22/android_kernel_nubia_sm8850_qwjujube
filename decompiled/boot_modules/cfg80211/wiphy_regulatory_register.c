__int64 __fastcall wiphy_regulatory_register(__int64 a1)
{
  _DWORD *v1; // x19
  int v2; // w8
  void (*v3)(void); // x8
  __int64 v4; // x20
  __int64 v5; // x1
  __int64 v6; // x19
  __int64 v7; // x0

  v1 = last_request;
  v2 = *(_DWORD *)(a1 + 104);
  if ( (v2 & 0x80) != 0 )
  {
    *(_DWORD *)(a1 + 104) = v2 | 0x14;
    if ( v1[5] == 1 )
    {
      v3 = *(void (**)(void))(a1 + 376);
      if ( v3 )
      {
        v4 = a1;
        if ( *((_DWORD *)v3 - 1) != -1916906463 )
          __break(0x8228u);
        v3();
        a1 = v4;
      }
    }
  }
  v5 = (unsigned int)v1[5];
  v6 = a1;
  wiphy_update_regulatory(a1, v5);
  v7 = wiphy_all_share_dfs_chan_state(v6);
  return reg_process_self_managed_hints(v7);
}
