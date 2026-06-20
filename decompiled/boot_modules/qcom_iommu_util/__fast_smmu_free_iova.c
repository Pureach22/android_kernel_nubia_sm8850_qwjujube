__int64 __fastcall _fast_smmu_free_iova(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 result; // x0

  result = _bitmap_clear(*(_QWORD *)(a1 + 56), (unsigned __int64)(a2 - *(_QWORD *)(a1 + 24)) >> 12, a3 >> 12);
  *(_BYTE *)(a1 + 80) = 1;
  return result;
}
