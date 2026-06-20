__int64 __fastcall get_ipa_config(__int64 a1)
{
  int v1; // w19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  v1 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1112);
  if ( v1 == -286331154 )
    return 0;
  if ( v1 == 125 )
    qdf_trace_msg(0x61u, 2u, "%s: Invalid IPA Config 0x%x", v2, v3, v4, v5, v6, v7, v8, v9, "get_ipa_config", 125);
  if ( v1 == 6781 )
    return 6781;
  else
    return 637;
}
