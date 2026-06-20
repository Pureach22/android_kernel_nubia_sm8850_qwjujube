__int64 __fastcall reg_dma_submit_queue_v4(_QWORD *a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v7; // x8

  v3 = *(unsigned int *)(*a1 + 64LL);
  if ( (unsigned int)v3 >= 7
    || (sde_reg_write(a2, reg_dma_ctl_queue_off[v3], *(_DWORD *)(a1[2] + 24LL), "reg_dma_ctl_queue_off[cfg->ctl->idx]"),
        v7 = *(unsigned int *)(*a1 + 64LL),
        (unsigned int)v7 > 6) )
  {
    __break(0x5512u);
    JUMPOUT(0x19CF40);
  }
  return sde_reg_write(a2, reg_dma_ctl_queue_off[v7] + 4, a3, "reg_dma_ctl_queue_off[cfg->ctl->idx] + 0x4");
}
