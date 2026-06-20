__int64 __fastcall sde_encoder_phys_cmd_mode_fixup(_DWORD *a1)
{
  int v1; // w4
  _DWORD *v3; // x19

  if ( !a1 )
    return 1;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
      v1 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v1 = -1;
    v3 = a1;
    _drm_dev_dbg(0, 0, 0, "enc%d intf%d \n", v1, a1[168] - 1);
    a1 = v3;
  }
  if ( a1[166] != 2 )
    return 1;
  printk(&unk_2770FA, "sde_encoder_phys_cmd_mode_fixup");
  return 0;
}
