__int64 __fastcall sde_hw_intf_collect_misr(__int64 a1, char a2, _DWORD *a3)
{
  __int64 v6; // x0

  if ( !a3 )
    return 4294967274LL;
  v6 = sde_reg_read(a1, 384);
  if ( (a2 & 1) != 0 )
  {
LABEL_3:
    *a3 = sde_reg_read(a1, 388);
    return 0;
  }
  if ( (v6 & 0x100) != 0 )
  {
    ktime_get(v6);
    usleep_range_state(126, 500, 2);
    while ( (sde_reg_read(a1, 384) & 0x200) == 0 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
    }
    goto LABEL_3;
  }
  return 4294967274LL;
}
