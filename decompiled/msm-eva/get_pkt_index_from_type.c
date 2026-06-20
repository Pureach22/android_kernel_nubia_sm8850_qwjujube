__int64 __fastcall get_pkt_index_from_type(unsigned int a1)
{
  __int64 result; // x0
  int v2; // w9
  int v3; // w8
  int v4; // w8

  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(cvp_driver + 48) + 264LL) + 56LL) == 1 )
  {
    if ( a1 - 67179008 >= 0xFFFFFE00 )
    {
      result = a1 - 67178496;
      goto LABEL_16;
    }
  }
  else
  {
    v2 = (a1 >> 12) & 1;
    v3 = -18886506;
    if ( (a1 & 0x2000) == 0 || !v2 )
    {
      if ( (a1 & 0x2000) == 0 || v2 )
      {
        if ( ((a1 >> 12) & 1) != 0 )
          v4 = (a1 >> 13) & 1;
        else
          v4 = 1;
        if ( v4 )
          v3 = -18874368;
        else
          v3 = -18878414;
      }
      else
      {
        v3 = -18882460;
      }
    }
    result = v3 + a1;
    if ( (unsigned int)result <= 0x1FF )
    {
LABEL_16:
      if ( *(_DWORD *)(cvp_hfi_defs + 84LL * (unsigned int)result) )
        return result;
    }
  }
  return 4294967274LL;
}
