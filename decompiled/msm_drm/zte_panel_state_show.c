__int64 __fastcall zte_panel_state_show(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  if ( v2 )
  {
    seq_printf(a1, "%d\n", *(_DWORD *)(*(_QWORD *)(v2 + 2312) + 88LL));
    return 0;
  }
  else
  {
    printk(&unk_2758E6, a2);
    return 4294967277LL;
  }
}
