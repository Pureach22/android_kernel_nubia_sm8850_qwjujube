__int64 __fastcall msm_vidc_decoder_persist_size_iris4(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x9
  unsigned int v3; // w19
  __int64 v4; // x8
  __int64 v5; // x9
  unsigned __int64 v6; // x10
  __int64 v7; // x12
  __int64 v8; // x11
  __int64 v9; // x8
  __int64 v10; // x13
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x8

  v1 = *(_DWORD *)(a1 + 312);
  v2 = *(_QWORD *)(a1 + 8720);
  if ( v1 > 7 )
  {
    if ( v1 == 8 )
    {
LABEL_10:
      if ( v2 )
        v3 = 2076928;
      else
        v3 = 733440;
      goto LABEL_29;
    }
    if ( v1 != 16 )
    {
      if ( v1 == 64 )
      {
        v3 = 475392;
        goto LABEL_29;
      }
      goto LABEL_16;
    }
    v3 = 2021376;
    if ( *(_QWORD *)(a1 + 34424) )
    {
      v4 = *(_QWORD *)(a1 + 17104);
      v5 = *(_QWORD *)(a1 + 17608);
      v6 = v4 + 63;
      v7 = v5 + 63;
      if ( v4 + 63 < 0 )
        v6 = v4 + 126;
      v8 = v4 + 127;
      if ( v7 < 0 )
        v7 = v5 + 126;
      v9 = v4 + 254;
      v10 = v5 + 127;
      if ( v8 >= 0 )
        v9 = v8;
      v11 = v5 + 254;
      v12 = v9 >> 7;
      if ( v10 >= 0 )
        v11 = v10;
      v13 = 2816 * v12 * (v11 >> 7);
      if ( (__int64)(((v6 >> 6) * ((unsigned __int64)v7 >> 6)) << 9) > v13 )
        LODWORD(v13) = ((unsigned int)(v6 >> 6) * (unsigned int)((unsigned __int64)v7 >> 6)) << 9;
      v3 = (32 * v13 + 2021631) & 0xFFFFF800;
    }
  }
  else
  {
    if ( v1 != 1 )
    {
      if ( v1 != 2 )
      {
        if ( v1 == 4 )
        {
          v3 = 9277184;
          goto LABEL_29;
        }
LABEL_16:
        v3 = 0;
        goto LABEL_29;
      }
      goto LABEL_10;
    }
    if ( v2 )
      v3 = 2152960;
    else
      v3 = 809472;
  }
LABEL_29:
  if ( a1 && (msm_vidc_debug & 4) != 0 )
    printk(&unk_8FA63, "low ", a1 + 340, "msm_vidc_decoder_persist_size_iris4", v3);
  return v3;
}
