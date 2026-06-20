__int64 __fastcall priv_dump_bbwatchdog(_QWORD *a1)
{
  _QWORD *v2; // x21
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x0
  unsigned int v8; // w22
  unsigned int v9; // w20
  __int64 v10; // x8
  int v11; // w0
  int v12; // w20
  __int64 v13; // x8
  int v14; // w9
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int v18; // w22
  unsigned int v19; // w20
  __int64 v20; // x8
  int v21; // w0
  int v22; // w20
  __int64 v23; // x8
  int v24; // w9
  __int64 v25; // x10
  __int64 v26; // x8
  __int64 v27; // x0
  unsigned int v28; // w22
  unsigned int v29; // w20
  __int64 v30; // x8
  int v31; // w0
  int v32; // w20
  __int64 v33; // x8
  int v34; // w9
  __int64 v35; // x10
  __int64 v36; // x8
  __int64 v37; // x0
  unsigned int v38; // w22
  unsigned int v39; // w20
  __int64 v40; // x8
  int v41; // w0
  int v42; // w0
  __int64 v43; // x8
  int v44; // w19
  __int64 result; // x0
  _QWORD v46[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a1 + 3584;
  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(61, 5, "%s: BB watchdog dump E", "priv_dump_bbwatchdog");
  v3 = a1[5];
  v4 = *((unsigned __int8 *)v2 + 2417);
  v46[0] = 0;
  v5 = v3 + 106496;
  v6 = a1[3840];
  v7 = v5 + 1984;
  if ( v4 == 1 && (v8 = v7 - v6, (unsigned int)(v7 - v6) >> 19) )
  {
    pld_lock_reg_window(a1[3845], v46);
    v9 = (v8 >> 19) & 0x3F | 0x40000000;
    writel_4(v9, a1[3840] + 12920LL);
    v10 = a1[3840];
    *((_DWORD *)v2 + 605) = (v8 >> 19) & 0x3F;
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
    v12 = readl_4(a1[3840] + (*(_QWORD *)&v8 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(a1[3845], v46);
  }
  else
  {
    v12 = readl_4(v7);
  }
  qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_bbwatchdog", v12);
  v13 = a1[5];
  v14 = *((unsigned __int8 *)v2 + 2417);
  v46[0] = 0;
  v15 = v13 + 106496;
  v16 = a1[3840];
  v17 = v15 + 1988;
  if ( v14 == 1 && (v18 = v17 - v16, (unsigned int)(v17 - v16) >> 19) )
  {
    pld_lock_reg_window(a1[3845], v46);
    v19 = (v18 >> 19) & 0x3F | 0x40000000;
    writel_4(v19, a1[3840] + 12920LL);
    v20 = a1[3840];
    *((_DWORD *)v2 + 605) = (v18 >> 19) & 0x3F;
    v21 = readl_4(v20 + 12920);
    if ( v21 != v19 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v19,
        v21,
        12920);
    v22 = readl_4(a1[3840] + (*(_QWORD *)&v18 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(a1[3845], v46);
  }
  else
  {
    v22 = readl_4(v17);
  }
  qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_bbwatchdog", v22);
  v23 = a1[5];
  v24 = *((unsigned __int8 *)v2 + 2417);
  v46[0] = 0;
  v25 = v23 + 106496;
  v26 = a1[3840];
  v27 = v25 + 1992;
  if ( v24 == 1 && (v28 = v27 - v26, (unsigned int)(v27 - v26) >> 19) )
  {
    pld_lock_reg_window(a1[3845], v46);
    v29 = (v28 >> 19) & 0x3F | 0x40000000;
    writel_4(v29, a1[3840] + 12920LL);
    v30 = a1[3840];
    *((_DWORD *)v2 + 605) = (v28 >> 19) & 0x3F;
    v31 = readl_4(v30 + 12920);
    if ( v31 != v29 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v29,
        v31,
        12920);
    v32 = readl_4(a1[3840] + (*(_QWORD *)&v28 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(a1[3845], v46);
  }
  else
  {
    v32 = readl_4(v27);
  }
  qdf_trace_msg(56, 8, "%s: 0x%x\t", "priv_dump_bbwatchdog", v32);
  v33 = a1[5];
  v34 = *((unsigned __int8 *)v2 + 2417);
  v46[0] = 0;
  v35 = v33 + 106496;
  v36 = a1[3840];
  v37 = v35 + 2016;
  if ( v34 == 1 && (v38 = v37 - v36, (unsigned int)(v37 - v36) >> 19) )
  {
    pld_lock_reg_window(a1[3845], v46);
    v39 = (v38 >> 19) & 0x3F | 0x40000000;
    writel_4(v39, a1[3840] + 12920LL);
    v40 = a1[3840];
    *((_DWORD *)v2 + 605) = (v38 >> 19) & 0x3F;
    v41 = readl_4(v40 + 12920);
    if ( v41 != v39 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v39,
        v41,
        12920);
    v42 = readl_4(a1[3840] + (*(_QWORD *)&v38 & 0x7FFFFLL) + 0x80000);
    v43 = a1[3845];
    v44 = v42;
    pld_unlock_reg_window(v43, v46);
  }
  else
  {
    v44 = readl_4(v37);
  }
  qdf_trace_msg(56, 8, "%s: 0x%x", "priv_dump_bbwatchdog", v44);
  result = qdf_trace_msg(61, 5, "%s: BB watchdog dump X", "priv_dump_bbwatchdog");
  _ReadStatusReg(SP_EL0);
  return result;
}
