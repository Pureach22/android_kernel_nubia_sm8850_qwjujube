unsigned __int64 __fastcall sub_19E45C(_QWORD *a1, char a2, int a3)
{
  if ( (a3 & 0x2000000) != 0 )
    return sde_reg_dma_aspace_cb_locked(a1, a2);
  else
    return sde_hw_dsc_config();
}
