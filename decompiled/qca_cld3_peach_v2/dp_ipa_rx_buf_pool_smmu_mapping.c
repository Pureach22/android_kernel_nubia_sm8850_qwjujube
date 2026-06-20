__int64 __fastcall dp_ipa_rx_buf_pool_smmu_mapping(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        char a11,
        char a12,
        __int64 a13,
        unsigned int a14)
{
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) & 1) != 0 )
    dp_ipa_handle_rx_buf_pool_smmu_mapping(a1, a12 & 1, a11 & 1, a13, a14, 2);
  else
    qdf_trace_msg(0x45u, 8u, "%s: SMMU S1 disabled", a2, a3, a4, a5, a6, a7, a8, a9, "dp_ipa_rx_buf_pool_smmu_mapping");
  return 0;
}
