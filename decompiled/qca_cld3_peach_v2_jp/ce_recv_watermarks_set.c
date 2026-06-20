__int64 __fastcall ce_recv_watermarks_set(__int64 *a1, int a2, int a3)
{
  __int64 v5; // x23
  int v6; // w25
  __int64 v7; // x8
  __int64 v8; // x21
  unsigned int v9; // w26
  unsigned int v10; // w22
  __int64 v11; // x8
  int v12; // w0
  int v13; // w22
  __int64 v14; // x8
  char v15; // w9
  int v16; // w11
  __int64 v17; // x8
  int v18; // w22
  int v19; // w26
  unsigned int v20; // w27
  unsigned int v21; // w20
  __int64 v22; // x8
  int v23; // w0
  __int64 v24; // x8
  __int64 v25; // x11
  __int64 v26; // x8
  __int64 v27; // x20
  unsigned int v28; // w22
  unsigned int v29; // w21
  __int64 v30; // x8
  int v31; // w0
  int v32; // w21
  __int64 v33; // x8
  char v34; // w9
  int v35; // w11
  __int64 v36; // x8
  int v37; // w21
  int v38; // w22
  unsigned int v39; // w25
  unsigned int v40; // w19
  __int64 v41; // x8
  int v42; // w0
  __int64 result; // x0
  _QWORD v44[2]; // [xsp+0h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v44[0] = 0;
  v6 = *((_DWORD *)a1 + 4);
  v7 = *(_QWORD *)(v5 + 30720);
  v8 = *(_QWORD *)(v5 + 40) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v5 + 616) + 356LL) + v6);
  if ( *(_BYTE *)(v5 + 31089) == 1 && (v9 = v8 - v7, (unsigned int)(v8 - v7) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(v5 + 30760), v44);
    v10 = (v9 >> 19) & 0x3F | 0x40000000;
    writel_1(v10, *(_QWORD *)(v5 + 30720) + 12920LL);
    v11 = *(_QWORD *)(v5 + 30720);
    *(_DWORD *)(v5 + 31092) = (v9 >> 19) & 0x3F;
    v12 = readl_1(v11 + 12920);
    if ( v12 != v10 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v10,
        v12,
        12920);
    v13 = readl_1(*(_QWORD *)(v5 + 30720) + (*(_QWORD *)&v9 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(v5 + 30760), v44);
  }
  else
  {
    v13 = readl_1(*(_QWORD *)(v5 + 40) + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v5 + 616) + 356LL) + v6));
  }
  v14 = *(_QWORD *)(v5 + 624);
  v44[0] = 0;
  v15 = *(_DWORD *)(v14 + 184);
  v16 = *(_DWORD *)(v14 + 16);
  v17 = *(_QWORD *)(v5 + 30720);
  v18 = v13 & ~v16;
  v19 = (a2 << v15) & v16;
  if ( *(_BYTE *)(v5 + 31089) == 1 && (v20 = v8 - v17, (unsigned int)(v8 - v17) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(v5 + 30760), v44);
    v21 = (v20 >> 19) & 0x3F | 0x40000000;
    writel_1(v21, *(_QWORD *)(v5 + 30720) + 12920LL);
    v22 = *(_QWORD *)(v5 + 30720);
    *(_DWORD *)(v5 + 31092) = (v20 >> 19) & 0x3F;
    v23 = readl_1(v22 + 12920);
    if ( v23 != v21 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v21,
        v23,
        12920);
    writel_1(v19 | (unsigned int)v18, *(_QWORD *)(v5 + 30720) + (*(_QWORD *)&v20 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(v5 + 30760), v44);
  }
  else
  {
    writel_1(v19 | (unsigned int)v18, v8);
  }
  v24 = *(_QWORD *)(v5 + 616);
  v44[0] = 0;
  v25 = (unsigned int)(*(_DWORD *)(v24 + 356) + v6);
  v26 = *(_QWORD *)(v5 + 30720);
  v27 = *(_QWORD *)(v5 + 40) + v25;
  if ( *(_BYTE *)(v5 + 31089) == 1 && (v28 = v27 - v26, (unsigned int)(v27 - v26) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(v5 + 30760), v44);
    v29 = (v28 >> 19) & 0x3F | 0x40000000;
    writel_1(v29, *(_QWORD *)(v5 + 30720) + 12920LL);
    v30 = *(_QWORD *)(v5 + 30720);
    *(_DWORD *)(v5 + 31092) = (v28 >> 19) & 0x3F;
    v31 = readl_1(v30 + 12920);
    if ( v31 != v29 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v29,
        v31,
        12920);
    v32 = readl_1(*(_QWORD *)(v5 + 30720) + (*(_QWORD *)&v28 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(v5 + 30760), v44);
  }
  else
  {
    v32 = readl_1(*(_QWORD *)(v5 + 40) + v25);
  }
  v33 = *(_QWORD *)(v5 + 624);
  v44[0] = 0;
  v34 = *(_DWORD *)(v33 + 188);
  v35 = *(_DWORD *)(v33 + 20);
  v36 = *(_QWORD *)(v5 + 30720);
  v37 = v32 & ~v35;
  v38 = (a3 << v34) & v35;
  if ( *(_BYTE *)(v5 + 31089) == 1 && (v39 = v27 - v36, (unsigned int)(v27 - v36) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(v5 + 30760), v44);
    v40 = (v39 >> 19) & 0x3F | 0x40000000;
    writel_1(v40, *(_QWORD *)(v5 + 30720) + 12920LL);
    v41 = *(_QWORD *)(v5 + 30720);
    *(_DWORD *)(v5 + 31092) = (v39 >> 19) & 0x3F;
    v42 = readl_1(v41 + 12920);
    if ( v42 != v40 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v40,
        v42,
        12920);
    writel_1(v38 | (unsigned int)v37, *(_QWORD *)(v5 + 30720) + (*(_QWORD *)&v39 & 0x7FFFFLL) + 0x80000);
    result = pld_unlock_reg_window(*(_QWORD *)(v5 + 30760), v44);
  }
  else
  {
    result = writel_1(v38 | (unsigned int)v37, v27);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
