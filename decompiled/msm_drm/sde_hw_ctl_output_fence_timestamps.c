__int64 __fastcall sde_hw_ctl_output_fence_timestamps(__int64 a1, unsigned __int64 *a2, unsigned __int64 *a3)
{
  __int64 result; // x0
  unsigned int v7; // w20
  unsigned int v8; // w20
  int v9; // w0

  if ( !a1 )
    return 4294967274LL;
  result = 4294967274LL;
  if ( a2 && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL && a3 && (unsigned __int64)a3 <= 0xFFFFFFFFFFFFF000LL )
  {
    v7 = sde_reg_read(a1, 616);
    *a2 = v7 | (unsigned __int64)(sde_reg_read(a1, 620) << 32);
    v8 = sde_reg_read(a1, 624);
    *a3 = v8 | (unsigned __int64)(sde_reg_read(a1, 628) << 32);
    v9 = sde_reg_read(a1, 612);
    sde_reg_write(a1, 612, v9 & 0xFFFFFFFC | 2, "CTL_TIMESTAMP_CTRL");
    __dsb(0xEu);
    return 0;
  }
  return result;
}
