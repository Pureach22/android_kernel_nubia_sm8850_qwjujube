__int64 __fastcall qdf_rtpm_register(unsigned int a1, __int64 a2)
{
  unsigned int v2; // w0

  if ( a1 > 3 )
    v2 = 12;
  else
    v2 = dword_B35888[a1];
  return hif_rtpm_register(v2, a2);
}
