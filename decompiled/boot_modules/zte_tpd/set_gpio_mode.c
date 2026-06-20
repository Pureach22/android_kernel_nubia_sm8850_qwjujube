__int64 __fastcall set_gpio_mode(unsigned int a1)
{
  __int64 (__fastcall *v1)(__int64, __int64); // x9
  __int64 v2; // x1
  __int64 v3; // x0

  v1 = *(__int64 (__fastcall **)(__int64, __int64))(tpd_cdev + 3488);
  if ( !v1 )
    return 4294967291LL;
  v2 = a1;
  v3 = tpd_cdev;
  if ( *((_DWORD *)v1 - 1) != -506053183 )
    __break(0x8229u);
  return v1(v3, v2);
}
