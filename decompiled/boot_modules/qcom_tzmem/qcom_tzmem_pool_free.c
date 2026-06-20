__int64 __fastcall qcom_tzmem_pool_free(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x20
  char v3; // w22
  __int64 v5; // x10
  __int64 v6; // x9
  _QWORD *v7; // x0
  __int64 v8; // t1
  _QWORD *v9; // x20
  _QWORD *v10; // x8
  _QWORD *v11; // x24
  __int64 v12; // x1
  __int64 v13; // x3
  __int64 v14; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h]
  __int64 v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = (_QWORD *)result;
    v16 = 0;
    v17 = 0;
    v2 = raw_spin_lock_irqsave(&qcom_tzmem_chunks_lock);
    v3 = 0;
    v14 = 0;
    v15 = 0;
LABEL_6:
    while ( 1 )
    {
      v7 = (_QWORD *)radix_tree_next_chunk(&qcom_tzmem_chunks, &v14, 0);
      if ( !v7 )
        break;
      v6 = v14;
LABEL_8:
      v3 |= *(_QWORD *)(*v7 + 8LL) == (_QWORD)v1;
      v5 = ~v6 + v15;
      while ( v5-- >= 1 )
      {
        v14 = ++v6;
        v8 = v7[1];
        ++v7;
        if ( v8 )
        {
          if ( v7 )
            goto LABEL_8;
          goto LABEL_6;
        }
      }
    }
    raw_spin_unlock_irqrestore(&qcom_tzmem_chunks_lock, v2);
    if ( (v3 & 1) != 0 )
    {
      _warn_printk("Freeing TZ memory pool with memory still allocated");
      __break(0x800u);
    }
    v9 = (_QWORD *)v1[1];
    if ( v9 != v1 + 1 )
    {
      do
      {
        v11 = (_QWORD *)*v9;
        v10 = (_QWORD *)v9[1];
        if ( (_QWORD *)*v10 == v9 && (_QWORD *)v11[1] == v9 )
        {
          v11[1] = v10;
          *v10 = v11;
        }
        else
        {
          _list_del_entry_valid_or_report(v9);
        }
        v13 = v9[3];
        v12 = v9[4];
        *v9 = 0xDEAD000000000100LL;
        v9[1] = 0xDEAD000000000122LL;
        dma_free_attrs(qcom_tzmem_dev, v12, v9[2], v13, 0);
        kfree(v9);
        v9 = v11;
      }
      while ( v11 != v1 + 1 );
    }
    gen_pool_destroy(*v1);
    result = kfree(v1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
