__int64 __fastcall gsi_get_hw_profiling_stats(__int64 *a1)
{
  __int64 reg_nk; // x20
  __int64 v3; // x20
  __int64 v4; // x20
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 result; // x0

  if ( a1 )
  {
    reg_nk = (unsigned int)gsihal_read_reg_nk(139, 0, 0);
    *a1 = reg_nk | (gsihal_read_reg_nk(140, 0, 0) << 32);
    v3 = (unsigned int)gsihal_read_reg_nk(141, 0, 0);
    a1[1] = v3 | (gsihal_read_reg_nk(142, 0, 0) << 32);
    v4 = (unsigned int)gsihal_read_reg_nk(143, 0, 0);
    a1[2] = v4 | (gsihal_read_reg_nk(144, 0, 0) << 32);
    v5 = (unsigned int)gsihal_read_reg_nk(145, 0, 0);
    v6 = (unsigned int)gsihal_read_reg_nk(146, 0, 0);
    result = 0;
    a1[3] = v5 | (v6 << 32);
  }
  else
  {
    dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d bad parms NULL stats == NULL\n", "gsi_get_hw_profiling_stats", 5875);
    return 4294967274LL;
  }
  return result;
}
