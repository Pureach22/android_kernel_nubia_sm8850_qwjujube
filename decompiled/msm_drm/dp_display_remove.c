__int64 __fastcall dp_display_remove(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x0

  if ( result )
  {
    v1 = *(_QWORD *)(result + 168);
    v2 = result;
    dp_debug_put(*(_QWORD *)(v1 + 192));
    dp_hpd_put(*(int **)(v1 + 128));
    v3 = *(_QWORD *)(v1 + 176);
    if ( v3 )
      dp_audio_put(*(_QWORD *)(v3 + 952));
    dp_ctrl_put(*(_QWORD *)(v1 + 184));
    dp_panel_put(*(_QWORD *)(v1 + 176));
    dp_link_put(*(_QWORD *)(v1 + 168));
    dp_power_put(*(_QWORD *)(v1 + 144));
    dp_pll_put(*(_QWORD *)(v1 + 200));
    dp_aux_put(*(_QWORD *)(v1 + 160));
    dp_catalog_put(*(_QWORD *)(v1 + 152));
    dp_parser_put(*(_QWORD *)(v1 + 136));
    v4 = *(_QWORD *)(v1 + 1520);
    if ( v4 )
      destroy_workqueue(v4);
    *(_QWORD *)(v2 + 168) = 0;
    devm_kfree(v2 + 16);
    if ( *(_QWORD *)(v1 + 1224) )
    {
      ipc_log_context_destroy();
      *(_QWORD *)(v1 + 1224) = 0;
    }
    result = *(_QWORD *)(v1 + 1232);
    if ( result )
    {
      result = ipc_log_context_destroy();
      *(_QWORD *)(v1 + 1232) = 0;
    }
  }
  return result;
}
