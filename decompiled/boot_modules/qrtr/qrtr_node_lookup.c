__int64 __fastcall qrtr_node_lookup(unsigned int a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v7; // x1
  unsigned int v13; // w8

  down_read(&qrtr_epts_lock);
  v2 = raw_spin_lock_irqsave(&qrtr_nodes_lock);
  v3 = radix_tree_lookup(&qrtr_nodes, a1);
  v4 = v3;
  if ( v3 )
  {
    _X0 = (unsigned int *)(v3 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v13 = __ldxr(_X0);
    while ( __stxr(v13 + 1, _X0) );
    if ( !v13 )
    {
      v7 = 2;
      goto LABEL_9;
    }
    if ( (((v13 + 1) | v13) & 0x80000000) != 0 )
    {
      v7 = 1;
LABEL_9:
      refcount_warn_saturate(_X0, v7);
    }
  }
  raw_spin_unlock_irqrestore(&qrtr_nodes_lock, v2);
  up_read(&qrtr_epts_lock);
  return v4;
}
