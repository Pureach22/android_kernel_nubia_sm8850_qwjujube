__int64 __fastcall sde_hw_reg_dma_flush(__int64 a1, char a2)
{
  __int64 ops; // x0
  __int64 v5; // x8
  _DWORD *v6; // x8

  ops = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1784));
  if ( !ops )
  {
    printk(&unk_221363, "sde_hw_reg_dma_flush");
    return 4294967274LL;
  }
  if ( !a1 )
    return 4294967274LL;
  v5 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v5 >= 3 )
  {
    __break(0x5512u);
    return sde_hw_ctl_get_start_state();
  }
  else
  {
    v6 = *(_DWORD **)(ops + 8 * v5 + 72);
    if ( v6 )
    {
      if ( *(v6 - 1) != 112044836 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, _QWORD, bool))v6)(a1, 0, (a2 & 1) == 0);
    }
    else
    {
      return 0;
    }
  }
}
