__int64 __fastcall gsi_get_drop_stats(int a1, int a2, __int64 a3)
{
  __int64 v3; // x1
  __int64 v4; // x0
  unsigned int reg_nk; // w0

  if ( *(_DWORD *)(gsi_ctx + 16) < 0xAu )
  {
    if ( a2 == 5 )
    {
      a3 = 0;
      v3 = (unsigned int)(12 * a1 + 7);
      v4 = 138;
      return (unsigned __int16)gsihal_read_reg_nk(v4, v3, a3);
    }
    return 0;
  }
  else
  {
    switch ( a2 )
    {
      case 7:
        reg_nk = gsihal_read_reg_nk(63, *(unsigned int *)(gsi_ctx + 20), a3);
        return (HIWORD(reg_nk) & 0x1FFF) + (reg_nk & 0x1FFF);
      case 6:
        return gsihal_read_reg_nk(62, *(unsigned int *)(gsi_ctx + 20), a3);
      case 5:
        v3 = *(unsigned int *)(gsi_ctx + 20);
        v4 = 61;
        return (unsigned __int16)gsihal_read_reg_nk(v4, v3, a3);
      default:
        dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid scratch id %d\n", "gsi_get_drop_stats", 5546, a2);
        return 0;
    }
  }
}
