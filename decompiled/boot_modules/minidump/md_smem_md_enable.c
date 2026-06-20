bool md_smem_md_enable()
{
  __int64 v0; // x1
  _BOOL4 v1; // w19

  v0 = raw_spin_lock_irqsave(&mdt_lock);
  if ( qword_1100E8 )
    v1 = *(_DWORD *)(qword_1100E8 + 4) == 1162756684;
  else
    v1 = 0;
  raw_spin_unlock_irqrestore(&mdt_lock, v0);
  return v1;
}
