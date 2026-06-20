__int64 __fastcall p2p_get_ap_assist_dfs_params(
        __int64 a1,
        _BYTE *a2,
        _BYTE *a3,
        _BYTE *a4,
        __int64 a5,
        _BYTE *a6,
        _BYTE *a7)
{
  __int64 comp_private_obj; // x0
  int v14; // w8
  unsigned int v15; // w8

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 5u);
  if ( comp_private_obj )
  {
    if ( a2 )
      *a2 = *(_BYTE *)(comp_private_obj + 958);
    if ( a3 )
      *a3 = *(_BYTE *)(comp_private_obj + 963);
    if ( a4 )
      *a4 = *(_BYTE *)(comp_private_obj + 960);
    if ( a5 )
    {
      v14 = *(_DWORD *)(comp_private_obj + 967);
      *(_WORD *)(a5 + 4) = *(_WORD *)(comp_private_obj + 971);
      *(_DWORD *)a5 = v14;
    }
    if ( a6 )
      *a6 = *(_BYTE *)(comp_private_obj + 973);
    v15 = 0;
    if ( a7 )
      *a7 = *(_BYTE *)(comp_private_obj + 974);
  }
  else
  {
    return 4;
  }
  return v15;
}
