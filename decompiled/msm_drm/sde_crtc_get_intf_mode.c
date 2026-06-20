__int64 __fastcall sde_crtc_get_intf_mode(__int64 *a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 *i; // x22

  if ( a1 && a2 && (v3 = *a1) != 0 )
  {
    for ( i = *(__int64 **)(v3 + 816); i != (__int64 *)(v3 + 816); i = (__int64 *)*i )
    {
      if ( ((*(_DWORD *)(a2 + 20) >> *((_DWORD *)i + 15)) & 1) != 0
        && (i == (__int64 *)&unk_8
         || (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(i - 1) & 1) == 0
         && ((*(_DWORD *)(a2 + 1812) >> *((_DWORD *)i + 15)) & 1) == 0
         && (*((_BYTE *)i + 636) & 0x80) == 0) )
      {
        return sde_encoder_get_intf_mode(i - 1);
      }
      v3 = *a1;
    }
  }
  else
  {
    printk(&unk_25E167, "sde_crtc_get_intf_mode");
  }
  return 0;
}
