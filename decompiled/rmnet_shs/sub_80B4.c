__int64 sub_80B4()
{
  __asm { SUBG            X21, X28, #0x2C0, #2 }
  return rmnet_shs_hstat_tbl_add();
}
