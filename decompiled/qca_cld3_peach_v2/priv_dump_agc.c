__int64 __fastcall priv_dump_agc(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x10
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned int v7; // w21
  unsigned int v8; // w20
  __int64 v9; // x8
  int v10; // w0
  char v11; // w25
  __int64 v12; // x8
  int v13; // w9
  __int64 v14; // x10
  __int64 v15; // x8
  __int64 v16; // x21
  unsigned int v17; // w20
  unsigned int v18; // w22
  __int64 v19; // x8
  int v20; // w0
  int v21; // w22
  int v22; // w9
  __int64 v23; // x8
  unsigned int v24; // w20
  unsigned int v25; // w21
  __int64 v26; // x8
  int v27; // w0
  __int64 v28; // x8
  int v29; // w9
  __int64 v30; // x10
  __int64 v31; // x8
  __int64 v32; // x21
  unsigned int v33; // w20
  unsigned int v34; // w22
  __int64 v35; // x8
  int v36; // w0
  int v37; // w22
  int v38; // w9
  __int64 v39; // x8
  unsigned int v40; // w20
  unsigned int v41; // w21
  __int64 v42; // x8
  int v43; // w0
  __int64 v44; // x8
  int v45; // w9
  unsigned int v46; // w20
  __int64 v47; // x11
  __int64 v48; // x8
  __int64 v49; // x1
  unsigned int v50; // w22
  unsigned int v51; // w21
  __int64 v52; // x8
  int v53; // w0
  int v54; // w20
  unsigned int v55; // w22
  int v56; // w9
  __int64 v57; // x10
  __int64 v58; // x8
  __int64 v59; // x1
  unsigned int v60; // w26
  unsigned int v61; // w27
  __int64 v62; // x8
  int v63; // w0
  int v64; // w9
  __int64 v65; // x10
  __int64 v66; // x8
  __int64 v67; // x0
  unsigned int v68; // w26
  unsigned int v69; // w27
  __int64 v70; // x8
  int v71; // w0
  int v72; // w27
  int v73; // w27
  unsigned int v74; // w21
  int v75; // w9
  __int64 v76; // x10
  __int64 v77; // x8
  __int64 v78; // x1
  unsigned int v79; // w25
  unsigned int v80; // w26
  __int64 v81; // x8
  int v82; // w0
  int v83; // w9
  __int64 v84; // x10
  __int64 v85; // x8
  __int64 v86; // x0
  unsigned int v87; // w25
  unsigned int v88; // w26
  __int64 v89; // x8
  int v90; // w0
  int v91; // w26
  _QWORD v92[2]; // [xsp+10h] [xbp-10h] BYREF

  v92[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = hif_target_sleep_state_adjust(a1);
  if ( (result & 0x80000000) == 0 )
  {
    v3 = *(_QWORD *)(a1 + 40);
    v92[0] = 0;
    v4 = v3 + 106496;
    v5 = *(_QWORD *)(a1 + 30720);
    v6 = v4 + 672;
    if ( *(_BYTE *)(a1 + 31089) == 1 && (v7 = v6 - v5, (unsigned int)(v6 - v5) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
      v8 = (v7 >> 19) & 0x3F | 0x40000000;
      writel_4(v8, *(_QWORD *)(a1 + 30720) + 12920LL);
      v9 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v7 >> 19) & 0x3F;
      v10 = readl_4(v9 + 12920);
      if ( v10 != v8 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v8,
          v10,
          12920);
      v11 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v7 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
    }
    else
    {
      v11 = readl_4(v6);
    }
    v12 = *(_QWORD *)(a1 + 40);
    v13 = *(unsigned __int8 *)(a1 + 31089);
    v92[0] = 0;
    v14 = v12 + 102400;
    v15 = *(_QWORD *)(a1 + 30720);
    v16 = v14 + 3592;
    if ( v13 == 1 && (v17 = v16 - v15, (unsigned int)(v16 - v15) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
      v18 = (v17 >> 19) & 0x3F | 0x40000000;
      writel_4(v18, *(_QWORD *)(a1 + 30720) + 12920LL);
      v19 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v17 >> 19) & 0x3F;
      v20 = readl_4(v19 + 12920);
      if ( v20 != v18 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v18,
          v20,
          12920);
      v21 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v17 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
    }
    else
    {
      v21 = readl_4(v14 + 3592);
    }
    v22 = *(unsigned __int8 *)(a1 + 31089);
    v23 = *(_QWORD *)(a1 + 30720);
    v92[0] = 0;
    if ( v22 == 1 && (v24 = v16 - v23, (unsigned int)(v16 - v23) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
      v25 = (v24 >> 19) & 0x3F | 0x40000000;
      writel_4(v25, *(_QWORD *)(a1 + 30720) + 12920LL);
      v26 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v24 >> 19) & 0x3F;
      v27 = readl_4(v26 + 12920);
      if ( v27 != v25 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v25,
          v27,
          12920);
      writel_4(v21 & 0xFFC3FFFF, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v24 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
    }
    else
    {
      writel_4(v21 & 0xFFC3FFFF, v16);
    }
    v28 = *(_QWORD *)(a1 + 40);
    v29 = *(unsigned __int8 *)(a1 + 31089);
    v92[0] = 0;
    v30 = v28 + 106496;
    v31 = *(_QWORD *)(a1 + 30720);
    v32 = v30 + 880;
    if ( v29 == 1 && (v33 = v32 - v31, (unsigned int)(v32 - v31) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
      v34 = (v33 >> 19) & 0x3F | 0x40000000;
      writel_4(v34, *(_QWORD *)(a1 + 30720) + 12920LL);
      v35 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v33 >> 19) & 0x3F;
      v36 = readl_4(v35 + 12920);
      if ( v36 != v34 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v34,
          v36,
          12920);
      v37 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v33 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
    }
    else
    {
      v37 = readl_4(v30 + 880);
    }
    v38 = *(unsigned __int8 *)(a1 + 31089);
    v39 = *(_QWORD *)(a1 + 30720);
    v92[0] = 0;
    if ( v38 == 1 && (v40 = v32 - v39, (unsigned int)(v32 - v39) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
      v41 = (v40 >> 19) & 0x3F | 0x40000000;
      writel_4(v41, *(_QWORD *)(a1 + 30720) + 12920LL);
      v42 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v40 >> 19) & 0x3F;
      v43 = readl_4(v42 + 12920);
      if ( v43 != v41 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v41,
          v43,
          12920);
      writel_4(v37 & 0xFFFFFFF7, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v40 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
    }
    else
    {
      writel_4(v37 & 0xFFFFFFF7, v32);
    }
    qdf_trace_msg(61, 5, "%s: AGC history buffer dump: E", "priv_dump_agc");
    if ( (v11 & 1) != 0 )
    {
      v54 = 0;
      v55 = 12800;
      do
      {
        v56 = *(unsigned __int8 *)(a1 + 31089);
        v57 = *(_QWORD *)(a1 + 40);
        v58 = *(_QWORD *)(a1 + 30720);
        v92[0] = 0;
        v59 = v57 + 104596;
        if ( v56 == 1 && (v60 = v59 - v58, (unsigned int)(v59 - v58) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
          v61 = (v60 >> 19) & 0x3F | 0x40000000;
          writel_4(v61, *(_QWORD *)(a1 + 30720) + 12920LL);
          v62 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(a1 + 31092) = (v60 >> 19) & 0x3F;
          v63 = readl_4(v62 + 12920);
          if ( v63 != v61 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v61,
              v63,
              12920);
          writel_4(v55, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v60 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
        }
        else
        {
          writel_4(v55, v59);
        }
        v64 = *(unsigned __int8 *)(a1 + 31089);
        v65 = *(_QWORD *)(a1 + 40);
        v66 = *(_QWORD *)(a1 + 30720);
        v92[0] = 0;
        v67 = v65 + 104600;
        if ( v64 == 1 && (v68 = v67 - v66, (unsigned int)(v67 - v66) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
          v69 = (v68 >> 19) & 0x3F | 0x40000000;
          writel_4(v69, *(_QWORD *)(a1 + 30720) + 12920LL);
          v70 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(a1 + 31092) = (v68 >> 19) & 0x3F;
          v71 = readl_4(v70 + 12920);
          if ( v71 != v69 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v69,
              v71,
              12920);
          v72 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v68 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
        }
        else
        {
          v72 = readl_4(v67);
        }
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_agc", v72);
        if ( (v54 & 3) == 0 )
          qdf_trace_msg(56, 8, "%s: \n", "priv_dump_agc");
        ++v54;
        v55 += 4;
      }
      while ( v54 != 60 );
    }
    if ( (v11 & 2) != 0 )
    {
      v73 = 0;
      v74 = 12800;
      do
      {
        v75 = *(unsigned __int8 *)(a1 + 31089);
        v76 = *(_QWORD *)(a1 + 40);
        v77 = *(_QWORD *)(a1 + 30720);
        v92[0] = 0;
        v78 = v76 + 108692;
        if ( v75 == 1 && (v79 = v78 - v77, (unsigned int)(v78 - v77) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
          v80 = (v79 >> 19) & 0x3F | 0x40000000;
          writel_4(v80, *(_QWORD *)(a1 + 30720) + 12920LL);
          v81 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(a1 + 31092) = (v79 >> 19) & 0x3F;
          v82 = readl_4(v81 + 12920);
          if ( v82 != v80 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v80,
              v82,
              12920);
          writel_4(v74, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v79 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
        }
        else
        {
          writel_4(v74, v78);
        }
        v83 = *(unsigned __int8 *)(a1 + 31089);
        v84 = *(_QWORD *)(a1 + 40);
        v85 = *(_QWORD *)(a1 + 30720);
        v92[0] = 0;
        v86 = v84 + 108696;
        if ( v83 == 1 && (v87 = v86 - v85, (unsigned int)(v86 - v85) >> 19) )
        {
          pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
          v88 = (v87 >> 19) & 0x3F | 0x40000000;
          writel_4(v88, *(_QWORD *)(a1 + 30720) + 12920LL);
          v89 = *(_QWORD *)(a1 + 30720);
          *(_DWORD *)(a1 + 31092) = (v87 >> 19) & 0x3F;
          v90 = readl_4(v89 + 12920);
          if ( v90 != v88 )
            qdf_trace_msg(
              61,
              2,
              "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
              "hif_reg_write_result_check",
              v88,
              v90,
              12920);
          v91 = readl_4(*(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v87 & 0x7FFFFLL) + 0x80000);
          pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
        }
        else
        {
          v91 = readl_4(v86);
        }
        qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_agc", v91);
        if ( (v73 & 3) == 0 )
          qdf_trace_msg(56, 8, "%s: \n", "priv_dump_agc");
        ++v73;
        v74 += 4;
      }
      while ( v73 != 60 );
    }
    qdf_trace_msg(61, 5, "%s: AGC history buffer dump X", "priv_dump_agc");
    v44 = *(_QWORD *)(a1 + 40);
    v45 = *(unsigned __int8 *)(a1 + 31089);
    v46 = g_priv_dump_ctx_0;
    v92[0] = 0;
    v47 = v44 + 102400;
    v48 = *(_QWORD *)(a1 + 30720);
    v49 = v47 + 3592;
    if ( v45 == 1 && (v50 = v49 - v48, (unsigned int)(v49 - v48) >> 19) )
    {
      pld_lock_reg_window(*(_QWORD *)(a1 + 30760), v92);
      v51 = (v50 >> 19) & 0x3F | 0x40000000;
      writel_4(v51, *(_QWORD *)(a1 + 30720) + 12920LL);
      v52 = *(_QWORD *)(a1 + 30720);
      *(_DWORD *)(a1 + 31092) = (v50 >> 19) & 0x3F;
      v53 = readl_4(v52 + 12920);
      if ( v53 != v51 )
        qdf_trace_msg(
          61,
          2,
          "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
          "hif_reg_write_result_check",
          v51,
          v53,
          12920);
      writel_4(v46, *(_QWORD *)(a1 + 30720) + (*(_QWORD *)&v50 & 0x7FFFFLL) + 0x80000);
      pld_unlock_reg_window(*(_QWORD *)(a1 + 30760), v92);
    }
    else
    {
      writel_4((unsigned int)g_priv_dump_ctx_0, v49);
    }
    result = hif_target_sleep_state_adjust(a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
