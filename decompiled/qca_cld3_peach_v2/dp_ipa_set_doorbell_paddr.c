__int64 __fastcall dp_ipa_set_doorbell_paddr(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  unsigned __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x8
  int v7; // w0
  int v8; // w0
  __int64 v10; // x0
  __int64 v11; // x0
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 6000);
  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 )
  {
    v3 = *(_QWORD *)(a1 + 18472);
    v12[0] = 0;
    if ( *(_BYTE *)(a1 + 18496) == 1 )
    {
      v4 = (v3 - memstart_addr) | 0xFFFFFF8000000000LL;
    }
    else
    {
      if ( arm64_use_ng_mappings )
        v5 = 0x68000000000F13LL;
      else
        v5 = 0x68000000000713LL;
      v4 = ioremap_prot(v3, 4, v5);
    }
    v6 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)(a1 + 18480) = v4;
    if ( *(_BYTE *)(v6 + 608) == 1 )
    {
      v7 = pld_smmu_map(*(_QWORD *)(v6 + 40), *(_QWORD *)(a1 + 18472), (__int64)v12, 4);
      *(_QWORD *)(a1 + 18472) = LODWORD(v12[0]);
      if ( v7 )
      {
        v10 = printk(
                &unk_AAA255,
                "!ret",
                "dp_ipa_map_ring_doorbell_paddr",
                "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
        dump_stack(v10);
      }
      v8 = pld_smmu_map(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), *(_QWORD *)(a1 + 18488), (__int64)v12 + 4, 4);
      *(_QWORD *)(a1 + 18488) = HIDWORD(v12[0]);
      if ( v8 )
      {
        v11 = printk(
                &unk_AAA255,
                "!ret",
                "dp_ipa_map_ring_doorbell_paddr",
                "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
        dump_stack(v11);
      }
    }
    hal_srng_dst_set_hp_paddr_confirm(v2, *(_QWORD *)(a1 + 18488));
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
