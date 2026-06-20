__int64 __fastcall tgt_if_regulatory_register_master_list_ext_handler(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 2800)) != 0 && (v2 = *(_QWORD *)(v1 + 16)) != 0 )
    return wmi_unified_register_event_handler(v2, 146, tgt_reg_chan_list_ext_update_handler, 0);
  else
    return 16;
}
