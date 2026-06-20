__int64 __fastcall wcd938x_rx_hph_mode_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  int v4; // w8

  v2 = *(_QWORD *)(a1 + 128);
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  v4 = *(_DWORD *)(a2 + 72);
  if ( *(_DWORD *)(v3 + 8) )
  {
    if ( !v4 )
    {
LABEL_9:
      if ( (unsigned int)__ratelimit(&wcd938x_rx_hph_mode_put__rs_386, "wcd938x_rx_hph_mode_put") )
        dev_info(*(_QWORD *)(v2 + 24), "%s:Invalid HPH Mode, default to class_AB\n", "wcd938x_rx_hph_mode_put");
LABEL_11:
      v4 = 5;
    }
  }
  else
  {
    if ( !v4 )
      goto LABEL_9;
    if ( v4 == 6 || v4 == 1 )
    {
      if ( (unsigned int)__ratelimit(&wcd938x_rx_hph_mode_put__rs, "wcd938x_rx_hph_mode_put") )
        dev_info(*(_QWORD *)(v2 + 24), "%s:Invalid HPH Mode, default to CLS_H_ULP\n", "wcd938x_rx_hph_mode_put");
      goto LABEL_11;
    }
  }
  *(_DWORD *)(v3 + 264) = v4;
  return 0;
}
