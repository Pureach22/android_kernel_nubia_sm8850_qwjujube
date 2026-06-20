__int64 __fastcall sdhci_msm_wrapper_suspend_late(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0

  if ( of_find_property(*(_QWORD *)(a1 + 744), "non-removable", 0) && (is_bootdevice_sdhci & 1) == 0 )
  {
    dev_info(a1, "SDHCI is not boot dev.\n");
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 152);
    v3 = *(_QWORD *)(v2 + 2160);
    if ( v3 && *(_BYTE *)(v2 + 2168) == 1 )
      ipc_log_string(v3, "%s: Enter\n", "sdhci_msm_suspend_late");
    flush_delayed_work(v2 + 1760);
  }
  return 0;
}
