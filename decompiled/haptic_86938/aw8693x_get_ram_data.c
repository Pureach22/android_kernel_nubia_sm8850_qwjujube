__int64 __fastcall aw8693x_get_ram_data(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int i; // w22
  unsigned int v6; // w8
  unsigned int v7; // w21

  v2 = *(_DWORD *)(a1 + 1104);
  if ( !v2 )
    return 0;
  for ( i = 0; i < v2; i += v7 )
  {
    v6 = v2 - i;
    if ( v6 >= 0x400 )
      v7 = 1024;
    else
      v7 = v6;
    i2c_r_bytes(a1, 66, a2 + (int)i, v7);
    v2 = *(_DWORD *)(a1 + 1104);
  }
  return (int)i;
}
