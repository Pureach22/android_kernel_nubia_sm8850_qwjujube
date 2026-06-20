__int64 __fastcall cti_restore(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x20
  unsigned int v4; // w21

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 78) != 1 )
    return 0;
  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 8) + 152LL) + 152LL);
  v3 = raw_spin_lock_irqsave(v2 + 56);
  if ( (*(_BYTE *)(v2 + 76) & 1) == 0 && *(_BYTE *)(v2 + 77) == 1 )
  {
    if ( (*(_BYTE *)(v2 + 1200) & 1) == 0 )
    {
      v4 = coresight_claim_device(*(_QWORD *)(v2 + 8));
      if ( v4 )
        goto LABEL_8;
    }
    cti_write_all_hw_regs((_QWORD *)v2);
    *(_BYTE *)(v2 + 76) = 1;
  }
  v4 = 0;
  ++*(_DWORD *)(v2 + 72);
LABEL_8:
  raw_spin_unlock_irqrestore(v2 + 56, v3);
  *(_BYTE *)(v1 + 78) = 0;
  return v4;
}
