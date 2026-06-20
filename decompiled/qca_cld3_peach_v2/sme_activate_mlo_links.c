__int64 __fastcall sme_activate_mlo_links(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 a3,
        unsigned __int8 *a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  char is_nlink_service_supported; // w8
  __int64 v19; // x0

  if ( (unsigned __int8)a2 > 5u || !(*(_QWORD *)(a1 + 17296) + 96LL * (unsigned __int8)a2) )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: No session for id %d",
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "sme_activate_mlo_links");
  is_nlink_service_supported = ml_is_nlink_service_supported(*(_QWORD *)(a1 + 21624));
  v19 = *(_QWORD *)(a1 + 21624);
  if ( (is_nlink_service_supported & 1) != 0 )
    return policy_mgr_activate_mlo_links_nlink(v19, a2, a3, a4, a5);
  else
    return policy_mgr_activate_mlo_links(v19, a2, a3, a4);
}
