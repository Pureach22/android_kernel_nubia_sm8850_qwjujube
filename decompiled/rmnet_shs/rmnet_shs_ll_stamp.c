__int64 __fastcall rmnet_shs_ll_stamp(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int16 v7; // w8
  __int64 v8; // x19
  unsigned __int8 v9; // w9

  v7 = *(_WORD *)(a2 + 212);
  v8 = result;
  if ( v7 )
  {
    v9 = *(_BYTE *)(a2 + 214);
    if ( !(_BYTE)v7 )
      return result;
  }
  else
  {
    v9 = byte_19498;
    if ( !byte_19497 )
      return result;
  }
  result = rmnet_shs_form_hash(*(unsigned __int16 *)(a2 + 208), v9, *(_DWORD *)(a2 + 192), 0, a5, a6, a7);
  *(_DWORD *)(v8 + 152) = result;
  return result;
}
