__int64 __fastcall cfr_iter_peer_handler(
        __int64 result,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  const char *v15; // x2
  __int64 v16; // [xsp+8h] [xbp-18h]

  if ( *a3 == 1 )
    return result;
  v16 = v12;
  if ( !result || !a2 )
  {
    v15 = "%s: peer or pdev object is NULL";
    return qdf_trace_msg(0x6Au, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "cfr_iter_peer_handler", v11, v16);
  }
  if ( *(_QWORD *)(*(_QWORD *)(a2 + 88) + 112LL) == a2 )
    return result;
  result = wlan_objmgr_peer_get_comp_private_obj(a2, 0x1Eu);
  if ( !result )
  {
    v15 = "%s: PEER cfr object is NULL!";
    return qdf_trace_msg(0x6Au, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "cfr_iter_peer_handler", v11, v16);
  }
  if ( *(_DWORD *)(result + 12) )
  {
    if ( *(_BYTE *)(result + 8) == 1 )
    {
      *a3 = 1;
      return qdf_trace_msg(
               0x6Au,
               8u,
               "%s: CFR capture running for peer %02x:%02x:%02x:**:**:%02x",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "cfr_iter_peer_handler",
               *(unsigned __int8 *)(a2 + 48),
               *(unsigned __int8 *)(a2 + 49),
               *(unsigned __int8 *)(a2 + 50),
               *(unsigned __int8 *)(a2 + 53),
               v11,
               v16);
    }
  }
  return result;
}
