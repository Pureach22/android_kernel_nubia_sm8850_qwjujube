__int64 __fastcall wcd_mbhc_adc_hs_rem_irq(__int64 a1, __int64 a2)
{
  __int64 v3; // x22
  __int64 v4; // x8
  void (__fastcall *v5)(__int64, int *); // x8
  int v6; // w8
  int v7; // w20
  unsigned int v8; // w9
  void (__fastcall *v9)(__int64, __int64, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x22
  int v12; // w23
  void (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x0
  void (__fastcall *v15)(__int64, __int64, __int64); // x8
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 (__fastcall *v18)(_QWORD); // x8
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x1
  int v22; // w23
  __int64 v23; // x8
  __int64 v24; // x1
  __int64 v25; // x1
  char v26; // w0
  int v27; // w22
  __int64 v28; // x8
  __int64 v29; // x1
  __int64 v30; // x1
  __int64 v31; // x1
  __int64 v32; // x1
  __int64 v33; // x1
  int v34; // w8
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x8
  __int64 v38; // x1
  __int64 v39; // x1
  __int64 v40; // x1
  __int64 v41; // x8
  __int64 v42; // x1
  __int64 v43; // x8
  __int64 v44; // x1
  int v46; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_DF5E, "wcd_mbhc_adc_hs_rem_irq");
  mutex_lock(a2 + 744);
  v3 = jiffies;
  v4 = *(_QWORD *)(a2 + 120);
  v46 = 0;
  v5 = *(void (__fastcall **)(__int64, int *))(v4 + 24);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -2034283555 )
      __break(0x8228u);
    v5(a2, &v46);
    v6 = v46;
    v7 = *(_DWORD *)(a2 + 168);
    if ( v7 )
      goto LABEL_10;
  }
  else if ( *(_DWORD *)(*(_QWORD *)(a2 + 856) + 728LL) )
  {
    v6 = 50
       * ((unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a2 + 216)) & *(_BYTE *)(*(_QWORD *)(a2 + 856) + 732LL)) >> *(_BYTE *)(*(_QWORD *)(a2 + 856) + 733LL))
       + 1000;
    v7 = *(_DWORD *)(a2 + 168);
    if ( v7 )
      goto LABEL_10;
  }
  else
  {
    v6 = 12700;
    v7 = *(_DWORD *)(a2 + 168);
    if ( v7 )
    {
LABEL_10:
      v8 = *(_DWORD *)(a2 + 176);
      if ( v8 != v6 )
        v7 = v7 * v6 / v8;
      goto LABEL_12;
    }
  }
  v7 = 1700 * v6 / 1800;
LABEL_12:
  v9 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a2 + 120) + 208LL);
  if ( v9 )
  {
    v10 = *(_QWORD *)(a2 + 216);
    if ( *((_DWORD *)v9 - 1) != -1208669315 )
      __break(0x8228u);
    v9(v10, 2, 2);
  }
  v11 = v3 + 25;
  v12 = 1;
  do
  {
    usleep_range_state(10000, 10100, 2);
    if ( (int)wcd_measure_adc_once(a2, 1) <= v7 && v12 >= 4 )
    {
      v13 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a2 + 120) + 208LL);
      if ( v13 )
      {
        v14 = *(_QWORD *)(a2 + 216);
        if ( *((_DWORD *)v13 - 1) != -1208669315 )
          __break(0x8228u);
        v13(v14, 2, 3);
      }
      goto LABEL_86;
    }
    ++v12;
  }
  while ( v11 - jiffies >= 0 );
  v15 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a2 + 120) + 208LL);
  if ( v15 )
  {
    v16 = *(_QWORD *)(a2 + 216);
    if ( *((_DWORD *)v15 - 1) != -1208669315 )
      __break(0x8228u);
    v15(v16, 2, 3);
  }
  if ( !wcd_swch_level_remove(a2) && (*(_QWORD *)(a2 + 904) & 2) != 0 )
  {
    v17 = *(_QWORD *)(a2 + 112);
    if ( (*(_BYTE *)(v17 + 72) & 1) != 0 || *(_BYTE *)(v17 + 92) == 1 )
    {
      v18 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 120) + 184LL);
      if ( !v18 )
        goto LABEL_39;
      v19 = *(_QWORD *)(a2 + 216);
      if ( *((_DWORD *)v18 - 1) != -67188162 )
        __break(0x8228u);
      if ( (v18(v19) & 1) != 0 )
      {
        v20 = *(_QWORD *)(a2 + 856);
        v21 = *(unsigned int *)(v20 + 456);
        if ( (_DWORD)v21 )
          snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v21, *(unsigned __int8 *)(v20 + 460), 0);
        v22 = 1;
      }
      else
      {
LABEL_39:
        v22 = 0;
      }
      v23 = *(_QWORD *)(a2 + 856);
      v24 = *(unsigned int *)(v23 + 568);
      if ( (_DWORD)v24 )
      {
        snd_soc_component_update_bits(
          *(_QWORD *)(a2 + 216),
          v24,
          *(unsigned __int8 *)(v23 + 572),
          (unsigned int)(1 << *(_BYTE *)(v23 + 573)));
        v23 = *(_QWORD *)(a2 + 856);
      }
      v25 = *(unsigned int *)(v23 + 584);
      if ( (_DWORD)v25 )
        snd_soc_component_update_bits(
          *(_QWORD *)(a2 + 216),
          v25,
          *(unsigned __int8 *)(v23 + 588),
          (unsigned int)(1 << *(_BYTE *)(v23 + 589)));
      usleep_range_state(50000, 50100, 2);
      if ( !*(_DWORD *)(*(_QWORD *)(a2 + 856) + 552LL) )
        goto LABEL_61;
      v26 = snd_soc_component_read(*(_QWORD *)(a2 + 216));
      v17 = *(_QWORD *)(a2 + 112);
      v27 = (unsigned __int8)(v26 & *(_BYTE *)(*(_QWORD *)(a2 + 856) + 556LL)) >> *(_BYTE *)(*(_QWORD *)(a2 + 856)
                                                                                           + 557LL);
      if ( (*(_BYTE *)(v17 + 72) & 1) != 0 )
      {
LABEL_50:
        if ( !v27 )
        {
LABEL_51:
          v28 = *(_QWORD *)(a2 + 856);
          v29 = *(unsigned int *)(v28 + 8);
          if ( (_DWORD)v29 )
          {
            snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v29, *(unsigned __int8 *)(v28 + 12), 0);
            v28 = *(_QWORD *)(a2 + 856);
            v30 = *(unsigned int *)(v28 + 40);
            if ( !(_DWORD)v30 )
            {
LABEL_53:
              v31 = *(unsigned int *)(v28 + 8);
              if ( !(_DWORD)v31 )
                goto LABEL_54;
              goto LABEL_77;
            }
          }
          else
          {
            v30 = *(unsigned int *)(v28 + 40);
            if ( !(_DWORD)v30 )
              goto LABEL_53;
          }
          snd_soc_component_update_bits(
            *(_QWORD *)(a2 + 216),
            v30,
            *(unsigned __int8 *)(v28 + 44),
            (unsigned int)(1 << *(_BYTE *)(v28 + 45)));
          v28 = *(_QWORD *)(a2 + 856);
          v31 = *(unsigned int *)(v28 + 8);
          if ( !(_DWORD)v31 )
          {
LABEL_54:
            v32 = *(unsigned int *)(v28 + 184);
            if ( !(_DWORD)v32 )
              goto LABEL_55;
            goto LABEL_78;
          }
LABEL_77:
          snd_soc_component_update_bits(
            *(_QWORD *)(a2 + 216),
            v31,
            *(unsigned __int8 *)(v28 + 12),
            (unsigned int)(1 << *(_BYTE *)(v28 + 13)));
          v28 = *(_QWORD *)(a2 + 856);
          v32 = *(unsigned int *)(v28 + 184);
          if ( !(_DWORD)v32 )
          {
LABEL_55:
            v33 = *(unsigned int *)(v28 + 360);
            if ( !(_DWORD)v33 )
            {
LABEL_57:
              v34 = *(unsigned __int8 *)(a2 + 161);
              *(_BYTE *)(a2 + 208) = 0;
              *(_BYTE *)(a2 + 160) = 0;
              if ( v34 > 2 )
              {
                if ( v34 == 3 )
                {
                  wcd_mbhc_report_plug(a2, 0, 4);
                  v35 = *(_QWORD *)(a2 + 968);
                  v36 = 23;
                }
                else
                {
                  if ( v34 != 4 )
                    goto LABEL_86;
                  v35 = *(_QWORD *)(a2 + 968);
                  v36 = 62;
                }
              }
              else if ( v34 == 1 )
              {
                wcd_mbhc_report_plug(a2, 0, 3);
                v35 = *(_QWORD *)(a2 + 968);
                v36 = 20;
              }
              else
              {
                if ( v34 != 2 )
                  goto LABEL_86;
                wcd_mbhc_report_plug(a2, 0, 1);
                v35 = *(_QWORD *)(a2 + 968);
                v36 = 21;
              }
              extcon_set_state_sync(v35, v36, 0);
              goto LABEL_86;
            }
LABEL_56:
            snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v33, *(unsigned __int8 *)(v28 + 364), 0);
            goto LABEL_57;
          }
LABEL_78:
          snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v32, *(unsigned __int8 *)(v28 + 188), 0);
          v28 = *(_QWORD *)(a2 + 856);
          v33 = *(unsigned int *)(v28 + 360);
          if ( !(_DWORD)v33 )
            goto LABEL_57;
          goto LABEL_56;
        }
LABEL_61:
        if ( *(_BYTE *)(a2 + 161) == 2 )
          *(_BYTE *)(a2 + 213) = 1;
        v37 = *(_QWORD *)(a2 + 856);
        v38 = *(unsigned int *)(v37 + 760);
        if ( (_DWORD)v38 )
        {
          snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v38, *(unsigned __int8 *)(v37 + 764), 0);
          v37 = *(_QWORD *)(a2 + 856);
          v39 = *(unsigned int *)(v37 + 744);
          if ( !(_DWORD)v39 )
          {
LABEL_65:
            v40 = *(unsigned int *)(v37 + 664);
            if ( !(_DWORD)v40 )
            {
LABEL_67:
              wcd_mbhc_elec_hs_report_unplug((_QWORD *)a2);
              v41 = *(_QWORD *)(a2 + 856);
              v42 = *(unsigned int *)(v41 + 360);
              if ( (_DWORD)v42 )
                snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v42, *(unsigned __int8 *)(v41 + 364), 0);
              if ( v22 )
              {
                v43 = *(_QWORD *)(a2 + 856);
                v44 = *(unsigned int *)(v43 + 456);
                if ( (_DWORD)v44 )
                  snd_soc_component_update_bits(
                    *(_QWORD *)(a2 + 216),
                    v44,
                    *(unsigned __int8 *)(v43 + 460),
                    (unsigned int)(3 << *(_BYTE *)(v43 + 461)));
              }
              goto LABEL_86;
            }
LABEL_66:
            snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v40, *(unsigned __int8 *)(v37 + 668), 0);
            goto LABEL_67;
          }
        }
        else
        {
          v39 = *(unsigned int *)(v37 + 744);
          if ( !(_DWORD)v39 )
            goto LABEL_65;
        }
        snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v39, *(unsigned __int8 *)(v37 + 748), 0);
        v37 = *(_QWORD *)(a2 + 856);
        v40 = *(unsigned int *)(v37 + 664);
        if ( !(_DWORD)v40 )
          goto LABEL_67;
        goto LABEL_66;
      }
    }
    else
    {
      if ( (*(_BYTE *)(v17 + 72) & 1) != 0 )
        goto LABEL_51;
      v22 = 0;
      v27 = 0;
    }
    if ( *(_BYTE *)(v17 + 92) != 1 )
      goto LABEL_61;
    goto LABEL_50;
  }
LABEL_86:
  mutex_unlock(a2 + 744);
  printk(&unk_E5CB, "wcd_mbhc_adc_hs_rem_irq");
  _ReadStatusReg(SP_EL0);
  return 1;
}
