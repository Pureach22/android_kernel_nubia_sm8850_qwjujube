__int64 __fastcall tgt_if_regulatory_register_ch_avoid_event_handler(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 2800)) != 0 && (v2 = *(_QWORD *)(v1 + 16)) != 0 )
    return wmi_unified_register_event(v2, 98, &tgt_reg_ch_avoid_event_handler);
  else
    return 16;
}
