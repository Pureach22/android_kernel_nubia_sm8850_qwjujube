__int64 __fastcall pld_audio_smmu_unmap(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 result; // x0

  v4 = pld_ctx;
  if ( !a1 || !pld_ctx )
    return printk(&unk_A8AF3B, "pld_get_dev_node", 198, a1);
  v7 = raw_spin_lock_irqsave(pld_ctx + 8);
  v8 = v4 + 16;
  do
  {
    v8 = *(_QWORD *)v8;
    if ( v8 == v4 + 16 )
      return raw_spin_unlock_irqrestore(v4 + 8, v7);
  }
  while ( *(_QWORD *)(v8 - 16) != a1 );
  result = raw_spin_unlock_irqrestore(v4 + 8, v7);
  if ( v8 != 16 && !*(_DWORD *)(v8 + 16) )
    return cnss_audio_smmu_unmap(a1, a2, a3);
  return result;
}
