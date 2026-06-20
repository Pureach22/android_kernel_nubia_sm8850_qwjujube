__int64 __fastcall kgsl_pwrctrl_init_sysfs(__int64 a1)
{
  __int64 result; // x0

  result = sysfs_create_files(*(_QWORD *)a1, pwrctrl_attr_list);
  if ( !(_DWORD)result )
  {
    if ( (*(_BYTE *)(a1 + 13052) & 2) != 0 )
      return sysfs_create_files(a1 + 12992, gpu_sysfs_attr_list);
    else
      return 0;
  }
  return result;
}
