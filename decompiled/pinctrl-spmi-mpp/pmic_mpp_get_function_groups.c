__int64 __fastcall pmic_mpp_get_function_groups(__int64 a1, __int64 a2, _QWORD *a3, _DWORD *a4)
{
  __int64 v4; // x8

  *a3 = pmic_mpp_groups;
  v4 = *(_QWORD *)(a1 + 16);
  *a4 = *(_DWORD *)(v4 + 16);
  return 0;
}
