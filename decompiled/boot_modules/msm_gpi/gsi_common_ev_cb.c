__int64 __fastcall gsi_common_ev_cb(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 (__fastcall *v10)(__int64, __int64, unsigned __int8 *); // x8

  if ( !a3 )
    return printk(&unk_122FF, "gsi_common_ev_cb", 0, a4, a5, a6, a7);
  ipc_log_string(*((_QWORD *)a3 + 2310), "%s: protocol:%d\n", "gsi_common_ev_cb", *a3);
  v10 = *((__int64 (__fastcall **)(__int64, __int64, unsigned __int8 *))a3 + 2314);
  if ( *((_DWORD *)v10 - 1) != 1361247836 )
    __break(0x8228u);
  return v10(a1, a2, a3);
}
