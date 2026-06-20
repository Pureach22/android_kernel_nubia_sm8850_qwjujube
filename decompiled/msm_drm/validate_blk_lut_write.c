__int64 __fastcall validate_blk_lut_write(unsigned int *a1)
{
  __int64 result; // x0
  unsigned int v3; // w1
  unsigned int v4; // w2
  unsigned int v5; // w8

  result = validate_write_reg(a1);
  if ( !(_DWORD)result )
  {
    v3 = a1[12];
    v4 = a1[13];
    if ( v3 <= 1 && v4 <= 3 && (v5 = a1[14], v5 <= 6) && ((1 << v5) & 0x68) != 0 )
    {
      return 0;
    }
    else
    {
      _drm_err("invalid table_sel %d block_sel %d trans_size %d\n", v3, v4, a1[14]);
      return 4294967274LL;
    }
  }
  return result;
}
