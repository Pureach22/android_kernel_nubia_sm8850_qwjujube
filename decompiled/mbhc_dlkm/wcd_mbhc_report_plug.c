__int64 __fastcall wcd_mbhc_report_plug(__int64 a1, int a2, int a3)
{
  __int64 v4; // x20
  _DWORD *v7; // x8
  unsigned int v8; // w21
  _QWORD *v9; // x8
  void (__fastcall *v10)(__int64, __int64, __int64); // x9
  _DWORD *v11; // x9
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x8
  __int64 v14; // x1
  unsigned int v15; // w20
  __int64 result; // x0
  int v17; // w8
  _QWORD *v18; // x8
  void (__fastcall *v19)(__int64, __int64, __int64); // x9
  _DWORD *v20; // x9
  void (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x8
  __int64 v23; // x1
  char v24; // w8
  __int64 v25; // x1
  __int64 v26; // x1
  __int64 v27; // x0
  void (__fastcall *v28)(__int64, __int64, __int64); // x8
  char v29; // w8
  __int64 (__fastcall *v30)(_QWORD); // x8
  char v31; // w22
  __int64 v32; // x8
  int v33; // w24
  __int64 v34; // x1
  __int64 v35; // x1
  char v36; // w0
  __int64 v37; // x1
  void (__fastcall *v38)(__int64, __int64, __int64); // x8
  __int64 v39; // x8
  __int64 v40; // x1
  unsigned int v41; // w8
  int v42; // w8
  unsigned int v43; // w21
  int v44; // w8
  int v45; // w22
  _DWORD *v46; // x8
  unsigned int v47; // w20
  unsigned int v48; // w20
  __int64 v49; // x8
  __int64 v50; // x1
  unsigned __int64 v53; // x21
  unsigned __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x1
  _DWORD *v59; // x8
  __int64 v60; // x0
  __int64 (__fastcall *v61)(__int64, __int64, __int64); // x8
  __int64 v62; // x0
  unsigned __int64 v65; // x8
  unsigned __int64 v68; // x8
  unsigned __int64 v75; // x9

  v4 = *(_QWORD *)(a1 + 216);
  if ( (mutex_is_locked(a1 + 744) & 1) != 0 || (wcd_mbhc_report_plug___already_done & 1) != 0 )
  {
    if ( !a2 )
      goto LABEL_4;
  }
  else
  {
    wcd_mbhc_report_plug___already_done = 1;
    _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_report_plug");
    __break(0x800u);
    if ( !a2 )
    {
LABEL_4:
      *(_DWORD *)(a1 + 128) &= ~a3;
      if ( (cancel_delayed_work_sync(a1) & 1) != 0 )
      {
        v7 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 144LL);
        if ( *(v7 - 1) != 1996337026 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v7)(a1, 0);
      }
      else
      {
        v8 = *(_DWORD *)(a1 + 104);
        if ( v8 )
        {
          printk(&unk_E38D, "wcd_mbhc_jack_report");
          snd_soc_jack_report(a1 + 568, 0, v8);
          *(_DWORD *)(a1 + 104) &= 0xFFFF81FF;
        }
      }
      if ( *(_BYTE *)(a1 + 207) != 1 )
        goto LABEL_26;
      v9 = *(_QWORD **)(a1 + 120);
      v10 = (void (__fastcall *)(__int64, __int64, __int64))v9[26];
      if ( v10 )
      {
        if ( *((_DWORD *)v10 - 1) != -1208669315 )
          __break(0x8229u);
        v10(v4, 2, 3);
        v9 = *(_QWORD **)(a1 + 120);
        v11 = (_DWORD *)v9[30];
        if ( !v11 )
        {
LABEL_13:
          v12 = (void (__fastcall *)(_QWORD))v9[8];
          if ( !v12 )
          {
LABEL_25:
            *(_BYTE *)(a1 + 207) = 0;
LABEL_26:
            v15 = *(_DWORD *)(a1 + 128);
            *(_DWORD *)(a1 + 388) = 0;
            *(_QWORD *)(a1 + 376) = 0;
            printk(&unk_DEBE, "wcd_mbhc_jack_report");
            snd_soc_jack_report(a1 + 392, v15, 15);
            result = wcd_mbhc_set_and_turnoff_hph_padac(a1);
            *(_BYTE *)(a1 + 161) = 0;
            *(_BYTE *)(a1 + 928) = 0;
            return result;
          }
LABEL_21:
          if ( *((_DWORD *)v12 - 1) != 933030000 )
            __break(0x8228u);
          v12(v4);
          v13 = *(_QWORD *)(a1 + 856);
          v14 = *(unsigned int *)(v13 + 392);
          if ( (_DWORD)v14 )
            snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v14, *(unsigned __int8 *)(v13 + 396), 0);
          goto LABEL_25;
        }
      }
      else
      {
        v11 = (_DWORD *)v9[30];
        if ( !v11 )
          goto LABEL_13;
      }
      if ( *(v11 - 1) != -1065592060 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v11)(v4, 2, 0);
      v12 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 120) + 64LL);
      if ( !v12 )
        goto LABEL_25;
      goto LABEL_21;
    }
  }
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 112) + 16LL) == 1 && (a3 == 4 || *(_BYTE *)(a1 + 161) == 3) )
  {
    v17 = *(_DWORD *)(a1 + 128);
    if ( v17 )
    {
      if ( v17 != a3 )
      {
        if ( v17 != 3 || (*(_BYTE *)(a1 + 207) & 1) == 0 )
          goto LABEL_50;
        v18 = *(_QWORD **)(a1 + 120);
        v19 = (void (__fastcall *)(__int64, __int64, __int64))v18[26];
        if ( v19 )
        {
          if ( *((_DWORD *)v19 - 1) != -1208669315 )
            __break(0x8229u);
          v19(v4, 2, 3);
          v18 = *(_QWORD **)(a1 + 120);
          v20 = (_DWORD *)v18[30];
          if ( !v20 )
          {
LABEL_37:
            v21 = (void (__fastcall *)(_QWORD))v18[8];
            if ( !v21 )
            {
LABEL_49:
              *(_BYTE *)(a1 + 207) = 0;
LABEL_50:
              v24 = *(_BYTE *)(a1 + 928);
              *(_DWORD *)(a1 + 388) = 0;
              *(_QWORD *)(a1 + 376) = 0;
              if ( (v24 & 1) == 0 )
              {
                printk(&unk_DEBE, "wcd_mbhc_jack_report");
                snd_soc_jack_report(a1 + 392, 0, 15);
                v25 = 0;
                if ( (unsigned __int8)(*(_BYTE *)(a1 + 161) - 1) <= 3u )
                  v25 = dword_E7D0[(unsigned __int8)(*(_BYTE *)(a1 + 161) - 1)];
                extcon_set_state_sync(*(_QWORD *)(a1 + 968), v25, 0);
              }
              if ( *(_DWORD *)(a1 + 128) == 4 )
              {
                wcd_enable_curr_micbias((_QWORD *)a1, 1);
                usleep_range_state(200, 210, 2);
                if ( (mutex_is_locked(a1 + 744) & 1) == 0 && (wcd_mbhc_hs_elec_irq___already_done & 1) == 0 )
                {
                  wcd_mbhc_hs_elec_irq___already_done = 1;
                  _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_hs_elec_irq");
                  __break(0x800u);
                }
                v26 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 16LL);
                if ( (*(_QWORD *)(a1 + 904) & 2) == 0 )
                {
                  v27 = *(_QWORD *)(a1 + 216);
                  v28 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 112LL);
                  if ( *((_DWORD *)v28 - 1) != 542830841 )
                    __break(0x8228u);
                  v28(v27, v26, 1);
                  _X8 = (unsigned __int64 *)(a1 + 904);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v75 = __ldxr(_X8);
                  while ( __stxr(v75 | 2, _X8) );
                }
              }
              *(_DWORD *)(a1 + 128) &= 0xFFFFFFF8;
              goto LABEL_63;
            }
LABEL_45:
            if ( *((_DWORD *)v21 - 1) != 933030000 )
              __break(0x8228u);
            v21(v4);
            v22 = *(_QWORD *)(a1 + 856);
            v23 = *(unsigned int *)(v22 + 392);
            if ( (_DWORD)v23 )
              snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v23, *(unsigned __int8 *)(v22 + 396), 0);
            goto LABEL_49;
          }
        }
        else
        {
          v20 = (_DWORD *)v18[30];
          if ( !v20 )
            goto LABEL_37;
        }
        if ( *(v20 - 1) != -1065592060 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v20)(v4, 2, 0);
        v21 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 120) + 64LL);
        if ( !v21 )
          goto LABEL_49;
        goto LABEL_45;
      }
    }
  }
LABEL_63:
  if ( a3 == 1 && *(_BYTE *)(a1 + 161) == 1 )
  {
    *(_DWORD *)(a1 + 128) &= 0xFFFFFFFC;
    v29 = 2;
LABEL_72:
    *(_BYTE *)(a1 + 161) = v29;
    goto LABEL_73;
  }
  switch ( a3 )
  {
    case 1:
      v29 = 2;
      goto LABEL_72;
    case 4:
      v29 = 3;
      goto LABEL_72;
    case 3:
      *(_BYTE *)(a1 + 161) = 1;
      *(_QWORD *)(a1 + 368) = jiffies;
      break;
  }
LABEL_73:
  v30 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 120) + 184LL);
  if ( v30 )
  {
    if ( *((_DWORD *)v30 - 1) != -67188162 )
      __break(0x8228u);
    v31 = v30(v4);
  }
  else
  {
    v31 = 0;
  }
  if ( *(_BYTE *)(a1 + 384) == 1
    && *(_QWORD *)(*(_QWORD *)(a1 + 120) + 56LL)
    && !((*(_DWORD *)(*(_QWORD *)(a1 + 112) + 68LL) == 0) | v31 & 1) )
  {
    v32 = *(_QWORD *)(a1 + 856);
    if ( !*(_DWORD *)(v32 + 184) )
    {
      v33 = 234;
      v34 = *(unsigned int *)(v32 + 536);
      if ( (_DWORD)v34 )
        goto LABEL_83;
LABEL_87:
      v35 = *(unsigned int *)(v32 + 184);
      if ( !(_DWORD)v35 )
      {
LABEL_89:
        v38 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 56LL);
        if ( *((_DWORD *)v38 - 1) != -2124248113 )
          __break(0x8228u);
        v38(a1, a1 + 376, a1 + 380);
        v39 = *(_QWORD *)(a1 + 856);
        v40 = *(unsigned int *)(v39 + 184);
        if ( (_DWORD)v40 )
          snd_soc_component_update_bits(
            *(_QWORD *)(a1 + 216),
            v40,
            *(unsigned __int8 *)(v39 + 188),
            (unsigned int)(v33 << *(_BYTE *)(v39 + 189)));
        v41 = *(_DWORD *)(*(_QWORD *)(a1 + 112) + 68LL);
        if ( *(_DWORD *)(a1 + 376) > v41 && a3 == 1 && *(_DWORD *)(a1 + 380) > v41 )
        {
          v42 = *(_DWORD *)(a1 + 128);
          *(_BYTE *)(a1 + 928) = 1;
          *(_BYTE *)(a1 + 161) = 3;
          if ( v42 )
          {
            v43 = v42 & 0xFFFFFFF8;
            *(_DWORD *)(a1 + 128) = v42 & 0xFFFFFFF8;
            printk(&unk_DEBE, "wcd_mbhc_jack_report");
            snd_soc_jack_report(a1 + 392, v43, 15);
          }
          a3 = 4;
        }
        goto LABEL_99;
      }
LABEL_88:
      snd_soc_component_update_bits(
        *(_QWORD *)(a1 + 216),
        v35,
        *(unsigned __int8 *)(v32 + 188),
        (unsigned int)(1 << *(_BYTE *)(v32 + 189)));
      goto LABEL_89;
    }
    v36 = snd_soc_component_read(*(_QWORD *)(a1 + 216));
    v32 = *(_QWORD *)(a1 + 856);
    v37 = *(unsigned int *)(v32 + 184);
    v33 = (unsigned __int8)(v36 & *(_BYTE *)(v32 + 188)) >> *(_BYTE *)(v32 + 189);
    if ( (_DWORD)v37 )
    {
      snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v37, *(unsigned __int8 *)(v32 + 188), 0);
      v32 = *(_QWORD *)(a1 + 856);
      v34 = *(unsigned int *)(v32 + 536);
      if ( !(_DWORD)v34 )
        goto LABEL_87;
    }
    else
    {
      v34 = *(unsigned int *)(v32 + 536);
      if ( !(_DWORD)v34 )
        goto LABEL_87;
    }
LABEL_83:
    snd_soc_component_update_bits(*(_QWORD *)(a1 + 216), v34, *(unsigned __int8 *)(v32 + 540), 0);
    v32 = *(_QWORD *)(a1 + 856);
    v35 = *(unsigned int *)(v32 + 184);
    if ( !(_DWORD)v35 )
      goto LABEL_89;
    goto LABEL_88;
  }
LABEL_99:
  if ( (v31 & 1) != 0 && *(_BYTE *)(a1 + 928) == 1 )
  {
    v44 = *(_DWORD *)(a1 + 128);
    *(_BYTE *)(a1 + 161) = 3;
    if ( v44 )
    {
      v47 = v44 & 0xFFFFFFF8;
      *(_DWORD *)(a1 + 128) = v44 & 0xFFFFFFF8;
      printk(&unk_DEBE, "wcd_mbhc_jack_report");
      snd_soc_jack_report(a1 + 392, v47, 15);
      v45 = *(_DWORD *)(a1 + 128) | 4;
    }
    else
    {
      v45 = 4;
    }
    *(_DWORD *)(a1 + 128) = v45;
  }
  else
  {
    v45 = *(_DWORD *)(a1 + 128) | a3;
    *(_DWORD *)(a1 + 128) = v45;
    if ( a3 == 1 )
    {
      v46 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 216LL);
      if ( v46 )
      {
        if ( *(v46 - 1) != -1918869124 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v46)(v4, 0);
        v45 = *(_DWORD *)(a1 + 128);
      }
    }
  }
  printk(&unk_DEBE, "wcd_mbhc_jack_report");
  snd_soc_jack_report(a1 + 392, v45 | 8u, 15);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 856) + 408LL) )
    v48 = 1000
        * (unsigned __int8)(((unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a1 + 216))
                                             & *(_BYTE *)(*(_QWORD *)(a1 + 856) + 412LL)) >> *(_BYTE *)(*(_QWORD *)(a1 + 856) + 413LL))
                          + 1);
  else
    v48 = 235000;
  mutex_lock(&hphr_pa_lock);
  _X8 = (unsigned __int64 *)(a1 + 344);
  __asm { PRFM            #0x11, [X8] }
  do
    v53 = __ldxr(_X8);
  while ( __stlxr(v53 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  __dmb(0xBu);
  if ( (v53 & 2) != 0 )
  {
    v49 = *(_QWORD *)(a1 + 856);
    v50 = *(unsigned int *)(v49 + 424);
    if ( (_DWORD)v50 )
      snd_soc_component_update_bits(
        *(_QWORD *)(a1 + 216),
        v50,
        *(unsigned __int8 *)(v49 + 428),
        (unsigned int)(1 << *(_BYTE *)(v49 + 429)));
  }
  mutex_unlock(&hphr_pa_lock);
  mutex_lock(&hphl_pa_lock);
  _X9 = (unsigned __int64 *)(a1 + 344);
  __asm { PRFM            #0x11, [X9] }
  do
    v56 = __ldxr(_X9);
  while ( __stlxr(v56 & 0xFFFFFFFFFFFFFFFELL, _X9) );
  __dmb(0xBu);
  if ( (v56 & 1) != 0 )
  {
    v57 = *(_QWORD *)(a1 + 856);
    v58 = *(unsigned int *)(v57 + 440);
    if ( (_DWORD)v58 )
      snd_soc_component_update_bits(
        *(_QWORD *)(a1 + 216),
        v58,
        *(unsigned __int8 *)(v57 + 444),
        (unsigned int)(1 << *(_BYTE *)(v57 + 445)));
    mutex_unlock(&hphl_pa_lock);
    goto LABEL_129;
  }
  result = mutex_unlock(&hphl_pa_lock);
  if ( (v53 & 2) != 0 )
LABEL_129:
    result = usleep_range_state(v48, v48 + 50, 2);
  _X9 = (unsigned __int64 *)(a1 + 352);
  __asm { PRFM            #0x11, [X9] }
  do
    v65 = __ldxr(_X9);
  while ( __stlxr(v65 & 0xFFFFFFFFFFFFFFFELL, _X9) );
  __dmb(0xBu);
  if ( (v65 & 1) != 0 )
  {
    result = usleep_range_state(20000, 20100, 2);
    v59 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 280LL);
    if ( v59 )
    {
      v60 = *(_QWORD *)(a1 + 216);
      if ( *(v59 - 1) != -643174803 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v59)(v60, 1, 0);
    }
  }
  _X9 = (unsigned __int64 *)(a1 + 352);
  __asm { PRFM            #0x11, [X9] }
  do
    v68 = __ldxr(_X9);
  while ( __stlxr(v68 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
  __dmb(0xBu);
  if ( (v68 & 2) != 0 )
  {
    result = usleep_range_state(20000, 20100, 2);
    v61 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 280LL);
    if ( v61 )
    {
      v62 = *(_QWORD *)(a1 + 216);
      if ( *((_DWORD *)v61 - 1) != -643174803 )
        __break(0x8228u);
      return v61(v62, 1, 1);
    }
  }
  return result;
}
