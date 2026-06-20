__int64 __fastcall ipahal_stats_generate_init_pyld(unsigned int a1, __int64 a2, char a3)
{
  char v3; // w14
  unsigned int v4; // w9
  _DWORD *v5; // x9
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 < 4 )
  {
    v4 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    {
      __break(0x5512u);
    }
    else if ( 96LL * v4 + 24 * (unsigned __int64)a1 <= 0x9BF )
    {
      v5 = (_DWORD *)ipahal_hw_stats_objs[12 * v4 + 3 * a1];
      if ( *(v5 - 1) != -356579242 )
        __break(0x8229u);
      return ((__int64 (__fastcall *)(__int64, _QWORD))v5)(a2, a3 & 1);
    }
    __break(1u);
    if ( (v3 & 0x40) != 0 )
      JUMPOUT(0x198CD8);
    JUMPOUT(0x19A068);
  }
  printk(&unk_3F6A9B, "ipahal_stats_generate_init_pyld");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d Invalid type stat=%d\n", "ipahal_stats_generate_init_pyld", 1074, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Invalid type stat=%d\n", "ipahal_stats_generate_init_pyld", 1074, a1);
  }
  __break(0x800u);
  return 0;
}
