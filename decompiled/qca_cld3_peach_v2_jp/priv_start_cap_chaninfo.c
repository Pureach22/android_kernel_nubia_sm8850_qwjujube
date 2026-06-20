__int64 __fastcall priv_start_cap_chaninfo(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x20
  unsigned int v8; // w23
  unsigned int v9; // w21
  __int64 v10; // x8
  int v11; // w0
  int v12; // w21
  int v13; // w9
  __int64 v14; // x8
  unsigned int v15; // w23
  unsigned int v16; // w20
  __int64 v17; // x8
  int v18; // w0
  __int64 result; // x0
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 + 28672;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int8 *)(a1 + 31089);
  v20[0] = 0;
  v5 = v3 + 106496;
  v6 = *(_QWORD *)(a1 + 30720);
  v7 = v5 + 880;
  if ( v4 == 1 && (v8 = v7 - v6, (unsigned int)(v7 - v6) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v20);
    v9 = (v8 >> 19) & 0x3F | 0x40000000;
    writel_4(v9, *(_QWORD *)(a1 + 30720) + 12920LL);
    v10 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v1 + 2420) = (v8 >> 19) & 0x3F;
    v11 = readl_4(v10 + 12920);
    if ( v11 != v9 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v9,
        v11,
        12920);
    v12 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v8 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v20);
  }
  else
  {
    v12 = readl_4(v5 + 880);
  }
  v13 = *(unsigned __int8 *)(v1 + 2417);
  v14 = *(_QWORD *)(a1 + 30720);
  v20[0] = 0;
  if ( v13 == 1 && (v15 = v7 - v14, (unsigned int)(v7 - v14) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v20);
    v16 = (v15 >> 19) & 0x3F | 0x40000000;
    writel_4(v16, *(_QWORD *)(a1 + 30720) + 12920LL);
    v17 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v1 + 2420) = (v15 >> 19) & 0x3F;
    v18 = readl_4(v17 + 12920);
    if ( v18 != v16 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v16,
        v18,
        12920);
    writel_4(v12 | 1u, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v15 & 0x7FFFFLL) + 0x80000);
    result = pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v20);
  }
  else
  {
    result = writel_4(v12 | 1u, v7);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
