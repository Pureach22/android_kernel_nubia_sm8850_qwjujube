__int64 __fastcall pmo_get_vdev_bridge_addr(
        __int64 a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
    qdf_mem_copy(a2, (const void *)(comp_private_obj + 1072), 6u);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x4Du, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_get_vdev_bridge_addr");
    return 4;
  }
}
