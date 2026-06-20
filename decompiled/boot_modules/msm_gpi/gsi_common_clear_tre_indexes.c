__int64 __fastcall gsi_common_clear_tre_indexes(__int64 result)
{
  *(_QWORD *)result = 0;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 8976) = 0;
  return result;
}
