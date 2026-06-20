__int64 __fastcall validate_ie_attr(_WORD *a1, _QWORD *a2)
{
  char *v4; // x8
  unsigned __int64 v5; // x10
  char *v6; // x9
  __int64 v7; // x11

  v4 = (char *)(a1 + 2);
  v5 = (unsigned __int16)(*a1 - 4);
  v6 = (char *)a1 + v5 + 4;
  if ( (unsigned __int16)(*a1 - 4) >= 2u )
  {
    do
    {
      v7 = (unsigned __int8)v4[1];
      if ( v5 < v7 + 2 )
        break;
      v4 += v7 + 2;
      v5 = v6 - v4;
    }
    while ( v6 - v4 > 1 );
  }
  if ( v6 == v4 )
    return 0;
  do_trace_netlink_extack("malformed information elements");
  if ( a2 )
  {
    *a2 = "malformed information elements";
    a2[1] = a1;
    a2[2] = 0;
  }
  return 4294967274LL;
}
