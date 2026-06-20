__int64 __fastcall msm_audio_ion_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  *(_BYTE *)v1 = 0;
  *(_BYTE *)(v1 + 16) = 0;
  cdev_del(v1 + 136);
  device_destroy(*(_QWORD *)(v1 + 120), *(unsigned int *)(v1 + 112));
  class_destroy(*(_QWORD *)(v1 + 120));
  return unregister_chrdev_region(0, 1);
}
