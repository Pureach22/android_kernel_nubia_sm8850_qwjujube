__int64 sleepmon_send_ssr_command()
{
  __int64 v0; // x0
  __int64 result; // x0
  __int64 v2; // [xsp+8h] [xbp-18h] BYREF
  __int64 v3; // [xsp+10h] [xbp-10h]
  __int64 v4; // [xsp+18h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 0;
  v3 = 0;
  mutex_lock(&unk_B140);
  if ( qword_A680 && (unsigned int)dword_A678 >= 2 )
  {
    if ( byte_A635 == 1 )
    {
      if ( qword_B138 )
      {
        printk(&unk_9E04);
        qcom_rproc_update_recovery_status(qword_B138, 1, 1);
      }
      else
      {
        printk(&unk_940C);
      }
    }
    byte_B190 = 1;
    v0 = *(_QWORD *)(qword_A680 + 968);
    v2 = 0x200000010LL;
    v3 = 0x100000004LL;
    if ( (unsigned int)rpmsg_send(v0, &v2, 16) )
    {
      printk(&unk_9AD1);
      if ( byte_A635 == 1 )
      {
        if ( qword_B138 )
        {
          printk(&unk_921D);
          qcom_rproc_update_recovery_status(qword_B138, 0, 1);
          byte_B190 = 0;
        }
      }
    }
  }
  else
  {
    printk(&unk_99E9);
  }
  result = mutex_unlock(&unk_B140);
  _ReadStatusReg(SP_EL0);
  return result;
}
