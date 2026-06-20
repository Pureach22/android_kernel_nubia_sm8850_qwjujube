__int64 __fastcall ipa3_compat_wan_ioctl(__int64 a1, int a2, unsigned int a3)
{
  if ( (unsigned int)(a2 + 1073452800) <= 8 && ((0x1FBu >> a2) & 1) != 0 )
    return ipa3_wan_ioctl(a1, dword_1E49C0[a2 + 1073452800], a3);
  else
    return -515;
}
