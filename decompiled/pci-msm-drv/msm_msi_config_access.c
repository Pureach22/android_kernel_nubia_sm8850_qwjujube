__int64 __fastcall msm_msi_config_access(__int64 a1, char a2)
{
  __int64 v3; // x20
  __int64 v4; // x0

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 144) + 32LL);
  v4 = raw_spin_lock_irqsave(v3 + 144);
  *(_BYTE *)(v3 + 148) = a2;
  return raw_spin_unlock_irqrestore(v3 + 144, v4);
}
