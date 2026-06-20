unsigned __int64 __fastcall _qdf_nbuf_nonlinear_data(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  unsigned __int64 result; // x0
  __int64 v4; // x8

  v1 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  if ( *(_BYTE *)(v1 + 2) )
  {
    v2 = *(_QWORD *)(v1 + 88);
    result = 0;
    if ( v2 )
    {
      if ( (v2 & 1) == 0 )
        return (((v2 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
             + *(unsigned int *)(v1 + 100);
    }
  }
  else
  {
    v4 = *(_QWORD *)(v1 + 8);
    if ( v4 )
      return *(_QWORD *)(v4 + 224);
    else
      return *(_QWORD *)(a1 + 224);
  }
  return result;
}
