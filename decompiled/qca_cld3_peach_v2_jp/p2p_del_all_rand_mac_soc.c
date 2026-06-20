__int64 __fastcall p2p_del_all_rand_mac_soc(
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
  if ( a1 )
    return wlan_objmgr_iterate_obj_list(a1, 2, p2p_del_rand_mac_vdev_enum_handler, 0, 0, 0xFu);
  else
    return qdf_trace_msg(
             0x4Eu,
             2u,
             "%s: random_mac:soc object is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "p2p_del_all_rand_mac_soc");
}
