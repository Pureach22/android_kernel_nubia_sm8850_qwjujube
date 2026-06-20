__int64 __fastcall sde_hw_intf_enable_te(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x2

  if ( !a1 )
    return 4294967274LL;
  sde_reg_write(
    a1,
    644,
    a2 & 1 | (8 * ((*(_DWORD *)(*(_QWORD *)(a1 + 40) + 32LL) >> 5) & 1u)),
    "INTF_TEAR_TEAR_CHECK_EN");
  if ( (a2 & 1) != 0 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL);
    if ( (v4 & 0x600) != 0 )
    {
      if ( (v4 & 0x11) != 0 )
        v5 = 33;
      else
        v5 = 1;
      sde_reg_write(a1, 528, v5, "INTF_VSYNC_TIMESTAMP_CTRL");
    }
  }
  return 0;
}
