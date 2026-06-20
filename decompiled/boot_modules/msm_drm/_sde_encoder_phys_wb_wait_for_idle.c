__int64 __fastcall sde_encoder_phys_wb_wait_for_idle(__int64 a1, char a2)
{
  int v3; // w8
  int v5; // w4
  __int64 v6; // x8
  int v7; // w5
  int *v8; // x24
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  char v12; // w0
  __int64 v13; // x9
  __int64 v14; // x8
  unsigned int v15; // w9
  unsigned int v16; // w20
  __int64 v17; // x10
  int v18; // w5
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x9
  int v23; // w4
  __int64 v24; // x8
  int v25; // w5
  __int64 v26; // [xsp+18h] [xbp-38h] BYREF
  __int64 v27; // [xsp+20h] [xbp-30h]
  __int64 v28; // [xsp+28h] [xbp-28h]
  __int64 v29; // [xsp+30h] [xbp-20h]
  __int64 v30; // [xsp+3Ch] [xbp-14h] BYREF
  int v31; // [xsp+44h] [xbp-Ch]
  __int64 v32; // [xsp+48h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 832);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  if ( v3 == 1 )
  {
    printk(&unk_25110D, "_sde_encoder_phys_wb_wait_for_idle");
    v16 = -11;
    goto LABEL_27;
  }
  if ( *(_QWORD *)a1 )
  {
    v5 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    if ( !a1 )
      goto LABEL_8;
  }
  else
  {
    v5 = -1;
    if ( !a1 )
    {
LABEL_8:
      v7 = -1;
      goto LABEL_9;
    }
  }
  v6 = *(_QWORD *)(a1 + 2864);
  if ( !v6 )
    goto LABEL_8;
  v7 = *(_DWORD *)(v6 + 12) - 1;
LABEL_9:
  v8 = (int *)(a1 + 876);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_encoder_phys_wb_wait_for_idle",
    2349,
    -1,
    v5,
    v7,
    *(unsigned __int8 *)(a1 + 2290),
    *(_DWORD *)(a1 + 876),
    a2 & 1);
  if ( (a2 & 1) != 0 || *(_BYTE *)(a1 + 2290) != 1 || *v8 >= 2 )
  {
    v9 = *(_QWORD *)(a1 + 512);
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 2680) + 56LL);
    v11 = *(_QWORD *)(v10 + 72);
    LODWORD(v10) = *(_DWORD *)(v10 + 80);
    v30 = v11;
    v31 = v10;
    v12 = ((__int64 (__fastcall *)(__int64, __int64 *))sde_vbif_get_xin_status)(v9, &v30);
    v13 = *(_QWORD *)(a1 + 2816);
    if ( !v13 || (v12 & 1) != 0 )
    {
      if ( a1 && (v17 = *(_QWORD *)(a1 + 2864)) != 0 )
        v18 = *(_DWORD *)(v17 + 12) - 1;
      else
        v18 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_phys_wb_wait_for_idle",
        2361,
        -1,
        *(_QWORD *)a1,
        v18,
        v13 == 0,
        v12 & 1,
        239);
      v16 = 0;
    }
    else
    {
      if ( *v8 >= 2 )
        LODWORD(v28) = 1;
      LODWORD(v14) = *(_DWORD *)(a1 + 2688);
      v15 = *(_DWORD *)(a1 + 992);
      v26 = a1 + 896;
      v27 = a1 + 876;
      if ( (unsigned int)v14 <= v15 )
        v14 = v15;
      else
        v14 = (unsigned int)v14;
      v29 = v14;
      if ( (unsigned int)sde_encoder_helper_wait_for_irq((__int64 **)a1, 0xAu, &v26) != -110 )
        goto LABEL_20;
      v20 = *(_QWORD *)(a1 + 512);
      v21 = *(_QWORD *)(*(_QWORD *)(a1 + 2680) + 56LL);
      v22 = *(_QWORD *)(v21 + 72);
      LODWORD(v21) = *(_DWORD *)(v21 + 80);
      v30 = v22;
      v31 = v21;
      if ( (((__int64 (__fastcall *)(__int64, __int64 *))sde_vbif_get_xin_status)(v20, &v30) & 1) != 0 )
        v16 = 0;
      else
        v16 = -110;
      printk(&unk_258246, "_sde_encoder_phys_wb_wait_for_idle");
      if ( *(_QWORD *)a1 )
        v23 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      else
        v23 = -1;
      if ( a1 && (v24 = *(_QWORD *)(a1 + 2864)) != 0 )
        v25 = *(_DWORD *)(v24 + 12) - 1;
      else
        v25 = -1;
      sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_phys_wb_wait_for_idle", 2382, -1, v23, v25, *v8, 60333, 239);
    }
    sde_encoder_phys_wb_frame_done_helper(a1, v16 != 0);
    goto LABEL_27;
  }
LABEL_20:
  v16 = 0;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v16;
}
