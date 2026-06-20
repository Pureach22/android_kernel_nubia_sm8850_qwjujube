unsigned __int8 *__fastcall t2lm_gen_dialog_token(
        unsigned __int8 *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int16 v9; // w8
  unsigned __int8 *v10; // x19
  unsigned __int8 v11; // w8

  if ( result )
  {
    v9 = *result;
    v10 = result;
    if ( ((v9 + 1) & 0x100) != 0 )
      v11 = 1;
    else
      v11 = v9 + 1;
    *result = v11;
    qdf_trace_msg(0x99u, 8u, "%s: gen dialog token %d", a2, a3, a4, a5, a6, a7, a8, a9, "t2lm_gen_dialog_token", v11);
    return (unsigned __int8 *)*v10;
  }
  return result;
}
