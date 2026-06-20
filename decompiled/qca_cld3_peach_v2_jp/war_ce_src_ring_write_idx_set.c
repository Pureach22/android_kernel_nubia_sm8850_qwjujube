__int64 __fastcall war_ce_src_ring_write_idx_set(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v5; // x23
  __int64 v6; // x8
  __int64 v7; // x21
  int v8; // w9
  __int64 v9; // x8
  unsigned int v10; // w24
  unsigned int v11; // w21
  __int64 v12; // x8
  int v13; // w0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x0
  __int64 v17; // x9
  int v18; // w10
  __int64 v19; // x11
  __int64 v20; // x9
  __int64 v21; // x1
  unsigned int v22; // w22
  unsigned int v23; // w21
  __int64 v24; // x8
  int v25; // w0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v34; // x8
  unsigned int v35; // w26
  unsigned int v36; // w22
  __int64 v37; // x8
  int v38; // w0
  int v39; // w9
  __int64 v40; // x8
  unsigned int v41; // w26
  unsigned int v42; // w22
  __int64 v43; // x8
  int v44; // w0
  int v45; // w9
  __int64 v46; // x8
  unsigned int v47; // w26
  unsigned int v48; // w22
  __int64 v49; // x8
  int v50; // w0
  __int64 v51; // x8
  int v52; // w9
  __int64 v53; // x10
  __int64 v54; // x11
  __int64 v55; // x8
  __int64 v56; // x1
  unsigned int v57; // w25
  unsigned int v58; // w22
  __int64 v59; // x8
  int v60; // w0
  int v61; // w9
  __int64 v62; // x8
  unsigned int v63; // w22
  unsigned int v64; // w20
  __int64 v65; // x8
  int v66; // w0
  _QWORD v67[2]; // [xsp+0h] [xbp-10h] BYREF

  v5 = a1 + 28672;
  v67[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 40);
  if ( hif_ce_war1 != 1 )
  {
    v17 = *(_QWORD *)(a1 + 616);
    v18 = *(unsigned __int8 *)(a1 + 31089);
    v67[0] = 0;
    v19 = *(_DWORD *)(v17 + 352) + a2;
    v20 = *(_QWORD *)(a1 + 30720);
    v21 = v6 + v19;
    if ( v18 != 1 || (v22 = v21 - v20, !((unsigned int)(v21 - v20) >> 19)) )
    {
      result = writel_1(a3, v21);
      goto LABEL_47;
    }
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v67);
    v23 = (v22 >> 19) & 0x3F | 0x40000000;
    writel_1(v23, *(_QWORD *)(a1 + 30720) + 12920LL);
    v24 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v5 + 2420) = (v22 >> 19) & 0x3F;
    v25 = readl_1(v24 + 12920);
    if ( v25 != v23 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v23,
        v25,
        12920);
    v14 = *(_QWORD *)(a1 + 30720);
    v15 = *(_QWORD *)&v22 & 0x7FFFFLL;
    v16 = a3;
    goto LABEL_13;
  }
  v7 = v6 + a2 + *(unsigned int *)(*(_QWORD *)(a1 + 616) + 356LL);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 624) + 256LL)
     + 4 * (*(_DWORD *)(*(_QWORD *)(a1 + 624) + 260LL) - *(_DWORD *)(*(_QWORD *)(a1 + 624) + 256LL)) == a2 )
  {
    v8 = *(unsigned __int8 *)(a1 + 31089);
    v9 = *(_QWORD *)(a1 + 30720);
    v67[0] = 0;
    if ( v8 != 1 || (v10 = v7 - v9, !((unsigned int)(v7 - v9) >> 19)) )
    {
      result = writel_1(a3 | 0xCEEF0000, v7);
      goto LABEL_47;
    }
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v67);
    v11 = (v10 >> 19) & 0x3F | 0x40000000;
    writel_1(v11, *(_QWORD *)(a1 + 30720) + 12920LL);
    v12 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v5 + 2420) = (v10 >> 19) & 0x3F;
    v13 = readl_1(v12 + 12920);
    if ( v13 != v11 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v11,
        v13,
        12920);
    v14 = *(_QWORD *)(a1 + 30720);
    v15 = *(_QWORD *)&v10 & 0x7FFFFLL;
    v16 = a3 | 0xCEEF0000;
LABEL_13:
    writel_1(v16, v14 + v15 + 0x80000);
    result = pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v67);
    goto LABEL_47;
  }
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v67[0] = 0;
  v34 = *(_QWORD *)(a1 + 30720);
  if ( *(_BYTE *)(a1 + 31089) == 1 && (v35 = v7 - v34, (unsigned int)(v7 - v34) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v67);
    v36 = (v35 >> 19) & 0x3F | 0x40000000;
    writel_1(v36, *(_QWORD *)(a1 + 30720) + 12920LL);
    v37 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v5 + 2420) = (v35 >> 19) & 0x3F;
    v38 = readl_1(v37 + 12920);
    if ( v38 != v36 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v36,
        v38,
        12920);
    writel_1(1, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v35 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v67);
  }
  else
  {
    writel_1(1, v7);
  }
  v39 = *(unsigned __int8 *)(v5 + 2417);
  v40 = *(_QWORD *)(a1 + 30720);
  v67[0] = 0;
  if ( v39 == 1 && (v41 = v7 - v40, (unsigned int)(v7 - v40) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v67);
    v42 = (v41 >> 19) & 0x3F | 0x40000000;
    writel_1(v42, *(_QWORD *)(a1 + 30720) + 12920LL);
    v43 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v5 + 2420) = (v41 >> 19) & 0x3F;
    v44 = readl_1(v43 + 12920);
    if ( v44 != v42 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v42,
        v44,
        12920);
    readl_1(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v41 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v67);
  }
  else
  {
    readl_1(v7);
  }
  v45 = *(unsigned __int8 *)(v5 + 2417);
  v46 = *(_QWORD *)(a1 + 30720);
  v67[0] = 0;
  if ( v45 == 1 && (v47 = v7 - v46, (unsigned int)(v7 - v46) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v67);
    v48 = (v47 >> 19) & 0x3F | 0x40000000;
    writel_1(v48, *(_QWORD *)(a1 + 30720) + 12920LL);
    v49 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v5 + 2420) = (v47 >> 19) & 0x3F;
    v50 = readl_1(v49 + 12920);
    if ( v50 != v48 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v48,
        v50,
        12920);
    readl_1(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v47 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v67);
  }
  else
  {
    readl_1(v7);
  }
  v51 = *(_QWORD *)(a1 + 616);
  v52 = *(unsigned __int8 *)(v5 + 2417);
  v53 = *(_QWORD *)(a1 + 40);
  v67[0] = 0;
  v54 = *(_DWORD *)(v51 + 352) + a2;
  v55 = *(_QWORD *)(a1 + 30720);
  v56 = v53 + v54;
  if ( v52 == 1 && (v57 = v56 - v55, (unsigned int)(v56 - v55) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v67);
    v58 = (v57 >> 19) & 0x3F | 0x40000000;
    writel_1(v58, *(_QWORD *)(a1 + 30720) + 12920LL);
    v59 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v5 + 2420) = (v57 >> 19) & 0x3F;
    v60 = readl_1(v59 + 12920);
    if ( v60 != v58 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v58,
        v60,
        12920);
    writel_1(a3, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v57 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v67);
  }
  else
  {
    writel_1(a3, v56);
  }
  v61 = *(unsigned __int8 *)(v5 + 2417);
  v62 = *(_QWORD *)(a1 + 30720);
  v67[0] = 0;
  if ( v61 == 1 && (v63 = v7 - v62, (unsigned int)(v7 - v62) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v67);
    v64 = (v63 >> 19) & 0x3F | 0x40000000;
    writel_1(v64, *(_QWORD *)(a1 + 30720) + 12920LL);
    v65 = *(_QWORD *)(a1 + 30720);
    *(_DWORD *)(v5 + 2420) = (v63 >> 19) & 0x3F;
    v66 = readl_1(v65 + 12920);
    if ( v66 != v64 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v64,
        v66,
        12920);
    writel_1(0, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v63 & 0x7FFFFLL) + 0x80000);
    result = pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v67);
  }
  else
  {
    result = writel_1(0, v7);
  }
  _WriteStatusReg(DAIF, StatusReg);
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
