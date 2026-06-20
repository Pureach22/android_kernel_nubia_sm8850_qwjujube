__int64 __fastcall get_mst_branch_device_by_guid_helper(__int64 result, _QWORD *a2)
{
  _QWORD *v4; // x20
  _QWORD *v5; // x21

  if ( result )
  {
    if ( *(_QWORD *)(result + 73) != *a2 || *(_QWORD *)(result + 81) != a2[1] )
    {
      v4 = (_QWORD *)(result + 40);
      v5 = (_QWORD *)(result + 40);
      while ( 1 )
      {
        v5 = (_QWORD *)*v5;
        if ( v5 == v4 )
          break;
        result = get_mst_branch_device_by_guid_helper(v5[2], a2);
        if ( result )
          return result;
      }
      return 0;
    }
  }
  return result;
}
