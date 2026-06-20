__int64 __fastcall ipa3_controller_static_bind(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x8
  int v8; // w9

  if ( (unsigned int)a2 >= 0x18 )
  {
    v4 = 2147483648600000000LL;
    v5 = 322122547440000000LL;
LABEL_7:
    *(_QWORD *)(a1 + 8) = v4;
    *(_QWORD *)(a1 + 16) = v5;
    goto LABEL_8;
  }
  if ( (unsigned int)a2 >= 0x15 )
  {
    v4 = 2147483648600000000LL;
    v5 = 515396075760000000LL;
    goto LABEL_7;
  }
  if ( (unsigned int)a2 >= 0xE )
  {
    v4 = 944892805370000000LL;
    v5 = 257698037885000000LL;
    goto LABEL_7;
  }
  if ( (unsigned int)a2 < 0xC )
  {
    *(_DWORD *)(a1 + 8) = 200000000;
    v8 = 37500000;
    *(_QWORD *)(a1 + 12) = 322122547350000000LL;
  }
  else
  {
    *(_DWORD *)(a1 + 16) = 200000000;
    *(_QWORD *)(a1 + 8) = 1717986918826400000LL;
    v8 = 100000000;
  }
  *(_DWORD *)(a1 + 20) = v8;
LABEL_8:
  *(_QWORD *)(a1 + 72) = ipa_init_rt4_v3;
  *(_QWORD *)(a1 + 80) = ipa_init_rt6_v3;
  *(_QWORD *)(a1 + 88) = ipa_init_flt4_v3;
  *(_QWORD *)(a1 + 96) = ipa_init_flt6_v3;
  *(_QWORD *)(a1 + 104) = ipa_read_ep_reg_v3_0;
  *(_QWORD *)(a1 + 112) = _ipa_commit_flt_v3;
  *(_QWORD *)(a1 + 120) = _ipa_commit_rt_v3;
  *(_QWORD *)(a1 + 128) = _ipa_commit_hdr_v3_0;
  *(_QWORD *)(a1 + 136) = ipa_enable_clks_v3_0;
  *(_QWORD *)(a1 + 144) = ipa_disable_clks_v3_0;
  *(_DWORD *)(a1 + 32) = 310;
  *(_QWORD *)(a1 + 24) = 0x258000003E8LL;
  if ( !(_DWORD)a3 )
    LODWORD(a3) = ipahal_get_reg_base(a1, a2, a3);
  *(_QWORD *)(a1 + 48) = ipa_sram_settings_read_v3_0;
  *(_QWORD *)(a1 + 56) = ipa_init_sram_v3;
  *(_QWORD *)(a1 + 64) = ipa_init_hdr_v3_0;
  v6 = ipa3_ctx;
  *(_DWORD *)(a1 + 36) = a3;
  *(_DWORD *)(a1 + 40) = -1;
  if ( *(_DWORD *)(v6 + 32240) >= 0xEu )
    *(_QWORD *)(a1 + 104) = ipa_read_ep_reg_v4_0;
  return 0;
}
