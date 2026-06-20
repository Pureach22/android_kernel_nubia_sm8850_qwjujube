__int64 __fastcall ucfg_fwol_get_ofdm_scrambler_seed(__int64 a1, _BYTE *a2)
{
  __int64 psoc_obj; // x0
  char v4; // w8
  __int64 result; // x0

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v4 = *(_BYTE *)(psoc_obj + 1317);
    result = 0;
  }
  else
  {
    v4 = 0;
    result = 16;
  }
  *a2 = v4;
  return result;
}
