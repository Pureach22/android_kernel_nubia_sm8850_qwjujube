__int64 __fastcall target_if_dbr_update_pdev_for_hw_mode_change(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  __int64 comp_private_obj; // x0
  const char *v15; // x2

  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 )
  {
    v15 = "%s: psoc is null";
LABEL_7:
    qdf_trace_msg(0x5Bu, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dbr_update_pdev_for_hw_mode_change");
    return 29;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v11, 8u);
  if ( !comp_private_obj )
  {
    v15 = "%s: dir buf rx psoc object is null";
    goto LABEL_7;
  }
  if ( a2 )
  {
    __break(0x5512u);
    return target_if_dbr_set_event_handler_ctx();
  }
  else
  {
    *(_QWORD *)(a1 + 640) = *(_QWORD *)(comp_private_obj + 16);
    return 0;
  }
}
