__int64 __fastcall devm_reboot_mode_unregister(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = devres_release(a1, devm_reboot_mode_release, devm_reboot_mode_match, a2);
  if ( (_DWORD)result )
    __break(0x800u);
  return result;
}
