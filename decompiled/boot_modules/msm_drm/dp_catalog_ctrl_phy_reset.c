__int64 __fastcall dp_catalog_ctrl_phy_reset(__int64 a1)
{
  __int64 v1; // x20
  void (__fastcall *v2)(__int64, __int64, __int64, __int64); // x8
  __int64 v3; // x21
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 - 224);
    v2 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    v3 = a1 - 232;
    v5 = a1 - 232;
    if ( *((_DWORD *)v2 - 1) != -626862723 )
      __break(0x8228u);
    v2(v5, v1, 20, 5);
    usleep_range_state(1000, 1010, 2);
    v6 = *(_DWORD **)(a1 - 104);
    if ( *(v6 - 1) != -626862723 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v6)(v3, v1, 20, 0);
    __dsb(0xEu);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_phy_reset");
  }
  return result;
}
