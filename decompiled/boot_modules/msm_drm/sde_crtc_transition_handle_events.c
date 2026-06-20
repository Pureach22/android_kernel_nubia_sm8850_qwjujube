__int64 __fastcall sde_crtc_transition_handle_events(__int64 result, char a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x19
  __int64 *v4; // x22

  if ( !result )
    return printk(&unk_25E167, "sde_crtc_transition_handle_events");
  v2 = *(_QWORD *)result;
  v3 = (_QWORD *)result;
  if ( !*(_QWORD *)result || !*(_QWORD *)(v2 + 56) )
    return printk(&unk_25E167, "sde_crtc_transition_handle_events");
  v4 = *(__int64 **)(v2 + 816);
  if ( v4 != (__int64 *)(v2 + 816) )
  {
    do
    {
      if ( ((*(_DWORD *)(v3[251] + 20LL) >> *((_DWORD *)v4 + 15)) & 1) != 0 )
      {
        result = ((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v4 - 1);
        if ( (result & 1) == 0 && (a2 & 1) == 0 && *((_BYTE *)v4 + 1304) == 1 )
          result = sde_encoder_register_vblank_callback(v4 - 1, 0, 0);
      }
      v4 = (__int64 *)*v4;
    }
    while ( v4 != (__int64 *)(*v3 + 816LL) );
  }
  return result;
}
