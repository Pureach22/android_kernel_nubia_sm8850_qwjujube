unsigned __int64 __fastcall qcom_smem_virt_to_phys(unsigned __int64 a1)
{
  __int64 i; // x9
  unsigned __int64 v2; // x10
  __int64 v3; // x8
  unsigned __int64 v4; // x9
  _QWORD *j; // x8
  unsigned __int64 v6; // x9
  __int64 v7; // x9
  unsigned __int64 v8; // x10

  for ( i = 0; i != 800; i += 32 )
  {
    v2 = *(_QWORD *)(_smem + i + 72);
    if ( v2 && v2 <= a1 && v2 + *(_QWORD *)(_smem + i + 96) > a1 )
    {
      v3 = _smem + i;
      v4 = a1 - v2;
      j = (_QWORD *)(v3 + 80);
      return v4 + *j;
    }
  }
  v6 = *(_QWORD *)(_smem + 40);
  if ( v6 && v6 <= a1 && v6 + *(_QWORD *)(_smem + 64) > a1 )
  {
    v4 = a1 - v6;
    j = (_QWORD *)(_smem + 48);
    return v4 + *j;
  }
  v7 = *(unsigned int *)(_smem + 872);
  if ( (_DWORD)v7 )
  {
    for ( j = (_QWORD *)(_smem + 880); ; j += 3 )
    {
      v8 = j[1];
      if ( v8 )
      {
        if ( v8 <= a1 && v8 + j[2] > a1 )
          break;
      }
      if ( !--v7 )
        return 0;
    }
    v4 = a1 - v8;
    return v4 + *j;
  }
  return 0;
}
