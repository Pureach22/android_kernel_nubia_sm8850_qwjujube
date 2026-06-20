__int64 __fastcall clk_vdd_proxy_unvote(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x8
  unsigned int v4; // w26
  unsigned int v5; // w23
  __int64 v7; // x24
  int v8; // w8
  int v9; // w25

  if ( *(_QWORD *)(a2 + 96) )
  {
    v3 = 0;
    v4 = 1;
    while ( 1 )
    {
      v7 = *(_QWORD *)(*(_QWORD *)(a2 + 88) + 8 * v3);
      v8 = *(_DWORD *)(v7 + 48);
      if ( v8 == 0x80000000 )
        goto LABEL_6;
      v9 = v8 - 1;
      if ( !*(_DWORD *)(*(_QWORD *)(v7 + 40) + 4LL * (v8 - 1)) )
        break;
      mutex_lock(&vdd_lock);
      --*(_DWORD *)(*(_QWORD *)(v7 + 40) + 4LL * v9);
      v5 = clk_aggregate_vdd(v7);
      if ( !v5 )
      {
        mutex_unlock(&vdd_lock);
        goto LABEL_8;
      }
      ++*(_DWORD *)(*(_QWORD *)(v7 + 40) + 4LL * v9);
      mutex_unlock(&vdd_lock);
LABEL_7:
      _warn_printk("clk_unvote_vdd_level failed ret=%d\n", v5);
      __break(0x800u);
LABEL_8:
      v3 = v4++;
      if ( *(_QWORD *)(a2 + 96) <= v3 )
        return v5;
    }
    _warn_printk("Reference counts are incorrect for %s level %d\n", *(const char **)v7, v9);
    __break(0x800u);
LABEL_6:
    v5 = -22;
    goto LABEL_7;
  }
  return 0;
}
