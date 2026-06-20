__int64 __fastcall cam_ife_csid_ver1_sof_irq_debug(__int64 a1, int *a2)
{
  __int64 v2; // x21
  int v3; // w19
  __int64 v4; // x20
  _QWORD *v5; // x22
  _DWORD *v6; // x8
  unsigned int v7; // w24
  int v8; // w0
  int v9; // w0
  int v10; // w23
  int v11; // w0
  int v12; // w0
  int v13; // w0
  int v14; // w0
  __int64 v15; // x0
  __int64 v16; // x1
  int v17; // w0
  int v18; // w23
  int v19; // w0
  int v20; // w0
  int v21; // w9
  int v22; // w8
  const char *v23; // x6
  unsigned int v24; // w9
  char v25; // w8
  const char *v26; // x6
  __int64 result; // x0
  int v28; // w10
  int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v3 = *a2;
  if ( !*(_DWORD *)(v2 + 92) )
  {
    if ( v3 == 1 )
      v26 = "enable";
    else
      v26 = "disable";
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               2,
               "cam_ife_csid_ver1_sof_irq_debug",
               3332,
               "CSID powered down unable to %s sof irq",
               v26);
    goto LABEL_23;
  }
  v4 = a1 + 24576;
  v5 = **(_QWORD ***)(a1 + 16);
  v29 = *(_DWORD *)(a1 + 28264);
  v6 = (_DWORD *)v5[12];
  if ( v6[39] )
  {
    v7 = 0;
    do
    {
      v8 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[1] + 4LL));
      cam_io_w_mb(v8 & 0xFFFFEFFF | ((v3 == 1) << 12), *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[1] + 4LL));
      v6 = (_DWORD *)v5[12];
      ++v7;
    }
    while ( v7 < v6[39] );
  }
  if ( !v6[38] )
    goto LABEL_27;
  v9 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[3] + 4LL));
  cam_io_w_mb(v9 & 0xFFFFEFFF | ((v3 == 1) << 12), *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[3] + 4LL));
  v6 = (_DWORD *)v5[12];
  if ( v6[38] <= 1u )
    goto LABEL_27;
  v10 = (v3 == 1) << 12;
  v11 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[4] + 4LL));
  cam_io_w_mb(v11 & 0xFFFFEFFF | v10, *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[4] + 4LL));
  v6 = (_DWORD *)v5[12];
  if ( v6[38] < 3u )
    goto LABEL_27;
  v12 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[5] + 4LL));
  cam_io_w_mb(v12 & 0xFFFFEFFF | v10, *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[5] + 4LL));
  v6 = (_DWORD *)v5[12];
  if ( v6[38] < 4u
    || (v13 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[6] + 4LL)),
        cam_io_w_mb(v13 & 0xFFFFEFFF | v10, *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[6] + 4LL)),
        v6 = (_DWORD *)v5[12],
        v6[38] < 5u)
    || (v14 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[7] + 4LL)),
        v15 = cam_io_w_mb(v14 & 0xFFFFEFFF | v10, *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[7] + 4LL)),
        v6 = (_DWORD *)v5[12],
        v6[38] <= 5u) )
  {
LABEL_27:
    if ( !v6[37]
      || (v17 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[8] + 4LL)),
          cam_io_w_mb(v17 & 0xFFFFEFFF | ((v3 == 1) << 12), *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[8] + 4LL)),
          *(_DWORD *)(v5[12] + 148LL) <= 1u)
      || (v18 = (v3 == 1) << 12,
          v19 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[9] + 4LL)),
          cam_io_w_mb(v19 & 0xFFFFEFFF | v18, *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[9] + 4LL)),
          *(_DWORD *)(v5[12] + 148LL) < 3u)
      || (v20 = cam_io_r_mb(*(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[10] + 4LL)),
          v15 = cam_io_w_mb(v20 & 0xFFFFEFFF | v18, *(_QWORD *)(v2 + 384) + *(unsigned int *)(v5[10] + 4LL)),
          *(_DWORD *)(v5[12] + 148LL) <= 3u) )
    {
      v21 = *(_DWORD *)(v4 + 3780);
      if ( v3 == 1 )
      {
        v22 = *(_DWORD *)(v4 + 3756);
        v23 = "enabled";
        *(_DWORD *)(v4 + 3780) = v21 | 0x1000;
        v24 = v22 | 1;
        v25 = 1;
      }
      else
      {
        v28 = *(_DWORD *)(v4 + 3756);
        v25 = 0;
        *(_DWORD *)(v4 + 3780) = v21 & 0xFFFFEFFF;
        v23 = "disabled";
        v24 = v28 & 0xFFFFFFFE;
      }
      *(_DWORD *)(v4 + 3756) = v24;
      *(_BYTE *)(v4 + 3738) = v25;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_ife_csid_ver1_sof_irq_debug",
        3396,
        "SOF freeze: CSID SOF irq %s",
        v23);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_ife_csid_ver1_sof_irq_debug",
        3399,
        "Notify CSIPHY: %d",
        *(_DWORD *)(v4 + 3688));
      result = cam_subdev_notify_message(65544, 1u, (__int64)&v29);
LABEL_23:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  __break(0x5512u);
  return cam_ife_csid_ver1_print_hbi_vbi(v15, v16);
}
