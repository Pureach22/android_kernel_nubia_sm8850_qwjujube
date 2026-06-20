__int64 __fastcall lim_update_stads_eht_capable(__int64 result, __int64 a2)
{
  *(_BYTE *)(result + 68) = *(_BYTE *)(a2 + 3480) != 0;
  return result;
}
