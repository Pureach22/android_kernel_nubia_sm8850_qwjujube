__int64 __fastcall ufp_report_gesture_uevent(const char *a1)
{
  __int64 v2; // x3
  __int64 v3; // x2
  __int64 result; // x0
  _QWORD v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = a1;
  v5[1] = 0;
  kobject_uevent_env(&ufp_tp_ops.pdev->dev.kobj, 2, v5);
  pm_wakeup_ws_event(&tp_wakeup, 2000, 0);
  if ( !strcmp(a1, "single_tap=true") )
  {
    v2 = 150;
    dword_31428 = 1;
LABEL_5:
    mod_delayed_work_on(32, qword_31498, &qword_31430, v2);
    goto LABEL_6;
  }
  if ( !strcmp(a1, "double_tap=true") )
  {
    v2 = 0;
    goto LABEL_5;
  }
LABEL_6:
  result = printk(unk_3B734, a1, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
