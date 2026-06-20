__int64 __fastcall cam_vfe_camif_lite_resource_start(__int64 a1)
{
  int v1; // w6
  __int64 v3; // x21
  __int64 v4; // x8
  int v5; // w10
  __int64 v6; // x9
  int v7; // w0
  __int64 v8; // x8
  int v9; // w20
  int v10; // w24
  __int64 result; // x0
  int v12; // w8
  char v13; // w8
  int v14; // w6
  unsigned int v15; // w19
  _DWORD v16[2]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v17; // [xsp+1Ch] [xbp-14h]
  int v18; // [xsp+24h] [xbp-Ch]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v17 = 0;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_resource_start",
      245,
      "Error! Invalid input arguments");
    result = 4294967274LL;
    goto LABEL_20;
  }
  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_resource_start",
      251,
      "Error! Invalid camif lite res res_state:%d",
      v1);
    result = 4294967274LL;
    goto LABEL_20;
  }
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(_QWORD *)(v3 + 32);
  v5 = *(_DWORD *)(v4 + 24);
  LODWORD(v4) = *(_DWORD *)(v4 + 28);
  v6 = *(unsigned int *)(*(_QWORD *)(v3 + 24) + 68LL);
  v16[0] = v5;
  v16[1] = v4;
  v7 = cam_io_r_mb(*(_QWORD *)v3 + v6);
  v8 = *(_QWORD *)(v3 + 32);
  v9 = v7;
  if ( *(_DWORD *)(v3 + 48) == 2 )
    v9 = (1 << *(_DWORD *)(v8 + 40)) | v7;
  v10 = 1 << *(_DWORD *)(v8 + 44);
  cam_io_w_mb(v10 | (unsigned int)v9, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 68LL));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_resource_start",
      276,
      "hw id:%d core_cfg val:%d",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
      v10 | v9);
  cam_io_w_mb(
    *(unsigned int *)(*(_QWORD *)(v3 + 32) + 4LL),
    *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 16LL));
  *(_DWORD *)(a1 + 8) = 4;
  cam_io_w_mb(**(unsigned int **)(v3 + 32), *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 20LL));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_resource_start",
      291,
      "hw id:%d RUP val:%d",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
      **(_DWORD **)(v3 + 32));
    if ( *(_DWORD *)(v3 + 72) )
      goto LABEL_11;
LABEL_15:
    v12 = cam_irq_controller_subscribe_irq(
            *(_QWORD *)(v3 + 80),
            0,
            (__int64)v16,
            a1,
            (__int64)cam_vfe_camif_lite_err_irq_top_half,
            *(_QWORD *)(a1 + 120),
            *(_QWORD *)(a1 + 56),
            tasklet_bh_api,
            0);
    result = 0;
    *(_DWORD *)(v3 + 72) = v12;
    if ( v12 <= 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_camif_lite_resource_start",
        305,
        "Error IRQ handle subscribe failure");
      result = 4294967284LL;
      *(_DWORD *)(v3 + 72) = 0;
    }
    goto LABEL_17;
  }
  if ( !*(_DWORD *)(v3 + 72) )
    goto LABEL_15;
LABEL_11:
  result = 0;
LABEL_17:
  v13 = debug_mdl;
  *(_QWORD *)(v3 + 22648) = 0;
  *(_QWORD *)(v3 + 22640) = 0;
  if ( (v13 & 8) != 0 && !debug_priority )
  {
    v14 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL);
    v15 = result;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v13 & 8,
      4,
      "cam_vfe_camif_lite_resource_start",
      315,
      "Start Camif Lite IFE %d Done",
      v14);
    result = v15;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
