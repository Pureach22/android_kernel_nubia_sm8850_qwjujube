__int64 __fastcall qcom_dma_common_find_pages(unsigned __int64 a1)
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
    return v2[4];
  }
  else
  {
LABEL_7:
    mutex_unlock(&rbtree_lock);
    return 0;
  }
}
