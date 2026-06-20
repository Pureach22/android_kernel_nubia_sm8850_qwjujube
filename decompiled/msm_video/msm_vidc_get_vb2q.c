_QWORD *__fastcall msm_vidc_get_vb2q(_QWORD *result, int a2)
{
  if ( a2 > 12 )
  {
    if ( a2 == 13 )
      return (_QWORD *)result[233];
    if ( a2 == 14 )
      return (_QWORD *)result[232];
  }
  else
  {
    if ( a2 == 9 )
      return (_QWORD *)result[231];
    if ( a2 == 10 )
      return (_QWORD *)result[230];
  }
  if ( result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_88043, "err ", (char *)result + 340, "msm_vidc_get_vb2q", (unsigned int)a2);
    return nullptr;
  }
  return result;
}
