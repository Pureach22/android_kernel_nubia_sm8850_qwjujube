unsigned __int64 __fastcall synx_util_map_import_params_to_create(unsigned __int64 result, unsigned __int64 a2)
{
  int v2; // w8

  if ( result && result <= 0xFFFFFFFFFFFFF000LL && a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v2 = *(_DWORD *)(result + 8);
    if ( (v2 & 2) != 0 )
    {
      *(_DWORD *)(a2 + 24) |= 2u;
      v2 = *(_DWORD *)(result + 8);
      if ( (v2 & 1) == 0 )
      {
LABEL_7:
        if ( (v2 & 8) == 0 )
          return result;
        goto LABEL_8;
      }
    }
    else if ( (v2 & 1) == 0 )
    {
      goto LABEL_7;
    }
    *(_DWORD *)(a2 + 24) |= 1u;
    if ( (*(_DWORD *)(result + 8) & 8) == 0 )
      return result;
LABEL_8:
    *(_DWORD *)(a2 + 24) |= 4u;
  }
  return result;
}
