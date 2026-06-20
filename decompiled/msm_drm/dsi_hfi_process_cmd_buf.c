__int64 __fastcall dsi_hfi_process_cmd_buf(_QWORD *a1, __int64 a2)
{
  unsigned int v2; // w19
  const char *v3; // x2
  unsigned int v5; // w0

  v2 = -22;
  v3 = "*ERROR* [msm-dsi-error]: Invalid client or buffer\n";
  if ( !a1 || !a2 )
    goto LABEL_7;
  v5 = hfi_adapter_unpack_cmd_buf(a1, a2);
  if ( !v5 )
  {
    v2 = hfi_adapter_release_cmd_buf(a2);
    if ( !v2 )
      return v2;
    v3 = "*ERROR* [msm-dsi-error]: [WARNING] Failed to release command buffer\n";
LABEL_7:
    drm_dev_printk(0, &unk_248D72, v3);
    return v2;
  }
  v2 = v5;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [WARNING] Error in response packet or unpacking buffer\n");
  return v2;
}
