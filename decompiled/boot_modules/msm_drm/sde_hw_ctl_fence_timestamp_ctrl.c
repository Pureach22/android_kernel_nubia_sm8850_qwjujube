__int64 __fastcall sde_hw_ctl_fence_timestamp_ctrl(__int64 a1, char a2, char a3)
{
  int v6; // w9
  int v7; // w8
  __int64 result; // x0

  v6 = sde_reg_read(a1, 612) & 0xFFFFFFFC;
  if ( (a3 & 1) != 0 )
    v7 = 2;
  else
    v7 = 0;
  result = sde_reg_write(a1, 612, v7 & 0xFFFFFFFE | a2 & 1 | v6, "CTL_TIMESTAMP_CTRL");
  __dsb(0xEu);
  return result;
}
