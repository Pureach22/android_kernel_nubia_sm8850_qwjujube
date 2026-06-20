__int64 __fastcall set_each_page_of_sg(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v4; // w21
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x9
  __int64 v7; // x8
  int v8; // w11

  if ( *(_DWORD *)(result + 8) )
  {
    v2 = result;
    result = *(_QWORD *)result;
    v4 = 0;
    do
    {
      if ( ((*(_DWORD *)(result + 12) & 0xFFF) != 0) | (*(_DWORD *)(result + 12) >> 12) )
      {
        v5 = (unsigned __int64)*(unsigned int *)(result + 12) >> 12;
        if ( (*(_DWORD *)(result + 12) & 0xFFF) != 0 )
          ++v5;
        v6 = v5 - 1;
        v7 = (v5 << 6) - 24;
        do
        {
          v8 = v6--;
          *(_QWORD *)((*(_QWORD *)result & 0xFFFFFFFFFFFFFFFCLL) + v7) = a2;
          v7 -= 64;
        }
        while ( v8 );
      }
      ++v4;
      result = sg_next(result);
    }
    while ( v4 < *(_DWORD *)(v2 + 8) );
  }
  return result;
}
