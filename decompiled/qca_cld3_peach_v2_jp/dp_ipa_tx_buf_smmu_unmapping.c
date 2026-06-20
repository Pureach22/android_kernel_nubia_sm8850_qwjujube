__int64 __fastcall dp_ipa_tx_buf_smmu_unmapping(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) & 1) != 0 )
  {
    if ( (wlan_ipa_is_shared_smmu_enabled(a1) & 1) != 0 )
      return 0;
    else
      return 16 * (unsigned int)((unsigned int)_dp_ipa_tx_buf_smmu_mapping(a1, 0) != 0);
  }
  else
  {
    qdf_trace_msg(0x45u, 8u, "%s: SMMU S1 disabled", a2, a3, a4, a5, a6, a7, a8, a9, "dp_ipa_tx_buf_smmu_unmapping");
    return 0;
  }
}
