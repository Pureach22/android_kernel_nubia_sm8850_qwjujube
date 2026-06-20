__int64 __fastcall hfi_crtc_atomic_check(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x21
  unsigned int display_id; // w0
  unsigned int v8; // w20
  __int64 cmd_buf; // x0
  void *v11; // x0

  if ( !a1 )
  {
    v11 = &unk_211DA1;
LABEL_10:
    printk(v11, "hfi_crtc_atomic_check");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)a1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
    return 4294967274LL;
  v4 = *(_QWORD *)(v3 + 6440);
  if ( !v4 )
    return 4294967274LL;
  display_id = hfi_crtc_get_display_id(
                 (__int64 *)a1,
                 *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 328) + 32LL) + 56LL * *(unsigned int *)(a1 + 160) + 24));
  if ( display_id == -1 )
  {
    v11 = &unk_231479;
    goto LABEL_10;
  }
  v8 = display_id;
  cmd_buf = hfi_kms_get_cmd_buf(v4, display_id, 0);
  if ( cmd_buf )
  {
    hfi_crtc_populate_props(cmd_buf, v8, (_QWORD *)a1, a2);
    return 0;
  }
  printk(&unk_211E26, "hfi_crtc_atomic_check");
  return 4294967274LL;
}
