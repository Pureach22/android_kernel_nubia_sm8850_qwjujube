__int64 __fastcall cam_tpg_flush_req(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  int v4; // w6
  __int64 v5; // x2
  const char *v6; // x5
  __int64 v7; // x4
  int v9; // w0
  unsigned int v10; // w20

  if ( !a1 )
  {
    v6 = "Invalid flush request handle encountered";
    v7 = 146;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_flush_req",
      v7,
      v6);
    return 4294967274LL;
  }
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    v6 = "Invalid TPG handle encountered during flush req";
    v7 = 153;
    goto LABEL_11;
  }
  v3 = device_priv;
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_flush_req",
      157,
      "Got flush request from crm. Flush Type: %d Req: %lld",
      *(_DWORD *)(a1 + 8),
      *(_QWORD *)(a1 + 16));
  mutex_lock(v3 + 24);
  v4 = *(_DWORD *)(a1 + 8);
  if ( v4 )
  {
    if ( v4 != 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_flush_req",
        170,
        "Invalid TPG flush type [%d] rcvd",
        v4);
      v9 = -22;
      goto LABEL_16;
    }
    v5 = 0;
  }
  else
  {
    v5 = 1;
  }
  v9 = tpg_hw_flush_requests(v3 + 4568, *(unsigned int *)(a1 + 16), v5);
  if ( v9 )
  {
LABEL_16:
    v10 = v9;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_flush_req",
      174,
      "Flushing active/waiting queue failed");
    goto LABEL_17;
  }
  v10 = 0;
LABEL_17:
  mutex_unlock(v3 + 24);
  return v10;
}
