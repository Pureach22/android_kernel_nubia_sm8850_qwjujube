__int64 __fastcall cam_hw_cdm_dump_core_debug_registers(__int64 a1, char a2)
{
  __int64 v4; // x27
  const char *v5; // x6
  int v6; // w7
  unsigned int **v7; // x28
  int v8; // w20
  int v9; // w21
  unsigned int v10; // w22
  unsigned int *v11; // x8
  __int64 v12; // x7
  unsigned int v13; // w8
  const char *v14; // x10
  _QWORD *v15; // x8
  __int64 v16; // x25
  unsigned __int64 v17; // x10
  __int64 result; // x0
  int v19; // [xsp+0h] [xbp-40h]
  int v20; // [xsp+8h] [xbp-38h]
  int v21; // [xsp+10h] [xbp-30h]
  char v22; // [xsp+20h] [xbp-20h]
  unsigned int v23; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v24; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v25[2]; // [xsp+30h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 3680);
  v24 = 0;
  v25[0] = 0;
  v5 = *(const char **)(a1 + 152);
  v6 = *(_DWORD *)(a1 + 116);
  v23 = 0;
  v7 = *(unsigned int ***)(**(_QWORD **)(v4 + 232) + 264LL);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    3,
    "cam_hw_cdm_dump_core_debug_registers",
    368,
    "Dumping debug data for %s%u",
    v5,
    v6);
  v22 = a2;
  if ( (a2 & 1) != 0 )
    cam_hw_cdm_pause_core(a1, 1u);
  cam_cdm_read_hw_reg(a1, ***(_DWORD ***)(v4 + 232), (int *)&v23);
  v8 = 0;
  v9 = 0;
  v10 = 65793;
  do
  {
    v10 = v8 + (v10 & 0xFFFFFF0F);
    if ( cam_cdm_write_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(a1 + 3680) + 232LL) + 72LL), v10) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_enable_core_dbg",
        235,
        "Failed to Write CDM HW core debug");
    cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 96LL), (int *)&v24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      387,
      "Core_dbg: 0x%x, Debug_status[%d]: 0x%x",
      v10,
      v9++,
      v24);
    v8 += 16;
  }
  while ( v9 != 16 );
  if ( cam_cdm_write_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(a1 + 3680) + 232LL) + 72LL), 0x10100u) )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_enable_core_dbg",
      235,
      "Failed to Write CDM HW core debug");
  if ( cam_cdm_write_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(a1 + 3680) + 232LL) + 72LL), 0x10100u) )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_enable_core_dbg",
      235,
      "Failed to Write CDM HW core debug");
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 96LL), (int *)&v24);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    3,
    "cam_hw_cdm_dump_core_debug_registers",
    404,
    "Debug_status: 0x%x",
    v24);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 28LL), (int *)&v24);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 56LL), (int *)&v24 + 1);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    3,
    "cam_hw_cdm_dump_core_debug_registers",
    412,
    "Core_en: %u, Core_pause: %u User_data: 0x%x",
    v24 & 1,
    ((unsigned int)v24 >> 1) & 1,
    HIDWORD(v24));
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 92LL), (int *)&v24);
  if ( v23 >> 29 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      422,
      "Current AHB base address: 0x%x set by change base cmd by fifo: %u",
      v24 & 0xFFFFFF,
      ((unsigned int)v24 >> 28) & 3);
  else
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      426,
      "Current AHB base address: 0x%x set by change base cmd",
      v24 & 0xFFFFFF);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 64LL), (int *)&v24);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 68LL), (int *)&v24 + 1);
  if ( v23 >> 29 )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, unsigned int))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      442,
      "Last AHB addr: 0x%x, data: 0x%x that cdm sent out from fifo: %u",
      v24 & 0xFFFFFF,
      HIDWORD(v24),
      ((unsigned int)v24 >> 28) & 3);
  else
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      447,
      "Last AHB addr: 0x%x, data: 0x%x that cdm sent out",
      v24 & 0xFFFFFF,
      HIDWORD(v24),
      v19);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 76LL), (int *)&v24);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 80LL), (int *)&v24 + 1);
  if ( v23 >> 29 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      464,
      "Last Bad AHB addr: 0x%x and data: 0x%x from fifo: %u",
      v24 & 0xFFFFFF,
      HIDWORD(v24),
      ((unsigned int)v24 >> 28) & 3);
    if ( !v7 )
      goto LABEL_25;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      467,
      "Last Bad AHB addr: 0x%x and data: 0x%x",
      v24 & 0xFFFFFF,
      HIDWORD(v24));
    if ( !v7 )
      goto LABEL_25;
  }
  v11 = v7[1];
  if ( v11 )
  {
    cam_cdm_read_hw_reg(a1, v11[1], (int *)&v24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      479,
      "ICL_Status: last_invalid_fifo: %u, last known good fifo: %u",
      v24 & 3,
      ((unsigned int)v24 >> 4) & 3);
    cam_cdm_read_hw_reg(a1, *v7[1], (int *)&v24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      485,
      "Last Inv Command BL's base_addr: 0x%x",
      v24);
  }
  if ( *v7 )
  {
    cam_cdm_read_hw_reg(a1, (*v7)[3], (int *)&v24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      492,
      "First word of Last Inv cmd: 0x%x",
      v24);
    cam_cdm_read_hw_reg(a1, **v7, (int *)&v24);
    cam_cdm_read_hw_reg(a1, (*v7)[1], (int *)&v24 + 1);
    cam_cdm_read_hw_reg(a1, (*v7)[2], (int *)v25);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      506,
      "Last good cdm command's word[0]: 0x%x, word[1]: 0x%x, word[2]: 0x%x",
      v24,
      HIDWORD(v24),
      LODWORD(v25[0]));
  }
LABEL_25:
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 28LL), (int *)&v24);
  if ( (v24 & 0x20) != 0 )
  {
    cam_hw_cdm_dump_bl_fifo_data(a1);
  }
  else
  {
    cam_hw_cdm_pause_core(a1, 1u);
    cam_hw_cdm_dump_bl_fifo_data(a1);
    cam_hw_cdm_pause_core(a1, 0);
  }
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 24LL), (int *)&v24);
  v12 = ((unsigned int)v24 >> 4) & 1;
  v13 = ((unsigned int)v24 >> 8) & 1;
  if ( v23 >> 29 )
  {
    v14 = "RR";
    if ( (v24 & 0x10000) == 0 )
      v14 = "PRI";
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int, const char *, unsigned int, unsigned int))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      539,
      "Core cfg: AHB_Burst_Len: %u, AHB_Burst_En: %u, AHB_stop_on_err: %u, Priority: %s, Imp_Wait: %u, Pririty_mask: 0x%x",
      v24 & 0xF,
      v12,
      v13,
      v14,
      ((unsigned int)v24 >> 17) & 1,
      ((unsigned int)v24 >> 20) & 0xF);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      547,
      "Core cfg: AHB_Burst_Len: %u, AHB_Burst_En: %u, AHB_stop_on_err: %u",
      v24 & 0xF,
      v12,
      v13);
  }
  if ( v23 >= 0x20010000 )
  {
    cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 40LL), (int *)&v24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      553,
      "irq_context_status: 0x%x",
      v24);
  }
  v15 = *(_QWORD **)(v4 + 232);
  if ( *(_DWORD *)(v15[9] + 4LL) )
  {
    v16 = 5;
    do
    {
      if ( v16 == 9 )
        __break(0x5512u);
      cam_cdm_read_hw_reg(a1, *(_DWORD *)(v15[v16] + 20LL), (int *)&v24);
      cam_cdm_read_hw_reg(a1, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 232) + 8 * v16) + 12LL), (int *)&v24 + 1);
      cam_cdm_read_hw_reg(a1, **(_DWORD **)(*(_QWORD *)(v4 + 232) + 8 * v16), (int *)v25);
      cam_cdm_read_hw_reg(a1, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 232) + 8 * v16) + 4LL), (int *)v25 + 1);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        3,
        "cam_hw_cdm_dump_core_debug_registers",
        568,
        "cnt %d irq status 0x%x set 0x%x mask 0x%x clear 0x%x",
        v16 - 5,
        v24,
        HIDWORD(v24),
        LODWORD(v25[0]),
        HIDWORD(v25[0]));
      v15 = *(_QWORD **)(v4 + 232);
      v17 = v16 - 4;
      ++v16;
    }
    while ( v17 < *(unsigned int *)(v15[9] + 4LL) );
  }
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(*v15 + 84LL), (int *)&v24);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 88LL), (int *)&v24 + 1);
  if ( v23 >> 29 )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, int, _DWORD))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      586,
      "Last fetched BL by cdm from fifo: %u has Base: 0x%x, len: %d ARB: %d tag: %d ",
      (HIDWORD(v24) >> 22) & 3,
      (unsigned int)v24,
      HIDWORD(v24) & 0xFFFFF,
      (HIDWORD(v24) >> 20) & 1,
      HIBYTE(HIDWORD(v24)));
  else
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, int, int))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_dump_core_debug_registers",
      593,
      "Last fetched BL by cdm has Base: 0x%x, len: %d tag: %d ",
      (unsigned int)v24,
      HIDWORD(v24) & 0xFFFFF,
      HIBYTE(HIDWORD(v24)),
      v20,
      v21);
  cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v4 + 232) + 60LL), (int *)&v24);
  cam_cdm_read_hw_reg(a1, **(_DWORD **)(**(_QWORD **)(v4 + 232) + 128LL), (int *)&v24 + 1);
  cam_cdm_read_hw_reg(a1, **(_DWORD **)(**(_QWORD **)(v4 + 232) + 136LL), (int *)v25);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    3,
    "cam_hw_cdm_dump_core_debug_registers",
    604,
    "Wait status: 0x%x, Comp_wait_status0: 0x%x:, Comp_wait_status1: 0x%x",
    v24,
    HIDWORD(v24),
    LODWORD(v25[0]));
  result = cam_cdm_write_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(*(_QWORD *)(a1 + 3680) + 232LL) + 72LL), 0);
  if ( (result & 1) != 0 )
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               1,
               1,
               "cam_hw_cdm_disable_core_dbg",
               249,
               "Failed to Write CDM HW core debug");
  if ( (v22 & 1) != 0 )
    result = cam_hw_cdm_pause_core(a1, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
