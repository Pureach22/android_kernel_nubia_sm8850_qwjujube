__int64 __fastcall tpdm_freeze(__int64 a1)
{
  coresight_disable_sysfs(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 16LL));
  return 0;
}
