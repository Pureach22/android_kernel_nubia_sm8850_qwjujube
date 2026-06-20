__int64 __fastcall rrm_get_start_tsf(__int64 result, _DWORD *a2)
{
  *a2 = *(_DWORD *)(result + 20212);
  a2[1] = *(_DWORD *)(result + 20216);
  return result;
}
