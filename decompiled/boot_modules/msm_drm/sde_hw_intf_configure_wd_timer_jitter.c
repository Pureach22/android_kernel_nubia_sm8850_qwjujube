__int64 __fastcall sde_hw_intf_configure_wd_timer_jitter(__int64 a1, __int64 a2)
{
  __int64 v4; // x2
  int v5; // w21
  unsigned int v6; // w21
  unsigned int v7; // w8
  __int64 v8; // x2
  __int64 result; // x0
  int v10; // w9
  __int64 v11; // x2

  sde_reg_write(a1, 548, 1, "INTF_WD_TIMER_0_JITTER_CTL");
  v4 = *(unsigned int *)(a2 + 4);
  v5 = (*(_DWORD *)a2 & 0x3FF) << 16;
  if ( (_DWORD)v4 )
  {
    sde_reg_write(a1, 556, v4, "INTF_WD_TIMER_0_LTJ_MAX");
    sde_reg_write(a1, 552, *(unsigned int *)(a2 + 8), "INTF_WD_TIMER_0_LTJ_SLOPE");
  }
  v6 = sde_reg_read(a1, 548) | v5;
  sde_reg_write(a1, 548, v6, "INTF_WD_TIMER_0_JITTER_CTL");
  if ( *(_DWORD *)a2 )
    v7 = v6 | 0x80000000;
  else
    v7 = v6;
  if ( *(_DWORD *)(a2 + 4) )
    v8 = v7 | 0x40000000;
  else
    v8 = v7;
  result = sde_reg_write(a1, 548, v8, "INTF_WD_TIMER_0_JITTER_CTL");
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 33LL) & 0x80) != 0 )
  {
    if ( *(_BYTE *)(a2 + 12) )
    {
      v10 = *(_DWORD *)(a2 + 16);
      if ( v10 )
      {
        result = sde_reg_write(
                   a1,
                   512,
                   v10 & 0x1FFFFF | (*(unsigned __int8 *)(a2 + 12) << 31),
                   "INTF_WD_TIMER_0_LTJ_CTL");
        *(_BYTE *)(a2 + 12) = 0;
        *(_DWORD *)(a2 + 16) = 0;
      }
    }
    v11 = *(unsigned int *)(a2 + 20);
    if ( (_DWORD)v11 )
    {
      result = sde_reg_write(a1, 516, v11, "INTF_WD_TIMER_0_LTJ_CTL1");
      *(_DWORD *)(a2 + 20) = 0;
    }
  }
  return result;
}
