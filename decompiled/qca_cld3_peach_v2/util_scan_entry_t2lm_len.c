__int64 __fastcall util_scan_entry_t2lm_len(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x9
  int v3; // w8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 1840);
    if ( v1 )
    {
      v2 = *(_QWORD *)(result + 1848);
      v3 = *(unsigned __int8 *)(v1 + 1);
      if ( v2 )
        return v3 + (unsigned int)*(unsigned __int8 *)(v2 + 1) + 4;
      else
        return (unsigned int)(v3 + 2);
    }
    else
    {
      return 0;
    }
  }
  return result;
}
