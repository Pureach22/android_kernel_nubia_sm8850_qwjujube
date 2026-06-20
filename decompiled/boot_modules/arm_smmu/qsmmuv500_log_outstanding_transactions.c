__int64 __fastcall qsmmuv500_log_outstanding_transactions(__int64 a1)
{
  _QWORD *v2; // x19
  __int64 result; // x0
  _QWORD *i; // x21
  void (__fastcall *v5)(_QWORD); // x8

  v2 = (_QWORD *)(a1 - 360);
  if ( (unsigned int)mutex_trylock(&capture_reg_lock) )
  {
    if ( (unsigned int)arm_smmu_power_on(*(_QWORD *)(a1 - 56)) )
    {
      if ( (unsigned int)__ratelimit(
                           &qsmmuv500_log_outstanding_transactions__rs_21,
                           "qsmmuv500_log_outstanding_transactions") )
        dev_err(*v2, "%s: Failed to power on SMMU.\n", "qsmmuv500_log_outstanding_transactions");
    }
    else
    {
      for ( i = *(_QWORD **)(a1 - 32); i != (_QWORD *)(a1 - 32); i = (_QWORD *)*i )
      {
        if ( (unsigned int)arm_smmu_power_on(i[6]) )
        {
          if ( (unsigned int)__ratelimit(
                               &qsmmuv500_log_outstanding_transactions__rs_23,
                               "qsmmuv500_log_outstanding_transactions") )
            dev_err(i[2], "%s: Failed to power on TBU.\n", "qsmmuv500_log_outstanding_transactions");
        }
        else
        {
          v5 = *(void (__fastcall **)(_QWORD))(i[5] + 40LL);
          if ( *((_DWORD *)v5 - 1) != -475300232 )
            __break(0x8228u);
          v5(i);
          arm_smmu_power_off(v2, i[6]);
        }
      }
      arm_smmu_power_off(v2, *(_QWORD *)(a1 - 56));
    }
    return mutex_unlock(&capture_reg_lock);
  }
  else
  {
    result = __ratelimit(&qsmmuv500_log_outstanding_transactions__rs, "qsmmuv500_log_outstanding_transactions");
    if ( (_DWORD)result )
      return dev_warn(*v2, "Tnx snapshot regs in use, not dumping OT tnxs.\n");
  }
  return result;
}
