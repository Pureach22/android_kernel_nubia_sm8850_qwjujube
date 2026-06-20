__int64 __fastcall sde_hw_intf_enable_timing_engine(__int64 a1, unsigned __int8 a2)
{
  int v2; // w20
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x2

  v2 = a2;
  result = sde_reg_write(a1, 0, a2 != 0, "INTF_TIMING_ENGINE_EN");
  if ( v2 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL);
    if ( (v5 & 0x600) != 0 )
    {
      if ( (v5 & 0x11) != 0 )
        v6 = 17;
      else
        v6 = 1;
      return sde_reg_write(a1, 528, v6, "INTF_VSYNC_TIMESTAMP_CTRL");
    }
  }
  return result;
}
