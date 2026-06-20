bool __fastcall hdd_is_runtime_pm_enabled(__int64 a1)
{
  return *(_BYTE *)(*(_QWORD *)(a1 + 104) + 123LL) != 0;
}
