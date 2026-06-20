__int64 __fastcall cti_enable(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned int v3; // w21

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  v2 = raw_spin_lock_irqsave(v1 + 56);
  if ( (*(_BYTE *)(v1 + 76) & 1) != 0 || *(_BYTE *)(v1 + 77) != 1 )
    goto LABEL_6;
  if ( (*(_BYTE *)(v1 + 1200) & 1) != 0 || (v3 = coresight_claim_device(*(_QWORD *)(v1 + 8))) == 0 )
  {
    cti_write_all_hw_regs((_QWORD *)v1);
    *(_BYTE *)(v1 + 76) = 1;
LABEL_6:
    v3 = 0;
    ++*(_DWORD *)(v1 + 72);
  }
  raw_spin_unlock_irqrestore(v1 + 56, v2);
  return v3;
}
