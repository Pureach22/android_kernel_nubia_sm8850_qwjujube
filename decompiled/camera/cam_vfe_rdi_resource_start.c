__int64 __fastcall cam_vfe_rdi_resource_start(__int64 a1)
{
  int v1; // w6
  __int64 v3; // x20
  __int64 v4; // x8
  int v5; // w10
  unsigned int *v6; // x9
  unsigned int *v7; // x11
  __int64 result; // x0
  int v9; // w8
  unsigned int v10; // w23
  int v11; // w8
  char v12; // w8
  unsigned int v13; // w23
  int v14; // w6
  unsigned int v15; // w19
  int v16; // [xsp+10h] [xbp-30h] BYREF
  __int64 v17; // [xsp+14h] [xbp-2Ch]
  __int64 v18; // [xsp+1Ch] [xbp-24h]
  _DWORD v19[2]; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v20; // [xsp+2Ch] [xbp-14h]
  int v21; // [xsp+34h] [xbp-Ch]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v20 = 0;
  v18 = 0;
  v17 = 0;
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_rdi_resource_start",
      229,
      "Error! Invalid input arguments");
    result = 4294967274LL;
    goto LABEL_18;
  }
  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 != 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_rdi_resource_start",
      235,
      "Error! Invalid rdi res res_state:%d",
      v1);
    result = 4294967274LL;
    goto LABEL_18;
  }
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(_QWORD *)(v3 + 32);
  v5 = *(_DWORD *)(v4 + 8);
  LODWORD(v4) = *(_DWORD *)(v4 + 12);
  *(_DWORD *)(a1 + 8) = 4;
  v6 = *(unsigned int **)(v3 + 48);
  v7 = *(unsigned int **)(v3 + 24);
  v19[0] = v5;
  v19[1] = v4;
  cam_io_w_mb(*v6, *(_QWORD *)v3 + *v7);
  if ( *(_DWORD *)(v3 + 80) )
  {
    result = 0;
  }
  else
  {
    v9 = cam_irq_controller_subscribe_irq(
           *(_QWORD *)(v3 + 88),
           0,
           (__int64)v19,
           a1,
           (__int64)cam_vfe_rdi_err_irq_top_half,
           *(_QWORD *)(a1 + 120),
           *(_QWORD *)(a1 + 56),
           tasklet_bh_api,
           0);
    result = 0;
    *(_DWORD *)(v3 + 80) = v9;
    if ( v9 <= 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_rdi_resource_start",
        263,
        "Error IRQ handle subscribe failure");
      result = 4294967284LL;
      *(_DWORD *)(v3 + 80) = 0;
    }
  }
  if ( *(_BYTE *)(a1 + 144) == 1 )
  {
    v16 = *(_DWORD *)(*(_QWORD *)(v3 + 48) + 4LL) | *(_DWORD *)(*(_QWORD *)(v3 + 48) + 8LL);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v13 = result;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_rdi_resource_start",
        278,
        "RDI%d irq_mask 0x%x",
        (unsigned int)(*(_DWORD *)(a1 + 4) - 3));
      result = v13;
      if ( !*(_DWORD *)(v3 + 84) )
      {
LABEL_13:
        v10 = result;
        v11 = cam_irq_controller_subscribe_irq(
                *(_QWORD *)(v3 + 88),
                1u,
                (__int64)&v16,
                a1,
                *(_QWORD *)(a1 + 112),
                *(_QWORD *)(a1 + 120),
                *(_QWORD *)(a1 + 56),
                tasklet_bh_api,
                0);
        result = v10;
        *(_DWORD *)(v3 + 84) = v11;
        if ( v11 <= 0 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_rdi_resource_start",
            292,
            "IRQ handle subscribe failure");
          result = 4294967284LL;
          *(_DWORD *)(v3 + 84) = 0;
        }
      }
    }
    else if ( !*(_DWORD *)(v3 + 84) )
    {
      goto LABEL_13;
    }
    v12 = debug_mdl;
    *(_QWORD *)(v3 + 22672) = 0;
    *(_QWORD *)(v3 + 22664) = 0;
    *(_QWORD *)(v3 + 22656) = 0;
    *(_QWORD *)(v3 + 22648) = 0;
    if ( (v12 & 8) != 0 && !debug_priority )
    {
      v14 = *(_DWORD *)(a1 + 4) - 3;
      v15 = result;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v12 & 8,
        4,
        "cam_vfe_rdi_resource_start",
        304,
        "Start RDI %d",
        v14);
      result = v15;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
