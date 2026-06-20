__int64 __fastcall gen8_get_gmem_size(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x8

  v1 = *(_QWORD *)(a1 + 14264);
  if ( (unsigned int)(*(_DWORD *)v1 - 524800) < 2 )
  {
    v2 = (*(unsigned __int64 *)(v1 + 64) * (unsigned __int128)0xAAAAAAAAAAAAAAABLL) >> 64;
    return (unsigned int)_sw_hweight32(*(unsigned int *)(a1 + 24612)) * (unsigned int)(v2 >> 1);
  }
  if ( *(_DWORD *)v1 == 526592 )
  {
    v2 = *(_QWORD *)(v1 + 64);
    return (unsigned int)_sw_hweight32(*(unsigned int *)(a1 + 24612)) * (unsigned int)(v2 >> 1);
  }
  return *(unsigned int *)(v1 + 64);
}
