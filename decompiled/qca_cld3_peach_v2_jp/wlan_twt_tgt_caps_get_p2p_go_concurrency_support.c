__int64 __fastcall wlan_twt_tgt_caps_get_p2p_go_concurrency_support(
        __int64 a1,
        _BYTE *a2,
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
  const char *v13; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
    if ( comp_private_obj )
    {
      *a2 = *(_BYTE *)(comp_private_obj + 30);
      return 0;
    }
    v13 = "%s: twt psoc priv obj is null";
  }
  else
  {
    v13 = "%s: psoc is null";
  }
  qdf_trace_msg(0x96u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_twt_tgt_caps_get_p2p_go_concurrency_support");
  return 16;
}
