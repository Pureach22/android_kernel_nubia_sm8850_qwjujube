__int64 __fastcall icnss_power_misc_params_init(__int64 a1)
{
  __int64 v1; // x20
  int string_helper; // w0
  __int64 v4; // x8
  __int64 v5; // x2
  __int64 result; // x0
  const char *v7; // x19

  v1 = *(_QWORD *)(a1 + 8);
  string_helper = of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,pdc_init_table", 0, 0, 0);
  *(_DWORD *)(a1 + 5776) = string_helper;
  if ( string_helper < 1 )
    return ipc_log_string(icnss_ipc_log_context, "PDC Init Table not configured\n");
  v4 = *(unsigned int *)(a1 + 5776);
  if ( (v4 & 0x80000000) != 0 )
  {
    *(_QWORD *)(a1 + 5768) = 0;
    goto LABEL_9;
  }
  v5 = _kmalloc_noprof(8 * v4, 3520);
  *(_QWORD *)(a1 + 5768) = v5;
  if ( !v5 )
  {
LABEL_9:
    v7 = "%sFailed to alloc PDC Init Table mem\n";
    printk("%sFailed to alloc PDC Init Table mem\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, v7, &unk_12DBF3);
  }
  result = of_property_read_string_helper(*(_QWORD *)(v1 + 760), "qcom,pdc_init_table", v5, *(int *)(a1 + 5776), 0);
  if ( (result & 0x80000000) != 0 )
  {
    v7 = "%sFailed to get PDC Init Table\n";
    printk("%sFailed to get PDC Init Table\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, v7, &unk_12DBF3);
  }
  return result;
}
