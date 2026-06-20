__int64 __fastcall ipahal_nat_is_entry_zeroed(unsigned int a1, __int64 a2, _BYTE *a3)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  int v9; // w12
  long double v10; // q0
  __int64 v11; // x22
  const char *v12; // x0
  unsigned int v13; // w8
  __int64 (__fastcall *v14)(_QWORD, long double); // x8
  __int64 result; // x0
  __int64 v16; // x0
  const char *v17; // x4

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
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
  if ( ipc_logbuf_low )
  {
    v11 = ipa3_get_ipc_logbuf_low();
    v12 = ipahal_nat_type_str(a1);
    v10 = ipc_log_string(
            v11,
            "ipahal %s:%d Determine whether the entry is zeroed for NAT type=%s\n",
            "ipahal_nat_is_entry_zeroed",
            459,
            v12);
  }
  v13 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
  {
    __break(0x5512u);
  }
  else if ( ((192LL * v13 + 48LL * a1) | 8uLL) <= 0x1380 )
  {
    v14 = (__int64 (__fastcall *)(_QWORD, long double))ipahal_nat_objs[24 * v13 + 1 + 6 * a1];
    if ( *((_DWORD *)v14 - 1) != -9507302 )
      __break(0x8228u);
    *a3 = v14(a2, v10) & 1;
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      if ( *a3 )
        v17 = (const char *)&unk_3B7A49;
      else
        v17 = "not ";
      ipc_log_string(v16, "ipahal %s:%d The entry is %szeroed\n", "ipahal_nat_is_entry_zeroed", 466, v17);
      return 0;
    }
    return result;
  }
  __break(1u);
  if ( !v9 )
    JUMPOUT(0x191F94);
  return ipahal_nat_is_entry_valid(ipc_logbuf_low, v7, v8);
}
