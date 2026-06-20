__int64 __fastcall get_tp_noise_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x0

  v4 = tpd_cdev;
  mutex_lock(tpd_cdev + 2728);
  v5 = *(_QWORD *)(v4 + 2720);
  if ( v5 )
  {
    if ( *(_QWORD *)(v5 + 8) )
    {
      vfree(*(_QWORD *)(v5 + 8));
      *(_QWORD *)(*(_QWORD *)(v4 + 2720) + 8LL) = 0;
      v5 = *(_QWORD *)(v4 + 2720);
    }
    kfree(v5);
    *(_QWORD *)(v4 + 2720) = 0;
  }
  *(_DWORD *)(v4 + 1096) = 0;
  mutex_unlock(v4 + 2728);
  return a3;
}
