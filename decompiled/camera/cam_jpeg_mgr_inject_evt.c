__int64 __fastcall cam_jpeg_mgr_inject_evt(__int64 result, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x10
  __int64 v4; // x11
  const char *v5; // x6
  const char *v6; // x7

  if ( result && a2 )
  {
    v2 = a2[3];
    v3 = *a2;
    v4 = a2[1];
    *(_QWORD *)(result + 176) = a2[2];
    *(_QWORD *)(result + 184) = v2;
    *(_QWORD *)(result + 160) = v3;
    *(_QWORD *)(result + 168) = v4;
    *(_BYTE *)(result + 188) = 1;
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
             512,
             1,
             "cam_jpeg_mgr_inject_evt",
             2281,
             "Invalid parameters ctx data %s event params %s",
             v5,
             v6);
  }
  return result;
}
