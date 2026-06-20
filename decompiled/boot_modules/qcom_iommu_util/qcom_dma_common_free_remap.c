__int64 __fastcall qcom_dma_common_free_remap(unsigned __int64 a1)
{
  _QWORD *v2; // x20
  unsigned __int64 v3; // x8

  mutex_lock(&rbtree_lock);
  v2 = (_QWORD *)*root;
  if ( *root )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v3 = v2[3];
        if ( v3 <= a1 )
          break;
        v2 = (_QWORD *)v2[2];
        if ( !v2 )
          goto LABEL_7;
      }
      if ( v3 >= a1 )
        break;
      v2 = (_QWORD *)v2[1];
      if ( !v2 )
        goto LABEL_7;
    }
    mutex_unlock(&rbtree_lock);
    mutex_lock(&rbtree_lock);
    rb_erase(v2, root);
    mutex_unlock(&rbtree_lock);
    kfree(v2);
  }
  else
  {
LABEL_7:
    mutex_unlock(&rbtree_lock);
  }
  return vunmap(a1);
}
