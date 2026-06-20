__int64 __fastcall dp_panel_handle_sink_request(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned int edid_checksum; // w0
  __int64 v4; // x1
  void (__fastcall *v5)(__int64, __int64); // x9
  __int64 (*v6)(void); // x8
  __int64 ipc_log_context; // x0

  if ( result )
  {
    v1 = *(_QWORD *)(result + 1200);
    v2 = result;
    if ( (*(_BYTE *)v1 & 4) != 0 )
    {
      if ( **(_QWORD **)(result + 96) )
      {
        edid_checksum = sde_get_edid_checksum();
        v1 = *(_QWORD *)(v2 + 1200);
        v4 = edid_checksum;
      }
      else
      {
        v4 = *(unsigned __int8 *)(*(_QWORD *)(result + 944) + 2497LL);
      }
      v5 = *(void (__fastcall **)(__int64, __int64))(v1 + 200);
      if ( *((_DWORD *)v5 - 1) != 865892320 )
        __break(0x8229u);
      v5(v1, v4);
      v6 = *(__int64 (**)(void))(*(_QWORD *)(v2 + 1200) + 184LL);
      if ( *((_DWORD *)v6 - 1) != 1968921649 )
        __break(0x8228u);
      return v6();
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_panel_handle_sink_request");
  }
  return result;
}
