__int64 __fastcall peer_delete_add_mlo_params(__int64 a1, __int64 a2)
{
  int v2; // w8

  if ( *(_DWORD *)(a2 + 4) || (*(_BYTE *)(a2 + 8) & 1) != 0 )
  {
    *(_QWORD *)a1 = 0x43E00080012000CLL;
    v2 = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a1 + 12) = v2 & 0xFFFFDFFF;
    *(_DWORD *)(a1 + 12) = v2 & 0xFFFFDFFF | ((*(_BYTE *)(a2 + 8) & 1) << 13);
    return a1 + 16;
  }
  else
  {
    *(_DWORD *)a1 = 1179648;
    return a1 + 4;
  }
}
