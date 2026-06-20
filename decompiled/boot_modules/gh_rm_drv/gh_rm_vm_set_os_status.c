unsigned __int64 __fastcall gh_rm_vm_set_os_status(char a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x19
  unsigned int v4; // w20

  result = gh_rm_vm_get_status(0);
  if ( result )
  {
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      *(_BYTE *)(result + 1) = a1;
      v3 = result;
      v4 = gh_rm_vm_set_status(*(_DWORD *)result);
      kfree(v3);
      return v4;
    }
  }
  return result;
}
