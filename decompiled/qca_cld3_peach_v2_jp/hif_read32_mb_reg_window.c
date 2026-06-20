__int64 __fastcall hif_read32_mb_reg_window(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // x8
  unsigned int v4; // w21
  __int64 result; // x0
  unsigned int v8; // w20
  __int64 v9; // x8
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w0
  __int64 v20; // x8
  unsigned int v21; // w19
  __int64 v22; // [xsp+0h] [xbp-10h] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v2 = a1 + 28672;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 30720);
  v22 = 0;
  v4 = a2 - v3;
  if ( *(_BYTE *)(a1 + 31089) != 1 || (unsigned int)(a2 - v3) >> 19 == 0 )
  {
    result = readl_9(a2);
  }
  else
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), (__int64)&v22);
    v8 = (v4 >> 19) & 0x3F | 0x40000000;
    writel_8(v8);
    v9 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v2 + 2420) = (v4 >> 19) & 0x3F;
    v10 = readl_9(v9 + 12920);
    if ( v10 != v8 )
      qdf_trace_msg(
        0x3Du,
        2u,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "hif_reg_write_result_check",
        v8,
        v10,
        12920,
        v22,
        v23);
    v19 = readl_9(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v4 & 0x7FFFFLL) + 0x80000);
    v20 = *(_QWORD *)(a1 + 30760);
    v21 = v19;
    pld_unlock_reg_window(v20, (__int64)&v22);
    result = v21;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
