__int64 __fastcall mhi_to_physical(__int64 a1, __int64 a2)
{
  return a2 - *(_QWORD *)(a1 + 32) + *(_QWORD *)(a1 + 8);
}
