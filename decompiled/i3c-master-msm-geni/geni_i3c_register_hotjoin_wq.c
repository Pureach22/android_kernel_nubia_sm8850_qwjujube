__int64 __fastcall geni_i3c_register_hotjoin_wq(__int64 a1)
{
  __int64 *v2; // x0
  __int64 v3; // x1
  __int64 v4; // x0

  if ( *(_BYTE *)(a1 + 21654) != 1 )
    return 0;
  v2 = *(__int64 **)(a1 + 8);
  v3 = v2[14];
  if ( !v3 )
    v3 = *v2;
  v4 = wakeup_source_register(v2, v3);
  *(_QWORD *)(a1 + 21528) = v4;
  if ( v4 )
  {
    *(_QWORD *)(a1 + 21496) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 21504) = a1 + 21504;
    *(_QWORD *)(a1 + 21512) = a1 + 21504;
    *(_QWORD *)(a1 + 21520) = geni_i3c_hotjoin;
    *(_QWORD *)(a1 + 21488) = alloc_workqueue("%s", byte_12);
    geni_i3c_enable_hotjoin_irq(a1, 1);
    return 0;
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "wakeup source registration failed\n");
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    geni_se_resources_off(a1);
    return 4294967284LL;
  }
}
