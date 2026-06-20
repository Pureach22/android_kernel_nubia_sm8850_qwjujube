__int64 __fastcall syna_dev_reflash_startup_work(__int64 a1)
{
  __int64 v2; // x2
  __int64 v4; // x2
  void *v5; // x0
  __int64 v6; // x2
  unsigned int v7; // w0

  wait_for_completion_timeout(a1 + 448, 250);
  if ( (*(_BYTE *)(a1 + 443) & 1) == 0 )
    return printk(&unk_36640, "syna_dev_reflash_startup_work", v2);
  pm_stay_awake(*(_QWORD *)(a1 - 960) + 16LL);
  if ( (syna_dev_do_reflash((__int64 *)(a1 - 968), 0) & 0x80000000) == 0 )
  {
    if ( (syna_dev_set_up_app_fw((_QWORD *)(a1 - 968)) & 0x80000000) != 0 )
    {
      v5 = &unk_3B114;
    }
    else
    {
      if ( (syna_dev_set_up_input_device(a1 - 968) & 0x80000000) == 0 )
      {
        printk(&unk_3C4B0, "syna_dev_reflash_startup_work", v4);
        syna_tpd_register_fw_class(a1 - 968);
        v7 = syna_dev_set_screen_on_fp_mode((_QWORD *)(a1 - 968), 0, v6);
        printk(&unk_3BEE4, "syna_dev_reflash_startup_work", v7);
        syna_dev_set_tp_report_rate((_QWORD *)(a1 - 968), *(_DWORD *)(a1 + 560), 0);
        printk(&unk_3A2DA, "syna_dev_reflash_startup_work", *(unsigned int *)(a1 + 560));
        return pm_relax(*(_QWORD *)(a1 - 960) + 16LL);
      }
      v5 = &unk_375F8;
    }
    printk(v5, "syna_dev_reflash_startup_work", v4);
  }
  return pm_relax(*(_QWORD *)(a1 - 960) + 16LL);
}
