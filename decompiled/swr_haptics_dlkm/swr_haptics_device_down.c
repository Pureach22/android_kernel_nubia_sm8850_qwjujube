__int64 __fastcall swr_haptics_device_down(__int64 a1)
{
  _QWORD *v1; // x19
  unsigned int v2; // w0
  unsigned int v3; // w0
  unsigned int v6; // w20

  if ( a1 && (v1 = *(_QWORD **)(a1 + 224)) != nullptr )
  {
    v2 = swr_hap_disable_hpwr_vreg(*(_QWORD *)(a1 + 224));
    if ( (v2 & 0x80000000) != 0 )
    {
      v6 = v2;
      if ( (unsigned int)__ratelimit(&swr_haptics_device_down__rs_65, "swr_haptics_device_down") )
      {
        dev_err(*v1, "Disable hpwr_vreg failed, rc=%d\n", v6);
        return v6;
      }
      return v6;
    }
    if ( *((_BYTE *)v1 + 180) != 1 )
      return 0;
    v3 = regulator_disable(v1[7]);
    if ( (v3 & 0x80000000) == 0 )
    {
      *((_BYTE *)v1 + 180) = 0;
      return 0;
    }
    v6 = v3;
    if ( !(unsigned int)__ratelimit(&swr_haptics_slave_disable__rs, "swr_haptics_slave_disable") )
      return v6;
    dev_err(*v1, "%s: disable swr-slave-vdd failed, rc=%d\n", "swr_haptics_slave_disable", v6);
    return v6;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&swr_haptics_device_down__rs, "swr_haptics_device_down") )
      dev_err(a1 + 72, "%s: no data for swr_hap\n", "swr_haptics_device_down");
    return 4294967277LL;
  }
}
