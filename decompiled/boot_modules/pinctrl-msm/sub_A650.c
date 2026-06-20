__int64 sub_A650()
{
  __asm { PRFM            #8, 0xFFFFFFFFFFF18D34 }
  return msm_get_function_name();
}
