__int64 __fastcall tgt_if_reg_txpb_unregister_event_handler(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 2800)) != 0 && (v2 = *(_QWORD *)(v1 + 16)) != 0 )
    return wmi_unified_unregister_event_handler(v2, 270);
  else
    return 16;
}
