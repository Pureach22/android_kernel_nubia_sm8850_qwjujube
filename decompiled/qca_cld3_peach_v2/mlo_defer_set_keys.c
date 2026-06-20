__int64 __fastcall mlo_defer_set_keys(
        __int64 result,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned __int8 *v12; // x10
  _BYTE *v13; // x8
  int v14; // w11
  int v15; // w12
  int v16; // w13
  __int64 v17; // x6
  _BYTE *v18; // x8
  __int64 v19; // x4
  __int64 v20; // x5

  if ( result )
  {
    v11 = *(_QWORD *)(result + 1360);
    if ( v11 )
    {
      v12 = *(unsigned __int8 **)(v11 + 2224);
      if ( v12 )
      {
        v13 = v12 + 16;
        if ( (a3 & 1) == 0 )
        {
          if ( v12[17] != a2 )
          {
            if ( v12[19] == a2 )
            {
              v13 = v12 + 18;
            }
            else
            {
              if ( v12[21] != a2 )
                return result;
              v13 = v12 + 20;
            }
          }
          v19 = a2;
          v20 = 0;
          *v13 = 0;
          return qdf_trace_msg(
                   0x8Fu,
                   8u,
                   "%s: set key link id %d value %d iter %d",
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   "mlo_defer_set_keys",
                   v19,
                   v20);
        }
        v14 = (unsigned __int8)*v13;
        if ( v14 != 1 || v12[17] != a2 )
        {
          v15 = v12[18];
          if ( v15 != 1 || v12[19] != a2 )
          {
            v16 = v12[20];
            if ( (v16 != 1 || v12[21] != a2) && ((v14 & v15) != 1 || (v16 & 1) == 0) )
            {
              if ( (v14 & v15) != 0 )
                v17 = 2;
              else
                v17 = (unsigned __int8)*v13;
              v18 = &v13[2 * v17];
              v19 = a2;
              v18[1] = a2;
              v20 = 1;
              *v18 = 1;
              return qdf_trace_msg(
                       0x8Fu,
                       8u,
                       "%s: set key link id %d value %d iter %d",
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11,
                       "mlo_defer_set_keys",
                       v19,
                       v20);
            }
          }
        }
      }
    }
  }
  return result;
}
