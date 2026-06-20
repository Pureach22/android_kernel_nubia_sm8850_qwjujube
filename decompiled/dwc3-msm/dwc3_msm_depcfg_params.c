__int64 __fastcall dwc3_msm_depcfg_params(__int64 result, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x12
  int v5; // w11
  __int64 v6; // x8
  int v7; // w9
  int v8; // w8
  int v9; // w8

  v2 = *(_QWORD *)(result + 24);
  v3 = *(_QWORD *)(result + 32);
  v4 = *(_QWORD *)(result + 152);
  v5 = (2 * (*(_BYTE *)(v2 + 3) & 3)) & 7 | (8 * (*(_WORD *)(v2 + 4) & 0x7FF));
  v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 368) + 96LL) + 152LL);
  *(_DWORD *)(a2 + 8) = v5;
  if ( *(_DWORD *)(*(_QWORD *)(v4 + 848) + 72LL) >= 5u )
    *(_DWORD *)(a2 + 8) = v5 & 0xFC3FFFFF | ((((*(unsigned __int8 *)(result + 62) >> 2) - 1) & 0xF) << 22);
  if ( v3 && (*(_BYTE *)(v3 + 3) & 0x1F) != 0 && (*(_BYTE *)(v2 + 3) & 3) == 2 )
  {
    *(_DWORD *)(a2 + 4) |= 0x1002000u;
    *(_BYTE *)(result + 204) |= 2u;
  }
  v7 = *(_DWORD *)(a2 + 4) | ((*(_BYTE *)(result + 170) & 0x1F) << 25);
  *(_DWORD *)(a2 + 4) = v7;
  if ( (*(_BYTE *)(result + 204) & 1) != 0 )
    *(_DWORD *)(a2 + 8) |= ((*(unsigned __int8 *)(result + 170) >> 1) & 0x1F) << 17;
  if ( *(unsigned __int8 *)(result + 170) >= 0x20uLL )
  {
    __break(0x5512u);
    return dwc3_core_resize_tx_fifos(result);
  }
  else
  {
    v8 = *(_DWORD *)(v6 + 40LL * *(unsigned __int8 *)(result + 170) + 1280);
    if ( v8 == 3 )
    {
      v9 = *(_DWORD *)(a2 + 8) | 0x8000;
      *(_DWORD *)(a2 + 4) = v7 | 0xC000;
      *(_DWORD *)(a2 + 8) = v9;
    }
    else if ( v8 == 2 )
    {
      *(_DWORD *)(a2 + 4) = v7 | 0xB00;
    }
  }
  return result;
}
