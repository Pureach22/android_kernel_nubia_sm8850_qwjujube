__int64 __fastcall hal_set_low_threshold(__int64 result, int a2)
{
  *(_DWORD *)(result + 152) = *(_DWORD *)(result + 44) * a2;
  return result;
}
