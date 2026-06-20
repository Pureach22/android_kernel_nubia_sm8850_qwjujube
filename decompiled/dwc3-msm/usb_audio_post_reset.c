__int64 __fastcall usb_audio_post_reset(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 176);
  dev_info(v1, "USB bus reset recovery triggered\n");
  if ( !*(_QWORD *)(*(_QWORD *)(v1 - 96) + 72LL) )
    kobject_uevent(a1 + 80, 2);
  return 0;
}
