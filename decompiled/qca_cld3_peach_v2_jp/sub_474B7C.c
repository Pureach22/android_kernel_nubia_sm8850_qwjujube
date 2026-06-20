__int64 __fastcall sub_474B7C(__int64 a1, _QWORD *a2)
{
  __int64 v2; // d9
  __int64 v3; // d18

  *a2 = v3;
  a2[1] = v2;
  return wma_remove_beacon_filter(a1, a2 - 35);
}
