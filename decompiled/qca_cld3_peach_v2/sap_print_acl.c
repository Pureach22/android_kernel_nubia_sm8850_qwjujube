__int64 __fastcall sap_print_acl(
        unsigned __int8 *a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 i; // x21
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  int v24; // w8
  __int64 result; // x0
  __int64 v26; // [xsp+0h] [xbp-10h]

  v11 = a2;
  qdf_trace_msg(0x39u, 8u, "%s: print acl entered", a3, a4, a5, a6, a7, a8, a9, a10, "sap_print_acl");
  if ( !a1 || (unsigned int)(v11 - 33) < 0xFFFFFFE0 )
    return qdf_trace_msg(
             0x39u,
             2u,
             "%s: Either buffer is NULL or size %d is incorrect",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "sap_print_acl",
             (unsigned int)v11);
  for ( i = 0; i != v11; ++i )
  {
    if ( a1 )
    {
      v21 = *a1;
      v22 = a1[1];
      v23 = a1[2];
      v24 = a1[5];
    }
    else
    {
      v23 = 0;
      v21 = 0;
      v22 = 0;
      v24 = 0;
    }
    LODWORD(v26) = v24;
    result = qdf_trace_msg(
               0x39u,
               8u,
               "%s: ** ACL entry %i - %02x:%02x:%02x:**:**:%02x",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "sap_print_acl",
               (unsigned int)i,
               v21,
               v22,
               v23,
               v26);
    a1 += 6;
  }
  return result;
}
