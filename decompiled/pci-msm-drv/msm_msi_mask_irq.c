__int64 __fastcall msm_msi_mask_irq(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x22
  __int64 v4; // x21
  __int64 (__fastcall *v5)(_QWORD); // x8

  v1 = *(_QWORD *)(result + 40);
  if ( v1 )
  {
    v2 = result;
    v3 = *(_QWORD *)(**(_QWORD **)(v1 + 48) + 16LL);
    v4 = raw_spin_lock_irqsave(v3 + 144);
    if ( *(_BYTE *)(v3 + 148) == 1 )
      pci_msi_mask_irq(v2);
    raw_spin_unlock_irqrestore(v3 + 144, v4);
    v5 = *(__int64 (__fastcall **)(_QWORD))(v3 + 160);
    if ( *((_DWORD *)v5 - 1) != 270158662 )
      __break(0x8228u);
    return v5(v1);
  }
  return result;
}
