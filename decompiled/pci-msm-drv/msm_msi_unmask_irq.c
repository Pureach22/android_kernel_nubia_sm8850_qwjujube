__int64 __fastcall msm_msi_unmask_irq(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x21
  void (*v4)(void); // x8
  __int64 v5; // x20

  result = *(_QWORD *)(a1 + 40);
  if ( result )
  {
    v3 = *(_QWORD *)(**(_QWORD **)(result + 48) + 16LL);
    v4 = *(void (**)(void))(v3 + 168);
    if ( *((_DWORD *)v4 - 1) != 270158662 )
      __break(0x8228u);
    v4();
    v5 = raw_spin_lock_irqsave(v3 + 144);
    if ( *(_BYTE *)(v3 + 148) == 1 )
      pci_msi_unmask_irq(a1);
    return raw_spin_unlock_irqrestore(v3 + 144, v5);
  }
  return result;
}
