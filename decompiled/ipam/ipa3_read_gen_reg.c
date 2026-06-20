__int64 __fastcall ipa3_read_gen_reg(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int reg_n; // w22
  int v7; // w23
  int v8; // w0
  int v9; // w24
  int v10; // w25
  int v11; // w26
  int v12; // w27
  int v13; // w28
  int v14; // w0
  int v15; // w22
  __int64 result; // x0
  _QWORD v18[2]; // [xsp+40h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  ipa3_inc_client_enable_clks();
  ipahal_read_reg_n_fields(63, 0, v18);
  reg_n = ipahal_read_reg_n(12, 0);
  v7 = ipahal_read_reg_n(15, 0);
  v8 = ipahal_read_reg_n(0, 0);
  v10 = v18[0];
  v9 = HIDWORD(v18[0]);
  v11 = v8;
  v12 = ipahal_read_reg_n(100, 0);
  v13 = ipahal_read_reg_n(101, 0);
  v14 = ipahal_read_reg_n(102, 0);
  v15 = scnprintf(
          &dbg_buff,
          4096,
          "IPA_VERSION=0x%x\n"
          "IPA_COMP_HW_VERSION=0x%x\n"
          "IPA_ROUTE=0x%x\n"
          "IPA_SHARED_MEM_RESTRICTED=0x%x\n"
          "IPA_SHARED_MEM_SIZE=0x%x\n"
          "IPA_QTIME_TIMESTAMP_CFG=0x%x\n"
          "IPA_TIMERS_PULSE_GRAN_CFG=0x%x\n"
          "IPA_TIMERS_XO_CLK_DIV_CFG=0x%x\n",
          reg_n,
          v7,
          v11,
          v9,
          v10,
          v12,
          v13,
          v14);
  ipa3_dec_client_disable_clks();
  result = simple_read_from_buffer(a2, a3, a4, &dbg_buff, v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
