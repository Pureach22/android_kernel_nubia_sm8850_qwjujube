__int64 __fastcall dp_connector_install_properties(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x19
  __int64 ipc_log_context; // x0

  if ( a1 && a2 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 1992LL);
    if ( v2 )
    {
      *(_QWORD *)(a2 + 1992) = v2;
LABEL_5:
      drm_object_attach_property(a2 + 64, v2, 0);
      return 0;
    }
    v4 = a2;
    result = drm_mode_create_dp_colorspace_property();
    if ( !(_DWORD)result )
    {
      v2 = *(_QWORD *)(v4 + 1992);
      a2 = v4;
      goto LABEL_5;
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24B695, "dp_connector_install_properties");
    return 4294967274LL;
  }
  return result;
}
