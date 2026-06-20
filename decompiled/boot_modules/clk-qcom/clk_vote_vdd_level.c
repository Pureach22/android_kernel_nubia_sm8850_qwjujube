__int64 __fastcall clk_vote_vdd_level(int *a1, int a2)
{
  __int64 v4; // x24
  __int64 v5; // x23
  unsigned int v6; // w0
  __int64 v7; // x22
  unsigned int v8; // w21
  __int64 v9; // x25
  __int64 v11; // x24

  if ( a1[8] >= 1 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *(_QWORD *)(*((_QWORD *)a1 + 1) + 8 * v4);
      if ( *(_DWORD *)(v5 + 48) <= a2 )
        break;
      mutex_lock(&vdd_lock);
      ++*(_DWORD *)(*(_QWORD *)(v5 + 40) + 4LL * a2);
      v6 = clk_aggregate_vdd(v5);
      if ( v6 )
      {
        v8 = v6;
        --*(_DWORD *)(*(_QWORD *)(v5 + 40) + 4LL * a2);
        goto LABEL_15;
      }
      mutex_unlock(&vdd_lock);
      if ( ++v4 >= a1[8] )
      {
        v7 = *(_QWORD *)a1;
        if ( !*(_QWORD *)a1 )
          return 0;
        goto LABEL_7;
      }
    }
LABEL_10:
    v8 = -22;
    v9 = (unsigned int)(v4 - 1);
    if ( (int)v4 - 1 < 0 )
      return v8;
    do
    {
LABEL_19:
      v11 = *(_QWORD *)(*((_QWORD *)a1 + 1) + 8 * v9);
      if ( *(_DWORD *)(v11 + 48) > a2 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(v11 + 40) + 4LL * a2) )
        {
          mutex_lock(&vdd_lock);
          --*(_DWORD *)(*(_QWORD *)(v11 + 40) + 4LL * a2);
          if ( (unsigned int)clk_aggregate_vdd(v11) )
            ++*(_DWORD *)(*(_QWORD *)(v11 + 40) + 4LL * a2);
          mutex_unlock(&vdd_lock);
        }
        else
        {
          _warn_printk("Reference counts are incorrect for %s level %d\n", *(const char **)v11, a2);
          __break(0x800u);
        }
      }
    }
    while ( v9-- > 0 );
    return v8;
  }
  LODWORD(v4) = 0;
  v7 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
    return 0;
LABEL_7:
  if ( *(_DWORD *)(v7 + 48) <= a2 )
    goto LABEL_10;
  mutex_lock(&vdd_lock);
  ++*(_DWORD *)(*(_QWORD *)(v7 + 40) + 4LL * a2);
  v8 = clk_aggregate_vdd(v7);
  if ( !v8 )
  {
    mutex_unlock(&vdd_lock);
    return v8;
  }
  --*(_DWORD *)(*(_QWORD *)(v7 + 40) + 4LL * a2);
LABEL_15:
  mutex_unlock(&vdd_lock);
  v9 = (unsigned int)(v4 - 1);
  if ( (int)v4 - 1 >= 0 )
    goto LABEL_19;
  return v8;
}
