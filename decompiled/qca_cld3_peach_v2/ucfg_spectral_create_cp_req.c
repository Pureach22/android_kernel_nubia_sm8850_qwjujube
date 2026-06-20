__int64 __fastcall ucfg_spectral_create_cp_req(__int64 a1, _DWORD *a2, unsigned int a3)
{
  int v3; // w9
  __int64 result; // x0

  v3 = *(unsigned __int8 *)(a1 + 4);
  if ( v3 == 37 )
  {
    result = 16;
    if ( a2 && a3 >= 4 )
    {
      result = 0;
      *(_DWORD *)(a1 + 8) = *a2;
    }
  }
  else if ( v3 == 30 )
  {
    result = 16;
    if ( a2 )
    {
      if ( a3 >= 0x50 )
      {
        qdf_mem_copy((void *)(a1 + 8), a2, 0x50u);
        return 0;
      }
    }
  }
  else
  {
    return 0;
  }
  return result;
}
