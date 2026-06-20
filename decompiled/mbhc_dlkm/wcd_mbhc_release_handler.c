__int64 __fastcall wcd_mbhc_release_handler(__int64 a1, __int64 a2)
{
  int v3; // w8
  _DWORD *v4; // x8
  __int64 v6; // x20
  unsigned int v7; // w21
  unsigned int v8; // w21

  mutex_lock(a2 + 744);
  if ( *(_DWORD *)(*(_QWORD *)(a2 + 856) + 472LL)
    && !((unsigned __int8)(snd_soc_component_read(*(_QWORD *)(a2 + 216)) & *(_BYTE *)(*(_QWORD *)(a2 + 856) + 476LL)) >> *(_BYTE *)(*(_QWORD *)(a2 + 856) + 477LL))
    && *(_BYTE *)(a2 + 160) == 1 )
  {
    v3 = *(_DWORD *)(a2 + 900);
    *(_BYTE *)(a2 + 160) = 0;
    if ( !v3 && *(_BYTE *)(a2 + 161) == 2 )
    {
      wcd_mbhc_find_plug_and_report(a2, 1);
      goto LABEL_13;
    }
    if ( (*(_BYTE *)(a2 + 105) & 0x7E) == 0 )
      goto LABEL_13;
    if ( (cancel_delayed_work_sync(a2) & 1) != 0 )
    {
      v4 = *(_DWORD **)(*(_QWORD *)(a2 + 120) + 144LL);
      if ( *(v4 - 1) != 1996337026 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v4)(a2, 0);
      if ( (*(_BYTE *)(a2 + 162) & 1) != 0 )
        goto LABEL_12;
      v7 = *(_DWORD *)(a2 + 104);
      v6 = a2 + 568;
      printk(&unk_E38D, "wcd_mbhc_jack_report");
      snd_soc_jack_report(a2 + 568, v7, v7);
    }
    else
    {
      v6 = a2 + 568;
    }
    v8 = *(_DWORD *)(a2 + 104);
    printk(&unk_E38D, "wcd_mbhc_jack_report");
    snd_soc_jack_report(v6, 0, v8);
LABEL_12:
    *(_DWORD *)(a2 + 104) &= 0xFFFF81FF;
  }
LABEL_13:
  mutex_unlock(a2 + 744);
  return 1;
}
