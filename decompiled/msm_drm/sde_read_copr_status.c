__int64 __fastcall sde_read_copr_status(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  int v5; // w21
  int v6; // w8

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 604LL);
      *a2 = sde_reg_read(a1, v5 + 836);
      a2[1] = sde_reg_read(a1, v5 + 840);
      a2[2] = sde_reg_read(a1, v5 + 844);
      a2[3] = sde_reg_read(a1, v5 + 848);
      a2[4] = sde_reg_read(a1, v5 + 852);
      a2[5] = sde_reg_read(a1, v5 + 856);
      a2[6] = sde_reg_read(a1, v5 + 860);
      a2[7] = sde_reg_read(a1, v5 + 864);
      a2[8] = sde_reg_read(a1, v5 + 868);
      v6 = sde_reg_read(a1, v5 + 872);
      a2[9] = v6;
      return 0;
    }
  }
  return result;
}
