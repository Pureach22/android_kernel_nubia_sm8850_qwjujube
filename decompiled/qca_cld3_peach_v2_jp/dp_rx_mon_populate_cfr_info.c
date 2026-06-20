__int64 __fastcall dp_rx_mon_populate_cfr_info(__int64 result, __int64 a2, __int64 a3)
{
  if ( *(_BYTE *)(result + 95040) == 1 )
  {
    *(_BYTE *)(a3 + 316) = *(_BYTE *)(a2 + 14216);
    *(_BYTE *)(a3 + 317) = *(_BYTE *)(a2 + 14217);
    *(_BYTE *)(a3 + 318) = *(_BYTE *)(a2 + 14218);
    *(_BYTE *)(a3 + 319) = *(_BYTE *)(a2 + 14219);
    *(_BYTE *)(a3 + 320) = *(_BYTE *)(a2 + 14220);
    *(_BYTE *)(a3 + 321) = *(_BYTE *)(a2 + 14221);
    *(_DWORD *)(a3 + 324) = *(_DWORD *)(a2 + 14224);
    *(_WORD *)(a3 + 328) = *(_WORD *)(a2 + 14228);
    *(_DWORD *)(a3 + 332) = *(_DWORD *)(a2 + 14232);
    *(_DWORD *)(a3 + 336) = *(_DWORD *)(a2 + 14236);
    *(_DWORD *)(a3 + 340) = *(_DWORD *)(a2 + 14240);
    *(_DWORD *)(a3 + 344) = *(_DWORD *)(a2 + 14244);
    *(_DWORD *)(a3 + 348) = *(_DWORD *)(a2 + 14248);
    *(_DWORD *)(a3 + 352) = *(_DWORD *)(a2 + 14252);
    *(_DWORD *)(a3 + 356) = *(_DWORD *)(a2 + 14256);
  }
  return result;
}
