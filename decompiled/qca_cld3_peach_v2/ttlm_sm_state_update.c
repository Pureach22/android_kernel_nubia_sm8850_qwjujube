unsigned int *__fastcall ttlm_sm_state_update(
        unsigned int *result,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *v12; // x20

  if ( result )
  {
    if ( a2 > 2 )
    {
      v12 = result;
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: ML peer %d state (%d) is invalid",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "ttlm_set_state",
        result[25],
        a2);
      result = v12;
    }
    else
    {
      result[182] = a2;
    }
    if ( a3 - 4 > 5 )
      return (unsigned int *)qdf_trace_msg(
                               0x99u,
                               2u,
                               "%s: ML peer %d sub state (%d) is invalid",
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10,
                               a11,
                               "ttlm_set_substate",
                               result[25],
                               a3);
    else
      result[183] = a3;
  }
  return result;
}
