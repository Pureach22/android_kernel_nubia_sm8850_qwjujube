__int64 __fastcall cnss_bus_dev_to_bus_priv(__int64 result)
{
  unsigned __int16 **v1; // x8
  unsigned __int16 *v2; // x8
  int v3; // w9
  int v4; // w8
  bool v5; // zf

  if ( result )
  {
    v1 = *(unsigned __int16 ***)(result + 128);
    if ( v1 && ((v2 = *v1, v3 = *v2, v4 = *((unsigned __int8 *)v2 + 2), v3 == 25456) ? (v5 = v4 == 105) : (v5 = 0), v5) )
      return *(_QWORD *)(result + 152);
    else
      return 0;
  }
  return result;
}
