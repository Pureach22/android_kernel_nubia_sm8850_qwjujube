__int64 __fastcall qcom_icc_rpmh_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  qcom_icc_debug_unregister(v1);
  clk_bulk_put_all(*(unsigned int *)(v1 + 176), *(_QWORD *)(v1 + 168));
  icc_provider_deregister(v1);
  return icc_nodes_remove(v1);
}
