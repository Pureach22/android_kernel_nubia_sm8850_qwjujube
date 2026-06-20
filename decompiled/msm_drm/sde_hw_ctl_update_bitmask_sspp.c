__int64 __fastcall sde_hw_ctl_update_bitmask_sspp(__int64 a1, int a2, char a3)
{
  __int64 v3; // x8
  __int64 v4; // x9

  if ( !a1 )
    return 4294967274LL;
  if ( (unsigned int)(a2 - 1) >= 0xE )
  {
    printk(&unk_228273, "sde_hw_ctl_update_bitmask_sspp");
    return 4294967274LL;
  }
  else
  {
    v3 = *(unsigned int *)(a1 + 96);
    if ( (a3 & 1) != 0 )
      v4 = (1LL << sspp_tbl[a2]) | v3;
    else
      LODWORD(v4) = ~(1 << sspp_tbl[a2]) & v3;
    *(_DWORD *)(a1 + 96) = v4;
    return 0;
  }
}
