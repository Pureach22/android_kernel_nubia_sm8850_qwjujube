__int64 __fastcall sde_hw_ds_setup_opmode_v1(__int64 a1, unsigned int a2, int a3)
{
  if ( (unsigned int)(a3 - 1) <= 2 )
    a2 = dword_28D8BC[a3 - 1];
  return sde_reg_write(
           a1,
           *(_DWORD *)(*(_QWORD *)(a1 + 40) + 20LL) + 12,
           a2,
           "DEST_SCALER_MERGE_CTRL + hw_ds->scl->base");
}
