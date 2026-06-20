__int64 sub_69A4()
{
  __asm { PRFM            #8, 0xFFFFFFFFFFF15088 }
  return pmic_mpp_get_group_name();
}
