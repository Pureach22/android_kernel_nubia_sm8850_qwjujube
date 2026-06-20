__int64 __fastcall sys_pm_vx_send_msg(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  _QWORD v4[13]; // [xsp+8h] [xbp-68h] BYREF

  v4[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v4, 0, 96);
  mutex_lock(a1 + 48);
  v2 = *(unsigned int *)(a1 + 132);
  if ( (unsigned int)v2 <= 2 )
  {
    scnprintf(v4, 96, off_8DE0[v2]);
    if ( (unsigned int)qmp_send(*(_QWORD *)(a1 + 96), v4, 96) )
      printk(&unk_73E8, "sys_pm_vx_send_msg");
  }
  result = mutex_unlock(a1 + 48);
  _ReadStatusReg(SP_EL0);
  return result;
}
