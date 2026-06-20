__int64 __fastcall hif_set_target_status(__int64 result, int a2)
{
  *(_DWORD *)(result + 600) = a2;
  return result;
}
