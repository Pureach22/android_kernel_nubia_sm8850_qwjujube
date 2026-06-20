__int64 __fastcall ce_send_watermarks_set(_DWORD *a1, int a2, int a3)
{
  _QWORD *v5; // x23
  int v6; // w25
  __int64 v7; // x24
  __int64 v8; // x10
  int v9; // w8
  __int64 v10; // x11
  __int64 v11; // x8
  __int64 v12; // x21
  unsigned int v13; // w26
  unsigned int v14; // w22
  __int64 v15; // x8
  int v16; // w0
  int v17; // w22
  __int64 v18; // x8
  char v19; // w9
  int v20; // w11
  __int64 v21; // x8
  int v22; // w22
  int v23; // w26
  unsigned int v24; // w27
  unsigned int v25; // w20
  __int64 v26; // x8
  int v27; // w0
  __int64 v28; // x10
  int v29; // w8
  __int64 v30; // x11
  __int64 v31; // x8
  __int64 v32; // x20
  unsigned int v33; // w22
  unsigned int v34; // w21
  __int64 v35; // x8
  int v36; // w0
  int v37; // w21
  __int64 v38; // x8
  char v39; // w9
  int v40; // w11
  __int64 v41; // x8
  int v42; // w21
  int v43; // w22
  unsigned int v44; // w25
  unsigned int v45; // w19
  __int64 v46; // x8
  int v47; // w0
  __int64 result; // x0
  _QWORD v49[2]; // [xsp+0h] [xbp-10h] BYREF

  v49[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD **)a1;
  v6 = a1[4];
  v7 = *(_QWORD *)a1 + 28672LL;
  v8 = *(_QWORD *)(*(_QWORD *)a1 + 40LL);
  v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 624LL) + 4LL);
  v49[0] = 0;
  v10 = (unsigned int)(v9 + v6);
  v11 = v5[3840];
  v12 = v8 + v10;
  if ( *(_BYTE *)(v7 + 2417) == 1 && (v13 = v12 - v11, (unsigned int)(v12 - v11) >> 19) )
  {
    pld_lock_reg_window(v5[3845], v49);
    v14 = (v13 >> 19) & 0x3F | 0x40000000;
    writel_1(v14, v5[3840] + 12920LL);
    v15 = v5[3840];
    *(_DWORD *)(v7 + 2420) = (v13 >> 19) & 0x3F;
    v16 = readl_1(v15 + 12920);
    if ( v16 != v14 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v14,
        v16,
        12920);
    v17 = readl_1(v5[3840] + (*(_QWORD *)&v13 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(v5[3845], v49);
  }
  else
  {
    v17 = readl_1(v8 + v10);
  }
  v18 = v5[78];
  v49[0] = 0;
  v19 = *(_DWORD *)(v18 + 176);
  v20 = *(_DWORD *)(v18 + 8);
  v21 = v5[3840];
  v22 = v17 & ~v20;
  v23 = (a2 << v19) & v20;
  if ( *(_BYTE *)(v7 + 2417) == 1 && (v24 = v12 - v21, (unsigned int)(v12 - v21) >> 19) )
  {
    pld_lock_reg_window(v5[3845], v49);
    v25 = (v24 >> 19) & 0x3F | 0x40000000;
    writel_1(v25, v5[3840] + 12920LL);
    v26 = v5[3840];
    *(_DWORD *)(v7 + 2420) = (v24 >> 19) & 0x3F;
    v27 = readl_1(v26 + 12920);
    if ( v27 != v25 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v25,
        v27,
        12920);
    writel_1(v23 | (unsigned int)v22, v5[3840] + (*(_QWORD *)&v24 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(v5[3845], v49);
  }
  else
  {
    writel_1(v23 | (unsigned int)v22, v12);
  }
  v28 = v5[5];
  v29 = *(_DWORD *)(v5[78] + 4LL);
  v49[0] = 0;
  v30 = (unsigned int)(v29 + v6);
  v31 = v5[3840];
  v32 = v28 + v30;
  if ( *(_BYTE *)(v7 + 2417) == 1 && (v33 = v32 - v31, (unsigned int)(v32 - v31) >> 19) )
  {
    pld_lock_reg_window(v5[3845], v49);
    v34 = (v33 >> 19) & 0x3F | 0x40000000;
    writel_1(v34, v5[3840] + 12920LL);
    v35 = v5[3840];
    *(_DWORD *)(v7 + 2420) = (v33 >> 19) & 0x3F;
    v36 = readl_1(v35 + 12920);
    if ( v36 != v34 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v34,
        v36,
        12920);
    v37 = readl_1(v5[3840] + (*(_QWORD *)&v33 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(v5[3845], v49);
  }
  else
  {
    v37 = readl_1(v28 + v30);
  }
  v38 = v5[78];
  v49[0] = 0;
  v39 = *(_DWORD *)(v38 + 180);
  v40 = *(_DWORD *)(v38 + 12);
  v41 = v5[3840];
  v42 = v37 & ~v40;
  v43 = (a3 << v39) & v40;
  if ( *(_BYTE *)(v7 + 2417) == 1 && (v44 = v32 - v41, (unsigned int)(v32 - v41) >> 19) )
  {
    pld_lock_reg_window(v5[3845], v49);
    v45 = (v44 >> 19) & 0x3F | 0x40000000;
    writel_1(v45, v5[3840] + 12920LL);
    v46 = v5[3840];
    *(_DWORD *)(v7 + 2420) = (v44 >> 19) & 0x3F;
    v47 = readl_1(v46 + 12920);
    if ( v47 != v45 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v45,
        v47,
        12920);
    writel_1(v43 | (unsigned int)v42, v5[3840] + (*(_QWORD *)&v44 & 0x7FFFFLL) + 0x80000);
    result = pld_unlock_reg_window(v5[3845], v49);
  }
  else
  {
    result = writel_1(v43 | (unsigned int)v42, v32);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
