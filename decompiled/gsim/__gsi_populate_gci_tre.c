__int64 __fastcall _gsi_populate_gci_tre(__int64 a1, __int64 *a2)
{
  __int64 v2; // x21
  int v4; // w5
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x9
  unsigned int v8; // w23
  __int64 v9; // x25
  __int64 v10; // x24
  unsigned int v11; // w22
  unsigned __int64 v12; // x8
  __int64 result; // x0
  __int64 *v14; // x9

  v2 = *a2;
  if ( (unsigned __int64)*a2 >> 40 )
  {
    dev_err(
      *(_QWORD *)(gsi_ctx + 8),
      "%s:%d chan_hdl=%u add too large=%llx\n",
      "__gsi_populate_gci_tre",
      4236,
      *(unsigned __int8 *)(a1 + 8),
      v2);
    return 4294967274LL;
  }
  else
  {
    v4 = *((_DWORD *)a2 + 3);
    if ( v4 )
    {
      dev_err(
        *(_QWORD *)(gsi_ctx + 8),
        "%s:%d chan_hdl=%u bad RE type=%u\n",
        "__gsi_populate_gci_tre",
        4242,
        *(unsigned __int8 *)(a1 + 8),
        v4);
      return 4294967274LL;
    }
    else
    {
      v6 = *(_QWORD *)(a1 + 168);
      v7 = *(_QWORD *)(a1 + 144);
      if ( v7 > v6 || *(_QWORD *)(a1 + 192) <= v6 )
      {
        __break(0x800u);
        v7 = *(_QWORD *)(a1 + 144);
        v2 = *a2;
      }
      v8 = *(unsigned __int8 *)(a1 + 188);
      v9 = *(_QWORD *)(a1 + 136);
      v10 = *((unsigned __int16 *)a2 + 4);
      v11 = ((int)v6 - (int)v7) / v8;
      v12 = (int)_gsi_get_gci_cookie(a1, v11) & 0xFFFFFFFFFFLL;
      if ( v12 <= (unsigned __int64)*(unsigned __int16 *)(a1 + 190) + 17 )
      {
        v14 = (__int64 *)(v9 + v8 * (unsigned __int64)(unsigned __int16)v11);
        result = 0;
        *v14 = v2 & 0x1FFFFFFFFFFLL | (v10 << 48);
        v14[1] = v12 | 0x8000000000000LL;
        *(_QWORD *)(*(_QWORD *)(a1 + 200) + 16 * v12 + 8) = a2[2];
      }
      else
      {
        return 0xFFFFFFFFLL;
      }
    }
  }
  return result;
}
