__int64 __fastcall tdls_get_connected_peer_count_from_vdev(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  const char *v12; // x2

  if ( !a1 )
  {
    v12 = "%s: NULL vdev";
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v12 = "%s: can't get psoc";
LABEL_8:
    qdf_trace_msg(0, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_get_tdls_soc_obj");
    return 0;
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(v10, 0xAu);
  if ( result )
    return *(unsigned __int16 *)(result + 202);
  return result;
}
