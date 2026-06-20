__int64 __fastcall swr_haptics_device_up(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v4; // w0
  unsigned int v5; // w20

  if ( a1 && (v1 = *(_QWORD *)(a1 + 224)) != 0 )
  {
    if ( (*(_BYTE *)(v1 + 186) & 1) != 0 )
      *(_BYTE *)(v1 + 183) = 1;
    if ( (*(_BYTE *)(v1 + 180) & 1) != 0 )
    {
      return 0;
    }
    else
    {
      v4 = regulator_enable(*(_QWORD *)(v1 + 56));
      if ( (v4 & 0x80000000) != 0 )
      {
        v5 = v4;
        if ( (unsigned int)__ratelimit(&swr_haptics_slave_enable__rs, "swr_haptics_slave_enable") )
          dev_err(*(_QWORD *)v1, "%s: enable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_enable", v5);
        return v5;
      }
      else
      {
        *(_BYTE *)(v1 + 180) = 1;
        return 0;
      }
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&swr_haptics_device_up__rs, "swr_haptics_device_up") )
      dev_err(a1 + 72, "%s: no data for swr_hap\n", "swr_haptics_device_up");
    return 4294967277LL;
  }
}
