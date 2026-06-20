__int64 sub_81C0()
{
  __asm { SUBG            X21, X28, #0x2C0, #2 }
  return rmnet_shs_hstat_tbl_remove();
}
