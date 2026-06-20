__int64 ipa3_counter_id_remove_all()
{
  _QWORD *v0; // x8
  __int64 next; // x0
  __int64 v2; // x19
  __int64 result; // x0
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock(ipa3_ctx + 43864);
  v0 = (_QWORD *)ipa3_ctx;
  v4 = 0;
  *(_QWORD *)(ipa3_ctx + 43856) = 0;
  v0[5479] = 0;
  v0[5480] = 0;
  v0[5481] = 0;
  next = idr_get_next(v0 + 5476, &v4);
  if ( next )
  {
    v2 = next;
    do
    {
      idr_remove(ipa3_ctx + 43808, v4);
      kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29408), v2);
      ++v4;
      v2 = idr_get_next(ipa3_ctx + 43808, &v4);
    }
    while ( v2 );
  }
  result = raw_spin_unlock(ipa3_ctx + 43864);
  _ReadStatusReg(SP_EL0);
  return result;
}
