bool __fastcall dp_check_pdev_exists(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 72);
  return v2 && v2 == a2;
}
