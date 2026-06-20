__int64 __fastcall sub_1C1874(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        float a6,
        __n128 a7)
{
  *(short float *)&a6 = -(short float)(*(short float *)&a2
                                     + (short float)(*(short float *)a7.n128_u16 * *(short float *)a7.n128_u16));
  return wlan_objmgr_peer_obj_create(a1, a2, a3, a4, a5, a6);
}
