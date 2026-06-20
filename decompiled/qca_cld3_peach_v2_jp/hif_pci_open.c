__int64 __fastcall hif_pci_open(__int64 a1, int a2)
{
  __int64 v3; // x20

  v3 = a1 + 28672;
  *(_DWORD *)(a1 + 72) = a2;
  hif_rtpm_open(a1);
  *(_DWORD *)(v3 + 2440) = 0;
  *(_QWORD *)(a1 + 31120) = 0;
  *(_DWORD *)(v3 + 2592) = 0;
  *(_QWORD *)(a1 + 31272) = 0;
  return hif_ce_open(a1);
}
