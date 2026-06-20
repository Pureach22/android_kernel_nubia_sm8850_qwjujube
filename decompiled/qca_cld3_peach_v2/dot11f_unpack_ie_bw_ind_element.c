__int64 __fastcall dot11f_unpack_ie_bw_ind_element(__int64 a1, unsigned __int8 *a2, char a3, __int64 a4)
{
  unsigned int v5; // w8
  unsigned __int8 v6; // w10

  if ( *(_BYTE *)a4 )
    return 32;
  *(_BYTE *)a4 = 1;
  if ( !a3
    || (v5 = *a2 & 2,
        v6 = *a2,
        *(_WORD *)(a4 + 1) = *a2 & 1 | (*(unsigned __int8 *)(a4 + 2) << 8) | *a2 & 0xFC | v5,
        a3 == 1)
    || (*(_WORD *)(a4 + 1) = v6 | (a2[1] << 8), a3 == 2)
    || (*(_BYTE *)(a4 + 3) = a2[2], a3 == 3)
    || (*(_BYTE *)(a4 + 4) = a2[3], v5 > (unsigned __int8)(a3 - 4)) )
  {
    *(_BYTE *)a4 = 0;
    return 4;
  }
  else
  {
    qdf_mem_copy((void *)(a4 + 5), a2 + 4, v5);
    return 0;
  }
}
