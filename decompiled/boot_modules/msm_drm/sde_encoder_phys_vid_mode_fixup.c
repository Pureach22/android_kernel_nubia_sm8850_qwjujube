__int64 __fastcall sde_encoder_phys_vid_mode_fixup(_QWORD *a1)
{
  int v1; // w4
  __int64 v2; // x8
  int v3; // w5

  if ( a1 && (_drm_debug & 4) != 0 )
  {
    if ( *a1 )
    {
      v1 = *(_DWORD *)(*a1 + 24LL);
      v2 = a1[53];
      if ( v2 )
      {
LABEL_5:
        v3 = *(_DWORD *)(v2 + 32) - 1;
LABEL_8:
        _drm_dev_dbg(0, 0, 0, "enc%d intf%d \n", v1, v3);
        return 1;
      }
    }
    else
    {
      v1 = -1;
      v2 = a1[53];
      if ( v2 )
        goto LABEL_5;
    }
    v3 = -1;
    goto LABEL_8;
  }
  return 1;
}
