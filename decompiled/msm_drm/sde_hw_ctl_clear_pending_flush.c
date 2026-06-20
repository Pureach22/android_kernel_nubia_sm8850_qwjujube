__int64 __fastcall sde_hw_ctl_clear_pending_flush(_QWORD *a1)
{
  if ( !a1 )
    return 4294967274LL;
  a1[18] = 0;
  a1[19] = 0;
  a1[16] = 0;
  a1[17] = 0;
  a1[14] = 0;
  a1[15] = 0;
  a1[12] = 0;
  a1[13] = 0;
  return 0;
}
