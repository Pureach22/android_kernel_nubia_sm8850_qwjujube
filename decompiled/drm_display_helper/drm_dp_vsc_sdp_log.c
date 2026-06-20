__int64 __fastcall drm_dp_vsc_sdp_log(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  const char *v5; // x2
  __int64 v6; // x8
  const char *v7; // x2
  int v8; // w9
  char **v9; // x9
  int v10; // w8
  const char *v11; // x9
  const char *v12; // x2
  __int64 v13; // x8
  const char *v14; // x2

  drm_printf(a1, "DP SDP: VSC, revision %u, length %u\n", *(unsigned __int8 *)(a2 + 1), *(unsigned __int8 *)(a2 + 2));
  v4 = *(unsigned int *)(a2 + 4);
  if ( (unsigned int)v4 <= 6 )
  {
    if ( (_DWORD)v4 == 6 )
      v5 = "Reserved";
    else
      v5 = (const char *)*(&off_1D678 + v4);
  }
  else
  {
    v5 = "Invalid";
  }
  drm_printf(a1, "    pixelformat: %s\n", v5);
  v6 = *(unsigned int *)(a2 + 4);
  v7 = "Invalid";
  if ( (unsigned int)v6 <= 6 )
  {
    v8 = *(_DWORD *)(a2 + 8);
    v7 = "Invalid";
    if ( v8 <= 3 )
    {
      if ( v8 > 1 )
      {
        if ( v8 == 2 )
        {
          if ( (unsigned int)v6 < 4 )
          {
            v9 = off_1D6F8;
            goto LABEL_33;
          }
        }
        else if ( (unsigned int)v6 < 4 )
        {
          v9 = off_1D718;
          goto LABEL_33;
        }
      }
      else if ( v8 )
      {
        if ( v8 != 1 )
          goto LABEL_35;
        if ( (unsigned int)v6 < 4 )
        {
          v9 = off_1D6D8;
LABEL_33:
          v7 = v9[v6];
          goto LABEL_35;
        }
      }
      else if ( (_DWORD)v6 != 6 )
      {
        v9 = off_1D6A8;
        goto LABEL_33;
      }
      goto LABEL_34;
    }
    if ( v8 <= 5 )
    {
      if ( v8 == 4 )
      {
        if ( (unsigned int)v6 < 4 )
        {
          v9 = off_1D738;
          goto LABEL_33;
        }
      }
      else if ( (unsigned int)v6 < 4 )
      {
        v9 = off_1D758;
        goto LABEL_33;
      }
      goto LABEL_34;
    }
    if ( v8 == 6 )
    {
      if ( (unsigned int)v6 < 4 )
      {
        v9 = off_1D778;
        goto LABEL_33;
      }
LABEL_34:
      v7 = "Reserved";
      goto LABEL_35;
    }
    if ( v8 == 7 )
    {
      if ( (unsigned int)(v6 - 1) >= 3 )
        v7 = "Reserved";
      else
        v7 = "BT.2020 YCC";
    }
  }
LABEL_35:
  drm_printf(a1, "    colorimetry: %s\n", v7);
  drm_printf(a1, "    bpc: %u\n", *(_DWORD *)(a2 + 12));
  v10 = *(_DWORD *)(a2 + 16);
  v11 = "CTA range";
  if ( v10 != 1 )
    v11 = "Invalid";
  if ( v10 )
    v12 = v11;
  else
    v12 = "VESA range";
  drm_printf(a1, "    dynamic range: %s\n", v12);
  v13 = *(unsigned int *)(a2 + 20);
  if ( (unsigned int)v13 > 4 )
    v14 = "Reserved";
  else
    v14 = off_1D798[v13];
  return drm_printf(a1, "    content type: %s\n", v14);
}
