__int64 __fastcall sde_crtc_get_output_fence(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  bool v9; // w22
  void *v10; // x0
  const char *v11; // x1
  __int64 v12; // x8
  __int64 *v13; // x24
  char v14; // w23
  __int64 v16; // x3
  int v17; // w8

  if ( !a1 || !*a1 || (v6 = *(_QWORD *)(*a1 + 56)) == 0 )
  {
    v10 = &unk_25E167;
    v11 = "sde_crtc_get_disp_op";
LABEL_10:
    printk(v10, v11);
    goto LABEL_11;
  }
  v7 = *(_QWORD *)(v6 + 8);
  if ( !v7 )
  {
    v10 = &unk_234896;
    v11 = "_sde_crtc_get_kms";
    goto LABEL_10;
  }
  v8 = *(_QWORD *)(v7 + 152);
  if ( v8 && (*(_QWORD *)(v8 + 22008) & 0x8000000000000LL) != 0 )
  {
    v9 = *(_DWORD *)(v6 + 5912) != 1;
    goto LABEL_12;
  }
LABEL_11:
  v9 = 1;
LABEL_12:
  v12 = *a1;
  v13 = *(__int64 **)(*a1 + 816);
  if ( v13 == (__int64 *)(*a1 + 816) )
  {
LABEL_19:
    v14 = 0;
LABEL_20:
    if ( (a1[991] & 1) != 0 )
    {
      if ( (unsigned int)sde_crtc_get_output_fence_count++ % *((_DWORD *)a1 + 1984) )
      {
        v16 = a1[276];
        if ( v16 )
        {
          v17 = *(_DWORD *)(a2 + 1024);
          if ( (v14 & 1) != 0 )
            return sde_fence_create(a1[404], a3, (unsigned int)(++v17 + 1), v16);
          goto LABEL_28;
        }
        if ( (_drm_debug & 4) != 0 )
        {
          _drm_dev_dbg(0, 0, 0, "invalid crtc params %d\n", 0);
          v17 = *(_DWORD *)(a2 + 1024);
          v16 = 0;
          if ( (v14 & 1) != 0 )
            return sde_fence_create(a1[404], a3, (unsigned int)(++v17 + 1), v16);
LABEL_28:
          if ( v9 )
            return sde_fence_create(a1[404], a3, (unsigned int)(v17 + 1), v16);
          return sde_fence_create(a1[404], a3, (unsigned int)(++v17 + 1), v16);
        }
      }
    }
    v16 = 0;
    v17 = *(_DWORD *)(a2 + 1024);
    if ( (v14 & 1) != 0 )
      return sde_fence_create(a1[404], a3, (unsigned int)(++v17 + 1), v16);
    goto LABEL_28;
  }
  v14 = 1;
  while ( ((*(_DWORD *)(a2 + 20) >> *((_DWORD *)v13 + 15)) & 1) == 0 )
  {
LABEL_14:
    v13 = (__int64 *)*v13;
    if ( v13 == (__int64 *)(v12 + 816) )
      goto LABEL_19;
  }
  if ( (sde_encoder_check_curr_mode(v13 - 1, 1) & 1) != 0 )
    goto LABEL_20;
  if ( (unsigned int)sde_crtc_get_intf_mode(a1, a1[251]) - 3 > 1 )
  {
    v12 = *a1;
    goto LABEL_14;
  }
  v17 = *(_DWORD *)(a2 + 1024);
  v16 = 0;
  return sde_fence_create(a1[404], a3, (unsigned int)(v17 + 1), v16);
}
