__int64 __fastcall dp_ipa_cleanup(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  unsigned int v6; // w20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w3
  int v16; // w4
  int v17; // w5
  int v18; // w6
  int v19; // w7
  __int64 v20; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  char v24; // [xsp+0h] [xbp+0h]

  v6 = ipa_wdi_disconn_pipes_per_inst(a5);
  if ( v6 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: ipa_wdi_disconn_pipes: IPA pipe cleanup failed: ret=%d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_ipa_cleanup",
      v6);
    wlan_ipa_log_message(
      (int)"dp_ipa_cleanup",
      (int)"ipa_wdi_disconn_pipes: IPA pipe cleanup failed: ret=%d",
      v6,
      v15,
      v16,
      v17,
      v18,
      v19,
      v24);
    v6 = 16;
  }
  v20 = *(_QWORD *)(a1 + 24);
  if ( *(_BYTE *)(v20 + 608) == 1 )
  {
    if ( (unsigned int)pld_smmu_unmap(*(_QWORD *)(v20 + 40), *(_DWORD *)(a1 + 18488), 4) )
    {
      v22 = printk(
              &unk_AAA255,
              "!ret",
              "dp_ipa_unmap_ring_doorbell_paddr",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
      dump_stack(v22);
    }
    if ( (unsigned int)pld_smmu_unmap(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), *(_DWORD *)(a1 + 18472), 4) )
    {
      v23 = printk(
              &unk_AAA255,
              "!ret",
              "dp_ipa_unmap_ring_doorbell_paddr",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
      dump_stack(v23);
    }
  }
  return v6;
}
