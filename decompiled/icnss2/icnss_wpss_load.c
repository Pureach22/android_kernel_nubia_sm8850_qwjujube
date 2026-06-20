__int64 icnss_wpss_load()
{
  __int64 v0; // x21
  unsigned __int64 v1; // x0
  __int64 result; // x0
  const char *v3; // x19
  int v4; // w20
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = penv;
  v5 = 0;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(penv + 8) + 760LL), "qcom,rproc-handle", &v5, 1, 0)
      & 0x80000000) != 0 )
  {
    v3 = "%sicnss2: error reading rproc phandle\n";
    printk("%sicnss2: error reading rproc phandle\n", byte_130B32);
LABEL_9:
    result = ipc_log_string(icnss_ipc_log_context, v3, &unk_12DBF3);
    goto LABEL_6;
  }
  v1 = rproc_get_by_phandle(v5);
  *(_QWORD *)(v0 + 3264) = v1;
  if ( !v1 || v1 >= 0xFFFFFFFFFFFFF001LL )
  {
    v3 = "%sicnss2: rproc not found";
    printk("%sicnss2: rproc not found", byte_130B32);
    goto LABEL_9;
  }
  result = rproc_boot();
  if ( (_DWORD)result )
  {
    v4 = result;
    printk("%sicnss2: Failed to boot wpss rproc, ret: %d", byte_130B32, result);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to boot wpss rproc, ret: %d", (const char *)&unk_12DBF3, v4);
    result = rproc_put(*(_QWORD *)(v0 + 3264));
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
