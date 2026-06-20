__int64 __fastcall get_pkt_fenceoverride(__int64 a1)
{
  unsigned int v2; // w8
  int v3; // w9
  int v4; // w10
  int v5; // w9

  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(cvp_driver + 48) + 264LL) + 56LL) == 1 )
    return *(unsigned __int8 *)(cvp_hfi_defs + 84LL * (unsigned int)(*(_DWORD *)(a1 + 4) - 67178496) + 80);
  v2 = *(_DWORD *)(a1 + 4);
  v3 = -18886506;
  v4 = (v2 >> 12) & 1;
  if ( (v2 & 0x2000) == 0 || !v4 )
  {
    if ( (v2 & 0x2000) == 0 || v4 )
    {
      if ( ((v2 >> 12) & 1) != 0 )
        v5 = (v2 >> 13) & 1;
      else
        v5 = 1;
      if ( v5 )
        v3 = -18874368;
      else
        v3 = -18878414;
    }
    else
    {
      v3 = -18882460;
    }
  }
  return *(unsigned __int8 *)(cvp_hfi_defs + 84LL * (int)(v2 + v3) + 80);
}
