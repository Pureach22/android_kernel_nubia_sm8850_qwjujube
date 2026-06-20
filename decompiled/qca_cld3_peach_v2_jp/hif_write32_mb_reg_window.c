__int64 __fastcall hif_write32_mb_reg_window(__int64 a1, int a2, unsigned int a3)
{
  __int64 v3; // x23
  __int64 v5; // x8
  unsigned int v6; // w22
  __int64 result; // x0
  unsigned int v10; // w21
  __int64 v11; // x8
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v3 = a1 + 28672;
  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 30720);
  v21 = 0;
  v6 = a2 - v5;
  if ( *(_BYTE *)(a1 + 31089) != 1 || (unsigned int)(a2 - v5) >> 19 == 0 )
  {
    result = writel_8(a3);
  }
  else
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), (__int64)&v21);
    v10 = (v6 >> 19) & 0x3F | 0x40000000;
    writel_8(v10);
    v11 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v3 + 2420) = (v6 >> 19) & 0x3F;
    v12 = readl_9(v11 + 12920);
    if ( v12 != v10 )
      qdf_trace_msg(
        0x3Du,
        2u,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hif_reg_write_result_check",
        v10,
        v12,
        12920,
        v21,
        v22);
    writel_8(a3);
    result = pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), (__int64)&v21);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
