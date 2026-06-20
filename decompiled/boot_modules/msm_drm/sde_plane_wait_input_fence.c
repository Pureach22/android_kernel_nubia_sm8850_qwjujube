__int64 __fastcall sde_plane_wait_input_fence(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x25
  __int64 v5; // x22
  int name_prefix; // w19
  __int64 v9; // x0
  int v10; // w8
  int v12; // w4
  unsigned int v13; // w20
  char v14; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    printk(&unk_226FC0, "sde_plane_wait_input_fence");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 1768);
  if ( !v3 )
  {
    printk(&unk_2246B5, "sde_plane_wait_input_fence");
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(v3 + 1752);
  if ( !v5 )
    return 0;
  name_prefix = sde_sync_get_name_prefix(*(_QWORD *)(v3 + 1752));
  v9 = sde_sync_wait(v5, a2, a3);
  if ( v9 > -10 )
  {
    if ( v9 == -9 )
    {
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_23C035, *(unsigned int *)(a1 + 104));
      else
        printk(&unk_22E786, "sde_plane_wait_input_fence");
      goto LABEL_12;
    }
    if ( !v9 )
    {
      printk(&unk_27405F, "sde_plane_wait_input_fence");
      sde_kms_timeline_status(*(_QWORD *)a1);
      v10 = -110;
      goto LABEL_21;
    }
  }
  else
  {
    if ( v9 == -512 )
    {
      printk(&unk_21DD02, "sde_plane_wait_input_fence");
      *(_BYTE *)(a1 + 2380) = 1;
      v10 = -512;
      goto LABEL_21;
    }
    if ( v9 == -22 )
    {
      printk(&unk_219D28, "sde_plane_wait_input_fence");
      *(_BYTE *)(a1 + 2380) = 1;
      v10 = -22;
LABEL_21:
      v12 = *(_DWORD *)(a1 + 104);
      v13 = v10;
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_plane_wait_input_fence", 779, -1, v12, -v10, name_prefix, 60333, 239);
      return v13;
    }
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "plane%d signaled\n", *(_DWORD *)(a1 + 104));
LABEL_12:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_plane_wait_input_fence",
    781,
    4,
    *(_DWORD *)(a1 + 104),
    0,
    name_prefix,
    -1059143953,
    v14);
  return 0;
}
