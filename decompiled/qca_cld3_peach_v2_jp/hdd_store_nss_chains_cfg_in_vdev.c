__int64 __fastcall hdd_store_nss_chains_cfg_in_vdev(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 result; // x0
  _QWORD v7[8]; // [xsp+0h] [xbp-40h] BYREF

  v7[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(unsigned int *)(a2 + 16);
  v5 = *(unsigned int *)(a1 + 1248);
  memset(v7, 0, 56);
  sme_populate_nss_chain_params(v3, v7, v4, v5);
  result = sme_store_nss_chains_cfg_in_vdev(a2, v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
