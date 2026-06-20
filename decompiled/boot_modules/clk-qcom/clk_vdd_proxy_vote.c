__int64 __fastcall clk_vdd_proxy_vote(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x8
  unsigned int v4; // w25
  unsigned int v5; // w23
  __int64 v6; // x24
  int v7; // w8
  int v8; // w27

  if ( *(_QWORD *)(a2 + 96) )
  {
    v3 = 0;
    v4 = 1;
    while ( 1 )
    {
      v6 = *(_QWORD *)(*(_QWORD *)(a2 + 88) + 8 * v3);
      v7 = *(_DWORD *)(v6 + 48);
      if ( v7 == 0x80000000 )
      {
        v5 = -22;
      }
      else
      {
        v8 = v7 - 1;
        mutex_lock(&vdd_lock);
        ++*(_DWORD *)(*(_QWORD *)(v6 + 40) + 4LL * v8);
        v5 = clk_aggregate_vdd(v6);
        if ( !v5 )
        {
          mutex_unlock(&vdd_lock);
          goto LABEL_5;
        }
        --*(_DWORD *)(*(_QWORD *)(v6 + 40) + 4LL * v8);
        mutex_unlock(&vdd_lock);
      }
      _warn_printk("%s failed, ret=%d\n", "clk_vdd_proxy_vote", v5);
      __break(0x800u);
LABEL_5:
      v3 = v4++;
      if ( *(_QWORD *)(a2 + 96) <= v3 )
        return v5;
    }
  }
  return 0;
}
