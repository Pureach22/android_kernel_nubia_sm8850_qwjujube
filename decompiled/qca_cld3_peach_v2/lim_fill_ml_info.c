__int64 __fastcall lim_fill_ml_info(__int64 result, __int64 a2)
{
  unsigned int v2; // w9
  char v3; // w10
  int v4; // w11
  int v5; // w10

  v2 = *(unsigned __int8 *)(result + 56);
  if ( v2 >= 2 )
    v3 = 2;
  else
    v3 = *(_BYTE *)(result + 56);
  *(_BYTE *)(a2 + 4368) = v3;
  if ( v2 )
  {
    *(_BYTE *)(a2 + 4382) = *(_BYTE *)(result + 70);
    v4 = *(_DWORD *)(result + 64);
    *(_WORD *)(a2 + 4380) = *(_WORD *)(result + 68);
    *(_DWORD *)(a2 + 4376) = v4;
    *(_WORD *)(a2 + 4386) = *(_WORD *)(result + 74);
    if ( v2 != 1 )
    {
      *(_BYTE *)(a2 + 4430) = *(_BYTE *)(result + 118);
      v5 = *(_DWORD *)(result + 112);
      *(_WORD *)(a2 + 4428) = *(_WORD *)(result + 116);
      *(_DWORD *)(a2 + 4424) = v5;
      *(_WORD *)(a2 + 4434) = *(_WORD *)(result + 122);
    }
  }
  *(_BYTE *)(a2 + 4544) = *(_BYTE *)(result + 232);
  return result;
}
