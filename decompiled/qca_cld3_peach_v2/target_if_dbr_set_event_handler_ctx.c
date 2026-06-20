__int64 __fastcall target_if_dbr_set_event_handler_ctx(
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
  const char *v11; // x2
  __int64 comp_private_obj; // x0

  if ( a1 )
  {
    if ( a2 >= 2 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: DBR handler context: Invalid context",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_dbr_set_event_handler_ctx");
      return 4;
    }
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 8u);
    if ( comp_private_obj )
    {
      *(_DWORD *)(comp_private_obj + 24) = a2;
      qdf_trace_msg(
        0x5Bu,
        4u,
        "%s: DBR handler context: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_dbr_set_event_handler_ctx",
        a2);
      return 0;
    }
    v11 = "%s: dir buf rx psoc object is null";
  }
  else
  {
    v11 = "%s: psoc is null";
  }
  qdf_trace_msg(0x5Bu, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dbr_set_event_handler_ctx");
  return 29;
}
