__int64 __fastcall dp_panel_hdr_supported(_BYTE *a1)
{
  char v1; // w8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = a1[1264];
    if ( v1 )
    {
      if ( a1[1233] != 1 )
        return 0;
      if ( (unsigned __int8)a1[1265] > 3u )
        return 1;
      v1 = a1[1234];
    }
    return v1 & 1;
  }
  else
  {
    ipc_log_context = get_ipc_log_context((unsigned __int8)a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_panel_hdr_supported");
    return 0;
  }
}
