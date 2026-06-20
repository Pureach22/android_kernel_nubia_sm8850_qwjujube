__int64 __fastcall gen8_hwsched_set_gmu_based_dcvs_value(__int64 a1, int a2, __int64 a3, int a4, char a5)
{
  __int64 result; // x0
  bool v10; // zf
  unsigned int v11; // w21
  const char *v12; // x2

  result = ((__int64 (*)(void))gen8_hwsched_hfi_set_value)();
  if ( (_DWORD)result )
  {
    v10 = (a5 & 1) == 0;
    v11 = result;
    if ( v10 )
      v12 = (const char *)&unk_13C708;
    else
      v12 = "default";
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "Failed to set %s for value %u for HFI type %u, ret: %d\n",
      v12,
      a4,
      a2,
      result);
    return v11;
  }
  return result;
}
