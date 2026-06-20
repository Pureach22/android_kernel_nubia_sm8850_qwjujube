__int64 __fastcall gen7_hwsched_set_thermal_index(__int64 result)
{
  __int64 v1; // x19

  if ( *(_DWORD *)(result + 11120) == 2 )
  {
    v1 = result;
    result = ((__int64 (__fastcall *)(__int64, __int64))gen7_hwsched_hfi_set_value)(result, 108);
    if ( (_DWORD)result )
      return dev_err(
               *(_QWORD *)(v1 + 1544) + 16LL,
               "Failed to set thermal level %u, ret: %d\n",
               *(_DWORD *)(v1 + 10048),
               result);
  }
  return result;
}
