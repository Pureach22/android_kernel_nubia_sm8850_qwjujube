__int64 __fastcall ipahal_nat_is_entry_valid(unsigned int a1, __int64 a2, _BYTE *a3)
{
  __int64 ipc_logbuf; // x22
  const char *v7; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  long double v12; // q0
  __int64 v13; // x22
  const char *v14; // x0
  unsigned int v15; // w8
  __int64 (__fastcall *v16)(_QWORD, long double); // x8
  __int64 v17; // x0
  const char *v18; // x4
  __int64 result; // x0
  __int64 v20; // x0
  const char *v21; // x4

  if ( !a2 || !a3 )
  {
    _warn_printk("NULL pointer received\n");
    __break(0x800u);
    return 4294967274LL;
  }
  if ( a1 >= 4 )
  {
    _warn_printk("requested NAT type %d is invalid\n", a1);
    __break(0x800u);
    return 4294967274LL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    v7 = ipahal_nat_type_str(a1);
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d Determine whether the entry is valid for NAT type=%s\n",
      "ipahal_nat_is_entry_valid",
      484,
      v7);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
  if ( ipc_logbuf_low )
  {
    v13 = ipa3_get_ipc_logbuf_low();
    v14 = ipahal_nat_type_str(a1);
    v12 = ipc_log_string(
            v13,
            "ipahal %s:%d Determine whether the entry is valid for NAT type=%s\n",
            "ipahal_nat_is_entry_valid",
            484,
            v14);
  }
  v15 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
  {
    __break(0x5512u);
    goto LABEL_26;
  }
  if ( (192LL * v15 + 48 * (unsigned __int64)a1) >> 4 > 0x136 )
  {
LABEL_26:
    __break(1u);
    return ipahal_nat_stringify_entry(ipc_logbuf_low, v9, v10, v11);
  }
  v16 = (__int64 (__fastcall *)(_QWORD, long double))ipahal_nat_objs[24 * v15 + 2 + 6 * a1];
  if ( *((_DWORD *)v16 - 1) != -9507302 )
    __break(0x8228u);
  *a3 = v16(a2, v12) & 1;
  if ( ipa3_get_ipc_logbuf() )
  {
    v17 = ipa3_get_ipc_logbuf();
    if ( *a3 )
      v18 = (const char *)&unk_3B7A49;
    else
      v18 = "not ";
    ipc_log_string(v17, "ipahal %s:%d The entry is %svalid\n", "ipahal_nat_is_entry_valid", 487, v18);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v20 = ipa3_get_ipc_logbuf_low();
    if ( *a3 )
      v21 = (const char *)&unk_3B7A49;
    else
      v21 = "not ";
    ipc_log_string(v20, "ipahal %s:%d The entry is %svalid\n", "ipahal_nat_is_entry_valid", 487, v21);
    return 0;
  }
  return result;
}
