__int64 __fastcall ipa_read_ep_reg_v4_0(__int64 a1, __int64 a2, unsigned int a3)
{
  int v4; // w21
  int v5; // w22
  int v6; // w23
  int v7; // w24
  int v8; // w25
  int v9; // w26
  int v10; // w27
  int v11; // w28
  int v12; // w20
  int v13; // w0
  int reg_n; // [xsp+8Ch] [xbp-4h]

  reg_n = ipahal_read_reg_n(47, a3);
  v4 = ipahal_read_reg_n(48, a3);
  v5 = ipahal_read_reg_n(41, a3);
  v6 = ipahal_read_reg_n(42, a3);
  v7 = ipahal_read_reg_n(46, a3);
  v8 = ipahal_read_reg_n(43, a3);
  v9 = ipahal_read_reg_n(49, a3);
  v10 = ipahal_read_reg_n(52, a3);
  v11 = ipahal_read_reg_n(53, a3);
  v12 = ipahal_read_reg_n(54, a3);
  v13 = ipahal_read_reg_n(57, a3);
  return scnprintf(
           &dbg_buff,
           4096,
           "IPA_ENDP_INIT_NAT_%u=0x%x\n"
           "IPA_ENDP_INIT_CONN_TRACK_n%u=0x%x\n"
           "IPA_ENDP_INIT_HDR_%u=0x%x\n"
           "IPA_ENDP_INIT_HDR_EXT_%u=0x%x\n"
           "IPA_ENDP_INIT_MODE_%u=0x%x\n"
           "IPA_ENDP_INIT_AGGR_%u=0x%x\n"
           "IPA_ENDP_INIT_CTRL_%u=0x%x\n"
           "IPA_ENDP_INIT_HOL_EN_%u=0x%x\n"
           "IPA_ENDP_INIT_HOL_TIMER_%u=0x%x\n"
           "IPA_ENDP_INIT_DEAGGR_%u=0x%x\n"
           "IPA_ENDP_INIT_CFG_%u=0x%x\n",
           a3,
           reg_n,
           a3,
           v4,
           a3,
           v5,
           a3,
           v6,
           a3,
           v7,
           a3,
           v8,
           a3,
           v9,
           a3,
           v10,
           a3,
           v11,
           a3,
           v12,
           a3,
           v13);
}
