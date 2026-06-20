__int64 __fastcall mhi_unprepare_after_power_down(__int64 a1)
{
  __int64 v1; // x19

  if ( *(_QWORD *)(a1 + 160) )
  {
    v1 = a1;
    mhi_free_bhie_table(a1, (_QWORD *)(a1 + 160));
    a1 = v1;
  }
  return mhi_deinit_dev_ctxt(a1);
}
