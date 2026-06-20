__int64 __fastcall dp_catalog_panel_set_colorspace(__int64 a1, char a2)
{
  __int64 v3; // x0
  unsigned int v4; // w9
  __int64 v5; // x8
  _DWORD **v6; // x22
  __int64 v7; // x19
  _DWORD *v8; // x10
  unsigned int v9; // w20
  __int64 v10; // x21
  __int64 v11; // x1
  _DWORD *v12; // x8
  __int64 v14; // x0
  __int64 ipc_log_context; // x0
  __int64 v17; // x0

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 204) >= 2u )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      printk(&unk_272496, "dp_catalog_panel_set_colorspace");
      return 4294967274LL;
    }
    else
    {
      if ( (a2 & 1) != 0 )
      {
        v3 = dp_catalog_panel_setup_vsc_sdp(a1);
        v4 = *(_DWORD *)(a1 + 204);
        v5 = a1;
        if ( v4 >= 2 )
        {
          v17 = get_ipc_log_context(v3);
          ipc_log_string(
            v17,
            "[e][%-4d]invalid stream_id:%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(_DWORD *)(a1 + 204));
          printk(&unk_272496, "dp_catalog_panel_sdp_update");
        }
        else
        {
          v6 = (_DWORD **)(a1 - 448);
          v7 = *(_QWORD *)(a1 - 552);
          v8 = *(_DWORD **)(v5 - 448);
          if ( v4 == 1 )
            v9 = 1256;
          else
            v9 = 588;
          v10 = v5 - 576;
          v11 = *(_QWORD *)(v5 - 552);
          if ( *(v8 - 1) != -626862723 )
            __break(0x822Au);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v8)(v5 - 576, v11, v9, 1);
          v12 = *v6;
          if ( *(*v6 - 1) != -626862723 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v12)(v10, v7, v9, 0);
        }
      }
      else
      {
        dp_catalog_panel_config_misc();
      }
      return 0;
    }
  }
  else
  {
    v14 = get_ipc_log_context(0);
    ipc_log_string(v14, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_catalog_panel_set_colorspace");
    return 4294967274LL;
  }
}
