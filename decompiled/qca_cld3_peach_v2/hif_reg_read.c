__int64 __fastcall hif_reg_read(__int64 a1, unsigned int a2)
{
  __int64 v2; // x22
  __int64 v4; // x8
  int v5; // w9
  __int64 v6; // x0
  __int64 v7; // x8
  unsigned int v8; // w21
  unsigned int v9; // w20
  __int64 v10; // x8
  int v11; // w0
  unsigned int v12; // w0
  __int64 v13; // x8
  unsigned int v14; // w19
  __int64 result; // x0
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a1 + 28672;
  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 40);
  v5 = *(unsigned __int8 *)(a1 + 31089);
  v16[0] = 0;
  v6 = v4 + a2;
  v7 = *(_QWORD *)(a1 + 30720);
  if ( v5 == 1 && (v8 = v6 - v7, (unsigned int)(v6 - v7) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v16);
    v9 = (v8 >> 19) & 0x3F | 0x40000000;
    writel_2(v9, *(_QWORD *)(a1 + 30720) + 12920LL);
    v10 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v2 + 2420) = (v8 >> 19) & 0x3F;
    v11 = readl_2(v10 + 12920);
    if ( v11 != v9 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v9,
        v11,
        12920);
    v12 = readl_2(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v8 & 0x7FFFFLL) + 0x80000);
    v13 = *(_QWORD *)(a1 + 30760);
    v14 = v12;
    pld_unlock_reg_window(v13, v16);
    result = v14;
  }
  else
  {
    result = readl_2(v6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
