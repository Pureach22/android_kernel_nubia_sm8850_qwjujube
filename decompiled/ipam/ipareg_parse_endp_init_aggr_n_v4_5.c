void __fastcall ipareg_parse_endp_init_aggr_n_v4_5(__int64 a1, __int64 a2, unsigned int a3)
{
  _DWORD *v3; // x8

  *(_QWORD *)(a2 + 20) = 0;
  *(_QWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 4) = (a3 >> 2) & 7;
  *(_DWORD *)(a2 + 8) = (a3 >> 5) & 0x3F;
  *(_DWORD *)a2 = (a3 & 3) == 1;
  *(_BYTE *)(a2 + 26) = (a3 >> 12) & 0x1F;
  v3 = (_DWORD *)ipahal_ctx;
  *(_DWORD *)(a2 + 16) = (a3 >> 17) & 0x3F;
  *(_DWORD *)(a2 + 20) = (a3 >> 26) & 1;
  *(_BYTE *)(a2 + 24) = (a3 & 0x800000) != 0;
  *(_BYTE *)(a2 + 25) = (a3 & 0x8000000) != 0;
  if ( *v3 >= 0x18u )
    *(_BYTE *)(a2 + 27) = (a3 & 0x10000000) != 0;
}
