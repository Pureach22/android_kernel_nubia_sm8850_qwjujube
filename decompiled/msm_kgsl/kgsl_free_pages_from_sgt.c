__int64 __fastcall kgsl_free_pages_from_sgt(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  unsigned int v4; // w21
  unsigned int v5; // w23
  unsigned __int64 v6; // x1
  char v7; // w8
  __int64 v8; // x24
  unsigned __int64 v9; // x25

  v1 = *(_QWORD *)(result + 56);
  if ( v1 )
  {
    v2 = result;
    if ( *(_DWORD *)(v1 + 8) )
    {
      v3 = *(_QWORD *)v1;
      v4 = 0;
      do
      {
        if ( *(_DWORD *)(v3 + 12) >= 0x1000u )
        {
          v5 = 0;
          v6 = *(_QWORD *)v3 & 0xFFFFFFFFFFFFFFFCLL;
          do
          {
            if ( (*(_QWORD *)v6 & 0x40) != 0 )
              v7 = *(_BYTE *)(v6 + 64);
            else
              v7 = 0;
            v8 = (unsigned int)(1 << v7);
            v9 = v6 + (v8 << 6);
            kgsl_free_page(v2, v6);
            v5 += v8;
            v6 = v9;
          }
          while ( v5 < *(_DWORD *)(v3 + 12) >> 12 );
        }
        ++v4;
        v3 = sg_next(v3);
      }
      while ( v4 < *(_DWORD *)(*(_QWORD *)(v2 + 56) + 8LL) );
    }
    result = *(_QWORD *)(v2 + 112);
    if ( result )
      return fput(result);
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
