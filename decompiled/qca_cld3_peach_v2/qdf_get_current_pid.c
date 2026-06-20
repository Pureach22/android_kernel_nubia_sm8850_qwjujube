__int64 qdf_get_current_pid()
{
  return *(unsigned int *)(_ReadStatusReg(SP_EL0) + 1800);
}
