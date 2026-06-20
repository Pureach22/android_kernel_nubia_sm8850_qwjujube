__int64 __fastcall sde_encoder_input_disconnect(__int64 a1)
{
  input_close_device();
  input_unregister_handle(a1);
  return kfree(a1);
}
