__int64 __fastcall cam_vfe_top_ver4_update_sof_debug(__int64 *a1, unsigned int a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v5; // x11
  int v6; // w2
  char v7; // w10
  int v8; // w1
  __int64 v9; // [xsp+10h] [xbp-30h]
  char v10; // [xsp+1Ch] [xbp-24h]
  _QWORD v11[2]; // [xsp+20h] [xbp-20h] BYREF
  int v12; // [xsp+30h] [xbp-10h]
  __int64 v13; // [xsp+38h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 != 16 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver4_update_sof_debug",
      1919,
      "Invalid arg size expected: %zu actual: %zu",
      0x10u,
      a2);
    result = 4294967274LL;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v2 = *a1;
  v12 = 0;
  v11[0] = 0;
  v11[1] = 0;
  v3 = *(_QWORD *)(v2 + 24);
  if ( *(_DWORD *)(v3 + 100) )
  {
    result = 0;
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_13;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver4_update_sof_debug",
      1931,
      "Frame IRQ (including SOF) is enabled, no SOF IRQ registration is needed");
    goto LABEL_12;
  }
  v5 = *(unsigned int *)(*(_QWORD *)(v3 + 24) + 776LL);
  if ( (unsigned int)v5 < 5 )
  {
    v6 = *((unsigned __int8 *)a1 + 8);
    v7 = debug_mdl;
    *((_DWORD *)v11 + v5) = *(_DWORD *)(*(_QWORD *)(v3 + 64) + 4LL);
    *(_BYTE *)(v3 + 22813) = v6;
    if ( (v7 & 8) != 0 && !debug_priority )
    {
      v10 = v6;
      v9 = v3;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v7 & 8,
        4,
        "cam_vfe_top_ver4_update_sof_debug",
        1941,
        "hw_idx:%u sof debug irq value:%d res_id:%d res:%s",
        *(_DWORD *)(*(_QWORD *)(v3 + 16) + 4LL),
        v6,
        *(_DWORD *)(v2 + 4),
        (const char *)(v2 + 128));
      v3 = v9;
      LOBYTE(v6) = v10;
      v8 = *(_DWORD *)(v9 + 104);
      if ( !v8 )
        goto LABEL_12;
    }
    else
    {
      v8 = *(_DWORD *)(v3 + 104);
      if ( !v8 )
      {
LABEL_12:
        result = 0;
        goto LABEL_13;
      }
    }
    cam_irq_controller_update_irq(*(_QWORD *)(v3 + 112), v8, v6, (__int64)v11);
    goto LABEL_12;
  }
  __break(0x5512u);
  return cam_vfe_res_mux_init();
}
