__int64 __fastcall sme_get_reg_info(__int64 a1, int a2, unsigned int *a3, unsigned int *a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  unsigned int v7; // w8
  unsigned int v8; // w8

  v4 = 0;
  *a3 = 0;
  *a4 = 0;
  while ( 1 )
  {
    v5 = a1 + v4;
    if ( *(_DWORD *)(a1 + v4 + 15404) == a2 )
      break;
    v4 += 12;
    if ( v4 == 1200 )
      return 16;
  }
  v7 = *a3;
  *a3 &= 0xFF00FFFF;
  *a3 = v7 & 0xFF00FFFF | ((unsigned __int8)*(_DWORD *)(v5 + 15412) << 16);
  v8 = *a4;
  *a4 &= 0xFFFF00FF;
  *a4 = v8 & 0xFFFF00FF | ((unsigned __int8)*(_DWORD *)(v5 + 15412) << 8);
  return 0;
}
