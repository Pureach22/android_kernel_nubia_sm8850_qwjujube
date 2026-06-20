__int64 mhi_misc_init()
{
  __int64 result; // x0

  result = _mutex_init(&unk_21020, "&mhi_bus.lock", &mhi_misc_init___key);
  mhi_bus = (__int64)&mhi_bus;
  qword_21018 = (__int64)&mhi_bus;
  return result;
}
