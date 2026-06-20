__int64 __fastcall sde_encoder_virt_disable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  _DWORD *v8; // x20
  __int64 v9; // x24
  int v10; // w26
  __int64 *v11; // x27
  __int64 v12; // x8
  __int64 v14; // x9
  __int64 v15; // x25
  __int64 v16; // x8
  __int64 v17; // x22
  __int64 v18; // x9
  __int64 v19; // x23
  __int64 v20; // x1
  unsigned int v21; // w8
  __int64 v22; // x21
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x9
  void (__fastcall *v26)(_QWORD); // x9
  __int64 v27; // x0
  void (__fastcall *v28)(_QWORD); // x8
  __int64 v29; // x21
  void (__fastcall *v30)(_QWORD); // x9
  __int64 v31; // x0
  void (__fastcall *v32)(_QWORD); // x8
  __int64 v33; // x21
  void (__fastcall *v34)(_QWORD); // x9
  __int64 v35; // x0
  void (__fastcall *v36)(_QWORD); // x8
  __int64 v37; // x21
  void (__fastcall *v38)(_QWORD); // x9
  __int64 v39; // x0
  void (__fastcall *v40)(_QWORD); // x8
  _QWORD *v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  unsigned int disp_op; // w0
  int v45; // w7
  unsigned int (__fastcall *v46)(_QWORD); // x8
  __int64 v47; // x8
  int v48; // w6
  int v49; // w7
  __int64 v50; // x8
  int v51; // w4
  int v52; // w8
  __int64 result; // x0
  int v54; // w8
  unsigned int v55; // w8
  __int64 v56; // x0
  void (*v57)(void); // x9
  __int64 v58; // x0
  void (*v59)(void); // x9
  __int64 v60; // x0
  void (*v61)(void); // x9
  __int64 v62; // x0
  void (*v63)(void); // x9
  __int64 v64; // x8
  __int64 v65; // x8
  __int64 v66; // x8
  __int64 v67; // x9
  int v68; // w8
  __int64 v69; // x9
  __int64 v70; // x9
  __int64 v71; // x9
  __int64 v72; // x9
  unsigned int v73; // w8
  __int64 v74; // x0
  void (*v75)(void); // x9
  __int64 v76; // x0
  void (*v77)(void); // x9
  __int64 v78; // x0
  void (*v79)(void); // x9
  __int64 v80; // x0
  void (*v81)(void); // x9
  unsigned int v82; // w8
  void *v83; // x0
  char v84; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return printk(&unk_249308, "sde_encoder_virt_disable");
  v12 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 || !*(_QWORD *)(v12 + 56) )
    return printk(&unk_249308, "sde_encoder_virt_disable");
  if ( (*(_WORD *)(*(_QWORD *)(v12 + 8) + 488LL) & 7) != 0 )
    return printk(&unk_24FBDF, "sde_encoder_virt_disable");
  v14 = *(_QWORD *)(a1 + 328);
  if ( !v14 )
    return printk(&unk_2319EE, "sde_encoder_virt_disable");
  v15 = *(_QWORD *)(v14 + 8);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
    v12 = *(_QWORD *)a1;
    if ( !*(_QWORD *)a1 )
      return printk(&unk_26FCAB, "sde_encoder_get_kms");
  }
  v16 = *(_QWORD *)(v12 + 56);
  if ( !v16 )
    return printk(&unk_234896, "sde_encoder_get_kms");
  v17 = *(_QWORD *)(v16 + 8);
  if ( !v17 )
    return printk(&unk_234896, "sde_encoder_get_kms");
  v18 = *(_QWORD *)(a1 + 328);
  v19 = *(_QWORD *)(*(_QWORD *)(v18 + 8) + 2512LL);
  if ( !v19 )
    return printk(&unk_215D04, "sde_encoder_virt_disable");
  if ( v18 )
    goto LABEL_12;
  v52 = *(_DWORD *)(a1 + 196);
  if ( v52 )
  {
    v18 = *(_QWORD *)(a1 + 200);
    if ( !v18 )
    {
      if ( v52 == 1 )
        goto LABEL_85;
      v18 = *(_QWORD *)(a1 + 208);
      if ( !v18 )
      {
        if ( v52 == 2 )
          goto LABEL_85;
        v18 = *(_QWORD *)(a1 + 216);
        if ( !v18 )
        {
          if ( v52 == 3 )
            goto LABEL_85;
          v18 = *(_QWORD *)(a1 + 224);
          if ( !v18 )
          {
            if ( v52 != 4 )
              goto LABEL_190;
            goto LABEL_85;
          }
        }
      }
    }
LABEL_12:
    v10 = *(_DWORD *)(v18 + 668);
    goto LABEL_13;
  }
LABEL_85:
  v10 = 0;
LABEL_13:
  v8 = *(_DWORD **)(a1 + 80);
  v11 = &qword_294000;
  v9 = *(_QWORD *)(*(_QWORD *)v8 + 56LL);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_virt_disable",
    4397,
    -1,
    *(_DWORD *)(a1 + 24),
    -1059143953,
    a7,
    a8,
    v84);
  v21 = *(_DWORD *)(a1 + 196);
  if ( !v21 )
  {
LABEL_62:
    sde_encoder_wait_for_event(a1, 1u);
    goto LABEL_63;
  }
  v22 = *(_QWORD *)(a1 + 200);
  if ( !v22 || (*(_BYTE *)(v22 + 2290) & 1) == 0 )
  {
    if ( v21 == 1 )
      goto LABEL_26;
    v23 = *(_QWORD *)(a1 + 208);
    if ( v23 && (*(_BYTE *)(v23 + 2290) & 1) != 0 )
      goto LABEL_63;
    if ( v21 == 2 )
      goto LABEL_26;
    v24 = *(_QWORD *)(a1 + 216);
    if ( v24 && (*(_BYTE *)(v24 + 2290) & 1) != 0 )
      goto LABEL_63;
    if ( v21 == 3 )
    {
LABEL_26:
      if ( v22 )
      {
        v26 = *(void (__fastcall **)(_QWORD))(v22 + 320);
        if ( v26 )
        {
          if ( *(_QWORD *)(v22 + 360) )
          {
            v27 = *(_QWORD *)(a1 + 200);
            if ( *((_DWORD *)v26 - 1) != -511414616 )
              __break(0x8229u);
            v26(v27);
            v28 = *(void (__fastcall **)(_QWORD))(v22 + 360);
            if ( *((_DWORD *)v28 - 1) != -511414616 )
              __break(0x8228u);
            v28(v22);
            v21 = *(_DWORD *)(a1 + 196);
          }
        }
      }
      if ( v21 >= 2 )
      {
        v29 = *(_QWORD *)(a1 + 208);
        if ( v29 )
        {
          v30 = *(void (__fastcall **)(_QWORD))(v29 + 320);
          if ( v30 )
          {
            if ( *(_QWORD *)(v29 + 360) )
            {
              v31 = *(_QWORD *)(a1 + 208);
              if ( *((_DWORD *)v30 - 1) != -511414616 )
                __break(0x8229u);
              v30(v31);
              v32 = *(void (__fastcall **)(_QWORD))(v29 + 360);
              if ( *((_DWORD *)v32 - 1) != -511414616 )
                __break(0x8228u);
              v32(v29);
              v21 = *(_DWORD *)(a1 + 196);
            }
          }
        }
        if ( v21 >= 3 )
        {
          v33 = *(_QWORD *)(a1 + 216);
          if ( v33 )
          {
            v34 = *(void (__fastcall **)(_QWORD))(v33 + 320);
            if ( v34 )
            {
              if ( *(_QWORD *)(v33 + 360) )
              {
                v35 = *(_QWORD *)(a1 + 216);
                if ( *((_DWORD *)v34 - 1) != -511414616 )
                  __break(0x8229u);
                v34(v35);
                v36 = *(void (__fastcall **)(_QWORD))(v33 + 360);
                if ( *((_DWORD *)v36 - 1) != -511414616 )
                  __break(0x8228u);
                v36(v33);
                v21 = *(_DWORD *)(a1 + 196);
              }
            }
          }
          if ( v21 >= 4 )
          {
            v37 = *(_QWORD *)(a1 + 224);
            if ( v37 )
            {
              v38 = *(void (__fastcall **)(_QWORD))(v37 + 320);
              if ( v38 )
              {
                if ( *(_QWORD *)(v37 + 360) )
                {
                  v39 = *(_QWORD *)(a1 + 224);
                  if ( *((_DWORD *)v38 - 1) != -511414616 )
                    __break(0x8229u);
                  v38(v39);
                  v40 = *(void (__fastcall **)(_QWORD))(v37 + 360);
                  if ( *((_DWORD *)v40 - 1) != -511414616 )
                    __break(0x8228u);
                  v40(v37);
                  v21 = *(_DWORD *)(a1 + 196);
                }
              }
            }
            if ( v21 > 4 )
              goto LABEL_190;
          }
        }
      }
      goto LABEL_62;
    }
    v25 = *(_QWORD *)(a1 + 224);
    if ( !v25 || (*(_BYTE *)(v25 + 2290) & 1) == 0 )
    {
      if ( v21 != 4 )
        goto LABEL_190;
      goto LABEL_26;
    }
  }
LABEL_63:
  if ( *(_DWORD *)(a1 + 648) == 2 && *(_BYTE *)(a1 + 837) == 1 )
  {
    v41 = *(_QWORD **)(a1 + 1304);
    if ( v41 )
    {
      if ( *v41 )
      {
        input_unregister_handler();
        **(_QWORD **)(a1 + 1304) = 0;
      }
    }
  }
  if ( !*(_QWORD *)a1 )
  {
    v83 = &unk_26FCAB;
    goto LABEL_183;
  }
  v42 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v42 || (v43 = *(_QWORD *)(v42 + 8)) == 0 )
  {
    v83 = &unk_234896;
LABEL_183:
    printk(v83, "sde_encoder_get_kms");
    disp_op = 0;
    goto LABEL_72;
  }
  disp_op = sde_kms_get_disp_op(v43, v20);
  if ( disp_op >= 3 )
    goto LABEL_190;
LABEL_72:
  v46 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 8LL * disp_op + 5152);
  if ( v46 )
  {
    if ( *((_DWORD *)v46 - 1) != 17023570 )
      __break(0x8228u);
    if ( v46(a1) )
      goto LABEL_191;
  }
  v47 = *(_QWORD *)(a1 + 328);
  if ( v47 )
  {
LABEL_77:
    if ( *(_BYTE *)(a1 + 748) == 1 )
    {
      hrtimer_cancel(v47 + 2544);
      sde_evtlog_log(
        v11[191],
        "sde_encoder_cancel_vrr_timers",
        2258,
        -1,
        *(_DWORD *)(a1 + 24),
        -1059143953,
        v48,
        v49,
        v84);
    }
    goto LABEL_79;
  }
  while ( 1 )
  {
LABEL_79:
    if ( *(_BYTE *)(a1 + 749) == 1 )
    {
      v50 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
      v51 = *(_DWORD *)(a1 + 4916);
      if ( *(_QWORD *)(*(_QWORD *)(v50 + 8) + 2128LL) )
      {
        sde_evtlog_log(v11[191], "sde_encoder_vhm_wakelock", 2277, -1, v51, 0, -1059143953, v45, v84);
      }
      else if ( v51 == 1 )
      {
        sde_power_wakelock_ctrl(v50 + 16, 0);
        *(_DWORD *)(a1 + 4916) = 0;
      }
    }
    if ( (*(_BYTE *)(a1 + 644) & 0x80) == 0 )
      flush_delayed_work(v15 + 4408);
    v54 = *(_DWORD *)(a1 + 696);
    if ( (unsigned int)(v54 - 3) < 0xFFFFFFFE )
      goto LABEL_92;
    if ( (*(_BYTE *)(v19 + 3240) & 0xC0) != 0 )
    {
      drm_crtc_vblank_get(*(_QWORD *)(a1 + 1360));
      v54 = *(_DWORD *)(a1 + 696);
    }
    if ( v54 == 1 && (unsigned int)(v10 - 1) <= 1 )
    {
      sde_encoder_resource_control(a1, 2);
      v73 = *(_DWORD *)(a1 + 196);
      if ( v73 )
      {
        v74 = *(_QWORD *)(a1 + 200);
        if ( v74 )
        {
          v75 = *(void (**)(void))(v74 + 72);
          if ( v75 )
          {
            if ( *((_DWORD *)v75 - 1) != -511414616 )
              __break(0x8229u);
            v75();
            v73 = *(_DWORD *)(a1 + 196);
          }
        }
        if ( v73 >= 2 )
        {
          v76 = *(_QWORD *)(a1 + 208);
          if ( v76 )
          {
            v77 = *(void (**)(void))(v76 + 72);
            if ( v77 )
            {
              if ( *((_DWORD *)v77 - 1) != -511414616 )
                __break(0x8229u);
              v77();
              v73 = *(_DWORD *)(a1 + 196);
            }
          }
          if ( v73 >= 3 )
          {
            v78 = *(_QWORD *)(a1 + 216);
            if ( v78 )
            {
              v79 = *(void (**)(void))(v78 + 72);
              if ( v79 )
              {
                if ( *((_DWORD *)v79 - 1) != -511414616 )
                  __break(0x8229u);
                v79();
                v73 = *(_DWORD *)(a1 + 196);
              }
            }
            if ( v73 >= 4 )
            {
              v80 = *(_QWORD *)(a1 + 224);
              if ( v80 )
              {
                v81 = *(void (**)(void))(v80 + 72);
                if ( v81 )
                {
                  if ( *((_DWORD *)v81 - 1) != -511414616 )
                    __break(0x8229u);
                  v81();
                  v73 = *(_DWORD *)(a1 + 196);
                }
              }
              if ( v73 > 4 )
                goto LABEL_190;
            }
          }
        }
      }
    }
    else
    {
LABEL_92:
      sde_encoder_resource_control(a1, 1);
      v55 = *(_DWORD *)(a1 + 196);
      if ( v55 )
      {
        v56 = *(_QWORD *)(a1 + 200);
        if ( v56 )
        {
          v57 = *(void (**)(void))(v56 + 72);
          if ( v57 )
          {
            if ( *((_DWORD *)v57 - 1) != -511414616 )
              __break(0x8229u);
            v57();
            v55 = *(_DWORD *)(a1 + 196);
          }
        }
        if ( v55 >= 2 )
        {
          v58 = *(_QWORD *)(a1 + 208);
          if ( v58 )
          {
            v59 = *(void (**)(void))(v58 + 72);
            if ( v59 )
            {
              if ( *((_DWORD *)v59 - 1) != -511414616 )
                __break(0x8229u);
              v59();
              v55 = *(_DWORD *)(a1 + 196);
            }
          }
          if ( v55 >= 3 )
          {
            v60 = *(_QWORD *)(a1 + 216);
            if ( v60 )
            {
              v61 = *(void (**)(void))(v60 + 72);
              if ( v61 )
              {
                if ( *((_DWORD *)v61 - 1) != -511414616 )
                  __break(0x8229u);
                v61();
                v55 = *(_DWORD *)(a1 + 196);
              }
            }
            if ( v55 >= 4 )
            {
              v62 = *(_QWORD *)(a1 + 224);
              if ( v62 )
              {
                v63 = *(void (**)(void))(v62 + 72);
                if ( v63 )
                {
                  if ( *((_DWORD *)v63 - 1) != -511414616 )
                    __break(0x8229u);
                  v63();
                  v55 = *(_DWORD *)(a1 + 196);
                }
              }
              if ( v55 > 4 )
                goto LABEL_190;
            }
          }
        }
      }
      sde_encoder_resource_control(a1, 2);
    }
    if ( v8 && *(_BYTE *)(a1 + 1312) == 1 && (*(_BYTE *)(v19 + 3240) & 0xC0) == 0 )
    {
      drm_crtc_vblank_off(v8);
      v82 = v8[40];
      if ( v82 > 0xF )
        goto LABEL_190;
      kthread_flush_worker(v9 + 80LL * v82 + 2432);
      v64 = *(_QWORD *)(v17 + 152);
      if ( !v64 )
      {
LABEL_123:
        sde_encoder_dce_disable(a1);
        goto LABEL_124;
      }
    }
    else
    {
      v64 = *(_QWORD *)(v17 + 152);
      if ( !v64 )
        goto LABEL_123;
    }
    if ( (*(_BYTE *)(v64 + 20120) & 1) == 0 )
      goto LABEL_123;
LABEL_124:
    result = sde_encoder_resource_control(a1, 3);
    v65 = *(_QWORD *)(a1 + 328);
    if ( v65 )
    {
      v66 = *(_QWORD *)(v65 + 8);
      if ( v66 )
      {
        v67 = *(_QWORD *)(a1 + 1360);
        if ( v67 )
        {
          if ( (*(_BYTE *)(*(_QWORD *)(v67 + 2008) + 10LL) & 4) != 0 )
          {
            result = sde_rm_update_topology(v17 + 2144, *(_QWORD *)(v66 + 2512), 0);
            if ( (_DWORD)result )
              return printk(&unk_234FBF, "sde_encoder_virt_disable");
          }
        }
      }
    }
    v68 = *(_DWORD *)(a1 + 196);
    if ( !v68 )
      return sde_encoder_virt_reset(a1);
    v69 = *(_QWORD *)(a1 + 200);
    if ( v69 && (*(_BYTE *)(v69 + 2290) & 1) != 0 )
      return result;
    if ( v68 == 1 )
      return sde_encoder_virt_reset(a1);
    v70 = *(_QWORD *)(a1 + 208);
    if ( v70 )
    {
      if ( (*(_BYTE *)(v70 + 2290) & 1) != 0 )
        return result;
    }
    if ( v68 == 2 )
      return sde_encoder_virt_reset(a1);
    v71 = *(_QWORD *)(a1 + 216);
    if ( v71 )
    {
      if ( (*(_BYTE *)(v71 + 2290) & 1) != 0 )
        return result;
    }
    if ( v68 == 3 )
      return sde_encoder_virt_reset(a1);
    v72 = *(_QWORD *)(a1 + 224);
    if ( v72 )
    {
      if ( (*(_BYTE *)(v72 + 2290) & 1) != 0 )
        return result;
    }
    if ( v68 == 4 )
      return sde_encoder_virt_reset(a1);
LABEL_190:
    __break(0x5512u);
LABEL_191:
    printk(&unk_23F430, "sde_encoder_virt_disable");
    v47 = *(_QWORD *)(a1 + 328);
    if ( v47 )
      goto LABEL_77;
  }
}
