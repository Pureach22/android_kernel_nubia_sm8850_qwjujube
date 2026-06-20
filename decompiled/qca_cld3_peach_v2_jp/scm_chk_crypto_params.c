__int64 __fastcall scm_chk_crypto_params(
        __int64 a1,
        __int64 a2,
        char a3,
        unsigned __int8 *a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x29
  __int64 v14; // x30
  int v15; // w11
  int v16; // w9
  int v17; // w13
  int v18; // w14
  int v20; // w13
  __int64 v21; // [xsp+58h] [xbp-28h]

  v15 = *(_DWORD *)(a2 + 8);
  v16 = *(_DWORD *)(a1 + 52);
  if ( (*(_DWORD *)(a2 + 4) & *(_DWORD *)(a1 + 48)) == 0 )
    goto LABEL_7;
  if ( (v15 & v16) == 0 )
    goto LABEL_7;
  if ( (*(_DWORD *)(a2 + 20) & *(_DWORD *)(a1 + 44)) == 0 )
    goto LABEL_7;
  v17 = *(_DWORD *)(a1 + 56);
  if ( v17 )
  {
    v18 = *(_DWORD *)(a2 + 12);
    if ( v18 )
    {
      if ( (v18 & v17) == 0 )
        goto LABEL_7;
    }
  }
  if ( (*(_WORD *)a1 & 4) == 0 )
  {
    v20 = *(_DWORD *)(a1 + 24);
    if ( v20 )
    {
      if ( v20 != 2 || (*(_WORD *)(a2 + 152) & 0x80) != 0 )
        goto LABEL_14;
LABEL_7:
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x: fail. adaptive 11r %d Self: AKM %x CIPHER: mc %x uc %x mgmt %x pmf %d AP: AKM %x "
        "CIPHER: mc %x uc %x mgmt %x, RSN caps %x",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "scm_chk_crypto_params",
        a4[1],
        a4[2],
        a4[3],
        a4[6],
        a3 & 1,
        *(_DWORD *)(a1 + 44),
        *(_DWORD *)(a1 + 52),
        *(_DWORD *)(a1 + 48),
        *(_DWORD *)(a1 + 56),
        *(_DWORD *)(a1 + 24),
        *(_DWORD *)(a2 + 20),
        *(_DWORD *)(a2 + 8),
        *(_DWORD *)(a2 + 4),
        *(_DWORD *)(a2 + 12),
        *(unsigned __int16 *)(a2 + 152),
        v21,
        v13,
        v14);
      return 0;
    }
    if ( (*(_WORD *)(a2 + 152) & 0x40) != 0 )
      goto LABEL_7;
  }
LABEL_14:
  *(_DWORD *)(a5 + 12) = v15 & v16;
  *(_DWORD *)(a5 + 8) = *(_DWORD *)(a1 + 48) & *(_DWORD *)(a2 + 4);
  *(_DWORD *)(a5 + 4) = *(_DWORD *)(a1 + 44) & *(_DWORD *)(a2 + 20);
  *(_WORD *)(a5 + 20) = *(_WORD *)(a2 + 152);
  return 1;
}
