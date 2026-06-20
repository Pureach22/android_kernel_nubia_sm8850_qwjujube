__int64 __fastcall hif_disable_interrupt(_QWORD *a1, unsigned int a2)
{
  _QWORD *v3; // x22
  int v4; // w20
  __int64 v5; // x8
  int v6; // w9
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x8
  __int64 v10; // x20
  unsigned int v11; // w23
  unsigned int v12; // w21
  __int64 v13; // x8
  int v14; // w0
  int v15; // w21
  __int64 v16; // x8
  int v17; // w9
  int v18; // w23
  __int64 v19; // x8
  unsigned int v20; // w24
  unsigned int v21; // w20
  __int64 v22; // x8
  int v23; // w0
  __int64 result; // x0
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 0xC )
    __break(0x5512u);
  v3 = a1 + 3584;
  v4 = *(_DWORD *)(a1[a2 + 60] + 16LL);
  hif_target_sleep_state_adjust(a1, 0, 1);
  v5 = a1[78];
  v6 = *((unsigned __int8 *)v3 + 2417);
  v7 = a1[5];
  v25[0] = 0;
  v8 = (unsigned int)(*(_DWORD *)(v5 + 76) + v4);
  v9 = a1[3840];
  v10 = v7 + v8;
  if ( v6 == 1 && (v11 = v10 - v9, (unsigned int)(v10 - v9) >> 19) )
  {
    pld_lock_reg_window(a1[3845], v25);
    v12 = (v11 >> 19) & 0x3F | 0x40000000;
    writel_0(v12, a1[3840] + 12920LL);
    v13 = a1[3840];
    *((_DWORD *)v3 + 605) = (v11 >> 19) & 0x3F;
    v14 = readl_0(v13 + 12920);
    if ( v14 != v12 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v12,
        v14,
        12920);
    v15 = readl_0(a1[3840] + (*(_QWORD *)&v11 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(a1[3845], v25);
  }
  else
  {
    v15 = readl_0(v7 + v8);
  }
  v16 = a1[78];
  v17 = *((unsigned __int8 *)v3 + 2417);
  v25[0] = 0;
  v18 = *(_DWORD *)(v16 + 84);
  v19 = a1[3840];
  if ( v17 == 1 && (v20 = v10 - v19, (unsigned int)(v10 - v19) >> 19) )
  {
    pld_lock_reg_window(a1[3845], v25);
    v21 = (v20 >> 19) & 0x3F | 0x40000000;
    writel_0(v21, a1[3840] + 12920LL);
    v22 = a1[3840];
    *((_DWORD *)v3 + 605) = (v20 >> 19) & 0x3F;
    v23 = readl_0(v22 + 12920);
    if ( v23 != v21 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v21,
        v23,
        12920);
    writel_0(v15 & (unsigned int)~v18, a1[3840] + (*(_QWORD *)&v20 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(a1[3845], v25);
  }
  else
  {
    writel_0(v15 & (unsigned int)~v18, v10);
  }
  result = hif_target_sleep_state_adjust(a1, 1, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
