__int64 __fastcall dot11f_get_packed_tdls_setup_rsp_size(__int64 a1, __int64 a2, int *a3)
{
  *a3 = 7;
  return get_packed_size_core(a1, a2, a3, IES_TDLSSetupRsp);
}
