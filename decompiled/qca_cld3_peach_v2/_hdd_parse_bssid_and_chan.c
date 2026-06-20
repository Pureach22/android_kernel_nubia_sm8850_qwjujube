__int64 __fastcall hdd_parse_bssid_and_chan(const char **a1, _BYTE *a2, __int64 a3, __int64 a4)
{
  const char *v4; // x22
  const char *v6; // x0
  size_t v10; // x0
  const char *v11; // x0
  int v12; // w8
  char v13; // t1
  unsigned int v14; // w8
  const char *v16; // x23
  unsigned int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  char v26; // w22
  char v27; // w8
  __int64 v28; // x0
  char v29; // w22
  char v30; // w8
  __int64 v31; // x0
  char v32; // w22
  char v33; // w8
  __int64 v34; // x0
  char v35; // w22
  char v36; // w8
  __int64 v37; // x0
  char v38; // w22
  char v39; // w8
  __int64 v40; // x0
  char v41; // w22
  size_t v42; // x0
  const char *v43; // x22
  int v44; // w0
  bool v45; // zf
  unsigned int v46; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v47; // [xsp+10h] [xbp-40h] BYREF
  __int64 v48; // [xsp+18h] [xbp-38h]
  __int16 v49; // [xsp+20h] [xbp-30h]
  _QWORD v50[5]; // [xsp+28h] [xbp-28h] BYREF

  v50[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v4 = *a1;
    if ( *a1 )
    {
      v6 = *a1;
      v46 = 0;
      memset(v50, 0, 32);
      v47 = 0;
      v48 = 0;
      v49 = 0;
      v10 = strlen(v6);
      v11 = (const char *)strnchr(v4, v10, 32);
      if ( !v11 )
        goto LABEL_9;
      v12 = *(unsigned __int8 *)v11;
      if ( v12 != 32 )
        goto LABEL_9;
      while ( (unsigned __int8)v12 == 32 )
      {
        v13 = *++v11;
        LOBYTE(v12) = v13;
      }
      if ( !(_BYTE)v12 )
        goto LABEL_9;
      v16 = v11;
      v17 = sscanf(v11, "%17s", &v47);
      if ( v17 != 1 || (hdd_is_valid_mac_address(&v47) & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid MAC address or All hex inputs are not read (%d)",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "_hdd_parse_bssid_and_chan",
          v17);
        v14 = -22;
        v11 = v16;
        goto LABEL_10;
      }
      v26 = hex_to_bin((unsigned __int8)v47);
      v27 = hex_to_bin(BYTE1(v47)) | (16 * v26);
      v28 = BYTE3(v47);
      *a2 = v27;
      v29 = hex_to_bin(v28);
      v30 = hex_to_bin(BYTE4(v47)) | (16 * v29);
      v31 = BYTE6(v47);
      a2[1] = v30;
      v32 = hex_to_bin(v31);
      v33 = hex_to_bin(HIBYTE(v47)) | (16 * v32);
      v34 = BYTE1(v48);
      a2[2] = v33;
      v35 = hex_to_bin(v34);
      v36 = hex_to_bin(BYTE2(v48)) | (16 * v35);
      v37 = BYTE4(v48);
      a2[3] = v36;
      v38 = hex_to_bin(v37);
      v39 = hex_to_bin(BYTE5(v48)) | (16 * v38);
      v40 = HIBYTE(v48);
      a2[4] = v39;
      v41 = hex_to_bin(v40);
      a2[5] = hex_to_bin((unsigned __int8)v49) | (16 * v41);
      v42 = strlen(v16);
      v11 = (const char *)strnchr(v16, v42, 32);
      if ( !v11 )
        goto LABEL_9;
      while ( *v11 == 32 )
        ++v11;
      if ( *v11 )
      {
        v43 = v11;
        if ( sscanf(v11, "%31s ", v50) == 1 )
        {
          v44 = kstrtoint(v50, 10, &v46);
          v14 = -22;
          if ( (v44 & 0x80000000) == 0 && (v46 & 0x80000000) == 0 )
          {
            v45 = (hdd_check_and_fill_freq(v46, a3, a4) & 1) == 0;
            v11 = v43;
            if ( v45 )
              v14 = -22;
            else
              v14 = 0;
            goto LABEL_10;
          }
        }
        else
        {
          v14 = -22;
        }
        v11 = v43;
      }
      else
      {
LABEL_9:
        v14 = -22;
      }
LABEL_10:
      *a1 = v11;
      goto LABEL_11;
    }
  }
  v14 = -22;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v14;
}
