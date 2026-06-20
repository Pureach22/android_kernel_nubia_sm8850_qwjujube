__int64 __fastcall drm_dp_downstream_debug(__int64 a1, unsigned __int8 *a2, char *a3, __int64 a4, _QWORD *a5)
{
  unsigned __int8 v10; // w24
  char v11; // w25
  const char *v12; // x2
  __int64 result; // x0
  unsigned int v14; // w8
  const char *v15; // x1
  __int64 v16; // x0
  __int64 v17; // x2
  unsigned __int8 v18; // w8
  int v19; // w2
  int v20; // w8
  __int64 v21; // x0
  int v22; // w9
  __int64 v23; // x0
  unsigned __int8 v24[4]; // [xsp+Ch] [xbp-14h] BYREF
  char v25[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a2[5];
  v11 = *a3;
  *(_WORD *)v24 = 0;
  if ( (v10 & 1) != 0 )
    v12 = "yes";
  else
    v12 = "no";
  result = seq_printf(a1, "\tDP branch device present: %s\n", v12);
  if ( (v10 & 1) == 0 )
    goto LABEL_47;
  v14 = v11 & 7;
  if ( v14 > 2 )
  {
    if ( (v11 & 7u) > 4 )
    {
      if ( v14 != 5 )
      {
        if ( v14 == 6 )
        {
          v15 = "\t\tType: Wireless\n";
          v16 = a1;
          v17 = 17;
          goto LABEL_24;
        }
        goto LABEL_18;
      }
      v15 = "\t\tType: DP++\n";
    }
    else
    {
      if ( v14 != 3 )
      {
        if ( v14 == 4 )
        {
          v15 = "\t\tType: others without EDID support\n";
          v16 = a1;
          v17 = 36;
          goto LABEL_24;
        }
LABEL_18:
        v15 = "\t\tType: N/A\n";
        goto LABEL_23;
      }
      v15 = "\t\tType: HDMI\n";
    }
    v16 = a1;
    v17 = 13;
    goto LABEL_24;
  }
  if ( (v11 & 7) == 0 )
  {
    v15 = "\t\tType: DisplayPort\n";
    v16 = a1;
    v17 = 20;
    goto LABEL_24;
  }
  if ( v14 == 1 )
  {
    v15 = "\t\tType: VGA\n";
    goto LABEL_23;
  }
  if ( v14 != 2 )
    goto LABEL_18;
  v15 = "\t\tType: DVI\n";
LABEL_23:
  v16 = a1;
  v17 = 12;
LABEL_24:
  seq_write(v16, v15, v17);
  *(_DWORD *)&v25[3] = 0;
  *(_DWORD *)v25 = 0;
  drm_dp_dpcd_read(a5, 0x503u, (__int64)v25, 6);
  seq_printf(a1, "\t\tID: %s\n", v25);
  if ( (int)drm_dp_dpcd_read(a5, 0x509u, (__int64)v24, 1) >= 1 )
    seq_printf(a1, "\t\tHW: %d.%d\n", v24[0] >> 4, v24[0] & 0xF);
  result = drm_dp_dpcd_read(a5, 0x50Au, (__int64)v24, 2);
  if ( (int)result >= 1 )
    result = seq_printf(a1, "\t\tSW: %d.%d\n", v24[0], v24[1]);
  if ( (v10 & 0x10) != 0 )
  {
    v18 = a2[5];
    if ( (v18 & 1) == 0 )
      goto LABEL_39;
    if ( *a2 < 0x11u )
    {
LABEL_36:
      if ( (v18 & 6) != 4 )
        goto LABEL_39;
      goto LABEL_37;
    }
    if ( (a2[5] & 0x10) == 0
      || (*a3 & 7) != 1
      || !a3[1]
      || (seq_printf(a1, "\t\tMax dot clock: %d kHz\n", 8000 * (unsigned __int8)a3[1]), v18 = a2[5], (v18 & 1) != 0) )
    {
      if ( *a2 <= 0x10u )
        goto LABEL_36;
      v22 = *a3 & 7;
      if ( v22 == 2 )
      {
        if ( (v18 & 0x10) == 0 )
        {
LABEL_37:
          v19 = 165000;
LABEL_38:
          seq_printf(a1, "\t\tMax TMDS clock: %d kHz\n", v19);
          goto LABEL_39;
        }
      }
      else
      {
        if ( v22 != 3 )
        {
          if ( v22 != 5 )
            goto LABEL_39;
          v23 = drm_edid_raw(a4);
          if ( v23 )
          {
            if ( *(unsigned __int8 *)(v23 + 19) >= 4u && (*(_BYTE *)(v23 + 20) & 0x87) == 0x85 )
              goto LABEL_39;
          }
        }
        if ( (a2[5] & 0x10) == 0 )
        {
          v19 = 300000;
          goto LABEL_38;
        }
      }
      if ( a3[1] )
      {
        v19 = 2500 * (unsigned __int8)a3[1];
        goto LABEL_38;
      }
    }
LABEL_39:
    if ( (a2[5] & 1) == 0 )
      goto LABEL_45;
    if ( *a2 > 0x10u )
    {
      v20 = *a3 & 7;
      if ( (unsigned int)(v20 - 2) >= 2
        && (v20 != 5
         || (v21 = drm_edid_raw(a4)) != 0
         && *(unsigned __int8 *)(v21 + 19) >= 4u
         && (*(_BYTE *)(v21 + 20) & 0x87) == 0x85) )
      {
LABEL_45:
        result = drm_dp_downstream_max_bpc(a2, a3, a4);
        if ( (_DWORD)result )
          result = seq_printf(a1, "\t\tMax bpc: %d\n", result);
        goto LABEL_47;
      }
    }
    else if ( (a2[5] & 6) != 4 )
    {
      goto LABEL_45;
    }
    seq_printf(a1, "\t\tMin TMDS clock: %d kHz\n", 25000);
    goto LABEL_45;
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
