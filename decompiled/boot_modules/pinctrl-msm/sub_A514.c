__int64 sub_A514()
{
  __asm { PRFM            #8, 0xFFFFFFFFFFF18BF8 }
  return msm_get_group_name();
}
