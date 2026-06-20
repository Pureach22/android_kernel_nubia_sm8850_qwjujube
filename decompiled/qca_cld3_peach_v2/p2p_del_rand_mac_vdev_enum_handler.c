__int64 __fastcall p2p_del_rand_mac_vdev_enum_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int v10; // w8
  __int64 result; // x0

  if ( !a10 )
    return qdf_trace_msg(
             0x4Eu,
             2u,
             "%s: random_mac:invalid vdev",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "p2p_del_rand_mac_vdev_enum_handler");
  v10 = *(_DWORD *)(a10 + 16);
  if ( v10 <= 0x10 && ((1 << v10) & 0x10085) != 0 )
    return p2p_del_all_rand_mac_vdev(a10);
  return result;
}
