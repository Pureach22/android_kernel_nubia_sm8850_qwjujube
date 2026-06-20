__int64 __fastcall ce_tx_ring_write_idx_update_wrapper(__int64 result, int a2)
{
  __int64 v2; // x21
  int v3; // w9
  unsigned int v4; // w19
  __int64 v5; // x8
  __int64 v6; // x1
  unsigned int v7; // w22
  unsigned int v8; // w20
  __int64 v9; // x8
  int v10; // w0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    v2 = *(_QWORD *)result;
    v3 = *(_DWORD *)(result + 16);
    v11[0] = 0;
    v4 = *(_DWORD *)(*(_QWORD *)(result + 136) + 12LL);
    v5 = *(_QWORD *)(v2 + 30720);
    v6 = *(_QWORD *)(v2 + 40) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v2 + 616) + 352LL) + v3);
    if ( *(_BYTE *)(v2 + 31089) == 1 && (v7 = v6 - v5, (unsigned int)(v6 - v5) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(v2 + 30760), v11);
      v8 = (v7 >> 19) & 0x3F | 0x40000000;
      writel_1(v8, *(_QWORD *)(v2 + 30720) + 12920LL);
      v9 = *(_QWORD *)(v2 + 30720);
      *(_DWORD *)(v2 + 31092) = (v7 >> 19) & 0x3F;
      v10 = readl_1(v9 + 12920);
      if ( v10 != v8 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v8,
          v10,
          12920);
      writel_1(v4, *(_QWORD *)(v2 + 30720) + (*(_QWORD *)&v7 & 0x7FFFFLL) + 0x80000);
      result = pld_unlock_reg_window(*(_QWORD *)(v2 + 30760), v11);
    }
    else
    {
      result = writel_1(v4, v6);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
