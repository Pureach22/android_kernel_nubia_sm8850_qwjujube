__int64 __fastcall zte_dsi_panel_tx_cmd_set(__int64 a1, __int64 a2)
{
  if ( a1 && *(_QWORD *)(a1 + 1424) )
  {
    if ( (*(_BYTE *)(a1 + 1973) & 1) == 0 )
    {
      printk(&unk_22C731, a2);
      return 0xFFFFFFFFLL;
    }
    if ( (unsigned int)a2 <= 0x3A )
      return dsi_panel_tx_cmd_set(a1, a2);
  }
  return 4294967274LL;
}
