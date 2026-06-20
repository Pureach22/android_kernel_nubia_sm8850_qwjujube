__int64 __fastcall wlan_ipa_uc_send_evt(__int64 a1, unsigned int a2, const void *a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 v9; // x20
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 )
  {
    v19 = 2621440;
    v8 = _qdf_mem_malloc(0x28u, "wlan_ipa_uc_send_evt", 6661);
    if ( v8 )
    {
      v9 = v8;
      _qdf_ipa_set_meta_msg_type(&v19, a2);
      sized_strscpy(v9, a1 + 296, 32);
      qdf_mem_copy((void *)(v9 + 32), a3, 6u);
      *(_WORD *)(v9 + 38) = *(_DWORD *)(a1 + 224);
      result = ipa_send_msg(&v19, v9, wlan_ipa_msg_free_fn);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: %s: Evt: %d fail",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "wlan_ipa_uc_send_evt",
          v9,
          (unsigned __int8)v19);
        _qdf_mem_free(v9);
        result = 16;
      }
      else
      {
        ++*(_QWORD *)(a4 + 3552);
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
