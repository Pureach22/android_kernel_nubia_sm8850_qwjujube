__int64 __fastcall wlan_objmgr_print_peer_ref_ids(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  return qdf_trace_msg(
           0x57u,
           a2,
           "%s: Pending refs -- %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "wlan_objmgr_print_peer_ref_ids",
           *(unsigned int *)(a1 + 104));
}
