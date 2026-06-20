_QWORD *__fastcall gh_rm_booster_mpidr(_QWORD *result)
{
  *result = _ReadStatusReg(MPIDR_EL1);
  return result;
}
