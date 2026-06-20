__int64 __fastcall provide_qseecom_kernel_fun_ops(__int64 a1)
{
  void *v3; // x9
  void *v4; // x10
  void *v5; // x8
  void *v6; // x11

  if ( a1 )
  {
    v4 = *(void **)(a1 + 16);
    v3 = *(void **)(a1 + 24);
    v6 = *(void **)a1;
    v5 = *(void **)(a1 + 8);
    off_6500 = v4;
    off_6508 = v3;
    qseecom_fun_ops = v6;
    off_64F8 = v5;
    return 0;
  }
  else
  {
    printk(&unk_6492);
    return 0xFFFFFFFFLL;
  }
}
