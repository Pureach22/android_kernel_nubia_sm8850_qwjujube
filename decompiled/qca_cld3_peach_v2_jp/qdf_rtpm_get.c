__int64 __fastcall qdf_rtpm_get(unsigned __int8 a1, unsigned int a2)
{
  unsigned int v2; // w1

  if ( a2 > 3 )
    v2 = 12;
  else
    v2 = dword_A2FA28[a2];
  if ( a1 >= 7u )
    a1 = 11;
  return hif_rtpm_get(a1, v2);
}
