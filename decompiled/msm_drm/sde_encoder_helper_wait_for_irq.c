__int64 __fastcall sde_encoder_helper_wait_for_irq(__int64 **a1, unsigned int a2, _QWORD *a3)
{
  __int64 *v5; // x8
  int v7; // w4
  int v8; // w4
  char v9; // w8
  int v10; // w23
  int v11; // w24
  __int64 v12; // x25
  __int64 v13; // x26
  __int64 v14; // x0
  __int64 v15; // x20
  unsigned int *v16; // x8
  unsigned int v17; // w19
  unsigned int v18; // w9
  unsigned int v19; // w10
  __int64 v21; // x8
  int v22; // w27
  int v23; // w8
  int v24; // w9
  bool v25; // zf
  __int64 v26; // x0
  __int64 v27; // x27
  int v28; // w8
  int v29; // w9
  bool v30; // zf
  __int64 v31; // x28
  __int64 v32; // x23
  __int64 **v33; // x24
  __int64 v34; // x8
  int v35; // w20
  __int64 v36; // x8
  unsigned int disp_op; // w0
  unsigned int v38; // w22
  int v39; // w4
  int v40; // w4
  int v41; // w4
  int v43; // w4
  void *v44; // x0
  __int64 *v45; // x8
  unsigned int (__fastcall *v46)(_QWORD); // x9
  __int64 *v47; // x0
  int v48; // w4
  __int64 *v49; // x8
  int v50; // w6
  unsigned __int64 StatusReg; // x19
  void (__fastcall *v56)(__int64 **, __int64); // x8
  __int64 v57; // x1
  int v58; // [xsp+28h] [xbp-48h]
  char v59; // [xsp+2Ch] [xbp-44h]
  __int64 **v60; // [xsp+30h] [xbp-40h]
  __int64 v61; // [xsp+38h] [xbp-38h]
  _QWORD v62[6]; // [xsp+40h] [xbp-30h] BYREF

  v62[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || a2 > 0x16 || !a3 || (v5 = a1[62]) == nullptr )
  {
    printk(&unk_223EAA, "sde_encoder_helper_wait_for_irq");
    v38 = -22;
    goto LABEL_77;
  }
  if ( *((_DWORD *)a1 + 208) == 1 )
  {
    printk(&unk_276E2B, "sde_encoder_helper_wait_for_irq");
    if ( *a1 )
      v39 = *((_DWORD *)*a1 + 6);
    else
      v39 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_helper_wait_for_irq",
      591,
      -1,
      v39,
      a2,
      (int)a1[7 * a2 + 127],
      HIDWORD(a1[7 * a2 + 127]),
      a2);
    v38 = -11;
    goto LABEL_77;
  }
  if ( (HIDWORD(a1[7 * a2 + 127]) & 0x80000000) != 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "enc%d intf%d pp%d irq %s hw %d disabled, skip wait\n",
        *((_DWORD *)*a1 + 6),
        *((_DWORD *)a1 + 168) - 1,
        *((_DWORD *)v5 + 8) - 1,
        (const char *)a1[7 * a2 + 125],
        LODWORD(a1[7 * a2 + 127]));
    if ( *a1 )
      v8 = *((_DWORD *)*a1 + 6);
    else
      v8 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_helper_wait_for_irq",
      599,
      -1,
      v8,
      a2,
      (int)a1[7 * a2 + 127],
      HIDWORD(a1[7 * a2 + 127]),
      239);
    v38 = 0;
    goto LABEL_77;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "enc%d intf%d pp%d pending_cnt %d\n",
      *((_DWORD *)*a1 + 6),
      *((_DWORD *)a1 + 168) - 1,
      *((_DWORD *)v5 + 8) - 1,
      *(_DWORD *)a3[1]);
  if ( *a1 )
    v7 = *((_DWORD *)*a1 + 6);
  else
    v7 = -1;
  v60 = a1;
  v61 = (__int64)&a1[7 * a2 + 125];
  v58 = a2;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_helper_wait_for_irq",
    607,
    4,
    v7,
    a2,
    (int)a1[7 * a2 + 127],
    HIDWORD(a1[7 * a2 + 127]),
    *((_BYTE *)a1[62] + 32) - 1);
  v9 = 1;
  while ( 2 )
  {
    v59 = v9;
    if ( *a1 )
      v10 = *((_DWORD *)*a1 + 6);
    else
      v10 = -1;
    v11 = *(_DWORD *)(v61 + 16);
    v12 = a3[3] / 2LL;
    v13 = _msecs_to_jiffies((unsigned int)v12);
    v14 = ktime_get(v13);
    v15 = v14 + 1000000 * v12;
    v16 = (unsigned int *)a3[1];
    v17 = *v16;
    v18 = *((_DWORD *)a3 + 4);
    while ( 1 )
    {
      v19 = *v16;
      if ( v13 )
        _ZF = 0;
      else
        _ZF = v19 == v18;
      if ( _ZF )
        v21 = 1;
      else
        v21 = v13;
      if ( v19 == v18 )
      {
        v22 = v21;
      }
      else
      {
        v22 = v21;
        if ( v21 )
        {
          memset(v62, 0, 40);
          init_wait_entry(v62, 0);
          prepare_to_wait_event(*a3, v62, 2);
          v23 = *(_DWORD *)a3[1];
          v24 = *((_DWORD *)a3 + 4);
          if ( v13 )
            v25 = 0;
          else
            v25 = v23 == v24;
          if ( v25 )
            v26 = 1;
          else
            v26 = v13;
          if ( v23 != v24 && v26 )
          {
            do
            {
              v27 = schedule_timeout(v26);
              prepare_to_wait_event(*a3, v62, 2);
              v28 = *(_DWORD *)a3[1];
              v29 = *((_DWORD *)a3 + 4);
              if ( v27 )
                v30 = 0;
              else
                v30 = v28 == v29;
              if ( v30 )
                v26 = 1;
              else
                v26 = v27;
            }
            while ( v28 != v29 && v26 );
          }
          v22 = v26;
          v14 = finish_wait(*a3, v62);
        }
      }
      v31 = ktime_get(v14);
      v14 = sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_encoder_wait_timeout",
              436,
              -1,
              v10,
              v11,
              v22,
              (int)v31 / 1000000,
              v12);
      v16 = (unsigned int *)a3[1];
      v18 = *((_DWORD *)a3 + 4);
      if ( *v16 < v18 && v18 < v17 )
        goto LABEL_69;
      if ( *v16 == v18 || v22 )
        break;
      if ( v15 - v31 <= 0 )
        goto LABEL_54;
    }
    if ( v22 )
    {
      if ( v22 > 0 )
      {
LABEL_69:
        v33 = a1;
        if ( *a1 )
          v40 = *((_DWORD *)*a1 + 6);
        else
          v40 = -1;
        v32 = v61;
        v35 = v58;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_helper_wait_for_irq",
          654,
          -1,
          v40,
          v58,
          *(_DWORD *)(v61 + 16),
          *(_DWORD *)(v61 + 20),
          *((_BYTE *)a1[62] + 32) - 1);
        v38 = 0;
        goto LABEL_73;
      }
    }
    else
    {
LABEL_54:
      v9 = 0;
      if ( (v59 & 1) != 0 )
        continue;
    }
    break;
  }
  v33 = a1;
  v32 = v61;
  if ( !(unsigned int)sde_core_irq_read(a1[64], *(unsigned int *)(v61 + 20), 1) )
  {
    if ( *a1 )
      v43 = *((_DWORD *)*a1 + 6);
    else
      v43 = -1;
    v35 = v58;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_helper_wait_for_irq",
      648,
      -1,
      v43,
      v58,
      *(_DWORD *)(v61 + 16),
      *(_DWORD *)(v61 + 20),
      *((_BYTE *)a1[62] + 32) - 1);
    v38 = -110;
    goto LABEL_73;
  }
  if ( !*a1 )
  {
    v35 = v58;
LABEL_86:
    disp_op = 0;
    goto LABEL_87;
  }
  v34 = **a1;
  v35 = v58;
  if ( !v34 )
  {
    v44 = &unk_26FCAB;
    goto LABEL_85;
  }
  v36 = *(_QWORD *)(v34 + 56);
  if ( !v36 || !*(_QWORD *)(v36 + 8) )
  {
    v44 = &unk_234896;
LABEL_85:
    printk(v44, "sde_encoder_get_kms");
    goto LABEL_86;
  }
  disp_op = sde_kms_get_disp_op();
LABEL_87:
  v45 = a1[52];
  if ( !v45 )
    goto LABEL_95;
  if ( disp_op >= 3 )
  {
    __break(0x5512u);
    return sde_encoder_helper_hw_fence_sw_override();
  }
  v46 = (unsigned int (__fastcall *)(_QWORD))v45[disp_op + 98];
  if ( v46 )
  {
    v47 = a1[52];
    if ( *((_DWORD *)v46 - 1) != 1814623283 )
      __break(0x8229u);
    if ( v46(v47) )
      v38 = -110;
    else
      v38 = 0;
  }
  else
  {
LABEL_95:
    v38 = 0;
  }
  if ( *v60 )
    v48 = *((_DWORD *)*v60 + 6);
  else
    v48 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_helper_wait_for_irq",
    636,
    -1,
    v48,
    v35,
    *(_DWORD *)(v61 + 16),
    *(_DWORD *)(v61 + 20),
    *((_DWORD *)v60[62] + 8) - 1);
  if ( (_drm_debug & 4) != 0 )
  {
    v49 = v60[62];
    if ( v49 )
      v50 = *((_DWORD *)v49 + 8) - 1;
    else
      v50 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "enc%d intf%d pp%d done but irq %d not triggered\n",
      *((_DWORD *)*v60 + 6),
      *((_DWORD *)v60 + 168) - 1,
      v50,
      *(_DWORD *)(v61 + 20));
  }
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v56 = *(void (__fastcall **)(__int64 **, __int64))(v61 + 40);
  v57 = *(unsigned int *)(v61 + 20);
  if ( *((_DWORD *)v56 - 1) != 1607364836 )
    __break(0x8228u);
  v56(v33, v57);
  _WriteStatusReg(DAIF, StatusReg);
LABEL_73:
  if ( *v33 )
    v41 = *((_DWORD *)*v33 + 6);
  else
    v41 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_helper_wait_for_irq",
    659,
    4,
    v41,
    v35,
    *(_DWORD *)(v32 + 16),
    *(_DWORD *)(v32 + 20),
    v38);
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return v38;
}
