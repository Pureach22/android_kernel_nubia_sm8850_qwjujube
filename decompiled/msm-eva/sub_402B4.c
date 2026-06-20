__int64 sub_402B4()
{
  _ReadStatusReg(TPIDR_EL2);
  _X28 = _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  __asm { LDLAR           X20, [X28] }
  return cvp_buf_map_set_vaddr();
}
