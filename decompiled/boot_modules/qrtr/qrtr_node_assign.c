__int64 __fastcall qrtr_node_assign(__int64 result, unsigned int a2)
{
  __int64 v3; // x20
  __int64 v4; // x21

  if ( a2 != -1 )
  {
    v3 = result;
    if ( *(_DWORD *)(result + 60) != a2 )
    {
      v4 = raw_spin_lock_irqsave(&qrtr_nodes_lock);
      if ( !radix_tree_lookup(&qrtr_nodes, a2) )
        radix_tree_insert(&qrtr_nodes, a2, v3);
      if ( *(_DWORD *)(v3 + 60) == -1 )
        *(_DWORD *)(v3 + 60) = a2;
      return raw_spin_unlock_irqrestore(&qrtr_nodes_lock, v4);
    }
  }
  return result;
}
