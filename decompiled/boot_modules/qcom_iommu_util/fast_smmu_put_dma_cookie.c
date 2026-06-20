__int64 __fastcall fast_smmu_put_dma_cookie(unsigned __int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v6; // x8
  unsigned __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  v2 = raw_write_lock_irqsave(&mappings_lock);
  v3 = v2;
  v4 = mappings;
  if ( !mappings )
    return raw_write_unlock_irqrestore(&mappings_lock, v2);
  while ( 1 )
  {
    v7 = *(_QWORD *)(v4 - 128);
    if ( v7 <= a1 )
      break;
    v6 = 16;
LABEL_5:
    v4 = *(_QWORD *)(v4 + v6);
    if ( !v4 )
      return raw_write_unlock_irqrestore(&mappings_lock, v2);
  }
  if ( v7 < a1 )
  {
    v6 = 8;
    goto LABEL_5;
  }
  if ( v4 == 136 )
    return raw_write_unlock_irqrestore(&mappings_lock, v2);
  rb_erase(v4, &mappings);
  raw_write_unlock_irqrestore(&mappings_lock, v3);
  if ( *(_QWORD *)(v4 - 120) )
  {
    put_iova_domain();
    kfree(*(_QWORD *)(v4 - 120));
  }
  v8 = *(_QWORD *)(v4 - 80);
  if ( v8 )
    kvfree(v8);
  v9 = *(_QWORD *)(v4 - 72);
  if ( v9 )
    kvfree(v9);
  return kfree(v4 - 136);
}
