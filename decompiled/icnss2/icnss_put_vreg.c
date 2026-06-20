__int64 __fastcall icnss_put_vreg(__int64 result)
{
  unsigned __int64 **v1; // x9
  unsigned __int64 *v2; // x10
  unsigned __int64 v3; // x11
  unsigned __int64 **v4; // x8
  unsigned __int64 v5; // x12

  v1 = (unsigned __int64 **)(result + 216);
  v2 = *(unsigned __int64 **)(result + 216);
  if ( v2 != (unsigned __int64 *)(result + 216) )
  {
    v3 = 0xDEAD000000000100LL;
    do
    {
      v4 = (unsigned __int64 **)v2[1];
      if ( *v4 == v2 && (v5 = *v2, *(unsigned __int64 **)(*v2 + 8) == v2) )
      {
        *(_QWORD *)(v5 + 8) = v4;
        *v4 = (unsigned __int64 *)v5;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v2);
      }
      *v2 = v3;
      v2[1] = v3 + 34;
      v2 = *v1;
    }
    while ( *v1 != (unsigned __int64 *)v1 );
  }
  return result;
}
