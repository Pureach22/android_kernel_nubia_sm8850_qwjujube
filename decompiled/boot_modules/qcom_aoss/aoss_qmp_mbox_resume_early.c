__int64 __fastcall aoss_qmp_mbox_resume_early(__int64 a1)
{
  unsigned int v3; // w20

  if ( pm_suspend_target_state != 3 )
    return 0;
  v3 = qmp_open(*(_QWORD *)(a1 + 152));
  if ( (v3 & 0x80000000) != 0 )
    dev_err(a1, "QMP restore failed, ret = %d\n", v3);
  dev_info(a1, "AOSS: Deep sleep exit\n");
  return v3;
}
