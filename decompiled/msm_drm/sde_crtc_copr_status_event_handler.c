__int64 __fastcall sde_crtc_copr_status_event_handler(__int64 a1, char a2)
{
  if ( !a1 )
    return 4294967274LL;
  *(_BYTE *)(a1 + 7947) = a2 & 1;
  return 0;
}
