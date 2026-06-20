__int64 __fastcall thermal_qmi_new_server(_QWORD *a1, __int64 a2)
{
  int v3; // w9
  int v4; // w10
  _DWORD v6[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 12);
  v4 = *(_DWORD *)(a2 + 16);
  v6[0] = 42;
  v6[1] = v3;
  v6[2] = v4;
  mutex_lock(a1 + 38);
  kernel_connect(*a1, v6, 12, 0);
  mutex_unlock(a1 + 38);
  queue_work_on(32, system_highpri_wq, a1 + 47);
  _ReadStatusReg(SP_EL0);
  return 0;
}
