__int64 __fastcall gsi_get_refetch_reg(__int64 a1, char a2)
{
  __int64 v3; // x0

  if ( (a2 & 1) != 0 )
    v3 = 120;
  else
    v3 = 121;
  return gsihal_read_reg_nk(v3, *(unsigned int *)(gsi_ctx + 20), a1);
}
