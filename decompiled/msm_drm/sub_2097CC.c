__int64 sub_2097CC()
{
  __int64 v0; // x25

  if ( !v0 )
    JUMPOUT(0x19C234);
  return msm_ioctl_gem_madvise();
}
