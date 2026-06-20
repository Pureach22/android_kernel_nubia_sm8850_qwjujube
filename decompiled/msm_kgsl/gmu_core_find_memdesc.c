__int64 __fastcall gmu_core_find_memdesc(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 result; // x0
  __int64 v6; // x11

  v3 = *(unsigned int *)(a1 + 8216);
  if ( !(_DWORD)v3 )
    return 0;
  v4 = 0;
  result = a1 + 1560;
  while ( v4 != 33 )
  {
    v6 = *(unsigned int *)(result + 184);
    if ( (unsigned int)v6 <= (unsigned int)a2
      && *(_QWORD *)(result + 40) + v6 >= (unsigned __int64)(unsigned int)(a3 + a2) )
    {
      return result;
    }
    ++v4;
    result += 208;
    if ( v3 == v4 )
      return 0;
  }
  __break(0x5512u);
  return gmu_core_find_vma_block(result, a2);
}
