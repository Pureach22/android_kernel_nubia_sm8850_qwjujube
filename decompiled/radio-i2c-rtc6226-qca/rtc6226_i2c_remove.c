__int64 __fastcall rtc6226_i2c_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 184);
  free_irq(*(unsigned int *)(a1 + 948), v1);
  kfree(*(_QWORD *)(v1 + 1920));
  v4l2_ctrl_handler_free(v1 + 1504);
  if ( (*(_QWORD *)(v1 + 1368) & 1) != 0 )
    video_unregister_device(v1 + 144);
  video_device_release_empty(v1 + 144);
  v4l2_device_unregister(v1 + 24);
  return kfree(v1);
}
