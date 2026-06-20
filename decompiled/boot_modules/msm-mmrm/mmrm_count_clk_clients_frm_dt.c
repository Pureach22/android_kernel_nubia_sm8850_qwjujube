__int64 __fastcall mmrm_count_clk_clients_frm_dt(__int64 a1)
{
  __int64 v1; // x0
  unsigned int v2; // w19
  unsigned int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 760);
  v4 = 0;
  of_find_property(v1, "mmrm-client-info", &v4);
  v2 = v4 / 0x14;
  if ( (~msm_mmrm_debug & 0x10002) == 0 )
    printk(&unk_CB39, "high", "mmrm_count_clk_clients_frm_dt");
  _ReadStatusReg(SP_EL0);
  return v2;
}
