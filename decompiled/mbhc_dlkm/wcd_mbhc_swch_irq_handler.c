__int64 __fastcall wcd_mbhc_swch_irq_handler(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x8
  char v4; // w0
  __int64 v5; // x8
  __int64 v6; // x1
  int v7; // w9
  _BOOL4 v8; // w22
  void (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x8
  void (__fastcall *v11)(__int64, __int64); // x9
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  char v13; // w21
  _BOOL4 v14; // w9
  __int64 v15; // x8
  __int64 v16; // x21
  _DWORD *v17; // x8
  __int64 v18; // x8
  _QWORD *v19; // x9
  __int64 (__fastcall *v20)(_QWORD); // x8
  __int64 v21; // x8
  __int64 v22; // x1
  __int64 v23; // x1
  void (__fastcall *v24)(__int64, __int64); // x8
  __int64 v25; // x8
  __int64 v26; // x1
  __int64 v27; // x1
  __int64 v28; // x8
  __int64 v29; // x1
  char v30; // w8
  _DWORD *v31; // x8
  __int64 v32; // x8
  __int64 v33; // x1
  __int64 v34; // x1
  __int64 v35; // x8
  void (__fastcall *v36)(__int64, __int64); // x9
  _DWORD *v37; // x8
  __int64 v38; // x8
  __int64 v39; // x1
  __int64 v40; // x1
  __int64 v41; // x8
  _DWORD *v42; // x9
  _DWORD *v43; // x8
  int v44; // w2
  int v45; // w20
  unsigned int v46; // w21
  _DWORD *v47; // x8
  __int64 v48; // x8
  __int64 v49; // x1
  __int64 v50; // x8
  __int64 v51; // x1
  __int64 v52; // x1
  __int64 v53; // x0
  _DWORD *v54; // x8
  __int64 v55; // x1
  __int64 v56; // x0
  _DWORD *v57; // x8
  __int64 v58; // x8
  __int64 v59; // x1
  __int64 v60; // x1
  __int64 v61; // x8
  __int64 v62; // x1
  _DWORD *v63; // x8
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x8
  _DWORD *v67; // x9
  _DWORD *v68; // x8
  __int64 v69; // x8
  void (__fastcall *v70)(__int64, __int64); // x8
  _DWORD *v71; // x8
  _DWORD *v72; // x8
  void (__fastcall *v73)(__int64, __int64); // x8
  void (__fastcall *v74)(__int64, __int64, __int64); // x8
  void (__fastcall *v75)(__int64, __int64, __int64); // x8
  __int64 v76; // x8
  __int64 v77; // x1
  __int64 v78; // x8
  void (__fastcall *v79)(_QWORD); // x9
  void (__fastcall *v80)(__int64, __int64); // x8
  __int64 v81; // x8
  void (__fastcall *v82)(_QWORD); // x8
  unsigned __int64 v90; // x10
  unsigned __int64 v93; // x10

  v2 = *(_QWORD *)(a1 + 216);
  mutex_lock(a1 + 744);
  *(_BYTE *)(a1 + 162) = 1;
  if ( (cancel_delayed_work_sync(a1) & 1) != 0 )
  {
    v3 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 144LL);
    if ( *(v3 - 1) != 1996337026 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v3)(a1, 0);
  }
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 856) + 40LL) )
  {
    v4 = snd_soc_component_read(*(_QWORD *)(a1 + 216));
    v5 = *(_QWORD *)(a1 + 856);
    v6 = *(unsigned int *)(v5 + 40);
    v7 = (unsigned __int8)(v4 & *(_BYTE *)(v5 + 44)) >> *(_BYTE *)(v5 + 45);
    v8 = v7 != 0;
    if ( (_DWORD)v6 )
      snd_soc_component_update_bits(
        *(_QWORD *)(a1 + 216),
        v6,
        *(unsigned __int8 *)(v5 + 44),
        (unsigned __int8)(v7 == 0) << *(_BYTE *)(v5 + 45));
  }
  else
  {
    v8 = 1;
  }
  v9 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 920) + 32LL);
  if ( v9 )
  {
    if ( *((_DWORD *)v9 - 1) != -794314397 )
      __break(0x8228u);
    v9(a1, a1 + 800);
  }
  else
  {
    printk(&unk_E3F3, "wcd_mbhc_swch_irq_handler");
  }
  v10 = *(_QWORD *)(a1 + 120);
  v11 = *(void (__fastcall **)(__int64, __int64))(v10 + 216);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != -1918869124 )
      __break(0x8229u);
    v11(v2, 1);
    v10 = *(_QWORD *)(a1 + 120);
  }
  v12 = *(__int64 (__fastcall **)(__int64, __int64))(v10 + 152);
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != -1840370871 )
      __break(0x8228u);
    v13 = v12(a1, 1);
  }
  else
  {
    v13 = 0;
  }
  if ( *(_BYTE *)(a1 + 161) )
    v14 = 0;
  else
    v14 = v8;
  if ( !v14 )
  {
    if ( *(_BYTE *)(a1 + 161) )
      v30 = v8;
    else
      v30 = 1;
    if ( (v30 & 1) != 0 )
    {
      if ( !v8 )
      {
        v31 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 40LL);
        if ( v31 )
        {
          if ( *(v31 - 1) != 312120118 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v31)(a1, 0);
        }
        v32 = *(_QWORD *)(a1 + 856);
        v33 = *(unsigned int *)(v32 + 184);
        if ( (_DWORD)v33 )
        {
          snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v33, *(unsigned __int8 *)(v32 + 188), 0);
          v32 = *(_QWORD *)(a1 + 856);
        }
        v34 = *(unsigned int *)(v32 + 360);
        if ( (_DWORD)v34 )
          snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v34, *(unsigned __int8 *)(v32 + 364), 0);
        *(_BYTE *)(a1 + 213) = 0;
      }
      goto LABEL_179;
    }
    v35 = *(_QWORD *)(a1 + 120);
    v36 = *(void (__fastcall **)(__int64, __int64))(v35 + 352);
    if ( v36 )
    {
      if ( *((_DWORD *)v36 - 1) != 1555053736 )
        __break(0x8229u);
      v36(v2, 2);
      v35 = *(_QWORD *)(a1 + 120);
    }
    v37 = *(_DWORD **)(v35 + 40);
    if ( v37 )
    {
      if ( *(v37 - 1) != 312120118 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v37)(a1, 0);
    }
    v38 = *(_QWORD *)(a1 + 856);
    v39 = *(unsigned int *)(v38 + 184);
    if ( (_DWORD)v39 )
    {
      snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v39, *(unsigned __int8 *)(v38 + 188), 0);
      v38 = *(_QWORD *)(a1 + 856);
    }
    v40 = *(unsigned int *)(v38 + 360);
    if ( (_DWORD)v40 )
      snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v40, *(unsigned __int8 *)(v38 + 364), 0);
    v41 = *(_QWORD *)(a1 + 120);
    v42 = *(_DWORD **)(v41 + 168);
    if ( v42 )
    {
      if ( *(v42 - 1) != 542830841 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v42)(v2, 2, 0);
      v41 = *(_QWORD *)(a1 + 120);
    }
    v43 = *(_DWORD **)(v41 + 88);
    if ( v43 )
    {
      if ( *(v43 - 1) != -888789118 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))v43)(v2, v13 & 1, 0);
    }
    v44 = *(unsigned __int8 *)(a1 + 161);
    *(_BYTE *)(a1 + 208) = 0;
    *(_BYTE *)(a1 + 160) = 0;
    if ( v44 > 2 )
    {
      if ( v44 == 3 )
      {
        if ( *(_DWORD *)(a1 + 900) == 1 )
        {
          v50 = *(_QWORD *)(a1 + 856);
          v51 = *(unsigned int *)(v50 + 776);
          if ( (_DWORD)v51 )
            snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v51, *(unsigned __int8 *)(v50 + 780), 0);
        }
        v45 = 4;
        v46 = 23;
        *(_BYTE *)(a1 + 210) = 0;
        goto LABEL_106;
      }
      if ( v44 == 4 )
        goto LABEL_94;
    }
    else
    {
      if ( v44 == 1 )
      {
        v47 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 176LL);
        if ( v47 )
        {
          if ( *(v47 - 1) != 542830841 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v47)(v2, 1, 0);
        }
        v48 = *(_QWORD *)(a1 + 856);
        v49 = *(unsigned int *)(v48 + 488);
        if ( (_DWORD)v49 )
          snd_soc_component_update_bits(
            *(_QWORD *)(a1 + 216),
            v49,
            *(unsigned __int8 *)(v48 + 492),
            (unsigned int)(1 << *(_BYTE *)(v48 + 493)));
        v45 = 3;
        v46 = 20;
        goto LABEL_106;
      }
      if ( v44 == 2 )
      {
        v45 = 1;
        v46 = 21;
        goto LABEL_106;
      }
    }
    printk(&unk_E1FE, "wcd_mbhc_swch_irq_handler");
LABEL_94:
    v45 = 1;
    v46 = 62;
LABEL_106:
    if ( (mutex_is_locked(a1 + 744) & 1) == 0 && (wcd_mbhc_hs_elec_irq___already_done & 1) == 0 )
    {
      wcd_mbhc_hs_elec_irq___already_done = 1;
      _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_hs_elec_irq");
      __break(0x800u);
    }
    v52 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 16LL);
    if ( (*(_QWORD *)(a1 + 904) & 2) != 0 )
    {
      v53 = *(_QWORD *)(a1 + 216);
      v54 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 112LL);
      if ( *(v54 - 1) != 542830841 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v54)(v53, v52, 0);
      _X8 = (unsigned __int64 *)(a1 + 904);
      __asm { PRFM            #0x11, [X8] }
      do
        v90 = __ldxr(_X8);
      while ( __stxr(v90 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    }
    if ( (mutex_is_locked(a1 + 744) & 1) == 0 && (wcd_mbhc_hs_elec_irq___already_done & 1) == 0 )
    {
      wcd_mbhc_hs_elec_irq___already_done = 1;
      _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_hs_elec_irq");
      __break(0x800u);
    }
    v55 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 12LL);
    if ( (*(_QWORD *)(a1 + 904) & 1) != 0 )
    {
      v56 = *(_QWORD *)(a1 + 216);
      v57 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 112LL);
      if ( *(v57 - 1) != 542830841 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v57)(v56, v55, 0);
      _X8 = (unsigned __int64 *)(a1 + 904);
      __asm { PRFM            #0x11, [X8] }
      do
        v93 = __ldxr(_X8);
      while ( __stxr(v93 & 0xFFFFFFFFFFFFFFFELL, _X8) );
    }
    v58 = *(_QWORD *)(a1 + 856);
    v59 = *(unsigned int *)(v58 + 72);
    if ( (_DWORD)v59 )
    {
      snd_soc_component_update_bits(
        *(_QWORD *)(a1 + 216),
        v59,
        *(unsigned __int8 *)(v58 + 76),
        (unsigned int)(1 << *(_BYTE *)(v58 + 77)));
      v58 = *(_QWORD *)(a1 + 856);
    }
    v60 = *(unsigned int *)(v58 + 168);
    if ( (_DWORD)v60 )
      snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v60, *(unsigned __int8 *)(v58 + 172), 0);
    *(_BYTE *)(a1 + 213) = 0;
    wcd_mbhc_report_plug(a1, 0, v45);
    extcon_set_state_sync(*(_QWORD *)(a1 + 968), v46, 0);
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 112) + 88LL) )
    {
      v61 = *(_QWORD *)(a1 + 856);
      v62 = *(unsigned int *)(v61 + 8);
      if ( (_DWORD)v62 )
        snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v62, *(unsigned __int8 *)(v61 + 12), 0);
      v63 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 128LL);
      if ( v63 )
      {
        v64 = *(_QWORD *)(a1 + 216);
        if ( *(v63 - 1) != -1918869124 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v63)(v64, 0);
      }
    }
    v65 = *(_QWORD *)(a1 + 112);
    if ( (*(_BYTE *)(v65 + 72) & 1) != 0 || *(_BYTE *)(v65 + 92) == 1 )
    {
      v66 = *(_QWORD *)(a1 + 120);
      v67 = *(_DWORD **)(v66 + 312);
      if ( v67 )
      {
        if ( *(v67 - 1) != 496203713 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v67)(a1, 0);
        v66 = *(_QWORD *)(a1 + 120);
      }
      v68 = *(_DWORD **)(v66 + 320);
      if ( v68 )
      {
        if ( *(v68 - 1) != 496203713 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v68)(a1, 0);
      }
    }
    if ( of_find_property(
           *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 32LL) + 72LL) + 744LL),
           "qcom,usbss-hsj-connect-enabled",
           0) )
    {
      wcd_usbss_switch_update(5, 0);
    }
    v69 = *(_QWORD *)(a1 + 120);
    if ( v69 )
    {
      v70 = *(void (__fastcall **)(__int64, __int64))(v69 + 336);
      if ( v70 )
      {
        if ( *((_DWORD *)v70 - 1) != 496203713 )
          __break(0x8228u);
        v70(a1, 1);
      }
    }
    goto LABEL_179;
  }
  v15 = *(_QWORD *)(a1 + 120);
  v16 = *(_QWORD *)(a1 + 216);
  if ( v15 )
  {
    v17 = *(_DWORD **)(v15 + 336);
    if ( v17 )
    {
      if ( *(v17 - 1) != 496203713 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v17)(a1, 0);
    }
  }
  if ( of_find_property(
         *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v16 + 32) + 72LL) + 744LL),
         "qcom,usbss-hsj-connect-enabled",
         0) )
  {
    wcd_usbss_switch_update(5, 1);
  }
  v18 = *(_QWORD *)(a1 + 112);
  if ( (*(_BYTE *)(v18 + 72) & 1) != 0 || *(_BYTE *)(v18 + 92) == 1 )
  {
    v19 = *(_QWORD **)(a1 + 120);
    v20 = (__int64 (__fastcall *)(_QWORD))v19[38];
    if ( v20 )
    {
      if ( v19[39] && v19[40] )
      {
        if ( *((_DWORD *)v20 - 1) != -9629763 )
          __break(0x8228u);
        if ( (v20(a1) & 1) != 0 )
        {
          v21 = *(_QWORD *)(a1 + 856);
          v22 = *(unsigned int *)(v21 + 8);
          if ( (_DWORD)v22 )
          {
            snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v22, *(unsigned __int8 *)(v21 + 12), 0);
            v21 = *(_QWORD *)(a1 + 856);
          }
          v23 = *(unsigned int *)(v21 + 24);
          if ( (_DWORD)v23 )
            snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v23, *(unsigned __int8 *)(v21 + 28), 0);
          v24 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 120) + 312LL);
          if ( *((_DWORD *)v24 - 1) != 496203713 )
            __break(0x8228u);
          v24(a1, 1);
          v25 = *(_QWORD *)(a1 + 856);
          v26 = *(unsigned int *)(v25 + 40);
          if ( (_DWORD)v26 )
          {
            snd_soc_component_update_bits(
              *(_QWORD *)(a1 + 216),
              v26,
              *(unsigned __int8 *)(v25 + 44),
              (unsigned int)(1 << *(_BYTE *)(v25 + 45)));
            v25 = *(_QWORD *)(a1 + 856);
          }
          v27 = *(unsigned int *)(v25 + 8);
          if ( (_DWORD)v27 )
            snd_soc_component_update_bits(
              *(_QWORD *)(a1 + 216),
              v27,
              *(unsigned __int8 *)(v25 + 12),
              (unsigned int)(1 << *(_BYTE *)(v25 + 13)));
          if ( *(_BYTE *)(*(_QWORD *)(a1 + 112) + 33LL) == 1 )
          {
            v28 = *(_QWORD *)(a1 + 856);
            v29 = *(unsigned int *)(v28 + 24);
            if ( (_DWORD)v29 )
              snd_soc_component_update_bits(
                *(_QWORD *)(a1 + 216),
                v29,
                *(unsigned __int8 *)(v28 + 28),
                (unsigned int)(1 << *(_BYTE *)(v28 + 29)));
          }
          goto LABEL_179;
        }
        v71 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 312LL);
        if ( *(v71 - 1) != 496203713 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v71)(a1, 0);
        v72 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 320LL);
        if ( *(v72 - 1) != 496203713 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v72)(a1, 0);
      }
    }
  }
  v73 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 120) + 160LL);
  if ( *((_DWORD *)v73 - 1) != -1918869124 )
    __break(0x8228u);
  v73(v2, 1);
  v74 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 168LL);
  if ( v74 )
  {
    if ( *((_DWORD *)v74 - 1) != 542830841 )
      __break(0x8228u);
    v74(v2, 2, 1);
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 112) + 32LL) & 1) == 0 )
  {
    v75 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 176LL);
    if ( v75 )
    {
      if ( *((_DWORD *)v75 - 1) != 542830841 )
        __break(0x8228u);
      v75(v2, 1, 1);
    }
  }
  v76 = *(_QWORD *)(a1 + 856);
  v77 = *(unsigned int *)(v76 + 488);
  if ( (_DWORD)v77 )
    snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v77, *(unsigned __int8 *)(v76 + 492), 0);
  v78 = *(_QWORD *)(a1 + 120);
  v79 = *(void (__fastcall **)(_QWORD))(v78 + 48);
  if ( v79 )
  {
    if ( *((_DWORD *)v79 - 1) != 933030000 )
      __break(0x8229u);
    v79(v2);
    v78 = *(_QWORD *)(a1 + 120);
  }
  v80 = *(void (__fastcall **)(__int64, __int64))(v78 + 40);
  if ( v80 )
  {
    if ( *((_DWORD *)v80 - 1) != 312120118 )
      __break(0x8228u);
    v80(a1, 1);
  }
  v81 = *(_QWORD *)(a1 + 920);
  *(_BYTE *)(a1 + 208) = 0;
  *(_BYTE *)(a1 + 160) = 0;
  if ( v81 )
  {
    v82 = *(void (__fastcall **)(_QWORD))(v81 + 16);
    if ( *((_DWORD *)v82 - 1) != -144065355 )
      __break(0x8228u);
    v82(a1);
  }
LABEL_179:
  *(_BYTE *)(a1 + 162) = 0;
  return mutex_unlock(a1 + 744);
}
