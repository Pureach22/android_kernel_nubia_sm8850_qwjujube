void rmnet_flush_buffered()
{
  unsigned __int64 StatusReg; // x8
  __int64 v1; // x0

  if ( qword_19468 )
  {
    if ( HIBYTE(word_19492) == 1 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      *(_DWORD *)(StatusReg + 16) += 512;
      v1 = rmnet_shs_flush_table(0, 1);
      local_bh_enable(v1);
    }
  }
}
