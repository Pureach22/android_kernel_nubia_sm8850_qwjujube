__int64 dump_enabled_client_info_show()
{
  int v0; // w19

  v0 = mmrm_clk_print_enabled_client_info(*(_QWORD *)(drv_data + 96));
  if ( !v0 && (~msm_mmrm_debug & 0x10001) == 0 )
    printk(&unk_C6BB, "err ", "dump_enabled_client_info_show");
  return v0;
}
