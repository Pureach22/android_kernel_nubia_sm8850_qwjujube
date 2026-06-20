__int64 __fastcall syna_dev_set_up_app_fw(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned int v3; // w20
  __int64 v4; // x2
  unsigned int app_info; // w0
  __int64 v6; // x2
  void *v8; // x8
  unsigned int v9; // w19

  if ( !a1 )
    return 4294967274LL;
  v1 = a1[78];
  v2 = *a1;
  if ( v1 != -168 && *(_DWORD *)(v1 + 184) && (*(_BYTE *)(v1 + 188) & 1) != 0 )
    v3 = 0;
  else
    v3 = *(_DWORD *)(v2 + 524);
  v4 = *(unsigned __int8 *)(v2 + 9);
  if ( (_DWORD)v4 != 1 )
  {
    printk(unk_32EDC, "syna_dev_set_up_app_fw", v4);
    return 4294967274LL;
  }
  app_info = syna_tcm_get_app_info(*a1, v2 + 176, v3);
  if ( (app_info & 0x80000000) != 0 )
  {
    v8 = unk_3298B;
LABEL_16:
    v9 = app_info;
    printk(v8, "syna_dev_set_up_app_fw", v6);
    return v9;
  }
  app_info = syna_tcm_preserve_touch_report_config(v2, v3);
  if ( (app_info & 0x80000000) != 0 )
  {
    v8 = unk_3609B;
    goto LABEL_16;
  }
  return 0;
}
