__int64 __fastcall i2c_pmic_suspend_noirq(__int64 a1)
{
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 152) + 105LL) != 1 )
    return 0;
  if ( (unsigned int)__ratelimit(&i2c_pmic_suspend_noirq__rs, "i2c_pmic_suspend_noirq") )
    dev_err(a1, "Aborting suspend, an interrupt was detected while suspending\n");
  return 4294967280LL;
}
