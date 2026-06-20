__int64 __fastcall sde_hw_intf_setup_dpu_sync_prog_intf_offset(__int64 a1, __int64 a2)
{
  __int64 v2; // x2

  if ( *(_BYTE *)a2 )
    v2 = *(unsigned int *)(a2 + 4);
  else
    v2 = 0;
  return sde_reg_write(a1, 404, v2, "INTF_DPU_SYNC_PROG_INTF_OFFSET_EN");
}
