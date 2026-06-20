__int64 qdf_mem_malloc_flags()
{
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    return 2080;
  if ( *(_DWORD *)(StatusReg + 16) )
    return 2080;
  result = 2080;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    if ( *(_DWORD *)(StatusReg + 1412) )
      return 2080;
    else
      return 3264;
  }
  return result;
}
