__int64 __fastcall sde_hw_intf_setup_prg_fetch(__int64 a1, __int64 a2)
{
  int v4; // w0
  __int64 v5; // x2
  unsigned int v6; // w20

  v4 = sde_reg_read(a1, 4);
  if ( *(_BYTE *)a2 )
  {
    v5 = *(unsigned int *)(a2 + 4);
    v6 = v4 | 0x80000000;
    sde_reg_write(a1, 368, v5, "INTF_PROG_FETCH_START");
  }
  else
  {
    v6 = v4 & 0x7FFFFFFF;
  }
  return sde_reg_write(a1, 4, v6, "INTF_CONFIG");
}
