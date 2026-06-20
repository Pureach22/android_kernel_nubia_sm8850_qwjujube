__int64 __fastcall gh_put_irq(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 irq_data; // x0
  int v4; // w20

  if ( (int)a1 < 1 )
    return 4294967274LL;
  v2 = a1;
  irq_data = irq_get_irq_data(a1, a2);
  if ( !irq_data )
    return 4294967274LL;
  v4 = *(_DWORD *)(irq_data + 8);
  irq_dispose_mapping(v2);
  if ( !idr_find(&gh_rm_free_virq_idr, v4 - 32) )
    return 4294967274LL;
  idr_remove(&gh_rm_free_virq_idr, v4 - 32);
  return 0;
}
