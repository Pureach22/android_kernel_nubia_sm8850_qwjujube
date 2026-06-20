__int64 __fastcall wlan_ipa_fw_rejuvenate_send_msg(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 2621440;
  result = _qdf_mem_malloc(0x28u, "wlan_ipa_fw_rejuvenate_send_msg", 6784);
  if ( result )
  {
    v3 = result;
    _qdf_ipa_set_meta_msg_type(&v20, 0xDu);
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: ipa_send_msg(Evt:%d)",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_ipa_fw_rejuvenate_send_msg",
      (unsigned __int8)v20);
    result = ipa_send_msg(&v20, v3, wlan_ipa_msg_free_fn);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: ipa_send_msg(Evt:%d)-fail=%d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_ipa_fw_rejuvenate_send_msg",
        (unsigned __int8)v20,
        (unsigned int)result);
      result = _qdf_mem_free(v3);
    }
    ++*(_QWORD *)(a1 + 3552);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
