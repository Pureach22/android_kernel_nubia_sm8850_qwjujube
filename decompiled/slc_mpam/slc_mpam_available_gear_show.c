__int64 __fastcall slc_mpam_available_gear_show(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  int v5; // w9
  int v6; // w10
  int device_capability; // w0
  __int64 v8; // x20
  int v10; // w8
  int v11; // w3
  unsigned int v12; // w22
  int v13; // w24
  int v14; // w0
  int v16; // w0
  int v17; // w0
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  __int64 v19; // [xsp+8h] [xbp-18h]
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20[0] = 0;
  v18 = 0;
  v4 = qcom_msc_lookup(2);
  if ( v4 )
  {
    v6 = *(_DWORD *)(a1 + 136);
    v5 = *(_DWORD *)(a1 + 140);
    LODWORD(v20[0]) = *(_DWORD *)(v4 + 12);
    HIWORD(v20[0]) = v5;
    WORD2(v20[0]) = v6;
  }
  device_capability = msc_system_get_device_capability(2, v20, &v18);
  if ( device_capability )
  {
    v8 = (int)scnprintf(a2, 4096, "failed to get available gear %d\n", device_capability);
  }
  else
  {
    v10 = BYTE1(v18);
    if ( !slc_firmware_ver )
    {
      if ( !BYTE1(v18) )
      {
        v8 = 0;
        goto LABEL_5;
      }
      if ( BYTE2(v18) < 5uLL )
      {
        v16 = scnprintf(a2, 4096, "%d - %s\n", BYTE2(v18), &gear_index[25 * BYTE2(v18)]);
        v8 = v16;
        if ( BYTE1(v18) < 2u )
          goto LABEL_5;
        if ( BYTE3(v18) <= 4uLL )
        {
          v8 = v16
             + (__int64)(int)scnprintf(a2 + v16, 4096LL - v16, "%d - %s\n", BYTE3(v18), &gear_index[25 * BYTE3(v18)]);
          if ( BYTE1(v18) < 3u )
            goto LABEL_5;
          if ( BYTE4(v18) <= 4uLL )
          {
            v17 = scnprintf(a2 + v8, 4096 - v8, "%d - %s\n", BYTE4(v18), &gear_index[25 * BYTE4(v18)]);
            if ( BYTE1(v18) <= 3u )
            {
              v8 += v17;
              goto LABEL_5;
            }
          }
        }
      }
      __break(0x5512u);
      JUMPOUT(0x70D0);
    }
    v8 = 0;
    if ( BYTE1(v18) )
    {
      v11 = 0;
      v12 = 0;
      do
      {
        if ( ((*(_DWORD *)((char *)&v18 + 2) >> v12) & 1) != 0 )
        {
          v13 = v11 + 1;
          v14 = scnprintf(a2 + v8, 4096 - v8, "%d - %d\n", v11, (unsigned int)v19 * v12);
          v10 = BYTE1(v18);
          v8 += v14;
          v11 = v13;
        }
        if ( v11 >= v10 )
          break;
      }
      while ( v12++ < 0x1F );
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v8;
}
