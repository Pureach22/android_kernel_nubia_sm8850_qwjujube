__int64 __fastcall tdls_find_all_peer(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  __int64 v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  if ( v10 )
  {
    v12 = a2;
    v13 = 0;
    wlan_objmgr_iterate_obj_list(v10, 2, tdls_find_peer_handler, (__int64)&v12, 0, 0x11u);
    result = v13;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: psoc is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "tdls_find_all_peer");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
