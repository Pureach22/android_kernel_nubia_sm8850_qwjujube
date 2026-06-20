__int64 __fastcall hdd_update_beacon_rate(
        __int64 result,
        __int64 a2,
        unsigned int **a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x10
  int v14; // w9
  __int64 v15; // x12
  int v16; // w10
  int v17; // w11
  __int16 *v18; // x12
  __int16 v19; // w5

  v13 = **a3;
  if ( (unsigned int)v13 >= 6 )
  {
    __break(0x5512u);
    return hdd_update_he_obss_pd(result, a2);
  }
  else
  {
    v14 = *((_DWORD *)a3 + 15 * (unsigned int)v13 + 99);
    if ( v14 )
    {
      v15 = *(_QWORD *)(a2 + 8 * v13 + 328);
      if ( v15 && (v16 = *(_DWORD *)(v15 + 24), v16 >= 1) )
      {
        v17 = 0;
        v18 = (__int16 *)(*(_QWORD *)(v15 + 8) + 4LL);
        while ( v14 != 1 << v17 )
        {
          ++v17;
          v18 += 6;
          if ( v16 == v17 )
            goto LABEL_8;
        }
        v19 = *v18;
      }
      else
      {
LABEL_8:
        v19 = 0;
      }
      *(_WORD *)(result + 2072) = v19;
      return qdf_trace_msg(
               0x33u,
               8u,
               "%s: beacon mask value %u, rate %hu",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "hdd_update_beacon_rate",
               *((unsigned int *)a3 + 99),
               v11,
               v12);
    }
  }
  return result;
}
