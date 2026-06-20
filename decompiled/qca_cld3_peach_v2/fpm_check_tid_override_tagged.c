bool __fastcall fpm_check_tid_override_tagged(__int64 a1)
{
  return (*(_DWORD *)(a1 + 168) & 0xF000000) == 201326592;
}
