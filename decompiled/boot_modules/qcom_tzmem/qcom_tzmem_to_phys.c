__int64 __fastcall qcom_tzmem_to_phys(__int64 a1)
{
  __int64 v2; // x19
  __int64 v4; // x9
  __int64 v5; // x8
  _QWORD *v6; // x22
  __int64 v7; // t1
  __int64 v8; // x0
  __int64 v9; // x20
  __int64 v11; // [xsp+8h] [xbp-28h] BYREF
  __int64 v12; // [xsp+10h] [xbp-20h]
  __int64 v13; // [xsp+18h] [xbp-18h]
  __int64 v14; // [xsp+20h] [xbp-10h]
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  v2 = raw_spin_lock_irqsave(&qcom_tzmem_chunks_lock);
  v11 = 0;
  v12 = 0;
LABEL_5:
  while ( 1 )
  {
    v6 = (_QWORD *)radix_tree_next_chunk(&qcom_tzmem_chunks, &v11, 0);
    if ( !v6 )
      break;
LABEL_6:
    v8 = gen_pool_virt_to_phys(**(_QWORD **)(*v6 + 8LL), a1);
    if ( v8 != -1 )
    {
      v9 = v8;
      goto LABEL_11;
    }
    v5 = v11 + 1;
    v4 = ~v11 + v12;
    while ( v4-- >= 1 )
    {
      v11 = v5++;
      v7 = v6[1];
      ++v6;
      if ( v7 )
      {
        if ( v6 )
          goto LABEL_6;
        goto LABEL_5;
      }
    }
  }
  v9 = 0;
LABEL_11:
  raw_spin_unlock_irqrestore(&qcom_tzmem_chunks_lock, v2);
  _ReadStatusReg(SP_EL0);
  return v9;
}
