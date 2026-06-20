__int64 __fastcall qcom_tzmem_free(const void *a1)
{
  __int64 v2; // x22
  _QWORD *v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 result; // x0

  v2 = raw_spin_lock_irqsave(&qcom_tzmem_chunks_lock);
  v3 = (_QWORD *)radix_tree_delete_item(&qcom_tzmem_chunks, a1, 0);
  raw_spin_unlock_irqrestore(&qcom_tzmem_chunks_lock, v2);
  if ( v3 )
  {
    v4 = v3[1] + 48LL;
    v5 = raw_spin_lock_irqsave(v4);
    gen_pool_free_owner(*(_QWORD *)v3[1], a1, *v3, 0);
    if ( v4 )
      raw_spin_unlock_irqrestore(v4, v5);
    return kfree(v3);
  }
  else
  {
    result = _warn_printk("Virtual address %p not owned by TZ memory allocator", a1);
    __break(0x800u);
  }
  return result;
}
