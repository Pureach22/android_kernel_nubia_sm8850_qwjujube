void __fastcall tdls_find_peer_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 comp_private_obj; // x0

  if ( !*(_QWORD *)(a11 + 8) )
  {
    if ( a10 )
    {
      if ( (*(_DWORD *)(a10 + 16) | 2) == 2 )
      {
        comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a10, 0xAu);
        if ( comp_private_obj )
          *(_QWORD *)(a11 + 8) = tdls_find_peer(comp_private_obj, *(unsigned __int8 **)a11);
      }
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: invalid vdev", a1, a2, a3, a4, a5, a6, a7, a8, "tdls_find_peer_handler");
    }
  }
}
