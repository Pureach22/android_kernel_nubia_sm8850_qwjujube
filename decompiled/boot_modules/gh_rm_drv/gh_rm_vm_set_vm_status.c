int *__fastcall gh_rm_vm_set_vm_status(char a1)
{
  int *result; // x0
  int *v3; // x19
  unsigned int v4; // w20

  result = (int *)gh_rm_vm_get_status(0);
  if ( result )
  {
    if ( (unsigned __int64)result < 0xFFFFFFFFFFFFF001LL )
    {
      *(_BYTE *)result = a1;
      v3 = result;
      v4 = gh_rm_vm_set_status(*result);
      kfree(v3);
      return (int *)v4;
    }
  }
  return result;
}
