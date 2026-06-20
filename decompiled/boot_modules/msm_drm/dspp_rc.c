__int64 __fastcall dspp_rc(__int64 result)
{
  _QWORD *v1; // x19
  __int64 (__fastcall *v2)(__int64, __int64); // x8
  __int64 (__fastcall *v3)(__int64, __int64 *); // x9

  if ( !result )
    return printk(&unk_26FEB0, "dspp_rc");
  v1 = (_QWORD *)result;
  if ( (*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 532LL) & 0xFFFFFFFE) == 0x10000 )
  {
    if ( (unsigned int)sde_hw_rc_init(result) )
    {
      return printk(&unk_243AC5, "dspp_rc");
    }
    else
    {
      result = reg_dmav1_init_dspp_op_v4(0x11u, (__int64)v1);
      if ( (_DWORD)result )
      {
        v2 = (__int64 (__fastcall *)(__int64, __int64))sde_hw_rc_setup_pu_roi;
        v3 = (__int64 (__fastcall *)(__int64, __int64 *))&sde_hw_rc_setup_mask;
      }
      else
      {
        v3 = reg_dmav1_setup_rc_mask_configv1;
        v2 = reg_dmav1_setup_rc_pu_configv1;
        v1[102] = reg_dmav1_setup_rc_mask_configv1;
      }
      v1[101] = v3;
      v1[107] = v2;
      v1[98] = sde_hw_rc_check_mask;
      v1[104] = sde_hw_rc_check_pu_roi;
      v1[99] = sde_hw_rc_check_mask;
    }
  }
  return result;
}
