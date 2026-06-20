__int64 __fastcall ipa_fltrt_generate_vlan_hw_rule_bdy(_WORD *a1, __int64 a2, _BYTE *a3, _BYTE **a4, _DWORD **a5)
{
  __int64 result; // x0
  unsigned __int64 v6; // x9
  unsigned int v8; // w8
  __int64 v9; // x9
  unsigned int v12; // w22
  _DWORD *v13; // x0
  _DWORD *v14; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( (*(_BYTE *)(a2 + 3) & 0x10) == 0 )
    return 0;
  v6 = (unsigned __int8)*a3;
  if ( v6 < 2 )
  {
    v8 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    {
      __break(0x5512u);
    }
    else
    {
      v9 = *((int *)&ipa3_0_ofst_meq32 + v6);
      if ( v9 + 152 * (unsigned __int64)v8 + 128 <= 0xF6F )
      {
        *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v8 + 16] + v9);
        *a4 = ipa_write_8(250, *a4);
        v12 = *(_WORD *)(a2 + 136) & 0xFFF | 0x81000000;
        v13 = ipa_write_32(-61441, *a5);
        *a5 = v13;
        v14 = ipa_write_32(v12, v13);
        result = 0;
        *a5 = v14;
        ++*a3;
        return result;
      }
    }
    __break(1u);
    return ipa_fltrt_generate_hw_rule_bdy_from_eq(a1, a2);
  }
  printk(&unk_3FA176, "ipa_fltrt_generate_vlan_hw_rule_bdy");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_vlan_hw_rule_bdy", 1466);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_vlan_hw_rule_bdy", 1466);
  }
  return 0xFFFFFFFFLL;
}
