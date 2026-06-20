__int64 __fastcall sub_48BE30(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  int v7; // w23
  int v8; // w24

  *(_DWORD *)(a7 + 148) = v8;
  *(_DWORD *)(a7 + 152) = v7;
  return wma_process_update_rx_nss(a1, a2, a3, a4, a5, a6, a7 + 148);
}
