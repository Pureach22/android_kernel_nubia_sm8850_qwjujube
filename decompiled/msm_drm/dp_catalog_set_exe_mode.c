__int64 __fastcall dp_catalog_set_exe_mode(__int64 a1, char *string)
{
  size_t v4; // x0
  unsigned __int64 v5; // x2
  __int64 v6; // x20
  void (__fastcall *v7)(__int64, const char *); // x8
  void (__fastcall *v8)(__int64, const char *); // x8
  void (__fastcall *v9)(__int64, const char *); // x8
  void (__fastcall *v10)(__int64, const char *); // x8
  void (__fastcall *v11)(__int64, const char *); // x8
  void (__fastcall *v12)(__int64, const char *); // x8
  void (__fastcall *v13)(__int64, const char *); // x8
  void (__fastcall *v14)(__int64, const char *); // x8
  void (__fastcall *v15)(__int64, const char *); // x8
  void (__fastcall *v16)(__int64, const char *); // x8
  void (__fastcall *v17)(__int64, const char *); // x8
  void (__fastcall *v18)(__int64, const char *); // x8
  __int64 (__fastcall *v19)(__int64, const char *); // x8
  __int64 result; // x0
  _QWORD *v21; // x10
  __int64 (__fastcall *v22)(); // x9
  _QWORD *v23; // x10
  __int64 (*v24)(void); // x8
  __int64 ipc_log_context; // x0
  __int64 v26; // x0
  __int64 v27; // x11

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_set_exe_mode");
  }
  v4 = strnlen(string, 4u);
  if ( v4 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v4 == 4 )
      v5 = 4;
    else
      v5 = v4 + 1;
    if ( v5 < 5 )
    {
      sized_strscpy(a1 + 1224, string);
      if ( *(_BYTE *)(a1 + 1224) == 104 && *(_BYTE *)(a1 + 1225) == 119 && !*(_BYTE *)(a1 + 1226) )
      {
        v24 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 32) + 864LL);
        if ( *((_DWORD *)v24 - 1) != 680055959 )
          __break(0x8228u);
        result = v24();
      }
      else
      {
        v6 = *(_QWORD *)(a1 - 32);
        v7 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v7 - 1) != -1887062843 )
          __break(0x8228u);
        v7(v6, "dp_ahb");
        v8 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v8 - 1) != -1887062843 )
          __break(0x8228u);
        v8(v6, "dp_aux");
        v9 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v9 - 1) != -1887062843 )
          __break(0x8228u);
        v9(v6, "dp_link");
        v10 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v10 - 1) != -1887062843 )
          __break(0x8228u);
        v10(v6, "dp_p0");
        v11 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v11 - 1) != -1887062843 )
          __break(0x8228u);
        v11(v6, "dp_phy");
        v12 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v12 - 1) != -1887062843 )
          __break(0x8228u);
        v12(v6, "dp_ln_tx0");
        v13 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v13 - 1) != -1887062843 )
          __break(0x8228u);
        v13(v6, "dp_ln_tx1");
        v14 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v14 - 1) != -1887062843 )
          __break(0x8228u);
        v14(v6, "dp_pll");
        v15 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v15 - 1) != -1887062843 )
          __break(0x8228u);
        v15(v6, "usb3_dp_com");
        v16 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v16 - 1) != -1887062843 )
          __break(0x8228u);
        v16(v6, "dp_mmss_cc");
        v17 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v17 - 1) != -1887062843 )
          __break(0x8228u);
        v17(v6, "hdcp_physical");
        v18 = *(void (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v18 - 1) != -1887062843 )
          __break(0x8228u);
        v18(v6, "dp_p1");
        v19 = *(__int64 (__fastcall **)(__int64, const char *))(v6 + 856);
        if ( *((_DWORD *)v19 - 1) != -1887062843 )
          __break(0x8228u);
        result = v19(v6, "dp_tcsr");
      }
      if ( *(_BYTE *)(a1 + 1224) == 104 && *(_BYTE *)(a1 + 1225) == 119 && !*(_BYTE *)(a1 + 1226)
        || (result = strcmp((const char *)(a1 + 1224), "all"), !(_DWORD)result) )
      {
        v23 = *(_QWORD **)(a1 + 1192);
        *(_QWORD *)(a1 - 24) = dp_read_hw;
        *(_QWORD *)(a1 - 16) = dp_write_hw;
        *v23 = dp_read_sub_hw;
        v22 = dp_write_sub_hw;
      }
      else
      {
        v21 = *(_QWORD **)(a1 + 1192);
        *(_QWORD *)(a1 - 24) = dp_read_sw;
        *(_QWORD *)(a1 - 16) = dp_write_sw;
        *v21 = dp_read_sub_sw;
        v22 = dp_write_sub_sw;
      }
      *(_QWORD *)(*(_QWORD *)(a1 + 1192) + 8LL) = v22;
      return result;
    }
  }
  v26 = _fortify_panic(7, 4, v5);
  if ( v27 )
    JUMPOUT(0x102E64);
  return dp_catalog_reg_dump(v26);
}
