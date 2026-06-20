__int64 __fastcall mhi_sat_rpmsg_probe(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  const char *v4; // x20
  __int64 v5; // x21
  const char *v6; // t1
  _QWORD *i; // x20
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 96);
  s1[0] = nullptr;
  result = of_property_read_string(*(_QWORD *)(v2 + 744), "label", s1);
  if ( (_DWORD)result )
    goto LABEL_13;
  if ( mhi_sat_driver_2 != 1 )
    goto LABEL_12;
  v4 = s1[0];
  v5 = mhi_sat_driver_1;
  if ( !strcmp(s1[0], *(const char **)mhi_sat_driver_1) )
    goto LABEL_8;
  if ( !strcmp(v4, *(const char **)(v5 + 96)) )
  {
    v5 += 96;
    goto LABEL_8;
  }
  v6 = *(const char **)(v5 + 192);
  v5 += 192;
  if ( strcmp(v4, v6) )
  {
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
LABEL_8:
  if ( !v5 )
    goto LABEL_12;
  mutex_lock(v5 + 32);
  ipc_log_string(
    *(_QWORD *)(v5 + 88),
    "%s[I][%s] Received RPMSG probe\n",
    (const char *)&unk_8360,
    "mhi_sat_rpmsg_probe");
  *(_QWORD *)(a1 + 152) = v5;
  *(_QWORD *)(v5 + 8) = a1;
  raw_spin_lock_irq(v5 + 80);
  for ( i = *(_QWORD **)(v5 + 16); i != (_QWORD *)(v5 + 16); i = (_QWORD *)*i )
    queue_work_on(32, system_wq, i + 17);
  raw_spin_unlock_irq(v5 + 80);
  mutex_unlock(v5 + 32);
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
