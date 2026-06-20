unsigned __int8 *__fastcall lim_iterate_triplets(
        unsigned __int8 *result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8
  __int64 v13; // x9
  unsigned __int64 *v14; // x10

  if ( result[4] <= 0xC8u || result[8] >= 0xC9u )
  {
    v12 = result[7];
    if ( result[7] )
    {
      v13 = 0;
      v14 = (unsigned __int64 *)(result + 8);
      while ( v13 != 80 )
      {
        if ( *((unsigned __int8 *)v14 + 3 * v13) < 0xC9u || v12 - 1 <= v13 )
        {
          ++v13;
        }
        else
        {
          if ( v13 == 79 )
            break;
          ++v13;
          if ( *((unsigned __int8 *)v14 + 3 * v13) < 0xC9u )
            return result;
        }
        if ( v13 == v12 )
          return (unsigned __int8 *)qdf_trace_msg(
                                      0x35u,
                                      8u,
                                      "%s: No operating class triplet followed by sub-band triplet",
                                      a3,
                                      a4,
                                      a5,
                                      a6,
                                      a7,
                                      a8,
                                      a9,
                                      a10,
                                      "lim_iterate_triplets",
                                      v10,
                                      v11);
      }
      __break(0x5512u);
      atomic_store(v10, v14);
      return (unsigned __int8 *)lim_get_max_tx_power(result, a2);
    }
    else
    {
      return (unsigned __int8 *)qdf_trace_msg(
                                  0x35u,
                                  8u,
                                  "%s: No operating class triplet followed by sub-band triplet",
                                  a3,
                                  a4,
                                  a5,
                                  a6,
                                  a7,
                                  a8,
                                  a9,
                                  a10,
                                  "lim_iterate_triplets",
                                  v10,
                                  v11);
    }
  }
  return result;
}
