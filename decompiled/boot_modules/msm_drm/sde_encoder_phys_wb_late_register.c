__int64 __fastcall sde_encoder_phys_wb_late_register(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8

  if ( !a1 )
    return 4294967274LL;
  v2 = -22;
  if ( a2 )
  {
    if ( *(_QWORD *)(a1 + 2680) )
    {
      debugfs_create_u32("wbdone_timeout", 384, a2, a1 + 2688);
      return 0;
    }
  }
  return v2;
}
