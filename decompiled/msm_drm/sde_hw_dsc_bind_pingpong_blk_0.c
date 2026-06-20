__int64 __fastcall sde_hw_dsc_bind_pingpong_blk_0(__int64 result, char a2, char a3)
{
  unsigned int v3; // w2

  if ( result )
  {
    if ( (a2 & 1) != 0 )
      v3 = (a3 - 1) & 7;
    else
      v3 = 15;
    return sde_reg_write(result, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 40) + 56LL) + 48LL), v3, "DSC_CTL + idx");
  }
  return result;
}
