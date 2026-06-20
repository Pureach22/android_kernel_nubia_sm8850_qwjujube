size_t __fastcall sde_setup_aiqe_common_v1(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x9
  unsigned int v5; // w20
  size_t result; // x0
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  __int64 v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  v7 = 0;
  v8 = 0;
  v5 = *(_DWORD *)(*(_QWORD *)(v4 + 48) + 604LL);
  aiqe_get_common_values(a2, a3, &v7);
  sde_reg_write(a1, v5, HIDWORD(v7), "aiqe_base");
  sde_reg_write(a1, v5 + 4, v7, "aiqe_base + 0x4");
  sde_reg_write(a1, v5 + 20, v8 & 0xFFF | ((WORD2(v8) & 0xFFF) << 16), "aiqe_base + 0x14");
  sde_reg_write(a1, v5 + 1004, 0, "aiqe_base + 0x3EC");
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_setup_aiqe_common_v1",
             31,
             -1,
             SHIDWORD(v7),
             v7,
             WORD2(v8) & 0xFFF,
             v8 & 0xFFF,
             239);
  _ReadStatusReg(SP_EL0);
  return result;
}
