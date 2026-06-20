__int64 __fastcall cpu_mpam_schemata_store(int a1, char *a2, __int64 a3)
{
  char *v5; // x1
  char *v6; // x3
  char *i; // [xsp+8h] [xbp-18h] BYREF
  char *stringp[2]; // [xsp+10h] [xbp-10h] BYREF

  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  stringp[0] = a2;
  for ( i = strsep(stringp, ";"); i; i = strsep(stringp, ";") )
  {
    v6 = strsep(&i, ":");
    if ( i )
      v5 = v6;
    else
      v5 = nullptr;
    cpu_mpam_set_by_schemata(a1, v5);
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
