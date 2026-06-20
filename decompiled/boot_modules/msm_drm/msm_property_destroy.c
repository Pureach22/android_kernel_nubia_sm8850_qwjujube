__int64 __fastcall msm_property_destroy(__int64 result, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x19

  if ( result )
  {
    v2 = *(_DWORD *)(result + 76);
    v3 = result;
    if ( v2 >= 1 )
    {
      while ( 1 )
      {
        *(_DWORD *)(v3 + 76) = v2 - 1;
        if ( (unsigned int)v2 >= 3 )
          break;
        result = kfree(*(_QWORD *)(v3 + 56 + 8LL * (unsigned int)(v2 - 1)));
        v2 = *(_DWORD *)(v3 + 76);
        if ( v2 <= 0 )
          return result;
      }
      __break(0x5512u);
      return msm_property_pop_dirty(result, a2);
    }
  }
  return result;
}
