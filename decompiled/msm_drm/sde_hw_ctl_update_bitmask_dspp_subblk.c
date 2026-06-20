__int64 __fastcall sde_hw_ctl_update_bitmask_dspp_subblk(_DWORD *a1, int a2, int a3, char a4)
{
  __int64 v4; // x9
  unsigned int v5; // w9

  if ( a1 && (unsigned int)(a2 - 5) >= 0xFFFFFFFC && (unsigned int)(a3 - 25) > 0xFFFFFFE7 )
  {
    v4 = (unsigned int)a1[a2 - 1 + 33];
    if ( (a4 & 1) != 0 )
      v4 |= 1LL << dspp_sub_blk_flush_tbl[a3];
    else
      LODWORD(v4) = ~(1 << dspp_sub_blk_flush_tbl[a3]) & v4;
    a1[a2 - 1 + 33] = v4;
    if ( a1[33] || a1[34] || a1[35] || a1[36] )
      v5 = a1[24] | 0x20000000;
    else
      v5 = a1[24] & 0xDFFFFFFF;
    a1[24] = v5;
    return 0;
  }
  else
  {
    printk(&unk_270ED7, "sde_hw_ctl_update_bitmask_dspp_subblk");
    return 4294967274LL;
  }
}
