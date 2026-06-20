__int64 __fastcall get_pkt_index(__int64 a1)
{
  int v1; // w8
  unsigned int v2; // w8
  unsigned int v3; // w8
  int v4; // w9
  int v5; // w10
  int v6; // w9

  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(cvp_driver + 48) + 264LL) + 56LL) != 1 )
  {
    if ( a1 )
    {
      v3 = *(_DWORD *)(a1 + 4);
      v4 = -18886506;
      v5 = (v3 >> 12) & 1;
      if ( (v3 & 0x2000) == 0 || !v5 )
      {
        if ( (v3 & 0x2000) == 0 || v5 )
        {
          if ( ((v3 >> 12) & 1) != 0 )
            v6 = (v3 >> 13) & 1;
          else
            v6 = 1;
          if ( v6 )
            v4 = -18874368;
          else
            v4 = -18878414;
        }
        else
        {
          v4 = -18882460;
        }
      }
      v2 = v3 + v4;
      if ( v2 <= 0x1FF )
        goto LABEL_19;
    }
    return 4294967274LL;
  }
  if ( !a1 )
    return 4294967274LL;
  v1 = *(_DWORD *)(a1 + 4);
  if ( (unsigned int)(v1 - 67179008) < 0xFFFFFE00 )
    return 4294967274LL;
  v2 = v1 - 67178496;
LABEL_19:
  if ( *(_DWORD *)(cvp_hfi_defs + 84LL * v2) )
    return v2;
  else
    return 4294967274LL;
}
