__int64 __fastcall ipa_flt_generat_vlan_eq(__int64 a1, _WORD *a2, _BYTE *a3, __int64 a4, long double a5)
{
  __int64 result; // x0
  unsigned __int64 v6; // x9
  unsigned int v7; // w8
  __int64 v8; // x9
  __int64 v9; // x8
  __int16 v10; // w9
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( (*(_BYTE *)(a1 + 3) & 0x10) == 0 )
    return 0;
  v6 = (unsigned __int8)*a3;
  if ( v6 < 2 )
  {
    v7 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx < 0x1Au )
    {
      v8 = *((int *)&ipa3_0_ofst_meq32 + v6);
      if ( v8 + 152 * (unsigned __int64)v7 + 128 > 0xF6F )
      {
LABEL_17:
        __break(1u);
        return ipa_fltrt_parse_hw_rule_eq(a1, a2, a3, a4, a5);
      }
      *a2 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v7 + 16] + v8);
      if ( (unsigned __int8)*a3 <= 1uLL )
      {
        v9 = a4 + 24;
        *(_BYTE *)(a4 + 24 + 12LL * (unsigned __int8)*a3) = -6;
        if ( (unsigned __int8)*a3 <= 1uLL )
        {
          v10 = *(_WORD *)(a1 + 136);
          *(_DWORD *)(v9 + 12LL * (unsigned __int8)*a3 + 4) = -61441;
          if ( (unsigned __int8)*a3 <= 1uLL )
          {
            result = 0;
            *(_DWORD *)(v9 + 12LL * (unsigned __int8)(*a3)++ + 8) = v10 & 0xFFF | 0x81000000;
            return result;
          }
        }
      }
    }
    __break(0x5512u);
    goto LABEL_17;
  }
  printk(&unk_3FA176, "ipa_flt_generat_vlan_eq");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d ran out of meq32 eq\n", "ipa_flt_generat_vlan_eq", 3103);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d ran out of meq32 eq\n", "ipa_flt_generat_vlan_eq", 3103);
  }
  return 0xFFFFFFFFLL;
}
