void __fastcall lim_received_hb_handler(__int64 a1, int a2, __int64 a3)
{
  if ( !a2 || *(_DWORD *)(a3 + 284) == a2 )
    ++*(_BYTE *)(a3 + 292);
  *(_BYTE *)(a3 + 7279) = 0;
}
