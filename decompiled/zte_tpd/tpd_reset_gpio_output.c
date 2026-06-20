__int64 __fastcall tpd_reset_gpio_output(__int64 result)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  v1 = *(__int64 (__fastcall **)(_QWORD))(tpd_cdev + 3320);
  if ( v1 )
  {
    v2 = result & 1;
    if ( *((_DWORD *)v1 - 1) != -1560483463 )
      __break(0x8228u);
    return v1(v2);
  }
  return result;
}
