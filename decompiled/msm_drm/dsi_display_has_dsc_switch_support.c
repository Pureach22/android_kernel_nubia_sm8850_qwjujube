__int64 __fastcall dsi_display_has_dsc_switch_support(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 264);
    if ( v2 )
      return *(_BYTE *)(v2 + 1416) & 1;
  }
  printk(&unk_24768D, a2);
  return 0;
}
