__int64 __fastcall btfmcodec_dai_shutdown(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x22
  unsigned int current_transport; // w0
  unsigned int prev_transport; // w0
  unsigned int v12; // w20
  __int64 v13; // x8
  _DWORD *v14; // x8
  __int64 v15; // x0
  int v16; // w2
  _QWORD *v17; // x20
  _QWORD *v18; // x19
  _QWORD *v19; // x8
  _QWORD *v20; // x9
  __int64 v21; // x0
  unsigned int v22; // w1
  unsigned int v23; // w20
  __int64 v24; // x8
  _DWORD *v25; // x8
  __int64 v26; // x0
  int v27; // w2
  _QWORD *v28; // x20
  _QWORD *v29; // x19
  _QWORD *v30; // x8
  _QWORD *v31; // x9
  __int64 v32; // [xsp+Ch] [xbp-14h] BYREF
  char v33; // [xsp+14h] [xbp-Ch]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL) + 152LL);
  if ( !(unsigned int)btfmcodec_get_current_transport(v3 + 912) )
  {
    result = printk(&unk_CD22, "btfmcodec_dai_shutdown");
    goto LABEL_51;
  }
  if ( (unsigned int)btfmcodec_get_current_transport(v3 + 912) == 3
    && (unsigned int)btfmcodec_get_prev_transport(v3 + 912) == 2
    || (unsigned int)btfmcodec_get_current_transport(v3 + 912) == 1
    && (unsigned int)btfmcodec_get_prev_transport(v3 + 912) == 4 )
  {
    printk(&unk_D4CD, "btfmcodec_dai_shutdown");
    printk(&unk_DE52, "btfmcodec_port_state_notify");
    v5 = *(_QWORD *)(btfm_get_btfmcodec() + 976);
    v33 = 0;
    v32 = 0x158000005LL;
    btfmcodec_dev_enqueue_pkt(v5, &v32, 9u);
  }
  if ( (unsigned int)btfmcodec_get_current_transport(v3 + 912) != 3
    || (unsigned int)btfmcodec_get_prev_transport(v3 + 912) != 2 )
  {
    if ( (unsigned int)btfmcodec_get_current_transport(v3 + 912)
      && (unsigned int)btfmcodec_get_current_transport(v3 + 912) != 2
      || (unsigned int)btfmcodec_get_current_transport(v3 + 912) == 3
      && (unsigned int)btfmcodec_get_prev_transport(v3 + 912) != 2 )
    {
      current_transport = btfmcodec_get_current_transport(v3 + 912);
      coverttostring(current_transport);
      prev_transport = btfmcodec_get_prev_transport(v3 + 912);
      coverttostring(prev_transport);
      result = printk(&unk_D8D7, "btfmcodec_dai_shutdown");
      goto LABEL_51;
    }
    v8 = *(_QWORD *)(v3 + 984);
    if ( v8 )
      v9 = *(_QWORD *)(v8 + 80);
    else
      v9 = 0;
    v12 = *(_DWORD *)(a2 + 8);
    btfmcodec_get_current_transport(v3 + 912);
    printk(&unk_D101, "btfmcodec_hwep_shutdown");
    if ( v9 )
    {
      v13 = *(_QWORD *)(v9 + 112);
      if ( v13 )
      {
        v14 = *(_DWORD **)(v13 + 8);
        if ( v14 )
        {
          v15 = *(_QWORD *)(v3 + 984);
          if ( *(v14 - 1) != 1607364836 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v14)(v15, v12);
        }
      }
    }
    v16 = *(unsigned __int8 *)(a2 + 8);
    v17 = (_QWORD *)(v3 + 992);
    v18 = (_QWORD *)(v3 + 992);
    while ( 1 )
    {
      v18 = (_QWORD *)*v18;
      if ( v18 == v17 )
        break;
      if ( *((unsigned __int8 *)v18 - 24) == v16 )
      {
        printk(&unk_DAC4, "btfmcodec_delete_configs");
        v19 = (_QWORD *)v18[1];
        if ( (_QWORD *)*v19 == v18 && (v20 = (_QWORD *)*v18, *(_QWORD **)(*v18 + 8LL) == v18) )
        {
          v20[1] = v19;
          *v19 = v20;
        }
        else
        {
          _list_del_entry_valid_or_report(v18);
        }
        *v18 = 0xDEAD000000000100LL;
        v18[1] = 0xDEAD000000000122LL;
        break;
      }
    }
    if ( (_QWORD *)*v17 != v17 )
    {
      printk(&unk_CFCA, "btfmcodec_dai_shutdown");
      v21 = v3 + 912;
      v22 = 2;
      goto LABEL_35;
    }
LABEL_34:
    v21 = v3 + 912;
    v22 = 0;
LABEL_35:
    result = btfmcodec_set_current_state(v21, v22);
    goto LABEL_51;
  }
  printk(&unk_C3EE, "btfmcodec_dai_shutdown");
  v6 = *(_QWORD *)(v3 + 984);
  if ( v6 )
    v7 = *(_QWORD *)(v6 + 80);
  else
    v7 = 0;
  v23 = *(_DWORD *)(a2 + 8);
  btfmcodec_get_current_transport(v3 + 912);
  result = printk(&unk_D101, "btfmcodec_hwep_shutdown");
  if ( v7 )
  {
    v24 = *(_QWORD *)(v7 + 112);
    if ( v24 )
    {
      v25 = *(_DWORD **)(v24 + 8);
      if ( v25 )
      {
        v26 = *(_QWORD *)(v3 + 984);
        if ( *(v25 - 1) != 1607364836 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD))v25)(v26, v23);
      }
    }
  }
  v27 = *(unsigned __int8 *)(a2 + 8);
  v28 = (_QWORD *)(v3 + 992);
  v29 = (_QWORD *)(v3 + 992);
  while ( 1 )
  {
    v29 = (_QWORD *)*v29;
    if ( v29 == v28 )
      break;
    if ( *((unsigned __int8 *)v29 - 24) == v27 )
    {
      result = printk(&unk_DAC4, "btfmcodec_delete_configs");
      v30 = (_QWORD *)v29[1];
      if ( (_QWORD *)*v30 == v29 && (v31 = (_QWORD *)*v29, *(_QWORD **)(*v29 + 8LL) == v29) )
      {
        v31[1] = v30;
        *v30 = v31;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v29);
      }
      *v29 = 0xDEAD000000000100LL;
      v29[1] = 0xDEAD000000000122LL;
      break;
    }
  }
  if ( (_QWORD *)*v28 == v28 )
    goto LABEL_34;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
