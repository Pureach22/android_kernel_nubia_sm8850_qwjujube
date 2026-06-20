__int64 __fastcall priv_start_agc(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x0
  unsigned int v8; // w21
  unsigned int v9; // w20
  __int64 v10; // x8
  int v11; // w0
  int v12; // w20
  __int64 v13; // x8
  __int64 v14; // x20
  unsigned int v15; // w23
  unsigned int v16; // w21
  __int64 v17; // x8
  int v18; // w0
  int v19; // w21
  int v20; // w9
  __int64 v21; // x8
  unsigned int v22; // w23
  unsigned int v23; // w20
  __int64 v24; // x8
  int v25; // w0
  __int64 result; // x0
  _QWORD v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 + 28672;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int8 *)(a1 + 31089);
  v27[0] = 0;
  v5 = v3 + 102400;
  v6 = *(_QWORD *)(a1 + 30720);
  v7 = v5 + 3592;
  if ( v4 == 1 && (v8 = v7 - v6, (unsigned int)(v7 - v6) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v27);
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
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v27);
  }
  else
  {
    v12 = readl_4(v7);
  }
  v27[0] = 0;
  g_priv_dump_ctx_0 = v12;
  v13 = *(_QWORD *)(a1 + 30720);
  v14 = *(_QWORD *)(a1 + 40) + 105992LL;
  if ( *(_BYTE *)(v1 + 2417) == 1 && (v15 = v14 - v13, (unsigned int)(v14 - v13) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v27);
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
    v19 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v15 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v27);
  }
  else
  {
    v19 = readl_4(*(_QWORD *)(a1 + 40) + 105992LL);
  }
  v20 = *(unsigned __int8 *)(v1 + 2417);
  v21 = *(_QWORD *)(a1 + 30720);
  v27[0] = 0;
  if ( v20 == 1 && (v22 = v14 - v21, (unsigned int)(v14 - v21) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v27);
    v23 = (v22 >> 19) & 0x3F | 0x40000000;
    writel_4(v23, *(_QWORD *)(a1 + 30720) + 12920LL);
    v24 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v1 + 2420) = (v22 >> 19) & 0x3F;
    v25 = readl_4(v24 + 12920);
    if ( v25 != v23 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v23,
        v25,
        12920);
    writel_4(v19 | 0x3C0000u, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v22 & 0x7FFFFLL) + 0x80000);
    result = pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v27);
  }
  else
  {
    result = writel_4(v19 | 0x3C0000u, v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
