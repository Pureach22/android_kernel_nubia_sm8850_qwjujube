__int64 __fastcall llcc_slice_getd(int a1)
{
  __int64 result; // x0
  __int64 v2; // x12
  unsigned int v3; // w10
  unsigned int v4; // w8
  _BOOL4 v5; // w11
  __int64 v6; // x12
  unsigned __int64 v7; // x9

  if ( (unsigned __int64)drv_data > 0xFFFFFFFFFFFFF000LL )
    return drv_data;
  v2 = *(_QWORD *)(drv_data + 24);
  v3 = *(_DWORD *)(drv_data + 92);
  v4 = 0;
  v5 = v2 != 0;
  if ( v2 && v3 )
  {
    v4 = 0;
    v6 = v2 + 56;
    while ( *(_DWORD *)(v6 - 56) != a1 )
    {
      ++v4;
      v5 = v6 != 0;
      if ( v6 )
      {
        v6 += 56;
        if ( v4 < v3 )
          continue;
      }
      goto LABEL_12;
    }
    v5 = 1;
  }
LABEL_12:
  result = -19;
  if ( v5 && v4 != v3 )
  {
    v7 = *(_QWORD *)(drv_data + 128);
    if ( v7 )
    {
      if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        return v7 + 24LL * v4;
    }
  }
  return result;
}
