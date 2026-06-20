bool __fastcall dma_cookie_status(__int64 a1, int a2, __int64 a3)
{
  int v3; // w8
  int v4; // w9
  _BOOL8 result; // x0

  v4 = *(_DWORD *)(a1 + 16);
  v3 = *(_DWORD *)(a1 + 20);
  if ( a3 )
  {
    *(_DWORD *)a3 = v3;
    *(_DWORD *)(a3 + 4) = v4;
    *(_QWORD *)(a3 + 8) = 0;
  }
  if ( v3 > v4 )
    return v4 >= a2 || v3 < a2;
  result = 0;
  if ( v4 >= a2 && v3 < a2 )
    return 1;
  return result;
}
