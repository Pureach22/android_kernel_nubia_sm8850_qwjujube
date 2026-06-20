__int64 __fastcall gh_dbl_cleanup(__int64 result)
{
  unsigned int v1; // w19
  __int64 v2; // x20

  if ( (result & 0x80000000) == 0 )
  {
    v1 = result;
    v2 = 12LL * (unsigned int)result;
    while ( 1 )
    {
      if ( v1 >= 0xB )
        goto LABEL_8;
      if ( (unsigned __int64)(v2 * 8 - 913) < 0xFFFFFFFFFFFFFC3FLL )
        break;
      result = kfree(gh_dbl_cap_table[v2 + 6]);
      v2 -= 12;
      if ( v2 == -12 )
        return result;
    }
    __break(1u);
LABEL_8:
    __break(0x5512u);
    JUMPOUT(0x70FC);
  }
  return result;
}
