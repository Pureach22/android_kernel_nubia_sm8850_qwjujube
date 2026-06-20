__int64 __fastcall sub_108A00(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int *v4; // x19

  atomic_load(v4);
  return kgsl_ioctl_copy_in(a1, a2, a3, a4);
}
