__int64 __fastcall wlansap_get_acl_accept_list(
        __int64 a1,
        void *dest,
        _WORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a1 )
  {
    memcpy(dest, (const void *)(a1 + 828), 6LL * *(unsigned __int16 *)(a1 + 1020));
    *a3 = *(_WORD *)(a1 + 1020);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid SAP pointer", a4, a5, a6, a7, a8, a9, a10, a11, "wlansap_get_acl_accept_list");
    return 5;
  }
}
