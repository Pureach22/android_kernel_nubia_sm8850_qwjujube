__int64 __fastcall osif_dp_hif_napi_gro_flush(__int64 a1)
{
  unsigned __int64 StatusReg; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  napi_gro_flush(a1 + 2696, 0);
  return local_bh_enable_0();
}
