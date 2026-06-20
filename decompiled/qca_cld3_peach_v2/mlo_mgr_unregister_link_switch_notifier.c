__int64 __fastcall mlo_mgr_unregister_link_switch_notifier(unsigned int a1)
{
  __int64 mlo_ctx; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  const char *v11; // x2
  __int64 v13; // x8

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
  {
    v11 = "%s: global mlo mgr not initialized";
    goto LABEL_5;
  }
  if ( a1 >= 0x36 )
  {
    v11 = "%s: Invalid component";
LABEL_5:
    qdf_trace_msg(0x8Fu, 2u, v11, v3, v4, v5, v6, v7, v8, v9, v10, "mlo_mgr_unregister_link_switch_notifier");
    return 4;
  }
  v13 = mlo_ctx + 16LL * a1;
  if ( *(_BYTE *)(v13 + 384) == 1 )
  {
    *(_BYTE *)(v13 + 384) = 0;
    *(_QWORD *)(v13 + 392) = 0;
    return 0;
  }
  return 4;
}
