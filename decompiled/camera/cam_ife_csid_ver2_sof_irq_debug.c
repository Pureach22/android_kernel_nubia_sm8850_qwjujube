__int64 __fastcall cam_ife_csid_ver2_sof_irq_debug(__int64 a1, int *a2)
{
  __int64 v3; // x8
  int v4; // w20
  __int64 v5; // x22
  __int64 v6; // x21
  __int64 v7; // x8
  int v8; // w1
  __int64 v9; // x8
  int v10; // w8
  __int64 v11; // x11
  const char *v12; // x7
  __int64 result; // x0
  int v14; // w7
  __int64 v15; // x6
  const char *v16; // x7
  int v17; // [xsp+10h] [xbp-10h] BYREF
  int v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 31128);
  v4 = *a2;
  v17 = 0;
  if ( *(_DWORD *)(v3 + 92) )
  {
    v5 = 0;
    v6 = **(_QWORD **)(a1 + 31136);
    do
    {
      v7 = *(_QWORD *)(a1 + v5 + 24);
      if ( v7 )
      {
        v8 = *(_DWORD *)(v7 + 208);
        if ( v8 )
        {
          v17 = 4096;
          v9 = *(unsigned int *)(a1 + v5 + 4);
          if ( (unsigned int)v9 > 0xB )
            __break(0x5512u);
          cam_irq_controller_update_irq(*(_QWORD *)(a1 + 31016 + 8 * v9), v8, v4 == 1, (__int64)&v17);
        }
      }
      v5 += 152;
    }
    while ( v5 != 1824 );
    v10 = *(_DWORD *)(a1 + 2200);
    v11 = *(_QWORD *)(a1 + 31120);
    *(_BYTE *)(a1 + 2150) = v4 == 1;
    *(_DWORD *)(a1 + 2200) = v10 & 0xFFFFEFFF | ((v4 == 1) << 12);
    if ( v4 == 1 )
      v12 = "enabled";
    else
      v12 = "disabled";
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_ife_csid_ver2_sof_irq_debug",
               665,
               "SOF freeze: CSID:%u SOF irq %s, Notify CSIPHY: %d",
               *(_DWORD *)(v11 + 4),
               v12,
               *(_DWORD *)(a1 + 2068) - 1);
    v14 = *(_DWORD *)(a1 + 2068) - *(_DWORD *)(*(_QWORD *)(v6 + 120) + 588LL);
    v18 = v14;
    if ( v4 == 1 )
    {
      v15 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      if ( v14 < 0 )
      {
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                   3,
                   8,
                   2,
                   "cam_ife_csid_ver2_sof_irq_debug",
                   671,
                   "CSID:%u Can't notify csiphy, incorrect phy selected=%d",
                   v15);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          3,
          "cam_ife_csid_ver2_sof_irq_debug",
          674,
          "CSID:%u Notify CSIPHY: %d",
          v15);
        result = cam_subdev_notify_message(65544, 1u, (__int64)&v18);
      }
    }
  }
  else
  {
    if ( v4 == 1 )
      v16 = "enable";
    else
      v16 = "disable";
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               2,
               "cam_ife_csid_ver2_sof_irq_debug",
               629,
               "CSID:%u powered down unable to %s sof irq",
               *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
               v16);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
