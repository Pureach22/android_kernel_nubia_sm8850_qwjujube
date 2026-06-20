__int64 __fastcall hfi_plane_atomic_update(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 *v6; // x23
  int display_id; // w0
  int v9; // w21
  _QWORD *cmd_buf; // x0
  void *v11; // x0

  if ( !a1 || (v2 = a1[221]) == 0 )
  {
    v11 = &unk_211DA1;
LABEL_18:
    printk(v11, "hfi_plane_atomic_update");
    return 4294967274LL;
  }
  if ( !*a1 )
    return 4294967274LL;
  v3 = *(_QWORD *)(*a1 + 56LL);
  if ( !v3 )
    return 4294967274LL;
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
    return 4294967274LL;
  v5 = *(_QWORD *)(v4 + 6440);
  if ( !v5 )
    return 4294967274LL;
  if ( !*(_QWORD *)(v2 + 16) || (v6 = *(__int64 **)(v2 + 8)) == nullptr )
  {
    if ( !a2 )
      return 4294967274LL;
    if ( !*(_QWORD *)(a2 + 16) )
      return 4294967274LL;
    v6 = *(__int64 **)(a2 + 8);
    if ( !v6 )
      return 4294967274LL;
  }
  display_id = hfi_crtc_get_display_id(v6, v6[251]);
  if ( display_id == -1 )
  {
    v11 = &unk_231479;
    goto LABEL_18;
  }
  v9 = display_id;
  cmd_buf = hfi_kms_get_cmd_buf(v5, display_id, 1);
  if ( !cmd_buf )
  {
    printk(&unk_211E26, "hfi_plane_atomic_update");
    return 4294967274LL;
  }
  if ( *(_QWORD *)(v2 + 16) && *(_QWORD *)(v2 + 8) )
    hfi_plane_populate_props((__int64)cmd_buf, v9, a1, v2);
  else
    hfi_plane_disable((__int64)cmd_buf, v9, (__int64)a1, 1);
  return 0;
}
