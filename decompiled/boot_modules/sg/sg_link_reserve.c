__int64 __fastcall sg_link_reserve(__int64 result, __int64 a2, int a3)
{
  int v3; // w9
  int v4; // w10
  int v5; // w11
  __int64 v6; // x8

  *(_BYTE *)(a2 + 240) = 1;
  if ( *(_WORD *)(result + 112) )
  {
    v3 = 0;
    v4 = 1 << (*(_DWORD *)(result + 136) + 12);
    v5 = v4 + a3;
    while ( 1 )
    {
      v5 -= v4;
      ++v3;
      if ( v5 <= v4 )
        break;
      if ( *(unsigned __int16 *)(result + 112) == v3 )
        return result;
    }
    *(_WORD *)(a2 + 24) = v3;
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(result + 116);
    v6 = *(_QWORD *)(result + 128);
    *(_DWORD *)(a2 + 32) = a3;
    *(_QWORD *)(a2 + 40) = v6;
    *(_DWORD *)(a2 + 48) = *(_DWORD *)(result + 136);
  }
  return result;
}
