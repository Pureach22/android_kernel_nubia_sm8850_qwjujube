__int64 __fastcall cam_hw_cdm_enable_bl_done_irq(__int64 a1, char a2, unsigned int a3)
{
  __int64 v6; // x23
  const char *v7; // x5
  __int64 v8; // x4
  __int64 result; // x0
  unsigned int v10; // w1
  const char *v12; // x5
  unsigned __int64 v13; // x8
  __int64 v14; // x4
  unsigned __int64 v20; // x10
  unsigned __int64 v23; // x11
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 3680);
  v24 = 0;
  if ( cam_cdm_read_hw_reg(a1, **(_DWORD **)(*(_QWORD *)(v6 + 232) + 8LL * a3 + 40), &v24) )
  {
    v7 = "Failed to read CDM IRQ mask";
    v8 = 143;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_enable_bl_done_irq",
      v8,
      v7);
    result = 4294967291LL;
    goto LABEL_4;
  }
  v10 = **(_DWORD **)(*(_QWORD *)(v6 + 232) + 8LL * a3 + 40);
  if ( (a2 & 1) != 0 )
  {
    if ( cam_cdm_write_hw_reg(a1, v10, v24 | 4) )
    {
      v7 = "Write failed to enable BL done irq";
      v8 = 151;
      goto LABEL_3;
    }
    _X8 = (unsigned __int64 *)(v6 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v20 = __ldxr(_X8);
    while ( __stxr(v20 | (1LL << a3), _X8) );
    result = 0;
    if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      v12 = "BL done irq enabled =%d";
      v13 = *(unsigned __int64 *)((char *)_X8 + (((unsigned __int64)a3 >> 3) & 0x1FFFFFF8));
      v14 = 156;
LABEL_18:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
        3,
        1,
        4,
        "cam_hw_cdm_enable_bl_done_irq",
        v14,
        v12,
        (v13 >> a3) & 1);
      result = 0;
    }
  }
  else
  {
    if ( cam_cdm_write_hw_reg(a1, v10, v24 & 0x70003) )
    {
      v7 = "Write failed to disable BL done irq";
      v8 = 162;
      goto LABEL_3;
    }
    _X10 = (unsigned __int64 *)(v6 + 4856 + 8LL * (a3 >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v23 = __ldxr(_X10);
    while ( __stxr(v23 & ~(1LL << a3), _X10) );
    result = 0;
    if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      v12 = "BL done irq disable =%d";
      v13 = *(_QWORD *)(v6 + 4856 + (((unsigned __int64)a3 >> 3) & 0x1FFFFFF8));
      v14 = 167;
      goto LABEL_18;
    }
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
