__int64 __fastcall qmp_mbox_suspend_noirq(__int64 a1)
{
  if ( pm_suspend_target_state == 3 )
    *(_BYTE *)(*(_QWORD *)(a1 + 152) + 154LL) = 1;
  return 0;
}
