__int64 __fastcall mhi_to_virtual(__int64 a1, __int64 a2)
{
  return *(_QWORD *)(a1 + 32) + a2 - *(_QWORD *)(a1 + 8);
}
