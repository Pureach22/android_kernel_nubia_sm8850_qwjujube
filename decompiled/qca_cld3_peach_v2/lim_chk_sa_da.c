bool __fastcall lim_chk_sa_da(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  int v8; // w21
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v18; // [xsp+10h] [xbp-10h] BYREF
  __int16 v19; // [xsp+14h] [xbp-Ch]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v18 = 0;
  v8 = qdf_mem_cmp((const void *)(a2 + 10), (const void *)(a2 + 4), 6u);
  if ( !v8 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Assoc Req rejected: wlan.sa = wlan.da",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "lim_chk_sa_da");
    lim_send_assoc_rsp_mgmt_frame(a1, 1, 1, a2 + 10, a4, 0, a3, 0, &v18);
  }
  _ReadStatusReg(SP_EL0);
  return v8 != 0;
}
