__int64 __fastcall ucfg_pmo_set_apf_mode(__int64 a1, unsigned int a2, unsigned int a3)
{
  if ( a1 )
    return pmo_set_apf_mode(a1, a2, a3);
  else
    return 4;
}
