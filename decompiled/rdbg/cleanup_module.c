__int64 cleanup_module()
{
  int v0; // w8
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x9

  v0 = dword_104;
  if ( dword_104 >= 1 )
  {
    v1 = 0;
    v2 = 88;
    v3 = qword_108;
    do
    {
      if ( *(_BYTE *)(v3 + v2) == 1 )
      {
        device_destroy(qword_F8, dword_100 & 0xFFF00000 | (unsigned int)v1);
        v3 = qword_108;
        v0 = dword_104;
      }
      ++v1;
      v2 += 456;
    }
    while ( v1 < v0 );
  }
  class_destroy(qword_F8);
  cdev_del(&g_rdbg_instance);
  unregister_chrdev_region((unsigned int)dword_100, 1);
  return kfree(qword_108);
}
