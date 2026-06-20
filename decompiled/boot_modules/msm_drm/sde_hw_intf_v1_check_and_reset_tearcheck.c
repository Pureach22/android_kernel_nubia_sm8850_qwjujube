__int64 __fastcall sde_hw_intf_v1_check_and_reset_tearcheck(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned int v5; // w21
  unsigned int v6; // w8

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    a2[1] = sde_reg_read(a1, 664);
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x10) != 0 )
      a2[1] |= (unsigned int)sde_reg_read(a1, 732) << 16;
    v5 = sde_reg_read(a1, 672);
    v6 = (unsigned int)sde_reg_read(a1, 656) >> 16;
    a2[2] = v6;
    a2[3] = v5;
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x10) != 0 )
    {
      sde_reg_write(a1, 740, HIWORD(v5), "INTF_TEAR_SYNC_WRCOUNT_EXT");
      v6 = a2[2];
      LOWORD(v5) = *((_WORD *)a2 + 6);
    }
    sde_reg_write(a1, 656, (unsigned __int16)v5 | ((unsigned __int16)v6 << 16), "INTF_TEAR_SYNC_WRCOUNT");
    return 0;
  }
  return result;
}
