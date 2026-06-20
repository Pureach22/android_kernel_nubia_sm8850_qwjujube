__int64 __fastcall hif_pci_disable_isr(__int64 a1)
{
  __int64 result; // x0

  ((void (*)(void))hif_exec_kill)();
  hif_nointrs(a1);
  ce_tasklet_kill(a1);
  result = tasklet_kill(a1 + 30784);
  *(_DWORD *)(a1 + 672) = 0;
  *(_DWORD *)(a1 + 676) = 0;
  return result;
}
