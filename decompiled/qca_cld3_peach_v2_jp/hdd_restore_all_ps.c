__int64 __fastcall hdd_restore_all_ps(__int64 *a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = a1[13];
  result = cfg_psoc_get_values(*a1);
  *(_BYTE *)(v1 + 123) = *(_DWORD *)(result + 2708);
  return result;
}
