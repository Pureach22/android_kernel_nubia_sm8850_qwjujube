__int64 __fastcall dsi_panel_alloc_cmd_packets(__int64 a1, int a2)
{
  __int64 v4; // x0

  v4 = _kmalloc_noprof((unsigned int)(a2 << 6), 3520);
  *(_QWORD *)(a1 + 16) = v4;
  if ( !v4 )
    return 4294967284LL;
  *(_DWORD *)(a1 + 8) = a2;
  return 0;
}
