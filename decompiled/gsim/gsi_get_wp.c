__int64 __fastcall gsi_get_wp(__int64 a1)
{
  return gsihal_read_reg_nk(68, *(unsigned int *)(gsi_ctx + 20), a1);
}
