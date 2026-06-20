__int64 __fastcall policy_mgr_add_24g_to_pcl(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        unsigned int *a4,
        char a5,
        __int64 a6,
        unsigned __int8 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v15; // x29
  __int64 v16; // x30
  unsigned int v17; // w10
  unsigned int v18; // w11
  unsigned int v20; // w5
  unsigned int v21; // w13
  __int64 v22; // x12
  __int64 v23; // x11
  int v24; // w14
  unsigned int v25; // w10

  v17 = *a4;
  if ( *a4 <= 0x65 && v17 < a3 )
  {
    v18 = v17 + a7;
    if ( v18 >= a3 )
      v18 = a3;
    v20 = v18 - v17;
    if ( a3 >= 0x66 )
      v21 = 102;
    else
      v21 = a3;
    if ( a7 )
    {
      v22 = 0;
      if ( v20 <= 1 )
        v23 = 1;
      else
        v23 = v20;
      while ( 1 )
      {
        v17 = *a4;
        if ( (unsigned int)v22 + *a4 >= v21 )
          break;
        *(_BYTE *)(a2 + (unsigned int)v22 + *a4) = a5;
        v24 = *(_DWORD *)(a6 + 4 * v22);
        v25 = v22++ + *a4;
        *(_DWORD *)(result + 4LL * v25) = v24;
        if ( v23 == v22 )
        {
          v17 = *a4;
          goto LABEL_17;
        }
      }
      LODWORD(v23) = v22;
    }
    else
    {
      LODWORD(v23) = 0;
    }
LABEL_17:
    *a4 = v17 + v23;
    return qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: Add 24g chlist len %d len %d index %d",
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             "policy_mgr_add_24g_to_pcl",
             v15,
             v16);
  }
  return result;
}
