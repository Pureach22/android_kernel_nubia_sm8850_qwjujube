__int64 __fastcall qmp_mbox_resume_early(__int64 a1, __int64 a2)
{
  if ( pm_suspend_target_state == 3 )
    qmp_mbox_restore(a1, a2);
  return 0;
}
