__int64 __fastcall msm_buffer_extra_count_iris4(__int64 a1, int a2)
{
  __int64 result; // x0
  unsigned int v5; // w21
  __int64 v6; // x0

  result = 0;
  if ( a2 > 2 )
  {
    if ( a2 == 4 )
      goto LABEL_10;
    if ( a2 != 3 )
      goto LABEL_8;
LABEL_7:
    result = msm_vidc_input_extra_count(a1);
    goto LABEL_8;
  }
  if ( a2 == 1 )
    goto LABEL_7;
  if ( a2 != 2 )
  {
LABEL_8:
    if ( !a1 )
      return result;
    goto LABEL_11;
  }
LABEL_10:
  result = msm_vidc_output_extra_count(a1);
  if ( !a1 )
    return result;
LABEL_11:
  if ( (msm_vidc_debug & 4) != 0 )
  {
    v5 = result;
    v6 = buf_name((unsigned int)a2);
    printk(&unk_91F64, "low ", a1 + 340, v6, v5);
    return v5;
  }
  return result;
}
