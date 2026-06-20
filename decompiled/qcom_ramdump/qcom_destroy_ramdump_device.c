__int64 __fastcall qcom_destroy_ramdump_device(__int64 result)
{
  unsigned __int64 v1; // x19
  int v2; // w20

  v1 = *(_QWORD *)(result + 152);
  if ( v1 )
  {
    if ( v1 <= 0xFFFFFFFFFFFFF000LL )
    {
      v2 = *(_DWORD *)(v1 + 384);
      cdev_del(v1 + 256);
      device_unregister(*(_QWORD *)(v1 + 392));
      ida_free(&rd_minor_id, v2 & 0xFFFFF);
      return kfree(v1);
    }
  }
  return result;
}
