unsigned __int64 qdf_get_current_comm()
{
  return _ReadStatusReg(SP_EL0) + 2320;
}
