__int64 __fastcall remote_etm_freeze(__int64 a1)
{
  coresight_disable_sysfs(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 8LL));
  return 0;
}
