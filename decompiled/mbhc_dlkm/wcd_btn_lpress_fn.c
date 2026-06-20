__int64 __fastcall wcd_btn_lpress_fn(__int64 a1)
{
  __int64 v1; // x19
  __int64 (*v2)(void); // x8
  unsigned int v4; // w19
  __int64 v5; // x20

  if ( *(_DWORD *)(*(_QWORD *)(a1 + 856) + 344LL) )
  {
    v1 = a1;
    snd_soc_component_read(*(_QWORD *)(a1 + 216));
    a1 = v1;
  }
  if ( *(_BYTE *)(a1 + 161) == 1 )
  {
    v4 = *(_DWORD *)(a1 + 104);
    v5 = a1;
    printk(&unk_E38D, "wcd_mbhc_jack_report");
    snd_soc_jack_report(v5 + 568, v4, v4);
    a1 = v5;
  }
  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 120) + 144LL);
  if ( *((_DWORD *)v2 - 1) != 1996337026 )
    __break(0x8228u);
  return v2();
}
