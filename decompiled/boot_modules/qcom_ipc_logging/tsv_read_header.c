__int64 __fastcall tsv_read_header(__int64 result, _WORD *dest)
{
  __int64 v2; // x8
  __int64 v3; // x8
  unsigned int v4; // w8
  __int64 v5; // x9
  __int64 v6; // x19

  v2 = *(int *)(result + 260);
  if ( (unsigned __int64)(v2 - 254) > 0xFFFFFFFFFFFFFEFFLL )
  {
    if ( (unsigned int)v2 <= 0xFF )
    {
      v3 = *(unsigned int *)(result + 260);
      if ( (unsigned int)v3 <= 0xFF )
      {
        *dest = *(_WORD *)(result + 2 + v3);
        *(_DWORD *)(result + 260) += 2;
        return result;
      }
    }
LABEL_8:
    __break(0x5512u);
    JUMPOUT(0x6C00);
  }
  __break(0x800u);
  v4 = *(_DWORD *)(result + 260);
  if ( v4 >= 0x100 )
    goto LABEL_8;
  v5 = *(unsigned int *)(result + 260);
  if ( (unsigned int)v5 > 0xFF )
    goto LABEL_8;
  v6 = result;
  memcpy(dest, (const void *)(result + 2 + v5), (int)(254 - v4));
  *(_DWORD *)(v6 + 260) = 254;
  return v6;
}
