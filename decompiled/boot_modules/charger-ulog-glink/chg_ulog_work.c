__int64 __fastcall chg_ulog_work(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x20
  __int64 v4; // x0
  int v5; // w8
  int v6; // w8
  unsigned int v7; // w0
  __int64 v8; // x2
  __int64 result; // x0
  __int64 v10; // x0
  unsigned int v11; // w19
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  int v13; // [xsp+10h] [xbp-10h]
  int v14; // [xsp+14h] [xbp-Ch]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v1 = a1 + 0x2000;
  v2 = a1 - 80;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1 - 80;
  v5 = *(unsigned __int8 *)(v1 + 121);
  v12 = 0x10000800ALL;
  if ( v5 )
    v6 = 35;
  else
    v6 = 24;
  v13 = v6;
  v14 = 0x2000;
  mutex_lock(v4);
  *(_DWORD *)(a1 - 32) = 0;
  v7 = pmic_glink_write(*(_QWORD *)(a1 - 112), &v12, 16);
  if ( v7 )
  {
    v11 = v7;
LABEL_12:
    mutex_unlock(v2);
    result = printk(&unk_6FD6, "chg_ulog_work", v11);
    goto LABEL_9;
  }
  if ( !(unsigned int)wait_for_completion_timeout(a1 - 32, 250) )
  {
    printk(&unk_6EE0, "chg_ulog_write", v8);
    v11 = -110;
    goto LABEL_12;
  }
  result = mutex_unlock(v2);
  if ( (*(_BYTE *)(v1 + 120) & 1) != 0 || *(_BYTE *)(v1 + 121) == 1 )
  {
    v10 = _msecs_to_jiffies(*(unsigned int *)(a1 + 8308));
    result = queue_delayed_work_on(32, system_wq, a1, v10);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
