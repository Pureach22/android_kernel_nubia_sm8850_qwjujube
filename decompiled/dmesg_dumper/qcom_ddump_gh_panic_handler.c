__int64 __fastcall qcom_ddump_gh_panic_handler(__int64 a1)
{
  qcom_ddump_to_shm(a1 - 256, dword_80B8);
  return 0;
}
