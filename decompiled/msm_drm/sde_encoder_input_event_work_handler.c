__int64 __fastcall sde_encoder_input_event_work_handler(__int64 result)
{
  _QWORD *v1; // x9

  if ( result == 1064 )
    return printk(&unk_27A266, "sde_encoder_input_event_work_handler");
  v1 = *(_QWORD **)(result + 240);
  if ( !v1 )
    return printk(&unk_27A266, "sde_encoder_input_event_work_handler");
  if ( *v1 )
    return sde_encoder_resource_control(result - 1064, 7);
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "enc%d input handler is unregistered\n", *(_DWORD *)(result - 1040));
  return result;
}
