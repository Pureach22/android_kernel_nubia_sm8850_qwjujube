__int64 __fastcall wcd9378_tx_sequencer_enable(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x23
  __int64 v4; // x1
  __int64 v6; // x19
  __int64 v7; // x24
  __int64 v8; // x1
  __int64 v9; // x9
  char v10; // w8
  __int64 v11; // x10
  __int64 v12; // x9
  char v14; // w10
  char v15; // w8
  char v16; // w25
  __int64 result; // x0
  int v18; // w8
  unsigned int v19; // w22
  unsigned int v20; // w21
  int v21; // w8
  int v22; // w0
  __int64 v23; // x8
  __int64 v24; // x9
  unsigned int v25; // w21
  int v26; // w2
  unsigned int v27; // w22
  unsigned int v28; // w8
  __int64 v29; // x9
  __int64 v30; // x8
  int v31; // w8
  unsigned int v32; // w22
  __int64 v33; // x0
  __int64 v34; // x1
  __int64 v35; // x2
  __int64 v36; // x3
  int v37; // w8
  unsigned int v38; // w19
  __int64 v39; // x1
  unsigned __int64 v42; // x10
  unsigned __int64 v45; // x10
  unsigned __int64 v51; // x10
  unsigned __int64 v54; // x9

  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int8 *)(a1 + 76);
  v6 = v3 - 208;
  v7 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 == 8 )
  {
    if ( (unsigned int)(v4 - 30) >= 3 )
    {
      v16 = 0;
    }
    else
    {
      v9 = (unsigned __int8)(v4 - 30);
      v10 = 2 * (v4 - 30);
      v11 = (__int64)*(&off_1E6C8 + v9);
      v12 = (__int64)*(&off_1E6E0 + v9);
      _ZF = (*(_QWORD *)(v7 + 16) & v11) == 0;
      v14 = 7 - v10;
      v15 = (6 - v10) & 0xFE;
      if ( _ZF )
        v14 = 0;
      if ( (*(_QWORD *)(v7 + 16) & v12) != 0 )
        v16 = v15;
      else
        v16 = v14;
    }
    wcd9378_tx_connect_port(v3 - 208, v4, 0, 0);
    v18 = *(unsigned __int8 *)(a1 + 76);
    if ( v18 == 31 )
    {
      if ( (*(_QWORD *)(v7 + 456) & 0x40) != 0 )
      {
        wcd9378_tx_connect_port(v3 - 208, 29, 0, 0);
        _X8 = (unsigned __int64 *)(v7 + 456);
        __asm { PRFM            #0x11, [X8] }
        do
          v51 = __ldxr(_X8);
        while ( __stxr(v51 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
      }
      v18 = *(unsigned __int8 *)(a1 + 76);
    }
    v19 = 1090519304;
    v20 = 1075314703;
    if ( v18 != 30 )
    {
      if ( v18 == 32 )
      {
        v20 = 1075314705;
        v19 = 1098907912;
      }
      else
      {
        if ( v18 != 31 )
          goto LABEL_31;
        if ( (*(_QWORD *)(v7 + 16) & 0x20) != 0 )
        {
          snd_soc_component_update_bits(v3 - 208, 1086326688, 255, 0);
          snd_soc_component_update_bits(v3 - 208, 1086326792, 255, 3);
        }
        if ( (*(_QWORD *)(v7 + 16) & 0x10) == 0 )
        {
LABEL_31:
          usleep_range_state(800, 810, 2);
          v21 = *(unsigned __int8 *)(a1 + 76);
          if ( v21 == 32 )
          {
            if ( (unsigned int)wcd9378_pde_act_ps_check(v3 - 208, 1098907912, 3) )
              dev_err(*(_QWORD *)(v3 - 184), "%s: TX2 sequencer tear down failed\n", "wcd9378_tx_sequencer_enable");
            goto LABEL_49;
          }
          if ( v21 != 31 )
          {
            if ( v21 == 30 && (unsigned int)wcd9378_pde_act_ps_check(v3 - 208, 1090519304, 3) )
              dev_err(*(_QWORD *)(v3 - 184), "%s: TX0 sequencer tear down failed\n", "wcd9378_tx_sequencer_enable");
LABEL_49:
            v6 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
            mutex_lock(v6 + 232);
            v23 = 1LL << v16;
            goto LABEL_100;
          }
          if ( (*(_QWORD *)(v7 + 16) & 0x20) != 0 )
          {
            v22 = wcd9378_pde_act_ps_check(v3 - 208, 1086326792, 3);
            if ( (*(_QWORD *)(v7 + 16) & 0x10) == 0 )
              goto LABEL_48;
          }
          else
          {
            v22 = 0;
            if ( (*(_QWORD *)(v7 + 16) & 0x10) == 0 )
            {
LABEL_48:
              if ( v22 )
                dev_err(*(_QWORD *)(v3 - 184), "%s: TX1 sequencer tear down failed\n", "wcd9378_tx_sequencer_enable");
              goto LABEL_49;
            }
          }
          v22 = wcd9378_pde_act_ps_check(v3 - 208, 1094713608, 3);
          goto LABEL_48;
        }
        v19 = 1094713608;
      }
    }
    snd_soc_component_update_bits(v3 - 208, v19 - 104, 255, 0);
    snd_soc_component_update_bits(v3 - 208, v20, 64, 0);
    snd_soc_component_update_bits(v3 - 208, v19, 255, 3);
    goto LABEL_31;
  }
  if ( a3 != 1 )
    return 0;
  if ( (_DWORD)v4 == 32 )
  {
    if ( (snd_soc_component_read(v3 - 208, 1075314991) & 7) == 1 )
    {
      v8 = 3;
      goto LABEL_55;
    }
    if ( (snd_soc_component_read(v3 - 208, 1075314991) & 7) == 3 )
    {
      v8 = 2;
      goto LABEL_55;
    }
    goto LABEL_94;
  }
  if ( (_DWORD)v4 == 31 )
  {
    if ( (snd_soc_component_read(v3 - 208, 1075314990) & 0x38) == 0x10 )
    {
      v8 = 5;
      goto LABEL_55;
    }
    if ( (snd_soc_component_read(v3 - 208, 1075314990) & 0x38) == 0x18 )
    {
      v8 = 4;
      goto LABEL_55;
    }
LABEL_94:
    dev_err(*(_QWORD *)(v3 - 184), "%s: unsupport usecase, pls check\n", "wcd9378_sys_usage_bit_get");
    return 4294967274LL;
  }
  if ( (_DWORD)v4 != 30 )
  {
    v8 = 0;
    goto LABEL_55;
  }
  if ( (snd_soc_component_read(v3 - 208, 1075314990) & 7) != 1 )
  {
    if ( (snd_soc_component_read(v3 - 208, 1075314990) & 7) == 2 )
    {
      v8 = 6;
      goto LABEL_55;
    }
    goto LABEL_94;
  }
  v8 = 7;
LABEL_55:
  wcd9378_sys_usage_auto_udpate(v3 - 208, v8, 1);
  v24 = *(unsigned __int8 *)(a1 + 76);
  v23 = v24 - 30;
  if ( (unsigned __int64)(v24 - 30) >= 3 )
    goto LABEL_99;
  v25 = 3;
  v26 = *(_DWORD *)(v7 + 376 + 4 * v23);
  if ( v26 > 1 )
  {
    if ( v26 == 2 )
      goto LABEL_63;
    if ( v26 == 3 )
    {
      v25 = 5;
      goto LABEL_63;
    }
  }
  else
  {
    if ( !v26 )
      goto LABEL_63;
    if ( v26 == 1 )
    {
      v25 = 1;
      goto LABEL_63;
    }
  }
  printk(&unk_135FF, "wcd9378_get_adc_mode_val");
  v24 = *(unsigned __int8 *)(a1 + 76);
  v23 = v24 - 30;
  if ( (unsigned __int64)(v24 - 30) > 2 )
  {
LABEL_99:
    __break(0x5512u);
LABEL_100:
    _X9 = (unsigned __int64 *)(v6 + 16);
    __asm { PRFM            #0x11, [X9] }
    do
      v42 = __ldxr(_X9);
    while ( __stxr(v42 & ~v23, _X9) );
    mutex_unlock(v6 + 232);
    return swr_slvdev_datapath_control(*(_QWORD *)(v7 + 64), *(unsigned __int8 *)(*(_QWORD *)(v7 + 64) + 64LL), 0);
  }
LABEL_63:
  if ( *(_DWORD *)(v7 + 376 + 4 * v23) == 3 )
    v27 = 4800000;
  else
    v27 = 9600000;
  if ( (_DWORD)v24 == 31
    && (snd_soc_component_read(v3 - 208, 1075314990) & 0x38) == 0x10
    && (*(_BYTE *)(v7 + 395) & 1) == 0 )
  {
    wcd9378_tx_connect_port(v3 - 208, 29, 4800000, 1);
    _X8 = (unsigned __int64 *)(v7 + 456);
    __asm { PRFM            #0x11, [X8] }
    do
      v54 = __ldxr(_X8);
    while ( __stxr(v54 | 0x40, _X8) );
  }
  v28 = *(unsigned __int8 *)(a1 + 76) - 30;
  v29 = v28 >> 6;
  v30 = 1LL << v28;
  _X9 = (unsigned __int64 *)(v7 + 456 + 8 * v29);
  __asm { PRFM            #0x11, [X9] }
  do
    v45 = __ldxr(_X9);
  while ( __stxr(v45 | v30, _X9) );
  wcd9378_tx_connect_port(v3 - 208, *(unsigned __int8 *)(a1 + 76), v27, 1);
  v31 = *(unsigned __int8 *)(a1 + 76);
  switch ( v31 )
  {
    case 32:
      v32 = 1098907912;
      snd_soc_component_update_bits(v3 - 208, 1098907808, 255, v25);
      v34 = 1075314705;
      v33 = v3 - 208;
      break;
    case 31:
      if ( (snd_soc_component_read(v3 - 208, 1075314990) & 0x38) == 0x10 )
      {
        v33 = v3 - 208;
        v35 = 255;
        v32 = 1086326792;
        v36 = v25;
        v34 = 1086326688;
      }
      else
      {
        v32 = 1094713608;
        snd_soc_component_update_bits(v3 - 208, 1094713504, 255, v25);
        v33 = v3 - 208;
        v35 = 32;
        v34 = 1075314703;
        v36 = 32;
      }
      goto LABEL_79;
    case 30:
      v32 = 1090519304;
      snd_soc_component_update_bits(v3 - 208, 1090519200, 255, v25);
      v33 = v3 - 208;
      v34 = 1075314703;
      break;
    default:
      goto LABEL_80;
  }
  v35 = 64;
  v36 = 64;
LABEL_79:
  snd_soc_component_update_bits(v33, v34, v35, v36);
  snd_soc_component_update_bits(v3 - 208, v32, 255, 0);
LABEL_80:
  usleep_range_state(800, 810, 2);
  result = swr_slvdev_datapath_control(*(_QWORD *)(v7 + 64), *(unsigned __int8 *)(*(_QWORD *)(v7 + 64) + 64LL), 1);
  v37 = *(unsigned __int8 *)(a1 + 76);
  switch ( v37 )
  {
    case 32:
      snd_soc_component_update_bits(v3 - 208, 1075314705, 64, 0);
      v38 = wcd9378_pde_act_ps_check(v3 - 208, 1099432192, 0);
      result = 0;
      if ( v38 )
      {
        dev_err(*(_QWORD *)(v3 - 184), "%s: TX2 sequencer power on failed\n", "wcd9378_tx_sequencer_enable");
        return v38;
      }
      break;
    case 31:
      snd_soc_component_update_bits(v3 - 208, 1075314703, 32, 0);
      if ( (*(_QWORD *)(v7 + 16) & 0x20LL) != 0 )
        v39 = 1086851072;
      else
        v39 = 1095237888;
      v38 = wcd9378_pde_act_ps_check(v3 - 208, v39, 0);
      result = 0;
      if ( v38 )
      {
        dev_err(*(_QWORD *)(v3 - 184), "%s: TX1 sequencer power on failed\n", "wcd9378_tx_sequencer_enable");
        return v38;
      }
      break;
    case 30:
      snd_soc_component_update_bits(v3 - 208, 1075314703, 64, 0);
      v38 = wcd9378_pde_act_ps_check(v3 - 208, 1091043584, 0);
      result = 0;
      if ( v38 )
      {
        dev_err(*(_QWORD *)(v3 - 184), "%s: TX0 sequencer power on failed\n", "wcd9378_tx_sequencer_enable");
        return v38;
      }
      break;
  }
  return result;
}
