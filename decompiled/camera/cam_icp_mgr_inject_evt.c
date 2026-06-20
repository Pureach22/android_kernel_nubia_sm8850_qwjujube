__int64 __fastcall cam_icp_mgr_inject_evt(__int64 result, __int64 *a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x11
  const char *v5; // x6
  const char *v6; // x7

  if ( result && a2 )
  {
    v2 = a2[2];
    v3 = *a2;
    v4 = a2[1];
    *(_QWORD *)(result + 29992) = a2[3];
    *(_QWORD *)(result + 29984) = v2;
    *(_QWORD *)(result + 29976) = v4;
    *(_QWORD *)(result + 29968) = v3;
    *(_BYTE *)(result + 29996) = 1;
  }
  else
  {
    if ( result )
      v5 = "Non-NULL";
    else
      v5 = "NULL";
    if ( a2 )
      v6 = "Non-NULL";
    else
      v6 = "NULL";
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_mgr_inject_evt",
             9938,
             "Invalid params ctx data %s event params %s",
             v5,
             v6);
  }
  return result;
}
