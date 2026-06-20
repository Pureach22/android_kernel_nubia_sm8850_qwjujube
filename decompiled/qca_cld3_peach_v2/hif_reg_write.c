__int64 __fastcall hif_reg_write(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x23
  __int64 v5; // x8
  int v6; // w9
  __int64 v7; // x1
  __int64 v8; // x8
  unsigned int v9; // w22
  unsigned int v11; // w21
  __int64 v12; // x8
  int v13; // w0
  __int64 result; // x0
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a1 + 28672;
  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v6 = *(unsigned __int8 *)(a1 + 31089);
  v15[0] = 0;
  v7 = v5 + a2;
  v8 = *(_QWORD *)(a1 + 30720);
  if ( v6 == 1 && (v9 = v7 - v8, (unsigned int)(v7 - v8) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v15);
    v11 = (v9 >> 19) & 0x3F | 0x40000000;
    writel_2(v11, *(_QWORD *)(a1 + 30720) + 12920LL);
    v12 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v3 + 2420) = (v9 >> 19) & 0x3F;
    v13 = readl_2(v12 + 12920);
    if ( v13 != v11 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v11,
        v13,
        12920);
    writel_2(a3, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v9 & 0x7FFFFLL) + 0x80000);
    result = pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v15);
  }
  else
  {
    result = writel_2(a3, v7);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
