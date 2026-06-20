__int64 __fastcall ufp_report_lcd_state(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  void *v4; // x0
  __int64 result; // x0
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = ufp_tp_ops;
  if ( ufp_tp_ops )
  {
    v6[0] = "aod=true";
    v6[1] = 0;
    printk(&unk_35F05, a2, a3);
    result = kobject_uevent_env(v3 + 16, 2, v6);
    if ( !(_DWORD)result )
      goto LABEL_5;
    v4 = &unk_37CDC;
  }
  else
  {
    v4 = &unk_37C83;
  }
  result = printk(v4, a2, a3);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
