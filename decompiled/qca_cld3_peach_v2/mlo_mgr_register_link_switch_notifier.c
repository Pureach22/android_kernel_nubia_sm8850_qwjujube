__int64 __fastcall mlo_mgr_register_link_switch_notifier(unsigned int a1, __int64 a2)
{
  __int64 mlo_ctx; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  const char *v15; // x2

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
  {
    v15 = "%s: global mlo mgr not initialized";
LABEL_8:
    qdf_trace_msg(0x8Fu, 2u, v15, v5, v6, v7, v8, v9, v10, v11, v12, "mlo_mgr_register_link_switch_notifier");
    return 4;
  }
  if ( a1 > 0x35 || !a2 )
  {
    v15 = "%s: Invalid component";
    goto LABEL_8;
  }
  v13 = mlo_ctx + 16LL * a1;
  if ( (*(_BYTE *)(v13 + 384) & 1) != 0 )
    return 6;
  *(_QWORD *)(v13 + 392) = a2;
  *(_BYTE *)(v13 + 384) = 1;
  return 0;
}
