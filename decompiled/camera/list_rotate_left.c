__int64 __fastcall list_rotate_left(__int64 result)
{
  __int64 *v1; // x9
  __int64 **v2; // x8
  __int64 v3; // x10
  __int64 *v4; // x1
  __int64 v5; // x10

  v1 = *(__int64 **)result;
  if ( *(_QWORD *)result != result )
  {
    v2 = (__int64 **)v1[1];
    if ( *v2 == v1 && (v3 = *v1, *(__int64 **)(*v1 + 8) == v1) )
    {
      *(_QWORD *)(v3 + 8) = v2;
      *v2 = (__int64 *)v3;
    }
    else
    {
      _list_del_entry_valid_or_report(v1);
      result = v5;
    }
    v4 = *(__int64 **)(result + 8);
    if ( v4 == v1 || *v4 != result )
    {
      return _list_add_valid_or_report(v1);
    }
    else
    {
      *(_QWORD *)(result + 8) = v1;
      *v1 = result;
      v1[1] = (__int64)v4;
      *v4 = (__int64)v1;
    }
  }
  return result;
}
