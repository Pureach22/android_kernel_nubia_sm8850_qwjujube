__int64 __fastcall sdhci_msm_cqe_irq(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 2160);
  v6[0] = 0;
  if ( v4 && *(_BYTE *)(a1 + 2168) == 1 )
    ipc_log_string();
  if ( (sdhci_cqe_irq(a1, a2, (char *)v6 + 4, v6) & 1) != 0 )
  {
    cqhci_irq(*(_QWORD *)(a1 + 72), a2, HIDWORD(v6[0]), LODWORD(v6[0]));
    a2 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return a2;
}
