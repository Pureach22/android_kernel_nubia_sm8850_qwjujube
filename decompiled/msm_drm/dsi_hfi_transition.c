__int64 __fastcall dsi_hfi_transition(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w19

  if ( a2 )
  {
    v2 = dsi_display_hfi_send_cmd_buf(
           a1,
           *(_QWORD *)(*(_QWORD *)(a1 + 1688) + 8LL),
           33554446,
           *(_QWORD *)(a1 + 40),
           1,
           a2,
           4,
           6);
    if ( v2 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: could not send hfi command, rc=%d\n", v2);
  }
  else
  {
    return 0;
  }
  return v2;
}
