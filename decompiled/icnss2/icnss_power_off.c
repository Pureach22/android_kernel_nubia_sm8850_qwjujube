__int64 __fastcall icnss_power_off(_QWORD *a1)
{
  _QWORD *v1; // x19

  v1 = (_QWORD *)a1[19];
  if ( v1 )
  {
    ipc_log_string(icnss_ipc_log_context, "Power Off: 0x%lx\n", v1[229]);
    icnss_hw_power_off(v1);
    return 0;
  }
  else
  {
    printk("%sInvalid drvdata: dev %pK, data %pK\n", byte_130B32, a1, nullptr);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sInvalid drvdata: dev %pK, data %pK\n",
      (const char *)&unk_12DBF3,
      a1,
      nullptr);
    return 4294967274LL;
  }
}
