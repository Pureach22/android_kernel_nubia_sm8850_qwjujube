__int64 __fastcall sde_encoder_virt_reset(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  void *v4; // x0
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  int v10; // w4

  if ( !a1 || !*(_QWORD *)a1 )
  {
    v4 = &unk_26FCAB;
    goto LABEL_7;
  }
  v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v2 || (v3 = *(_QWORD *)(v2 + 8)) == 0 )
  {
    v4 = &unk_234896;
LABEL_7:
    printk(v4, "sde_encoder_get_kms");
    v3 = 0;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 1360) + 2008LL);
  ((void (__fastcall *)(__int64, _QWORD))sde_encoder_control_fal10_veto)(a1, 0);
  if ( *(_DWORD *)(a1 + 196) )
  {
    v6 = *(_QWORD *)(a1 + 200);
    if ( v6 )
    {
      *(_BYTE *)(v6 + 2289) = 0;
      *(_QWORD *)(*(_QWORD *)(a1 + 200) + 8LL) = 0;
      *(_QWORD *)(*(_QWORD *)(a1 + 200) + 416LL) = 0;
    }
    *(_DWORD *)(a1 + 576) = 0;
    if ( *(_DWORD *)(a1 + 196) >= 2u )
    {
      v7 = *(_QWORD *)(a1 + 208);
      if ( v7 )
      {
        *(_BYTE *)(v7 + 2289) = 0;
        *(_QWORD *)(*(_QWORD *)(a1 + 208) + 8LL) = 0;
        *(_QWORD *)(*(_QWORD *)(a1 + 208) + 416LL) = 0;
      }
      *(_DWORD *)(a1 + 580) = 0;
      if ( *(_DWORD *)(a1 + 196) >= 3u )
      {
        v8 = *(_QWORD *)(a1 + 216);
        if ( v8 )
        {
          *(_BYTE *)(v8 + 2289) = 0;
          *(_QWORD *)(*(_QWORD *)(a1 + 216) + 8LL) = 0;
          *(_QWORD *)(*(_QWORD *)(a1 + 216) + 416LL) = 0;
        }
        *(_DWORD *)(a1 + 584) = 0;
        if ( *(_DWORD *)(a1 + 196) >= 4u )
        {
          v9 = *(_QWORD *)(a1 + 224);
          if ( v9 )
          {
            *(_BYTE *)(v9 + 2289) = 0;
            *(_QWORD *)(*(_QWORD *)(a1 + 224) + 8LL) = 0;
            *(_QWORD *)(*(_QWORD *)(a1 + 224) + 416LL) = 0;
          }
          *(_DWORD *)(a1 + 588) = 0;
          if ( *(_DWORD *)(a1 + 196) > 4u )
          {
            __break(0x5512u);
            JUMPOUT(0xDE640);
          }
        }
      }
    }
  }
  *(_QWORD *)(a1 + 328) = 0;
  *(_QWORD *)(a1 + 1360) = 0;
  memset((void *)(a1 + 3944), 0, 0x388u);
  *(_DWORD *)(v5 + 1816) = 0;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( a1 )
      v10 = *(_DWORD *)(a1 + 24);
    else
      v10 = -1;
    _drm_dev_dbg(0, 0, 0, "enc%d encoder disabled\n", v10);
  }
  return sde_rm_release(v3 + 2144, a1, 0);
}
