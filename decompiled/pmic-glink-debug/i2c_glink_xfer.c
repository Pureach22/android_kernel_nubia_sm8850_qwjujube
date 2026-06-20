__int64 __fastcall i2c_glink_xfer(__int64 a1, __int64 a2, int a3)
{
  __int64 *v3; // x8
  int v4; // w19
  __int64 v5; // x21
  unsigned int v6; // w22
  int v8; // w23
  unsigned __int16 *v9; // x9
  __int64 v10; // x8
  unsigned __int16 *v11; // x10
  __int64 v12; // x2
  __int64 v13; // x24
  __int64 v14; // x3
  unsigned __int16 *v15; // x11
  int regs; // w0

  v3 = *(__int64 **)(a1 + 264);
  if ( !v3 )
    return 4294967277LL;
  v4 = a3;
  if ( a3 >= 1 )
  {
    v5 = *v3;
    v6 = *((_DWORD *)v3 + 312);
    v8 = 0;
    while ( 1 )
    {
      v9 = (unsigned __int16 *)(a2 + 16LL * v8);
      v10 = v9[2];
      if ( (unsigned int)v10 < 2 )
        return 4294967274LL;
      v11 = *((unsigned __int16 **)v9 + 1);
      v12 = *v9;
      v13 = v8 + 1LL;
      v14 = bswap32(*v11) >> 16;
      if ( (int)v13 < v4
        && (v15 = (unsigned __int16 *)(a2 + 16 * v13), (v15[1] & 1) != 0)
        && (_DWORD)v12 == *v15
        && v15[2] )
      {
        regs = pmic_glink_debug_read_regs(v5, v6);
      }
      else
      {
        if ( (_DWORD)v10 == 2 || (v9[1] & 1) != 0 )
          return 4294967274LL;
        regs = pmic_glink_debug_write_regs(v5, v6, v12, v14, v11 + 1, v10 - 2);
        LODWORD(v13) = v8;
      }
      if ( regs )
        break;
      v8 = v13 + 1;
      if ( (int)v13 + 1 >= v4 )
        return (unsigned int)v4;
    }
    v4 = regs;
    dev_err(*(_QWORD *)(v5 + 8), "%s failed\n", "i2c_glink_xfer");
  }
  return (unsigned int)v4;
}
