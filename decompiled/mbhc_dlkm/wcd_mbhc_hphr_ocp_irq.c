__int64 __fastcall wcd_mbhc_hphr_ocp_irq(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w8
  char v5; // w9
  __int64 v6; // x8
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 v9; // x1
  __int64 v10; // x0
  _DWORD *v11; // x8
  __int64 v12; // x1
  unsigned int v13; // w20

  if ( a2 )
  {
    if ( *(_BYTE *)(a2 + 912) == 1 )
    {
      *(_BYTE *)(a2 + 912) = 0;
    }
    else
    {
      v3 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 120) + 272LL);
      if ( !v3 )
        goto LABEL_8;
      if ( *((_DWORD *)v3 - 1) != -9629763 )
        __break(0x8228u);
      if ( (v3(a2) & 1) == 0 )
      {
LABEL_8:
        v4 = *(unsigned __int8 *)(a2 + 133);
        if ( v4 > 0x13 )
        {
          v10 = *(_QWORD *)(a2 + 216);
          v11 = *(_DWORD **)(*(_QWORD *)(a2 + 120) + 112LL);
          v12 = *(unsigned int *)(*(_QWORD *)(a2 + 792) + 24LL);
          if ( *(v11 - 1) != 542830841 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v11)(v10, v12, 0);
          v13 = *(_DWORD *)(a2 + 128);
          printk(&unk_DEBE, "wcd_mbhc_jack_report");
          snd_soc_jack_report(a2 + 392, v13, 15);
        }
        else
        {
          v5 = v4 + 1;
          v6 = *(_QWORD *)(a2 + 856);
          *(_BYTE *)(a2 + 133) = v5;
          v7 = *(unsigned int *)(v6 + 328);
          if ( (_DWORD)v7 )
          {
            snd_soc_component_update_bits(*(_QWORD *)(a2 + 216), v7, *(unsigned __int8 *)(v6 + 332), 0);
            v8 = *(_QWORD *)(a2 + 856);
            v9 = *(unsigned int *)(v8 + 328);
            if ( (_DWORD)v9 )
              snd_soc_component_update_bits(
                *(_QWORD *)(a2 + 216),
                v9,
                *(unsigned __int8 *)(v8 + 332),
                (unsigned int)(1 << *(_BYTE *)(v8 + 333)));
          }
        }
      }
    }
  }
  else
  {
    printk(&unk_DE64, "wcd_mbhc_hphr_ocp_irq");
  }
  return 1;
}
