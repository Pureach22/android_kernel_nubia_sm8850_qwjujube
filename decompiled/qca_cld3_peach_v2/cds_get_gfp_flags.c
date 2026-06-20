__int64 cds_get_gfp_flags()
{
  unsigned __int64 StatusReg; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || *(_DWORD *)(StatusReg + 16)
    || (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
    return 2080;
  }
  else
  {
    return 3264;
  }
}
