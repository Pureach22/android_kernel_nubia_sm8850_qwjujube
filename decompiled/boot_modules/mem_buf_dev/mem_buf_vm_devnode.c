__int64 __fastcall mem_buf_vm_devnode(const char **a1)
{
  const char *v1; // x2

  v1 = a1[14];
  if ( !v1 )
    v1 = *a1;
  return kasprintf(3264, "mem_buf_vm/%s", v1);
}
