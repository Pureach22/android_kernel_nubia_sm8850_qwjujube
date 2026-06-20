bool __fastcall hwmon_match_device(__int64 a1)
{
  return *(_QWORD *)(a1 + 792) == (_QWORD)&hwmon_class;
}
