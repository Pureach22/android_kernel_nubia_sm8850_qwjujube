__int64 __fastcall hif_fw_interrupt_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x10
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v6; // x0
  unsigned int v7; // w24
  unsigned int v8; // w20
  __int64 v9; // x8
  int v10; // w0
  int v11; // w20
  unsigned int v12; // w21
  int v13; // w24
  int v14; // w9
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x1
  unsigned int v18; // w25
  unsigned int v19; // w21
  __int64 v20; // x8
  int v21; // w0
  void (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x0
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (hif_target_sleep_state_adjust(a2, 0, 1) & 0x80000000) != 0 )
  {
    v12 = 0;
    goto LABEL_17;
  }
  v3 = *(_QWORD *)(a2 + 40);
  v25[0] = 0;
  v4 = *(_QWORD *)(a2 + 30720);
  v5 = *(unsigned int *)(a2 + 29144);
  v6 = v3 + v5;
  if ( *(_BYTE *)(a2 + 31089) == 1 && (v7 = v6 - v4, (unsigned int)(v6 - v4) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a2 + 30760), v25);
    v8 = (v7 >> 19) & 0x3F | 0x40000000;
    writel_0(v8, *(_QWORD *)(a2 + 30720) + 12920LL);
    v9 = *(_QWORD *)(a2 + 30720);
    *(_DWORD *)(a2 + 31092) = (v7 >> 19) & 0x3F;
    v10 = readl_0(v9 + 12920);
    if ( v10 != v8 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v8,
        v10,
        12920);
    v11 = readl_0(*(_QWORD *)(a2 + 30720) + (*(_QWORD *)&v7 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a2 + 30760), v25);
    if ( v11 == -1 )
      goto LABEL_16;
  }
  else
  {
    v11 = readl_0(v6);
    if ( v11 == -1 )
    {
LABEL_16:
      v12 = 1;
      hif_target_sleep_state_adjust(a2, 1, 0);
      goto LABEL_17;
    }
  }
  v13 = *(_DWORD *)(*(_QWORD *)(a2 + 632) + 184LL);
  if ( (v13 & v11) == 0 )
    goto LABEL_16;
  v14 = *(unsigned __int8 *)(a2 + 31089);
  v15 = *(_QWORD *)(a2 + 40);
  v16 = *(_QWORD *)(a2 + 30720);
  v25[0] = 0;
  v17 = v15 + v5;
  if ( v14 == 1 && (v18 = v17 - v16, (unsigned int)(v17 - v16) >> 19) )
  {
    pld_lock_reg_window(*(_QWORD *)(a2 + 30760), v25);
    v19 = (v18 >> 19) & 0x3F | 0x40000000;
    writel_0(v19, *(_QWORD *)(a2 + 30720) + 12920LL);
    v20 = *(_QWORD *)(a2 + 30720);
    *(_DWORD *)(a2 + 31092) = (v18 >> 19) & 0x3F;
    v21 = readl_0(v20 + 12920);
    if ( v21 != v19 )
      qdf_trace_msg(
        61,
        2,
        "%s: Reg write failed. write val 0x%x read val 0x%x offset 0x%x",
        "hif_reg_write_result_check",
        v19,
        v21,
        12920);
    writel_0(v11 & (unsigned int)~v13, *(_QWORD *)(a2 + 30720) + (*(_QWORD *)&v18 & 0x7FFFFLL) + 0x80000);
    pld_unlock_reg_window(*(_QWORD *)(a2 + 30760), v25);
  }
  else
  {
    writel_0(v11 & (unsigned int)~v13, v17);
  }
  v12 = 1;
  if ( (hif_target_sleep_state_adjust(a2, 1, 0) & 0x80000000) == 0 )
  {
    if ( *(_BYTE *)(a2 + 26440) == 1 )
    {
      v23 = *(void (__fastcall **)(__int64, __int64))(a2 + 29128);
      if ( v23 )
      {
        v24 = *(_QWORD *)(a2 + 29096);
        if ( *((_DWORD *)v23 - 1) != -963780396 )
          __break(0x8228u);
        v23(v24, 16);
      }
    }
    else if ( (byte_506C & 1) != 0 )
    {
      qdf_trace_msg(
        56,
        2,
        "%s: %s: Early firmware event indicated 0x%x\n",
        "hif_fw_interrupt_handler",
        "hif_fw_interrupt_handler",
        v11);
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v12;
}
