__int64 __fastcall sde_kms_info_add_list(__int64 result, char *a2, __int64 a3, unsigned __int64 a4)
{
  unsigned int *v6; // x23
  __int64 v7; // x19
  __int64 v8; // x8
  int v9; // w0
  unsigned int v10; // w8
  unsigned int v11; // w8
  unsigned __int64 v12; // x9
  unsigned int v13; // w24
  int v14; // w0
  unsigned int v15; // w9
  unsigned int v16; // w8

  if ( result && a2 && a3 && a4 )
  {
    v6 = (unsigned int *)(result + 0x4000);
    v7 = result;
    v8 = *(unsigned int *)(result + 0x4000);
    if ( (unsigned int)v8 > 0x4000 )
      goto LABEL_18;
    v9 = snprintf((char *)(result + v8), (unsigned int)(0x4000 - v8), "%s=", a2);
    v10 = *v6;
    *((_BYTE *)v6 + 8) = 1;
    v11 = v10 + v9;
    if ( v11 >= 0x4000 )
      v11 = v6[1];
    else
      v6[1] = v11;
    v12 = 0;
    v13 = 1;
    do
    {
      if ( v11 > 0x4000 )
        goto LABEL_18;
      v14 = scnprintf(v7 + v11, 0x4000 - *v6, "%d ", *(_DWORD *)(a3 + 4 * v12));
      v11 = v6[1];
      v15 = v11 + v14;
      if ( !((v11 + v14) >> 14) )
      {
        v11 += v14;
        v6[1] = v15;
        *((_BYTE *)v6 + 8) = 0;
      }
      v12 = v13++;
    }
    while ( v12 < a4 );
    if ( v11 > 0x4000 )
    {
LABEL_18:
      __break(0x5512u);
      __ldxp((unsigned __int128 *)a2);
      JUMPOUT(0x10C5B0);
    }
    result = snprintf((char *)(v7 + v11), 0x4000 - v11, "\n");
    v16 = v6[1] + result;
    if ( !(v16 >> 14) )
      *v6 = v16;
  }
  return result;
}
