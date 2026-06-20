__int64 __fastcall cds_set_ring_log_level(__int64 result, unsigned int a2, __int64 a3, __int64 a4)
{
  _DWORD *v4; // x8
  int v5; // w9
  unsigned int v6; // w20
  unsigned int v7; // w21
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  v4 = (_DWORD *)gp_cds_context;
  if ( !gp_cds_context )
  {
    v6 = result;
    v7 = a2;
    printk(&unk_94D98D, "cds_get_global_context", a3, a4);
    v4 = (_DWORD *)gp_cds_context;
    a2 = v7;
    result = v6;
    if ( !gp_cds_context )
      return qdf_trace_msg(
               0x38u,
               2u,
               "%s: cds context is Invalid",
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               "cds_set_ring_log_level");
  }
  if ( a2 >= 3 )
    v5 = 3;
  else
    v5 = a2;
  if ( (int)result <= 1 )
  {
    if ( (_DWORD)result )
    {
      if ( (_DWORD)result == 1 )
        v4[23] = v5;
    }
    else
    {
      v4[22] = v5;
    }
  }
  else
  {
    switch ( (_DWORD)result )
    {
      case 2:
        v4[24] = v5;
        break;
      case 3:
        v4[25] = v5;
        break;
      case 4:
        v4[26] = v5;
        break;
    }
  }
  return result;
}
