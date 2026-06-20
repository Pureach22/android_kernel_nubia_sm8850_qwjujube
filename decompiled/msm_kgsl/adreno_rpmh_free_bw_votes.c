__int64 __fastcall adreno_rpmh_free_bw_votes(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned int v3; // w20

  if ( result )
  {
    v1 = result;
    v2 = *(_QWORD *)(result + 24);
    if ( v2 )
    {
      v3 = 0;
      do
      {
        if ( v3 >= *(_DWORD *)(v1 + 16) )
          break;
        kfree(*(_QWORD *)(v2 + 8LL * (int)v3));
        v2 = *(_QWORD *)(v1 + 24);
        ++v3;
      }
      while ( v2 );
    }
    kfree(v2);
    kfree(*(_QWORD *)(v1 + 8));
    return kfree(v1);
  }
  return result;
}
