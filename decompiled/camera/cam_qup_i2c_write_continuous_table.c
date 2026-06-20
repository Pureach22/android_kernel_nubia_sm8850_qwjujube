__int64 __fastcall cam_qup_i2c_write_continuous_table(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v3; // w8

  v3 = -22;
  if ( !a1 || !a2 )
    return v3;
  if ( (unsigned int)(*(_DWORD *)(a2 + 12) - 5) < 0xFFFFFFFC )
    return 4294967274LL;
  if ( (unsigned int)(*(_DWORD *)(a2 + 16) - 5) < 0xFFFFFFFC )
    return 4294967274LL;
  if ( (unsigned int)a3 - 1 <= 1 )
    return (unsigned int)cam_qup_i2c_write_burst(a1, a2);
  return 0;
}
