__int64 __fastcall sde_hw_intf_get_vsync_info(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  int v5; // w0
  int v6; // w8
  unsigned int v7; // w0
  int v8; // w21
  __int64 v9; // x1
  int v10; // w8

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = sde_reg_read(a1, 660);
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x10LL) != 0 )
      v6 = v5;
    else
      v6 = (unsigned __int16)v5;
    a2[2] = v6;
    v7 = sde_reg_read(a1, 664);
    a2[3] = HIWORD(v7);
    a2[4] = (unsigned __int16)v7;
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x10) != 0 )
      a2[4] |= (unsigned int)sde_reg_read(a1, 732) << 16;
    a2[5] = sde_reg_read(a1, 688);
    v8 = sde_reg_read(a1, 692);
    if ( (((unsigned int)sde_reg_read(a1, 4) | v8) & 0x80000000) != 0
      && (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 33LL) & 8) != 0 )
    {
      v9 = 164;
    }
    else
    {
      v9 = 172;
    }
    v10 = sde_reg_read(a1, v9);
    result = 0;
    a2[6] = v10;
  }
  return result;
}
