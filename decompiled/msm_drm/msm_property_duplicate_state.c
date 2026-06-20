void *__fastcall msm_property_duplicate_state(__int64 a1, const void *a2, void *dest, _QWORD *a4, __int64 a5)
{
  void *result; // x0
  __int64 v9; // x21
  unsigned __int64 v10; // x22
  __int64 v11; // x8
  __int64 v12; // x8

  if ( !a1 || !a2 || !dest )
    return (void *)_drm_err("invalid argument(s)\n", a2, dest);
  result = memcpy(dest, a2, *(unsigned int *)(a1 + 72));
  if ( a4 )
  {
    a4[2] = a4 + 2;
    a4[3] = a4 + 2;
    a4[1] = a5;
    if ( a5 )
    {
      if ( *(_DWORD *)(a1 + 32) )
      {
        v9 = 0;
        v10 = 0;
        do
        {
          v12 = a4[1];
          result = *(void **)(v12 + v9 + 8);
          if ( result )
          {
            result = (void *)drm_property_blob_get();
            v12 = a4[1];
          }
          v11 = v12 + v9;
          ++v10;
          v9 += 32;
          *(_QWORD *)(v11 + 16) = v11 + 16;
          *(_QWORD *)(v11 + 24) = v11 + 16;
        }
        while ( v10 < *(unsigned int *)(a1 + 32) );
      }
    }
  }
  return result;
}
