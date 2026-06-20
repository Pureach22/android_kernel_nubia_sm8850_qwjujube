__int64 __fastcall gsi_inst_clean(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w21

  v1 = *(_QWORD *)(a1 + 176);
  v3 = *(_DWORD *)(v1 + 1200);
  if ( v3 )
  {
    device_destroy(gsi_class, v3);
    cdev_del(v1 + 1072);
    *(_DWORD *)(v1 + 1200) = 0;
    ida_free(&gsi_ida, v3 & 0xFFFFF);
    v1 = *(_QWORD *)(a1 + 176);
  }
  kfree(v1);
  return kfree(a1);
}
