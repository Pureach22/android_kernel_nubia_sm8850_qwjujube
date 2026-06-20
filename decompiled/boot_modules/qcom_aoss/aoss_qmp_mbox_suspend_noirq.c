__int64 __fastcall aoss_qmp_mbox_suspend_noirq(__int64 a1)
{
  if ( pm_suspend_target_state == 3 )
  {
    *(_BYTE *)(*(_QWORD *)(a1 + 152) + 248LL) = 1;
    dev_info(a1, "AOSS: Deep sleep entry\n");
  }
  return 0;
}
