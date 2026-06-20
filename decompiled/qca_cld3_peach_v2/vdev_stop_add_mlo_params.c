__int64 __fastcall vdev_stop_add_mlo_params(__int64 a1, __int64 a2)
{
  int v2; // w8

  if ( (*(_BYTE *)(a2 + 1) & 1) != 0 )
  {
    v2 = *(_DWORD *)(a1 + 8);
    *(_QWORD *)a1 = 0x4BB000400120008LL;
    *(_DWORD *)(a1 + 8) = v2 & 0xFFFFDFFF;
    *(_DWORD *)(a1 + 8) = v2 & 0xFFFFDFFF | ((*(_BYTE *)(a2 + 1) & 1) << 13);
    return a1 + 12;
  }
  else
  {
    *(_DWORD *)a1 = 1179648;
    return a1 + 4;
  }
}
