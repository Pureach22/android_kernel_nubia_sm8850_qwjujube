__int64 __fastcall lim_assoc_rej_get_remaining_delta(__int64 a1)
{
  return *(_DWORD *)(a1 + 24) + *(_DWORD *)(a1 + 32) - (unsigned int)(ktime_get_with_offset(1) / 1000 / 0x3E8uLL);
}
