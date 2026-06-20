__int64 __fastcall sde_hw_setup_split_pipe(__int64 result, unsigned __int8 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  unsigned int v4; // w20
  int v5; // w9
  int v6; // w8
  int v7; // w9
  __int64 v8; // x8
  __int64 v10; // x21

  if ( result && a2 )
  {
    v2 = *(_QWORD *)(result + 40);
    if ( (*(_QWORD *)(v2 + 32) & 0x800) != 0 && *a2 == 1 )
    {
      if ( *((_DWORD *)a2 + 1) == 1 )
      {
        v3 = 1LL << *(_DWORD *)(v2 + 64);
        if ( *((_DWORD *)a2 + 3) == 10 )
          v4 = 1LL << *(_DWORD *)(v2 + 64);
        else
          v4 = 4;
        goto LABEL_25;
      }
    }
    else if ( *a2 == 1 )
    {
      v5 = *((_DWORD *)a2 + 2);
      if ( *((_DWORD *)a2 + 1) == 1 )
      {
        v6 = *(_DWORD *)(v2 + 64);
        if ( v5 == 3 )
          v7 = 18;
        else
          v7 = 258;
        v8 = 1LL << v6;
        if ( *((_DWORD *)a2 + 3) == 10 )
          LODWORD(v3) = v7;
        else
          LODWORD(v3) = 4;
        v4 = v3 | v8;
      }
      else
      {
        if ( v5 == 3 )
          LODWORD(v3) = 256;
        else
          LODWORD(v3) = 16;
        if ( v5 == 3 )
          v4 = 16;
        else
          v4 = 256;
      }
      goto LABEL_25;
    }
    LODWORD(v3) = 0;
    v4 = 0;
LABEL_25:
    v10 = result;
    sde_reg_write(result, 0x28u, a2[20], "SSPP_SPARE");
    sde_reg_write(v10, 0x3F0u, v4, "SPLIT_DISPLAY_LOWER_PIPE_CTRL");
    sde_reg_write(v10, 0x2F8u, v3, "SPLIT_DISPLAY_UPPER_PIPE_CTRL");
    return sde_reg_write(v10, 0x2F4u, *a2, "SPLIT_DISPLAY_EN");
  }
  return result;
}
