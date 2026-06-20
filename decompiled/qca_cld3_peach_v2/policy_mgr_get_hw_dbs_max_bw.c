__int64 __fastcall policy_mgr_get_hw_dbs_max_bw(__int64 a1, int *a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  unsigned __int64 i; // x23
  __int64 v14; // x8

  result = policy_mgr_get_context(a1);
  if ( !result )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "policy_mgr_get_hw_dbs_max_bw");
  v12 = result;
  if ( *(_DWORD *)(result + 1184) )
  {
    for ( i = 0; i < *(unsigned int *)(v12 + 1184); ++i )
    {
      v14 = *(_QWORD *)(*(_QWORD *)(v12 + 1192) + 8 * i);
      if ( (v14 & 0xA0) != 0 )
      {
        if ( (v14 & 0x80) != 0 )
          goto LABEL_9;
      }
      else
      {
        *a2 = (unsigned __int16)v14 >> 12;
        if ( (v14 & 0x80) != 0 )
        {
LABEL_9:
          *a2 = (unsigned __int16)v14 >> 12;
          a2[1] = ((unsigned int)v14 >> 8) & 0xF;
          result = qdf_trace_msg(
                     0x4Fu,
                     8u,
                     "%s: mac0_bw %d mac1_bw %d",
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     "policy_mgr_get_hw_dbs_max_bw");
        }
      }
    }
  }
  return result;
}
