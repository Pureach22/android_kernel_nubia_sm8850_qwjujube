__int64 __fastcall cnss_aop_interface_deinit(__int64 a1)
{
  __int64 result; // x0

  if ( !*(_QWORD *)(a1 + 7640) )
  {
    mbox_free_channel(0);
    *(_QWORD *)(a1 + 7640) = 0;
  }
  result = *(_QWORD *)(a1 + 7648);
  if ( result )
  {
    result = qmp_put();
    *(_QWORD *)(a1 + 7648) = 0;
  }
  return result;
}
