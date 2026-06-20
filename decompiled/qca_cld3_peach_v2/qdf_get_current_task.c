unsigned __int64 qdf_get_current_task()
{
  return _ReadStatusReg(SP_EL0);
}
