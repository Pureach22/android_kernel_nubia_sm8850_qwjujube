__int64 __fastcall sde_encoder_phys_vid_destroy(_QWORD *a1)
{
  int v1; // w4
  __int64 v2; // x8
  _QWORD *v3; // x19
  int v4; // w5

  if ( !a1 )
    return printk(&unk_26FCAB, "sde_encoder_phys_vid_destroy");
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *a1 )
    {
      v1 = *(_DWORD *)(*a1 + 24LL);
      v2 = a1[53];
      if ( v2 )
      {
LABEL_5:
        v3 = a1;
        v4 = *(_DWORD *)(v2 + 32) - 1;
LABEL_8:
        _drm_dev_dbg(0, 0, 0, "enc%d intf%d \n", v1, v4);
        a1 = v3;
        return kfree(a1);
      }
    }
    else
    {
      v1 = -1;
      v2 = a1[53];
      if ( v2 )
        goto LABEL_5;
    }
    v3 = a1;
    v4 = -1;
    goto LABEL_8;
  }
  return kfree(a1);
}
