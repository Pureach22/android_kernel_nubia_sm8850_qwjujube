__int64 __fastcall drm_dp_subconnector_type(_BYTE *a1, _BYTE *a2)
{
  __int64 v3; // x8
  unsigned int *v4; // x9

  if ( (a1[5] & 1) == 0 )
    return 15;
  if ( *a1 != 16 )
  {
    v3 = *a2 & 7;
    if ( (_DWORD)v3 != 7 )
    {
      v4 = (unsigned int *)&unk_1D5EC;
      return v4[v3];
    }
    return 0;
  }
  v3 = a1[5] & 6;
  if ( (unsigned int)v3 >= 5 )
    return 0;
  v4 = (unsigned int *)&unk_1D5D8;
  return v4[v3];
}
