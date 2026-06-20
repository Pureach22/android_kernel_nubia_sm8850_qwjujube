__int64 __fastcall tmc_get_memwidth_mask(__int64 a1)
{
  unsigned int v1; // w8

  v1 = *(_DWORD *)(a1 + 144) - 1;
  if ( v1 > 7 )
    return 0;
  else
    return dword_10994[v1];
}
