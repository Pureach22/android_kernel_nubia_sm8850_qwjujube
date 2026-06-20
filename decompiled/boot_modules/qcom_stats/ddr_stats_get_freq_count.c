__int64 ddr_stats_get_freq_count()
{
  __int64 v0; // x9
  __int64 v1; // x21
  unsigned int v2; // w0
  __int64 v3; // x1
  unsigned int v4; // w19
  unsigned int v5; // w20
  __int64 v6; // x21
  __int16 v7; // w0

  if ( drv && *(_QWORD *)(drv + 240) && (v0 = *(_QWORD *)(drv + 8), *(_BYTE *)(v0 + 35) == 1) )
  {
    v1 = *(_QWORD *)drv + *(_QWORD *)(v0 + 8);
    v2 = readl_relaxed(v1 + 4);
    if ( v2 >= 0x15 )
    {
      printk(&unk_A209, v3);
      return 0;
    }
    else
    {
      v4 = 0;
      v5 = v2;
      if ( v2 )
      {
        v6 = v1 + 8;
        do
        {
          v7 = readl_relaxed(v6);
          v6 += 16;
          if ( (v7 & 0xFF00) == 0x100 )
            ++v4;
          --v5;
        }
        while ( v5 );
      }
    }
  }
  else
  {
    return (unsigned int)-19;
  }
  return v4;
}
