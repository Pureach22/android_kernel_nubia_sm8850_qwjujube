__int64 __fastcall qcom_q6v5_crash_handler_work(__int64 a1)
{
  __int64 v1; // x20
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x21
  void (__fastcall *v7)(__int64, __int64); // x8

  v1 = *(_QWORD *)(a1 - 96);
  mutex_lock(v1 + 984);
  if ( *(_DWORD *)(v1 + 968) && *(_QWORD *)(a1 + 208) == *(_QWORD *)(a1 + 200) )
  {
    v4 = v1;
    v5 = *(_QWORD *)(v1 + 1128);
    v6 = v4 + 1120;
    for ( *(_DWORD *)(v4 + 972) = 3; v5 != v6; v5 = *(_QWORD *)(v5 + 8) )
    {
      v7 = *(void (__fastcall **)(__int64, __int64))(v5 + 32);
      if ( v7 && v5 != *(_QWORD *)(a1 - 8) )
      {
        if ( *((_DWORD *)v7 - 1) != -1840791471 )
          __break(0x8228u);
        v7(v5, 1);
      }
    }
    msleep(100);
    panic("Panicking, remoteproc %s crashed\n", *(const char **)(*(_QWORD *)(a1 - 96) + 24LL));
  }
  return mutex_unlock(v1 + 984);
}
