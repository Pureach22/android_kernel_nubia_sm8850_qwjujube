__int64 __fastcall geni_i3c_read_dt_properties(__int64 a1, __int64 a2)
{
  int *v4; // x21
  int v5; // w8
  __int64 v6; // x0
  __int64 result; // x0

  if ( of_find_property(*(_QWORD *)(a2 + 760), "qcom,shared", 0) )
  {
    *(_BYTE *)(a1 + 21640) = 1;
    dev_info(a2 + 16, "SE being used by two EEs.\n");
  }
  if ( of_find_property(*(_QWORD *)(a2 + 760), "qcom,split-tx-dma-tre", 0) )
    *(_BYTE *)(a1 + 21656) = 1;
  v4 = (int *)(a1 + 21644);
  *(_BYTE *)(a1 + 21654) = 1;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a2 + 760), "qcom,use_setdasa", a1 + 21644, 1, 0) & 0x80000000) == 0 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 2528),
      "use set dasa for static addr:0x%lx dyn addr:0x%lx\n",
      (unsigned __int8)*v4,
      (unsigned __int8)BYTE1(*v4));
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    v5 = *v4;
    if ( (*v4 & 0x10000) != 0 )
      *(_BYTE *)(a1 + 21654) = 0;
    if ( (v5 & 0x20000) != 0 )
      *(_BYTE *)(a1 + 21649) = 1;
  }
  if ( !of_find_property(*(_QWORD *)(a2 + 760), "qcom,pm-ctrl-client", 0)
    || (*(_BYTE *)(a1 + 21641) = 1,
        dev_info(a2 + 16, "Client controls the I3C PM\n"),
        (*(_QWORD *)(*(_QWORD *)(a2 + 760) + 240LL) = devm_kmalloc(*(_QWORD *)(a1 + 8), 4, 3520)) != 0) )
  {
    v6 = *(_QWORD *)(a1 + 2528);
    *(_BYTE *)(a1 + 21641) = 0;
    ipc_log_string(v6, "Client controls the I3C PM, pm_ctrl_client:%d\n", 0);
    result = *(_QWORD *)(a1 + 8);
    if ( result )
    {
      i3c_trace_log();
      return 0;
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "memory allocation failed for pm-ctrl-client\n");
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    return 4294967284LL;
  }
  return result;
}
