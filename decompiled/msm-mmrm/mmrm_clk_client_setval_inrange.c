__int64 __fastcall mmrm_clk_client_setval_inrange(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 152)) != 0 && (v2 = *(__int64 (**)(void))(v1 + 24)) != nullptr )
  {
    if ( *((_DWORD *)v2 - 1) != -1711376514 )
      __break(0x8228u);
    return v2();
  }
  else
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_DCD6, "err ", "mmrm_clk_client_setval_inrange");
    return 4294967274LL;
  }
}
