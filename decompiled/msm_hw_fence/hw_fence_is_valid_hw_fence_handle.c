bool __fastcall hw_fence_is_valid_hw_fence_handle(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x8

  if ( a1 )
    v2 = *(unsigned int *)(a1 + 12);
  else
    v2 = 0;
  return (a2 & 0x80000000) != 0LL && v2 == ((a2 >> 27) & 0xF);
}
