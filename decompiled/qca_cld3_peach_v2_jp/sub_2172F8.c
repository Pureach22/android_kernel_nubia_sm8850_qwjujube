__int64 __usercall sub_2172F8@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        __int64 a6@<X8>)
{
  __int64 v6; // x13
  __int128 v7; // t2

  *((_QWORD *)&v7 + 1) = v6;
  *(_QWORD *)&v7 = a6;
  return wmi_unified_rtt_keepalive_req_cmd_send(a1, a2, a3, a4, a5, v7 >> 24);
}
