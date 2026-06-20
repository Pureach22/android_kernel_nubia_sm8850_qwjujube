__int64 __fastcall clk_hw_debug_register(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  void *v5; // x2

  if ( a1 && a2 )
  {
    v4 = _kmalloc_cache_noprof(kfree, 3520, 32);
    if ( v4 )
    {
      *(_QWORD *)(v4 + 16) = a2;
      *(_QWORD *)(v4 + 24) = a1;
      mutex_lock(&clk_debug_lock);
      v5 = clk_hw_debug_list;
      if ( clk_hw_debug_list == (_UNKNOWN *)v4
        || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)clk_hw_debug_list) != &clk_hw_debug_list )
      {
        _list_add_valid_or_report(v4, &clk_hw_debug_list);
      }
      else
      {
        *(_QWORD *)((char *)&unk_8 + (_QWORD)clk_hw_debug_list) = v4;
        *(_QWORD *)v4 = v5;
        *(_QWORD *)(v4 + 8) = &clk_hw_debug_list;
        clk_hw_debug_list = (_UNKNOWN *)v4;
      }
      mutex_unlock(&clk_debug_lock);
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    printk(&unk_2946F);
    return 4294967274LL;
  }
}
