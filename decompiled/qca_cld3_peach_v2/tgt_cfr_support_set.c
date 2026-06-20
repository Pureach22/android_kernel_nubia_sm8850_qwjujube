__int64 __fastcall tgt_cfr_support_set(__int64 result, int a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( result )
  {
    result = wlan_objmgr_psoc_get_comp_private_obj(result, 0x1Eu);
    if ( result )
    {
      *(_BYTE *)(result + 8) = a2 != 0;
      return qdf_trace_msg(
               0x6Au,
               8u,
               "%s: CFR: FW support advert=%d",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "tgt_cfr_support_set");
    }
  }
  return result;
}
