__int64 __fastcall sdhci_msm_reset(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v3; // w20

  if ( (a2 & 1) != 0 && (*(_DWORD *)(*(_QWORD *)(a1 + 72) + 1000LL) & 0x800000) != 0 )
  {
    v2 = a1;
    v3 = a2;
    cqhci_deactivate(*(_QWORD *)(a1 + 72));
    a1 = v2;
    a2 = v3;
  }
  return sdhci_reset(a1, a2);
}
