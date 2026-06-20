__int64 __fastcall nla_parse_nested(__int64 a1, __int64 a2, _WORD *a3, __int64 a4, _QWORD *a5)
{
  if ( (__int16)a3[1] < 0 )
    return _nla_parse(a1, a2, a3 + 2, (unsigned __int16)(*a3 - 4), a4, 31, a5);
  do_trace_netlink_extack("NLA_F_NESTED is missing");
  if ( a5 )
  {
    *a5 = "NLA_F_NESTED is missing";
    a5[1] = a3;
    a5[2] = 0;
  }
  return 4294967274LL;
}
