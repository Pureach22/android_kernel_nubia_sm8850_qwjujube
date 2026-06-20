__int64 __fastcall dsi_display_hfi_enable(_QWORD *a1, __int64 a2)
{
  __int64 *v2; // x8
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  unsigned int v8; // w19
  void *v9; // x0

  v2 = (__int64 *)a1[2];
  if ( !v2 || (v3 = *v2) == 0 || (v4 = *(_QWORD *)(v3 + 56)) == 0 )
  {
    v9 = &unk_2207A9;
LABEL_11:
    printk(v9, a2);
    return (unsigned int)-22;
  }
  v5 = *(_QWORD *)(v4 + 8);
  if ( !v5 )
  {
    v9 = &unk_22A98C;
    goto LABEL_11;
  }
  v6 = *(_QWORD *)(v5 + 6440);
  if ( !v6 )
    return (unsigned int)-22;
  v8 = dsi_display_hfi_send_cmd_buf(a1, v6 + 8, 33554438, a1[5], 0, 0, 0, 4);
  if ( v8 )
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Could not send HFI_COMMAND_DISPLAY_ENABLE, rc=%d\n", v8);
  else
    *(_BYTE *)(a1[33] + 1973LL) = 1;
  return v8;
}
