__int64 __fastcall cam_vfe_camif_resource_start(__int64 a1)
{
  int v1; // w6
  __int64 v3; // x21
  _DWORD *v4; // x8
  int v5; // w11
  __int64 v6; // x25
  int v7; // w12
  unsigned int v8; // w20
  unsigned int v9; // w9
  int v10; // w8
  unsigned int v11; // w8
  char v12; // w8
  unsigned int v13; // w0
  int v14; // w0
  int v15; // w0
  __int64 result; // x0
  int v17; // w8
  int v18; // w10
  int v19; // w9
  unsigned int v20; // w8
  unsigned int v21; // w9
  unsigned int v22; // w20
  _DWORD v23[2]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v24; // [xsp+18h] [xbp-28h]
  int v25; // [xsp+20h] [xbp-20h]
  _DWORD v26[2]; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v27; // [xsp+2Ch] [xbp-14h]
  int v28; // [xsp+34h] [xbp-Ch]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v27 = 0;
  v25 = 0;
  v24 = 0;
  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 8);
    if ( v1 == 2 )
    {
      v3 = *(_QWORD *)(a1 + 24);
      v4 = *(_DWORD **)(v3 + 32);
      v5 = v4[25];
      v6 = *(_QWORD *)(*(_QWORD *)(v3 + 40) + 3296LL);
      v26[0] = v4[24];
      v26[1] = v5;
      v7 = v4[27];
      v23[0] = v4[26];
      v23[1] = v7;
      if ( v6 )
      {
        v8 = *(_DWORD *)(v3 + 22636) << v4[12];
        if ( *(_DWORD *)(v3 + 22628) == 2 )
          v8 |= 1 << v4[10];
        v9 = *(_DWORD *)(v3 + 22632) - 1;
        if ( v9 <= 1 )
          v8 |= ((v4[15] & v9) << v4[14]) | (1 << v4[16]);
        cam_io_w_mb(v8, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 24) + 68LL));
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_camif_resource_start",
            409,
            "hw id:%d core_cfg val:%d",
            *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
            v8);
        cam_io_w_mb(0xFFFFFFFFLL, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v3 + 24) + 40LL) + 4LL));
        v10 = *(_DWORD *)(v6 + 4);
        if ( (unsigned int)(v10 - 1507584) <= 0x20 && ((1LL << *(_DWORD *)(v6 + 4)) & 0x100010001LL) != 0
          || v10 == 1507840 )
        {
          cam_io_w_mb(
            *(unsigned int *)(*(_QWORD *)(v3 + 32) + 76LL),
            *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 24LL));
        }
        else
        {
          v17 = *(_DWORD *)(v3 + 22652);
          v18 = *(_DWORD *)(v3 + 22644);
          v19 = *(_DWORD *)(v3 + 22660) + v17;
          v20 = v17 - v18;
          v21 = (unsigned int)(v19 - v18) >> 1;
          if ( v21 < v20 )
            v20 = v21;
          v22 = *(unsigned __int16 *)(*(_QWORD *)(v3 + 32) + 76LL) | (v20 << 16);
          cam_io_w_mb(v22, *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 24LL));
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_camif_resource_start",
              448,
              "first_line: %u\nlast_line: %u vbi: %u\nepoch_line_cfg: 0x%x",
              *(_DWORD *)(v3 + 22644),
              *(_DWORD *)(v3 + 22652),
              *(_DWORD *)(v3 + 22660),
              v22);
        }
        if ( *(_DWORD *)(v3 + 22680) )
        {
          v11 = *(_DWORD *)(*(_QWORD *)(v3 + 32) + 116LL);
          if ( v11 )
            cam_io_w_mb(
              (*(_DWORD *)(v3 + 22676) & v11) + 1,
              *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 48LL));
        }
        *(_DWORD *)(a1 + 8) = 4;
        cam_io_w_mb(
          *(unsigned int *)(*(_QWORD *)(v3 + 32) + 72LL),
          *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 36LL));
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_camif_resource_start",
            464,
            "hw id:%d RUP val:%d",
            *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
            *(_DWORD *)(*(_QWORD *)(v3 + 32) + 72LL));
        v12 = *(_BYTE *)(v3 + 22672);
        *(_BYTE *)(v3 + 22664) = 0;
        *(_DWORD *)(v3 + 22668) = 0;
        if ( (v12 & 1) != 0 )
        {
          v13 = cam_io_r_mb(*(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 40LL));
          cam_io_w_mb(
            *(_DWORD *)(*(_QWORD *)(v3 + 32) + 112LL) | v13,
            *(_QWORD *)v3 + *(unsigned int *)(*(_QWORD *)(v3 + 16) + 40LL));
        }
        if ( (*(_DWORD *)(v3 + 22628) != 2 || !*(_DWORD *)(v3 + 22680)) && !*(_DWORD *)(v3 + 68) )
        {
          v14 = cam_irq_controller_subscribe_irq(
                  *(_QWORD *)(v3 + 72),
                  1u,
                  (__int64)v23,
                  a1,
                  *(_QWORD *)(a1 + 112),
                  *(_QWORD *)(a1 + 120),
                  *(_QWORD *)(a1 + 56),
                  tasklet_bh_api,
                  0);
          *(_DWORD *)(v3 + 68) = v14;
          if ( v14 <= 0 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_camif_resource_start",
              495,
              "IRQ handle subscribe failure");
            *(_DWORD *)(v3 + 68) = 0;
          }
        }
        if ( !*(_DWORD *)(v3 + 64) )
        {
          v15 = cam_irq_controller_subscribe_irq(
                  *(_QWORD *)(v3 + 72),
                  0,
                  (__int64)v26,
                  a1,
                  (__int64)cam_vfe_camif_err_irq_top_half,
                  *(_QWORD *)(a1 + 120),
                  *(_QWORD *)(a1 + 56),
                  tasklet_bh_api,
                  0);
          *(_DWORD *)(v3 + 64) = v15;
          if ( v15 <= 0 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_camif_resource_start",
              513,
              "Error IRQ handle subscribe failure");
            *(_DWORD *)(v3 + 64) = 0;
          }
        }
        result = 0;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_camif_resource_start",
            518,
            "Start Camif IFE %d Done",
            *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
          result = 0;
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_camif_resource_start",
          387,
          "Error! soc_private NULL");
        result = 4294967277LL;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_camif_resource_start",
        370,
        "Error! Invalid camif res res_state:%d",
        v1);
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_resource_start",
      364,
      "Error! Invalid input arguments");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
