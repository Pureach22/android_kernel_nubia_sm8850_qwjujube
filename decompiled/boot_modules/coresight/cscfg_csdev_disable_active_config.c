__int64 __fastcall cscfg_csdev_disable_active_config(__int64 a1)
{
  __int64 v2; // x20

  raw_spin_lock_irqsave(a1 + 1040);
  v2 = *(_QWORD *)(a1 + 1048);
  if ( v2 && (*(_BYTE *)(v2 + 16) & 1) != 0 )
  {
    *(_BYTE *)(v2 + 16) = 0;
    *(_QWORD *)(a1 + 1048) = 0;
    raw_spin_unlock_irqrestore(a1 + 1040);
    return cscfg_csdev_disable_config(v2);
  }
  else
  {
    *(_QWORD *)(a1 + 1048) = 0;
    return raw_spin_unlock_irqrestore(a1 + 1040);
  }
}
