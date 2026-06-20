__int64 __fastcall kgsl_get_memory_usage(char *a1, size_t a2, __int16 a3)
{
  __int64 v3; // x8
  char **v4; // x10

  v3 = 0;
  while ( 1 )
  {
    v4 = memtype_attrs[v3];
    if ( !v4 )
      return snprintf(a1, a2, "VK/others(%3d)", HIBYTE(a3));
    if ( *((_DWORD *)v4 - 2) == HIBYTE(a3) )
      break;
    if ( ++v3 == 23 )
    {
      __break(0x5512u);
      return snprintf(a1, a2, "VK/others(%3d)", HIBYTE(a3));
    }
  }
  return sized_strscpy(a1, *v4);
}
