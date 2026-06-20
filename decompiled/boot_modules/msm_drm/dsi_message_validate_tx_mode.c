__int64 __fastcall dsi_message_validate_tx_mode(__int64 a1, int a2, int *a3)
{
  int v3; // w8
  const char *v4; // x3
  __int64 v5; // x9
  const char *v6; // x3
  __int64 v7; // x9
  const char *v9; // x3
  const char *v10; // x3
  const char *v11; // x3

  v3 = *a3;
  if ( (*a3 & 0x10) != 0 )
  {
    if ( (unsigned int)(a2 - 61) <= 0xFFFFFFBE )
    {
      if ( a1 )
        v4 = *(const char **)(a1 + 16);
      else
        v4 = "inv";
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Cannot transfer Cmd in FIFO config\n", v4);
      return 4294966772LL;
    }
    v5 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v5 >= 3 )
      goto LABEL_36;
    if ( !*(_QWORD *)(a1 + 8 * v5 + 528) )
    {
      if ( a1 )
        v10 = *(const char **)(a1 + 16);
      else
        v10 = "inv";
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Cannot transfer command,ops not defined\n", v10);
      return 4294966772LL;
    }
  }
  if ( (v3 & 0x80) == 0 )
    goto LABEL_8;
  if ( (v3 & 2) != 0 )
  {
    if ( a1 )
      v9 = *(const char **)(a1 + 16);
    else
      v9 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Non embedded not supported with broadcast\n", v9);
    return 4294966772LL;
  }
  v7 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v7 > 2 )
  {
LABEL_36:
    __break(0x5512u);
    return dsi_ctrl_toggle_error_interrupt_status();
  }
  if ( !*(_QWORD *)(a1 + 8 * v7 + 504) )
  {
    if ( a1 )
      v11 = *(const char **)(a1 + 16);
    else
      v11 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s:  Cannot transfer command,ops not defined\n", v11);
    return 4294966772LL;
  }
  if ( (unsigned int)(a2 - 4093) > 0xFFFFEFFE )
  {
LABEL_8:
    if ( (v3 & 0x20) == 0 || (unsigned int)(a2 + *(_DWORD *)(a1 + 2784) - 4093) > 0xFFFFEFFE )
      return 0;
    if ( a1 )
      goto LABEL_11;
LABEL_17:
    v6 = "inv";
    goto LABEL_18;
  }
  if ( !a1 )
    goto LABEL_17;
LABEL_11:
  v6 = *(const char **)(a1 + 16);
LABEL_18:
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Cannot transfer,size is greater than 4096\n", v6);
  return 4294966772LL;
}
