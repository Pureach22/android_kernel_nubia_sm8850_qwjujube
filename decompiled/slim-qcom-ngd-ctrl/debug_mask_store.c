__int64 __fastcall debug_mask_store(__int64 a1, __int64 a2, unsigned __int8 *a3, __int64 a4)
{
  unsigned int v4; // w8
  __int64 v5; // x9
  __int64 result; // x0
  int v7; // w8

  v4 = *a3;
  v5 = *(_QWORD *)(a1 + 152);
  result = a4;
  if ( v4 <= 0x34 )
    v7 = v4 - 48;
  else
    v7 = 4;
  *(_DWORD *)(v5 + 5476) = v7;
  return result;
}
