__int64 __fastcall sde_crtc_request_frame_reset(__int64 a1, _BOOL8 a2)
{
  __int64 result; // x0

  if ( (*(_QWORD *)(a1 + 7928) & 2) != 0 )
    sde_crtc_dump_fences(a1);
  if ( *(_DWORD *)(a1 + 7584) == 2 )
    return sde_crtc_reset_hw((__int64 *)a1, *(_QWORD *)(a1 + 2008), 0);
  result = sde_encoder_is_dsi_display(a2);
  if ( (result & 1) == 0 )
    return sde_crtc_reset_hw((__int64 *)a1, *(_QWORD *)(a1 + 2008), 0);
  return result;
}
